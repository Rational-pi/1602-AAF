#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H

#include <Arduino.h>

namespace RotaryENcoder {

void initRotary();
int getPose();
bool clicked();

}


#endif // ROTARYENCODER_H
