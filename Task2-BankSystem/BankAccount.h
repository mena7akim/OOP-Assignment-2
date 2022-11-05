#ifndef TASK2_BANKSYSTEM_BANKACCOUNT_H
#define TASK2_BANKSYSTEM_BANKACCOUNT_H

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
protected:
    int accountID;
    double balance;
public:
    explicit BankAccount();
    explicit BankAccount(int value);
    void setAccountID(int ID);
    void setBalance(int balance);
    int getAccountID() const;
    int getBalance() const;
    virtual int getAmount();
    virtual void withdraw(int amount);
    virtual void deposit(int amount);
};



#endif
