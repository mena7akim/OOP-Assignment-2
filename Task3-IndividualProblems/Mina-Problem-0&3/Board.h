//
// Created by over- on 10/11/2022.
//

#ifndef MAIN_CPP_BOARD_H
#define MAIN_CPP_BOARD_H

#include "Player.h"


class Board {
protected:
    char board[3][3] = {{'-','-','-'}, {'-','-','-'}, {'-','-','-'}};
    int  n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    Board() {}
    bool update_board (int x, int y, char symbol);
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    bool is_winner();
    // Return true if 9 moves are done and no winner
    bool is_draw();
    void copyBoard(char other[][3]){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                other[i][j] = board[i][j];
            }
        }
    }
    // Display the board and the pieces on it
    void display_board();
};


#endif //MAIN_CPP_BOARD_H
