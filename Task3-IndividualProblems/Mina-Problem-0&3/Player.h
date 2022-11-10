//
// Created by over- on 10/11/2022.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include <bits/stdc++.h>
using namespace std;

class Player {
    protected:
        string name;
        char symbol;
    public:
        // Two constructors to initiate player
        // Give player a symbol to use in playing
        // It can be X or O or others
        // Optionally, you can give him ID or order
        // Like Player 1 and Player 2
        Player ();
        Player (char symbol); // Needed for computer players
        Player (int order, char symbol);
        // Get desired move: x y (each between 0 and 2)
        // Virtual (can change for other player types)
        void get_move(int& x, int& y);
        // Give player info as a string
        virtual string to_string();
        // Get symbol used by player
        virtual char get_symbol();
};


#endif //MAIN_CPP_PLAYER_H
