#ifndef GAME_H
#define GAME_H

#include "player.h"
using namespace std;

namespace tictactoe
{
  const int NUM_PLAYERS = 2;
  const int MAX_NAME = 50;

  class Game
  {
    int m_moveCount;
    char m_board[9];

    Player m_players[NUM_PLAYERS];

  public:
    Game();
    ~Game();
    ostream &display(ostream &os = cout) const;
    void setPlayers();
  };
}

#endif