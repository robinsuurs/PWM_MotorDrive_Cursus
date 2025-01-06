/*
 */

#include <avr/io.h>
#include <stdbool.h>

#define BV(bit)                 (1 << (bit))
#define SetBit(byte, bit)       (byte |= BV(bit))
#define ClearBit(byte, bit)     (byte &= ~BV(bit))
#define ToggleBit(byte, bit)    (byte ^= BV(bit))

#define Links   0
#define Rechts  1

void init_Timers(void)
{
    //set fast PWM mode aan van timer0
    TCCR0A |= BV(WGM01) | BV(WGM00);
    TCCR0B &= ~BV(WGM02);

    //set Compare Output Mode van COM A
    TCCR0A |= BV(COM0A1)& ~BV(COM0A0);  //set OC0A pin laag op COM match en set OC0A pin hoog bij BOTTOM


    //set Compare Output Mode van COM B
    TCCR0A |= BV(COM0B1) & ~BV(COM0B0);  //set OC0B pin laag op COM match en set OC0A pin hoog bij BOTTOM



    //set clock snelheid op clk/64
    TCCR0B |= BV(CS01) | BV(CS00);

    //set standaard COM waarde AKA pulse breedte
    OCR0A = 127; //50% duty cycle
    OCR0B = 127;


}

void SetMotor(char Speed, bool Dir)
{
    if(Speed)
    {
        if(Dir == Rechts)
        {
            OCR0A = Speed;
            ClearBit(DDRD, PD5);
            SetBit(DDRD, PD6);

        }
        else
        {
            OCR0B = Speed;
            ClearBit(DDRD, PD6);
            SetBit(DDRD, PD5);
        }
    }
    else
    {
        ClearBit(DDRD, PD6); ///D6
        ClearBit(DDRD, PD5); ///D5
    }



}


int main(void)
{

    init_Timers();

    //stuur nog geen PWM uit
    ClearBit(DDRD, PD6); ///D6
    ClearBit(DDRD, PD5); ///D5



    while(1)
    {
        SetMotor(100,Rechts);
    }
    ;

    return 0;
}
