/*
 * @brief LPC11xx ADC example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2012
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include <stdio.h>

#if !defined(CHIP_LPC1125)

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

static ADC_CLOCK_SETUP_T ADCSetup;

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/
#define JOYSTICK_GPIO_PORT0_NUM	0

void Init_ADC(void)
{
	//P0_11
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 11, (IOCON_FUNC2 | IOCON_ADMODE_EN | IOCON_HYS_EN));
	//P0_12
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 12, (IOCON_FUNC2 | IOCON_ADMODE_EN | IOCON_HYS_EN));
	//P0_13
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 13, (IOCON_FUNC2 | IOCON_ADMODE_EN | IOCON_HYS_EN));
	//P0_14
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 14, (IOCON_FUNC2 | IOCON_ADMODE_EN | IOCON_HYS_EN));
#if 0 //set 0 to debug jtag
	//P0_15
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 15, (IOCON_FUNC2 | IOCON_ADMODE_EN | IOCON_HYS_EN));//SW
#endif
	//P0_16
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 16, (IOCON_FUNC1 | IOCON_ADMODE_EN | IOCON_HYS_EN));
	//P0_22
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 22, (IOCON_FUNC1 | IOCON_ADMODE_EN | IOCON_HYS_EN));
	//P0_23
	Chip_IOCON_PinMuxSet(LPC_IOCON, JOYSTICK_GPIO_PORT0_NUM, 23, (IOCON_FUNC1 | IOCON_ADMODE_EN | IOCON_HYS_EN));

	/* ADC Init */
	Chip_ADC_Init(LPC_ADC, &ADCSetup);
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for ADC example
 * @return	Function should not exit
 */
static uint16_t ADCout[8];
uint16_t GetADC(uint8_t ch)
{
	if(ch < sizeof(ADCout)/sizeof(ADCout[0]))
	{
		return ADCout[ch];
	}
	else
	{
		return 0xffff;
	}
}

int ADCConvert(void)
{
	enum {START, WAIT};
	static uint8_t s_STATE = START;
	static ADC_CHANNEL_T ch = ADC_CH0;
	switch(s_STATE)
	{
		case START:
		{
			/* Start A/D conversion */
			ch = ADC_CH0;
			Chip_ADC_EnableChannel(LPC_ADC, ch, ENABLE);
			Chip_ADC_SetStartMode(LPC_ADC, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
			s_STATE = WAIT;
			break;
		}
		case WAIT:
		{
			/* Waiting for A/D conversion complete */
			if(Chip_ADC_ReadStatus(LPC_ADC, ch, ADC_DR_DONE_STAT) != SET)
			{
				break;
			}
			/* Read ADC value */
			Chip_ADC_ReadValue(LPC_ADC, ch, &ADCout[ch]);


			/* Print ADC value */
			DEBUGOUT("ADC value ch:%d = 0x%x\r\n", ch, ADCout[ch]);

			Chip_ADC_EnableChannel(LPC_ADC, ch, DISABLE); //unselect channel

			if(++ch > ADC_CH7)	//move to next channel
			{
				ch = ADC_CH0;
			}

			/* start next channel conversion (one channel at a time) */
			Chip_ADC_EnableChannel(LPC_ADC, ch, ENABLE);
			Chip_ADC_SetStartMode(LPC_ADC, ADC_START_NOW, ADC_TRIGGERMODE_RISING);

			break;
		}
		default:
		{
			break;
		}
	}
#if 0 //test usb packet
	static uint32_t cnt = 0;
	static uint16_t d = 0;
	if(cnt++ > 10)
	{
		d++;
	}
	ADCout[4] = d;
	ADCout[5] = ~d;
#endif
	return 0;
}

#endif /* !defined(CHIP_LPC1125) */
