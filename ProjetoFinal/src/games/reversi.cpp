#include "../../include/games/games.hpp"
#include "../../include/games/reversi.hpp"
#include <limits>

std::pair<int, int> Reversi::readPlay () {
  int playRow = 0;
  int playColumn = 0;
    
    while (true) {
    // Verifica se a entrada é válida
    if (!(std::cin >> playRow >> playColumn)) {
        // Caso a entrada não seja válida, limpa o erro e o buffer
        std::cin.clear();  // Limpa o estado de erro
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignora o restante da linha
        std::cout << "ERRO: Jogada inválida, insira números inteiros." << std::endl;
        continue;
    }
    break;
    }

  return {playRow-1, playColumn-1};
}

bool Reversi::verifyVerticalUp (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {
    //Verifica se a jogada pode ter uma sequencia para cima
    if (play.first > 1) {
        //Verifica se o char acima é da cor diferente do da jogada
        if (board[play.first - 1][play.second] != playingSymbol) {
            //Se for uma jogada, entra em um loop até encontrar um char da mesma cor da jogada
            for (int i = play.first - 1; i >= 0; i--) {
                if (board[i][play.second] == ' ') {
                    return false;
                } else if (board[i][play.second] == playingSymbol) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Reversi::verifyVerticalDown (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {
    //Verifica se é permitido uma sequencia para baixo
    if (play.first < 6) {
        //Verifica se o char abaixo é da cor diferente do da jogada
        if (board[play.first + 1][play.second] != playingSymbol) {
                //Entra em um loop até encontrar um char da mesma cor da jogada
                for (int i = play.first + 1; i < 8; i++) {
                    if (board[i][play.second] == ' ') {
                        return false;
                    } else if (board[i][play.second] == playingSymbol) {
                        return true;
                    }
                }    
                }
    }
    return false;
}

bool Reversi::verifyHorizontalLeft (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {
    //Verifica se é possível sequência para a esquerda
    if (play.second > 1) {
        //Verifica se o char da esquerda é da cor diferente do da jogada
        if (board[play.first][play.second - 1] != playingSymbol) {
            //Entra em um loop até encontrar um char da mesma cor da jogada
            for (int i = play.second - 1; i >= 0; i--) {
                if (board[play.first][i] == ' ') {
                    return false;
                } else if (board[play.first][i] == playingSymbol) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Reversi::verifyHorizontalRight (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {  
    //Verifica se é possível sequência para a direita
    if (play.second < 6) {
        //Verifica se o char da direita é da cor diferente do da jogada
        if (board[play.first][play.second + 1] != playingSymbol) {
            //Entra em um loop até encontrar um char da mesma cor da jogada
            for (int i = play.second + 1; i < 8; i++) {
                if (board[play.first][i] == ' ') {
                    return false;
                } else if (board[play.first][i] == playingSymbol) {
                    return true;
                }
            } 
        }
    }
    return false;
}

bool Reversi::verifyDiagonalUp (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {
    //Verifica se é possível sequência para a diagonal para cima
    if (play.first > 1 && play.second > 1) {
        //Verifica se o char da diagnonal pra cima é da cor diferente do da jogada
        if (board[play.first - 1][play.second - 1] != playingSymbol) {
            //Entra em um loop até encontrar um char da mesma cor da jogada
            int k = play.first - 1;
            for (int i = play.second-1; i >= 0 && k >= 0; i--) {
                if (board[k][i] == ' ') {
                    return false;
                } else if (board[k][i] == playingSymbol) {
                    return true;;
                }
                k--;
            }
        }
    }
    return false;
}

bool Reversi::verifyDiagonalDown (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {
    //Verifica se é possível sequência para a diagonal para baixo
    if (play.first < 6 && play.second < 6) {
        //Verifica se o char da diagonal para baixo é da cor diferente do da jogada
        if (board[play.first + 1][play.second + 1] != playingSymbol) {
            //Entra em um loop até encontrar um char da mesma cor da jogada
            int k = play.first + 1;
            for (int i = play.second + 1; i < 8; i++) {
                if (board[k][i] == ' ') {
                    return false;
                } else if (board[k][i] == playingSymbol) {
                    return true;
                }
                k++;
            }
        }
        }
    return false;
}