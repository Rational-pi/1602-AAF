#ifndef UI_USRIOTESTER_H
#define UI_USRIOTESTER_H

#include "ui_base.h"

class UI_usrIOtester : public Ui_Base
{
    int32_t count;
    bool toogle;
public:
    UI_usrIOtester(App *app);

    virtual void render();
    virtual void HandleClick();
    virtual void HandleDelta(int8_t delta);
    virtual void compute();
};

#endif // UI_USRIOTESTER_H
