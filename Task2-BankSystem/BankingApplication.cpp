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
    cout << "Enter client address: =======> ";
    string address;
    cin >> address;
    c1.setAddress(address);
    cout << "Enter client phone: =======> ";
    string phone;
    cin >> phone;
    c1.setPhone(phone);
    cout << "What type of account do you like?\n1. Basic. \n2. Saving. \n";
    int t;
    cin >> t;
    if (t == 1) basicAccount = new BankAccount(), type = "basic";
    else if (t == 2) basicAccount = new SavingsBankAccount(), type = "saving";
    cout << "Please enter the starting balance: =======> ";
    double balance;
    cin >> balance;
    basicAccount->setBalance(balance);
    cout << "An account was created with ID " << basicAccount->getAccountID() << " and starting balance "
         << balance << " L.E." << endl;
    cout << "your information are saved" << endl;
}
void BankingApplication::ListClientsAndAccounts()
{
    cout << "Client name: " << name << endl;
    cout << "Client address: " << address << endl;
    cout << "Client phone: " << phone << endl;
    cout << "Account ID: " << getAccountID() << endl;
    cout << "Account balance: " << c1.getBalance() << endl;
}
void BankingApplication::WithdrawMoney() {
    cout << "Please enter account ID (e.g., FCAI-015): ======> ";
    int id = basicAccount->getAccountID();
    cout << "Account Id: " << c1.getAccountID() << endl;
    cout << "Account type: " << type << '\n';
    cout << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "please enter the amount to withdraw: =====> ";
    int amount;
    cin >> amount;
    c1.withdraw(amount);
    cout << "New balance: " << getBalance() << endl;
}
void BankingApplication::DepositMoney() {
    cout << "Please enter account ID (e.g., FCAI-015): ======> ";
    c1.getAccountID()
    cout << "Account Id: " << c1.getAccountID() << endl;
    cout << "Account type: ";
    if (type == 1)
        cout << "Basic";
    else if (type == 2)
        cout << "Saving";
    cout << endl;
    cout << "Balance: " << balance << endl;
    while (true) {
        cout << "please enter the amount to deposit: =====> ";
        int amount;
        cin >> amount;
        if (amount < 0) {
            cout << "Sorry. enter a positive amount!" << endl;
        } else {
            deposit(amount);
            cout << "New balance: " << balance << endl;
            break;
        }
    }
}