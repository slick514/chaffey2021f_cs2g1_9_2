#include <iostream>
#include "person.h"

/*
 * Prompt: A Person has a name (just a first name for simplicity) and friends.
 *  Store the names of the friends in a string, separated by spaces.
 *  Provide a constructor that constructs a person with a given name
    and no friends.
 *  Provide member functions:
        void befriend(Person p)
        void unfriend(Person p)
        string get_friend_names()
*/


Person::Person(string name){
    this->name = name;
    cout << name << endl;
}



// Using the cat operation to concatenate is inefficient, but IDC. I'm
// unfamiliar with whether or not C++ has something akin to a StringBuilder
// class, and for this simple project, cat will do.
string Person::get_friend_names() {
    return "";
}

void Person::befriend(Person new_friend) {

}

void Person::unfriend(Person ex_friend) {

}