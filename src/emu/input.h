/***************************************************************************

    input.h

    Handle input from the user.

    Copyright (c) 1996-2007, Nicola Salmoria and the MAME Team.
    Visit http://mamedev.org for licensing and usage restrictions.

***************************************************************************/

#pragma once

#ifndef __INPUT_H__
#define __INPUT_H__

#include "mamecore.h"


/***************************************************************************
    CONSTANTS
***************************************************************************/

/* NOTE: If you modify this value you need also to modify the SEQ_DEF declarations */
#define SEQ_MAX				16

/* MIN/MAX values for analog axes */
/* absolute values should range min..max in its entirety */
#define ANALOG_VALUE_MIN	-65536
#define ANALOG_VALUE_MAX	65536
#define ANALOG_VALUE_INVALID (ANALOG_VALUE_MAX*3)

/* types of analog controls */
enum
{
	ANALOG_TYPE_NONE = 0,
	ANALOG_TYPE_ABSOLUTE = 1,
	ANALOG_TYPE_RELATIVE = 2
};

enum
{
	/* digital keyboard codes */
	KEYCODE_A,
	KEYCODE_B,
	KEYCODE_C,
	KEYCODE_D,
	KEYCODE_E,
	KEYCODE_F,
	KEYCODE_G,
	KEYCODE_H,
	KEYCODE_I,
	KEYCODE_J,
	KEYCODE_K,
	KEYCODE_L,
	KEYCODE_M,
	KEYCODE_N,
	KEYCODE_O,
	KEYCODE_P,
	KEYCODE_Q,
	KEYCODE_R,
	KEYCODE_S,
	KEYCODE_T,
	KEYCODE_U,
	KEYCODE_V,
	KEYCODE_W,
	KEYCODE_X,
	KEYCODE_Y,
	KEYCODE_Z,
	KEYCODE_0,
	KEYCODE_1,
	KEYCODE_2,
	KEYCODE_3,
	KEYCODE_4,
	KEYCODE_5,
	KEYCODE_6,
	KEYCODE_7,
	KEYCODE_8,
	KEYCODE_9,
	KEYCODE_F1,
	KEYCODE_F2,
	KEYCODE_F3,
	KEYCODE_F4,
	KEYCODE_F5,
	KEYCODE_F6,
	KEYCODE_F7,
	KEYCODE_F8,
	KEYCODE_F9,
	KEYCODE_F10,
	KEYCODE_F11,
	KEYCODE_F12,
	KEYCODE_F13,
	KEYCODE_F14,
	KEYCODE_F15,
	KEYCODE_ESC,
	KEYCODE_TILDE,
	KEYCODE_MINUS,
	KEYCODE_EQUALS,
	KEYCODE_BACKSPACE,
	KEYCODE_TAB,
	KEYCODE_OPENBRACE,
	KEYCODE_CLOSEBRACE,
	KEYCODE_ENTER,
	KEYCODE_COLON,
	KEYCODE_QUOTE,
	KEYCODE_BACKSLASH,
	KEYCODE_BACKSLASH2,
	KEYCODE_COMMA,
	KEYCODE_STOP,
	KEYCODE_SLASH,
	KEYCODE_SPACE,
	KEYCODE_INSERT,
	KEYCODE_DEL,
	KEYCODE_HOME,
	KEYCODE_END,
	KEYCODE_PGUP,
	KEYCODE_PGDN,
	KEYCODE_LEFT,
	KEYCODE_RIGHT,
	KEYCODE_UP,
	KEYCODE_DOWN,
	KEYCODE_0_PAD,
	KEYCODE_1_PAD,
	KEYCODE_2_PAD,
	KEYCODE_3_PAD,
	KEYCODE_4_PAD,
	KEYCODE_5_PAD,
	KEYCODE_6_PAD,
	KEYCODE_7_PAD,
	KEYCODE_8_PAD,
	KEYCODE_9_PAD,
	KEYCODE_SLASH_PAD,
	KEYCODE_ASTERISK,
	KEYCODE_MINUS_PAD,
	KEYCODE_PLUS_PAD,
	KEYCODE_DEL_PAD,
	KEYCODE_ENTER_PAD,
	KEYCODE_PRTSCR,
	KEYCODE_PAUSE,
	KEYCODE_LSHIFT,
	KEYCODE_RSHIFT,
	KEYCODE_LCONTROL,
	KEYCODE_RCONTROL,
	KEYCODE_LALT,
	KEYCODE_RALT,
	KEYCODE_SCRLOCK,
	KEYCODE_NUMLOCK,
	KEYCODE_CAPSLOCK,
	KEYCODE_LWIN,
	KEYCODE_RWIN,
	KEYCODE_MENU,
	KEYCODE_CANCEL,

