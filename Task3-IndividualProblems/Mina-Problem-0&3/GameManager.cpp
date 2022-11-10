//
// Created by over- on 10/11/2022.
//

#include "GameManager.h"

void GameManager::run() {
    Board x_o;
    int x, y;
    Player players = Player (1, 'x');
    ComputerPlayer computer = ComputerPlayer(2, 'o');
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
                computer.getBoard(x_o);
                computer.findBest();
                pair<int,int> computerMove = computer.getMove();
                x_o.update_board (computerMove.first, computerMove.second, computer.get_symbol());
                x_o.display_board();
                if (x_o.is_winner()){
                    cout  << computer.to_string() << " wins\n";
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