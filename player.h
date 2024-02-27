#ifndef PLAYER_H
#define PLAYER_H

namespace tictactoe
{
  class Player
  {
    char *m_name;
    char m_symbol;

  public:
    Player();
    Player(char *name, char symbol);
    ~Player();
  };
}

#endif