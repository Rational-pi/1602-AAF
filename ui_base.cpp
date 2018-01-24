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
