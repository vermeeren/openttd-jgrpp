/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_sl.cpp Handles the saveload part of the AIs */

#include "../stdafx.h"
#include "../company_base.h"
#include "../debug.h"
#include "saveload.h"
#include "../string_func.h"

#include "../ai/ai.hpp"
#include "../ai/ai_config.hpp"
#include "../network/network.h"
#include "../ai/ai_instance.hpp"

struct AiSaveload {
	char name[64];
	char settings[1024];
	int  version;
	bool is_random;
	CompanyID id;
};

static const SaveLoad _ai_company[] = {
	     SLE_STR(AiSaveload, name,        SLS_STRB, lengthof(AiSaveload::name)),
	     SLE_STR(AiSaveload, settings,    SLS_STRB, lengthof(AiSaveload::settings)),
	 SLE_CONDVAR(AiSaveload, version,   SLE_UINT32, 108, SL_MAX_VERSION),
	 SLE_CONDVAR(AiSaveload, is_random,   SLE_BOOL, 136, SL_MAX_VERSION),
	     SLE_END()
};

static void SaveReal_AIPL(AiSaveload *aisl)
{
	SlObject(aisl, _ai_company);
	/* If the AI was active, store his data too */
	if (aisl->id != (CompanyID)-1) AI::Save(aisl->id);
}

static void Load_AIPL()
{
	/* Free all current data */
	for (CompanyID c = COMPANY_FIRST; c < MAX_COMPANIES; c++) {
		AIConfig::GetConfig(c, AIConfig::SSS_FORCE_GAME)->Change(NULL);
	}

	AiSaveload aisl;
	while ((aisl.id = (CompanyID)SlIterateArray()) != (CompanyID)-1) {
		if (aisl.id >= MAX_COMPANIES) SlErrorCorrupt("Too many AI configs");

		aisl.is_random = 0;
		aisl.version = -1;
		SlObject(&aisl, _ai_company);

		if (_networking && !_network_server) {
			if (Company::IsValidAiID(aisl.id)) AIInstance::LoadEmpty();
			continue;
		}

		AIConfig *config = AIConfig::GetConfig(aisl.id, AIConfig::SSS_FORCE_GAME);
		if (StrEmpty(aisl.name)) {
			/* A random AI. */
			config->Change(NULL, -1, false, true);
		} else {
			config->Change(aisl.name, aisl.version, false, aisl.is_random);
			if (!config->HasScript()) {
				/* No version of the AI available that can load the data. Try to load the
				 * latest version of the AI instead. */
				config->Change(aisl.name, -1, false, aisl.is_random);
				if (!config->HasScript()) {
					if (strcmp(aisl.name, "%_dummy") != 0) {
						DEBUG(script, 0, "The savegame has an AI by the name '%s', version %d which is no longer available.", aisl.name, aisl.version);
						DEBUG(script, 0, "A random other AI will be loaded in its place.");
					} else {
						DEBUG(script, 0, "The savegame had no AIs available at the time of saving.");
						DEBUG(script, 0, "A random available AI will be loaded now.");
					}
				} else {
					DEBUG(script, 0, "The savegame has an AI by the name '%s', version %d which is no longer available.", aisl.name, aisl.version);
					DEBUG(script, 0, "The latest version of that AI has been loaded instead, but it'll not get the savegame data as it's incompatible.");
				}
				/* Make sure the AI doesn't get the saveload data, as he was not the
				 *  writer of the saveload data in the first place */
				aisl.version = -1;
			}
		}

		config->StringToSettings(aisl.settings);

		/* Start the AI directly if it was active in the savegame */
		if (Company::IsValidAiID(aisl.id)) {
			AI::StartNew(aisl.id, false);
			AI::Load(aisl.id, aisl.version);
		}
	}
}

static void Save_AIPL()
{
	AiSaveload aisl;

	for (int i = COMPANY_FIRST; i < MAX_COMPANIES; i++) {
		AIConfig *config = AIConfig::GetConfig((CompanyID)i);

		if (config->HasScript()) {
			ttd_strlcpy(aisl.name, config->GetName(), lengthof(aisl.name));
			aisl.version = config->GetVersion();
		} else {
			/* No AI is configured for this so store an empty string as name. */
			aisl.name[0] = '\0';
			aisl.version = -1;
		}

		aisl.is_random = config->IsRandom();
		aisl.settings[0] = '\0';
		config->SettingsToString(aisl.settings, lengthof(aisl.settings));

		/* If the AI was active, store his data too */
		aisl.id = (CompanyID)(Company::IsValidAiID(i) ? i : -1);

		SlArrayAutoElement(i, (AutolengthProc *)SaveReal_AIPL, &aisl);
	}
}

extern const ChunkHandler _ai_chunk_handlers[] = {
	{ 'AIPL', Save_AIPL, Load_AIPL, NULL, NULL, CH_ARRAY | CH_LAST},
};
