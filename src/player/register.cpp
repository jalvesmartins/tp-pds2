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
    if (!outFile.is_open()) {
        std::cerr << "Erro ao criar ou abrir o arquivo: " << file << std::endl;
    }
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

//Metodo para encontrar um jogador no arquivo
Player* Registration::findPlayer(const std::string& nickname) {
    for (auto& player : players) {
        if (player.getNickname() == nickname) {
            return &player; // Retorna um ponteiro para o jogador encontrado
        }
    }
    return nullptr; // Retorna nullptr se o jogador não for encontrado
}

bool Registration::registerPlayer(const std::string& nickname, const std::string& name) {
    std::regex validNicknamePattern("^[\\w]+$");

    if (!std::regex_match(nickname, validNicknamePattern)) {
        std::cerr << "Apelido invalido. Caracteres permitidos: letras, numeros e underscore (_).\n";
        return false;
    }

    for (const auto& player : players) {
        if (player.getNickname() == nickname) {
            std::cerr << "Apelido ja existe.\n";
            return false;
        }
    }

    // Cria um novo jogador e adiciona ao vetor
    Player newPlayer(nickname, name);
    players.push_back(newPlayer);

    // Salva no arquivo
    savePlayers();
    return true;
}

//Remove um jogador
bool Registration::removePlayer(const std::string& nickname) {
    // Localiza o jogador pelo apelido
    auto it = std::find_if(players.begin(), players.end(),
                           [&nickname](const Player& player) {
                               return player.getNickname() == nickname;
                           });

    if (it != players.end()) {
        // Remove o jogador do vetor
        players.erase(it);

        // Salva as alterações no arquivo
        savePlayers();
        return true;
    }

    // Retorna falso se o jogador não foi encontrado
    std::cerr << "ERRO: Jogador com apelido '" << nickname << "' não encontrado.\n";
    return false;
}
// Lista os jogadores ordenados por um critério
void Registration::listPlayers(const std::string& criterion) {
    void loadPlayers();
    
    if (criterion == "N" || criterion == "n") {
        std::sort(players.begin(), players.end(),
                  [](const Player& a, const Player& b) { return a.getName() < b.getName(); });
    } else if (criterion == "A" || criterion == "a") {
        std::sort(players.begin(), players.end(),
                  [](const Player& a, const Player& b) { return a.getNickname() < b.getNickname(); });
    } else {
        std::cerr << "Criterio de listagem nao existente: " << criterion << std::endl;
        return;
    }

    for (const auto& player : players) {
        player.printStatistics();
    }
}

bool Registration::updatePlayerStats(const std::string& nickname, const std::string& game, bool isWin) {
    bool updated = false;

    for (auto& player : players) {
        if (player.getNickname() == nickname) {
            player.updateStatistics(game, isWin);
            updated = true;
            break;
        }
    }

    if (!updated) {
        std::cerr << "\nERRO: Jogador nao encontrado: " << nickname << "\n";
        return false;
    }

    // Salva as alterações no arquivo
    savePlayers();
    return true;
}

// Carrega os jogadores do arquivo para o vetor
void Registration::loadPlayers() {
    players.clear();

    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::ios_base::failure("Erro ao abrir o arquivo para leitura: " + file);
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            players.push_back(Player::fromCSV(line));
        }
    }

    inFile.close();
}

// Reescreve todo o arquivo com os dados atualizados
void Registration::savePlayers() {
    std::ofstream outFile(file, std::ios::out | std::ios::trunc);

    if (!outFile) {
        std::cerr << "Erro ao abrir o arquivo para escrita: " << file << std::endl;
        return;
    }

    for (const auto& player : players) {
        outFile << player.toCSV() << "\n";
    }

    outFile.close();
}