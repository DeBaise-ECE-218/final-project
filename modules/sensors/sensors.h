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
<<<<<<< HEAD
bool motionSensorRead();
float convertToPercent(float sensorVal);

void motionSensorActivate();
void motionSensorDeactivate();
=======
>>>>>>> 6023b00e1f85061f4ac1919367a9c79d84104303


//=====[#include guards - end]=================================================

#endif // _SENSORS_H_