/*
 * InitUsart.c
 *
 *  Created on: Aug 18, 2020
 *      Author: academic
 */
#include "HardwareConfig.h"
#include "Gpio.h"
#include "Clock.h"
#include "Nvic.h"
#include "Syscfg.h"
#include "Exti.h"
#include "Rcc.h"
#include "Common.h"
#include "BaseAddress.h"
#include "Spi.h"

void configureGpio(){
	enableGpio(PORT_B);
	gpioSetMode(gpioB, PIN_13, GPIO_OUT);
	gpioSetPinSpeed(gpioB,PIN_13,HIGH_SPEED);

	enableGpioA();

	//config SPI1
	gpioSetMode(gpioA, PIN_4, GPIO_ALT);
	gpioSetOutputType(gpioA, PIN_4, PUSH_PULL);
	gpioSetPinSpeed(gpioA,PIN_4,HIGH_SPEED);
	gpioSetPullUpDownReg(gpioA , PIN_4 , PULL_UP);

	gpioSetMode(gpioA, PIN_5, GPIO_ALT);
	gpioSetMode(gpioA, PIN_6, GPIO_ALT);
	gpioSetMode(gpioA, PIN_7, GPIO_ALT);
	gpioSetPinSpeed(gpioA,PIN_7,HIGH_SPEED);
	gpioSetPinSpeed(gpioA,PIN_5,HIGH_SPEED);
	gpioSetPinSpeed(gpioA,PIN_6,HIGH_SPEED);
}

void initSPI1(){
	enableSpi1();
	gpioSetAlternateFunction(gpioA ,PIN_4 ,AF5); //set PA4 as SPI NSS ----->CSB
	gpioSetAlternateFunction(gpioA ,PIN_5 ,AF5); //set PA5 as SPI SCLK ---->CLK
	gpioSetAlternateFunction(gpioA ,PIN_6 ,AF5); //set PA6 as SPI MISO --->SDO
	gpioSetAlternateFunction(gpioA ,PIN_7 ,AF5); //set PA7 as SPI MOSI ---->SDA
	spiSetControlRegister(spi1,DEFAULT_SETTING|SPI_NSS_1);
	//enable interrupt
	nvicEnableInterrupt(35);

}
