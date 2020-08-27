/*
 * SpiDriver.h
 *
 *  Created on: Aug 27, 2020
 *      Author: owen
 */

#ifndef INC_SPIDRIVER_H_
#define INC_SPIDRIVER_H_
#include "Spi.h"
#include "SpiMacro.h"


typedef struct SpiInfo SpiInfo;
struct SpiInfo {
	SpiRegs * spi;
	char * spiTxBuffer;
	char * spiRxBuffer;
	int requestTxPacket;
	int requestRxPacket;
	int  txTurn;
	int txLength;
	int rxLength;
	int txCount;
	int rxCount;
};

typedef enum{
	MASTER,
} SpiPort;


#endif /* INC_SPIDRIVER_H_ */
