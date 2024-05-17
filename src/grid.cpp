#include "grid.h"

void GameOfLife::Grid::Draw()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            Color color = cells[row][col] ? ALIVE_CELL_COLOR : DEAD_CELL_COLOR;
            DrawRectangle(row * cellSize, col * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void GameOfLife::Grid::SetValue(int row, int col, int value)
{
    if (IsWithinBounds(row, col))
        cells[row][col] = value;
}

int GameOfLife::Grid::GetValue(int row, int col)
{
    if (IsWithinBounds(row, col))
        return cells[row][col];
    return 0;
}

bool GameOfLife::Grid::IsWithinBounds(int row, int col)
{
    return row > 0 && row < rows && col > 0 && col < columns;
}

void GameOfLife::Grid::FillRandom()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            cells[row][col] = GetRandomValue(0, 1) ? 0 : 1;
        }
    }
}