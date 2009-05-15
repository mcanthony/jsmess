/***************************************************************************

        IQ-151

        12/05/2009 Skeleton driver.

****************************************************************************/

#include "driver.h"
#include "cpu/z80/z80.h"

static ADDRESS_MAP_START(iq151_mem, ADDRESS_SPACE_PROGRAM, 8)
	ADDRESS_MAP_UNMAP_HIGH
ADDRESS_MAP_END

static ADDRESS_MAP_START( iq151_io , ADDRESS_SPACE_IO, 8)
	ADDRESS_MAP_UNMAP_HIGH
ADDRESS_MAP_END

/* Input ports */
INPUT_PORTS_START( iq151 )
INPUT_PORTS_END


static MACHINE_RESET(iq151)
{
}

static VIDEO_START( iq151 )
{
}

static VIDEO_UPDATE( iq151 )
{
    return 0;
}

static MACHINE_DRIVER_START( iq151 )
    /* basic machine hardware */
    MDRV_CPU_ADD("maincpu",Z80, XTAL_4MHz)
    MDRV_CPU_PROGRAM_MAP(iq151_mem)
    MDRV_CPU_IO_MAP(iq151_io)

    MDRV_MACHINE_RESET(iq151)

    /* video hardware */
    MDRV_SCREEN_ADD("screen", RASTER)
    MDRV_SCREEN_REFRESH_RATE(50)
    MDRV_SCREEN_VBLANK_TIME(ATTOSECONDS_IN_USEC(2500)) /* not accurate */
    MDRV_SCREEN_FORMAT(BITMAP_FORMAT_INDEXED16)
    MDRV_SCREEN_SIZE(640, 480)
    MDRV_SCREEN_VISIBLE_AREA(0, 640-1, 0, 480-1)
    MDRV_PALETTE_LENGTH(2)
    MDRV_PALETTE_INIT(black_and_white)

    MDRV_VIDEO_START(iq151)
    MDRV_VIDEO_UPDATE(iq151)
MACHINE_DRIVER_END

static SYSTEM_CONFIG_START(iq151)
SYSTEM_CONFIG_END

/* ROM definition */
ROM_START( iq151 )
    ROM_REGION( 0x10000, "maincpu", ROMREGION_ERASEFF )
  ROM_LOAD( "iq151_disc2_12_5_1987_v4_0.rom", 0x0000, 0x0800, CRC(b189b170) SHA1(3e2ca80934177e7a32d0905f5a0ad14072f9dabf))
  ROM_LOAD( "iq151_monitor_cpm.rom", 0x0000, 0x1000, CRC(26f57013) SHA1(4df396edc375dd2dd3c82c4d2affb4f5451066f1))
  ROM_LOAD( "iq151_monitor_cpm_old.rom", 0x0000, 0x1000, CRC(6743e1b7) SHA1(ae4f3b1ba2511a1f91c4e8afdfc0e5aeb0fb3a42))
  ROM_LOAD( "iq151_monitor_disasm.rom", 0x0000, 0x1000, CRC(45c2174e) SHA1(703e3271a124c3ef9330ae399308afd903316ab9))
  ROM_LOAD( "iq151_monitor_orig.rom", 0x0000, 0x1000, CRC(acd10268) SHA1(4d75c73f155ed4dc2ac51a9c22232f869cca95e2))
  ROM_LOAD( "iq151_video32font.rom", 0x0000, 0x0400, CRC(395567a7) SHA1(18800543daf4daed3f048193c6ae923b4b0e87db))
  ROM_LOAD( "iq151_video64font.rom", 0x0000, 0x0800, CRC(cb6f43c0) SHA1(4b2c1d41838d569228f61568c1a16a8d68b3dadf))

ROM_END

/* Driver */

/*    YEAR  NAME    PARENT  COMPAT   MACHINE    INPUT    INIT    CONFIG COMPANY   FULLNAME       FLAGS */
COMP( ????, iq151,  0,       0, 	iq151, 	iq151, 	 0,  	  iq151,  	 "ZPA Novy Bor",   "IQ-151",		GAME_NOT_WORKING)

