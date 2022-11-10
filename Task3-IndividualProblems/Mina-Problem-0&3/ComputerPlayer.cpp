#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(char symbol) : Player(symbol) {

}

ComputerPlayer::ComputerPlayer(int order, char symbol): Player(order, symbol) { }

ComputerPlayer::ComputerPlayer(Board &other) {
    other.copyBoard(gameBoard);
}

void ComputerPlayer::getBoard(Board &other){
    other.copyBoard(gameBoard);
}

int ComputerPlayer::score(){
    for(int i = 0; i < 3; i++){
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != '-'){
            return (toupper(symbol) == gameBoard[i][0] ? 10 : -10);
        }
    }
    for(int i = 0; i < 3; i++){
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != '-'){
            return (toupper(symbol) == gameBoard[0][i] ? 10 : -10);
        }
    }
    if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] && gameBoard[1][1] != '-'){
        return (toupper(symbol) == gameBoard[0][0] ? 10 : -10);
    }
    if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[2][0] == gameBoard[0][2] && gameBoard[1][1] != '-'){
        return (toupper(symbol) == gameBoard[0][2] ? 10 : -10);
    }
    return 0;
}

bool ComputerPlayer::movesLeft(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(gameBoard[i][j] == '-'){
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
    int ret;
    if(turn){
        ret = -10000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(gameBoard[i][j] == '-'){
                    gameBoard[i][j] = toupper(symbol);
                    ret = max(ret, minimax(!turn));
                    gameBoard[i][j] = '-';
                }
            }
        }
    }
    else{
        ret = 10000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(gameBoard[i][j] == '-'){
                    gameBoard[i][j] = (toupper(symbol) == 'O' ? 'X' : 'O');
                    ret = min(ret, minimax(!turn));
                    gameBoard[i][j] = '-';
                }
            }
        }
    }
    return ret;
}

void ComputerPlayer::findBest(){
    int best = -10000;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(gameBoard[i][j] == '-'){
                gameBoard[i][j] = toupper(symbol);
                int ret = minimax(0);
                gameBoard[i][j] = '-';
                if(ret > best){
                    best = ret;
                    bestMove = {i, j};
                }
            }
        }
    }
}

pair<int,int> ComputerPlayer::getMove(){ return bestMove; }

char ComputerPlayer::get_symbol(){
    return toupper(symbol);
}

string ComputerPlayer::to_string(){
    return "Player: Computer\n";
}