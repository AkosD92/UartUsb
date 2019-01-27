/*
 * File:   main.c
 * Author: AkosD
 *
 * Created on 2017. október 22., 15:49
 */


#include <xc.h>
#include "DeviceConfig.h"
#include <pic16f887.h>
#include "LcdDriver_h.h"
#include "UartDriver_h.h"

#define _XTAL_FREQ 4000000
#define LCD_ROW_LENGTH 16
#define PASS 1

void mainInit();

char ReceivedFirstLine[LCD_ROW_LENGTH];
char ReceivedSecondLine[LCD_ROW_LENGTH];
unsigned char FirstLineCnt = 0;
unsigned char SecondLineCnt = 0;

unsigned char ReceivedCheck;
unsigned char CheckPassed = 0;


void interrupt tc_int(void)
{   
    if (RCIF == 1)
    {
        if(FirstLineCnt != (LCD_ROW_LENGTH-1))
        {
            if(RCREG != '\n')
            {
                ReceivedFirstLine[FirstLineCnt] = RCREG;
                FirstLineCnt++;
            }
            else
            {
                FirstLineCnt = (LCD_ROW_LENGTH-1);
            }
            
        }
        else
        {
            if(RCREG != '\n')
            {
                ReceivedSecondLine[SecondLineCnt] = RCREG;
                SecondLineCnt++;
            }
            else
            {
                SecondLineCnt = (LCD_ROW_LENGTH-1);
            }
            
        }
       
          
        RCIF = 0;
      
    }
    
    return;
}

void main(void) {
    /*Call the init functions, place dummy message to LCD*/
    mainInit();  
    lcdInit();
    lcdBe();
    uartInit(); 
  
    WriteLine1("System ready");
    WriteLine2("PIC16F887");
    
    while(1)
    {  
        __delay_ms(10);
        
        if(SecondLineCnt == (LCD_ROW_LENGTH-1))
        {
            lcdClean();
            
            WriteLine1(ReceivedFirstLine);
            WriteLine2(ReceivedSecondLine);
            FirstLineCnt = 0;
            SecondLineCnt = 0;
            
            for(int i = 0; i < LCD_ROW_LENGTH; i++)
            {
                ReceivedFirstLine[i] = ' ';
                ReceivedSecondLine[i] = ' ';
            }
            
        }
 
    }
    

    return;
}

void mainInit()
{
    TRISC = 0;
    TRISCbits.TRISC7 = 1;
    TRISD = 0;
    RS = 0;
    E = 0;
}

