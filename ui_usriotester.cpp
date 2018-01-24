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
