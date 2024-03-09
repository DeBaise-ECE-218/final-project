//=====[Libraries]=============================================================

#include "arduino.h"
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut dataTransfer(D10);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void sendData(bool state) {
    dataTransfer = state;
}

//=====[Implementations of private functions]==================================