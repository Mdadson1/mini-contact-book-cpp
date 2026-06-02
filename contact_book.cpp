#include "contact_book.h"

ContactBook::ContactBook(int size){
    if(size <= 0){
        //empty object
        table = nullptr;
        tableLength = MINPRIME;
        m_size = 0;
        numDeleted = 0;
    }else{
        //reserve heap for the array of this 
        //amount of contacts
        table = new Contact[size];
        tableLength = size;
        m_size = 0;
        numDeleted = 0;
    }
        
}

ContactBook::~ContactBook(){
    delete [] table;
    table = nullptr;
}

void ContactBook::insert(const string& name, const string& phone){
    /* hashes the name to find a starting index,
    probes until it finds an empty or deleted slot,
    places the contact there */

    int bucket = probe(name, true);
    if(bucket == -1){
        cout << "Unable to add Contact. Try again later." << endl;
        return;
    }
    table[bucket] = Contact(name, phone);
    m_size++;
}
void ContactBook::search(const string& name) const{
    /*
    hashes the name,
    probes until it finds a matching name or an empty slot
    (empty = stop, deleted = skip past)
    */ 
   int bucket = probe(name, false);
   if(bucket == -1){
    cout << "No Results for ' " << name
    << " ' \nCheck the spelling or try a new search."
    << endl;
   }else{
    cout << "Name: " << name <<
    "\tPhone: " << table[bucket].getPhone() << endl;
   }

}
void ContactBook::remove(const string& name){
/* hashes the name, 
probes until it finds a match, 
marks it as deleted*/
    int bucket = probe(name, false);
    if(bucket == -1){
        cout << "No Results for ' " << name
        << " ' \nCheck the spelling or try a new search."
        << endl;
    }else{
        table[bucket].markDeleted();
        table[bucket].setState(DELETED);
        numDeleted++;
    }
    
}

void ContactBook::displayContacts() const{
    /* shows all contacts that exist (status == occupied)*/
    if(table == nullptr){//empty table
        cout << "No Contacts." << endl;
    }else{
        for(int i = 0; i < tableLength; i++){
            if(table[i].getState() == OCCUPIED){
                cout << table[i].getName() 
                << "\tPhone: " 
                << table[i].getPhone() << endl;
            }
        }
    }
            
}


/*Private Helpers*/
int ContactBook::hash(const string& name) const{
    /*
     takes the name string 
     and returns an index into the table
    */

    //build the int index
    int ascii = 0;
    for(int i = 0; i < name.length(); i++){
        //go through the string to build the ascii equiv
        ascii += name[i];
    }
    return ascii % tableLength;
    
}

int ContactBook::probe(const string& name, bool forInsert) const{
    //quadratic by default
    /*the shared probing logic used by insert,
     search, and remove
     forInsert is used to determine if we are inserting or not
    formula: (hashresult + (i*i) ) % tablelength */
    if(table != nullptr){
        int init = hash(name);
        int probed = 0;
        int attempt = 0;
        bool found = false;
        bool empty = false;

        if(forInsert){
            while(attempt < tableLength && !found && !empty){
                //calc probed index
                probed = (init + attempt*attempt) % tableLength;

                //check availability
                if(table[probed].getState() == DELETED ||
                    table[probed].getState() == EMPTY){
                    //safe to overwrite, return this bucket index
                    found = true;
                    return probed;
                }//else just keep probing
                attempt++;
            }
            //searched entire table
            return -1;
        }else{
            //searching or removal
            while(attempt < tableLength && !found){
                probed = (init + attempt*attempt) % tableLength;

                if(table[probed].getName() == name){
                    found = true;
                    return probed;
                }else if(table[probed].getState() == EMPTY){
                    //stop search
                    empty = true;
                    return -1;
                }
                attempt++;
            }
            return -1;
        } 
    }else{
        return -1;
    }
}