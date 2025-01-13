#pragma once

#include <iostream>
#include <vector>
#include "./board.hpp"

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
      virtual void executeGame () = 0;
};