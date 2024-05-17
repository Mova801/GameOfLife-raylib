#include "simulation.h"

int GameOfLife::Simulation::CountLiveNeighbors(int row, int col)
{
    int liveNeighbors = 0;
    for (int i = row - 1; i <= row + 1; ++i)
    {
        for (int j = col - 1; j <= col + 1; ++j)
        {
            if (i == row && j == col)
                continue;
            int y = (i + grid.GetRows()) % grid.GetRows();
            int x = (j + grid.GetColumns()) % grid.GetRows();
            liveNeighbors += grid.GetValue(y, x);
        }
    }
    return liveNeighbors;
}

void GameOfLife::Simulation::Draw()
{
    grid.Draw();
}

void GameOfLife::Simulation::Update()
{
    if (!running)
        return;
    for (int row = 0; row < grid.GetRows(); ++row)
    {
        for (int col = 0; col < grid.GetColumns(); ++col)
        {
            int aliveNeighbors = CountLiveNeighbors(row, col);
            int cellValue = grid.GetValue(row, col);
            if (cellValue == 1)
            {
                if (aliveNeighbors < 2 || aliveNeighbors > 3)
                    canvas.SetValue(row, col, 0);
                else
                    canvas.SetValue(row, col, 1);
            }
            else
            {
                if (aliveNeighbors == 3)
                    canvas.SetValue(row, col, 1);
                else
                    canvas.SetValue(row, col, 0);
            }
        }
    }
    grid = canvas;
}

void GameOfLife::Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

void GameOfLife::Simulation::InitializeRandom()
{
    grid.FillRandom();
}
