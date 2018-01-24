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
#inc
#include "ui_menu_base.h"



void Ui_Menu_Base::compute(){}

void Ui_Menu_Base::render(){
    app->lcd.clear();
    app->lcd.setCursor(0,0);
    if (pose!=itemNames.size()){
        app->lcd.print(itemNames[pose]);
    }else app->lcd.print("Return");
    app->lcd.setCursor(0,1);
    for (int var = 0; var < itemNames.size()+1; ++var) {
        if(pose==var){
            app->lcd.print((char)0xff);
        }else if(var==itemNames.size()){
            app->lcd.print((char)0x7f);
        }else app->lcd.print(var);
    }
}

void Ui_Menu_Base::HandleClick(){
    switch (pose) {
    case 1:
        exit();
        break;
    default:
        app->openSubUI(new Ui_Base(app));
    }needRendering=true;
}

void Ui_Menu_Base::HandleDelta(int8_t delta){
    pose+=delta;
    if(pose<=0)pose=0;
    if(pose>=itemNames.size())pose=itemNames.size();
    needRendering=true;
}

Ui_Menu_Base::Ui_Menu_Base(App *app):Ui_Base(app),pose(0){
    addItem("NOT IMPLEMENTED!");
}

void Ui_Menu_Base::addItem(const char* sting){
    itemNames.push_back(sting);
}
