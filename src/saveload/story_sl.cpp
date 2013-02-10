/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file story_sl.cpp Code handling saving and loading of story pages */

#include "../stdafx.h"
#include "../story_base.h"

#include "saveload_buffer.h"

/** Called after load to trash broken pages. */
void AfterLoadStoryBook(const SavegameTypeVersion *stv)
{
	if (IsSavegameVersionBefore(stv, 185)) {
		/* Trash all story pages and page elements because
		 * they were saved with wrong data types.
		 */
		_story_page_element_pool.CleanPool();
		_story_page_pool.CleanPool();
	}
}

static const SaveLoad _story_page_elements_desc[] = {
	SLE_CONDVAR(StoryPageElement, sort_value,    SLE_FILE_U16 | SLE_VAR_U32, 0,   184),
	SLE_CONDVAR(StoryPageElement, sort_value,    SLE_UINT32,                 185, SL_MAX_VERSION),
	    SLE_VAR(StoryPageElement, page,          SLE_UINT16),
	SLE_CONDVAR(StoryPageElement, type,          SLE_FILE_U16 | SLE_VAR_U8,  0,   184),
	SLE_CONDVAR(StoryPageElement, type,          SLE_UINT8,                  185, SL_MAX_VERSION),
	    SLE_VAR(StoryPageElement, referenced_id, SLE_UINT32),
	    SLE_STR(StoryPageElement, text,          SLS_STR | SLS_ALLOW_CONTROL, 0),
	    SLE_END()
};

static void Save_STORY_PAGE_ELEMENT(SaveDumper *dumper)
{
	StoryPageElement *s;
	FOR_ALL_STORY_PAGE_ELEMENTS(s) {
		dumper->WriteElement(s->index, s, _story_page_elements_desc);
	}
}

static void Load_STORY_PAGE_ELEMENT(LoadBuffer *reader)
{
	int index;
	uint32 max_sort_value = 0;
	while ((index = reader->IterateChunk()) != -1) {
		StoryPageElement *s = new (index) StoryPageElement();
		reader->ReadObject(s, _story_page_elements_desc);
		if (s->sort_value > max_sort_value) {
			max_sort_value = s->sort_value;
		}
	}
	/* Update the next sort value, so that the next
	 * created page is shown after all existing pages.
	 */
	_story_page_element_next_sort_value = max_sort_value + 1;
}

static const SaveLoad _story_pages_desc[] = {
	SLE_CONDVAR(StoryPage, sort_value, SLE_FILE_U16 | SLE_VAR_U32, 0,   184),
	SLE_CONDVAR(StoryPage, sort_value, SLE_UINT32,                 185, SL_MAX_VERSION),
	    SLE_VAR(StoryPage, date,       SLE_UINT32),
	SLE_CONDVAR(StoryPage, company,    SLE_FILE_U16 | SLE_VAR_U8,  0,   184),
	SLE_CONDVAR(StoryPage, company,    SLE_UINT8,                  185, SL_MAX_VERSION),
	    SLE_STR(StoryPage, title,      SLS_STR | SLS_ALLOW_CONTROL, 0),
	    SLE_END()
};

static void Save_STORY_PAGE(SaveDumper *dumper)
{
	StoryPage *s;
	FOR_ALL_STORY_PAGES(s) {
		dumper->WriteElement(s->index, s, _story_pages_desc);
	}
}

static void Load_STORY_PAGE(LoadBuffer *reader)
{
	int index;
	uint32 max_sort_value = 0;
	while ((index = reader->IterateChunk()) != -1) {
		StoryPage *s = new (index) StoryPage();
		reader->ReadObject(s, _story_pages_desc);
		if (s->sort_value > max_sort_value) {
			max_sort_value = s->sort_value;
		}
	}
	/* Update the next sort value, so that the next
	 * created page is shown after all existing pages.
	 */
	_story_page_next_sort_value = max_sort_value + 1;
}

extern const ChunkHandler _story_page_chunk_handlers[] = {
	{ 'STPE', Save_STORY_PAGE_ELEMENT, Load_STORY_PAGE_ELEMENT, NULL, NULL, CH_ARRAY},
	{ 'STPA', Save_STORY_PAGE, Load_STORY_PAGE, NULL, NULL, CH_ARRAY | CH_LAST},
};
