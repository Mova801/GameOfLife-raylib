#pragma once

#include "constants.h"
#include "grid.h"

namespace GameOfLife
{
    class Simulation
    {
    public:
        Simulation(int width, int height, int cellSize) : running(true), grid1(Grid(width, height, cellSize)), grid2(Grid(width, height, cellSize)){};
        int CountLiveNeighbors(int row, int col);
        void Draw();
        void Update();
        void SetCellValue(int row, int col, int value);
        void InitializeRandom();
        void Start() { running = true; };
        void Stop() { running = false; };
        bool IsRunning() { return running; };
    private:
        int running;
        Grid grid1;
        Grid grid2;
    };
}
