#ifndef UI_VALUEEDITOR_H
#define UI_VALUEEDITOR_H
#include "ui_base.h"

template<typename Data>
struct Ui_ValueEditor : public Ui_Base
{
public:
    Ui_ValueEditor(App *app,Data *EditedVal):Ui_Base(app),EditedVal(EditedVal){}
    virtual void compute(){}
    virtual void render(){
        app->lcd.clear();
        app->lcd.setCursor(0,0);
        app->lcd.print("");
    }
    virtual void HandleClick(){}
    virtual void HandleDelta(int8_t delta){}
private:
    Data *EditedVal;
};


#endif // UI_VALUEEDITOR_H
