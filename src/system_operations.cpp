#include "../include/system_operations.hpp"
#include <iostream>
#include <string>
#include <fstream>

    
void handleExecuteGame(Registration& registry){
    std::string game;
    std::cin.ignore();

    std::cout << "\nEscolha o jogo:";
    std::cout << "\n<REVERSI>, <LIG4> ou <VELHA> (Digite os nomes com todas as letras maiusculas, como exibido entre <>.)";
    std::getline(std::cin, game);
    std::cout << "\n";

    if (game != "REVERSI" && game != "LIG4" && game != "VELHA") {
        std::cerr << "ERRO: dados incorretos\n";
        return;
    }

    std::string player1, player2;
    std::cout << "Digite o Apelido do jogador 1: \n";
    std::getline(std::cin, player1);
  
    std::cout << "Digite o Apelido do jogador 2: \n";
    std::getline(std::cin, player2);

    Player* player1Data = registry.findPlayer(player1);
    Player* player2Data = registry.findPlayer(player2);

    if (!player1Data) {
    std::cerr << "ERRO: Jogador 1 (" << player1 << ") não está cadastrado.\n";
    return;
    }

    if (!player2Data) {
    std::cerr << "ERRO: Jogador 2 (" << player2 << ") não está cadastrado.\n";
    return;
    }


    std::pair<std::string, std::string> players = {player1, player2};

    if (game == "REVERSI"){

        Reversi reversi;
        std::string winner, loser;
        winner = reversi.executeGame(players);
        if (winner == "") {
            std::cout << "O jogo terminou em empate! Nenhuma pontuação será atualizada.\n";
            return;
        }
        
        registry.updatePlayerStats(winner, game, true);

        loser = (winner == player1) ? player2 : player1;

        registry.updatePlayerStats(loser, game, false);    
        
    } else if (game == "LIG4"){

        Lig4 lig4;
        std::string winner, loser;
        winner = lig4.executeGame(players);
        if (winner == "") {
            std::cout << "O jogo terminou em empate! Nenhuma pontuação será atualizada.\n";
            return;
        }

        registry.updatePlayerStats(winner, game, true);
        
        loser = (winner == player1) ? player2 : player1;

        registry.updatePlayerStats(loser, game, false);    
        
    } else if (game == "VELHA"){

        TickTackToe ticktacktoe;
        std::string winner, loser;
        winner = ticktacktoe.executeGame(players);
        if (winner == "") {
            std::cout << "O jogo terminou em empate! Nenhuma pontuação será atualizada.\n";
            return;
        }

        registry.updatePlayerStats(winner, game, true);
        
        loser = (winner == player1) ? player2 : player1;

        registry.updatePlayerStats(loser, game, false); 
        
    }

}