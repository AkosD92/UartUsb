
#include <xc.h>
#include "UartDriver_h.h"
#include <pic16f887.h>


void uartInit()
{
    //Enable TX
    //TXEN = 1;
    //SYNC = 0;
    //SPEN = 1;
    PIE1bits.RCIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
   
    //Enable RX
    CREN = 1;
    SYNC = 0;
    SPEN = 1;
    
    
    //Configure baud-rate:
    //9600bps
    BRGH = 1;
    SPBRG = 25;
     
    
}


