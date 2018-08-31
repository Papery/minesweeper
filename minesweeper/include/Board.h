#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <iostream>
#include <vector>
#include <random>

#include "Entry.h"

enum Outcome
{
    valid, exploded, won, outofbound
};

class Board
{
private:

    int m_height;

    int m_width;

    int m_numMines;

    int m_numRevealedEntries;

    std::vector<std::vector<Entry> > m_fields;

    void placeMines();
    void reveal(int y, int x);

public:

    Board() = default;

    void initialize(int height, int width, int numMines);

    Outcome doMove(int y, int x, bool markAsMine);

    void print(bool showAll) const;
};

#endif //MINESWEEPER_BOARD_H
