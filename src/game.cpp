#include <string>
#include <raylib.h>
#include "game.h"
#include "mathfunc.h"
#include "constants.h"

GameOfLife::Game::Game(int fps = FPS) : simulation(Simulation(SCREEN_W, SCREEN_H, CELL_SIZE)), gui(Gui())
{
    // Initialization
    InitWindow(SCREEN_W, SCREEN_H, WINDOW_NAME);
    simulation.InitializeRandom();
    SetTargetFPS(fps); // Set our game to run at FPS frames-per-second
    Run();
}

void GameOfLife::Game::Run()
{
    std::string state = "running";
    int mouseX = 0, mouseY = 0;
    Camera2D camera = {(Vector2){SCREEN_W / 2, SCREEN_H / 2}, (Vector2){0, 0}, 0.0f, 1.0f};
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Get inputs
        if (IsKeyPressed(KEY_SPACE))
        {
            if (simulation.IsRunning())
            {
                simulation.Stop();
                state = "paused ";
            }
            else
            {
                simulation.Start();
                state = "running";
            }
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !simulation.IsRunning())
        {
            AddLiveCell(mouseX, mouseY);
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && !simulation.IsRunning())
        {
            RemoveLiveCell(mouseX, mouseY);
        }
        if (IsKeyDown(KEY_T))
        {
            camera.zoom = 2.0f;
        }

        // Update
        Update();

        // Draw
        BeginDrawing();
        ClearBackground(DARKGRAY);
        BeginMode2D(camera);
        EndMode2D();
        Draw(state);
        EndDrawing();
    }
    // De-Initialization
    CloseWindow(); // Close window and OpenGL context
}

void GameOfLife::Game::Draw(std::string state)
{
    simulation.Draw();
    gui.DrawMenu(state);
}

void GameOfLife::Game::Update()
{
    simulation.Update();
    gui.Update();
}

void GameOfLife::Game::AddLiveCell(int mouseX, int mouseY)
{
    mouseX = GetMouseX();
    mouseY = GetMouseY();
    int cellX = (int)GameOfLife::map(mouseX, 0, SCREEN_W, 0, RESOLUTION_X);
    int cellY = (int)GameOfLife::map(mouseY, 0, SCREEN_H, 0, RESOLUTION_Y);
    simulation.SetCellValue(cellY, cellX, 1);
}

void GameOfLife::Game::RemoveLiveCell(int mouseX, int mouseY)
{
    mouseX = GetMouseX();
    mouseY = GetMouseY();
    int cellX = (int)GameOfLife::map(mouseX, 0, SCREEN_W, 0, RESOLUTION_X);
    int cellY = (int)GameOfLife::map(mouseY, 0, SCREEN_H, 0, RESOLUTION_Y);
    simulation.SetCellValue(cellY, cellX, 0);
}
