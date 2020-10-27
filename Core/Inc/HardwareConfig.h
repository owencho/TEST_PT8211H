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

#define DEFAULT_SETTING (SPI_2_LINE_UNIDIRECTION |SPI_16BIT_DATA_FRAME| SPI_SOFTWARE_SLAVE_M_ENABLED | \
						 SPI_MSB_FIRST|SPI_ENABLE | SPI_MASTER_CONFIG |SPI_CLK_IDLE1 | \
						 SPI_DATA_CAPTURE_SECOND_CLK_TRANS|SPI_SS_OUT_ENABLED)

#endif /* INC_HARDWARECONFIG_H_ */
