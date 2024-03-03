#include "player.h"

using namespace std;

namespace tictactoe
{
  Player::Player()
  {
    m_name = nullptr;
    m_symbol = 0;
    m_wins = 0;
  }

  Player::~Player()
  {
    delete[] m_name;
    m_name = nullptr;
  }

  void Player::set(char const *name, char symbol)
  {
    m_name = nullptr;
    m_symbol = 0;
    m_wins = 0;

    if (name != nullptr && name[0] != '\0' && symbol != 0)
    {
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      m_symbol = symbol;
    }
  }

  char Player::getSymbol() const
  {
    return m_symbol;
  }

  char *Player::getName() const
  {
    return m_name;
  }

  int Player::getWins() const
  {
    return m_wins;
  }

  ostream &Player::display(ostream &os) const
  {
    os << m_name << ": " << m_symbol << endl;
    return os;
  }

  Player &Player::operator++()
  {
    m_wins++;
    return *this;
  }
}