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
#include "ui_usriotester.h"
#include "ui_menu_base.h"

UI_usrIOtester::UI_usrIOtester(App *app):
    Ui_Base(app),
    count(0),
    toogle(false)
{


}

void UI_usrIOtester::render(){
    app->lcd.clear();
    app->lcd.setCursor(0,0);
    app->lcd.print("      Pose  :");
    app->lcd.setCursor(13,0);
    app->lcd.print(count);
    app->lcd.setCursor(0,1);
    app->lcd.print("      Switch:");
    app->lcd.setCursor(13,1);
    app->lcd.print(toogle);
}

void UI_usrIOtester::HandleClick(){
    needRendering=true;
    toogle=!toogle;
}

void UI_usrIOtester::HandleDelta(int8_t delta){
    needRendering=true;
    count+=delta;
}

void UI_usrIOtester::compute()
{
    if (count==-2){
        app->openSubUI(new Ui_Menu_Base(app));
        count=0;
    }
}
