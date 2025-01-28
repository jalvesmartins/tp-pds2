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
    void switchSymbol (char& symbol) override;
    void switchPlayer (std::string& playing, std::pair<std::string,std::string> players) override;
    std::string executeGame (std::pair<std::string,std::string> players) override;
};