	/* digital joystick codes */
	JOYCODE_1_LEFT,
	JOYCODE_1_RIGHT,
	JOYCODE_1_UP,
	JOYCODE_1_DOWN,
	JOYCODE_1_BUTTON1,
	JOYCODE_1_BUTTON2,
	JOYCODE_1_BUTTON3,
	JOYCODE_1_BUTTON4,
	JOYCODE_1_BUTTON5,
	JOYCODE_1_BUTTON6,
	JOYCODE_1_BUTTON7,
	JOYCODE_1_BUTTON8,
	JOYCODE_1_BUTTON9,
	JOYCODE_1_BUTTON10,
	JOYCODE_1_BUTTON11,
	JOYCODE_1_BUTTON12,
	JOYCODE_1_BUTTON13,
	JOYCODE_1_BUTTON14,
	JOYCODE_1_BUTTON15,
	JOYCODE_1_BUTTON16,
	JOYCODE_1_START,
	JOYCODE_1_SELECT,
	JOYCODE_2_LEFT,
	JOYCODE_2_RIGHT,
	JOYCODE_2_UP,
	JOYCODE_2_DOWN,
	JOYCODE_2_BUTTON1,
	JOYCODE_2_BUTTON2,
	JOYCODE_2_BUTTON3,
	JOYCODE_2_BUTTON4,
	JOYCODE_2_BUTTON5,
	JOYCODE_2_BUTTON6,
	JOYCODE_2_BUTTON7,
	JOYCODE_2_BUTTON8,
	JOYCODE_2_BUTTON9,
	JOYCODE_2_BUTTON10,
	JOYCODE_2_BUTTON11,
	JOYCODE_2_BUTTON12,
	JOYCODE_2_BUTTON13,
	JOYCODE_2_BUTTON14,
	JOYCODE_2_BUTTON15,
	JOYCODE_2_BUTTON16,
	JOYCODE_2_START,
	JOYCODE_2_SELECT,
	JOYCODE_3_LEFT,
	JOYCODE_3_RIGHT,
	JOYCODE_3_UP,
	JOYCODE_3_DOWN,
	JOYCODE_3_BUTTON1,
	JOYCODE_3_BUTTON2,
	JOYCODE_3_BUTTON3,
	JOYCODE_3_BUTTON4,
	JOYCODE_3_BUTTON5,
	JOYCODE_3_BUTTON6,
	JOYCODE_3_BUTTON7,
	JOYCODE_3_BUTTON8,
	JOYCODE_3_BUTTON9,
	JOYCODE_3_BUTTON10,
	JOYCODE_3_BUTTON11,
	JOYCODE_3_BUTTON12,
	JOYCODE_3_BUTTON13,
	JOYCODE_3_BUTTON14,
	JOYCODE_3_BUTTON15,
	JOYCODE_3_BUTTON16,
	JOYCODE_3_START,
	JOYCODE_3_SELECT,
	JOYCODE_4_LEFT,
	JOYCODE_4_RIGHT,
	JOYCODE_4_UP,
	JOYCODE_4_DOWN,
	JOYCODE_4_BUTTON1,
	JOYCODE_4_BUTTON2,
	JOYCODE_4_BUTTON3,
	JOYCODE_4_BUTTON4,
	JOYCODE_4_BUTTON5,
	JOYCODE_4_BUTTON6,
	JOYCODE_4_BUTTON7,
	JOYCODE_4_BUTTON8,
	JOYCODE_4_BUTTON9,
	JOYCODE_4_BUTTON10,
	JOYCODE_4_BUTTON11,
	JOYCODE_4_BUTTON12,
	JOYCODE_4_BUTTON13,
	JOYCODE_4_BUTTON14,
	JOYCODE_4_BUTTON15,
	JOYCODE_4_BUTTON16,
	JOYCODE_4_START,
	JOYCODE_4_SELECT,
	JOYCODE_5_LEFT,
	JOYCODE_5_RIGHT,
	JOYCODE_5_UP,
	JOYCODE_5_DOWN,
	JOYCODE_5_BUTTON1,
	JOYCODE_5_BUTTON2,
	JOYCODE_5_BUTTON3,
	JOYCODE_5_BUTTON4,
	JOYCODE_5_BUTTON5,
	JOYCODE_5_BUTTON6,
	JOYCODE_5_BUTTON7,
	JOYCODE_5_BUTTON8,
	JOYCODE_5_BUTTON9,
	JOYCODE_5_BUTTON10,
	JOYCODE_5_BUTTON11,
	JOYCODE_5_BUTTON12,
	JOYCODE_5_BUTTON13,
	JOYCODE_5_BUTTON14,
	JOYCODE_5_BUTTON15,
	JOYCODE_5_BUTTON16,
	JOYCODE_5_START,
	JOYCODE_5_SELECT,
	JOYCODE_6_LEFT,
	JOYCODE_6_RIGHT,
	JOYCODE_6_UP,
	JOYCODE_6_DOWN,
	JOYCODE_6_BUTTON1,
	JOYCODE_6_BUTTON2,
	JOYCODE_6_BUTTON3,
	JOYCODE_6_BUTTON4,
	JOYCODE_6_BUTTON5,
	JOYCODE_6_BUTTON6,
	JOYCODE_6_BUTTON7,
	JOYCODE_6_BUTTON8,
	JOYCODE_6_BUTTON9,
	JOYCODE_6_BUTTON10,
	JOYCODE_6_BUTTON11,
	JOYCODE_6_BUTTON12,
	JOYCODE_6_BUTTON13,
	JOYCODE_6_BUTTON14,
	JOYCODE_6_BUTTON15,
	JOYCODE_6_BUTTON16,
	JOYCODE_6_START,
	JOYCODE_6_SELECT,
	JOYCODE_7_LEFT,
	JOYCODE_7_RIGHT,
	JOYCODE_7_UP,
	JOYCODE_7_DOWN,
	JOYCODE_7_BUTTON1,
	JOYCODE_7_BUTTON2,
	JOYCODE_7_BUTTON3,
	JOYCODE_7_BUTTON4,
	JOYCODE_7_BUTTON5,
	JOYCODE_7_BUTTON6,
	JOYCODE_7_BUTTON7,
	JOYCODE_7_BUTTON8,
	JOYCODE_7_BUTTON9,
	JOYCODE_7_BUTTON10,
	JOYCODE_7_BUTTON11,
	JOYCODE_7_BUTTON12,
	JOYCODE_7_BUTTON13,
	JOYCODE_7_BUTTON14,
	JOYCODE_7_BUTTON15,
	JOYCODE_7_BUTTON16,
	JOYCODE_7_START,
	JOYCODE_7_SELECT,
	JOYCODE_8_LEFT,
	JOYCODE_8_RIGHT,
	JOYCODE_8_UP,
	JOYCODE_8_DOWN,
	JOYCODE_8_BUTTON1,
	JOYCODE_8_BUTTON2,
	JOYCODE_8_BUTTON3,
	JOYCODE_8_BUTTON4,
	JOYCODE_8_BUTTON5,
	JOYCODE_8_BUTTON6,
	JOYCODE_8_BUTTON7,
	JOYCODE_8_BUTTON8,
	JOYCODE_8_BUTTON9,
	JOYCODE_8_BUTTON10,
	JOYCODE_8_BUTTON11,
	JOYCODE_8_BUTTON12,
	JOYCODE_8_BUTTON13,
	JOYCODE_8_BUTTON14,
	JOYCODE_8_BUTTON15,
	JOYCODE_8_BUTTON16,
	JOYCODE_8_START,
	JOYCODE_8_SELECT,

