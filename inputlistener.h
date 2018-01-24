#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include "app.h"

struct InputListener
{
    InputListener(App *app);
    virtual void HandleClick()=0;
    virtual void HandleDelta(int8_t delta){}
protected:
    App *app;
};

#endif // INPUTLISTENER_H
