#include "game.h"

void DinoSmasherGame::run(void)
{
    arduboy.begin();
    arduboy.setFrameRate(45);
    arduboy.initRandomSeed();

    while (true)
    {
        switch (currGameState)
        {
        case GameState::GAMEPLAY:
            showGameplayScreen();
            break;

        case GameState::GAMEOVER:
            showGameOverScreen();
            break;

        case GameState::HIGHSCORE:
            showHighScoreScreen();
            break;

        default:
            this->currGameState = showTitleScreen();
            break;
        }
    }
}

GameState DinoSmasherGame::showTitleScreen()
{
    while (true)
    {
        if (!arduboy.nextFrame())
            continue;
        arduboy.pollButtons();

        arduboy.clear();
        tinyfont.setCursor(23, 21);
        tinyfont.print(F("Title screen"));
        if (arduboy.justPressed(A_BUTTON))
        {
            this->currGameState = showGameplayScreen();
        }
        arduboy.display();
    }
    return GameState::TITLE;
}

GameState DinoSmasherGame::showGameplayScreen()
{
    while (true)
    {
        if (!arduboy.nextFrame())
            continue;
        arduboy.pollButtons();

        arduboy.clear();
        tinyfont.setCursor(0, 0);

        playerInput();
        drawWorld();

        if (arduboy.justPressed(A_BUTTON))
        {
            this->currGameState = showGameOverScreen();
        }
        if (arduboy.justPressed(B_BUTTON))
        {
            this->currGameState = showHighScoreScreen();
        }
        arduboy.display();
    }
    return GameState::GAMEPLAY;
}

GameState DinoSmasherGame::showGameOverScreen()
{
    while (true)
    {
        if (!arduboy.nextFrame())
            continue;
        arduboy.pollButtons();

        arduboy.clear();
        tinyfont.setCursor(23, 21);
        tinyfont.print(F("Game Over!"));
        if (arduboy.justPressed(A_BUTTON))
        {
            this->currGameState = showTitleScreen();
        }
        arduboy.display();
    }
}

GameState DinoSmasherGame::showHighScoreScreen()
{
    while (true)
    {
        if (!arduboy.nextFrame())
            continue;
        arduboy.pollButtons();
        arduboy.clear();
        tinyfont.setCursor(23, 21);
        tinyfont.print(F("High Score screen"));
        if (arduboy.justPressed(A_BUTTON))
        {
            this->currGameState = showTitleScreen();
        }
        arduboy.display();
    }
}

void DinoSmasherGame::drawWorld()
{
    for (int y = 0; y < WORLD_HEIGHT; y++)
    {
        for (int x = 0; x < WORLD_WIDTH; x++)
        {
            Sprites::drawOverwrite(x * TILE_SIZE + mapX, y * TILE_SIZE + mapY, tiles, world[y][x]);
        }
    }
}

void DinoSmasherGame::playerInput()
{
    if(arduboy.pressed(UP_BUTTON)) {
        mapY += 1;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
        mapY -= 1;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
        mapX += 1;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
        mapX -= 1;
    }
}