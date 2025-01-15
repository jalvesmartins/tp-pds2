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