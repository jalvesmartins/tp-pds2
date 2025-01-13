#include "../../include/games/games.hpp"
#include "../../include/games/reversi.hpp"

std::pair<int, int> Reversi::readPlay () {
  int playRow = 0;
  int playColumn = 0;
    
  std::cin >> playRow >> playColumn;

  return {playRow-1, playColumn-1};
}

bool Reversi::verifyPlay (std::pair<int,int> play) {
  if (play.first > 7 || play.second > 7 || play.first < 0 || play.second < 0) {
    std::cout << "ERRO: formato incorreto" << std::endl;
    return false;

  } else if (board.getBoard()[play.first][play.second] != ' ') {
    std::cout << "ERRO: jogada inválida" << std::endl;
    return false;

  } else if (board.getBoard()[play.first][play.second] != ' ') {
    std::cout << "ERRO: jogada inválida" << std::endl;
    return false;

  } else {
    return true;
  }
}

bool Reversi::verifyVertical (std::pair<int,int> play, Board &board) {
    //Verifica se o char acima é da cor diferente do da jogada
    if (play.first>1 &&
        board.getBoard()[play.first - 1][play.second] != board.getBoard()[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.first-2; i>=0; i--) {
            if (board.getBoard()[i][play.second] == ' ') {
                break;
            } else if (board.getBoard()[i][play.second] == board.getBoard()[play.first][play.second]) {
                return true;
            }
        }

    //Verifica se o char acima é da cor diferente do da jogada
    } else if (play.first<6 &&
                board.getBoard()[play.first + 1][play.second] != board.getBoard()[play.first][play.second]) {
         //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.first+2; i<8; i++) {
            if (board.getBoard()[i][play.second] == ' ') {
                break;
            } else if (board.getBoard()[i][play.second] == board.getBoard()[play.first][play.second]) {
                return true;
            }
        }    
    } else {
        return false;
    }
}

bool Reversi::verifyHorizontal (std::pair<int,int> play, Board &board) {
    int verifier = 0;
    //Verifica se o char da esquerda é da cor diferente do da jogada
    if (play.second>1 &&
        board.getBoard()[play.first][play.second - 1] != board.getBoard()[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.second-2; i>=0; i--) {
            if (board.getBoard()[play.first][i] == ' ') {
                break;
            } else if (board.getBoard()[play.first][i] == board.getBoard()[play.first][play.second]) {
                //Faz a jogada após verificar que é valida
                for (int j = i; j<play.second; j++) {
                    board.makePlay({play.first,j}, board.getBoard()[play.first][play.second]);
                }
                verifier++;
            }
            }

    //Verifica se o char a direita é da cor diferente do da jogada
    } else if (play.second<6 &&
                 board.getBoard()[play.first][play.second + 1] != board.getBoard()[play.first][play.second]) {
         //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.second+2; i<8; i++) {
            if (board.getBoard()[play.first][i] == ' ') {
                break;
            } else if (board.getBoard()[play.first][i] == board.getBoard()[play.first][play.second]) {
                //Faz a jogada após verificar que é valida
                for (int j = i; j>play.second; j--) {
                    board.makePlay({play.first,j}, board.getBoard()[play.first][play.second]);
                }
                return true;
            }
        }    
    } else {
        if (verifier > 0) {
            return true;
        }
        return false;
    }
}