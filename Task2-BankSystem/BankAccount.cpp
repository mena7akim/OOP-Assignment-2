#include "BankAccount.h"



BankAccount::BankAccount() : BankAccount(0){}
BankAccount::BankAccount(int value) : accountID(-1), balance(value){}
void BankAccount::setAccountID(int ID) {
    this->accountID = ID;
}
void BankAccount::setBalance(int balance) {
    this->balance = balance;
}

int BankAccount::getAccountID() const {
    return accountID;
}
int BankAccount::getBalance() const {
    return balance;
}

void BankAccount::withdraw(int amount) {
    balance -= amount;
}
void BankAccount::deposit(int amount) {
<<<<<<< HEAD
    balance += amount;
}
SavingsBankAccount ::SavingsBankAccount(int initialBal,int minAm)
{
    if(initialBal>=minAm)
        minAmount=minAm;

    setBalance(initialBal);
}

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
    if(amount >= 100)
        balance+=amount;
=======
    blance += amount;
>>>>>>> origin/main
}
void client::setName(string n){
    this->name = n;
}
void client::setAddress(string ad){
    this->address = ad;
}
void client::setPhone(string ph){
    this->phone = ph;
}
string client::getName() const{
    return name;
}
string client::getAddress() const{
    return address;
}
string client::getPhone() const{
    return phone;
}
int BankingApplication::menu(int n){
    cout << "Welcome to FCAI banking application" << endl;
    cout << "1. Create a new account \n2. List clients and accounts \n3. Withdraw money \n4. Deposit money \n";
    int choice;
    cin >> choice;
    return choice;
}
void BankingApplication::CreateAccount(){
    int type;

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
    cin >> type;
    if (type == 1) {
        cout << "Please enter the starting balance: =======> ";
        double balance;
        cin >> balance;
        basicAccount.setBalance(balance);
        cout << "An account was created with ID " << accountID << " and starting balance "
             << balance << " L.E." << endl;
    } else if (type == 2) {
        cout << "your information are saved" << endl;
    }
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
    c1.getAccountID()
    cout << "Account Id: " << c1.getAccountID() << endl;
    cout << "Account type: ";
    if (type == 1)
        cout << "Basic";
    else if (type == 2)
        cout << "Saving";
    cout << endl;
    cout << "Balance: " << getBalance() << endl;
    while (true) {
        cout << "please enter the amount to withdraw: =====> ";
        int amount;
        cin >> amount;
        if (amount > c1.getBalance()) {
            cout << "Sorry. this is more than what you cac withdraw.!" << endl;
        } else {
            c1.withdraw(amount);
            cout << "New balance: " << getBalance() << endl;
            break;
        }
    }
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