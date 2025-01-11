#pragma once

#include <iostream>

class Board {
    private:
      char** board;
      int rows;
      int columns;
    
    public:
      Board () : Board(0,0) {}

      Board (int rows, int columns) : rows(rows), columns(columns) {
        board = new char*[rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new char[columns]();
        }
      }

      virtual ~Board() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }
        delete[] board;
      }

      int getRows ();
      int getColumns ();
      void makePlay (std::pair<int,int> play, char symbol);
      void printBoard ();
};