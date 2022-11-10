//
// Created by over- on 05/11/2022.
//

#ifndef TASK2_BANKSYSTEM_SAVINGSBANKACCOUNT_H
#define TASK2_BANKSYSTEM_SAVINGSBANKACCOUNT_H

#include "BankAccount.h"

class SavingsBankAccount:public BankAccount
{
private:
    int minAmount=1000;
public:
    SavingsBankAccount();
    SavingsBankAccount(int bal ,int minAm):BankAccount(bal), minAmount(minAm){}
    void setAmount(int min);
    int getAmount();
    void withdraw(int amount);
    void deposit(int amount);

};


#endif //TASK2_BANKSYSTEM_SAVINGSBANKACCOUNT_H
