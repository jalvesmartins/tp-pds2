#include "../ProjetoFinal/include/games/lig4.hpp"
#include <iostream>


    std::pair<int, int> Lig4::readPlay (){
        int playRow, playColumn = 0;
        std::cin >> playColumn;
        return {5, playColumn};
    }

    std::pair<int, int> Lig4::verifyPlayColumn(std::pair<int, int> play){
        while (play.first >= 0 && board[play.first][play.second] != '\0'){
            play.first--;
        }
        return play;
    }

    bool Lig4::verifyPlay (std::pair<int, int> play){   
        play = verifyPlayColumn(play);
        if(play.first >= rows || play.second >= columns || play.second < 0 || play.first < 0){
            std::cout << "ERRO: formato incorreto";
            return false;
        } else if(board[play.first][play.second] != '\0') {
            std::cout << "ERRO: jogada inválida";
            return false;
        } else {
            return true;
        }
    }


    void Lig4::makePlay (std::pair<int,int> play, char symbol){
        if (verifyPlay(play)){
            board[play.first][play.second] = symbol;
        }
    }

    bool Lig4::verifyWin (std::pair<int,int> play) {
        
        //Verificação Horizontal

        //Para esquerda
        int horizontal_sequence = 1;
        int column = play.second - 1;
        while (column >= 0 && board[play.first][column] == board[play.first][play.second]) {
            horizontal_sequence++;
            column--;
        }

        //Para direita
        column = play.second + 1;
        while (column <= 6 && board[play.first][column] == board[play.first][play.second]){
            horizontal_sequence++;
            column++;
        }

        //Verificação Vertical

        //Para baixo
        int vertical_sequence = 1;
        int row = play.first + 1;
        while(row <= 5 && board[row][play.second] == board[play.first][play.second]){
            vertical_sequence++;
            row++;
        }

        //Para cima 
        row = play.first - 1;
        while (row >= 0 && board[row][play.second] == board[play.first][play.second]){
            vertical_sequence++;
            row--;
        }


        //Verificação Diagonal

        //Diagonal Crescente
        int diagonal1_sequence = 1;

        //Acima da peça
        row = play.first - 1;
        column = play.second + 1;
        while (row >= 0 && column <= 6 && board[row][column] == board[play.first][play.second]){
            row--;
            column++;
            diagonal1_sequence++;
        }

        //Abaixo da peça
        row = play.first + 1;
        column = play.second - 1;
        while (row <= 5 && column >= 0 && board[row][column] == board[play.first][play.second]){
            row++;
            column--;
            diagonal1_sequence++;
        }

        //Diagonal Decrescente
        int diagonal2_sequence = 1;

        //Acima da peça
        row = play.first - 1;
        column = play.second - 1;
        while(row >= 0 && column >= 0 && board[row][column] == board[play.first][play.second]){
            row--;
            column--;
            diagonal2_sequence++;
        }

        //Abaixo da peça
        row = play.first + 1;
        column = play.second + 1;
        while(row <= 5 && column <= 6 && board[row][column] == board[play.first][play.second]){
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

    void Lig4::printGame (){
        
    }

