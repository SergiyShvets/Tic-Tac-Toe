#ifndef BOARD_H_
#define BOARD_H_



#include <vector>

const int BOARD_DIM = 3;

typedef struct {
  unsigned int x;
  unsigned int y;
} COORDS;

typedef enum {
  EMPTY, CROSS, NAUGHT
} TILE_STATE;

typedef enum{
  OK, BAD
} PLACE_RESULT;

typedef struct {
  //Tile(COORDS coord_, TILE_STATE state_);
  COORDS coord;
  TILE_STATE state;

} Tile;

class Board {
 public:
  Board();
  virtual ~Board();
  PLACE_RESULT Place(COORDS coord, TILE_STATE state);
  bool CheckTile(COORDS& coord);
  bool GameOver();
  bool IsWinnerX();
  bool IsWinnerO();
  void Refresh(COORDS& coord);
  void Print();
 private:
  //Tile* tile_;
  std::vector<std::vector<Tile> > board_;

};

#endif /* BOARD_H_ */
