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