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

bool Reversi::verifyDiagonal2Up (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {
    //Verifica se é possível sequência para a diagonal secundária para cima
    if (play.first > 1 && play.second < 6) {
        //Verifica se o char da diagnonal secundária pra cima é da cor diferente do da jogada
        if (board[play.first - 1][play.second + 1] != playingSymbol) {
            //Entra em um loop até encontrar um char da mesma cor da jogada
            int k = play.first - 1;
            for (int i = play.second + 1; i < 8 && k >= 0; i++) {
                if (board[k][i] == ' ') {
                    return false;
                } else if (board[k][i] == playingSymbol) {
                    return true;
                }
                k--;
            }
        }
    }
    return false;
}

bool Reversi::verifyDiagonal2Down (std::pair<int,int> play, std::vector<std::vector<char>>& board, char& playingSymbol) {
    //Verifica se é possível sequência para a diagonal secundária para cima
    if (play.first < 6 && play.second < 6) {
        //Verifica se o char da diagonal para baixo é da cor diferente do da jogada
        if (board[play.first + 1][play.second - 1] != playingSymbol) {
            //Entra em um loop até encontrar um char da mesma cor da jogada
            int k = play.first + 1;
            for (int i = play.second - 1; i >= 0 && k < 8; i--) {
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

bool Reversi::verifyPlayAdapted (std::pair<int,int> play, char& playingSymbol) {
    //Verifica se ta dentro do tabuleiro
  if (play.first > 7 || play.second > 7 || play.first < 0 || play.second < 0) {
    std::cout << "ERRO: formato incorreto" << std::endl;
    return false;

    //Verifica se tem alguma casa lá
  } else if (board.getBoard()[play.first][play.second] != ' ') {
    std::cout << "ERRO: jogada inválida, essa casa já possui uma peça" << std::endl;
    return false;

    //Verifica se a jogada é válida para alguma direção
  } else if (!verifyVerticalUp(play, board.getBoard(), playingSymbol) &&
            !verifyVerticalDown(play, board.getBoard(), playingSymbol) && 
            !verifyHorizontalLeft(play, board.getBoard(), playingSymbol) &&
            !verifyHorizontalRight(play, board.getBoard(), playingSymbol) &&
            !verifyDiagonalUp(play, board.getBoard(), playingSymbol) &&
            !verifyDiagonalDown(play, board.getBoard(), playingSymbol) && 
            !verifyDiagonal2Up(play, board.getBoard(), playingSymbol) && 
            !verifyDiagonal2Down(play, board.getBoard(), playingSymbol)) {

    std::cout << "ERRO: jogada inválida, não é posível formar uma sequência válida" << std::endl;
    return false;

  } else {
    return true;
  }
}

bool Reversi::verifyPlayWithoutPrint (std::pair<int,int> play, char& playingSymbol) {
    
    //Mesma coisa da de cima, mas sem printar os erros (Feita para a verificação do fim do jogo)
    if (    !verifyVerticalUp(play, board.getBoard(), playingSymbol) &&
            !verifyVerticalDown(play, board.getBoard(), playingSymbol) && 
            !verifyHorizontalLeft(play, board.getBoard(), playingSymbol) &&
            !verifyHorizontalRight(play, board.getBoard(), playingSymbol) &&
            !verifyDiagonalUp(play, board.getBoard(), playingSymbol) &&
            !verifyDiagonalDown(play, board.getBoard(), playingSymbol) && 
            !verifyDiagonal2Up(play, board.getBoard(), playingSymbol) && 
            !verifyDiagonal2Down(play, board.getBoard(), playingSymbol)) {

    return false;
  } else {
    return true;
  }
}

bool Reversi::checkGameOver() {
    bool player1HasValidMove = false;
    bool player2HasValidMove = false;
    char x = 'X';
    char o = 'O';
    //Itera por todo o tabuleiro para verificar se existem jogadas válidas
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //Verifica se o jogador 1 ('X') tem uma jogada válida
            if (board.getBoard()[i][j] == ' ' && verifyPlayWithoutPrint(std::make_pair(i, j), x)) {
                player1HasValidMove = true;
            }
            //Verifica se o jogador 2 ('O') tem uma jogada válida
            if (board.getBoard()[i][j] == ' ' && verifyPlayWithoutPrint(std::make_pair(i, j), o)) {
                player2HasValidMove = true;
            }
            //Se ambos os jogadores tiverem jogadas válidas, o jogo ainda não terminou
            if (player1HasValidMove && player2HasValidMove) {
                return false;// O jogo não terminou
            }
        }
    }
    //Se não houver jogadas válidas para ambos os jogadores, o jogo terminou
    return true; // O jogo terminou
}

char Reversi::verifyWinSpecial () {
    int xCount = 0;
    int oCount = 0;
    char winner = ' ';

    //Faz a contagem de todas as peças
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //Verifica se o char na posição é igual a 'X'
            if (board.getBoard()[i][j] == 'X') {
                xCount++;;
            }
            //Verifica se o char na posição é igual a 'O'
            if (board.getBoard()[i][j] == 'O') {
                oCount++;;
            }
        }
    }
    if (oCount == xCount) {
        return winner; // Retorna o símbolo vencedor
    } else {
    winner = (xCount > oCount) ? winner = 'X' : winner = 'O';
    }

return winner; // Retorna o símbolo vencedor
}