#include "register.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

// Construtor (garante que o arquivo existe)
Registration::Registration() {
    std::ofstream outFile(file, std::ios::app);
    outFile.close();
}

Registration::~Registration() {}

//Metodo para encontrar um jogador no arquivo
std::string Registration::findPlayerLine(const std::string& nickname) {
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        std::cerr << "ERRO: Não é possível abrir o arquivo\n";
        return "";
    }

    std::string line;
    while (std::getline(inFile, line)) {
        Player player = Player::fromCSV(line);
        if (player.getNickname() == nickname) {
            inFile.close();
            return line; // Retorna a linha do jogador encontrado
        }
    }

    inFile.close();
    return ""; // Jogador não encontrado
}

bool Registration::registerPlayer( std::string& nickname, std::string& name) {
    std::regex validNicknamePattern("^[\\w]+$");
    // Loop para garantir que o apelido seja válido e único
    while (true) {
        std::cout << "Digite o apelido: ";
        std::cin >> nickname;

        // Verifica se o apelido é válido
        if (!std::regex_match(nickname, validNicknamePattern)) {
            std::cerr << "ERRO: Apelido inválido, espaço não permitido. Caracteres permitidos: letras maiusculas e minusculas(sem acentuação), numeros e underscore(_).\n";
            continue; // Volta para pedir o apelido novamente
        }

        // Verifica se o apelido já existe
        if (!findPlayerLine(nickname).empty()) {
            std::cerr << "ERRO: Apelido já existe. Tente novamente.\n";
            continue; // Volta para pedir o apelido novamente
        }

        // Se passou pelas verificações, apelido válido e único, sai do loop
        break;
    }

    std::cout << "Digite seu nome: ";
    std::getline(std::cin, name);

    std::ofstream outFile(file, std::ios::app); // Abre para adicionar no final do arquivo
    if (outFile.is_open()) {
        Player player(nickname, name);
        outFile << player.toCSV() << "\n";
        outFile.close();
        std::cout << "Jogador " << nickname << " registrado com sucesso!\n";
        return true;
    } else {
        std::cerr << "ERRO: Não é possível abrir o arquivo\n";
        return false;
    }
}
bool Registration::removePlayer(std::string& nickname) {
    std::cout << "Digite o apelido do jogador a ser excluido: \n";
    while (findPlayerLine(nickname).empty()) {
        std::cerr << "ERRO: Jogador não encontrado. Tente novamente.\n";
        std::cin >> nickname;
    }

    rewriteFileExcludingPlayer(nickname);
    std::cout << "Jogador " << nickname << " removido com sucesso!\n";
    return true;
}

void Registration::rewriteFileExcludingPlayer(const std::string& nickname) {
    std::ifstream inFile(file);
    std::ofstream outFile("temp.csv");

    if (inFile.is_open() && outFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            Player player = Player::fromCSV(line);
            if (player.getNickname() != nickname) {
                outFile << line << "\n";
            }
        }

        inFile.close();
        outFile.close();

        std::remove(file.c_str());
        std::rename("temp.csv", file.c_str());
    } else {
        std::cerr << "ERRO: Não é possível abrir o(s) arquivo(s)\n";
    }
}

void Registration::listPlayers(char criterion) {
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        std::cerr << "ERRO: Não é possível abrir o arquivo.\n";
        return;
    }

    std::vector<Player> players;
    std::string line;

    while (std::getline(inFile, line)) {
        players.push_back(Player::fromCSV(line));
    }

    inFile.close();

    if (criterion == 'A') {
        std::sort(players.begin(), players.end(),
                  [](const Player& a, const Player& b) { return a.getName() < b.getName(); });
    } else {
        std::sort(players.begin(), players.end(),
                  [](const Player& a, const Player& b) { return a.getNickname() < b.getNickname(); });
    }

    for (const auto& player : players) {
        player.printStatistics();
    }
}

bool Registration::updatePlayerStats(const std::string& nickname, const std::string& game, bool isWin) {
    bool updated = false;
    std::ifstream inFile(file);
    std::ofstream outFile("temp.csv");

    if (inFile.is_open() && outFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            Player player = Player::fromCSV(line);
            if (player.getNickname() == nickname) {
                player.updateStatistics(game, isWin);
                updated = true;
            }
            outFile << player.toCSV() << "\n";
        }

        inFile.close();
        outFile.close();

        std::remove(file.c_str());
        std::rename("temp.csv", file.c_str());

        if (updated) {
            std::cout << "Estatísticas do jogador " << nickname << " foram atualizadas com sucesso!\n";
            return true;
        } else {
            std::cerr << "ERRO: Jogador não encontrado\n";
            return false;
        }
    }

    std::cerr << "ERRO: Não é possível abrir o(s) arquivo(s)\n";
    return false;
}



