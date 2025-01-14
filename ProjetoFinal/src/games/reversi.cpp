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

  } else if (!verifyVerticalUp(play, board.getBoard()) &&
            !verifyVerticalDown(play, board.getBoard()) && 
            !verifyHorizontalLeft(play, board.getBoard()) &&
            !verifyHorizontalRight(play, board.getBoard()) &&
            !verifyDiagonalUp(play, board.getBoard()) &&
            !verifyDiagonalDown(play, board.getBoard()) && 
            !verifyDiagonal2Up(play, board.getBoard()) && 
            !verifyDiagonal2Down(play, board.getBoard())) {

    std::cout << "ERRO: jogada inválida" << std::endl;
    return false;

  } else {
    return true;
  }
}

bool Reversi::checkGameOver() {
    //Verifica se ambos os jogadores têm jogadas válidas
    bool player1HasValidMove = false;
    bool player2HasValidMove = false;

    //Itera por todo o tabuleiro para verificar se existem jogadas válidas
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //Verifica se o jogador 1 ('X') tem uma jogada válida
            if (board.getBoard()[i][j] == ' ' && verifyPlay(std::make_pair(i, j))) {
                player1HasValidMove = true;
            }
            //Verifica se o jogador 2 ('O') tem uma jogada válida
            if (board.getBoard()[i][j] == ' ' && verifyPlay(std::make_pair(i, j))) {
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

bool Reversi::verifyVerticalUp (std::pair<int,int> play, std::vector<std::vector<char>>& board) {
    //Verifica se o char acima é da cor diferente do da jogada
    if (play.first>1 &&
        board[play.first - 1][play.second] != board[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.first-1; i>=0; i--) {
            if (board[i][play.second] == ' ') {
                return false;
            } else if (board[i][play.second] == board[play.first][play.second]) {
                return true;
            }
        }
    }
    return false;
}

bool Reversi::verifyVerticalDown (std::pair<int,int> play, std::vector<std::vector<char>>& board) {
    //Verifica se o char abaixo é da cor diferente do da jogada
    if (play.first<6 &&
        board[play.first + 1][play.second] != board[play.first][play.second]) {
         //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.first+1; i<8; i++) {
            if (board[i][play.second] == ' ') {
                return false;
            } else if (board[i][play.second] == board[play.first][play.second]) {
                return true;
            }
        }    
    }
    return false;
}

bool Reversi::verifyHorizontalLeft (std::pair<int,int> play, std::vector<std::vector<char>>& board) {
    //Verifica se o char da esquerda é da cor diferente do da jogada
    if (play.second>1 &&
        board[play.first][play.second - 1] != board[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.second-1; i>=0; i--) {
            if (board[play.first][i] == ' ') {
                return false;
            } else if (board[play.first][i] == board[play.first][play.second]) {
                return true;
            }
            }
    }
    return false;
}

bool Reversi::verifyHorizontalRight (std::pair<int,int> play, std::vector<std::vector<char>>& board) {  
    //Verifica se o char a direita é da cor diferente do da jogada
    if (play.second<6 &&
        board[play.first][play.second + 1] != board[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.second+1; i<8; i++) {
            if (board[play.first][i] == ' ') {
                return false;
            } else if (board[play.first][i] == board[play.first][play.second]) {
                return true;
            }
        }    
    }
    return false;
}

bool Reversi::verifyDiagonalUp (std::pair<int,int> play, std::vector<std::vector<char>>& board) {
    //Verifica se o char da diagnonal pra cima é da cor diferente do da jogada
    if (play.second>1 &&
        board[play.first-1][play.second - 1] != board[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.second-1; i>=0; i--) {
            if (board[i][i] == ' ') {
                return false;
            } else if (board[i][i] == board[play.first][play.second]) {
                return true;;
            }
        }
    }
    return false;
}

bool Reversi::verifyDiagonalDown (std::pair<int,int> play, std::vector<std::vector<char>>& board) {
    //Verifica se o char da diagonal para baixo é da cor diferente do da jogada
    if (play.second<6 &&
        board[play.first + 1][play.second + 1] != board[play.first][play.second]) {
         //Entra em um loop até encontrar um char da mesma cor da jogada
        for (int i = play.second + 1; i < 8; i++) {
            if (board[i][i] == ' ') {
                return false;
            } else if (board[i][i] == board[play.first][play.second]) {
                return true;
            }
        }
    }
    return false;
}

bool Reversi::verifyDiagonal2Up (std::pair<int,int> play, std::vector<std::vector<char>>& board) {
    //Verifica se o char da diagnonal secundária pra cima é da cor diferente do da jogada
    if (play.second<6 &&
        board[play.first -1][play.second + 1] != board[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        int k = play.second + 1;
        for (int i = play.first - 1; i >= 0; i--) {
            if (board[i][k] == ' ') {
                return false;
            } else if (board[i][k] == board[play.first][play.second]) {
                return true;
            }
        }
    }
    return false;
}

bool Reversi::verifyDiagonal2Down (std::pair<int,int> play, std::vector<std::vector<char>>& board) {
    //Verifica se o char da diagonal para baixo é da cor diferente do da jogada
    if (play.second > 1 &&
        board[play.first + 1][play.second - 1] != board[play.first][play.second]) {
        //Entra em um loop até encontrar um char da mesma cor da jogada
        int k = play.second - 1;
        for (int i = play.first + 1; i < 8; i++) {
            if (board[i][k] == ' ') {
                return false;
            } else if (board[i][k] == board[play.first][play.second]) {
                return true;
            }
        }    
    }
    return false;
}