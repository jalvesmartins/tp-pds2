#include "../../include/games/games.hpp"
#include "../../include/games/ticktacktoe.hpp"

#include <iostream>
#include <vector>


std::pair<int, int> TickTackToe::readPlay () {
  int playRow = 0;
  int playColumn = 0;
    
  std::cin >> playRow >> playColumn;

  return {playRow-1, playColumn-1};
}

bool TickTackToe::verifyPlay (std::pair<int,int> play) {
  if (play.first > 2 || play.second > 2 || play.first < 0 || play.second < 0) {
    std::cout << "ERRO: formato incorreto" << std::endl;
    return false;

  } else if (board.getBoard()[play.first][play.second] != ' ') {
    std::cout << "ERRO: jogada inválida" << std::endl;
    return false;

  } else {
    return true;
  }
}

bool TickTackToe::verifyWin (std::pair<int,int> play) {
  if (board.getBoard()[play.first][0] == board.getBoard()[play.first][1] && board.getBoard()[play.first][1] == board.getBoard()[play.first][2]) {
    return true;

  } else if (board.getBoard()[0][play.second] == board.getBoard()[1][play.second] && board.getBoard()[1][play.second] == board.getBoard()[2][play.second]) {
    return true;

  } else if (play.first == play.second && board.getBoard()[0][0] == board.getBoard()[1][1] && board.getBoard()[1][1] == board.getBoard()[2][2]) {
    return true;

  } else if ((play.first + play.second == 2) && board.getBoard()[0][2] == board.getBoard()[1][1] && board.getBoard()[1][1] == board.getBoard()[2][0]) {
    return true;

  } else {
    return false;
  }
}

void TickTackToe::switchSymbol (char& symbol) {
  symbol = (symbol == 'X') ? 'O' : 'X';
}

void TickTackToe::switchPlayer (std::string& playing, std::pair<std::string,std::string> players) {
  playing = (playing == players.first) ? players.second : players.first;
}

std::string TickTackToe::executeGame (std::pair<std::string,std::string> players) {
  int playCount = 0;
  bool win = false;

  std::cout << "Símbolo do" << players.first << ": X" << std::endl;
  std::cout << "Símbolo do" << players.second << ": O" << std::endl << std::endl;

  std::string player = players.first;
  char playingSymbol = 'X';

  std::cout << "Iniciando partida:" << std::endl << std::endl;
  board.printBoard();

  while (!win) {
    if (playCount > 8) {
      std::cout << "Jogo terminou empatado! Tente outra vez." << std::endl << std::endl;
      return "";
    }

    std::cout << "Turno de jogador " << player << " (Linha Coluna)" << std::endl << std::endl;
    std::pair coordinates = readPlay();
    bool playPossibility = verifyPlay(coordinates);

    if (!playPossibility) {
      continue;
    }

    board.makePlay(coordinates, playingSymbol);

    if (playCount > 4 && verifyWin(coordinates)) {
      win = true;
      board.printBoard();
      std::cout << "Parabéns " << player << ", você venceu! Execute outra partida." << std::endl << std::endl;
      return player;

    } else {
      board.printBoard();
      switchSymbol(playingSymbol);
      switchPlayer(player, players);
    }

    playCount ++;
  }
  return "";
}
