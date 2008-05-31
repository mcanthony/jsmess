#include "driver.h"

#include "includes/hp48.h"

/*
  0
  1bc
  1fc6
  1fe3 configure memory
   2248
   2256
  201a power control register loaded (currently 1!)
  202e
   26fd copies 0x36 nibbles from 701c to 700a !
    c192 ram address into d0
	11fc
   2494
   1929
    13437
 */

enum {
	HP48_ROM,
	HP48_CARD1,
	HP48_CARD2,
	HP48_RAM,
	HP48_HDW,
	HP48_END
};






UINT8 *hp48_ram, *hp48_card1, *hp48_card2;
static int out;

#define HDW 0
#define RAM 1
#define CARD2 2
#define CARD1 3
#define NCE3
#define ROM 4
static struct {
	int state;
	struct {
		int realsize,
			adr,/* a11..a0 ignored */
			size;/* a19..a12 comparator select, 1 means address line must match adr */
	} mem[5];
} hp48s= {
	0,
	{
		{ 32 }, // no size configure, only a4..a0 ignored
		{ 128*1024 }, //s 32kb, sx 128kb
		{ 32*1024 }, // card2 32 kb or 128kb
		{ 32*1024 }, // card1 32 kb or 128kb
		{ 256*1024, 0 } // not configurable, always visible
	}
};

static struct {
	UINT8	*base;
	UINT8	type;
} hp48_banks[129];

// to do support weired comparator settings
static void hp48_config(running_machine *machine)
{
	static const read8_machine_func read_handlers[11] = { 0, SMH_BANK1, SMH_BANK2, SMH_BANK3, SMH_BANK4, SMH_BANK5, SMH_BANK6, SMH_BANK7, SMH_BANK8, SMH_BANK9, SMH_BANK10 };
	int i, begin_bank, end_bank, begin, end, mem_type, bank;

	/* Determine the current memory map */

	/* Lowest priority is ROM */
	for ( i = 0; i < 128; i++ ) {
		hp48_banks[i].base = memory_region( REGION_CPU1 ) + i * 0x2000;
		hp48_banks[i].type = HP48_ROM;
	}
	hp48_banks[128].type = HP48_END;

	/* Next priority is CARD1 */
	if ( hp48s.mem[CARD1].adr != -1 ) {
		logerror("hp48_config CARD1 should be configured\n");
		begin_bank = ( ( hp48s.mem[CARD1].adr & ~( hp48s.mem[CARD1].size - 1 ) ) >> 13 ) & 0x7F;
		end_bank = begin_bank | ( ( hp48s.mem[CARD1].size - 1 ) >> 13 );
		for ( i = begin_bank; i <= end_bank; i++ ) {
			hp48_banks[i].base = hp48_card1 + i * 0x2000;
			hp48_banks[i].type = HP48_CARD1;
		}
		logerror("CARD1 begin = %02X, end = %02X\n", begin_bank, end_bank);
	}

	/* Next priority is CARD2 */
	if ( hp48s.mem[CARD2].adr != -1 ) {
		logerror("hp48_config CARD2 should be configured\n");
		begin_bank = ( ( hp48s.mem[CARD2].adr & ~( hp48s.mem[CARD2].size - 1 ) ) >> 13 ) & 0x7F;
		end_bank = begin_bank | ( ( hp48s.mem[CARD2].size - 1 ) >> 13 );
		for ( i = begin_bank; i <= end_bank; i++ ) {
			hp48_banks[i].base = hp48_card2 + i * 0x2000;
			hp48_banks[i].type = HP48_CARD2;
		}
		logerror("CARD2 begin = %02X, end = %02X\n", begin_bank, end_bank);
	}

	/* Next priority is RAM */
	if ( hp48s.mem[RAM].adr != -1 ) {
		logerror("hp48_config RAM should be configured\n");
		begin_bank = ( ( hp48s.mem[RAM].adr & ~( hp48s.mem[RAM].size - 1 ) ) >> 13 ) & 0x7F;
		end_bank = begin_bank | ( ( hp48s.mem[RAM].size - 1 ) >> 13 );
		for ( i = begin_bank; i <= end_bank; i++ ) {
			hp48_banks[i].base = hp48_ram + i * 0x2000;
			hp48_banks[i].type = HP48_RAM;
		}
		logerror("RAM begin = %02X, end = %02X\n", begin_bank, end_bank);
	}

	/* Highest priority is HDW */

	/* Set up dynamic bank configuration */
	bank = 1;
	begin_bank = end_bank = 0;
	mem_type = hp48_banks[begin_bank].type;
	for ( i = 1; i < 129; i++ ) {
		if ( hp48_banks[i].type != mem_type ) {
			begin = begin_bank << 13;
			end = ( end_bank << 13 ) | 0x1FFF;

			memory_install_read8_handler(machine, 0, ADDRESS_SPACE_PROGRAM, begin, end, 0, 0, read_handlers[bank] );
			memory_set_bankptr( bank, hp48_banks[begin_bank].base );

			bank++;
			begin_bank = i;
			mem_type = hp48_banks[i].type;
		}
		end_bank = i;
	}

	if ( hp48s.mem[HDW].adr != -1 ) {
		memory_install_read8_handler(machine, 0, ADDRESS_SPACE_PROGRAM, hp48s.mem[HDW].adr&~0x3f,
								 hp48s.mem[HDW].adr|0x3f, 0, 0, hp48_read);
//		memory_install_write8_handler(machine, 0, ADDRESS_SPACE_PROGRAM, hp48s.mem[HDW].adr&~0x3f,
//								  hp48s.mem[HDW].adr|0x3f, 0, 0, hp48_write);
	}
}

