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
    ~Player();

    void setNickname(std::string nick) { this->nickname = nick; }
    void setName(std::string nm) { this->name = nm; }

    std::string getNickname() const { return this->nickname; }
    std::string getName() const { return this->name; }
    std::map<std::string, std::pair<int, int>> getStatistics() const { return this->statistics; }

    std::string toCSV() const;
    static Player fromCSV(const std::string& line);

    void updateStatistics(const std::string& game, bool isWin);
    void printStatistics() const;
};

#endif