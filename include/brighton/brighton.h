
/*
 *  Diverse Bristol audio routines.
 *  Copyright (c) by Nick Copeland <nickycopeland@hotmail.com> 1996,2012
 *
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef BRIGHTON_H
#define BRIGHTON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#include <config.h>

#include <unistd.h>

#include <config.h>

#include "brightondevflags.h"
#include "brightonevents.h"

#include "brightondev.h"

typedef struct brightonLocations {
	char *name;
	int device;
	float x, y;
	float width, height;
	float from, to;
	brightonCallback callback;
	char *image;
	char *image2;
	unsigned int flags;
	int var;
	int val;
} brightonLocations;

typedef struct brightonResource {
	char *name;
	char *image;
	char *surface;
	unsigned int flags;
	brightonRoutine1 init;
	brightonRoutine1 configure;
	brightonCallback callback;
	int x, y, width, height;
	int ndevices;
	brightonLocations *devlocn;
} brightonResource;

#define RESOURCE_COUNT 64 /* Max # of panels */

/* Emulation defaults - can be overridden */
typedef struct BrightonEmulation {
	int voices;
	int detune;
	int gain;
	int pwd;
	int glide;
	int velocity;
	int opacity;
	int panel;
} brightonEmulation;

typedef struct BrightonApp {
	char *name;
	char *image;
	char *surface;
	unsigned int flags;
	brightonRoutine1 init;
	brightonRoutine1 configure;
	brightonCallback callback;
	brightonRoutine1 destroy;
	brightonEmulation emulate;
	int width, height, x, y;
	/*
	 * It would be nice to integrate the following as defaults that would be
	 * set when synth is found and overridden by subsequent options:
	int voices, detune, gain, glide; This is now brightonEmulation.
	 */
	int nresources;
	brightonResource resources[RESOURCE_COUNT];
} brightonApp;

extern int brightonRemoveInterface(struct brightonWindow *);
extern int brightonParamChange(struct brightonWindow *, int, int, brightonEvent *);
extern int brightonOp(struct brightonWindow *, struct brightonIResource*, struct brightonEvent*);
extern int brightonOpacity(struct brightonWindow *, float);
extern int brightonColorQuality(struct brightonWindow *, int);
extern struct brightonWindow *brightonInterface(brightonApp *, int, int, int, float, int, int, int);
extern void brightonLogo(struct brightonWindow *);
extern int brightonEventMgr();

#endif /* BRIGHTON_H */

