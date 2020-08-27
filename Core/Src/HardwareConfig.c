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
	//button
	gpioSetMode(gpioA, PIN_0, GPIO_IN);
	gpioSetPinSpeed(gpioA,PIN_0,HIGH_SPEED);

	//config SPI1
	gpioSetMode(gpioA, PIN_15, GPIO_ALT);
	gpioSetPinSpeed(gpioA,PIN_15,HIGH_SPEED);

	gpioSetMode(gpioB, PIN_3, GPIO_ALT);
	gpioSetMode(gpioB, PIN_4, GPIO_ALT);
	gpioSetMode(gpioB, PIN_5, GPIO_ALT);
	gpioSetPinSpeed(gpioB,PIN_3,HIGH_SPEED);
	gpioSetPinSpeed(gpioB,PIN_4,HIGH_SPEED);
	gpioSetPinSpeed(gpioB,PIN_5,HIGH_SPEED);
}

void initSPI1(){
	enableSpi1();
	gpioSetAlternateFunction(gpioA ,PIN_15 ,AF5); //set PA15 as SPI NSS
	gpioSetAlternateFunction(gpioB ,PIN_3 ,AF5); //set PB3 as SPI SCLK
	gpioSetAlternateFunction(gpioB ,PIN_4 ,AF5); //set PB4 as SPI MISO
	gpioSetAlternateFunction(gpioB ,PIN_5 ,AF5); //set PB5 as SPI MOSI
	spiSetControlRegister(spi1,DEFAULT_SETTING|SPI_NSS_1);
	//enable interrupt
	nvicEnableInterrupt(35);

}
