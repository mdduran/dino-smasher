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
        tinyfont.setCursor(23, 21);
        tinyfont.print(F("Gameplay screen"));
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