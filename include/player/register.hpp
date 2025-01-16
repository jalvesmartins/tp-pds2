#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include <string>
#include "player.hpp"

class Registration {
private:
    const std::string file = "registration.csv";

    // Metodo auxiliar
    void rewriteFileExcludingPlayer(const std::string& nickname);

public:
    Registration();
    ~Registration();

    std::string findPlayerLine(const std::string& nickname);
    bool registerPlayer(std::string& nickname, std::string& name);
    bool removePlayer(std::string& nickname);
    void listPlayers(char criterion);
    bool updatePlayerStats(const std::string& nickname, const std::string& game, bool isWin);
};

#endif
