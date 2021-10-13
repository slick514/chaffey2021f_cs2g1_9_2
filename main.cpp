#include <iostream>
using namespace std;

/*
 * Date 2021-10-12
 * Coder: Justin Gries
 * Tester(s):
 *
 * Prompt: Project 9.2
 *  A Person has a name (just a first name for simplicity) and friends
 *  .  Store the names of the friends in a string, separated by spaces.
 *  Provide a constructor that constructs a person with a given name and no
 *  friends.
 *  Provide member functions
        void befriend(Person p)
        void unfriend(Person p)
        string get_friend_names()
 *
 */
int main(int argc, char *argv[]) {
    for(int i = 0; i < argc; i++)
        cout << argv[i] << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