WRITE8_HANDLER( hp48_mem_w ) {
	int	bank = ( offset >> 13 ) & 0x7F;
	//logerror("hp48_mem_w: offset = %06X, data = %02X\n", offset, data );

	/* Check for write to HDW */
	if ( hp48s.mem[HDW].adr != -1 && offset >= hp48s.mem[HDW].adr && offset < hp48s.mem[HDW].adr + 0x40 ) {
		hp48_write( machine, offset & 0x3F, data );
	} else {
		switch( hp48_banks[bank].type ) {
		case HP48_RAM:
			//logerror("RAM write\n");
			hp48_banks[bank].base[offset & 0x1FFF] = data;
			break;
		case HP48_CARD1:
			//logerror("CARD1 write\n");
			hp48_banks[bank].base[offset & 0x1FFF] = data;
			break;
		case HP48_CARD2:
			//logerror("CARD2 write\n");
			hp48_banks[bank].base[offset & 0x1FFF] = data;
			break;
		}
	}
}

/* priority on the bus
   hdw, ram, ce2, ce1, nce3, rom */
void hp48_mem_reset(running_machine *machine)
{
	int i;
	hp48s.state=0;

	for (i=0; i+1< sizeof(hp48s.mem)/sizeof(hp48s.mem[0]); i++) {
		hp48s.mem[i].adr=-1;
	}
	hp48_config(machine);
}

void hp48_mem_config(running_machine *machine, int v)
{
	logerror("hp48_mem_config called\n");
	if (hp48s.mem[HDW].adr==-1) {
		logerror("Configuring HDW at %06X\n", v );
		hp48s.mem[HDW].adr=v;
		hp48_config(machine);
	} else if (hp48s.mem[RAM].adr==-1) {
		if (hp48s.state==0) {
			v = 0x100000 - v;
			hp48s.mem[RAM].size=v;
			logerror("Setting RAM size to %06X\n", v );
			hp48s.state++;
		} else {
			logerror("Configuring RAM at %06X\n", v );
			hp48s.mem[RAM].adr=v;
			hp48s.state=0;
			hp48_config(machine);
		}
	} else if (hp48s.mem[CARD1].adr==-1) {
		if (hp48s.state==0) {
			v = 0x100000 - v;
			hp48s.mem[CARD1].size=v;
			hp48s.state++;
		} else {
			logerror("Configuring CARD1 at %06X\n", v );
			hp48s.mem[CARD1].adr=v;
			hp48s.state=0;
			hp48_config(machine);
		}
	} else if (hp48s.mem[CARD2].adr==-1) {
		if (hp48s.state==0) {
			v = 0x100000 - v;
			hp48s.mem[CARD2].size=v;
			hp48s.state++;
		} else {
			logerror("Configuring CARD2 at %06X\n", v );
			hp48s.mem[CARD2].adr=v;
			hp48s.state=0;
			hp48_config(machine);
		}
	}
}

