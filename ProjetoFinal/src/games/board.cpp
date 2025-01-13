#include "../../include/games/board.hpp"

#include <iostream>

int Board::getRows () {
    return this->rows;
}

int Board::getColumns () {
    return this->columns;
}

void Board::makePlay (std::pair<int,int> play, char symbol) {
  board[play.first][play.second] = symbol;
}

void Board::printBoard () {
  std::cout << std::endl;
  for (int i=0; i< rows; i++) {
    for (int j=0; j< columns; j++) {
      if(j == 0) {
        std::cout << "|";
      }
      std::cout << " " << board[i][j] << " |";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

std::vector<std::vector<char>>& Board::getBoard () {
    return this->board;
}