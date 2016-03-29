#include "HumanPlayer.h"

#include <iostream>

HumanPlayer::HumanPlayer()
    : Player() {
  board = new Board();
  input = new Input();

}

HumanPlayer::~HumanPlayer() {
  delete board;
  delete input;
}

bool HumanPlayer::MakeMove(Board &board, COORDS& coord, TILE_STATE& state) {

  std::cout << "Human Move" << std::endl;
  coord.x = InputCoordX(coord);
  coord.y = InputCoordY(coord);
  return board.Place(coord, state) != BAD;
}

int HumanPlayer::InputCoordX(COORDS& coord) {

  coord.x = input->xDigits;

  while (true) {
    std::cout << "Enter coords" << std::endl;
    std::cin >> input->xDigits;

    switch (input->xDigits) {
      case '1':
        return 0;
      case '2':
        return 1;
      case '3':
        return 2;
      default:
        std::cout << "Wrong coord X" << std::endl;
        continue;
    }
  }
  return coord.x;
}

int HumanPlayer::InputCoordY(COORDS& coord) {

  coord.y = input->yChars;

  while (true) {

    std::cin >> input->yChars;
    switch (input->yChars) {
      case 'A':
      case 'a':
        return 0;
      case 'B':
      case 'b':
        return 1;
      case 'C':
      case 'c':
        return 2;
      default:
        std::cout << "Wrong coord Y" << std::endl;
        continue;
    }
  }
  return coord.y;
}

int HumanPlayer::ChooseMark(){

  std::cout << "Choose [1] - X or [2] - O" << std::endl;
  int mark;

  std::cin >> mark;
  if(mark == 1)
    return 1;
  else return 2;

}
