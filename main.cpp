#include "contact_book.h"

using namespace std;

int main(){

    ContactBook PhoneBook(11);
    PhoneBook.displayContacts();
    PhoneBook.remove("Ricardo");

    PhoneBook.insert("Jesus Christ","616-355-316");
    PhoneBook.insert("Holy Spirit", "523-670-011");
    PhoneBook.displayContacts();

    return 0;
}