	/* digital mouse codes */
	MOUSECODE_1_BUTTON1,
	MOUSECODE_1_BUTTON2,
	MOUSECODE_1_BUTTON3,
	MOUSECODE_1_BUTTON4,
	MOUSECODE_1_BUTTON5,
	MOUSECODE_1_BUTTON6,
	MOUSECODE_2_BUTTON1,
	MOUSECODE_2_BUTTON2,
	MOUSECODE_2_BUTTON3,
	MOUSECODE_2_BUTTON4,
	MOUSECODE_2_BUTTON5,
	MOUSECODE_2_BUTTON6,
	MOUSECODE_3_BUTTON1,
	MOUSECODE_3_BUTTON2,
	MOUSECODE_3_BUTTON3,
	MOUSECODE_3_BUTTON4,
	MOUSECODE_3_BUTTON5,
	MOUSECODE_3_BUTTON6,
	MOUSECODE_4_BUTTON1,
	MOUSECODE_4_BUTTON2,
	MOUSECODE_4_BUTTON3,
	MOUSECODE_4_BUTTON4,
	MOUSECODE_4_BUTTON5,
	MOUSECODE_4_BUTTON6,
	MOUSECODE_5_BUTTON1,
	MOUSECODE_5_BUTTON2,
	MOUSECODE_5_BUTTON3,
	MOUSECODE_5_BUTTON4,
	MOUSECODE_5_BUTTON5,
	MOUSECODE_5_BUTTON6,
	MOUSECODE_6_BUTTON1,
	MOUSECODE_6_BUTTON2,
	MOUSECODE_6_BUTTON3,
	MOUSECODE_6_BUTTON4,
	MOUSECODE_6_BUTTON5,
	MOUSECODE_6_BUTTON6,
	MOUSECODE_7_BUTTON1,
	MOUSECODE_7_BUTTON2,
	MOUSECODE_7_BUTTON3,
	MOUSECODE_7_BUTTON4,
	MOUSECODE_7_BUTTON5,
	MOUSECODE_7_BUTTON6,
	MOUSECODE_8_BUTTON1,
	MOUSECODE_8_BUTTON2,
	MOUSECODE_8_BUTTON3,
	MOUSECODE_8_BUTTON4,
	MOUSECODE_8_BUTTON5,
	MOUSECODE_8_BUTTON6,

