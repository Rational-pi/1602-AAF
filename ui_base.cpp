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
#include "ui_base.h"
#include "Arduino.h"

Ui_Base::Ui_Base(App *app):
    InputListener(app),
    needRendering(true),
    exitRequested(false),
    getBackToMain(false)
{

}

void Ui_Base::compute()
{

}

void Ui_Base::render()
{
    app->lcd.clear();
    app->lcd.setCursor(0,0);
    app->lcd.print("UI NOT");
    app->lcd.setCursor(0,1);
    app->lcd.print("IMPLEMENTED!");
}

void Ui_Base::HandleClick()
{
    exit();
}

void Ui_Base::exit()
{
    exitRequested=true;
}
