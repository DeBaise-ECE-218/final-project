//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"
#include "sensors.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn ldr(A0);

AnalogIn Bpot(A1);
AnalogIn Gpot(A2);
AnalogIn Rpot(A3);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================

void sensorInit(){ 
    
}

void sensorUpdate(){ 

}

float ldrRead()
{
    return ldr.read();
}

float BpotRead()
{
    return Bpot.read();
}

float GpotRead()
{
    return Gpot.read();
}

float RpotRead()
{
    return Rpot.read();
}


//=====[Implementations of private functions]==================================
