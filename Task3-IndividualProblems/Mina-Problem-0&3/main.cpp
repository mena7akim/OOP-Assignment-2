#include <bits/stdc++.h>
using namespace std;

char board[3][3];
char computer = 'x', player = 'o';

int score(){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-'){
            return (board[i][0] == computer ? 10 : -10);
        }
    }
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-'){
            return (board[0][i] == computer ? 10 : -10);
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != '-'){
        return (board[0][0] == computer ? 10 : -10);
    }
    if(board[0][2] == board[1][1] && board[2][0] == board[0][2] && board[1][1] != '-'){
        return (board[0][0] == computer ? 10 : -10);
    }
    return 0;
}

bool movesLeft(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '-'){
                return 1;
            }
        }
    }
    return 0;
}

int minimax(bool turn){
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

pair<int,int> findBest(){
    int best = -11;
    pair<int, int> bestCell;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '-'){
                int ret = minimax(1);
                if(ret > best){
                    best = ret;
                    bestCell = {i, j};
                }
            }
        }
    }
    return bestCell;
}



int main() {

}
