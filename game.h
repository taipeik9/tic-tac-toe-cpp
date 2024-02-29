#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "player.h"

namespace tictactoe
{
  const int NUM_PLAYERS = 2;
  const int MAX_NAME = 50;

  class Game
  {
    int m_moveCount;
    char m_board[9]{};
    bool m_over;
    Player m_players[NUM_PLAYERS]{};

  public:
    Game();
    ~Game();

    std::ostream &display(std::ostream &os = std::cout) const;
    void setPlayer(Player &player, int playNum);
    void setPlayers();

    void setMove(int column, int row, Player &player);
    void selectMove(Player &player);

    void start();
  };
}

#endif