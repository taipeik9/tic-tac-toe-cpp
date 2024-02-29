#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>

namespace tictactoe
{
  class Player
  {
    char *m_name{};
    int m_id;
    char m_symbol;

  public:
    Player();
    ~Player();

    void set(char const *name, char symbol, int id);
    char getSymbol() const;
    // char *getName() const;
    std::ostream &display(std::ostream &os = std::cout) const;
  };
}

#endif