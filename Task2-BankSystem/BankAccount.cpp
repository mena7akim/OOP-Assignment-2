#include "BankAccount.h"



BankAccount::BankAccount() : BankAccount(0){}
BankAccount::BankAccount(int value) : accountID(-1), balance(value){}
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
SavingsBankAccount ::SavingsBankAccount(int initialBal,int minAm)
{
    if(initialBal>=minAm)
        minAmount=minAm;

    setBalance(initialBal);
}

void SavingsBankAccount::setAmount(int min)
{
    minAmount=min;
}

int SavingsBankAccount::getAmount()
{
    return minAmount;
}

void SavingsBankAccount::withdraw(int amount)
{
    if (amount >= minAmount)
        balance-=amount;
}
void SavingsBankAccount::deposit(int amount)
{
    if(amount >= 100)
        balance+=amount;
    balance += amount;

}