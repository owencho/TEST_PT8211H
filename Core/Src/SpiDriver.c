/*
 * SpiDriver.c
 *
 *  Created on: Aug 27, 2020
 *      Author: owen
 */
#include "SpiDriver.h"
#include "HardwareConfig.h"
#include "Irq.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include <stdarg.h>

#define hasRequestedTxPacket(info) ((info)->requestTxPacket)
#define hasRequestedRxPacket(info) ((info)->requestRxPacket)

SpiInfo spiInfo[] = {
  [MASTER]={NULL},
};

void spiInfoConfig(){
    disableIRQ();
	memset(&spiInfo[MASTER],0,sizeof(SpiInfo));
	SpiInfo * info =&spiInfo[MASTER];
	info->spi = spi1;
	info->spiRxBuffer = malloc(sizeof(char)*64);
	info->txCount = 0;
	info->rxCount = 0;
	info->requestTxPacket = 0;
	info->requestRxPacket = 0;
    enableIRQ();
}

void SpiSendData(SpiPort port,char * message,int length){
	disableIRQ();
	SpiInfo * info =&spiInfo[port];

    if(!hasRequestedTxPacket(info)){
        info->requestTxPacket = 1;
    	info->spiTxBuffer = message;
    	info->txLength = length;
    	info->txTurn = 1;
    	//spiSetControlRegister(spi1,spiControlMacro|SPI_TX_EMPTY_INT_ENABLE|SPI_NSS_0);
    }
	enableIRQ();
}

void SpiReceiveData(SpiPort port,int size){
	disableIRQ();
	SpiInfo * info =&spiInfo[port];
	if(!hasRequestedRxPacket(info)){
		info->requestRxPacket = 1;
		info->rxLength = size;
		info->txTurn = 0;
		//spiSetControlRegister(spi1,spiControlMacro|SPI_RX_EMPTY_INT_ENABLE|SPI_NSS_0);
	}
	enableIRQ();
}

void SpiSetReceiveLength(SpiPort port,int size){
	disableIRQ();
	SpiInfo * info =&spiInfo[port];
	if(!hasRequestedRxPacket(info)){
		info->rxLength = size;
	}
	enableIRQ();
}

