#include "Board.h"

#include <string>
#include <iostream>

Board::Board() {

  board_.resize(BOARD_DIM);
  for (int x = 0; x < BOARD_DIM; x++) {
    board_[x].resize(BOARD_DIM);
    for (int y = 0; y < BOARD_DIM; y++) {
      board_[x][y].state = EMPTY;
    }
  }
}

Board::~Board() {

}

PLACE_RESULT Board::Place(COORDS coord, TILE_STATE state) {

  int x0 = coord.x;
  int y0 = coord.y;

  if (CheckTile(coord))
  {

    if (state == NAUGHT){
      board_[x0][y0].state = NAUGHT;
      return OK;
    }
    else if (state == CROSS){
      board_[x0][y0].state = CROSS;
      return OK;

    } else if (board_[x0][y0].state == CROSS && board_[x0][y0].state == NAUGHT) {
      std::cout << "Bad Move" << std::endl;
      return BAD;
    }
  }
  return BAD;
}

bool Board::CheckTile(COORDS& coord) {
  if (board_[coord.x][coord.y].state == NAUGHT
      || board_[coord.x][coord.y].state == CROSS)
    return false;
  return true;
}

//improve this src
bool Board::IsWinnerX(){

  if(board_[0][0].state == CROSS && board_[0][1].state == CROSS && board_[0][2].state == CROSS)
  {
    return true;
  }
  else if(board_[1][0].state == CROSS && board_[1][1].state == CROSS && board_[1][2].state == CROSS)
  {
    return true;
  }
  else if(board_[2][0].state == CROSS && board_[2][1].state == CROSS && board_[2][2].state == CROSS)
  {
    return true;
  }
  else if(board_[0][0].state == CROSS && board_[1][0].state == CROSS && board_[2][0].state == CROSS)
  {
    return true;
  }
  else if(board_[0][1].state == CROSS && board_[1][1].state == CROSS && board_[2][1].state == CROSS)
  {
    return true;
  }
  else if(board_[0][2].state == CROSS && board_[1][2].state == CROSS && board_[2][2].state == CROSS)
  {
    return true;
  }
  else if(board_[0][0].state == CROSS && board_[1][1].state == CROSS && board_[2][2].state == CROSS)
  {
    return true;
  }
  else if(board_[0][2].state == CROSS && board_[1][1].state == CROSS && board_[2][0].state == CROSS)
  {
    return true;
  }
  return false;
}

bool Board::IsWinnerO(){

  if(board_[0][0].state == NAUGHT && board_[0][1].state == NAUGHT && board_[0][2].state == NAUGHT)
  {
    return true;
  }
  else if(board_[1][0].state == NAUGHT && board_[1][1].state == NAUGHT && board_[1][2].state == NAUGHT)
  {
    return true;
  }
  else if(board_[2][0].state == NAUGHT && board_[2][1].state == NAUGHT && board_[2][2].state == NAUGHT)
  {
    return true;
  }
  else if(board_[0][0].state == NAUGHT && board_[1][0].state == NAUGHT && board_[2][0].state == NAUGHT)
  {
    return true;
  }
  else if(board_[0][1].state == NAUGHT && board_[1][1].state == NAUGHT && board_[2][1].state == NAUGHT)
  {
    return true;
  }
  else if(board_[0][2].state == NAUGHT && board_[1][2].state == NAUGHT && board_[2][2].state == NAUGHT)
  {
    return true;
  }
  else if(board_[0][0].state == NAUGHT && board_[1][1].state == NAUGHT && board_[2][2].state == NAUGHT)
  {
    return true;
  }
  else if(board_[0][2].state == NAUGHT && board_[1][1].state == NAUGHT && board_[2][0].state == NAUGHT)
  {
    return true;
  }
  return false;
}

bool Board::GameOver() {

  if(IsWinnerX() || IsWinnerO()){
    std::cout << "Winner" << std::endl;
    return true;
  }
  for (int x = 0; x < BOARD_DIM; x++) {
    for (int y = 0; y < BOARD_DIM; y++) {
      if (board_[x][y].state == EMPTY)
        return false;
    }
  }
  return true;
}

void Board::Refresh(COORDS& coord) {

  for (coord.x = 0; coord.x < BOARD_DIM; coord.x++) {
    for (coord.y = 0; coord.y < BOARD_DIM; coord.y++) {
      board_[coord.x][coord.y].state = EMPTY;
    }
  }
}


void Board::Print() {

  char mark;
  char empty = ' ';
  char cross = 'X';
  char naught = 'O';
  char error = 'F';
  std::cout << "    A   B   C  " << std::endl;
  std::cout << "  -------------" << std::endl;
  for (int x = 0; x < BOARD_DIM; x++) {
    std::cout << x+1 << " | ";
    for (int y = 0; y < BOARD_DIM; y++) {
      switch (board_[x][y].state) {
        case EMPTY:
          mark = empty;
          break;
        case CROSS:
          mark = cross;
          break;
        case NAUGHT:
          mark = naught;
          break;
        default:
          mark = error;
          break;
      }
      std::cout << mark << " | ";
    }
    std::cout << x << std::endl;
    std::cout << "  -------------" << std::endl;
  }
  std::cout << "    A   B   C  " << std::endl << std::endl;
}
