//=====[#include guards - begin]===============================================

#ifndef _MOTION_H_
#define _MOTION_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void motionInit();
void motionUpdate();
bool motionSensorRead();

void motionSensorActivate();
void motionSensorDeactivate();

//=====[#include guards - end]=================================================

#endif // _MOTION_H_