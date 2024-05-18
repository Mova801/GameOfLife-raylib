#include "gui.h"
#include "reasings.h"

GameOfLife::Gui::Gui() : _showMenu(true), menuAnimationFramesCounter(0), menuStartingWidth(0), menuEndingWidth(MENU_WIDTH), menuAnimationCompleted(false), menuBackground({0, 0, 0, SCREEN_H})
{
}

void GameOfLife::Gui::DrawMenu(std::string state)
{
    if (!_showMenu && menuAnimationCompleted)
        return;

    if (!menuAnimationCompleted)
    {
        menuAnimationFramesCounter++;
        menuBackground.width = EaseCircOut((float)menuAnimationFramesCounter, menuStartingWidth, menuEndingWidth, MENU_ANIMATION_TIME);
        if (menuBackground.width == menuEndingWidth || (menuBackground.width == 0 && menuAnimationFramesCounter > 0))
        {
            menuAnimationCompleted = true;
        }
    }
    DrawRectanglePro(menuBackground, (Vector2){0, 0}, 0, MENU_COLOR);

    std::string state_text = TextFormat("STATE: %s", state.c_str());

    int padY = 20;
    int padX = 20;
    int posY = 10;
    int posX = menuBackground.width - (MENU_WIDTH - padX);

    DrawText(MENU_TITLE, posX, posY, FONT_SIZE + 20, TEXT_COLOR);
    posY += 2 * padY;
    DrawText(MENU_SUBTITLE, posX, posY, FONT_SIZE, TEXT_COLOR);
    posY += 1.5 * padY;
    DrawLine(posX, posY, posX + (MENU_WIDTH - (2 * padX)), posY, WHITE);
    posY += padY;
    DrawFPS(posX, posY);
    posY += padY;
    DrawText(state_text.c_str(), posX, posY, FONT_SIZE, TEXT_COLOR);
}

void GameOfLife::Gui::Update()
{
    if (IsKeyPressed(KEY_M))
    {
        menuAnimationFramesCounter = 0;
        _showMenu = !_showMenu;
        if (_showMenu) // showMenu set to true
        {
            menuStartingWidth = 0;
            menuEndingWidth = MENU_WIDTH;
        }
        else // showMenu set to false
        {
            menuStartingWidth = MENU_WIDTH;
            menuEndingWidth = -MENU_WIDTH;
        }
        menuAnimationCompleted = false;
    }
}