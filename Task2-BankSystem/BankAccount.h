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
    virtual void withdraw(int amount);
    void deposit(int amount);
};
class SavingsBankAccount:public BankAccount
{
private:
    int minAmount=1000;
public:
    SavingsBankAccount(int bal ,int minAm);
    void setAmount(int min);
    int getAmount();
    void withdraw(int amount);
    void deposit(int amount);

};
class client : public BankAccount {
private :
    string name;
    string address;
    string phone;

public:
    client();
    client(string name, string address, string phone);
    void setName(string n);
    string getName() const;
    void setAddress(string ad);
    string getAddress() const;
    void setPhone(string ph);
    string getPhone() const;

};



#endif
