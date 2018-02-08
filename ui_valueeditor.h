#ifndef UI_VALUEEDITOR_H
#define UI_VALUEEDITOR_H
#include "ui_base.h"
#include "ui_menu_base.h"

/// return a fuction that build a value editor linked to the public member "member" of the app child "childType"
#define EditorBuilder(childType,member)\
    [](App* a){\
        childType* app=static_cast<childType*>(a);\
        return (Ui_Base*)new Ui_ValueEditor<decltype(app->member)>(a,&(app->member));\
    }\

template<typename Data>
struct Ui_ValueEditor : public Ui_Base
{
public:
    Ui_ValueEditor(App *app,Data *EditedVal):
        Ui_Base(app),
        EditedVal(EditedVal),
        currentState(state::Value),
        pitch(1){
        Data testVal=0;
        testVal+=0.01;
        DataIsInteger=testVal!=0.01;
    }
    virtual void compute(){}
    virtual void render(){
        app->lcd.clear();
        app->lcd.setCursor(0,0);
        switch (currentState) {
        case state::Value:
            app->lcd.print("Value: ");
            app->lcd.setCursor(0,1);
            app->lcd.print(*EditedVal,10);
            break;
        case state::pitch:
            app->lcd.print("Pitch: ");
            app->lcd.setCursor(0,1);
            app->lcd.print(pitch,15);
            break;
        case state::saveExit:
            app->lcd.print("Exit?: NO");
            break;
        }
    }
    virtual void HandleClick(){
        switch (currentState) {
        case state::Value:
            currentState=state::pitch;
            break;
        case state::pitch:
            currentState=state::saveExit;
            break;
        case state::saveExit:
            currentState=state::Value;
            break;
        }
        needRendering=true;
    }
    virtual void HandleDelta(int8_t delta){
        switch (currentState) {
        case state::Value:
            *EditedVal+=pitch*delta;
            break;
        case state::pitch:
            pitch*=delta>0?2:0.5;
            if(DataIsInteger&&pitch<=1)pitch=1;
            break;
        case state::saveExit:
            exit();
            break;
        }
        needRendering=true;
    }


    float pitch;
private:
    bool DataIsInteger;
    Data *EditedVal;
    enum class state{
        Value,
        pitch,
        saveExit,
    }currentState;
};


#endif // UI_VALUEEDITOR_H
