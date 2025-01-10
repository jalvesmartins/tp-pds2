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