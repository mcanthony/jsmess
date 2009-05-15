/******************************************************************************
 *
 *  Acorn Archimedes 310
 *
 *  Skeleton: Juergen Buchmueller <pullmoll@t-online.de>, Jul 2000
 *  Enhanced: R. Belmont, June 2007
 *
 *      Memory map (from http://b-em.bbcmicro.com/arculator/archdocs.txt)
 *
 *  0000000 - 1FFFFFF - logical RAM (32 meg)
 *  2000000 - 2FFFFFF - physical RAM (supervisor only - max 16MB - requires quad MEMCs)
 *  3000000 - 33FFFFF - IOC (IO controllers - supervisor only)
 *  3310000 - FDC - WD1772
 *  33A0000 - Econet - 6854
 *  33B0000 - Serial - 6551
 *  3240000 - 33FFFFF - internal expansion cards
 *  32D0000 - hard disc controller (not IDE) - HD63463
 *  3350010 - printer
 *  3350018 - latch A
 *  3350040 - latch B
 *  3270000 - external expansion cards
 *
 *  3400000 - 3FFFFFF - ROM (read - 12 meg - Arthur and RiscOS 2 512k, RiscOS 3 2MB)
 *  3400000 - 37FFFFF - Low ROM  (4 meg, I think this is expansion ROMs)
 *  3800000 - 3FFFFFF - High ROM (main OS ROM)
 *
 *  3400000 - 35FFFFF - VICD10 (write - supervisor only)
 *  3600000 - 3FFFFFF - MEMC (write - supervisor only)
 *
 *****************************************************************************/

#include "driver.h"
#include "machine/wd17xx.h"
#include "devices/basicdsk.h"
#include "cpu/arm/arm.h"
#include "sound/dac.h"
#include "includes/archimds.h"

static VIDEO_START( a310 )
{
}

static VIDEO_UPDATE( a310 )
{
	return 0;
}

static WD17XX_CALLBACK ( a310_wd177x_callback )
{
	switch (state)
	{
		case WD17XX_IRQ_CLR:
			archimedes_clear_fiq(device->machine, ARCHIMEDES_FIQ_FLOPPY);
			break;

		case WD17XX_IRQ_SET:
			archimedes_request_fiq(device->machine, ARCHIMEDES_FIQ_FLOPPY);
			break;

		case WD17XX_DRQ_CLR:
			archimedes_clear_fiq(device->machine, ARCHIMEDES_FIQ_FLOPPY_DRQ);
			break;

		case WD17XX_DRQ_SET:
			archimedes_request_fiq(device->machine, ARCHIMEDES_FIQ_FLOPPY_DRQ);
			break;
	}
}

static DRIVER_INIT(a310)
{
	archimedes_driver_init(machine);
}

static MACHINE_START( a310 )
{
	archimedes_init(machine);

	// reset the DAC to centerline
	dac_signed_data_w(devtag_get_device(machine, "dac"), 0x80);
}

static MACHINE_RESET( a310 )
{
	archimedes_reset(machine);
}

static ADDRESS_MAP_START( a310_mem, ADDRESS_SPACE_PROGRAM, 32 )
	AM_RANGE(0x00000000, 0x01ffffff) AM_READWRITE(memc_logical_r, memc_logical_w)
	AM_RANGE(0x02000000, 0x02ffffff) AM_RAM AM_BASE(&memc_physmem) /* physical RAM - 16 MB for now, should be 512k for the A310 */
	AM_RANGE(0x03000000, 0x033fffff) AM_READWRITE(ioc_r, ioc_w)
	AM_RANGE(0x03400000, 0x035fffff) AM_READWRITE(vidc_r, vidc_w)
	AM_RANGE(0x03600000, 0x037fffff) AM_READWRITE(memc_r, memc_w)
	AM_RANGE(0x03800000, 0x03ffffff) AM_ROM AM_REGION("maincpu", 0) AM_WRITE(memc_page_w)
ADDRESS_MAP_END