void hp48_mem_unconfig(running_machine *machine, int v)
{
	int i;
	for (i=0; i+1< sizeof(hp48s.mem)/sizeof(hp48s.mem[0]); i++) {
		if (hp48s.mem[i].adr==v) {
			hp48s.mem[i].adr=-1;
			hp48s.state=0;
			hp48_config(machine);
			break;
		}
	}
}

#define HDW_ID_ADR 0x19
#define RAM_ID_SIZE 3
#define RAM_ID_ADR 0xf4
#define CE1_ID_SIZE 5
#define CE1_ID_ADR 0xf6
#define CE2_ID_SIZE 7
#define CE2_ID_ADR 0xf8
#define NCE3_ID_SIZE 1
#define NCE3_ID_ADR 0xf2
int hp48_mem_id(running_machine *machine)
{
	if (hp48s.mem[HDW].adr==-1) {
		return (hp48s.mem[HDW].adr&~0x3f)|HDW_ID_ADR;
    } else if (hp48s.mem[RAM].adr==-1) {
		if (hp48s.state==0) return (hp48s.mem[RAM].size&~0xff)|RAM_ID_SIZE;
		else return (hp48s.mem[RAM].size&~0xff)|RAM_ID_ADR;
    } else if (hp48s.mem[CARD1].adr==-1) {
		if (hp48s.state==0) return (hp48s.mem[CARD1].size&~0xff)|RAM_ID_SIZE;
		else return (hp48s.mem[CARD1].size&~0xff)|RAM_ID_ADR;
    } else if (hp48s.mem[CARD2].adr==-1) {
		if (hp48s.state==0) return (hp48s.mem[CARD2].size&~0xff)|RAM_ID_SIZE;
		else return (hp48s.mem[CARD2].size&~0xff)|RAM_ID_ADR;
	}
	return 0;
}

#define TIMER1_VALUE hp48_hardware.data[0x37]
HP48_HARDWARE hp48_hardware={
	{0}
};

void hp48_crc(running_machine *machine, int adr, int data)
{
	if ((hp48s.mem[HDW].adr==-1)
		||(adr<(hp48s.mem[HDW].adr&~0x3f))
		||(adr>(hp48s.mem[HDW].adr|0x3f)) )
		hp48_hardware.crc=(hp48_hardware.crc >> 4)
			^ (((hp48_hardware.crc ^ data) & 0xf) * 0x1081);
	else
		hp48_hardware.crc=(hp48_hardware.crc >> 4)
			^ ((hp48_hardware.crc& 0xf) * 0x1081);
}

