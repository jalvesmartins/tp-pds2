#pragma once

#include "./games.hpp"

#include <iostream>

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {}
//  Reversu (int rows, int columns) {}

    std::pair<int, int> readPlay () override;
    bool verifyPlay (std::pair<int, int> play) override;
    bool verifyWin (std::pair<int,int> play) override;
    void makePlay (std::pair<int,int> play, char symbol) override;
    void printGame () override;
};