#ifndef UI_BASE_H
#define UI_BASE_H

#include "inputlistener.h"

class App;
struct Ui_Base : public InputListener
{
    Ui_Base(App *app);
    virtual void compute();
    virtual void render();
    virtual void HandleClick();
protected:
    void exit();
    bool needRendering;
    bool getBackToMain;
private:
    bool exitRequested;
    friend class App;
};

#endif // UI_BASE_H
