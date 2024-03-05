//=====[#include guards - begin]===============================================

#ifndef _SENSORS_H_
#define _SENSORS_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================
void sensorInit();
void sensorUpdate();

float ldrRead();
float BpotRead();
float GpotRead();
float RpotRead();
bool motionSensorRead();

void motionSensorActivate();
void motionSensorDeactivate();


//=====[#include guards - end]=================================================

#endif // _SENSORS_H_