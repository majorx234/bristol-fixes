
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
#ifndef BRISTOLAUDIO_H_
#define BRISTOLAUDIO_H_

//#include "bristol.h"
struct audioMain;
struct bristolOP;
struct bAudio;
struct bristolSound;

extern int bristolAudioOpen(char *, int, int, int);
extern void initAudioThread(struct audioMain*);
extern int bristolAudioWrite(float *, int);
extern int bristolAudioStart();
extern int bristolAudioRead(float *, register int);
extern int bristolAudioClose();
extern int doAudioOps(struct audioMain *, float *, float*);
extern void freeSoundAlgo(struct bAudio *, int, struct bristolSound **);
extern int bristolOPprint(struct bristolOP *);

#endif
