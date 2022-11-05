//
// Created by over- on 05/11/2022.
//

#include "Client.h"


void Client::setName(string n){
    this->name = n;
}
void Client::setAddress(string ad){
    this->address = ad;
}
void Client::setPhone(string ph){
    this->phone = ph;
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