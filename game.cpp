#include <iostream>

#include "game.h"

namespace tictactoe
{
  Game::Game()
  {
    m_moveCount = 0;

    for (int i = 0; i < 8; ++i)
      m_board[i] = ' ';

    for (int i = 0; i < 1; i++)
      m_players[i] = Player();
  }

  Game::~Game()
  {
  }

  void Game::setPlayers()
  {
    char name[NAME_MAX];
    bool isValid = true;

    for (int i = 0; i < 1; i++)
    {
      do
      {
        cout << "Enter Player " << i + 1 << "'s name: ";

      } while (!isValid);

      m_players[i] = Player();
    }
  }

  ostream &Game::display(ostream &os) const
  {
    os << "Game Board" << endl;

    for (int i = 0; i < 8; ++i)
    {
      os << m_board[i];
      if ((i + 1) % 3 == 0)
      {
        os << endl;
      }
      else
      {
        os << " | ";
      }
    }

    return os;
  }
}