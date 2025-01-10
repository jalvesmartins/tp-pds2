#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

#include <iostream>

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {}
//  Reversu (int rows, int columns) {}

    virtual void printGame () override = 0;
    virtual std::pair<int, int> readPlay () override = 0;
    virtual void verifyPlay () override = 0;
    virtual void verifyWin () override = 0;
};