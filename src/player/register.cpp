#include "register.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

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
        std::cerr << "ERROR: Unable to open file\n";
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

bool Registration::registerPlayer(const std::string& nickname, const std::string& name) {
    if (!findPlayerLine(nickname).empty()) {
        std::cerr << "ERROR: Player already exists\n";
        return false;
    }

    std::ofstream outFile(file, std::ios::app); // Abre para adicionar no final do arquivo
    if (outFile.is_open()) {
        Player player(nickname, name);
        outFile << player.toCSV() << "\n";
        outFile.close();
        std::cout << "Player " << nickname << " registered successfully\n";
        return true;
    } else {
        std::cerr << "ERROR: Unable to open file\n";
        return false;
    }
}
bool Registration::removePlayer(const std::string& nickname) {
    if (findPlayerLine(nickname).empty()) {
        std::cerr << "ERROR: Player not found\n";
        return false;
    }

    rewriteFileExcludingPlayer(nickname);
    std::cout << "Player " << nickname << " removed successfully\n";
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
        std::cerr << "ERROR: Unable to open file(s)\n";
    }
}

void Registration::listPlayers(char criterion) {
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        std::cerr << "ERROR: Unable to open file\n";
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
            std::cout << "Player " << nickname << "'s stats updated successfully\n";
            return true;
        } else {
            std::cerr << "ERROR: Player not found\n";
            return false;
        }
    }

    std::cerr << "ERROR: Unable to open file(s)\n";
    return false;
}



