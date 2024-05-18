#pragma once

#include <raylib.h>

//
#define RECTANGULAR_CELL
#ifndef RECTANGULAR_CELL
#define CIRCULAR_CELL
#endif

// window constants
#define WINDOW_NAME "GameOfLifeSimulation - 0.0.0"
#define SCREEN_W 1080
#define SCREEN_H 740
#define FPS 60

// menu constants
#define MENU_TITLE "VITAS"
#define MENU_SUBTITLE "simulation0.0.0"
#define MENU_COLOR Color{132, 59, 98, 255}
#define MENU_TEXT_POS_X 10
#define MENU_WIDTH 200 // in pixels
#define MENU_ANIMATION_TIME 60 // in frames
#define FONT_SIZE 20
#define TEXT_COLOR WHITE

// cell constants
#define CELL_SIZE 5 // cell size in pixels
#define ALIVE_CELL_COLOR Color{0, 255, 0, 255}
#define DEAD_CELL_COLOR BLACK

// simulation constants
#define RESOLUTION_X SCREEN_W / CELL_SIZE
#define RESOLUTION_Y SCREEN_H / CELL_SIZE
#define SIMULATION_WIDTH 740
#define SIMULATION_HEIGHT 700
