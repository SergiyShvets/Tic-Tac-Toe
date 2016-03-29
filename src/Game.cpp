#include "Game.h"

#include <iostream>
#include <cstdlib>

Game::Game() {
  human = new HumanPlayer();
  computer = new ComputerPlayer();
  board = new Board();

}

Game::~Game() {

  delete computer;
  delete human;
  delete board;

}

void Game::Run(){

  COORDS coord;
  TILE_STATE state;
  state = EMPTY;

  Player* activePlayer;
  activePlayer = human;
  int mark;
  int cross = 1;
  int naught = 2;
  if(human->ChooseMark() == 1)
    mark = cross;
  else
    mark = naught;

  board->Print();

  while(!board->GameOver()){

   activePlayer = human;
   if(mark == cross)
   state = CROSS;
   else
     state = NAUGHT;
    while(!activePlayer->MakeMove(*board, coord, state))
      activePlayer = human;

    board->Print();
    if(board->GameOver())
      break;

    activePlayer = computer;
    if(mark == cross)
       state = NAUGHT;
       else
         state = CROSS;

    while(!activePlayer->MakeMove(*board, coord, state))
         activePlayer = computer;

    board->Print();

  }
  std::cout << "Game Over" << std::endl;

  TryAgain();
}

void Game::TryAgain(){
  COORDS coord;
  std::cout << "Try again?[y/n]" << std::endl;
  char option;
  while(true){
  std::cin >> option;
  if(option == 'y' || option == 'Y'){
    board->Refresh(coord);
    Run();
  }
  else if (option == 'n' || option == 'N'){
    std::cout << "Bye" << std::endl;
    exit(1);
  }
  else continue;
}
}