static INPUT_PORTS_START( a310 )
	PORT_START("dip") /* DIP switches */
	PORT_BIT(0xfd, 0xfd, IPT_UNUSED)

	PORT_START("key0") /* KEY ROW 0 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("ESC") PORT_CODE(KEYCODE_ESC)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("1  !") PORT_CODE(KEYCODE_1)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("2  \"") PORT_CODE(KEYCODE_2)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("3  #") PORT_CODE(KEYCODE_3)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("4  $") PORT_CODE(KEYCODE_4)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("5  %") PORT_CODE(KEYCODE_5)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("6  &") PORT_CODE(KEYCODE_6)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("7  '") PORT_CODE(KEYCODE_7)

	PORT_START("key1") /* KEY ROW 1 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("8  *") PORT_CODE(KEYCODE_8)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("9  (") PORT_CODE(KEYCODE_9)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("0  )") PORT_CODE(KEYCODE_0)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("-  _") PORT_CODE(KEYCODE_MINUS)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("=  +") PORT_CODE(KEYCODE_EQUALS)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("`  ~") PORT_CODE(KEYCODE_TILDE)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("BACK SPACE") PORT_CODE(KEYCODE_BACKSPACE)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("TAB") PORT_CODE(KEYCODE_TAB)

	PORT_START("key2") /* KEY ROW 2 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("q  Q") PORT_CODE(KEYCODE_Q)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("w  W") PORT_CODE(KEYCODE_W)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("e  E") PORT_CODE(KEYCODE_E)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("r  R") PORT_CODE(KEYCODE_R)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("t  T") PORT_CODE(KEYCODE_T)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("y  Y") PORT_CODE(KEYCODE_Y)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("u  U") PORT_CODE(KEYCODE_U)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("i  I") PORT_CODE(KEYCODE_I)

	PORT_START("key3") /* KEY ROW 3 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("o  O") PORT_CODE(KEYCODE_O)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("p  P") PORT_CODE(KEYCODE_P)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("[  {") PORT_CODE(KEYCODE_OPENBRACE)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("]  }") PORT_CODE(KEYCODE_CLOSEBRACE)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("RETURN") PORT_CODE(KEYCODE_ENTER)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("DEL") PORT_CODE(KEYCODE_DEL)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("CTRL") PORT_CODE(KEYCODE_LCONTROL)
	PORT_BIT(0x80, 0x80, IPT_KEYBOARD) PORT_NAME("CAPS LOCK") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE

	PORT_START("key4") /* KEY ROW 4 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("a  A") PORT_CODE(KEYCODE_A)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("s  S") PORT_CODE(KEYCODE_S)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("d  D") PORT_CODE(KEYCODE_D)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("f  F") PORT_CODE(KEYCODE_F)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("g  G") PORT_CODE(KEYCODE_G)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("h  H") PORT_CODE(KEYCODE_H)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("j  J") PORT_CODE(KEYCODE_J)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("k  K") PORT_CODE(KEYCODE_K)

	PORT_START("key5") /* KEY ROW 5 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("l  L") PORT_CODE(KEYCODE_L)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME(";  :") PORT_CODE(KEYCODE_COLON)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("'  \"") PORT_CODE(KEYCODE_QUOTE)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("\\  |") PORT_CODE(KEYCODE_ASTERISK)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("SHIFT (L)") PORT_CODE(KEYCODE_LSHIFT)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("z  Z") PORT_CODE(KEYCODE_Z)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("x  X") PORT_CODE(KEYCODE_X)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("c  C") PORT_CODE(KEYCODE_C)

	PORT_START("key6") /* KEY ROW 6 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("v  V") PORT_CODE(KEYCODE_V)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("b  B") PORT_CODE(KEYCODE_B)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("n  N") PORT_CODE(KEYCODE_N)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("m  M") PORT_CODE(KEYCODE_M)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME(",  <") PORT_CODE(KEYCODE_COMMA)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME(".  >") PORT_CODE(KEYCODE_STOP)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("/  ?") PORT_CODE(KEYCODE_SLASH)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("SHIFT (R)") PORT_CODE(KEYCODE_RSHIFT)

	PORT_START("key7") /* KEY ROW 7 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("LINE FEED")
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("SPACE") PORT_CODE(KEYCODE_SPACE)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("- (KP)") PORT_CODE(KEYCODE_MINUS_PAD)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME(", (KP)") PORT_CODE(KEYCODE_PLUS_PAD)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("ENTER (KP)") PORT_CODE(KEYCODE_ENTER_PAD)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME(". (KP)") PORT_CODE(KEYCODE_DEL_PAD)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("0 (KP)") PORT_CODE(KEYCODE_0_PAD)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("1 (KP)") PORT_CODE(KEYCODE_1_PAD)

	PORT_START("key8") /* KEY ROW 8 */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("2 (KP)") PORT_CODE(KEYCODE_2_PAD)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("3 (KP)") PORT_CODE(KEYCODE_3_PAD)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("4 (KP)") PORT_CODE(KEYCODE_4_PAD)
	PORT_BIT(0x08, 0x00, IPT_KEYBOARD) PORT_NAME("5 (KP)") PORT_CODE(KEYCODE_5_PAD)
	PORT_BIT(0x10, 0x00, IPT_KEYBOARD) PORT_NAME("6 (KP)") PORT_CODE(KEYCODE_6_PAD)
	PORT_BIT(0x20, 0x00, IPT_KEYBOARD) PORT_NAME("7 (KP)") PORT_CODE(KEYCODE_7_PAD)
	PORT_BIT(0x40, 0x00, IPT_KEYBOARD) PORT_NAME("8 (KP)") PORT_CODE(KEYCODE_8_PAD)
	PORT_BIT(0x80, 0x00, IPT_KEYBOARD) PORT_NAME("9 (KP)") PORT_CODE(KEYCODE_9_PAD)

	PORT_START("via1a") /* VIA #1 PORT A */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1					 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON2					 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_4WAY
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_4WAY
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_4WAY
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_4WAY

	PORT_START("tape")/* tape control */
	PORT_BIT(0x01, 0x00, IPT_KEYBOARD) PORT_NAME("TAPE STOP") PORT_CODE(KEYCODE_F5)
	PORT_BIT(0x02, 0x00, IPT_KEYBOARD) PORT_NAME("TAPE PLAY") PORT_CODE(KEYCODE_F6)
	PORT_BIT(0x04, 0x00, IPT_KEYBOARD) PORT_NAME("TAPE REW") PORT_CODE(KEYCODE_F7)
	PORT_BIT (0xf8, 0x80, IPT_UNUSED)
