//
// Created by over- on 05/11/2022.
//

#include "BankingApplication.h"

int BankingApplication::menu(){
    cout << "Welcome to FCAI banking application" << endl;
    cout << "1. Create a new account \n2. List clients and accounts \n3. Withdraw money \n4. Deposit money \n";
    int choice;
    cin >> choice;
    return choice;
}
void BankingApplication::CreateAccount(){
    cout << "Enter client name: =======> ";
    string name;
    cin >> name;
    c1.setName(name);
    cout << endl;
    cout << "Enter client address: =======> ";
    string address;
    cin >> address;
    c1.setAddress(address);
    cout << endl;
    cout << "Enter client phone: =======> ";
    string phone;
    cin >> phone;
    c1.setPhone(phone);
    cout << endl;
    cout << "What type of account do you like?\n1. Basic. \n2. Saving. \n";
    int t;
    cin >> t;
    if (t == 1) basicAccount = new BankAccount(), type = "basic";
    else if (t == 2) basicAccount = new SavingsBankAccount(), type = "saving";
    cout << "Please enter the starting balance: =======> ";
    double balance;
    cin >> balance;
    basicAccount->setBalance(balance);
    cout << endl;
    cout << "An account was created with ID " << basicAccount->getAccountID() << " and starting balance "
         << balance << " L.E." << endl;
    cout << "your information are saved" << endl;
}
void BankingApplication::ListClientsAndAccounts()
{
    cout << "Client name: ";
    string name;
    cin >> name;
    c1.setName(name);
    cout << endl;
    cout << "Client address: ";
    string address;
    cin >> address;
    c1.setAddress(address);
    cout << endl;
    cout << "Client phone: ";
    string phone;
    cin >> phone;
    c1.setPhone(phone);
    cout << endl;
    cout << "Account ID: " << endl;
    int ID;
    cin >> ID;
    basicAccount->setAccountID(ID);
    cout << endl;
    cout << "Account balance: " << endl;
    double balance;
    cin >> balance;
    basicAccount->setBalance(balance);
    cout << endl;
}
void BankingApplication::WithdrawMoney() {
    cout << "Please enter account ID (e.g., FCAI-015): ======> ";
    int id ;
    cin >> id;
    basicAccount->setAccountID(id);
    cout << endl;
    cout << "Account Id: "  << id << endl;
    cout << "Account type: " << type << '\n';
    cout << "Balance: " ;
    double balance;
    cin >> balance;
    basicAccount->setBalance(balance);
    cout << endl;
    cout << "please enter the amount to withdraw: =====> ";
    int amount;
    cin >> amount;
    basicAccount->withdraw(amount);
    cout << endl;
    cout << "New balance: " << balance << endl;
}
void BankingApplication::DepositMoney() {
    cout << "Please enter account ID (e.g., FCAI-015): ======> ";
    int id;
    cin >> id;
    basicAccount->setAccountID(id);
    cout << endl;
    cout << "Account Id: " << id << endl;
    cout << "Account type: " << type << '\n';
    cout << "Balance: " ;
    int balance;
    cin >> balance;
    basicAccount->setBalance(balance);
    cout << endl;
    cout << "please enter the amount to deposit: =====> ";
    int amount;
    cin >> amount;
    basicAccount->deposit(amount);
    cout << endl;
    cout << "New balance: " << balance << endl;
}
