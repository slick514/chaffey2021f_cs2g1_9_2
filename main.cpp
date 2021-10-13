#include "person.cpp"

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
    Person p = *new Person("BoB");
    cout << p.get_name() << "'s friends: \n\"";
    cout << p.get_friend_names() << "\"" << endl;
}