INPUT_PORTS_END

static const wd17xx_interface a310_wd17xx_interface = {
	a310_wd177x_callback,
	NULL
};

static MACHINE_DRIVER_START( a310 )
	/* basic machine hardware */
	MDRV_CPU_ADD("maincpu", ARM, 8000000)        /* 8 MHz */
	MDRV_CPU_PROGRAM_MAP(a310_mem)

	MDRV_MACHINE_RESET( a310 )
	MDRV_MACHINE_START( a310 )

	/* video hardware */
	MDRV_SCREEN_ADD("screen", RASTER)
	MDRV_SCREEN_REFRESH_RATE(60)
	MDRV_SCREEN_VBLANK_TIME(ATTOSECONDS_IN_USEC(2500)) /* not accurate */
	MDRV_SCREEN_FORMAT(BITMAP_FORMAT_INDEXED16)
	MDRV_SCREEN_SIZE(32*8, 16*16)
	MDRV_SCREEN_VISIBLE_AREA(0*8, 32*8 - 1, 0*16, 16*16 - 1)
	MDRV_PALETTE_LENGTH(32768)

	MDRV_VIDEO_START(a310)
	MDRV_VIDEO_UPDATE(a310)

	MDRV_SPEAKER_STANDARD_MONO("a310")
	MDRV_SOUND_ADD("dac", DAC, 0)
	MDRV_SOUND_ROUTE(0, "a310", 1.00)
	
	MDRV_WD1772_ADD("wd1772", a310_wd17xx_interface )
MACHINE_DRIVER_END

ROM_START(a310)
	ROM_REGION(0x800000, "maincpu", 0)
	ROM_SYSTEM_BIOS(0, "311", "RiscOS 3.11 (29 Sep 1992)")
	ROMX_LOAD("ic24.rom", 0x000000, 0x80000, CRC(c1adde84) SHA1(12d060e0401dd0523d44453f947bdc55dd2c3240), ROM_BIOS(1))
	ROMX_LOAD("ic25.rom", 0x080000, 0x80000, CRC(15d89664) SHA1(78f5d0e6f1e8ee603317807f53ff8fe65a3b3518), ROM_BIOS(1))
	ROMX_LOAD("ic26.rom", 0x100000, 0x80000, CRC(a81ceb7c) SHA1(46b870876bc1f68f242726415f0c49fef7be0c72), ROM_BIOS(1))
	ROMX_LOAD("ic27.rom", 0x180000, 0x80000, CRC(707b0c6c) SHA1(345199a33fed23996374b9db8170a52ab63f0380), ROM_BIOS(1))
	ROM_SYSTEM_BIOS(1, "120", "Arthur/RiscOS 1.20 (25 Sep 1987)")
	ROMX_LOAD( "arthur.bin",   0x000000, 0x080001, CRC(453b09df) SHA1(0c27c7b5a414a96b54be15e0388c97fb4fcc8a5e), ROM_BIOS(2))
	ROM_SYSTEM_BIOS(2, "200", "RiscOS 2.0 (05 Oct 1988)")	
	ROMX_LOAD( "riscos2.bin",  0x000000, 0x080000, CRC(89c4ad36) SHA1(b82a78830dac386f9b649b6d32a34f9c6910546d), ROM_BIOS(3))
	ROM_REGION(0x00800, "gfx1", 0)
ROM_END

/*    YEAR  NAME  PARENT  COMPAT  MACHINE  INPUT     INIT  CONFIG  COMPANY  FULLNAME */
COMP( 1988, a310, 0,      0,      a310,    a310,  a310, NULL,   "Acorn", "Archimedes 310 (Risc OS 3.11)", GAME_NOT_WORKING)


