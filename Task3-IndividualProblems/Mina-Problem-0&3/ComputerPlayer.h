#ifndef MINA_PROBLEM_0_3_COMPUTERPLAYER_H
#define MINA_PROBLEM_0_3_COMPUTERPLAYER_H

#include "XO_Classes.hpp"

class ComputerPlayer : protected Player{
private:
    pair<int,int> bestMove;
    char board[3][3];
public:
    ComputerPlayer(char **copyBoard);
    ComputerPlayer(char **copyBoard, int order, char symbol);
    int score();
    bool movesLeft();
    int minimax(bool turn);
    pair<int,int> getMove();
    void findBest();
};


#endif
