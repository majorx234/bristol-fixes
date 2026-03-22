
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

/*
 * Palette consists of three sections. We have a set of global operators which
 * will affect any given audio stream, and we have a set of algorithms, which
 * will sequence the operators according to any desired method, and produce a
 * synthesiser.
 * Finally we have a set of effects processors for a final output stage. These
 * can potentially be mixed into any given voice, but would then need to be 
 * define in the palette as well as the FX lists.
 */

#ifndef PALETTE_H
#define PALETTE_H

/*
 * Effects operators.
 */
extern bristolOP * leslieinit(bristolOP **operator, int index, int samplerate, int);

/*
 * Synth operators
 */
extern bristolOP * bristolinit();
extern bristolOP * noiseinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * dcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * envinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * dcainit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * filterinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * hammondinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * resinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * prophetdcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * dxopinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * hpfinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * junodcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * chorusinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * vchorusinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * filter2init(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * expdcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * lfoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * voxdcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * sdcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * arpdcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * ringmodinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * eswitchinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * reverbinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * followerinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * aksdcoinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * aksenvinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * aksreverbinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * aksfilterinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * hammondchorusinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * quantuminit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * bit1oscinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * cs80oscinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * cs80envinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * trilogyoscinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * env5stageinit(bristolOP **operator, int index, int samplerate, int);
extern bristolOP * nroinit(bristolOP **operator, int index, int samplerate, int);

struct bristolPalette {
	bristolOP * (*initialise)(bristolOP **, int, int, int);
} bristolPalette[BRISTOL_SYNTHCOUNT] = {
	{dcoinit},
	{envinit},
	{dcainit},
	{filterinit},
	{noiseinit},
	{hammondinit},
	{resinit},
	{leslieinit},
	{prophetdcoinit}, /* 8 */
	{dxopinit},
	{hpfinit},
	{junodcoinit},
	{chorusinit},
	{vchorusinit},
	{filter2init},
	{expdcoinit},
	{lfoinit}, /* 16 */
	{voxdcoinit},
	{sdcoinit},
	{arpdcoinit},
	{ringmodinit},
	{eswitchinit},
	{reverbinit},
	{followerinit},
	{aksdcoinit}, /* 24 */
	{aksenvinit},
	{aksreverbinit},
	{aksfilterinit},
	{hammondchorusinit},
	{quantuminit}, /* This will be the "quantum" grain generator */
	{bit1oscinit},
	{cs80oscinit},
	{cs80envinit}, /* 32 - now to use the env5stage init */
	{trilogyoscinit},
	{env5stageinit},
	{nroinit},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL}
};

/*
 * Synth algorithms
 */
extern int bristolMMInit(audioMain *, bAudio *);
extern int bristolHammondInit(audioMain *, bAudio *);
extern int bristolProphetInit(audioMain *, bAudio *);
extern int bristolProphet52Init(audioMain *, bAudio *);
extern int bristolDXInit(audioMain *, bAudio *);
extern int bristolRhodesInit(audioMain *, bAudio *);
extern int bristolJunoInit(audioMain *, bAudio *);
extern int bristolExpInit(audioMain *, bAudio *);
extern int bristolHammondB3Init(audioMain *, bAudio *);
extern int bristolVoxInit(audioMain *, bAudio *);
extern int bristolSamplerInit(audioMain *, bAudio *);
extern int bristolMixerInit(audioMain *, bAudio *);
extern int bristolOBXInit(audioMain *, bAudio *);
extern int bristolOBXaInit(audioMain *, bAudio *);
extern int bristolPolyInit(audioMain *, bAudio *);
extern int bristolPoly6Init(audioMain *, bAudio *);
extern int bristolAxxeInit(audioMain *, bAudio *);
extern int bristolOdysseyInit(audioMain *, bAudio *);
extern int bristolMemoryMoogInit(audioMain *, bAudio *);
extern int bristolArp2600Init(audioMain *, bAudio *);
extern int bristolAksInit(audioMain *, bAudio *);
extern int bristolSolinaInit(audioMain *, bAudio *);
extern int bristolRoadrunnerInit(audioMain *, bAudio *);
extern int bristolGranularInit(audioMain *, bAudio *);
extern int bristolMg1Init(audioMain *, bAudio *);
extern int bristolVoxM2Init(audioMain *, bAudio *);
extern int bristolJupiterInit(audioMain *, bAudio *);
extern int bristolBitoneInit(audioMain *, bAudio *);
extern int bristolCs80Init(audioMain *, bAudio *);
extern int bristolPro1Init(audioMain *, bAudio *);
extern int bristolSonic6Init(audioMain *, bAudio *);
extern int bristolTrilogyInit(audioMain *, bAudio *);
extern int bristolTrilogyODCInit(audioMain *, bAudio *);
extern int bristolPoly800Init(audioMain *, bAudio *);
extern int bristolBme700Init(audioMain *, bAudio *);
extern int bristolBassMakerInit(audioMain *, bAudio *);
extern int bristolSidInit(audioMain *, bAudio *);

struct bristolAlgos {
	int (*initialise)(audioMain *, bAudio *);
	char *name;
} bristolAlgos[BRISTOL_SYNTHCOUNT] = {
	{bristolMMInit, "mini"},
	{bristolHammondInit, "hammond"},
	{bristolProphetInit, "prophet"},
	{bristolDXInit, "dx"},
	{bristolJunoInit, "juno"},
	{bristolExpInit, "explorer"},
	{bristolHammondB3Init, "hammondB3"},
	{bristolVoxInit, "vox"},
	{bristolRhodesInit, "dx"},
	{bristolSamplerInit, NULL},
	{bristolMixerInit, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{bristolProphet52Init, "prophet52"}, /* Uses Prophet algorithm with added FX. */
	{bristolOBXInit, "obx"}, /* Used by OB-X and two for OB-Xa */
	{NULL, NULL}, /* This was for the OBXA? */
	{NULL, NULL},
	{bristolPolyInit, "mono"},
	{bristolPoly6Init, "poly"},
	{bristolAxxeInit, "axxe"},
	{bristolOdysseyInit, "odyssey"},
	{bristolMemoryMoogInit, "memoryMoog"},
	{bristolArp2600Init, "arp2600"},
	{bristolAksInit, "aks"},
	{NULL, NULL}, /* Will be MS-20 */
	{bristolSolinaInit, "solina"},
	{bristolRoadrunnerInit, "roadrunner"},
	{bristolGranularInit, "granular"},
	{bristolMg1Init, "realistic"},
	{bristolVoxM2Init, "voxM2"},
	{bristolJupiterInit, "jupiter8"},
	{bristolBitoneInit, "bitone"},
	{NULL, NULL}, /* Will be Master Keyboard */
	{bristolCs80Init, "cs80"},
	{bristolPro1Init, "pro1"},
	{bristolExpInit, "explorer"},
	{bristolSonic6Init, "sonic6"},
	{bristolTrilogyInit, "trilogy"},
	{bristolTrilogyODCInit, "trilogyODC"},
	{NULL, "stratus"}, /* Is the trilogy */
	{bristolPoly800Init, "poly800"},
	{bristolBme700Init, "bme700"},
	{bristolBassMakerInit, "bassmaker"},
	{bristolSidInit, "sid"},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL}
};

void
newPalette()
{
	/*
	 * This is defined in fatboy headers, here we only have a null call
	 */
}

struct bristolEffects {
	bristolOP * (*initialise)(bristolOP **operator, int index, int samplerate, int);
} bristolEffects[BRISTOL_SYNTHCOUNT] = {
	{leslieinit},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL},
	{NULL}
};

#endif

