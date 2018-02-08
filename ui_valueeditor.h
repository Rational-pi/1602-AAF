#ifndef UI_VALUEEDITOR_H
#define UI_VALUEEDITOR_H
#include "ui_base.h"
#include "ui_menu_base.h"

/// return a fuction that build a value editor linked to the public member "member" of the app child "childType"
#define EditorBuilder(childType,member)\
    [](App* a){\
        childType* app=dynamic_cast<childType*>(a);\
        if (app) return (Ui_Base*)new Ui_ValueEditor<int>(a,&(app->member));\
        else {\
            Ui_Menu_Base* ui=new Ui_Menu_Base(a);\
            return (Ui_Base*)ui->addItem(#childType "!:app");\
        }\
    }\

template<typename Data>
struct Ui_ValueEditor : public Ui_Base
{
public:
    Ui_ValueEditor(App *app,Data *EditedVal):
        Ui_Base(app),
        EditedVal(EditedVal),
        pitch(0.1),
        currentState(state::drawVal){}
    virtual void compute(){}
    virtual void render(){
        app->lcd.clear();
        app->lcd.setCursor(0,0);
        switch (currentState) {
        case state::drawVal:
            app->lcd.print(*EditedVal);
            break;
        case state::menu:
            app->lcd.print("Action implemented");
            break;
        }
    }
    virtual void HandleClick(){
        switch (currentState) {
        case state::drawVal:
            currentState=state::menu;
            break;
        case state::menu:
            currentState=state::drawVal;
            break;
        }
    }
    virtual void HandleDelta(int8_t delta){
        switch (currentState) {
        case state::drawVal:
            EditedVal+=pitch*delta;
            break;
        case state::menu:
            break;
        }
    }
    float pitch;
private:
    Data *EditedVal;
    enum class state{
        drawVal,
        menu,
    }currentState;
};


#endif // UI_VALUEEDITOR_H
