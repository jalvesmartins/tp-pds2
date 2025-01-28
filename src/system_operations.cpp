#include <iostream>
#include <string>
#include <fstream>

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
