/*
 * HardwareConfig.h
 *
 *  Created on: Aug 27, 2020
 *      Author: owen
 */

#ifndef INC_HARDWARECONFIG_H_
#define INC_HARDWARECONFIG_H_
#include "SpiMacro.h"
void configureGpio();
void initSPI1();

#define DEFAULT_SETTING (SPI_2_LINE_UNIDIRECTION |SPI_8BIT_DATA_FRAME| SPI_SOFTWARE_SLAVE_M_ENABLED | \
						 SPI_MSB_FIRST|SPI_ENABLE | SPI_MASTER_CONFIG |SPI_CLK_IDLE0 | \
						 SPI_DATA_CAPTURE_FIRST_CLK_TRANS)

#endif /* INC_HARDWARECONFIG_H_ */
