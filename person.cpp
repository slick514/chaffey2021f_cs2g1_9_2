#include <utility>
#include <string>
#include "person.h"

using namespace std;

Person::Person(const string &name){
    this->name = name;
}

string Person::get_friend_names() const{
    return this->friend_names;
}

void Person::befriend(const Person &new_friend) {

    if(!this->friend_names.empty())
        this->friend_names.append(" ");
    this->friend_names.append(new_friend.get_name());
}

void Person::unfriend(const Person &ex_friend) {
    string ex_name = ex_friend.get_name();
    size_t position = this->friend_names.find(ex_name);
    if(position != string::npos)
        this->friend_names.erase(position, ex_name.length());
}

void Person::print_person() const{
    cout << "Name: " << this->name;
    cout << ";  Friends: ";
    string message = this->get_friend_names().empty() ? NO_FRIENDS_MSG :
            this->get_friend_names();
    cout << message << endl;
}

string Person::get_name() const {
    return this->name;
}
