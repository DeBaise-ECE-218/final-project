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

void print( const char* str );

InterruptIn pir(PG_0);

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

void print( const char* str )
{
    uartUsb.write( str, strlen(str) );
}


//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============
static bool pirState;
static bool motionSensorActivated;

motionState_t motionState = NOT_OCCUPIED;

int accumulatedTime = 0;
int accumulatedTimes = 0;

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
    if(accumulatedTimes > 500) {
        accumulatedTimes = 0;
        if(motionState == OCCUPIED) {
            print("Curr state: occupied");
        } else if(motionState == WAIT) {
            print("Curr state: wait");
        } else {
            print("Curr state: not occupied");
        }


        if(motionSensorRead()) {
            print("Motion detected");
        } else {
            print("Motion not detected");
        }
        print("\n");

    } else {
        accumulatedTimes += 10;
    }

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