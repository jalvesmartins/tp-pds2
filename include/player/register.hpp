#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include <string>
#include "Player.hpp"

class Registration {
private:
    const std::string file = "registration.csv";

    // Auxiliary methods
    std::string findPlayerLine(const std::string& nickname);
    void rewriteFileExcludingPlayer(const std::string& nickname);

public:
    Registration();
    ~Registration();

    bool registerPlayer(const std::string& nickname, const std::string& name);
    bool removePlayer(const std::string& nickname);
    void listPlayers(char criterion);
    bool updatePlayerStats(const std::string& nickname, const std::string& game, bool isWin);
};

#endif
