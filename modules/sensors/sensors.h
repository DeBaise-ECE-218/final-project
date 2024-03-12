//=====[#include guards - begin]===============================================

#ifndef _SENSORS_H_
#define _SENSORS_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================
float ldrRead();
float BpotRead();
float GpotRead();
float RpotRead();

float convertToPercent(float sensorVal);




//=====[#include guards - end]=================================================

#endif // _SENSORS_H_