	/* fake digital input based on mouse axis */
	MOUSECODE_1_X_NEG,
	MOUSECODE_1_X_POS,
	MOUSECODE_1_Y_NEG,
	MOUSECODE_1_Y_POS,
	MOUSECODE_1_Z_NEG,
	MOUSECODE_1_Z_POS,
	MOUSECODE_2_X_NEG,
	MOUSECODE_2_X_POS,
	MOUSECODE_2_Y_NEG,
	MOUSECODE_2_Y_POS,
	MOUSECODE_2_Z_NEG,
	MOUSECODE_2_Z_POS,
	MOUSECODE_3_X_NEG,
	MOUSECODE_3_X_POS,
	MOUSECODE_3_Y_NEG,
	MOUSECODE_3_Y_POS,
	MOUSECODE_3_Z_NEG,
	MOUSECODE_3_Z_POS,
	MOUSECODE_4_X_NEG,
	MOUSECODE_4_X_POS,
	MOUSECODE_4_Y_NEG,
	MOUSECODE_4_Y_POS,
	MOUSECODE_4_Z_NEG,
	MOUSECODE_4_Z_POS,
	MOUSECODE_5_X_NEG,
	MOUSECODE_5_X_POS,
	MOUSECODE_5_Y_NEG,
	MOUSECODE_5_Y_POS,
	MOUSECODE_5_Z_NEG,
	MOUSECODE_5_Z_POS,
	MOUSECODE_6_X_NEG,
	MOUSECODE_6_X_POS,
	MOUSECODE_6_Y_NEG,
	MOUSECODE_6_Y_POS,
	MOUSECODE_6_Z_NEG,
	MOUSECODE_6_Z_POS,
	MOUSECODE_7_X_NEG,
	MOUSECODE_7_X_POS,
	MOUSECODE_7_Y_NEG,
	MOUSECODE_7_Y_POS,
	MOUSECODE_7_Z_NEG,
	MOUSECODE_7_Z_POS,
	MOUSECODE_8_X_NEG,
	MOUSECODE_8_X_POS,
	MOUSECODE_8_Y_NEG,
	MOUSECODE_8_Y_POS,
	MOUSECODE_8_Z_NEG,
	MOUSECODE_8_Z_POS,


