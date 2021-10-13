//
// Created by justi on 10/13/2021.
//
#ifndef CHAFFEY2021F_CS2G1_9_2_PERSON_H
#define CHAFFEY2021F_CS2G1_9_2_PERSON_H
#include <vector>

using namespace std;

/*
 * Notes(s)
 *  Storing the list of names as a string is a bad idea. What if two instances
 *  of Person have the same name? Would be better to store as a Vector of
 *  Person objects.
 */
class Person {
public:
    explicit Person(string name);
    ~Person();
    void befriend(Person new_friend);
    void unfriend(Person ex_friend);
    string get_friend_names();
    string get_name(){return name;}
private:
    string name;
    vector<Person> friends;
    string build_namestring();
};

/*
 * Deconstructor. Unused but good code practice
 */
Person::~Person(){
}

#endif //CHAFFEY2021F_CS2G1_9_2_PERSON_H
