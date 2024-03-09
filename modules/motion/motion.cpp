//=====[Libraries]=============================================================
#include "arm_book_lib.h"
#include "mbed.h"
#include "motion.h"
#include "interface.h"
#include "arduino.h"

//=====[Declaration of private defines]========================================

#define TIME_WAIT 5000

//=====[Declaration of private data types]=====================================

typedef enum {
    OCCUPIED,
    WAIT,
    NOT_OCCUPIED
} motionState_t;

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external private global objects]=======================

InterruptIn pir(PG_0);


//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============
static bool pirState;
static bool motionSensorActivated;

motionState_t motionState = NOT_OCCUPIED;

int accumulatedTime = 0;

//=====[Declarations (prototypes) of private functions]========================

static void motionDetected();
static void motionCeased();

//=====[Implementations of public functions]===================================

void motionInit() {
    pir.rise(&motionDetected);
    pirState = 0;
    motionSensorActivated = false;
}

void motionUpdate() {
    switch(motionState) {
        case OCCUPIED:
            if(!motionSensorRead()) {
                motionState = WAIT;
            }
            // send 1
            sendData(ON);
            break;
        case NOT_OCCUPIED:
            if(motionSensorRead()) {
                motionState = OCCUPIED;
            }
            // send 0
            sendData(OFF);
            break;
        case WAIT:
        default:
            if(accumulatedTime > TIME_WAIT) {
                accumulatedTime = 0;
                motionState = NOT_OCCUPIED;
            } else {
                if(motionSensorRead()) {
                    accumulatedTime = 0;
                    motionState = OCCUPIED;
                }

                accumulatedTime += SYSTEM_DELAY_TIME;
            }
            break;
    }
}

bool motionSensorRead()
{
    return pirState;
}


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