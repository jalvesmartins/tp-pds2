#include "../../include/games/games.hpp"
#include "../../include/games/ticktacktoe.hpp"

#include <iostream>

std::pair<int, int> TickTackToe::readPlay () {
  int playRow = 0;
  int playColumn = 0;
    
  std::cin >> playRow >> playColumn;

  return std::make_pair(playRow-1, playColumn-1);
}

bool TickTackToe::verifyPlay (std::pair<int,int> play) {
  if (play.first > 2 || play.second > 2 || play.first < 0 || play.second < 0) {
    std::cout << "ERRO: formato incorreto" << std::endl;
    return false;

  } else if (board[play.first][play.second] != '\0') {
    std::cout << "ERRO: jogada inválida" << std::endl;
    return false;

  } else {
    return true;
  }
}

void TickTackToe::makePlay (std::pair<int,int> play, char symbol) {
  board[play.first][play.second] = symbol;
}

bool TickTackToe::verifyWin (std::pair<int,int> play) {
  if (board[play.first][0] == board[play.first][1] && board[play.first][1] == board[play.first][2]) {
    return true;

  } else if (board[0][play.second] == board[1][play.second] && board[1][play.second] == board[2][play.second]) {
    return true;

  } else if (play.first == play.second && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return true;

  } else if ((play.first + play.second == 2) && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return true;

  } else {
    return false;
  }
}

void TickTackToe::printGame () {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
        if(j == 0) {
          std::cout << "|";
        }

        std::cout << " " << (board[i][j] == '\0' ? ' ' : board[i][j]) << " |";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}