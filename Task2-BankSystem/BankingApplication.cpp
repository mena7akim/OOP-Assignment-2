#include "BankingApplication.h"

BankingApplication::BankingApplication() {
    client.reserve(1000);
    bankAccount.reserve(1000);
    cout << "Welcome to our Bank Application :)\n";
}

void BankingApplication::menu(){
    cout << "Welcome to FCAI banking application\n";
    cout << "1. Create a new account \n2. List clients and accounts \n3. Withdraw money \n4. Deposit money \n";
    int choice;
    cin >> choice;
    if(choice == 1) CreateAccount();
    else if(choice == 2) ListClientsAndAccounts();
    else if(choice == 3) WithdrawMoney();
    else if(choice == 4) DepositMoney();
}

void BankingApplication::CreateAccount(){
    cout << "Enter client name: =======> \n";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter client address: =======> \n";
    string address;
    getline(cin, address);
    cout << "Enter client phone: =======> \n";
    string phone;
    cin >> phone;

    client.push_back(Client(name, address, phone));

    cout << "What type of account do you like?\n1. Basic. \n2. Saving. \n";
    int t;
    cin >> t;
    if (t == 1) {
        bankAccount.push_back(new BankAccount(0));
        client[client.size() - 1].pointToAccount(*bankAccount[bankAccount.size() - 1]);
    }
    else if (t == 2) {
        bankAccount.push_back(new SavingsBankAccount());
        client[client.size() - 1].pointToAccount(*bankAccount[bankAccount.size() - 1]);
        cout << "Enter the minimum amount\n";
        int amount;
        cin >> amount;
        bankAccount[bankAccount.size() - 1]->setMinBalance(amount);
    }
    cout << "Please enter the starting balance: =======> ";
    double balance;
    cin >> balance;
    bankAccount[bankAccount.size() - 1]->setBalance(balance);
    cout << endl;
    cout << "An account was created with ID " << bankAccount[bankAccount.size() - 1]->getAccountID() << " and starting balance "
         << balance << " L.E.\n";
    cout << "your information are saved\n";
}
void BankingApplication::ListClientsAndAccounts()
{
    for(auto c : client){
        cout << "---------" << c.getName() << "---------" << '\n';
        cout << "Account Type: " << c.getClientAccount().accountType() << '\n';
        cout << "Address: " << c.getAddress() << '\n';
        cout << "Phone: " << c.getPhone() << '\n';
        cout << c.getClientAccount().getBalance() << '\n';
        cout << "-----------------------------------------" << '\n';
    }
}
void BankingApplication::WithdrawMoney() {
    cout << "Please enter account ID (e.g., FCAI-015): ======> \n";
    int id ;
    cin >> id;
    for(auto c : client){
        if(id == c.getClientAccount().getAccountID()){
            cout << "Account ID: " << c.getClientAccount().getAccountID() << '\n';
            cout << "Account Type: " << c.getClientAccount().accountType() << '\n';
            cout << "Balance: " << c.getClientAccount().getBalance() << '\n';
            cout << "Please enter the amount to Withdraw: \n";
            int amount;
            cin >> amount;
            while(amount > c.getClientAccount().getBalance()){
                cout << "Sorry. This is more than what you can withdraw\n";
                cout << "Please enter the amount to Withdraw: \n";
                cin >> amount;
            }
            c.getClientAccount().withdraw(amount);
            cout << "Thank you.\n";
            cout << "Account ID: " << c.getClientAccount().getAccountID() << '\n';
            cout << "New Balance: " << c.getClientAccount().getBalance() << '\n';
            break;
        }
    }

}
void BankingApplication::DepositMoney() {
    cout << "Please enter account ID (e.g., FCAI-015): ======> \n";
    int id ;
    cin >> id;
    for(auto c : client){
        if(id == c.getClientAccount().getAccountID()){
            cout << "Account ID: " << c.getClientAccount().getAccountID() << '\n';
            cout << "Account Type: " << c.getClientAccount().accountType() << '\n';
            cout << "Balance: " << c.getClientAccount().getBalance() << '\n';
            cout << "Please enter the amount to deposit: \n";
            int amount;
            cin >> amount;
            while(c.getClientAccount().accountType() == "Savings bank account" && amount < c.getClientAccount().getMinBalance()){
                cout << "Sorry. This is less than what you can deposit\n";
                cout << "Please enter the amount to deposit: \n";
                cin >> amount;
            }
            c.getClientAccount().deposit(amount);
            cout << "Thank you.\n";
            cout << "Account ID: " << c.getClientAccount().getAccountID() << '\n';
            cout << "New Balance: " << c.getClientAccount().getBalance() << '\n';
            break;
        }
    }
}
