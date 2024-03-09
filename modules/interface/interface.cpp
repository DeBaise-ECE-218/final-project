//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "interface.h"
#include "display.h"
#include "sensors.h"

//=====[Declaration of private defines]========================================
#define DISPLAY_REFRESH_TIME_MS 1000

//=====[Declaration of private data types]=====================================



//=====[Declaration and initialization of public global objects]===============


//=====[Declaration of external public global variables]=======================


//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============


// Declaration of modeSelector



//=====[Declarations (prototypes) of private functions]========================


static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static void userInterfaceDisplayReportStateUpdate();


//=====[Implementations of public functions]===================================


void userInterfaceInit()
{
   userInterfaceDisplayInit();
}


void userInterfaceUpdate()
{
   userInterfaceDisplayUpdate();


}


//=====[Implementations of private functions]==================================


static void userInterfaceDisplayReportStateUpdate()
{
   char ldrString[3] = "";
   char rString[3] = "";
   char gString[3] = "";
   char bString[3] = "";
  
   // ldr reading display
   sprintf(ldrString, "%.0f", convertToPercent(ldrRead()));
   displayCharPositionWrite ( 7,0 );
   displayStringWrite( ldrString );

   // rgb reading display
   sprintf(rString, "%.0f", convertToPercent(RpotRead()));
   displayCharPositionWrite ( 2,1 );
   displayStringWrite( rString );
   
   sprintf(gString, "%.0f", convertToPercent(GpotRead()));
   displayCharPositionWrite ( 7,1 );
   displayStringWrite( gString );

   sprintf(bString, "%.0f", convertToPercent(BpotRead()));
   displayCharPositionWrite ( 12,1 );
   displayStringWrite( bString );
}


static void userInterfaceDisplayInit() {
   displayInit();

   // Display light lvl
   displayCharPositionWrite ( 0,0 );
   displayStringWrite( "NL Lvl:");

   
   // Display RGB lvls
   displayCharPositionWrite ( 0,1 );
   displayStringWrite( "R:" );

   displayCharPositionWrite ( 5,1 );
   displayStringWrite( "G:" );

   displayCharPositionWrite ( 10,1 );
   displayStringWrite( "B:" );
}


static void userInterfaceDisplayUpdate()
{
   static int accumulatedDisplayTime = 0;
  
   if( accumulatedDisplayTime >= DISPLAY_REFRESH_TIME_MS ) {
       accumulatedDisplayTime = 0;
       userInterfaceDisplayReportStateUpdate();
   } else {
       accumulatedDisplayTime += SYSTEM_DELAY_TIME;
   }
}
