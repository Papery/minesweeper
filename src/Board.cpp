#include "Board.h"

void Board::initialize(const int height, const int width, const int numMines)
{
    this->height = std::min(height, MAX_HEIGHT_BOARD);
    this->width = std::min(width, MAX_WIDTH_BOARD);
    this->numMines = std::min(numMines, (int) (height * width * 0.5));
    numRevealedEntries = 0;

    fields.clear();
    fields.resize(this->height);
    for (std::vector<Tile>& line : fields)
    {
        line.resize(this->width, {0, TileStatus::unknown});
    }

    placeMines();
    printCurrentState();
}

void Board::placeMines()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> yDistribution(0, height - 1);
    std::uniform_int_distribution<int> xDistribution(0, width - 1);

    int placedMines = 0;

    while (placedMines < numMines)
    {
        int y = yDistribution(generator);
        int x = xDistribution(generator);

        if (fields[y][x].data != MINE)
        {
            placeMine(y, x);
            ++placedMines;
        }
    }
}

void Board::placeMine(const int y, const int x)
{
    fields[y][x].data = MINE;

    for (int adjY = y - 1; adjY <= y + 1; ++adjY)
    {
        if (adjY < 0 || adjY >= height)
        {
            continue;
        }

        for (int adjX = x - 1; adjX <= x + 1; ++adjX)
        {
            if (adjX < 0 || adjX >= width)
            {
                continue;
            }

            if (fields[adjY][adjX].data != MINE)
            {
                fields[adjY][adjX].data += 1;
            }
        }
    }
}

void Board::printCurrentState() const
{
    std::cout << std::endl;

    for (int y = -2; y < height; ++y)
    {
        for (int x = -2; x < width; ++x)
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
            else
            {
                fields[y][x].printStatus();
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::printCompleteBoard() const
{
    std::cout << std::endl;

    for (int y = -2; y < height; ++y)
    {
        for (int x = -2; x < width; ++x)
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
            else
            {
                fields[y][x].printData();
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

BoardState Board::doMove(int y, int x, bool markAsMine)
{
    if (y < 0 || y >= height || x < 0 || x >= width)
    {
        printCurrentState();
        throw std::invalid_argument("Specified tile does not exist.");
    }

    if (!markAsMine && fields[y][x].data == MINE)
    {
        printCompleteBoard();
        return BoardState::exploded;
    }

    if (!markAsMine && (fields[y][x].status == TileStatus::revealed))
    {
        printCurrentState();
        throw std::invalid_argument("Tile is already revealed.");
    }

    if (!markAsMine && (fields[y][x].status == TileStatus::markedAsMine))
    {
        fields[y][x].status = TileStatus::unknown;
        printCurrentState();
        return BoardState::valid;
    }

    if (markAsMine)
    {
        if (fields[y][x].status == TileStatus::unknown)
        {
            fields[y][x].status = TileStatus::markedAsMine;
            printCurrentState();
            return BoardState::valid;
        }
        printCurrentState();
        throw std::invalid_argument("Tile is already revealed and cannot be marked as mine.");
    }

    reveal(y, x);

    if (numRevealedEntries == height * width - numMines)
    {
        printCompleteBoard();
        return BoardState::won;
    }

    printCurrentState();
    return BoardState::valid;
}

void Board::reveal(const int y, const int x)
{
    if (fields[y][x].status != TileStatus::unknown)
    {
        return;
    }

    if (fields[y][x].data != 0)
    {
        fields[y][x].status = TileStatus::revealed;
        ++numRevealedEntries;
        return;
    }

    if (fields[y][x].data == 0)
    {
        fields[y][x].status = TileStatus::revealed;
        ++numRevealedEntries;

        for (int adjY = y - 1; adjY <= y + 1; ++adjY)
        {
            if (adjY < 0 || adjY > height - 1)
            {
                continue;
            }

            for (int adjX = x - 1; adjX <= x + 1; ++adjX)
            {
                if (adjX < 0 || adjX > width - 1)
                {
                    continue;
                }

                reveal(adjY, adjX);
            }
        }
    }
}