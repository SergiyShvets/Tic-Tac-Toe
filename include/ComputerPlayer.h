#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"


class ComputerPlayer : public Player {
 public:
  ComputerPlayer();
  virtual ~ComputerPlayer();
  bool MakeMove(Board &board, COORDS& coord, TILE_STATE& state);
  int InputCoordX(COORDS& coord);
  int InputCoordY(COORDS& coord);
 private:
  Board* board;
};

#endif
