#include "player.hpp"
#include <iostream>
#include <sstream>

// Construtor que inicializa o jogador com apelido, nome e estatísticas padrão
Player::Player(std::string nick, std::string nm) 
    : nickname(nick), name(nm) {
    statistics["REVERSI"] = {0, 0};
    statistics["LIG4"] = {0, 0};
    statistics["VELHA"] = {0, 0};
}

// Construtor que permite inicializar o jogador com estatísticas passadas
Player::Player(std::string nick, std::string nm, std::map<std::string, std::pair<int, int>> stats) 
    : nickname(nick), name(nm), statistics(stats) {}

Player::~Player() {}

void Player::updateStatistics(const std::string& game, bool isWin) {
    if (isWin) {
        statistics[game].first++;
    } else {
        statistics[game].second++;
    }
}

// Converte as informações do jogador para formato CSV
std::string Player::toCSV() const {
    std::stringstream ss;
    ss << nickname << "," << name;

    // Ordem explícita para garantir que os jogos aparecem na ordem correta
    std::vector<std::string> games = {"REVERSI", "LIG4", "VELHA"};

    for (const auto& game : games) {
        const auto& stat = statistics.at(game);
        ss << "," << stat.first << "," << stat.second;
    }

    return ss.str();
}

// Converte uma linha CSV para um objeto Player
Player Player::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string nick, nm;
    std::map<std::string, std::pair<int, int>> stats;
    int win, loss;

    std::getline(ss, nick, ',');
    std::getline(ss, nm, ',');

    ss >> win >> loss;
    stats["REVERSI"] = {win, loss};
    ss.ignore();

    ss >> win >> loss;
    stats["LIG4"] = {win, loss};
    ss.ignore();

    ss >> win >> loss;
    stats["VELHA"] = {win, loss};

    return Player(nick, nm, stats);
}

void Player::printStatistics() const {
    std::cout << nickname << " " << name << std::endl;
    for (const auto& stat : statistics) {
        std::cout << stat.first << " - V: " << stat.second.first << " D: " << stat.second.second << std::endl;
    }
}
