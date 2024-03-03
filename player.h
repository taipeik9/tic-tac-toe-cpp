#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>

namespace tictactoe
{
  class Player
  {
    char *m_name{};
    char m_symbol;
    int m_wins;

  public:
    Player();
    ~Player();

    void set(char const *name, char symbol);
    char getSymbol() const;
    char *getName() const;
    int getWins() const;

    std::ostream &display(std::ostream &os = std::cout) const;

    Player &operator++();
  };
}

#endif