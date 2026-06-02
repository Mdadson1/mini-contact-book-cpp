#include "contact_book.h"

Contact::Contact(){
    name = "";
    phone = "";
    deleted = false;
    status = EMPTY;
}
Contact::Contact(const string& n, const string& p){
    name = n;
    phone = p;
    deleted = false;
    status = OCCUPIED;
}

string Contact::getName() const{
    return name;
}
string Contact::getPhone() const{
    return phone;
}
State Contact::getState() const{
    return status;
}

bool Contact::isDeleted() const{
    return deleted;
}
void Contact::markDeleted(){
    deleted = true;
}
void Contact::setState(State stat){
    status = stat;
}