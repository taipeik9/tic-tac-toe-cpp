#include "player.h"

using namespace std;

namespace tictactoe
{
  Player::Player()
  {
    m_name = nullptr;
    m_id = 0;
    m_symbol = 0;
  }

  Player::~Player()
  {
    delete[] m_name;
    m_name = nullptr;
  }

  void Player::set(char const *name, char symbol, int id)
  {
    m_name = nullptr;
    m_id = 0;
    m_symbol = 0;

    if (name != nullptr && name[0] != '\0' && symbol != 0)
    {
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      m_id = id;
      m_symbol = symbol;
    }
  }

  char Player::getSymbol() const
  {
    return m_symbol;
  }

  // char *Player::getName() const
  // {
  //   return m_name;
  // }

  ostream &Player::display(ostream &os) const
  {
    os << m_name << ": " << m_symbol << endl;
    return os;
  }
}