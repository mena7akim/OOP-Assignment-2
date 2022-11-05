//
// Created by over- on 05/11/2022.
//

#ifndef TASK2_BANKSYSTEM_CLIENT_H
#define TASK2_BANKSYSTEM_CLIENT_H

#include <bits/stdc++.h>
using namespace std;

class Client {
private :
    string name;
    string address;
    string phone;
public:
    Client();
    Client(string name, string address, string phone);
    void setName(string n);
    string getName() const;
    void setAddress(string ad);
    string getAddress() const;
    void setPhone(string ph);
    string getPhone() const;
};


#endif //TASK2_BANKSYSTEM_CLIENT_H
