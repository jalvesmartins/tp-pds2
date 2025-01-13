#pragma once

#include "./games.hpp"

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {}
//  Reversu (int rows, int columns) {}

    std::pair<int, int> readPlay () override;
    bool verifyPlay (std::pair<int, int> play) override;
    bool verifyWin (std::pair<int,int> play) override;
    void switchSymbol (char& symbol) override;
    void switchPlayer (std::string& playing, std::pair<std::string,std::string> players) override;
    std::string executeGame (std::pair<std::string,std::string> players) override;
};