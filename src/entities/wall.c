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

#include "wall.h"

static void touch(Entity *other);
static int blocking(void);
static void die(void);
static void activate(void);

void initWall(Entity *e)
{
	e->type = ET_WALL;
	e->sprite = getSprite("Wall");
	e->touch = touch;
	e->isBlocking = blocking;
	e->die = die;
	e->activate = activate;
	
	e->solid = 1;
}

static void touch(Entity *other)
{
	if (self->visible && isGuy(other))
	{
		stepBack();

		clearRoute();
	}
}

static void activate(void)
{
	Entity *candidates[MAX_CANDIDATES];
	int i, n;
	
	self->solid = self->visible = !self->visible;
	
	getEntitiesAt(self->x, self->y, &n, self, candidates);

	for (i = 0 ; i < n ; i++)
	{
		if (isGuy(candidates[i]))
		{
			candidates[i]->alive = 0;
		}
		else if (candidates[i]->type == ET_PUSH_BLOCK)
		{
			self->alive = 0;
		}
	}
}

static void die(void)
{
	playSound(SND_DIE, -1);
	
	addExplosionEffect(self->x, self->y, 1, 1, 1);
}

static int blocking(void)
{
	return self->visible;
}
