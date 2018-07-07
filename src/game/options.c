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

#include "options.h"

static void logic(void);
static void draw(void);
static void setScreenResOption(Widget *w);
static void res(void);
static void sound(void);
static void music(void);
static void sex(void);
static void speed(void);
static void back(void);

static Background background;
static Widget *resWidget;
static Widget *soundWidget;
static Widget *musicWidget;
static Widget *sexWidget;
static Widget *speedWidget;
static Widget *backWidget;

void initOptions(void)
{
	initGLRectangle(&background.rect, SCREEN_WIDTH, SCREEN_HEIGHT);
	background.rect.texture = loadTexture("gfx/backgrounds/background.jpg")->texture;
	background.r = background.g = background.b = 1.0;
	
	showWidgetGroup("options");
	
	resWidget = getWidget("resolution", "options");
	resWidget->action = res;
	setScreenResOption(resWidget);
	
	soundWidget = getWidget("sound", "options");
	soundWidget->action = sound;
	soundWidget->value = app.config.soundVolume / 12.8;
	
	musicWidget = getWidget("music", "options");
	musicWidget->action = music;
	musicWidget->value = app.config.musicVolume / 12.8;
	
	sexWidget = getWidget("sex", "options");
	sexWidget->action = sex;
	sexWidget->value = app.config.sex;
	
	speedWidget = getWidget("speed", "options");
	speedWidget->action = speed;
	speedWidget->value = app.config.speed;
	
	backWidget = getWidget("back", "options");
	backWidget->action = back;
	
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	
	initWipe(WIPE_FADE);
}

static void logic(void)
{
	doWidgets();
	
	doWipe();
}

static void draw(void)
{
	drawBackground(&background);
	
	drawShadowText(SCREEN_WIDTH / 2, 100, TA_CENTER, 60, "Options");
	
	drawWidgets();
	
	drawWipe();
}

static void res(void)
{
	sscanf(resWidget->options[(int)resWidget->value], "%dx%d", &app.config.winWidth, &app.config.winHeight);
	
	playSound(SND_SELECT, 0);
}

static void sound(void)
{
	soundWidget->value = limit(soundWidget->value, 0, 10);
	
	app.config.soundVolume = soundWidget->value;
	
	Mix_Volume(-1, app.config.soundVolume * 12.8);
	
	playSound(SND_SELECT, 0);
}

static void music(void)
{
	musicWidget->value = limit(musicWidget->value, 0, 10);
	
	app.config.musicVolume = musicWidget->value;
	
	Mix_VolumeMusic(app.config.musicVolume * 12.8);
	
	playSound(SND_SELECT, 0);
}

static void sex(void)
{
	app.config.sex = sexWidget->value;
	
	playSound(SND_SELECT, 0);
}

static void speed(void)
{
	app.config.speed = speedWidget->value;
	
	playSound(SND_SELECT, 0);
}

static void back(void)
{
	saveConfig();
	
	app.delegate.postOptions();
	
	playSound(SND_SELECT, 0);
}

static void setScreenResOption(Widget *w)
{
	char res[12];
	int i;
	
	sprintf(res, "%dx%d", app.config.winWidth, app.config.winHeight);
	
	for (i = 0 ; i < w->numOptions ; i++)
	{
		if (strcmp(w->options[i], res) == 0)
		{
			w->value = i;
			return;
		}
	}
}
