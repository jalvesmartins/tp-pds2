#include "../include/doctest.h"
#include "../include/games/ticktacktoe.hpp"

TickTackToe game;

TEST_CASE ("Teste Jogo da Velha - verifyPlay") {

    SUBCASE("Teste verifyPlay") {
        CHECK(game.verifyPlay({1,2}) == true);
        CHECK(game.verifyPlay({0,0}) == true);
        CHECK(game.verifyPlay({-1,2}) == false);
        CHECK(game.verifyPlay({4,2}) == false);
        CHECK(game.verifyPlay({10000000000,2}) == false);
        CHECK(game.verifyPlay({-11111111,-1111111111}) == false);
    }
}