
#ifndef TASK2_BANKSYSTEM_CLIENT_H
#define TASK2_BANKSYSTEM_CLIENT_H

#include "SavingsBankAccount.h"

class Client {
private :
    string name;
    string address;
    string phone;
    BankAccount *clientAccount;
public:
    Client();
    Client(string name, string address, string phone);
    void setName(string n);
    void setAddress(string ad);
    void setPhone(string ph);

    void pointToAccount(BankAccount &account);
    BankAccount& getClientAccount();

    string getName() const;
    string getAddress() const;
    string getPhone() const;
};


#endif //TASK2_BANKSYSTEM_CLIENT_H
