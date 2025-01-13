#pragma once

#include <iostream>
#include <vector>

class Board {
    private:
      std::vector<std::vector<char>> board;
      int rows;
      int columns;
    
    public:
      Board () {
        std::cout << "ERRO: Tamanho inválido de tabuleiro" << std::endl;
      }

      Board (int rows, int columns) : rows(rows), columns(columns) {
        board.resize(rows, std::vector<char>(columns, ' '));
      }

      virtual ~Board() {}

      int getRows ();
      int getColumns ();
      std::vector<std::vector<char>>& getBoard ();
      void makePlay (std::pair<int,int> play, char symbol);
      void printBoard ();
};