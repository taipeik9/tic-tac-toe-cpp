#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "player.h"

namespace tictactoe
{
  const int NUM_PLAYERS = 2;
  const int MAX_NAME = 50;
  const int MAX_GAMES = 50;

  class Game
  {
    char m_board[9]{};
    bool m_over;
    Player m_players[NUM_PLAYERS]{};

    int m_gameSize;
    char *m_boards{};
    int *m_winIds{};

  public:
    Game();
    ~Game();

    std::ostream &display(std::ostream &os = std::cout) const;
    std::ostream &displayEndGame(std::ostream &os = std::cout) const;

    void setPlayer(Player &player, int playNum);
    void setPlayers();

    void setGame();
    void resetBoard();

    bool setMove(int column, int row, Player &player);
    bool checkWin();
    bool checkDraw();

    void selectMove(Player &player);
    void start();
  };
}

#endif