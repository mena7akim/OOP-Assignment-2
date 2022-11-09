// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"XO_Classes.hpp"
#include "ComputerPlayer.h"
using namespace std;

void GameManager::run() {
    Board x_o;
    int x, y;
    Player players = Player (1, 'x');
    ComputerPlayer computer = ComputerPlayer(x_o.getboard(), 2, 'o');
    x_o.display_board();
    while (true) {
        for (int i:{0,1}) {
            if(i){
                players.get_move(x, y);
                while (!x_o.update_board (x, y, players.get_symbol())){
                    players.get_move(x, y);
                }
                x_o.display_board();
                if (x_o.is_winner()){
                    cout  << players.to_string() << " wins\n";
                    return;
                }
                if (x_o.is_draw()){
                    cout << "Draw!\n";
                    return;
                }
            }
            else{
                computer.findBest();
                pair<int,int> computerMove = computer.getMove();
                while (!x_o.update_board (x, y, computer.get_symbol())){
                    players.get_move(x, y);
                }
                x_o.display_board();
                if (x_o.is_winner()){
                    cout  << players.to_string() << " wins\n";
                    return;
                }
                if (x_o.is_draw()){
                    cout << "Draw!\n";
                    return;
                }
            }
        }
    }
}
