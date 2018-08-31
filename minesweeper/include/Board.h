#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <iostream>
#include <vector>
#include <random>

#include "Entry.h"

class Board
{
private:

    int m_height;

    int m_width;

    int m_numMines;

    std::vector<std::vector<Entry> > m_fields;

    void placeMines();

public:

    Board(int height, int width, int numMines);

    void print(bool showAll);
};

#endif //MINESWEEPER_BOARD_H
