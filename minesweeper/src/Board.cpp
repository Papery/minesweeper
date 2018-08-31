#include "Board.h"

Board::Board(const int height, const int width, const int numMines)
{
    m_height = std::min(height, MAX_HEIGHT_BOARD);
    m_width = std::min(width, MAX_WIDTH_BOARD);
    m_numMines = std::min(numMines, (int) (m_height * m_width * 0.5));

    m_fields.resize(m_height);
    for (std::vector<Entry>& line : m_fields)
    {
        line.resize(m_width, {0, Status::unknown});
    }

    placeMines();
}

void Board::placeMines()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> yDistribution(0, m_height - 1);
    std::uniform_int_distribution<int> xDistribution(0, m_width - 1);

    int placedMines = 0;

    while (placedMines < m_numMines)
    {
        int y = yDistribution(generator);
        int x = xDistribution(generator);

        if (m_fields[y][x].data == MINE)
        {
            continue;
        }

        m_fields[y][x].data = MINE;
        ++placedMines;

        for (int adjY = y - 1; adjY <= y + 1; ++adjY)
        {
            if (adjY < 0 || adjY >= m_height)
            {
                continue;
            }

            for (int adjX = x - 1; adjX <= x + 1; ++adjX)
            {
                if (adjX < 0 || adjX >= m_width)
                {
                    continue;
                }

                if (m_fields[adjY][adjX].data != MINE)
                {
                    m_fields[adjY][adjX].data += 1;
                }
            }
        }
    }
}

void Board::print(bool showAll)
{
    std::cout << std::endl;

    for (int y = -2; y < m_height; ++y)
    {
        for (int x = -2; x < m_width; ++x)
        {
            if ((y == -2 && x == -2) || y == -1 || x == -1)
            {
                std::cout << "   ";
            }
            else if (y == -2)
            {
                std::cout << x << " ";
                if (x < 10)
                {
                    std::cout << " ";
                }
            }
            else if (x == -2)
            {
                std::cout << y << " ";
                if (y < 10)
                {
                    std::cout << " ";
                }
            }
            else if (showAll)
            {
                m_fields[y][x].printData();
            }
            else
            {
                m_fields[y][x].printStatus();
            }
        }
        std::cout << std::endl;
    }
}

