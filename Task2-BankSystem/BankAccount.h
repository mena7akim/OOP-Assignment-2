#ifndef TASK2_BANKSYSTEM_BANKACCOUNT_H
#define TASK2_BANKSYSTEM_BANKACCOUNT_H

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
protected:
    int accountID;
    double balance;
public:
    explicit BankAccount();
    explicit BankAccount(int value);
    void setAccountID(int ID);
    void setBalance(int balance);
    int getAccountID() const;
    int getBalance() const;
    virtual void withdraw(int amount);
    void deposit(int amount);
};
class SavingsBankAccount:public BankAccount
{
private:
    int minAmount=1000;
public:
    SavingsBankAccount(int bal ,int minAm);
    void setAmount(int min);
    int getAmount();
    void withdraw(int amount);
    void deposit(int amount);

};
class client : public BankAccount {
private :
    string name;
    string address;
    string phone;

public:
    client();
    client(strint name, string address, string phone);
    void setName(string n);
    string getName() const;
    void setAddress(string ad);
    string getAddress() const;
    void setPhone(string ph);
    string getPhone() const;

};
class BankingApplication : public BankAccount{
    int menu(int n)
    {
        cout << "Welcome to FCAI banking application" << endl;
        cout << "1. Create a new account \n2. List clients and accounts \n3. Withdraw money \n4. Deposit money \n";
        int choice;
        cin >> choice;
        return choice;
    }
    void CreateAccount()
    {
        int type;
        cin >> type;
        cout << "Enter client name: =======> ";
        c1.getName();
        cout << "Enter client address: =======> ";
        c1.getAddress();
        cout << "Enter client phone: =======> ";
        c1.getPhone();
        cout << "What type of account do you like?\n1. Basic. \n2. Saving. \n";

        if (type == 1) {
            cout << "Please enter the starting balance: =======> ";
            c1.getBalance();
            cout << "An account was created with ID " << c1.getAccountID() << " and starting balance "
                 << c1.getBalance() << " L.E." << endl;
        } else if (type == 2) {
            cout << "your information is saved" << endl;
        }
    }
    void ListClientsAndAccounts()
    {
        cout << "Client name: " << c1.getName() << endl;
        cout << "Client address: " << c1.getAddress() << endl;
        cout << "Client phone: " << c1.getPhone() << endl;
        cout << "Account ID: " << c1.getAccountID() << endl;
        cout << "Account balance: " << c1.getBalance() << endl;
    }
    void WithdrawMoney()
    {
        cout << "Please enter account ID (e.g., FCAI-015): ======> ";
        c1.getAccountID()
        cout << "Account Id: " << c1.getAccountID() << endl;
        cout << "Account type: ";
        if (type == 1)
            cout << "Basic";
        else if (type == 2)
            cout << "Saving";
        cout << endl;
        cout << "Balance: " << c1.getBalance() << endl;
        while (true) {
            cout << "please enter the amount to withdraw: =====> ";
            int amount;
            cin >> amount;
            if (amount > c1.getBalance()) {
                cout << "Sorry. this is more than what you cac withdraw.!" << endl;
            } else {
                c1.withdraw(amount);
                cout << "New balance: " << c1.getBalance() << endl;
                break;
            }
        }
    }
    void DepositMoney()
    {
        cout << "Please enter account ID (e.g., FCAI-015): ======> ";
        c1.getAccountID()
        cout << "Account Id: " << c1.getAccountID() << endl;
        cout << "Account type: ";
        if (type == 1)
            cout << "Basic";
        else if (type == 2)
            cout << "Saving";
        cout << endl;
        cout << "Balance: " << c1.getBalance() << endl;
        while (true) {
            cout << "please enter the amount to deposit: =====> ";
            int amount;
            cin >> amount;
            if (amount < 0) {
                cout << "Sorry. enter a positive amount!" << endl;
            } else {
                c1.deposit(amount);
                cout << "New balance: " << c1.getBalance() << endl;
                break;
            }
        }
    }



};

#endif
