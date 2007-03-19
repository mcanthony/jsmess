/******************************************************************************
 *	Archimedes 310
 *
 *	system driver
 *
 *	Juergen Buchmueller <pullmoll@t-online.de>, Jul 2000
 *
 *****************************************************************************/

#include "driver.h"
#include "video/generic.h"

#ifndef VERBOSE
#define VERBOSE 0
#endif

#if VERBOSE
#define LOG(x)	logerror x
#else
#define LOG(x)	/* x */
#endif

static MACHINE_RESET( a310 )
{
	UINT8 *mem = memory_region(REGION_CPU1);

	memory_set_bankptr(1,&mem[0x00200000]);
	memory_set_bankptr(2,&mem[0x00000000]);
    memory_set_bankptr(3,&mem[0x00200000]);
    memory_set_bankptr(4,&mem[0x00200000]);
    memory_set_bankptr(5,&mem[0x00200000]);
    memory_set_bankptr(6,&mem[0x00200000]);
    memory_set_bankptr(7,&mem[0x00200000]);
    memory_set_bankptr(8,&mem[0x00200000]);
}

static VIDEO_UPDATE( a310 )
{
    int offs;
	int full_refresh = 1;

    if( full_refresh )
	{
		memset(dirtybuffer, 1, videoram_size);
    }

	for( offs = 0; offs < videoram_size; offs++ )
	{
		if( dirtybuffer[offs] )
		{
            int sx, sy, code;
			sx = (offs % 80) * 8;
			sy = (offs / 80) * 8;
			code = videoram[offs];
			drawgfx(bitmap,Machine->gfx[0],code,0,0,0,sx,sy,
                &Machine->screen[0].visarea,TRANSPARENCY_NONE,0);
        }
	}
	return 0;
}



/* R Nabet : no idea what this is supposed to do */
/* NPW 4-Feb-2004 - This appears to be a 32 bit dirtybuffer update */
static WRITE32_HANDLER( a310_videoram_w )
{
	if (((UINT32 *)videoram)[offset] != data)
	{
		dirtybuffer[offset << 2] = 1;
		dirtybuffer[(offset << 2) + 1] = 1;
		dirtybuffer[(offset << 2) + 2] = 1;
		dirtybuffer[(offset << 2) + 3] = 1;

		COMBINE_DATA(((UINT32 *)videoram)+offset);
	}
}


static ADDRESS_MAP_START( a310_mem, ADDRESS_SPACE_PROGRAM, 32 )
    AM_RANGE(0x001ff000, 0x001fffff) AM_WRITE(a310_videoram_w) AM_BASE((UINT32**)&videoram) AM_SIZE(&videoram_size)

	AM_RANGE(0x00000000, 0x007fffff) AM_READWRITE(MRA32_BANK1, MWA32_ROM)
	AM_RANGE(0x00800000, 0x00ffffff) AM_READWRITE(MRA32_BANK2, MWA32_BANK2)
	AM_RANGE(0x01000000, 0x017fffff) AM_READWRITE(MRA32_BANK3, MWA32_ROM)
	AM_RANGE(0x01800000, 0x01ffffff) AM_READWRITE(MRA32_BANK4, MWA32_ROM)
	AM_RANGE(0x02000000, 0x027fffff) AM_READWRITE(MRA32_BANK5, MWA32_ROM)
	AM_RANGE(0x02800000, 0x02ffffff) AM_READWRITE(MRA32_BANK6, MWA32_ROM)
	AM_RANGE(0x03000000, 0x037fffff) AM_READWRITE(MRA32_BANK7, MWA32_ROM)
	AM_RANGE(0x03800000, 0x03ffffff) AM_READWRITE(MRA32_BANK8, MWA32_ROM)
ADDRESS_MAP_END


