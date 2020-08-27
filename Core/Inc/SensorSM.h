/*
 * SensorSM.h
 *
 *  Created on: Aug 27, 2020
 *      Author: owen
 */

#ifndef INC_SENSORSM_H_
#define INC_SENSORSM_H_

typedef enum{
    INIT_STATE,
    WAIT_HARDWARE_DATA,
    SEND_CONFIG,
    WAIT_FOR_REQUEST,
    WAIT_FOR_PRESSURE_DATA,
	WAIT_FOR_TEMPERATURE_DATA,
} SensorState;

#endif /* INC_SENSORSM_H_ */
