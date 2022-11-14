#include "BankAccount.h"


int BankAccount::ID = 0;

BankAccount::BankAccount() : BankAccount(0){
    ID++;
    accountID = ID;
}
BankAccount::BankAccount(int value) : balance(value){
    ID++;
    accountID = ID;
}

string BankAccount::accountType() {
    return "Bank Account";
}

void BankAccount::setBalance(int bal) {
    this->balance = bal;
}

int BankAccount::getAccountID() const {
    return accountID;
}
int BankAccount::getBalance() const {
    return balance;
}

void BankAccount::withdraw(int amount) {
    if(amount > balance){
        throw invalid_argument("Operation failed, Amount you want to withdraw is bigger than your account balance.");
    }
    balance -= amount;
}
void BankAccount::deposit(int amount) {
    balance += amount;
}

int BankAccount::getMinBalance() const {
    return 0;
}

void BankAccount::setMinBalance(int min) {
    return;
}
