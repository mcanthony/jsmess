#include "emu.h"
#include "includes/pc8401a.h"
#include "video/sed1330.h"
#include "video/mc6845.h"
#include "pc8500.lh"

/* PC-8401A */

static PALETTE_INIT( pc8401a )
{
	palette_set_color(machine, 0, MAKE_RGB(39, 108, 51));
	palette_set_color(machine, 1, MAKE_RGB(16, 37, 84));
}

static VIDEO_START( pc8401a )
{
	pc8401a_state *state = machine->driver_data<pc8401a_state>();

	/* allocate video memory */
	state->video_ram = auto_alloc_array(machine, UINT8, PC8401A_LCD_VIDEORAM_SIZE);

	/* register for state saving */
	state->save_pointer(NAME(state->video_ram), PC8401A_LCD_VIDEORAM_SIZE);
}

static SCREEN_UPDATE( pc8401a )
{
	return 0;
}

/* PC-8500 */

static VIDEO_START( pc8500 )
{
	pc8401a_state *state = machine->driver_data<pc8401a_state>();

	/* find devices */
	state->sed1330 = machine->device(SED1330_TAG);
	state->mc6845 = machine->device(MC6845_TAG);
	state->lcd = machine->device(SCREEN_TAG);

	/* allocate video memory */
	state->video_ram = auto_alloc_array(machine, UINT8, PC8500_LCD_VIDEORAM_SIZE);

	/* register for state saving */
	state->save_pointer(NAME(state->video_ram), PC8500_LCD_VIDEORAM_SIZE);
}

static SCREEN_UPDATE( pc8500 )
{
	pc8401a_state *state = screen->machine->driver_data<pc8401a_state>();

	if (screen == state->lcd)
	{
		sed1330_update(state->sed1330, bitmap, cliprect);
	}
	else
	{
		mc6845_update(state->mc6845, bitmap, cliprect);
	}

	return 0;
}

/* SED1330 Interface */

static READ8_HANDLER( pc8500_sed1330_vd_r )
{
	pc8401a_state *state = space->machine->driver_data<pc8401a_state>();

	return state->video_ram[offset & PC8500_LCD_VIDEORAM_MASK];
}

static WRITE8_HANDLER( pc8500_sed1330_vd_w )
{
	pc8401a_state *state = space->machine->driver_data<pc8401a_state>();

	state->video_ram[offset & PC8500_LCD_VIDEORAM_MASK] = data;
}

static SED1330_INTERFACE( pc8500_sed1330_config )
{
	SCREEN_TAG,
	DEVCB_MEMORY_HANDLER(Z80_TAG, PROGRAM, pc8500_sed1330_vd_r),
	DEVCB_MEMORY_HANDLER(Z80_TAG, PROGRAM, pc8500_sed1330_vd_w)
};

/* MC6845 Interface */

static MC6845_UPDATE_ROW( pc8441a_update_row )
{
}

static const mc6845_interface pc8441a_mc6845_interface = {
	CRT_SCREEN_TAG,
	6,
	NULL,
	pc8441a_update_row,
	NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	NULL
};

/* Machine Drivers */

MACHINE_CONFIG_FRAGMENT( pc8401a_video )
//  MCFG_DEFAULT_LAYOUT(layout_pc8401a)

	MCFG_PALETTE_LENGTH(2)
	MCFG_PALETTE_INIT(pc8401a)

	MCFG_VIDEO_START(pc8401a)

	/* LCD */
	MCFG_SCREEN_ADD(SCREEN_TAG, LCD)
	MCFG_SCREEN_REFRESH_RATE(44)
	MCFG_SCREEN_FORMAT(BITMAP_FORMAT_INDEXED16)
	MCFG_SCREEN_SIZE(480, 128)
	MCFG_SCREEN_VISIBLE_AREA(0, 480-1, 0, 128-1)
	MCFG_SCREEN_UPDATE(pc8401a)
MACHINE_CONFIG_END

MACHINE_CONFIG_FRAGMENT( pc8500_video )
	MCFG_DEFAULT_LAYOUT(layout_pc8500)

	MCFG_PALETTE_LENGTH(2+8)
	MCFG_PALETTE_INIT(pc8401a)

	MCFG_VIDEO_START(pc8500)

	/* LCD */
	MCFG_SCREEN_ADD(SCREEN_TAG, LCD)
	MCFG_SCREEN_REFRESH_RATE(44)
	MCFG_SCREEN_FORMAT(BITMAP_FORMAT_INDEXED16)
	MCFG_SCREEN_SIZE(480, 208)
	MCFG_SCREEN_VISIBLE_AREA(0, 480-1, 0, 200-1)
	MCFG_SCREEN_UPDATE(pc8500)
	
	MCFG_SED1330_ADD(SED1330_TAG, 0, pc8500_sed1330_config)

	/* PC-8441A CRT */
	MCFG_SCREEN_ADD(CRT_SCREEN_TAG, RASTER)
	MCFG_SCREEN_FORMAT(BITMAP_FORMAT_INDEXED16)
	MCFG_SCREEN_SIZE(80*8, 24*8)
	MCFG_SCREEN_VISIBLE_AREA(0, 80*8-1, 0, 24*8-1)
	MCFG_SCREEN_VBLANK_TIME(ATTOSECONDS_IN_USEC(2500))
	MCFG_SCREEN_REFRESH_RATE(50)
	MCFG_SCREEN_UPDATE(pc8500)
	
	MCFG_MC6845_ADD(MC6845_TAG, MC6845, 400000, pc8441a_mc6845_interface)
MACHINE_CONFIG_END
