/*****************************************************************************
 *
 * includes/apple1.h
 *
 ****************************************************************************/

#ifndef APPLE1_H_
#define APPLE1_H_

#include "imagedev/snapquik.h"
#include "machine/6821pia.h"

typedef short termchar_t;

typedef struct
{
	tilemap_t *tm;
	int gfx;
	int blank_char;
	int char_bits;
	int num_cols;
	int num_rows;
	int (*getcursorcode)(int original_code);
	int cur_offset;
	int cur_hidden;
	termchar_t mem[1];
} terminal_t;


class apple1_state : public driver_device
{
public:
	apple1_state(running_machine &machine, const driver_device_config_base &config)
		: driver_device(machine, config) { }

	int vh_clrscrn_pressed;
	int kbd_data;
	UINT32 kbd_last_scan[4];
	int reset_flag;
	int cassette_output_flipflop;
	terminal_t *current_terminal;
	terminal_t *terminal;
	int blink_on;
};


/*----------- defined in machine/apple1.c -----------*/

extern const pia6821_interface apple1_pia0;

DRIVER_INIT( apple1 );
MACHINE_RESET( apple1 );
SNAPSHOT_LOAD( apple1 );

READ8_HANDLER( apple1_cassette_r );
WRITE8_HANDLER( apple1_cassette_w );


/*----------- defined in video/apple1.c -----------*/

VIDEO_START( apple1 );
SCREEN_UPDATE( apple1 );

void apple1_vh_dsp_w (running_machine *machine, int data);
void apple1_vh_dsp_clr (running_machine *machine);
attotime apple1_vh_dsp_time_to_ready (running_machine *machine);



/*----------- defined in drivers/apple1.c -----------*/

extern const gfx_layout apple1_charlayout;


#endif /* APPLE1_H_ */
