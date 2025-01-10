#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

#include <iostream>

class TickTackToe : public Games {
  public:
    TickTackToe () : Games(3,3) {}
//  TickTackToe (int rows, int columns) {}

    virtual void printGame () override;
    virtual std::pair<int, int> readPlay () override;
    virtual void verifyPlay () override = 0;
    virtual void verifyWin () override;
};
