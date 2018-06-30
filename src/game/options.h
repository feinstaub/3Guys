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

#include "../common.h"

extern void doWidgets(void);
extern void drawBackground(Background *background);
extern void drawWidgets(void);
extern void initGLRectangle(GLRectangle *rect, int width, int height);
extern Texture *loadTexture(const char *filename);
extern void showWidgetGroup(const char *name);
extern void useFont(char *name);
extern Widget *getWidget(const char *name, const char *group);

extern App app;