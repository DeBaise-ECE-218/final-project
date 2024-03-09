//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "interface.h"
#include "display.h"
#include "sensors.h"

//=====[Declaration of private defines]========================================


//=====[Declaration of private data types]=====================================



//=====[Declaration and initialization of public global objects]===============


//=====[Declaration of external public global variables]=======================


//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============


// Declaration of modeSelector



//=====[Declarations (prototypes) of private functions]========================


static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static void userInterfaceDisplayReportStateInit();
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


static void userInterfaceDisplayReportStateInit()
{
    displayInit();
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Tmp:" );

    displayCharPositionWrite ( 9,0 );
    displayStringWrite( "Gas:" );
    
    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Alarm:" );


   // Display light lvl
   displayCharPositionWrite ( 0,0 );
   displayStringWrite( "NL Lvl:" );

   
   // Display RGB lvls
   displayCharPositionWrite ( 0,1 );
   displayStringWrite( "R:" );

   displayCharPositionWrite ( 6,1 );
   displayStringWrite( "G:" );

   displayCharPositionWrite ( 11,1 );
   displayStringWrite( "B:" );

   
}




static void userInterfaceDisplayReportStateUpdate()
{
   char ldrString[10] = "";
   char rString[10] = "";
   char gString[10] = "";
   char bString[10] = "";
  
   // ldr reading display
   sprintf(ldrString, "%.0f", ldrRead());
   displayCharPositionWrite ( 9,0 );
   displayStringWrite( ldrString );

   // rgb reading display
   sprintf(rString, "%.0f", RpotRead());
   displayCharPositionWrite ( 3,1 );
   displayStringWrite( rString );
   
   sprintf(gString, "%.0f", GpotRead());
   displayCharPositionWrite ( 9,1 );
   displayStringWrite( gString );

   sprintf(bString, "%.0f", BpotRead());
   displayCharPositionWrite ( 14,1 );
   displayStringWrite( bString );
}


static void userInterfaceDisplayInit()
{
   displayInit( DISPLAY_TYPE_GLCD_ST7920, DISPLAY_CONNECTION_SPI );
   userInterfaceDisplayReportStateInit();
}


static void userInterfaceDisplayUpdate()
{
   static int accumulatedDisplayTime = 0;
  
   if( accumulatedDisplayTime >=
       displayRefreshTimeMs ) {


       accumulatedDisplayTime = 0;


       switch ( displayState ) {
           case DISPLAY_REPORT_STATE:
               userInterfaceDisplayReportStateUpdate();


           break;


           default:
               userInterfaceDisplayReportStateInit();
           break;
       }
   }
}
