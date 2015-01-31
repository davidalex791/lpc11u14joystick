#include "board.h"

#define JOYSTICK_GPIO_PORT0_NUM	0
#define JOYSTICK_GPIO_PORT1_NUM	1

void KeyboardInit(void)
{
	//inputs
	//P1_22
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 22, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 22 );
	//P1_23
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 23, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 23 );
	//P1_24
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 24, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 24 );
	//P1_25
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 25, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 25 );
	//P1_26
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 26, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 26 );
	//P1_27
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 27, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 27 );
	//P1_28
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 28, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 28 );
	//P1_31
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 31, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 31 );


	//outputs
	//P0_21
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 21, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, JOYSTICK_GPIO_PORT0_NUM, 21);

	//P0_4
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 4, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, JOYSTICK_GPIO_PORT0_NUM, 4);
	//P0_5
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 5, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, JOYSTICK_GPIO_PORT0_NUM, 5);
	//P0_3
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 3, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, JOYSTICK_GPIO_PORT0_NUM, 3);
	//P1_10
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT1_NUM, 10, (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_HYS_EN));
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, 10);

}

uint64_t KeyboardScan(void)
{
	struct{
		uint8_t port;
		uint8_t pin;
	} out[] = {	{JOYSTICK_GPIO_PORT0_NUM, 21},
				{JOYSTICK_GPIO_PORT0_NUM, 4},
				{JOYSTICK_GPIO_PORT0_NUM, 5},
				{JOYSTICK_GPIO_PORT0_NUM, 3},
				{JOYSTICK_GPIO_PORT1_NUM, 10}
	};
	uint8_t ins[] = {22, 23, 24, 25, 26, 27, 28, 31};
	uint8_t key = 0;
	uint64_t scan = 0;
	for(uint8_t j = 0; j < sizeof(out); j++)
	{
		for(uint8_t o = 0; o < sizeof(out); o++)
		{
			Chip_GPIO_SetPinState(LPC_GPIO, out[o].port, out[o].pin, o == j ? 1 : 0);
		}
		for(uint8_t i = 0; i < sizeof(ins); i++)
		{
			if(Chip_GPIO_ReadPortBit(LPC_GPIO, JOYSTICK_GPIO_PORT1_NUM, ins[i]) == 1)
			{
				scan |= (uint64_t)1 << key;
			}
			key++;
		}

	}
	return scan;
}