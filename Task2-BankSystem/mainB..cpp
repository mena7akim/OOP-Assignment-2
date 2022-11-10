#include<iostream>
#include "BankAccount.h"
using namespace std;
int main()
{
    client c1;
    int type;
    cin >> type;
    cout << "Welcome to FCAI banking application" << endl;
    cout << "1. Create a new account \n2. List clients and accounts \n3. Widthrow money \n4. Deposit money \n";
    int choice;
    cin >> choice;
    if (choice == 1) {
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
    else if (choice == 2)
    {


    }
    else if (choice == 3) {
        cout << "Please enter account ID (e.g., FCAI-015): ======> ";
        c1.getAccountID();
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
    else if (choice == 4) {
        cout << "Please enter account ID (e.g., FCAI-015): ======> ";
        c1.getAccountID();
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


}

