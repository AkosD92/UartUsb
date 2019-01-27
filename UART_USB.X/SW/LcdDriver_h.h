
//Adat: PORTD
//RS (Register Select) = C.0 [1:DATA  |  0:INSTRUCTION]	
//E (LCD Enable) = C.2
//R/W  -> GND	
//BF (Busy Flag) = PORTD.7

#define RS PORTCbits.RC0
#define E PORTCbits.RC2

#define FSET 0b00111000
#define DSPOFF 0b00001000
#define DSPON 0b00001100
#define DSPCLR 0b00000001
#define ENMOD 0b00000110

void lcdInit();
void lcdBe();
void lcdClean();
void WriteLine1(char[]);
void WriteLine2(char[]);

#define _XTAL_FREQ 4000000

