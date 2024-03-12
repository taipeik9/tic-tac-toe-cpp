#include <limits>

#include "game.h"
#include "utils.h"

using namespace std;

namespace tictactoe
{
  Game::Game()
  {
    m_over = false;
    m_gameSize = 0;
    m_boards = nullptr;
    m_winIds = nullptr;

    for (int i = 0; i < 9; ++i)
      m_board[i] = ' ';
    for (int i = 0; i < NUM_PLAYERS; ++i)
      m_players[i] = Player();
  }

  Game::~Game()
  {
    delete[] m_boards;
    m_boards = nullptr;

    delete[] m_winIds;
    m_winIds = nullptr;
  }

  void Game::setPlayers()
  {
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
      setPlayer(m_players[i], i + 1);
    }
  }

  void Game::setPlayer(Player &player, int playNum)
  {
    bool isValid = false;
    char name[MAX_NAME];
    char symbol;

    do
    {
      cout << "Enter Player " << playNum << "'s name (max 50 characters): ";
      isValid = validateStringInput(name, MAX_NAME, "Invalid input. Please input a string with a maximum length of 50 characters.");
    } while (!isValid);

    do
    {
      cout << "Enter Player " << playNum << "'s symbol: ";
      isValid = validateCharInput(symbol);
    } while (!isValid);

    player.set(name, symbol);
  }

  void Game::selectMove(Player &player)
  {
    int row;
    int col;
    bool isValid;
    bool flag = true;

    player.display();

    do
    {
      isValid = true;

      do
      {
        cout << "Enter column number: ";
        flag = inputIntRange(1, 3, col);
      } while (!flag);

      do
      {
        cout << "Enter row number: ";
        flag = inputIntRange(1, 3, row);
      } while (!flag);

      isValid = setMove(col, row, player);

      if (!isValid)
        cout << "Spot has already been taken, try again." << endl;
    } while (!isValid);
  }

  bool Game::setMove(int column, int row, Player &player)
  {
    int index = (column + ((row - 1) * 3)) - 1;
    bool flag = true;

    if (m_board[index] == ' ')
      m_board[index] = player.getSymbol();
    else
      flag = false;

    return flag;
  }

  bool Game::checkWin()
  {
    bool flag = false;

    int const winCons[8][3] = {
        {0, 1, 2}, // horizontal win conditions
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6}, // veritical win conditions
        {1, 4, 7},
        {2, 5, 8},
        {2, 4, 6}, // diagonal win conditions
        {0, 4, 8}};

    for (int i = 0; i < 8; ++i)
    {
      if (m_board[winCons[i][0]] == m_board[winCons[i][1]] &&
          m_board[winCons[i][1]] == m_board[winCons[i][2]] &&
          m_board[winCons[i][0]] != ' ' && m_board[winCons[i][1]] != ' ' &&
          m_board[winCons[i][2]] != ' ')
      {
        flag = true;
      }
    }

    return flag;
  }

  bool Game::checkDraw()
  {
    bool flag = true;

    for (int i = 0; i < 9; ++i)
    {
      if (m_board[i] == ' ')
      {
        flag = false;
      }
    }

    return flag;
  }

  void Game::setGame()
  {
    int gameSize;
    bool flag = true;

    do
    {
      cout << "Please enter the amount of games you would like to play: ";
      flag = inputIntRange(1, MAX_GAMES, gameSize);
    } while (!flag);

    while ((getchar()) != '\n')
      ;

    m_boards = new char[9 * gameSize];
    m_winIds = new int[gameSize];

    m_gameSize = gameSize;
  }

  void Game::resetBoard()
  {
    for (int i = 0; i < 9; ++i)
      m_board[i] = ' ';
  }

  ostream &Game::display(ostream &os) const
  {
    int row = 1;

    os << "Game Board" << endl;

    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
      m_players[i].display();
    }
    os << "\n";
    os << "     1   2   3" << endl;
    os << "   +-----------+" << endl;
    os << " " << row++ << " | ";

    for (int i = 0; i < 9; ++i)
    {
      os << m_board[i];
      if ((i + 1) % 3 == 0)
      {
        os << " |" << endl;
        if (i != 8)
        {
          os << "   |---+---+---|" << endl;
          os << " " << row++ << " | ";
        }
      }
      else
      {
        os << " | ";
      }
    }

    os << "   +-----------+" << endl;

    return os;
  }

  void Game::start()
  {
    int turnIndex = 0;

    setGame();

    setPlayers();

    for (int i = 0; i < m_gameSize; ++i)
    {
      m_over = false;

      do
      {
        display();
        selectMove(m_players[turnIndex]);

        if (checkWin())
        {
          cout << m_players[turnIndex].getName() << " Wins Game #" << i + 1 << endl;
          ++m_players[turnIndex];

          m_winIds[i] = turnIndex;
          m_over = true;
        }
        else if (checkDraw())
        {
          cout << "Draw for Game #" << i + 1 << endl;
          m_winIds[i] = -1;
          m_over = true;
        }

        turnIndex = turnIndex == 0 ? 1 : 0;

      } while (!m_over);

      for (int j = 0; j < 9; ++j)
      {
        m_boards[(i * 9) + j] = m_board[j];
      }
      resetBoard();
    }

    displayEndGame();
    cout << "Thanks for playing!" << endl;
  }

  ostream &Game::displayEndGame(ostream &os) const
  {
    os << "All Games Complete! Summary Below" << endl;

    for (int i = 0; i < m_gameSize; ++i)
    {
      if (m_winIds[i] == 0 || m_winIds[i] == 1)
        os << m_players[m_winIds[i]].getName() << " won Game #" << i + 1 << endl;
      else
        os << "Game #" << i + 1 << " was a Draw!" << endl;

      os << "+-----------+" << endl;
      os << "| ";

      for (int j = 0; j < 9; ++j)
      {

        os << m_boards[(i * 9) + j];
        if ((j + 1) % 3 == 0)
        {
          os << " |" << endl;
          if (j != 8)
          {
            os << "|---+---+---|" << endl;
            os << "| ";
          }
        }
        else
        {
          os << " | ";
        }
      }
      os << "+-----------+" << endl;
      os << "\n";
    }

    os << "Total score was:" << endl;
    os << m_players[0].getName() << ": " << m_players[0].getWins()
       << " wins" << endl;
    os << m_players[1].getName() << ": " << m_players[1].getWins()
       << " wins" << endl;

    return os;
  }
}