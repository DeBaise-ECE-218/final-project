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

InterruptIn pir(PG_0);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool pirState;
static bool motionSensorActivated;

//=====[Declarations (prototypes) of private functions]========================

static void motionDetected();
static void motionCeased();

//=====[Implementations of public functions]===================================

void sensorInit(){ 
    pir.rise(&motionDetected);
    pirState = 0;
    motionSensorActivated = false;
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

bool motionSensorRead()
{
    return pirState;
}

// ===================================================== motion sensor specifics

void motionSensorActivate()
{
    motionSensorActivated = true;
    if ( !pirState ) {
        pir.rise(&motionDetected);
    }   
}

void motionSensorDeactivate()
{
    motionSensorActivated = false;
    if ( !pirState ) {
        pir.rise(NULL);
    }
}


//=====[Implementations of private functions]==================================

static void motionDetected()
{
    pirState = ON;
    pir.rise(NULL);
    pir.fall(&motionCeased);
}

static void motionCeased()
{
    pirState = OFF;
    pir.fall(NULL);
    if ( motionSensorActivated ) {
        pir.rise(&motionDetected);
    }
}