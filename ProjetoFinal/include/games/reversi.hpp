#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

#include <iostream>

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {}
//  Reversu (int rows, int columns) {}

    virtual std::pair<int, int> readPlay () override;
    virtual bool verifyPlay (std::pair<int, int> play) override;
    virtual bool verifyWin (std::pair<int,int> play) override;
    virtual void makePlay (std::pair<int,int> play, char symbol) override;
    virtual void printGame () override;
};