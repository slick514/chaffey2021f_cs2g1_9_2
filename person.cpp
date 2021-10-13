#include <iostream>
#include "person.h"

/*
 * Prompt: A Person has a name (just a first name for simplicity) and friends.
 *
 *  Store the names of the friends in a string, separated by spaces. (Why is
 *  this telling me how to implement things internally? Is this a suggestion
 *  or a requirement?)
 *
 *  Provide a constructor that constructs a person with a given name
 *  and no friends.
 *
 *  Provide member functions:
 *      void befriend(Person p)
 *      void unfriend(Person p)
 *      string get_friend_names()
 *
 * Note: See header file for class and function defs.
*/


Person::Person(string name){
    this->name = name;
}


string Person::get_friend_names() {
    return build_namestring();
}

/* Using the append operation to concatenate may be inefficient, but IDC. I'm
 *  unfamiliar with whether C++ has something akin to a StringBuilder
 *  class, and for this simple project, "append" will do.
*/
 string Person::build_namestring() {
    string friend_names;
    for(auto& f: friends)
        friend_names.append(f.get_name() + " ");

    // remove final space on the end, though this shouldn't really matter all
    // that much.
    if(!friends.empty())
        friend_names.pop_back();
    return friend_names;
}

void Person::befriend(Person new_friend) {
    this->friends.push_back(new_friend);
}

void Person::unfriend(Person ex_friend) {

}