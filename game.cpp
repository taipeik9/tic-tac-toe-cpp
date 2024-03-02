#include <limits>

#include "game.h"
#include "utils.h"

using namespace std;

namespace tictactoe
{
  Game::Game()
  {
    m_moveCount = 0;
    m_over = false;

    for (int i = 0; i < 9; ++i)
      m_board[i] = ' ';

    for (int i = 0; i < NUM_PLAYERS; ++i)
      m_players[i] = Player();
  }

  Game::~Game()
  {
  }

  void Game::setPlayers()
  {
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
      setPlayer(m_players[i], i + 1);
    }

    // for testing
    // m_players[0].set("Henry", 'X', 1);
    // m_players[1].set("Eden", 'O', 2);
  }

  void Game::setPlayer(Player &player, int playNum)
  {
    bool isValid = false;
    char name[MAX_NAME];
    char symbol;

    do
    {
      cout << "Enter Player " << playNum << "'s name (max 50 characters): ";
      isValid = validateStringInput(name, MAX_NAME);
    } while (!isValid);

    do
    {
      cout << "Enter Player " << playNum << "'s symbol: ";
      isValid = validateCharInput(symbol);
    } while (!isValid);

    while ((getchar()) != '\n')
      ;

    player.set(name, symbol, playNum);
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
    int i = 0;
    setPlayers();
    display();

    do
    {
      selectMove(m_players[i % 2 != 0]);
      ++i;
      if (i == 8)
        m_over = false;

      if (checkWin())
      {
        cout << "You Win!" << endl;
        m_over = true;
      }
      display();

    } while (!m_over);
  }
}