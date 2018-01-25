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
#ifndef APP_H
#define APP_H

#include "LiquidCrystal.h"
#include "vector.h"

class Ui_Base;

class App
{
    Vector<Ui_Base *> UiArray;
    uint8_t UiID;
    void welcomeAnimation(uint8_t charDelay);
public:
    void openSubUI(Ui_Base *subUi);
    App(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void run(Ui_Base *MainUI);
    LiquidCrystal lcd;
protected:
    virtual bool AppOnMode()=0;
    virtual void AppInit()=0;
    virtual void AppLoop()=0;
    virtual void AppDelete()=0;
};

#endif // APP_H
