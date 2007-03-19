#include "driver.h"
#include "includes/cclimber.h"

static void cclimber_decode(const unsigned char convtable[8][16])
{
	UINT8 *rom = memory_region(REGION_CPU1);
	UINT8 *decrypt = auto_malloc(0x10000);
	int A;

	memory_set_decrypted_region(0, 0x0000, 0xffff, decrypt);

	for (A = 0x0000;A < 0x10000;A++)
	{
		int i,j;
		unsigned char src;


		src = rom[A];

		/* pick the translation table from bit 0 of the address */
		/* and from bits 1 7 of the source data */
		i = (A & 1) | (src & 0x02) | ((src & 0x80) >> 5);

		/* pick the offset in the table from bits 0 2 4 6 of the source data */
		j = (src & 0x01) | ((src & 0x04) >> 1) | ((src & 0x10) >> 2) | ((src & 0x40) >> 3);

		/* decode the opcodes */
		decrypt[A] = (src & 0xaa) | convtable[i][j];
	}
}

DRIVER_INIT( cclimber )
{
	static const unsigned char convtable[8][16] =
	{
		/* -1 marks spots which are unused and therefore unknown */
		{ 0x44,0x14,0x54,0x10,0x11,0x41,0x05,0x50,0x51,0x00,0x40,0x55,0x45,0x04,0x01,0x15 },
		{ 0x44,0x10,0x15,0x55,0x00,0x41,0x40,0x51,0x14,0x45,0x11,0x50,0x01,0x54,0x04,0x05 },
		{ 0x45,0x10,0x11,0x44,0x05,0x50,0x51,0x04,0x41,0x14,0x15,0x40,0x01,0x54,0x55,0x00 },
		{ 0x04,0x51,0x45,0x00,0x44,0x10,  -1,0x55,0x11,0x54,0x50,0x40,0x05,  -1,0x14,0x01 },
		{ 0x54,0x51,0x15,0x45,0x44,0x01,0x11,0x41,0x04,0x55,0x50,  -1,0x00,0x10,0x40,  -1 },
		{   -1,0x54,0x14,0x50,0x51,0x01,  -1,0x40,0x41,0x10,0x00,0x55,0x05,0x44,0x11,0x45 },
		{ 0x51,0x04,0x10,  -1,0x50,0x40,0x00,  -1,0x41,0x01,0x05,0x15,0x11,0x14,0x44,0x54 },
		{   -1,  -1,0x54,0x01,0x15,0x40,0x45,0x41,0x51,0x04,0x50,0x05,0x11,0x44,0x10,0x14 }
	};

	cclimber_decode(convtable);
}

DRIVER_INIT( cclimbrj )
{
	static const unsigned char convtable[8][16] =
	{
		{ 0x41,0x54,0x51,0x14,0x05,0x10,0x01,0x55,0x44,0x11,0x00,0x50,0x15,0x40,0x04,0x45 },
		{ 0x50,0x11,0x40,0x55,0x51,0x14,0x45,0x04,0x54,0x15,0x10,0x05,0x44,0x01,0x00,0x41 },
		{ 0x44,0x11,0x00,0x50,0x41,0x54,0x04,0x14,0x15,0x40,0x51,0x55,0x05,0x10,0x01,0x45 },
		{ 0x10,0x50,0x54,0x55,0x01,0x44,0x40,0x04,0x14,0x11,0x00,0x41,0x45,0x15,0x51,0x05 },
		{ 0x14,0x41,0x01,0x44,0x04,0x50,0x51,0x45,0x11,0x40,0x54,0x15,0x10,0x00,0x55,0x05 },
		{ 0x01,0x05,0x41,0x45,0x54,0x50,0x55,0x10,0x11,0x15,0x51,0x14,0x44,0x40,0x04,0x00 },
		{ 0x05,0x55,0x00,0x50,0x11,0x40,0x54,0x14,0x45,0x51,0x10,0x04,0x44,0x01,0x41,0x15 },
		{ 0x55,0x50,0x15,0x10,0x01,0x04,0x41,0x44,0x45,0x40,0x05,0x00,0x11,0x14,0x51,0x54 },
	};

	cclimber_decode(convtable);
}

DRIVER_INIT( mshuttle )
{
	static const UINT8 convtable[8][16] =
	{
		/* -1 marks spots which are unused and therefore unknown */
		{ 0x40,0x41,0x44,0x15,0x05,0x51,0x54,0x55,0x50,0x00,0x01,0x04,  -1,0x10,0x11,0x14 },
		{ 0x45,0x51,0x55,0x44,0x40,0x11,0x05,0x41,0x10,0x14,0x54,0x50,0x15,0x04,0x00,0x01 },
		{ 0x11,0x14,0x10,0x00,0x44,0x05,  -1,0x04,0x45,0x15,0x55,0x50,  -1,0x01,0x54,0x51 },
		{ 0x14,0x01,0x11,0x10,0x50,0x15,0x00,0x40,0x04,0x51,0x45,0x05,0x55,0x54,  -1,0x44 },
		{ 0x04,0x10,  -1,0x40,0x15,0x41,0x50,0x50,0x11,  -1,0x14,0x00,0x51,0x45,0x55,0x01 },
		{ 0x44,0x45,0x00,0x51,  -1,  -1,0x15,0x11,0x01,0x10,0x04,0x55,0x05,0x40,0x50,0x41 },
		{ 0x51,0x00,0x01,0x05,0x04,0x55,0x54,0x50,0x41,  -1,0x11,0x15,0x14,0x10,0x44,0x40 },
		{ 0x05,0x04,0x51,0x01,  -1,  -1,0x55,  -1,0x00,0x50,0x15,0x14,0x44,0x41,0x40,0x54 },
	};

	cclimber_decode(convtable);
}

DRIVER_INIT( cannonb )
{
	int A;
	unsigned char *rom = memory_region(REGION_CPU1);


	for (A = 0x0000;A < 0x1000;A++) /* only first ROM is encrypted */
	{
		unsigned char src;
		int i;
		static const unsigned char xor_tab[4] ={0x92, 0x82, 0x12, 0x10};

		src = rom[A+0x10000];

		i = ((A&0x200)>>8) | ((A&0x80)>>7);

		src ^= xor_tab[i];

		rom[A] = src;
	}
}

DRIVER_INIT( ckongb )
{
	int A;
	unsigned char *rom = memory_region(REGION_CPU1);


	for (A = 0x0000;A < 0x6000;A++) /* all the program ROMs are encrypted */
	{
		rom[A] = rom[A] ^ 0xf0;
	}
}
