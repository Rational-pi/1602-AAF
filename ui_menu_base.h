#ifndef UI_MENU_BASE_H
#define UI_MENU_BASE_H
#include "ui_base.h"
#include "vector.h"

class Ui_Menu_Base : public Ui_Base
{
    Vector<char *> itemNames;
    int8_t pose;
public:
    virtual void compute();
    virtual void render();
    virtual void HandleClick();
    virtual void HandleDelta(int8_t delta);
    Ui_Menu_Base(App *app);
protected:
    void addItem(const char *sting);
};

#endif // UI_MENU_BASE_H