WRITE8_HANDLER( hp48_write )
{
	switch (offset) {
		//lcd
	case 0: case 1: case 2: case 3:
	case 0xb: case 0xc:
		hp48_hardware.data[offset]=data;
		break;
	case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
	case 0x25: case 0x26: case 0x27:
	case 0x28: case 0x29: //wo
	case 0x30: case 0x31: case 0x32: case 0x33: case 0x34:
		hp48_hardware.data[offset]=data;
		break;
		// uart
	case 0xd: case 0x10: case 0x11: case 0x12:
	case 0x13: //w0
	case 0x14: case 0x15: //r0
	case 0x16: case 0x17: //w0
		hp48_hardware.data[offset]=data;
		break;
		// infrared serial
	case 0x1a: case 0x1c: case 0x1d:
		hp48_hardware.data[offset]=data;
		break;
		// timers
	case 0x2e: case 0x2f:
	case 0x37:
	case 0x38: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf)|data;break;
	case 0x39: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf0)|(data<<4);break;
	case 0x3a: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf00)|(data<<8);break;
	case 0x3b: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf000)|(data<<12);break;
	case 0x3c: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf0000)|(data<<16);break;
	case 0x3d: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf00000)|(data<<20);break;
	case 0x3e: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf000000)|(data<<24);break;
	case 0x3f: hp48_hardware.timer2=(hp48_hardware.timer2&~0xf0000000)|(data<<28);break;
		hp48_hardware.data[offset]=data;
		break;
 		// cards
	case 0xe:case 0xf:
		hp48_hardware.data[offset]=data;
		break;
	case 4: // crc low
		hp48_hardware.data[offset]=data;
		hp48_hardware.crc=(hp48_hardware.crc&~0xf)|data;
		break;
	case 5: // crc high
		hp48_hardware.data[offset]=data;
		hp48_hardware.crc=(hp48_hardware.crc&~0xf0)|(data<<4);
		break;
	case 6: // crc high
		hp48_hardware.data[offset]=data;
		hp48_hardware.crc=(hp48_hardware.crc&~0xf00)|(data<<8);
		break;
	case 7:
		hp48_hardware.data[offset]=data;
		hp48_hardware.crc=(hp48_hardware.crc&~0xf000)|(data<<12);
		break;
	case 8: //power state
		hp48_hardware.data[offset]=data;
		break;
	case 9: // power control
		// 0 rst input
		// 1 grst input
		// 2 enable very low batterie interrupt
		// 3 enable low batterie interrupt
		hp48_hardware.data[offset]=data;
		break;
	case 0xa: //ro chip mode
		hp48_hardware.data[offset]=data;
		break;
	case 0x18: case 0x19: //lsb of service request
		hp48_hardware.data[offset]=data;
		break;
	case 0x1b: // base nibble offset
		hp48_hardware.data[offset]=data;
		break;
	case 0x1e: // scratch pad, used by the interrupt handler
		hp48_hardware.data[offset]=data;
		break;
	case 0x1f: // IRAM@ 7 for s/sx, 8 for g/gx
		hp48_hardware.data[offset]=data;
		break;
	default: //temporary for better debugging, write of ro registers
		hp48_hardware.data[offset]=data;
	}
}

 READ8_HANDLER( hp48_read )
{
	int data=0;
	switch (offset) {
		// lcd
	case 0: case 1: case 2: case 3:
	case 9:
		data=1; //reset
		break;
	case 0xb: case 0xc:
		data=hp48_hardware.data[offset];
		break;
	case 0x28: // ro line count / rasterline?
		break;
	case 0x29: // ro line count / rasterline?
		break;
		// cards
	case 0xe:case 0xf:
		data=hp48_hardware.data[offset];
		break;
	case 4: data=hp48_hardware.crc&0xf;break;
	case 5: data=(hp48_hardware.crc>>4)&0xf;break;
	case 6: data=(hp48_hardware.crc>>8)&0xf;break;
	case 7: data=(hp48_hardware.crc>>12)&0xf;break;
	case 0x38: data=hp48_hardware.timer2&0xf;break;
	case 0x39: data=(hp48_hardware.timer2>>4)&0xf;break;
	case 0x3a: data=(hp48_hardware.timer2>>8)&0xf;break;
	case 0x3b: data=(hp48_hardware.timer2>>12)&0xf;break;
	case 0x3c: data=(hp48_hardware.timer2>>16)&0xf;break;
	case 0x3d: data=(hp48_hardware.timer2>>20)&0xf;break;
	case 0x3e: data=(hp48_hardware.timer2>>24)&0xf;break;
	case 0x3f: data=(hp48_hardware.timer2>>28)&0xf;break;
	default: //temporary for better debugging, read of wo registers
		data=hp48_hardware.data[offset];
	}
	return data;
}

static TIMER_CALLBACK(hp48_timer)
{
	static int delay=256;
	if (--delay==0) {
		delay=256;
		TIMER1_VALUE=(TIMER1_VALUE-1)&0xf;
		if (TIMER1_VALUE==0) {
		}
	}
	hp48_hardware.timer2--;
	if (hp48_hardware.timer2==0) {
	}
}

void hp48_out(running_machine *machine, int v)
{
	out=v;
}

