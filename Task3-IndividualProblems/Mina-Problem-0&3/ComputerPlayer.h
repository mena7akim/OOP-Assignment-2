//
// Created by over- on 10/11/2022.
//

#ifndef MAIN_CPP_COMPUTERPLAYER_H
#define MAIN_CPP_COMPUTERPLAYER_H

#include "Board.h"


class ComputerPlayer : protected Player {
private:
    pair<int, int> bestMove;
    char gameBoard[3][3];
public:
    ComputerPlayer(char symbol);

    ComputerPlayer(int order, char symbol);

    ComputerPlayer(Board &other);

    bool movesLeft();

    int minimax(bool turn);

    pair<int, int> getMove();

    void findBest();

    void getBoard(Board &other);

    char get_symbol();

    string to_string();

    int score();
};


#endif //MAIN_CPP_COMPUTERPLAYER_H
