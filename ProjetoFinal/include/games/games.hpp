#pragma once

#include <iostream>

class Games {
    protected:
      char** board;
      int columns;
      int rows;
    
    public:
      Games () : Games(0,0) {}

      Games (int rows, int columns) : rows(rows), columns(columns) {
        board = new char*[rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new char[columns]();
        }
      }

      virtual ~Games() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }

        delete[] board;
      }

      virtual std::pair<int, int> readPlay () = 0;
      virtual bool verifyPlay (std::pair<int, int> play) = 0;
      virtual void makePlay () = 0;
      virtual void verifyWin() = 0;
      virtual void printGame () = 0;
};