int hp48_in(running_machine *machine)
{
	int data=0;
#if 1
	if (out&0x100) {
		if (KEY_B) data|=0x10;
		if (KEY_C) data|=8;
		if (KEY_D) data|=4;
		if (KEY_E) data|=2;
		if (KEY_F) data|=1;
	}
	if (out&0x80) {
		if (KEY_H) data|=0x10;
		if (KEY_I) data|=8;
		if (KEY_J) data|=4;
		if (KEY_K) data|=2;
		if (KEY_L) data|=1;
	}
	if (out&0x40) {
		if (KEY_N) data|=0x10;
		if (KEY_O) data|=8;
		if (KEY_P) data|=4;
		if (KEY_Q) data|=2;
		if (KEY_R) data|=1;
	}
	if (out&0x20) {
		if (KEY_T) data|=0x10;
		if (KEY_U) data|=8;
		if (KEY_V) data|=4;
		if (KEY_W) data|=2;
		if (KEY_X) data|=1;
	}
	if (out&0x10) {
		if (KEY_ON) data|=0x20;
		if (KEY_ENTER) data|=0x10;
		if (KEY_Y) data|=8;
		if (KEY_Z) data|=4;
		if (KEY_DEL) data|=2;
		if (KEY_LEFT) data|=1;
	}
	if (out&8) {
		if (KEY_ALPHA) data|=0x20;
		if (KEY_S) data|=0x10;
		if (KEY_7) data|=8;
		if (KEY_8) data|=4;
		if (KEY_9) data|=2;
		if (KEY_DIVIDE) data|=1;
	}
	if (out&4) {
		if (KEY_ORANGE) data|=0x20;
		if (KEY_G) data|=0x10;
		if (KEY_4) data|=8;
		if (KEY_5) data|=4;
		if (KEY_6) data|=2;
		if (KEY_MULTIPLY) data|=1;
	}
	if (out&2) {
		if (KEY_BLUE) data|=0x20;
		if (KEY_A) data|=0x10;
		if (KEY_1) data|=8;
		if (KEY_2) data|=4;
		if (KEY_3) data|=2;
		if (KEY_MINUS) data|=1;
	}
	if (out&1) {
		if (KEY_M) data|=0x10;
		if (KEY_0) data|=8;
		if (KEY_POINT) data|=4;
		if (KEY_SPC) data|=2;
		if (KEY_PLUS) data|=1;
	}
#else
	if (out&0x100) data|=input_port_read_indexed(machine, 0);
	if (out&0x080) data|=input_port_read_indexed(machine, 1);
	if (out&0x040) data|=input_port_read_indexed(machine, 2);
	if (out&0x020) data|=input_port_read_indexed(machine, 3);
	if (out&0x010) data|=input_port_read_indexed(machine, 4);
	if (out&0x008) data|=input_port_read_indexed(machine, 5);
	if (out&0x004) data|=input_port_read_indexed(machine, 6);
	if (out&0x002) data|=input_port_read_indexed(machine, 7);
	if (out&0x001) data|=input_port_read_indexed(machine, 8);
#endif
	return data;
}

DRIVER_INIT( hp48s )
{
	int i,j,t;
	UINT8 *mem=memory_region(REGION_CPU1);
	for (i=0x3ffff,j=0x7fffe; i>=0;i--,j-=2) {
		t=mem[i];
		mem[j+1]=t>>4;
		mem[j]=t&0xf;
	}
	memset(mem+0x80000, 0, 0x80000); //unused area must be 0!
	memset(mem+0x140000, 0, 0x40000); //unused area must be 0!
	memset(mem+0x180000, 0, 0x40000); //unused area must be 0!

	hp48_ram=memory_region(REGION_CPU1)+0x100000;
	hp48_card1=memory_region(REGION_CPU1)+0x140000;
	hp48_card2=memory_region(REGION_CPU1)+0x180000;

	timer_pulse(ATTOTIME_IN_HZ(8192), NULL, 0, hp48_timer);
}

DRIVER_INIT( hp48g )
{
	int i,j,t;
	UINT8 *mem=memory_region(REGION_CPU1);
	UINT8 *gfx=memory_region(REGION_GFX1);

	for (i=0x7ffff,j=0xffffe; i>=0;i--,j-=2) {
		t=mem[i];
		mem[j]=t>>4;
		mem[j+1]=t&0xf;
	}
	for (i=0; i<256; i++) gfx[i]=i;

	hp48_ram=memory_region(REGION_CPU1)+0x100000;
	hp48_card1=memory_region(REGION_CPU1)+0x140000;
	hp48_card2=memory_region(REGION_CPU1)+0x180000;

	timer_pulse(ATTOTIME_IN_HZ(8192), NULL, 0, hp48_timer);
}

MACHINE_RESET( hp48 )
{
	hp48_mem_reset(machine);
}
