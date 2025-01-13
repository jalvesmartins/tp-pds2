#pragma once

#include "./games.hpp"
#include <vector>
#include <iostream>

class TickTackToe : public Games {
  public:
    TickTackToe () : Games(3,3) {}
//  TickTackToe (int rows, int columns) {}

    std::pair<int, int> readPlay () override;
    bool verifyPlay (std::pair<int, int> play) override;
    bool verifyWin (std::pair<int,int> play) override;
    void executeGame () override;
};
