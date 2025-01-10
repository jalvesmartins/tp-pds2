#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

class Lig4 : public Games {
  public:
    Lig4 () : Games(6,7) {}
//  Lig4 (int rows, int columns) {}

    virtual std::pair<int, int> readPlay () override;
    virtual bool verifyPlay (std::pair<int, int> play) override = 0;
    virtual bool verifyWin (std::pair<int,int> play) override = 0;
    virtual void makePlay (std::pair<int,int> play, char symbol) override;
    virtual void printGame () override = 0;
};