#pragma once

#include "./board.hpp"
#include <string>

class Games {
    protected:
      Board board;
    
    public:
      Games () : board() {}

      Games (int rows, int columns) : board(rows, columns) {}

      virtual ~Games() {}

      virtual std::pair<int, int> readPlay () = 0;
      virtual bool verifyPlay (std::pair<int, int> play) = 0;
      virtual bool verifyWin (std::pair<int,int> play) = 0;
      virtual void switchSymbol (char& symbol) = 0;
      virtual void switchPlayer (std::string& playing, std::pair<std::string,std::string> players) = 0;
      virtual std::string executeGame (std::pair<std::string,std::string> players) = 0;
};