INPUT_PORTS_START( a310 )
	PORT_START /* DIP switches */
	PORT_BIT(0xfd, 0xfd, IPT_UNUSED)

    PORT_START /* KEY ROW 0 */
    PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("ESC") PORT_CODE(KEYCODE_ESC)
    PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("1  !") PORT_CODE(KEYCODE_1)
    PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("2  \"") PORT_CODE(KEYCODE_2)
    PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("3  #") PORT_CODE(KEYCODE_3)
    PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("4  $") PORT_CODE(KEYCODE_4)
    PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("5  %") PORT_CODE(KEYCODE_5)
    PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("6  &") PORT_CODE(KEYCODE_6)
    PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("7  '") PORT_CODE(KEYCODE_7)

    PORT_START /* KEY ROW 1 */
    PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("8  *") PORT_CODE(KEYCODE_8)
    PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("9  (") PORT_CODE(KEYCODE_9)
    PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("0  )") PORT_CODE(KEYCODE_0)
    PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("-  _") PORT_CODE(KEYCODE_MINUS)
    PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("=  +") PORT_CODE(KEYCODE_EQUALS)
    PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("`  ~") PORT_CODE(KEYCODE_TILDE)
    PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("BACK SPACE") PORT_CODE(KEYCODE_BACKSPACE)
    PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("TAB") PORT_CODE(KEYCODE_TAB)

    PORT_START /* KEY ROW 2 */
    PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("q  Q") PORT_CODE(KEYCODE_Q)
    PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("w  W") PORT_CODE(KEYCODE_W)
    PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("e  E") PORT_CODE(KEYCODE_E)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("r  R") PORT_CODE(KEYCODE_R)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("t  T") PORT_CODE(KEYCODE_T)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("y  Y") PORT_CODE(KEYCODE_Y)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("u  U") PORT_CODE(KEYCODE_U)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("i  I") PORT_CODE(KEYCODE_I)

	PORT_START /* KEY ROW 3 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("o  O") PORT_CODE(KEYCODE_O)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("p  P") PORT_CODE(KEYCODE_P)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("[  {") PORT_CODE(KEYCODE_OPENBRACE)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("]  }") PORT_CODE(KEYCODE_CLOSEBRACE)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("RETURN") PORT_CODE(KEYCODE_ENTER)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("DEL") PORT_CODE(KEYCODE_DEL)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("CTRL") PORT_CODE(KEYCODE_LCONTROL)
	PORT_BIT(0x80, 0x80, IPT_KEYBOARD) PORT_NAME("CAPS LOCK") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE

	PORT_START /* KEY ROW 4 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("a  A") PORT_CODE(KEYCODE_A)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("s  S") PORT_CODE(KEYCODE_S)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("d  D") PORT_CODE(KEYCODE_D)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("f  F") PORT_CODE(KEYCODE_F)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("g  G") PORT_CODE(KEYCODE_G)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("h  H") PORT_CODE(KEYCODE_H)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("j  J") PORT_CODE(KEYCODE_J)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("k  K") PORT_CODE(KEYCODE_K)

	PORT_START /* KEY ROW 5 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("l  L") PORT_CODE(KEYCODE_L)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME(";  :") PORT_CODE(KEYCODE_COLON)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("'  \"") PORT_CODE(KEYCODE_QUOTE)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("\\  |") PORT_CODE(KEYCODE_ASTERISK)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("SHIFT (L)") PORT_CODE(KEYCODE_LSHIFT)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("z  Z") PORT_CODE(KEYCODE_Z)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("x  X") PORT_CODE(KEYCODE_X)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("c  C") PORT_CODE(KEYCODE_C)

	PORT_START /* KEY ROW 6 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("v  V") PORT_CODE(KEYCODE_V)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("b  B") PORT_CODE(KEYCODE_B)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("n  N") PORT_CODE(KEYCODE_N)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("m  M") PORT_CODE(KEYCODE_M)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME(",  <") PORT_CODE(KEYCODE_COMMA)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME(".  >") PORT_CODE(KEYCODE_STOP)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("/  ?") PORT_CODE(KEYCODE_SLASH)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("SHIFT (R)") PORT_CODE(KEYCODE_RSHIFT)

	PORT_START /* KEY ROW 7 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("LINE FEED")
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("SPACE") PORT_CODE(KEYCODE_SPACE)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("- (KP)") PORT_CODE(KEYCODE_MINUS_PAD)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME(", (KP)") PORT_CODE(KEYCODE_PLUS_PAD)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("ENTER (KP)") PORT_CODE(KEYCODE_ENTER_PAD)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME(". (KP)") PORT_CODE(KEYCODE_DEL_PAD)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("0 (KP)") PORT_CODE(KEYCODE_0_PAD)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("1 (KP)") PORT_CODE(KEYCODE_1_PAD)

	PORT_START /* KEY ROW 8 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("2 (KP)") PORT_CODE(KEYCODE_2_PAD)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("3 (KP)") PORT_CODE(KEYCODE_3_PAD)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("4 (KP)") PORT_CODE(KEYCODE_4_PAD)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("5 (KP)") PORT_CODE(KEYCODE_5_PAD)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("6 (KP)") PORT_CODE(KEYCODE_6_PAD)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("7 (KP)") PORT_CODE(KEYCODE_7_PAD)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("8 (KP)") PORT_CODE(KEYCODE_8_PAD)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("9 (KP)") PORT_CODE(KEYCODE_9_PAD)

	PORT_START /* VIA #1 PORT A */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1					 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON2					 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_4WAY
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_4WAY
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_4WAY
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_4WAY

	PORT_START /* tape control */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("TAPE STOP") PORT_CODE(KEYCODE_F5)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("TAPE PLAY") PORT_CODE(KEYCODE_F6)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("TAPE REW") PORT_CODE(KEYCODE_F7)
	PORT_BIT (0xf8, 0x80, IPT_UNUSED)
