#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>

class Player {

private:
    std::string nickname;
    std::string name;
    std::map<std::string, std::pair<int, int>> statistics;

public:
    Player(std::string nick, std::string nm);
    Player(std::string nick, std::string nm, std::map<std::string, std::pair<int, int>> stats);

    std::string getNickname() { return this->nickname; }
    std::string getName() { return this->name; }
    std::map<std::string, std::pair<int, int>> getStatistics() const { return this->statistics; }

    std::string toCSV() const;
    static Player fromCSV(const std::string& line);

    void updateStatistics(const std::string& game, bool isWin);
    void printStatistics() const;
};

#endif