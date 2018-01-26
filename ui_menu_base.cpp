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
#include "ui_menu_base.h"



void Ui_Menu_Base::compute(){}

void Ui_Menu_Base::render(){
    app->lcd.clear();
    app->lcd.setCursor(0,0);
    if (pose!=actionVector.size()){
        app->lcd.print((char*)actionVector[pose].menuTitle);
    }else app->lcd.print("Return");
    app->lcd.setCursor(0,1);
    for (int var = 0; var < actionVector.size()+1; ++var) {
        if(pose==var){
            app->lcd.print((char)0xff);
        }else if(var==actionVector.size()){
            app->lcd.print((char)0x7f);
        }else app->lcd.print(var);
    }
}

void Ui_Menu_Base::HandleClick(){
    if (pose>=actionVector.size()){
        exit();
    }else if(actionVector[pose].factory){
        app->openSubUI(actionVector[pose].factory(app));
    }else{
        app->openSubUI(new Ui_Base(app));
    }
}

void Ui_Menu_Base::HandleDelta(int8_t delta){
    pose+=delta;
    if(pose<=0)pose=0;
    if(pose>=actionVector.size())pose=actionVector.size();
    needRendering=true;
}

Ui_Menu_Base::Ui_Menu_Base(App *app):Ui_Base(app),pose(0){}

void Ui_Menu_Base::addItem(const char* sting, UiFactory Fac){
    actionVector.push_back(Action{sting,Fac});
}

void Ui_Menu_Base::addItem(const char* sting){
    actionVector.push_back(Action{sting,nullptr});
}
