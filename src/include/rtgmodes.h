#ifndef UAE_RTGMODES_H
#define UAE_RTGMODES_H

/* Types for RGBFormat used */
typedef enum {
	RGBFB_NONE,		/* no valid RGB format (should not happen) */
	RGBFB_CLUT,		/* palette mode, set colors when opening screen using
			   tags or use SetRGB32/LoadRGB32(...) */
	RGBFB_R8G8B8,	/* TrueColor RGB (8 bit each) */
	RGBFB_B8G8R8,	/* TrueColor BGR (8 bit each) */
	RGBFB_R5G6B5PC,	/* HiColor16 (5 bit R, 6 bit G, 5 bit B),
			   format: gggbbbbbrrrrrggg */
	RGBFB_R5G5B5PC,	/* HiColor15 (5 bit each), format: gggbbbbb0rrrrrgg */
	RGBFB_A8R8G8B8,	/* 4 Byte TrueColor ARGB (A unused alpha channel) */
	RGBFB_A8B8G8R8,	/* 4 Byte TrueColor ABGR (A unused alpha channel) */
	RGBFB_R8G8B8A8,	/* 4 Byte TrueColor RGBA (A unused alpha channel) */
	RGBFB_B8G8R8A8,	/* 4 Byte TrueColor BGRA (A unused alpha channel) */
	RGBFB_R5G6B5,	/* HiColor16 (5 bit R, 6 bit G, 5 bit B),
			   format: rrrrrggggggbbbbb */
	RGBFB_R5G5B5,	/* HiColor15 (5 bit each), format: 0rrrrrgggggbbbbb */
	RGBFB_B5G6R5PC,	/* HiColor16 (5 bit R, 6 bit G, 5 bit B),
			   format: gggrrrrrbbbbbggg */
	RGBFB_B5G5R5PC,	/* HiColor15 (5 bit each), format: gggrrrrr0bbbbbbgg */

	    /* By now, the following formats are for use with a hardware window only
	       (bitmap operations may be implemented incompletely) */

	RGBFB_Y4U2V2,	/* 2 Byte TrueColor YUV (CCIR recommendation CCIR601).
			   Each two-pixel unit is stored as one longword
			   containing luminance (Y) for each of the two pixels,
			   and chrominance (U,V) for alternate pixels.
			   The missing chrominance values are generated by
			   interpolation. (Y1-U0-Y0-V0) */
	RGBFB_Y4U1V1,	/* 1 Byte TrueColor ACCUPAK. Four adjacent pixels form
			   a packet of 5 bits Y (luminance) each pixel and 6 bits
			   U and V (chrominance) shared by the four pixels */

	RGBFB_MaxFormats
} RGBFTYPE;

#define RGBFF_NONE	(1<<RGBFB_NONE)
#define RGBFF_CLUT	(1<<RGBFB_CLUT)
#define RGBFF_R8G8B8	(1<<RGBFB_R8G8B8)
#define RGBFF_B8G8R8	(1<<RGBFB_B8G8R8)
#define RGBFF_R5G6B5PC	(1<<RGBFB_R5G6B5PC)
#define RGBFF_R5G5B5PC	(1<<RGBFB_R5G5B5PC)
#define RGBFF_A8R8G8B8	(1<<RGBFB_A8R8G8B8)
#define RGBFF_A8B8G8R8	(1<<RGBFB_A8B8G8R8)
#define RGBFF_R8G8B8A8	(1<<RGBFB_R8G8B8A8)
#define RGBFF_B8G8R8A8	(1<<RGBFB_B8G8R8A8)
#define RGBFF_R5G6B5	(1<<RGBFB_R5G6B5)
#define RGBFF_R5G5B5	(1<<RGBFB_R5G5B5)
#define RGBFF_B5G6R5PC	(1<<RGBFB_B5G6R5PC)
#define RGBFF_B5G5R5PC	(1<<RGBFB_B5G5R5PC)
#define RGBFF_Y4U2V2	(1<<RGBFB_Y4U2V2)
#define RGBFF_Y4U1V1	(1<<RGBFB_Y4U1V1)

#define RGBMASK_8BIT RGBFF_CLUT
#define RGBMASK_16BIT (RGBFF_R5G6B5PC | RGBFF_B5G6R5PC | RGBFF_R5G6B5)
#define RGBMASK_15BIT (RGBFF_R5G5B5PC | RGBFF_B5G5R5PC | RGBFF_R5G5B5)
#define RGBMASK_24BIT (RGBFF_R8G8B8 | RGBFF_B8G8R8)
#define RGBMASK_32BIT (RGBFF_A8R8G8B8 | RGBFF_A8B8G8R8 | RGBFF_R8G8B8A8 | RGBFF_B8G8R8A8)

#define	RGBFF_PLANAR	RGBFF_NONE
#define	RGBFF_CHUNKY	RGBFF_CLUT

#define	RGBFB_PLANAR	RGBFB_NONE
#define	RGBFB_CHUNKY	RGBFB_CLUT

#endif /* UAE_RTGMODES_H */