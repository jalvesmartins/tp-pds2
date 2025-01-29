#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include "player.hpp"
#include <string>
#include <vector>

class Registration {
private:
    std::string file;
    std::vector<Player> players; // Vetor de jogadores em memória

public:
    // Construtor e destrutor
    Registration(const std::string& filename);
    ~Registration();

    // Getters e setters
    std::string getFileName() const;
    void setFileName(const std::string& filename);

    // Funções principais
    Player* findPlayer(const std::string& nickname);
    void loadPlayers();
    void savePlayers();
    bool registerPlayer(const std::string& nickname, const std::string& name);
    bool removePlayer(const std::string& nickname);
    void listPlayers(const std::string& criterion);
    bool updatePlayerStats(const std::string& nickname, const std::string& game, bool isWin);
};

#endif // REGISTRATION_HPP
