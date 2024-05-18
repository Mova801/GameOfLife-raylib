#pragma once

#include <string>
#include "simulation.h"
#include "gui.h"

namespace GameOfLife
{
    class Game
    {
    public:
        Game(int fps);
        void Run();
        void Draw(std::string state);
        void Update();
        void AddLiveCell(int mouseX, int mouseY);
        void RemoveLiveCell(int mouseX, int mouseY);

    private:
        Simulation simulation;
        Gui gui;
    };

}
