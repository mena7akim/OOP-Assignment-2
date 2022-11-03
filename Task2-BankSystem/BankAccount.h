#ifndef TASK2_BANKSYSTEM_BANKACCOUNT_H
#define TASK2_BANKSYSTEM_BANKACCOUNT_H

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    int accountID;
    double balance;
public:
    explicit BankAccount();
    explicit BankAccount(int value);
    void setAccountID(int ID);
    void setBalance(int balance);
    int getAccountID() const;
    int getBalance() const;
    void withdraw(int amount);
    void deposit(int amount);
};


#endif
