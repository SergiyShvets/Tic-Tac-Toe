#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"

class Player {
 public:
  Player();
  virtual bool MakeMove(Board &board, COORDS& coord, TILE_STATE& state) = 0;
  virtual int InputCoordX(COORDS& coord) = 0;
  virtual int InputCoordY(COORDS& coord) = 0;
  virtual ~Player();
};

#endif
