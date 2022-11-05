//
// Created by over- on 05/11/2022.
//

#ifndef TASK2_BANKSYSTEM_BANKINGAPPLICATION_H
#define TASK2_BANKSYSTEM_BANKINGAPPLICATION_H

#include "Client.h"
#include "BankAccount.h"
#include "SavingsBankAccount.h"

class BankingApplication {
private:
    Client c1;
    BankAccount *basicAccount;
    string type;
public:
    int menu();
    void CreateAccount();
    void ListClientsAndAccounts();
    void WithdrawMoney();
    void DepositMoney();
};


#endif //TASK2_BANKSYSTEM_BANKINGAPPLICATION_H
