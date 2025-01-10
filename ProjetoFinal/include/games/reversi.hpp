#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {}
//  Reversu (int rows, int columns) {}

    virtual void printGame () override = 0;
    virtual void readPlay () override = 0;
    virtual void verifyWin () override = 0;
};