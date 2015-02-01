#include "board.h"

#define JOYSTICK_GPIO_PORT0_NUM	0
#define JOYSTICK_GPIO_PORT1_NUM	1

typedef struct{
		uint8_t port;
		uint8_t pin;
	} TPin;

//ISP P0_1 needs 10k pullup to Vcc, cannot be used.
//P0_4, P0_5 are open drain, need pullups so were not used
TPin out[] = {
		{JOYSTICK_GPIO_PORT0_NUM, 21},
		{JOYSTICK_GPIO_PORT0_NUM, 17},
		{JOYSTICK_GPIO_PORT0_NUM, 20},
		{JOYSTICK_GPIO_PORT0_NUM, 3},
		{JOYSTICK_GPIO_PORT1_NUM, 10}
	};

TPin ins[] = {
		{JOYSTICK_GPIO_PORT1_NUM, 22},
		{JOYSTICK_GPIO_PORT1_NUM, 23},
		{JOYSTICK_GPIO_PORT1_NUM, 24},
		{JOYSTICK_GPIO_PORT1_NUM, 25},
		{JOYSTICK_GPIO_PORT1_NUM, 26},
		{JOYSTICK_GPIO_PORT1_NUM, 27},
		{JOYSTICK_GPIO_PORT1_NUM, 28},
		{JOYSTICK_GPIO_PORT1_NUM, 31}
	};

void KeyboardInit(void)
{
	//inputs
	for(uint8_t i = 0; i < sizeof(ins)/sizeof(ins[0]); i++)
	{
		Chip_IOCON_PinMuxSet(LPC_IOCON, ins[i].port, ins[i].pin, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
		Chip_GPIO_SetPinDIRInput(LPC_GPIO, ins[i].port, ins[i].pin);
	}

	//outputs
	for(uint8_t o = 0; o < sizeof(out)/sizeof(out[0]); o++)
	{
		Chip_IOCON_PinMuxSet(LPC_IOCON, out[o].port, out[o].pin, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
		Chip_GPIO_SetPinDIROutput(LPC_GPIO, out[o].port, out[o].pin);
	}
}

uint64_t KeyboardScan(void)
{
	uint8_t key = 0;
	uint64_t scan = 0;
	for(uint8_t j = 0; j < sizeof(out); j++)
	{
		for(uint8_t o = 0; o < sizeof(out)/sizeof(out[0]); o++)
		{
			Chip_GPIO_SetPinState(LPC_GPIO, out[o].port, out[o].pin, o == j ? 1 : 0);
		}
		for(uint8_t i = 0; i < sizeof(ins)/sizeof(ins[0]); i++)
		{
			if(Chip_GPIO_ReadPortBit(LPC_GPIO, ins[i].port, ins[i].pin) == 1)
			{
				scan |= (uint64_t)1 << key;
			}
			key++;
		}

	}

#if 0 //test usb packet
	static uint64_t d = 1;
	static uint32_t cnt = 0;
	if(cnt++ > 10)
	{
		d <<= 1;
		if(d > 0x10000000000)
		{
			d = 1;
		}
		cnt = 0;
	}
	scan = d;
#endif
	return scan;
}
