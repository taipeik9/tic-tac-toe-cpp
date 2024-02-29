#include "game.h"

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
    // for (int i = 0; i < NUM_PLAYERS; ++i)
    // {
    //   setPlayer(m_players[i], i + 1);
    // }

    // testing
    m_players[0].set("Henry", 'X', 1);
    m_players[1].set("Eden", 'O', 2);
  }

  void Game::setPlayer(Player &player, int playNum)
  {
    char name[MAX_NAME];
    char symbol;
    bool isValid = true;

    do
    {
      isValid = true;
      cout << "Enter Player " << playNum << "'s name: ";
      cin >> name;

      cout << "Enter Player " << playNum << "'s symbol: ";
      cin >> symbol;

      if (symbol == '\0' || name[0] == '\0')
      {
        cout << "Invalid input." << endl;
        isValid = false;
      }
    } while (!isValid);

    player.set(name, symbol, playNum);
  }

  void Game::selectMove(Player &player)
  {
    int row;
    int col;

    player.display();
    cout << "Enter column number: ";
    cin >> col;

    cout << "Enter row number: ";
    cin >> row;

    setMove(col, row, player);
  }

  void Game::setMove(int column, int row, Player &player)
  {
    m_board[(column + ((row - 1) * 3)) - 1] = player.getSymbol();
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

    while (!m_over)
    {
      selectMove(m_players[i % 2 != 0]);
      ++i;
      if (i == 8)
        m_over = false;

      display();
    }
  }
}