	/* analog codes of all sorts */
#define __code_absolute_analog_start JOYCODE_1_ANALOG_X
	JOYCODE_1_ANALOG_X,
	JOYCODE_1_ANALOG_X_NEG,
	JOYCODE_1_ANALOG_X_POS,
	JOYCODE_1_ANALOG_Y,
	JOYCODE_1_ANALOG_Y_NEG,
	JOYCODE_1_ANALOG_Y_POS,
	JOYCODE_1_ANALOG_Z,
	JOYCODE_1_ANALOG_Z_NEG,
	JOYCODE_1_ANALOG_Z_POS,
	JOYCODE_2_ANALOG_X,
	JOYCODE_2_ANALOG_X_NEG,
	JOYCODE_2_ANALOG_X_POS,
	JOYCODE_2_ANALOG_Y,
	JOYCODE_2_ANALOG_Y_NEG,
	JOYCODE_2_ANALOG_Y_POS,
	JOYCODE_2_ANALOG_Z,
	JOYCODE_2_ANALOG_Z_NEG,
	JOYCODE_2_ANALOG_Z_POS,
	JOYCODE_3_ANALOG_X,
	JOYCODE_3_ANALOG_X_NEG,
	JOYCODE_3_ANALOG_X_POS,
	JOYCODE_3_ANALOG_Y,
	JOYCODE_3_ANALOG_Y_NEG,
	JOYCODE_3_ANALOG_Y_POS,
	JOYCODE_3_ANALOG_Z,
	JOYCODE_3_ANALOG_Z_NEG,
	JOYCODE_3_ANALOG_Z_POS,
	JOYCODE_4_ANALOG_X,
	JOYCODE_4_ANALOG_X_NEG,
	JOYCODE_4_ANALOG_X_POS,
	JOYCODE_4_ANALOG_Y,
	JOYCODE_4_ANALOG_Y_NEG,
	JOYCODE_4_ANALOG_Y_POS,
	JOYCODE_4_ANALOG_Z,
	JOYCODE_4_ANALOG_Z_NEG,
	JOYCODE_4_ANALOG_Z_POS,
	JOYCODE_5_ANALOG_X,
	JOYCODE_5_ANALOG_X_NEG,
	JOYCODE_5_ANALOG_X_POS,
	JOYCODE_5_ANALOG_Y,
	JOYCODE_5_ANALOG_Y_NEG,
	JOYCODE_5_ANALOG_Y_POS,
	JOYCODE_5_ANALOG_Z,
	JOYCODE_5_ANALOG_Z_NEG,
	JOYCODE_5_ANALOG_Z_POS,
	JOYCODE_6_ANALOG_X,
	JOYCODE_6_ANALOG_X_NEG,
	JOYCODE_6_ANALOG_X_POS,
	JOYCODE_6_ANALOG_Y,
	JOYCODE_6_ANALOG_Y_NEG,
	JOYCODE_6_ANALOG_Y_POS,
	JOYCODE_6_ANALOG_Z,
	JOYCODE_6_ANALOG_Z_NEG,
	JOYCODE_6_ANALOG_Z_POS,
	JOYCODE_7_ANALOG_X,
	JOYCODE_7_ANALOG_X_NEG,
	JOYCODE_7_ANALOG_X_POS,
	JOYCODE_7_ANALOG_Y,
	JOYCODE_7_ANALOG_Y_NEG,
	JOYCODE_7_ANALOG_Y_POS,
	JOYCODE_7_ANALOG_Z,
	JOYCODE_7_ANALOG_Z_NEG,
	JOYCODE_7_ANALOG_Z_POS,
	JOYCODE_8_ANALOG_X,
	JOYCODE_8_ANALOG_X_NEG,
	JOYCODE_8_ANALOG_X_POS,
	JOYCODE_8_ANALOG_Y,
	JOYCODE_8_ANALOG_Y_NEG,
	JOYCODE_8_ANALOG_Y_POS,
	JOYCODE_8_ANALOG_Z,
	JOYCODE_8_ANALOG_Z_NEG,
	JOYCODE_8_ANALOG_Z_POS,
	GUNCODE_1_ANALOG_X,
	GUNCODE_1_ANALOG_Y,
	GUNCODE_2_ANALOG_X,
	GUNCODE_2_ANALOG_Y,
	GUNCODE_3_ANALOG_X,
	GUNCODE_3_ANALOG_Y,
	GUNCODE_4_ANALOG_X,
	GUNCODE_4_ANALOG_Y,
	GUNCODE_5_ANALOG_X,
	GUNCODE_5_ANALOG_Y,
	GUNCODE_6_ANALOG_X,
	GUNCODE_6_ANALOG_Y,
	GUNCODE_7_ANALOG_X,
	GUNCODE_7_ANALOG_Y,
	GUNCODE_8_ANALOG_X,
	GUNCODE_8_ANALOG_Y,
#define __code_absolute_analog_end GUNCODE_8_ANALOG_Y
#define __code_relative_analog_start MOUSECODE_1_ANALOG_X
	MOUSECODE_1_ANALOG_X,
	MOUSECODE_1_ANALOG_Y,
	MOUSECODE_1_ANALOG_Z,
	MOUSECODE_2_ANALOG_X,
	MOUSECODE_2_ANALOG_Y,
	MOUSECODE_2_ANALOG_Z,
	MOUSECODE_3_ANALOG_X,
	MOUSECODE_3_ANALOG_Y,
	MOUSECODE_3_ANALOG_Z,
	MOUSECODE_4_ANALOG_X,
	MOUSECODE_4_ANALOG_Y,
	MOUSECODE_4_ANALOG_Z,
	MOUSECODE_5_ANALOG_X,
	MOUSECODE_5_ANALOG_Y,
	MOUSECODE_5_ANALOG_Z,
	MOUSECODE_6_ANALOG_X,
	MOUSECODE_6_ANALOG_Y,
	MOUSECODE_6_ANALOG_Z,
	MOUSECODE_7_ANALOG_X,
	MOUSECODE_7_ANALOG_Y,
	MOUSECODE_7_ANALOG_Z,
	MOUSECODE_8_ANALOG_X,
	MOUSECODE_8_ANALOG_Y,
	MOUSECODE_8_ANALOG_Z,
#define __code_relative_analog_end MOUSECODE_8_ANALOG_Z

