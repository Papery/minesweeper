#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <iostream>
#include <vector>
#include <random>

enum Status
{
    mine, revealed, unknown
};

struct Entry
{
    int data;
    Status status;
};

class Board
{
private:

    const int MINE = -1;

    const int MAX_HEIGHT = 100;

    const int MAX_WIDTH = 100;

    int m_height;

    int m_width;

    int m_numMines;

    std::vector<std::vector<Entry> > m_fields;

    void placeMines();

    void print(bool showAll);

    void printEntryData(const Entry& entry);

    void printEntryStatus(const Entry& entry);

public:

    Board(int height, int width, int numMines);

};

#endif //MINESWEEPER_BOARD_H
