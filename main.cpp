#include "mbed.h"
#include "arm_book_lib.h"
#include "interface.h"

// main() runs in its own thread in the OS
int main()
{

    userInterfaceInit();

    while (true) {

        userInterfaceUpdate();
        delay(SYSTEM_DELAY_TIME);
    }
}

