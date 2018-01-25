/*
1602-AAF
Copyright (C) 2018 SALMIERI Nicolas

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
