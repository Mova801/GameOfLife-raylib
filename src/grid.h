#pragma once

#include <raylib.h>
#include <vector>
#include "constants.h"

namespace GameOfLife
{
    class Grid
    {
    public:
        Grid(int width = SCREEN_W, int height = SCREEN_H, int cellSize = CELL_SIZE) : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {}
        void FillRandom();
        void Draw();
        void SetValue(int row, int col, int value);
        int GetValue(int row, int col);
        bool IsWithinBounds(int row, int col);
        int GetRows() { return rows; };
        int GetColumns() { return columns; };

    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;
    };
}

