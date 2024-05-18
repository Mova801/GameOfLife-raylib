#include "simulation.h"

int GameOfLife::Simulation::CountLiveNeighbors(int row, int col)
{
    int liveNeighbors = 0;
    for (int neighborRow = row - 1; neighborRow <= row + 1; ++neighborRow)
    {
        for (int neighborCol = col - 1; neighborCol <= col + 1; ++neighborCol)
        {
            if (neighborRow == row && neighborCol == col)
                continue;
            int y = (neighborRow + grid1.GetRows()) % grid1.GetRows();
            int x = (neighborCol + grid1.GetColumns()) % grid1.GetColumns();
            liveNeighbors += grid1.GetValue(y, x);
        }
    }
    return liveNeighbors;
}

void GameOfLife::Simulation::Draw()
{
    grid1.Draw();
}

void GameOfLife::Simulation::Update()
{
    if (!running)
        return;
    for (int row = 0; row < grid1.GetRows(); ++row)
    {
        for (int col = 0; col < grid1.GetColumns(); ++col)
        {
            int aliveNeighbors = CountLiveNeighbors(row, col);
            int cellValue = grid1.GetValue(row, col);
            if (cellValue == 1)
            {
                if (aliveNeighbors < 2 || aliveNeighbors > 3)
                    grid2.SetValue(row, col, 0);
                else
                    grid2.SetValue(row, col, 1);
            }
            else
            {
                if (aliveNeighbors == 3)
                    grid2.SetValue(row, col, 1);
                else
                    grid2.SetValue(row, col, 0);
            }
        }
    }
    grid1 = grid2;
}

void GameOfLife::Simulation::SetCellValue(int row, int col, int value)
{
    grid1.SetValue(row, col, value);
}

void GameOfLife::Simulation::InitializeRandom()
{
    grid1.FillRandom();
}
