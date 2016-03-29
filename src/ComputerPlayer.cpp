#include "ComputerPlayer.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

ComputerPlayer::ComputerPlayer(): Player() {
  board = new Board();

  srand(static_cast<unsigned int>(time(NULL)));
}

ComputerPlayer::~ComputerPlayer() {
  delete board;
}

bool ComputerPlayer::MakeMove(Board &board, COORDS& coord, TILE_STATE& state){

  std::cout << "Computer move" << std:: endl;

  coord.x = InputCoordX(coord);
  coord.y = InputCoordY(coord);
  return board.Place(coord, state) != BAD;

}

int ComputerPlayer::InputCoordX(COORDS& coord){

  coord.x = rand()%BOARD_DIM;
  return coord.x;
}
int ComputerPlayer::InputCoordY(COORDS& coord){


  coord.y = rand()%BOARD_DIM;
  return coord.y;
}
