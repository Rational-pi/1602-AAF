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
