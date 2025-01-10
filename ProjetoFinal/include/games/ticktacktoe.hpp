#pragma once

#include "./games.hpp"

#include <iostream>

class TickTackToe : public Games {
  public:
    TickTackToe () : Games(3,3) {}
//  TickTackToe (int rows, int columns) {}

    std::pair<int, int> readPlay () override;
    bool verifyPlay (std::pair<int, int> play) override;
    bool verifyWin (std::pair<int,int> play) override;
    void makePlay (std::pair<int,int> play, char symbol) override;
    void printGame () override;
};
