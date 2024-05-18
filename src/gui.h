#pragma once

#include <raylib.h>
#include <string>
#include "raygui.h"
#include "constants.h"

namespace GameOfLife
{

    class Gui
    {
    public:
        Gui();
        void DrawMenu(std::string state);
        void Update();

    private:
        bool _showMenu;
        int menuAnimationFramesCounter;
        float menuStartingWidth;
        float menuEndingWidth;
        bool menuAnimationCompleted;
        Rectangle menuBackground;
    };

}
