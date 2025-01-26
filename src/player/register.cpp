#include "register.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>
#include <ctime>

// Construtor (garante que o arquivo existe)
Registration::Registration(const std::string& filename) : file(filename) {
    std::ofstream outFile(file, std::ios::app);
    outFile.close();
}

Registration::~Registration() {}

// Getters e setters
std::string Registration::getFileName() const {
    return file;
}

void Registration::setFileName(const std::string& filename) {
    file = filename;
}

// Método auxiliar para gerar nomes temporários para arquivos
std::string Registration::generateTempFileName() const {
    return "temp_" + std::to_string(std::time(nullptr)) + ".csv";
}

void Registration::rewriteFileExcludingPlayer(const std::string& nickname) {
    std::ifstream inFile(file);
    std::string tempFile= generateTempFileName();
    std::ofstream outFile(tempFile);

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

        if (std::remove(file.c_str()) != 0) {
                std::cerr << "ERRO: Não foi possível remover o arquivo original.\n";
        } else if (std::rename(tempFile.c_str(), file.c_str()) != 0) {
                std::cerr << "ERRO: Não foi possível renomear o arquivo temporário.\n";
            }
    } else {
        std::cerr << "ERRO: Não é possível abrir o(s) arquivo(s).\n";
    }
}

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

bool Registration::registerPlayer( const std::string& nickname, std::string& name) {
   std::regex validNicknamePattern("^[\\w]+$");

    if (!std::regex_match(nickname, validNicknamePattern)) {
        std::cerr << "ERRO: Apelido inválido. Caracteres permitidos: letras, números e underscore (_).\n";
        return false;
    }

    if (!findPlayerLine(nickname).empty()) {
        std::cerr << "ERRO: Apelido já existe.\n";
        return false;
    }

    std::ofstream outFile(file, std::ios::app); // Abre para adicionar no final do arquivo
    if (outFile.is_open()) {
        Player player(nickname, name);
        outFile << player.toCSV() << "\n";
        outFile.close();
        return true;
    } else {
        std::cerr << "ERRO: Não é possível abrir o arquivo\n";
        return false;
    }
}

bool Registration::removePlayer(const std::string& nickname) {
    if (findPlayerLine(nickname).empty())
        return false;

    rewriteFileExcludingPlayer(nickname);
    return true;
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
    std::string tempFile = generateTempFileName();
    std::ofstream outFile(tempFile);

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

       if (std::remove(file.c_str()) != 0) {
            std::cerr << "ERRO: Não foi possível remover o arquivo original.\n";
        } else if (std::rename(tempFile.c_str(), file.c_str()) != 0) {
            std::cerr << "ERRO: Não foi possível renomear o arquivo temporário.\n";
        }

        if (updated) {
            std::cout << "Estatísticas do jogador " << nickname << " foram atualizadas com sucesso!\n";
            return true;
        } else {
            std::cerr << "ERRO: Jogador não encontrado.\n";
            return false;
        }
    }

    std::cerr << "ERRO: Não é possível abrir o(s) arquivo(s).\n";
    return false;
    }
