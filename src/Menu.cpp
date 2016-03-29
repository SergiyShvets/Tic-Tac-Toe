#include "Menu.h"

#include <iostream>
#include <cstdlib>

Menu::Menu() {
  game = new Game();
}

Menu::~Menu() {
  delete game;
}

void Menu::MainMenu(){

  std::cout << "[1] Start Game" << std::endl;
  std::cout << "[2] Exit Game" << std::endl;

  int option;
  while(true){
    std::cin >> option;

    if(option == 1)
      game->Run();
    else if (option == 2)
      exit(1);
    else
      continue;
  }
}

