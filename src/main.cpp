#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>
#include <string>
#include "constants.h"
#include "simulation.h"

int main()
{
    // Initialization
    InitWindow(SCREEN_W, SCREEN_H, WINDOW_NAME);

    // game board
    GameOfLife::Simulation game = GameOfLife::Simulation(SCREEN_W, SCREEN_H, CELL_SIZE);
    game.InitializeRandom();
    SetTargetFPS(MIN_FPS); // Set our game to run at FPS frames-per-second

    std::string state = "running";

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Get inputs
        if (IsKeyDown(KEY_SPACE))
        {
            if (game.IsRunning())
            {
                game.Stop();
                state = "paused ";
            }
            else
            {
                game.Start();
                state = "running";
            }
        }
        // Update
        game.Update();

        // Draw
        BeginDrawing();
        ClearBackground(DARKGRAY);
        game.Draw();

        DrawFPS(10, 10);
        DrawText(TextFormat("STATE: %s", state.c_str()), SCREEN_W - state.length() * CELL_SIZE * 1.3f, 10, 20, TEXT_COLOR);
        EndDrawing();
    }
    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
