

#ifndef TASK2_BANKSYSTEM_BANKINGAPPLICATION_H
#define TASK2_BANKSYSTEM_BANKINGAPPLICATION_H

#include "Client.h"

class BankingApplication {
private:
    vector<Client> client;
    vector<BankAccount*> bankAccount;
public:
    BankingApplication();
    void menu();
    void CreateAccount();
    void ListClientsAndAccounts();
    void WithdrawMoney();
    void DepositMoney();
};


// client   --> bankaccount
// client 2 --> ....
// client 3 --> ....
// ,,,

#endif
