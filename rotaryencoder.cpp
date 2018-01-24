#include "rotaryencoder.h"

namespace RotaryENcoder {
uint8_t state;
int16_t pose;
uint8_t lastCLK=0x01;
bool SWwasPressed;

void CBintEncoder(){
    state=PIND;
    /*false pulses are always the same clk as before, so we escape them*/
    if((state>>2&0x01)==lastCLK)return;
    lastCLK=state>>2&0x01;

    switch (state&0x14) {
    case 4:/*CW*/
        pose++;
        break;
    case 20:/*CCW*/
        pose--;
        break;
    }
}

}

bool RotaryENcoder::clicked()
{
    bool pressed = (PIND>>1&0x01)==0x00;
    bool clicked = !SWwasPressed && pressed;
    SWwasPressed = pressed;
    return clicked;
}



void RotaryENcoder::initRotary()
{
    SWwasPressed=false;
    pose=0;
    pinMode(1, INPUT);// SW  digital pin
    pinMode(2, INPUT);// DT  digital pin
    pinMode(4, INPUT);// CLK digital pin
    attachInterrupt(0/*digital pin 2*/, CBintEncoder, CHANGE);
}

int RotaryENcoder::getPose()
{
    return pose;
}
