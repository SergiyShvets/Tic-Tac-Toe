#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"



class Game {
 public:
  Game();
  virtual ~Game();
  void Run();
  void TryAgain();
 private:

  HumanPlayer* human;
  ComputerPlayer* computer;
  Board* board;

};

#endif /* GAME_H_ */
