#include "../ProjetoFinal/include/games/lig4.hpp"
#include <iostream>


    std::pair<int, int> Lig4::readPlay (){
        int playRow, playColumn = 0;
        std::cin >> playColumn;
        return {5, playColumn};
    }

    std::pair<int, int> Lig4::verifyPlayColumn(std::pair<int, int> play){
        while (play.first >= 0 && board.getBoard()[play.first][play.second] != ' '){
            play.first--;
        }
        return play;
    }

    bool Lig4::verifyPlay (std::pair<int, int> play){   
        play = verifyPlayColumn(play);
        if(play.first >= board.getRows() || play.second >= board.getColumns() || play.second < 0 || play.first < 0){
            std::cout << "ERRO: formato incorreto";
            return false;
        } else if(board.getBoard()[play.first][play.second] != ' ') {
            std::cout << "ERRO: jogada inválida";
            return false;
        } else {
            return true;
        }
    }

    bool Lig4::verifyWin (std::pair<int,int> play) {
        
        //Verificação Horizontal

        //Para esquerda
        int horizontal_sequence = 1;
        int column = play.second - 1;
        while (column >= 0 && board.getBoard()[play.first][column] == board.getBoard()[play.first][play.second]) {
            horizontal_sequence++;
            column--;
        }

        //Para direita
        column = play.second + 1;
        while (column <= 6 && board.getBoard()[play.first][column] == board.getBoard()[play.first][play.second]){
            horizontal_sequence++;
            column++;
        }

        //Verificação Vertical

        //Para baixo
        int vertical_sequence = 1;
        int row = play.first + 1;
        while(row <= 5 && board.getBoard()[row][play.second] == board.getBoard()[play.first][play.second]){
            vertical_sequence++;
            row++;
        }

        //Para cima 
        row = play.first - 1;
        while (row >= 0 && board.getBoard()[row][play.second] == board.getBoard()[play.first][play.second]){
            vertical_sequence++;
            row--;
        }


        //Verificação Diagonal

        //Diagonal Crescente
        int diagonal1_sequence = 1;

        //Acima da peça
        row = play.first - 1;
        column = play.second + 1;
        while (row >= 0 && column <= 6 && board.getBoard()[row][column] == board.getBoard()[play.first][play.second]){
            row--;
            column++;
            diagonal1_sequence++;
        }

        //Abaixo da peça
        row = play.first + 1;
        column = play.second - 1;
        while (row <= 5 && column >= 0 && board.getBoard()[row][column] == board.getBoard()[play.first][play.second]){
            row++;
            column--;
            diagonal1_sequence++;
        }

        //Diagonal Decrescente
        int diagonal2_sequence = 1;

        //Acima da peça
        row = play.first - 1;
        column = play.second - 1;
        while(row >= 0 && column >= 0 && board.getBoard()[row][column] == board.getBoard()[play.first][play.second]){
            row--;
            column--;
            diagonal2_sequence++;
        }

        //Abaixo da peça
        row = play.first + 1;
        column = play.second + 1;
        while(row <= 5 && column <= 6 && board.getBoard()[row][column] == board.getBoard()[play.first][play.second]){
            row++;
            column++;
            diagonal2_sequence++;
        }

        if(horizontal_sequence >= 4) return true; 
        else if(vertical_sequence >= 4) return true;  
        else if(diagonal1_sequence >= 4) return true;
        else if(diagonal2_sequence >= 4) return true; 
        else return false;   
    }

    void Lig4::switchSymbol (char& symbol) {
    symbol = (symbol == 'X') ? 'O' : 'X';
    }

    void Lig4::switchPlayer (std::string& playing, std::pair<std::string,std::string> players) {
    playing = (playing == players.first) ? players.second : players.first;
    }

    std::string Lig4::executeGame (std::pair<std::string,std::string> players){
        int playCount = 0;
        bool win = false;

        std::cout << "Símbolo do" << players.first << ": X" << std::endl;
        std::cout << "Símbolo do" << players.second << ": O" << std::endl << std::endl;

        std::string player = players.first;
        char playingSymbol = 'X';

        std::cout << "Iniciando partida:" << std::endl << std::endl;
        board.printBoard();

        while (!win) {
            if (playCount > 41) {
            std::cout << "Jogo terminou empatado! Tente outra vez." << std::endl << std::endl;
            return "";
            }

            std::cout << "Turno de jogador " << player << " (Coluna)" << std::endl << std::endl;
            std::pair coordinates = readPlay();
            bool playPossibility = verifyPlay(coordinates);

            if (!playPossibility) {
            continue;
            }

            board.makePlay(coordinates, playingSymbol);

            if (playCount > 6 && verifyWin(coordinates)) {
            win = true;
            board.printBoard();
            std::cout << "Parabéns " << player << ", você venceu! Execute outra partida." << std::endl << std::endl;
            return player;

            } else {
            board.printBoard();
            switchSymbol(playingSymbol);
            switchPlayer(player, players);
            }
            
            playCount ++;
        }
        return "";
    }


