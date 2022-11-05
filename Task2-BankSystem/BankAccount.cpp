#include "BankAccount.h"



BankAccount::BankAccount() : BankAccount(0){}
BankAccount::BankAccount(int value) : balance(value){}
void BankAccount::setAccountID(int ID) {
    this->accountID = ID;
}
void BankAccount::setBalance(int balance) {
    this->balance = balance;
}

int BankAccount::getAccountID() const {
    return accountID;
}
int BankAccount::getBalance() const {
    return balance;
}

void BankAccount::withdraw(int amount) {
    balance -= amount;
}
void BankAccount::deposit(int amount) {
    balance += amount;
}



