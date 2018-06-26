/*
Copyright (C) 2018 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "strings.h"

void initStrings(void)
{
	app.strings[ST_CLICK_TO_CONTINUE] = _("Click to continue");
	app.strings[ST_OUT_OF_MOVES] = _("Out of moves!");
	app.strings[ST_DIAMOND_DESC] = _("A diamond. It's very shiny. I'll have it for lunch.");
	app.strings[ST_STAR_DESC] = _("A star. It looks tasty. Will make a nice side for the diamond.");
	app.strings[ST_LEVEL_NUM] = _("Level %03d / 100");
	app.strings[ST_NUM_MOVES] = _("Moves: %d");
	app.strings[ST_KEY_DESC] = _("A key. I can use it to open doors.");
	app.strings[ST_ALREADY_HAVE_KEY] = _("I've already got a key.");
	app.strings[ST_DOOR_DESC] = _("It's a door. It can be opened with a key.");
	app.strings[ST_PUSH_BLOCK_DESC] = _("A heavy object. Green Guy can push it.");
	app.strings[ST_TOOLS_DESC] = _("Tools. They can be used to build a bridge.");
	app.strings[ST_PRESSURE_PLATE_DESC] = _("A pressure plate. I can weigh it down to activate it.");
	app.strings[ST_PLATFORM_DESC] = _("A moving platform. I can walk on it to move it around.");
	app.strings[ST_CRUMBLING_FLOOR_DESC] = _("A crumbling floor. It will break after I walk on it.");
}
