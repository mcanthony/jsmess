/*****************************************************************************
 *
 * includes/gamecom.h
 *
 * Tiger Game.com
 *
 * Driver by Wilbert Pol
 *
 ****************************************************************************/

#ifndef GAMECOM_H_
#define GAMECOM_H_


/* SM8521 register addresses */
enum
{
	SM8521_R0		= 0x00,
	SM8521_R1		= 0x01,
	SM8521_R2		= 0x02,
	SM8521_R3		= 0x03,
	SM8521_R4		= 0x04,
	SM8521_R5		= 0x05,
	SM8521_R6		= 0x06,
	SM8521_R7		= 0x07,
	SM8521_R8		= 0x08,
	SM8521_R9		= 0x09,
	SM8521_R10		= 0x0A,
	SM8521_R11		= 0x0B,
	SM8521_R12		= 0x0C,
	SM8521_R13		= 0x0D,
	SM8521_R14		= 0x0E,
	SM8521_R15		= 0x0F,
	SM8521_IE0		= 0x10,
	SM8521_IE1		= 0x11,
	SM8521_IR0		= 0x12,
	SM8521_IR1		= 0x13,
	SM8521_P0		= 0x14,
	SM8521_P1		= 0x15,
	SM8521_P2		= 0x16,
	SM8521_P3		= 0x17,
	SM8521_18		= 0x18,	/* reserved */
	SM8521_SYS		= 0x19,
	SM8521_CKC		= 0x1A,
	SM8521_1B		= 0x1B,	/* reserved */
	SM8521_SPH		= 0x1C,
	SM8521_SPL		= 0x1D,
	SM8521_PS0		= 0x1E,
	SM8521_PS1		= 0x1F,
	SM8521_P0C		= 0x20,
	SM8521_P1C		= 0x21,
	SM8521_P2C		= 0x22,
	SM8521_P3C		= 0x23,
	SM8521_MMU0		= 0x24,
	SM8521_MMU1		= 0x25,
	SM8521_MMU2		= 0x26,
	SM8521_MMU3		= 0x27,
	SM8521_MMU4		= 0x28,
	SM8521_29		= 0x29,	/* reserved */
	SM8521_2A		= 0x2A,	/* reserved */
	SM8521_URTT		= 0x2B,
	SM8521_URTR		= 0x2C,
	SM8521_URTS		= 0x2D,
	SM8521_URTC		= 0x2E,
	SM8521_2F		= 0x2F,	/* reserved */
	SM8521_LCDC		= 0x30,
	SM8521_LCH		= 0x31,
	SM8521_LCV		= 0x32,
	SM8521_33		= 0x33,	/* reserved */
	SM8521_DMC		= 0x34,
	SM8521_DMX1		= 0x35,
	SM8521_DMY1		= 0x36,
	SM8521_DMDX		= 0x37,
	SM8521_DMDY		= 0x38,
	SM8521_DMX2		= 0x39,
	SM8521_DMY2		= 0x3A,
	SM8521_DMPL		= 0x3B,
	SM8521_DMBR		= 0x3C,
	SM8521_DMVP		= 0x3D,
	SM8521_3E		= 0x3E,	/* reserved */
	SM8521_3F		= 0x3F,	/* reserved */
	SM8521_SGC		= 0x40,
	SM8521_41		= 0x41,	/* reserved */
	SM8521_SG0L		= 0x42,
	SM8521_43		= 0x43,	/* reserved */
	SM8521_SG1L		= 0x44,
	SM8521_45		= 0x45,	/* reserved */
	SM8521_SG0TH	= 0x46,
	SM8521_SG0TL	= 0x47,
	SM8521_SG1TH	= 0x48,
	SM8521_SG1TL	= 0x49,
	SM8521_SG2L		= 0x4A,
	SM8521_4B		= 0x4B,	/* reserved */
	SM8521_SG2TH	= 0x4C,
	SM8521_SG2TL	= 0x4D,
	SM8521_SGDA		= 0x4E,
	SM8521_4F		= 0x4F,	/* reserved */
	SM8521_TM0C		= 0x50,
	SM8521_TM0D		= 0x51,
	SM8521_TM1C		= 0x52,
	SM8521_TM1D		= 0x53,
	SM8521_CLKT		= 0x54,
	SM8521_55		= 0x55,	/* reserved */
	SM8521_56		= 0x56,	/* reserved */
	SM8521_57		= 0x57,	/* reserved */
	SM8521_58		= 0x58,	/* reserved */
	SM8521_59		= 0x59,	/* reserved */
	SM8521_5A		= 0x5A,	/* reserved */
	SM8521_5B		= 0x5B,	/* reserved */
	SM8521_5C		= 0x5C,	/* reserved */
	SM8521_5D		= 0x5D,	/* reserved */
	SM8521_WDT		= 0x5E,
	SM8521_WDTC		= 0x5F,
	SM8521_SG0W0	= 0x60,
	SM8521_SG0W1	= 0x61,
	SM8521_SG0W2	= 0x62,
	SM8521_SG0W3	= 0x63,
	SM8521_SG0W4	= 0x64,
	SM8521_SG0W5	= 0x65,
	SM8521_SG0W6	= 0x66,
	SM8521_SG0W7	= 0x67,
	SM8521_SG0W8	= 0x68,
	SM8521_SG0W9	= 0x69,
	SM8521_SG0W10	= 0x6A,
	SM8521_SG0W11	= 0x6B,
	SM8521_SG0W12	= 0x6C,
	SM8521_SG0W13	= 0x6D,
	SM8521_SG0W14	= 0x6E,
	SM8521_SG0W15	= 0x6F,
	SM8521_SG1W0	= 0x70,
	SM8521_SG1W1	= 0x71,
	SM8521_SG1W2	= 0x72,
	SM8521_SG1W3	= 0x73,
	SM8521_SG1W4	= 0x74,
	SM8521_SG1W5	= 0x75,
	SM8521_SG1W6	= 0x76,
	SM8521_SG1W7	= 0x77,
	SM8521_SG1W8	= 0x78,
	SM8521_SG1W9	= 0x79,
	SM8521_SG1W10	= 0x7A,
	SM8521_SG1W11	= 0x7B,
	SM8521_SG1W12	= 0x7C,
	SM8521_SG1W13	= 0x7D,
	SM8521_SG1W14	= 0x7E,
	SM8521_SG1W15	= 0x7F
};


/*----------- defined in drivers/gamecom.c -----------*/

extern UINT8 *gamecom_vram;

/*----------- defined in machine/gamecom.c -----------*/

extern MACHINE_RESET( gamecom );
extern DRIVER_INIT( gamecom );
extern DEVICE_IMAGE_LOAD( gamecom_cart1 );
extern DEVICE_IMAGE_LOAD( gamecom_cart2 );

extern WRITE8_HANDLER( gamecom_internal_w );
extern READ8_HANDLER( gamecom_internal_r );
extern WRITE8_HANDLER( gamecom_pio_w );
extern READ8_HANDLER( gamecom_pio_r );

extern void gamecom_handle_dma( running_device *device, int cycles );
extern void gamecom_update_timers( running_device *device, int cycles );


/*----------- defined in video/gamecom.c -----------*/

VIDEO_START( gamecom );


#endif /* GAMECOM_H_ */
