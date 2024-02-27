#include <iostream>
#include <cstring>

#include "player.h"

namespace tictactoe
{
  Player::Player()
  {
    char *m_name = nullptr;
    char m_symbol = 0;
  }

  Player::~Player()
  {
    delete[] m_name;
    m_name = nullptr;
  }

  Player::Player(char *name, char symbol)
  {
    *this = Player();

    if (name != nullptr && name[0] != '\0' && symbol)
    {
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      m_symbol = symbol;
    }
  }
}