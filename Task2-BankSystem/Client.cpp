#include "Client.h"


Client::Client() {

}

Client::Client(string name, string address, string phone) : name(name), address(address), phone(phone) {

}


void Client::setName(string n){
    name = n;
}
void Client::setAddress(string ad){
    address = ad;
}
void Client::setPhone(string ph){
    phone = ph;
}
void Client::pointToAccount(BankAccount &account) {
    clientAccount = &account;
}

BankAccount& Client::getClientAccount() {
    return *clientAccount;
}


string Client::getName() const{
    return name;
}
string Client::getAddress() const{
    return address;
}
string Client::getPhone() const{
    return phone;
}