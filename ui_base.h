/*
1602-AAF
Copyright (C) 2018 SALMIERI Nicolas

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef UI_BASE_H
#define UI_BASE_H

#include "inputlistener.h"
#include "app.h"

class App;
struct Ui_Base : public InputListener
{
    enum class RequestType{
        BackToMain,
        exit,
        Rendering,
    };

    Ui_Base(App *app);
    virtual ~Ui_Base(){}
    virtual void compute();
    virtual void render();
    virtual void HandleClick();
    bool PullRequest(RequestType type);
    /// a way for the outside to set needRendering to true
    void Update();
protected:
    /// call whenever the UI whant to be deleted, the parent ui will be set to active
    void exit();
    /// set to true if a rendering is needed, will be set back to false whenever the action has been done
    bool needRendering;
    /// set to true if need to go to main UI, will be set back to false whenever the action has been done
    bool BackToMainRequest;
    /// Main App (not owner)
    App *app;
private:
    bool exitRequested;
};

#endif // UI_BASE_H
