/*
 * canMsgType.h
 *
 *  Created on: 24.06.2018
 *      Author: M.Rogge 
 *
 * Can Msg Datatype for STM32F4xx. 
 */

#ifndef CANMSG_H_
#define CANMSG_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_def.h"
/** Private Variables **/


typedef struct{
	uint32_t lowerWord;
	uint32_t upperWord;
}canWord;

typedef struct{
	uint8_t BYTE1;
	uint8_t BYTE2;
	uint8_t BYTE3;
	uint8_t BYTE4;
	uint8_t BYTE5;
	uint8_t BYTE6;
	uint8_t BYTE7;
	uint8_t BYTE8;
}canByte;

typedef union
{
    canByte canBytes;
	canWord canWords;
	uint8_t canData[8];
}canStdData;

#endif /* CANMSG_H_ */
