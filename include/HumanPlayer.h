#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

typedef struct {
  char xDigits;
  char yChars;
} Input;

class HumanPlayer : public Player {
 public:
  HumanPlayer();
  virtual ~HumanPlayer();
  bool MakeMove(Board &board, COORDS& coord, TILE_STATE& state);
  int ChooseMark();
  int InputCoordX(COORDS& coord);
  int InputCoordY(COORDS& coord);
 private:
  Board* board;
  Input* input;

};

#endif /* HUMANPLAYER_H_ */
