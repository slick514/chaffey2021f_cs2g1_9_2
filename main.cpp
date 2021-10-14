#include "person.cpp"

void printPeople(vector<Person> &people);
void do_tests();
vector<Person> get_3_people();

using namespace std;
/*
 * Course: Chaffey College 2021-Fall CS2
 * Prof: Dr. Tracy Kocher
 * Date 2021-10-12
 * Coder: Justin Gries
 * Tester(s):
 *
 * Prompt: See "person.cpp"
 *
 */
int main(int argc, char **argv) {
    do_tests();
}

// todo: complete class testing
void do_tests(){
//    test_create_person();
//    test_add_friend();
//    test_add_multiple_friends();
//    test_remove_friend_from_beginning();
//    test_remove_friend_from_middle();
//    test_remove_friend_from_end();
//    test_add_duplicate();
//    test_remove_duplicate();
}

/*  Clue-code:
 *  vector<Person> people = get_3_people();
    Person *p1 = &people[1];
    Person *p2= &people[1];
    (*p2).befriend(*p1);
    printPeople(people);
 */
vector<Person> get_3_people() {
    Person bob("Bob");
    Person doug("Doug");
    Person mike("Mike");
    return {bob, doug, mike};
}

void printPeople(vector<Person> &people) {
    for(int i = 0; i < people.size(); i++){
        people[i].printPerson();
    }
    cout << endl;
}
