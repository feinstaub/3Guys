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

#include "title.h"

static void logic(void);
static void draw(void);

static Atlas *red;

void initTitle(void)
{
	app.delegate.logic = &logic;
	app.delegate.draw = &draw;
	
	red = getImageFromAtlas("gfx/sprites/red1.png", 1);
	
	loadMusic("music/MSTR_-_MSTR_-_Choro_bavario_Loop.ogg");
	
	playMusic(1);
	
	initLevelSelect();
	
	initOptions();
}

static void logic(void)
{
}

static void draw(void)
{
	drawText(5, 5, TA_LEFT, "Hello, World");
	
	drawGLRectangleBatch(&red->rect, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1);
}
