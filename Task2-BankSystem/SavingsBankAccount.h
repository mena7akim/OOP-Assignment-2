
#ifndef TASK2_BANKSYSTEM_SAVINGSBANKACCOUNT_H
#define TASK2_BANKSYSTEM_SAVINGSBANKACCOUNT_H

#include "BankAccount.h"

class SavingsBankAccount : public BankAccount
{
private:
    int minBalance = 100;

public:
    SavingsBankAccount();
    SavingsBankAccount(int bal ,int minAm);
    string accountType() override;
    void setMinBalance(int min) override;
    void setBalance(int bal) override;
    int getMinBalance() const override;
    int getAccountID() const override;
    int getBalance() const override;
    void withdraw(int amount) override;
    void deposit(int amount) override;
};


#endif
