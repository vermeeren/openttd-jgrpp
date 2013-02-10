/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file cheat_sl.cpp Code handling saving and loading of cheats */

#include "../stdafx.h"
#include "../cheat_type.h"

#include "saveload_buffer.h"
#include "saveload_error.h"

/**
 * Save the cheat values.
 */
static void Save_CHTS(SaveDumper *dumper)
{
	/* Cannot use lengthof because _cheats is of type Cheats, not Cheat */
	byte count = sizeof(_cheats) / sizeof(Cheat);
	Cheat *cht = (Cheat*) &_cheats;
	Cheat *cht_last = &cht[count];

	dumper->WriteRIFFSize(count * 2);
	for (; cht != cht_last; cht++) {
		dumper->WriteByte(cht->been_used);
		dumper->WriteByte(cht->value);
	}
}

/**
 * Load the cheat values.
 */
static void Load_CHTS(LoadBuffer *reader)
{
	Cheat *cht = (Cheat*)&_cheats;
	size_t count = reader->GetChunkSize() / 2;
	/* Cannot use lengthof because _cheats is of type Cheats, not Cheat */
	if (count > sizeof(_cheats) / sizeof(Cheat)) throw SlCorrupt("Too many cheat values");

	for (uint i = 0; i < count; i++) {
		cht[i].been_used = (reader->ReadByte() != 0);
		cht[i].value     = (reader->ReadByte() != 0);
	}
}

/** Chunk handlers related to cheats. */
extern const ChunkHandler _cheat_chunk_handlers[] = {
	{ 'CHTS', Save_CHTS, Load_CHTS, NULL, NULL, CH_RIFF | CH_LAST},
};
