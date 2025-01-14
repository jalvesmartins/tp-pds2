#pragma once

#include "./games.hpp"

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {}
//  Reversu (int rows, int columns) {}

    std::pair<int, int> readPlay () override;
    bool verifyPlay (std::pair<int, int> play) override;
    bool verifyVerticalUp (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyVerticalDown (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyHorizontalLeft (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyHorizontalRight (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyDiagonalUp (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyDiagonalDown (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyDiagonal2Up (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyDiagonal2Down (std::pair<int, int> play, std::vector<std::vector<char>>& board);
    bool verifyWin (std::pair<int,int> play) override;
    bool Reversi::checkGameOver ();
    void switchSymbol (char& symbol) override;
    void switchPlayer (std::string& playing, std::pair<std::string,std::string> players) override;
    std::string executeGame (std::pair<std::string,std::string> players) override;
};