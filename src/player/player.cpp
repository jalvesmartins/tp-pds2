#include "player.hpp"
#include <iostream>
#include <sstream>

Player::Player(std::string nick, std::string nm) 
    : nickname(nick), name(nm) {
    statistics["REVERSI"] = {0, 0};
    statistics["LIG4"] = {0, 0};
    statistics["VELHA"] = {0, 0};
}

Player::Player(std::string nick, std::string nm, std::map<std::string, std::pair<int, int>> stats) 
    : nickname(nick), name(nm), statistics(stats) {}

void Player::updateStatistics(const std::string& game, bool isWin) {
    if (isWin) {
        statistics[game].first++;
    } else {
        statistics[game].second++;
    }
}

std::string Player::toCSV() const {
    std::stringstream ss;
    ss << nickname << "," << name;
    for (const auto& stat : statistics) {
        ss << "," << stat.second.first << "," << stat.second.second;
    }
    return ss.str();
}

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
