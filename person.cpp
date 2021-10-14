#include "person.h"
/*
 * Prompt: A Person has a name (just a first name for simplicity) and friends.
 *
 *  Store the names of the friends in a string, separated by spaces.
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

const string NO_FRIENDS_MSG = "This person has no friends.";

Person::Person(string name){
    this->name = name;
}


string Person::get_friend_names() {
    return this->friend_names;
}

/*
 * (At the moment) we are not checking for duplicates. Just adding names to
 * the end of friend_names.
 * todo: Ask instructor how to handle:
 *      new_friend = self
 *      new_friend.get_name() already in friend_names
 */
void Person::befriend(Person new_friend) {
    if(!this->friend_names.empty())
        this->friend_names.append(" ");
    this->friend_names.append(new_friend.get_name());
}

/*
 * FIFO
 * todo: find out what to do if/when ex_friend does not exist in friend_names
 */
void Person::unfriend(Person ex_friend) {
    string ex_name = ex_friend.get_name();
    size_t position = this->friend_names.find(ex_name);
    if(position != string::npos)
        this->friend_names.erase(position, ex_name.length());
}

void Person::printPerson(){
    cout << "Name: " << this->get_name() << endl;
    cout << "Friends: ";
    string message = this->get_friend_names().empty() ? NO_FRIENDS_MSG :
            this->get_friend_names();
    cout << message << endl;
}
