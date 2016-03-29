#ifndef MENU_H_
#define MENU_H_

#include "Game.h"

class Menu {
 public:
  Menu();
  virtual ~Menu();
  void MainMenu();
 private:
  Game* game;
};

#endif
