#pragma once

#include "./games.hpp"

class Lig4 : public Games {
  public:
    Lig4 () : Games(6,7) {}
//  Lig4 (int rows, int columns) {}

    virtual std::pair<int, int> readPlay () override;
    virtual bool verifyPlay (std::pair<int, int> play) override;
    std::pair<int, int> verifyPlayColumn(std::pair<int, int> play);
    virtual bool verifyWin (std::pair<int,int> play) override;
    virtual void makePlay (std::pair<int,int> play, char symbol) override;
    virtual void printGame () override;
};