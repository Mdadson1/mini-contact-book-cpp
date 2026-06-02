#ifndef CONTACT_BOOK_H
#define CONTACT_BOOK_H

#include <iostream>
#include <string>
using namespace std;
//forward declaration
class Contact;
class ContactBook;
enum State { EMPTY, DELETED, OCCUPIED};
#define MINPRIME 7
#define MAXPRIME 23
class Contact {
private:
    string name; //key
    string phone;
    bool deleted;
    State status;

public:
    Contact();
    Contact(const string& n, const string& p);

    string getName() const;
    string getPhone() const;
    State getState() const;
    bool isDeleted() const;
    void markDeleted();
    void setState(State stat);
    
};

class ContactBook {
private:
    Contact* table;
    int tableLength;
    int m_size;
    int numDeleted;

    int hash(const string& n) const;
    int probe(const string& n, bool forInsert) const;

public:
    ContactBook(int size);
    ~ContactBook();

    void insert(const string& name, const string& phone);
    void search(const string& name) const;
    void remove(const string& name);
    void displayContacts() const;
};


#endif