#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

#include <iostream>

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {}
//  Reversu (int rows, int columns) {}

    virtual std::pair<int, int> readPlay () override = 0;
    virtual bool verifyPlay (std::pair<int, int> play) override = 0;
    virtual void verifyWin () override = 0;
    virtual void makePlay () override = 0;
    virtual void printGame () override = 0;
};