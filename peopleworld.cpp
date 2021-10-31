//
// Created by Justin Gries on 10/30/2021.
//

#include <sstream>
#include <algorithm>
#include "peopleworld.h"
using namespace std;

void PeopleWorld::do_people_world() {
    cout << endl << "Welcome to People-World" << endl;
    PeopleWorld world;
    char choice;
    string name1;
    string name2;
    do {
        Menu menu(MENU_TITLE);
        menu = world.build_menu();
        menu.display_menu(3);
        choice = get_choice_from_user(name1, name2);
        switch (choice) {
            case CHOICE_ADD_PERSON: {
                string name = parse_name(name1);
                if (world.find_person(name)) {
                    cout << endl << "A person named '" << name << "' already exists" << endl << endl;
                }else {
                    world.add_person(name);
                }
                break;
            }
            case CHOICE_MAKE_FRIENDS: {
                string n1 = parse_name(name1);
                string n2 = parse_name(name2);
                auto *pP1 = new Person("");
                auto *pP2 = new Person("");
                bool p1_exists = world.find_person(n1, &pP1);
                bool p2_exists = world.find_person(n2, &pP2);
                if (p1_exists && p2_exists) {
                    make_friends(pP1, pP2);
                }else{
                    if(!p1_exists)
                        cout << "Person '" << n1 << "' does not exist" << endl;
                    if(!p2_exists)
                        cout << "Person '" << n2 << "' does not exist" << endl;
                }
                break;
            }
            case CHOICE_BREAK_FRIENDS: {
                string n1 = parse_name(name1);
                string n2 = parse_name(name2);
                auto *pP1 = new Person("");
                auto *pP2 = new Person("");
                bool p1_exists = world.find_person(n1, &pP1);
                bool p2_exists = world.find_person(n2, &pP2);
                if (p1_exists && p2_exists) {
                    break_up(pP1, pP2);
                }else{
                    if(!p1_exists)
                        cout << "Person '" << n1 << "' does not exist" << endl;
                    if(!p2_exists)
                        cout << "Person '" << n2 << "' does not exist" << endl;
                }
                break;
            }
            case CHOICE_VIEW_PEOPLE: {
                world.display_people();
                break;
            }
            case CHOICE_QUIT:
                break;
            default:
                cout << "Input '" << choice << "' is not valid." << endl;
        }
    }while(choice != CHOICE_QUIT);
}

Menu PeopleWorld::build_menu(){
    Menu menu("People-Watcher Menu");
    string menu_str = Menu::build_menu_string("(", CHOICE_ADD_PERSON, ")dd Person");
    menu.add_item(menu_str);
    if(!(this->people.empty())) {
        string view_friends_menu_str = Menu::build_menu_string("(", CHOICE_VIEW_PEOPLE, ")iew People");
        menu.add_item(view_friends_menu_str);
        if(this->people.size() > 1) {
            string make_friend_menu_str = Menu::build_menu_string("(", CHOICE_MAKE_FRIENDS, ")ake Friends");
            menu.add_item(make_friend_menu_str);
            string break_friend_menu_str = Menu::build_menu_string("(", CHOICE_BREAK_FRIENDS, ")reak Up");
            menu.add_item(break_friend_menu_str);
        }
    }
    string quit_menu_str = Menu::build_menu_string("(", CHOICE_QUIT, ")uit");
    menu.add_item(quit_menu_str);
    return menu;
}

char PeopleWorld::get_choice_from_user(string &name1, string &name2) {
    char choice = read_in_char_to_upper();
    switch (choice) {
        case CHOICE_ADD_PERSON:
            cout << "What is the person's name?" << endl;
            cin >> name1;
            break;
        case CHOICE_MAKE_FRIENDS:
        case CHOICE_BREAK_FRIENDS:
            cout << "Give me two names please:" << endl;
            cin >> name1 >> name2;
            break;
        default:
            ;
    }
    return choice;
}

void PeopleWorld::add_person(const string &person_name) {
    auto *pPerson = new Person(person_name);
    this->people.push_back(pPerson);
    for(const Person *p : this->people){
        p->print_person();
    }
}

string PeopleWorld::parse_name(const string &name_str) {
    stringstream stream;
    if(name_str.empty()){
        cout << "Name is empty" << endl;
    }else {
        for (const char &rChar: name_str) {
            if (!isalnum(rChar)) {
                cout << "Entry '" << name_str << "' is not alpha-numeric";
                return "";
            }
            stream << (char)toupper(rChar);
        }
    }
    return stream.str();
}

bool PeopleWorld::find_person(const string &person_name, Person **ppPerson) {

    for (Person *p : this->people){
        if(p->get_name() == person_name) {
            *ppPerson = p;
            return true;
        }
    }
    return false;
}

void PeopleWorld::display_people() {
    for(const Person *p : this->people)
        p->print_person();
}

void PeopleWorld::break_up(Person *pP1, Person *pP2) {
    pP1->unfriend(*pP2);
    pP2->unfriend(*pP1);
}

void PeopleWorld::make_friends(Person *pP1, Person *pP2) {
    pP1->befriend(*pP2);
    pP2->befriend(*pP1);
}

bool PeopleWorld::find_person(const string &person_name) {
    for (Person *p : this->people)
        if(p->get_name() == person_name)
            return true;
    return false;
}

char read_in_char_to_upper() {
    string input;
    cin >> input;
    return (char)toupper(input[0]);
}
