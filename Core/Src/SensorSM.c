/*
 * SensorSM.c
 *
 *  Created on: Aug 27, 2020
 *      Author: owen
 */

#include"SensorSM.h"
/*
void handleSensorSM(){
	switch(buttonState){
		case BUTTON_WAIT:
			usartSendMessage(MASTER,adcRead,4);
			buttonState = READ_ADC;
		break;

		case READ_ADC:
			usartReceiveMessage(MASTER,7);
			buttonState = WAIT_ADC_VALUE;
		break;

		case WAIT_ADC_VALUE:
			strcpy(adcPacket, (info->usartRxBuffer)+DATA_PACKET);
			ledControl[CMD_PACKET]++;
			if(ledControl[CMD_PACKET]> 0x12){
				ledControl[CMD_PACKET] = 0x10;
			}
			usartSendMessage(MASTER,ledControl,4);
			buttonState = SEND_CONTROL_LED;
		break;

		case SEND_CONTROL_LED:
			memcpy(serialPacket, serialSlave, 4);
			memcpy(&serialPacket[4], adcPacket, 4);
			usartSendMessage(MASTER,serialPacket,8);
			buttonState = SEND_STRING;
		break;

		case SEND_STRING:
			extiSetInterruptMaskRegister(exti,PIN_0,NOT_MASKED);
			buttonState = BUTTON_WAIT;
		break;
	}
}
*/
