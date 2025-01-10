#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

#include <iostream>

class TickTackToe : public Games {
  public:
    TickTackToe () : Games(3,3) {}
//  TickTackToe (int rows, int columns) {}

    virtual std::pair<int, int> readPlay () override;
    virtual bool verifyPlay (std::pair<int, int> play) override;
    virtual bool verifyWin (std::pair<int,int> play) override;
    virtual void makePlay (std::pair<int,int> play, char symbol) override;
    virtual void printGame () override;
};