INPUT_PORTS_END


static MACHINE_DRIVER_START( a310 )
	/* basic machine hardware */
	MDRV_CPU_ADD_TAG("main", ARM, 8000000)        /* 8 MHz */
	MDRV_CPU_PROGRAM_MAP(a310_mem, 0)
	MDRV_SCREEN_REFRESH_RATE(60)
	MDRV_SCREEN_VBLANK_TIME(DEFAULT_REAL_60HZ_VBLANK_DURATION)
	MDRV_INTERLEAVE(1)

	MDRV_MACHINE_RESET( a310 )

    /* video hardware */
	MDRV_VIDEO_ATTRIBUTES(VIDEO_TYPE_RASTER)
	MDRV_SCREEN_FORMAT(BITMAP_FORMAT_INDEXED16)
	MDRV_SCREEN_SIZE(32*8, 16*16)
	MDRV_SCREEN_VISIBLE_AREA(0*8, 32*8 - 1, 0*16, 16*16 - 1)
	MDRV_PALETTE_LENGTH(2)
	MDRV_COLORTABLE_LENGTH(2)

	MDRV_VIDEO_START(generic)
	MDRV_VIDEO_UPDATE(a310)
MACHINE_DRIVER_END


ROM_START(a310)
	ROM_REGION(0x00400000,REGION_CPU1,0)
		ROM_LOAD("ic24.rom", 0x00200000, 0x00080000, CRC(c1adde84) SHA1(12d060e0401dd0523d44453f947bdc55dd2c3240))
		ROM_LOAD("ic25.rom", 0x00280000, 0x00080000, CRC(15d89664) SHA1(78f5d0e6f1e8ee603317807f53ff8fe65a3b3518))
		ROM_LOAD("ic26.rom", 0x00300000, 0x00080000, CRC(a81ceb7c) SHA1(46b870876bc1f68f242726415f0c49fef7be0c72))
		ROM_LOAD("ic27.rom", 0x00380000, 0x00080000, CRC(707b0c6c) SHA1(345199a33fed23996374b9db8170a52ab63f0380))
	ROM_REGION(0x00800,REGION_GFX1,0)
ROM_END

/*	  YEAR	NAME	  PARENT	COMPAT	MACHINE   INPUT 	INIT	  CONFIG  COMPANY    FULLNAME */
COMP( 1988, a310,	  0,		0,		a310,	  a310, 	NULL,	  NULL,	  "Acorn",   "Archimedes 310" , 0)



