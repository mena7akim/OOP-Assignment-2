#ifndef TASK2_BANKSYSTEM_BANKACCOUNT_H
#define TASK2_BANKSYSTEM_BANKACCOUNT_H

#include <bits/stdc++.h>
using namespace std;


class BankAccount{
protected:
    static int ID;
    int accountID;
    double balance;
public:
    explicit BankAccount();
    explicit BankAccount(int value);

    virtual void setMinBalance(int min);
    virtual int getMinBalance() const;


    virtual string accountType();
    virtual void setBalance(int bal);
    virtual int getAccountID() const;
    virtual int getBalance() const;
    virtual void withdraw(int amount);
    virtual void deposit(int amount);
};


#endif
