#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

class TickTackToe : public Games {
  public:
    TickTackToe () : Games(3,3) {}
//  TickTackToe (int rows, int columns) {}

    virtual void printGame () override;
    virtual void readPlay () override;
    virtual void verifyWin () override;
};
