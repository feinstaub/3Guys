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

extern void addExplosionEffect(int mx, int my, float r, float g, float b);
extern void blitAtlasImageRotated(AtlasImage *atlasImage, int x, int y, float angle);
extern AtlasImage *getCurrentFrame(Sprite *s);
extern void getEntitiesAt(int x, int y, int *n, Entity *ignore, Entity **candidates);
extern AtlasImage *getImageFromAtlas(char *filename, int required);
extern Sprite *getSprite(char *name);
extern int isGuy(Entity *e);
extern void playSound(int snd, int ch);

extern App app;
extern Entity *self;
extern Level level;
