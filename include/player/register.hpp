#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include <string>
#include "player.hpp"

class Registration {
private:
    std::string file;

    void rewriteFileExcludingPlayer(const std::string& nickname);

    // Metodo auxiliar para gerar nomes de arquivos temporarios
    std::string generateTempFileName() const;

public:
    // Construtor e destrutor
    Registration(const std::string& filename = "players.csv");
    ~Registration();

    // Getters e setters
    std::string getFileName() const;
    void setFileName(const std::string& filename);


    std::string findPlayerLine(const std::string& nickname);
    bool registerPlayer(std::string& nickname, std::string& name);
    bool removePlayer(std::string& nickname);
    void listPlayers(char criterion);
    bool updatePlayerStats(const std::string& nickname, const std::string& game, bool isWin);
};

#endif
