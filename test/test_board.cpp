#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/games/board.hpp"
#include "../include/doctest.h"

TEST_CASE("Testando o construtor"){
    Board board(5, 5);
    CHECK(board.getRows() == 5);
    CHECK(board.getColumns() == 5);
    CHECK(board.getBoard().size() == 5);
}

TEST_CASE ("Testando o getRows e getColumns") {
    Board board(5, 5);
    CHECK(board.getRows() == 5);
    CHECK(board.getColumns() == 5);
}

TEST_CASE ("Testando makePlay") {
    Board board(5, 5);
    board.makePlay({0,0}, 'X');
    CHECK(board.getBoard()[0][0] == 'X');
    board.makePlay({4,2}, 'O');
    CHECK(board.getBoard()[4][2] == 'O');
}