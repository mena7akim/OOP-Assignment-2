//
// Created by over- on 05/11/2022.
//

#include "SavingsBankAccount.h"



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
    if(amount >= 100) balance+=amount;
}