//
// Created by over- on 09/11/2022.
//

#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(char **copyBoard, int order, char symbol): Player(order, symbol) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = copyBoard[i][j];
        }
    }
}

int ComputerPlayer::score(){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-'){
            return (board[i][0] == symbol ? 10 : -10);
        }
    }
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-'){
            return (board[0][i] == symbol ? 10 : -10);
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != '-'){
        return (board[0][0] == symbol ? 10 : -10);
    }
    if(board[0][2] == board[1][1] && board[2][0] == board[0][2] && board[1][1] != '-'){
        return (board[0][0] == symbol ? 10 : -10);
    }
    return 0;
}

bool ComputerPlayer::movesLeft(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '-'){
                return 1;
            }
        }
    }
    return 0;
}

int ComputerPlayer::minimax(bool turn){
    int currState = score();
    if(currState) return currState;
    if(!movesLeft()) return 0;
    int bestMove;
    if(turn){
        bestMove = -10000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '-'){
                    board[i][j] = 'x';
                    bestMove = max(bestMove, minimax(!turn));
                    board[i][j] = '-';
                }
            }
        }
    }
    if(turn){
        bestMove = 10000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '-'){
                    board[i][j] = 'x';
                    bestMove = min(bestMove, minimax(!turn));
                    board[i][j] = '-';
                }
            }
        }
    }
    return bestMove;
}

void ComputerPlayer::findBest(){
    int best = -11;
    pair<int, int> bestCell;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '-'){
                int ret = minimax(1);
                if(ret > best){
                    best = ret;
                    bestMove = {i, j};
                }
            }
        }
    }
}

pair<int,int> ComputerPlayer::getMove(){ return bestMove; }