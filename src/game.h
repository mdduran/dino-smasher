#ifndef GAME_H
#define GAME_H

#include <Arduboy2.h>
#include <Tinyfont.h>

enum class GameState : uint8_t
{
    TITLE,
    GAMEPLAY,
    GAMEOVER,
    HIGHSCORE
};

class DinoSmasherGame
{
public:
    DinoSmasherGame(void) = default;
    void run(void);

private:
    GameState showTitleScreen();
    GameState showGameplayScreen();
    GameState showGameOverScreen();
    GameState showHighScoreScreen();
    Arduboy2Base arduboy;
    Tinyfont tinyfont = Tinyfont(arduboy.getBuffer(), Arduboy2::width(), Arduboy2::height());
    GameState currGameState = GameState::TITLE;
};
#endif
