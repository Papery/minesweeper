#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Board.h"

class Game
{

private:

    Board m_board;

    bool m_continue;
    bool m_running;

    void start();
    void move();

public:

    Game();
    void run();
};

#endif //MINESWEEPER_GAME_H
