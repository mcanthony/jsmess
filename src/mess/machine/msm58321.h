/**********************************************************************

    OKI MSM58321 Real Time Clock/Calendar emulation

    Copyright MESS Team.
    Visit http://mamedev.org for licensing and usage restrictions.

**********************************************************************
							_____   _____
				   CS2	 1 |*    \_/     | 16  Vdd
				 WRITE	 2 |			 | 15  XT
				  READ	 3 |			 | 14  _XT
					D0	 4 |   MSM58321	 | 13  CS1
					D1	 5 |			 | 12  TEST
					D2	 6 |			 | 11  STOP
					D3	 7 |			 | 10  _BUSY
				   GND   8 |_____________| 9   ADDRESS WRITE

**********************************************************************/

#ifndef __MSM58321__
#define __MSM58321__

#include "devcb.h"

/***************************************************************************
    MACROS / CONSTANTS
***************************************************************************/

#define MSM58321		DEVICE_GET_INFO_NAME(msm58321)

#define MDRV_MSM58321_ADD(_tag, _clock, _intrf) \
	MDRV_DEVICE_ADD(_tag, MSM58321, _clock) \
	MDRV_DEVICE_CONFIG(_intrf)

#define MSM58321_INTERFACE(name) \
	const msm58321_interface (name)=

/***************************************************************************
    TYPE DEFINITIONS
***************************************************************************/

typedef struct _msm58321_interface msm58321_interface;
struct _msm58321_interface
{
	devcb_write_line	out_busy_func;
};

/***************************************************************************
    PROTOTYPES
***************************************************************************/

/* device interface */
DEVICE_GET_INFO( msm58321 );

/* register access */
READ8_DEVICE_HANDLER( msm58321_a_r );
WRITE8_DEVICE_HANDLER( msm58321_b_w );

/* stop */
WRITE_LINE_DEVICE_HANDLER( msm58321_stop_w );

/* test */
WRITE_LINE_DEVICE_HANDLER( msm58321_test_w );

#endif
