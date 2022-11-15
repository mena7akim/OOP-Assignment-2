#include "SavingsBankAccount.h"

SavingsBankAccount::SavingsBankAccount() : BankAccount(100) { }

SavingsBankAccount::SavingsBankAccount(int bal ,int minBal) {
    if(bal < minBal){
        throw invalid_argument("Operation failed, we expect the balance to be more than or equal the minimum balance");
    }
    balance = bal;
    minBalance = minBal;
}

string SavingsBankAccount::accountType() {
    return "Savings bank account";
}

void SavingsBankAccount::setMinBalance(int min)
{
    minBalance = min;
}

void SavingsBankAccount::setBalance(int bal)
{
    if(bal < minBalance){
        throw invalid_argument("Operation failed, we expect the balance to be more than or equal the minimum balance");
    }
    balance = bal;
}

int SavingsBankAccount::getMinBalance() const
{
    return minBalance;
}

int SavingsBankAccount::getAccountID() const
{
    return accountID;
}

int SavingsBankAccount::getBalance() const
{
    return balance;
}

void SavingsBankAccount::withdraw(int amount)
{
    if (amount >= minBalance){
        balance -= amount;
    }
    else{
        throw invalid_argument("operation failed, you can not withdraw less than your minimum balance");
    }
}
void SavingsBankAccount::deposit(int amount)
{
    if(amount >= 100) {
        balance += amount;
    }
    else{
        throw invalid_argument("Operation failed, you need to deposit not less than 100");
    }
}

