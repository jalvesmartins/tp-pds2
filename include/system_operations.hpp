#ifndef SYSTEMOPERATIONS_HPP
#define SYSTEMOPERATIONS_HPP

#include "headers.hpp"

class SystemOperations{
    
public:
    void displayMenu();
    void handleRegisterPlayer(Registration& registry);
    void handleRemovePlayer(Registration& registry);
    void handleListPlayers(Registration& registry);
    void handleExecuteGame(Registration& registry);
};

#endif