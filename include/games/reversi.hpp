#pragma once

#include "./games.hpp"

class Reversi : public Games {
  public:
    Reversi () : Games(8,8) {
      board.getBoard()[3][3] = 'O';
      board.getBoard()[3][4] = 'X';
      board.getBoard()[4][3] = 'X';
      board.getBoard()[4][4] = 'O';
    }

    std::pair<int, int> readPlay () override;
    bool verifyPlayAdapted (std::pair<int, int> play, char& playingSymbol);
    bool verifyPlayWithoutPrint (std::pair<int, int> play, char& playingSymbol);
    char verifyWinSpecial ();
    void makePlay (std::pair<int,int>coordinates, char& playingSymbol);
    bool checkGameOver ();
    void switchSymbol (char& playingSymbol) override;
    void switchPlayer (std::string& playing, std::pair<std::string,std::string> players) override;
    std::string executeGame (std::pair<std::string,std::string> players) override;

    //Funções de verificação interna do jogo
    bool verifyVerticalUp (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);
    bool verifyVerticalDown (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);
    bool verifyHorizontalLeft (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);
    bool verifyHorizontalRight (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);
    bool verifyDiagonalUp (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);
    bool verifyDiagonalDown (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);
    bool verifyDiagonal2Up (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);
    bool verifyDiagonal2Down (std::pair<int, int> play, std::vector<std::vector<char>>& board, char& playingSymbol);

    //Funções que não foram usadas e não tem implementação.
    bool verifyPlay ([[maybe_unused]]std::pair<int, int> play) override;
    bool verifyWin ([[maybe_unused]]std::pair<int,int> play) override;
};