	__code_max,					/* Temination of standard code */

	/* special */
	CODE_NONE = 0x8000,			/* no code, also marker of sequence end */
	CODE_OTHER_DIGITAL,			/* OS code not mapped to any other code */
	CODE_OTHER_ANALOG_ABSOLUTE,	/* OS code not mapped to any other code */
	CODE_OTHER_ANALOG_RELATIVE,	/* OS code not mapped to any other code */
	CODE_DEFAULT,				/* special for input port definitions */
	CODE_NOT,					/* operators for sequences */
	CODE_OR						/* operators for sequences */
};



/***************************************************************************
    TYPE DEFINITIONS
***************************************************************************/

struct _input_seq
{
	input_code code[SEQ_MAX];
};
typedef struct _input_seq input_seq;



/***************************************************************************
    MACROS
***************************************************************************/

/* NOTE: It's very important that this sequence is EXACTLY as long as SEQ_MAX */
#define SEQ_DEF_6(a,b,c,d,e,f) {{ a, b, c, d, e, f, CODE_NONE, CODE_NONE, CODE_NONE, CODE_NONE, CODE_NONE, CODE_NONE, CODE_NONE, CODE_NONE, CODE_NONE, CODE_NONE }}
#define SEQ_DEF_5(a,b,c,d,e) SEQ_DEF_6(a,b,c,d,e,CODE_NONE)
#define SEQ_DEF_4(a,b,c,d) SEQ_DEF_5(a,b,c,d,CODE_NONE)
#define SEQ_DEF_3(a,b,c) SEQ_DEF_4(a,b,c,CODE_NONE)
#define SEQ_DEF_2(a,b) SEQ_DEF_3(a,b,CODE_NONE)
#define SEQ_DEF_1(a) SEQ_DEF_2(a,CODE_NONE)
#define SEQ_DEF_0 SEQ_DEF_1(CODE_NONE)



/***************************************************************************
    FUNCTION PROTOTYPES
***************************************************************************/

/* single code functions */
void code_init(running_machine *machine);

INT32 code_analog_value(input_code code);
int code_pressed(input_code code);
int code_pressed_memory(input_code code);
int code_pressed_memory_repeat(input_code code, int speed);
input_code code_read_async(void);

int code_analog_type(input_code code);
const char *code_name(input_code code);
input_code token_to_code(const char *token);
void code_to_token(input_code code, char *token);

/* Sequence code funtions */
void seq_set_0(input_seq *seq);
void seq_set_1(input_seq *seq, input_code code);
void seq_set_2(input_seq *seq, input_code code1, input_code code2);
void seq_set_3(input_seq *seq, input_code code1, input_code code2, input_code code3);
void seq_set_4(input_seq *seq, input_code code1, input_code code2, input_code code3, input_code code4);
void seq_set_5(input_seq *seq, input_code code1, input_code code2, input_code code3, input_code code4, input_code code5);
void seq_copy(input_seq *seqdst, const input_seq *seqsrc);
int seq_cmp(const input_seq *seqa, const input_seq *seqb);
char *seq_name(const input_seq *seq, char *buffer, unsigned max);
int seq_pressed(const input_seq *seq);
INT32 seq_analog_value(const input_seq *seq, int *analogtype);
void seq_read_async_start(int analog);
int seq_read_async(input_seq *seq, int first);
int string_to_seq(const char *string, input_seq *seq);
void seq_to_string(const input_seq *seq, char *string, int maxlen);

INLINE input_code seq_get_1(const input_seq *seq) { return seq->code[0]; }

#endif	/* __INPUT_H__ */
