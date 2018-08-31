#include "Game.h"

Game::Game()
{
}

void Game::run()
{
    m_continue = true;

    while (m_continue)
    {
        start();

        while (m_running)
        {
            move();
        }
    }
}

void Game::start()
{
    int heightBoard;
    int widthBoard;
    int numMines;

    std::cout << "Enter height of board: ";
    std::cin >> heightBoard;

    std::cout << "Enter width of board: ";
    std::cin >> widthBoard;

    std::cout << "Enter number of mines: ";
    std::cin >> numMines;

    m_board.initialize(heightBoard, widthBoard, numMines);
    m_running = true;
}

void Game::move()
{
    int y;
    int x;
    bool markAsMine;

    std::cout << "Enter y coordinate: ";
    std::cin >> y;

    std::cout << "Enter x coordinate: ";
    std::cin >> x;

    std::cout << "Mark as mine (1) or reveal (0): ";
    std::cin >> markAsMine;

    Outcome outcome = m_board.doMove(y, x, markAsMine);

    if (outcome == Outcome::valid)
    {
        return;
    }
    else if (outcome == Outcome::outofbound)
    {
        std::cout << "Invalid coordinates. No move made." << std::endl;
        return;
    }
    else if (outcome == Outcome::exploded)
    {
        std::cout << "You exploded!" << std::endl;
        m_running = false;
    }
    else if (outcome == Outcome::won)
    {
        std::cout << "You won!" << std::endl;
        m_running = false;
    }

    std::cout << "Do you want to start a new game? (yes = 1, no = 0) ?";
    std::cin >> m_continue;
}