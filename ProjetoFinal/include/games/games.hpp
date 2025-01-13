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

      virtual ~Games() {
        for (int i = 0; i < board.getRows(); ++i) {
            delete[] board[i];
        }

        delete[] board.getBoard ();
      }

      virtual std::pair<int, int> readPlay () = 0;
      virtual bool verifyPlay (std::pair<int, int> play) = 0;
      virtual void makePlay (std::pair<int,int> play, char symbol) = 0;
      virtual bool verifyWin(std::pair<int,int> play) = 0;
      virtual void printGame () = 0;
};