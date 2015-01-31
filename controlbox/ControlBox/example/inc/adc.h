/*
 * adc.h
 *
 *  Created on: 5 Jan 2015
 *      Author: david_000
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

void Init_ADC(void);
int ADCConvert(void);
uint16_t GetADC(uint8_t ch);

#endif /* INC_ADC_H_ */
