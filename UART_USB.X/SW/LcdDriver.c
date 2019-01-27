#include "LcdDriver_h.h"
#include <pic16f887.h>
#include <xc.h>

void WriteLine1(char txt1[])
{
    
    
        //set DDRAM address to 00h
        E = 1;
        PORTD = 0b10000000;
        E = 0;
        __delay_us(40);
        
        //write to display
        for (int i = 0; (i < 16) && (txt1[i] != 0); i++)
        {
          
                RS = 1;
                E = 1;
                PORTD = txt1[i];
                E = 0;
                RS = 0;
                __delay_us(45);
    
                        
        }
        
}

void WriteLine2(char txt2[])
{

        //set DDRAM address to 40h
        E = 1;
        PORTD = 0b11000000;
        E = 0;
        __delay_us(40);
        
        //write to display
        for (int i = 0; (i < 16) && (txt2[i] != 0); i++)
        {
           
                RS = 1;
                E = 1;
                PORTD = txt2[i];
                E = 0;
                RS = 0;
                __delay_us(45);
            
        }

}


void lcdInit()
{
    __delay_ms(15);   
    PORTD = FSET;
    E = 1;
    __delay_us(1);
    E = 0;
    
    __delay_ms(5);  
    E = 1;
    __delay_us(1);
    E = 0;
    
    __delay_us(100);
    E = 1;
    __delay_us(1);
    E = 0;
    
    __delay_ms(2);
    E = 1;
    __delay_us(1);
    E = 0;
    __delay_ms(2);
     
    E = 1;
    PORTD = DSPOFF;
    E = 0;
    __delay_ms(2);
     
    E = 1;
    PORTD = DSPCLR;
    E = 0;
    __delay_ms(2);
    
    E = 1;
    PORTD = ENMOD;
    E = 0;
    __delay_ms(2);
    
}



void lcdBe()
{
    PORTD = DSPON;
    E = 1;
    __delay_us(1);
    E = 0;
    __delay_us(40);
}

void lcdClean()
{
    E = 1;
    PORTD = DSPCLR;
    E = 0;
    __delay_ms(2);
}
