#include <iostream>
#include <string>
#include <fstream>
#include "../include/system_operations.hpp"

void SystemOperations::displayMenu() {
    std::cout << "\n==== Sistema de Jogos de Tabuleiro ====\n";
    std::cout << "1. Cadastrar Jogador\n";
    std::cout << "2. Remover Jogador\n";
    std::cout << "3. Listar Jogadores\n";
    std::cout << "4. Executar Partida\n";
    std::cout << "5. Finalizar Sistema\n";
    std::cout << "=======================================\n";
    std::cout << "\nEscolha uma opcao: ";
}

void SystemOperations::handleRegisterPlayer(Registration& registry) {
    std::string nickname, name;
    bool success = false;
    std::cin.ignore();

    while (!success) {
        try {
            std::cout << "\nDigite o apelido do jogador (ou digite 'sair' para voltar ao menu): ";
            std::getline(std::cin, nickname);

            if (nickname == "sair" || nickname == "Sair" || nickname == "SAIR") {
                std::cout << "\nVoltando ao menu principal...\n";
                return;
            }

            if (nickname.empty()) throw std::invalid_argument("Apelido nao pode ser vazio.");

            std::cout << "\nDigite o nome do jogador: ";
            std::getline(std::cin, name);

            if (name.empty()) throw std::invalid_argument("Nome nao pode ser vazio.");

            success = registry.registerPlayer(nickname, name);
            if (!success) {
                throw std::runtime_error("Nao foi possivel cadastrar o jogador. Tente novamente.");
            }
        } catch (const std::exception& e) {
            std::cerr << "\nERRO: " << e.what() << "\n";
        }
    }

    std::cout << "\nJogador " << nickname << " registrado com sucesso!\n";
}

void SystemOperations::handleRemovePlayer(Registration& registry) {
    std::string nickname;
    bool success = false;
    std::cin.ignore();

    while (!success) {
        try {
            std::cout << "\nDigite o apelido do jogador a ser removido (ou digite 'sair' para voltar ao menu): ";
            std::getline(std::cin, nickname);

            if (nickname == "sair" || nickname == "Sair" || nickname == "SAIR") {
                std::cout << "\nVoltando ao menu principal...\n";
                return;
            }

            if (nickname.empty()) throw std::invalid_argument("Apelido nao pode ser vazio.");

            success = registry.removePlayer(nickname);
            if (!success) {
                throw std::runtime_error("Jogador nao encontrado. Tente novamente.");
            }
        } catch (const std::exception& e) {
            std::cerr << "\nERRO: " << e.what() << "\n";
        }
    }
    std::cout << "\nJogador removido com sucesso.\n";
}

void SystemOperations::handleListPlayers(Registration& registry) {
    std::string criterion;
    std::cin.ignore();
    while (true) {
        try {
            std::cout << "\nEscolha o criterio de ordenacao: 'A' (Apelido), 'N' (Nome) ou digite 'sair' para voltar ao menu: ";
            std::getline(std::cin, criterion);

            if (criterion == "sair" || criterion == "Sair" || criterion == "SAIR") {
                std::cout << "\nVoltando ao menu principal...\n";
                return;
            }

            if (criterion != "A" && criterion != "a" && criterion != "N" && criterion != "n") {
                throw std::invalid_argument("Criterio invalido. Use 'A' ou 'N'.");
            }

            registry.listPlayers(criterion);
            break;
        } catch (const std::exception& e) {
            std::cerr << "\nERRO: " << e.what() << "\n";
        }
    }
}

void SystemOperations::handleExecuteGame(Registration& registry){
    std::string game;
    std::cin.ignore();

    std::cout << "\nEscolha o jogo:";
    std::cout << "\n<REVERSI>, <LIG4> ou <VELHA> (Digite os nomes com todas as letras maiusculas, como exibido entre <>.): ";
    std::getline(std::cin, game);
    std::cout << "\n";

    if (game != "REVERSI" && game != "LIG4" && game != "VELHA") {
        std::cerr << "ERRO: Dados incorretos, use lestras maiusculas.\n";
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
    std::cerr << "ERRO: Jogador 1 (" << player1 << ") nao esta cadastrado.\n";
    return;
    }

    if (!player2Data) {
    std::cerr << "ERRO: Jogador 2 (" << player2 << ") nao esta cadastrado.\n";
    return;
    }


    std::pair<std::string, std::string> players = {player1, player2};

    if (game == "REVERSI"){

        Reversi reversi;
        std::string winner, loser;
        winner = reversi.executeGame(players);
        if (winner == "") {
            std::cout << "O jogo terminou em empate! Nenhuma pontuacao sera atualizada.\n";
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
            std::cout << "O jogo terminou em empate! Nenhuma pontuacao sera atualizada.\n";
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
            std::cout << "O jogo terminou em empate! Nenhuma pontuacao sera atualizada.\n";
            return;
        }

        registry.updatePlayerStats(winner, game, true);
        
        loser = (winner == player1) ? player2 : player1;

        registry.updatePlayerStats(loser, game, false); 
        
    }

}