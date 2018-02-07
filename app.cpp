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
#include <Arduino.h>
#include "app.h"
#include "rotaryencoder.h"
#include "ui_usriotester.h"

App::App(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
    lcd(rs,enable,d0,d1,d2,d3),
    UiID(0)
{
    init(); /* Initialize Arduino Librairies */
    lcd.begin(16, 2); // Enables the LCD

}

void App::welcomeAnimation(uint8_t charDelay)
{
    char text[] ="eBike-HUD by";
    delay(charDelay);
    for (int i = 0; i < sizeof(text)-1; ++i) {
        lcd.setCursor(i+2,0);
        lcd.print(text[i]);
        delay(charDelay);
    }
    char text2[]="Nicolas SALMIERI";
    delay(charDelay);
    for (int i = 0; i < sizeof(text2)-1; ++i) {
        lcd.setCursor(i,1);
        lcd.print(text2[i]);
        delay(charDelay);
    }delay(500);
}

/// App is the owner of subUi then
void App::openSubUI(Ui_Base *subUi)
{
    UiVect.push_back(subUi);
    UiID++;
}


void App::run(Ui_Base *MainUI)
{
    /*APP*/{
        welcomeAnimation(50);
        int lastPose,thisPose;
        if (MainUI){
            UiVect.push_back(MainUI);
        }else{
            UiVect.push_back(new UI_usrIOtester(this));
        }

        while (true) {
            AppInit();
            RotaryENcoder::initRotary();
            lastPose=RotaryENcoder::getPose();
            while (AppOnMode()){
                /*UI*/{
                    //Navigation
                    if(UiVect[UiID]->PullRequest(Ui_Base::RequestType::BackToMain)){
                        while (UiVect.size()!=1) {
                            delete UiVect[UiID--];
                            UiVect.pop_back();
                        }
                        UiVect[UiID]->Update();
                    }else if(UiVect[UiID]->PullRequest(Ui_Base::RequestType::exit) && UiID!=0){
                        delete UiVect[UiID];
                        UiVect.pop_back();
                        UiVect[--UiID]->Update();
                    }Ui_Base *CurrentUi=UiVect[UiID];

                    //Encoder rotation event emiting
                    thisPose=RotaryENcoder::getPose();
                    if (thisPose!=lastPose){
                        CurrentUi->HandleDelta(thisPose-lastPose);
                        lastPose=thisPose;
                    }

                    //Encoder click event emmiting
                    if(RotaryENcoder::clicked())CurrentUi->HandleClick();

                    //Compute
                    CurrentUi->compute();

                    //Render
                    if(CurrentUi->PullRequest(Ui_Base::RequestType::Rendering))
                        CurrentUi->render();
                }
                AppLoop();

            }
            AppDelete();
            while (!AppOnMode()){
                delay(200);
            }
        }
    }

    //float read=analogRead(7);
    //float ratio=45.3653174f/1024;
    //while (true){
    //    lcd.clear();
    //    lcd.setCursor(10,1);
    //    lcd.print(ratio*(read=read*0.95f+analogRead(7)*0.05f),3);
    //    lcd.setCursor(15,1);
    //    lcd.print("V");
    //}
}
