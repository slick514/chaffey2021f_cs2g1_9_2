//
// Created by Justin Gries on 10/30/2021.
//

#ifndef CHAFFEY2021F_CS2G1_9_2_PEOPLEWORLD_H
#define CHAFFEY2021F_CS2G1_9_2_PEOPLEWORLD_H

#include "person.h"
#include "menu.h"

static const std::string MENU_TITLE = "CHOICES:";
static const char CHOICE_ADD_PERSON = 'A';
static const char CHOICE_MAKE_FRIENDS = 'M';
static const char CHOICE_BREAK_FRIENDS = 'B';
static const char CHOICE_VIEW_PEOPLE = 'V';
static const char CHOICE_QUIT = 'Q';

class PeopleWorld{
public:

    /**
     * Attempts to add a person
     * @param person_name The name of the new person.
     * @return 0 if successful, 1 if person already exists
     */
    void add_person(const std::string &person_name);

    /**
     * Make friends of two people
     * @param pPerson_1
     * @param pPerson_2
     */
    static void make_friends(Person *pP1, Person *pP2);

    static void break_up(Person *pP1, Person *pP2);

    void display_people();

    static void do_people_world();
private:
    std::vector<Person*> people;
    Menu build_menu();
    static char get_choice_from_user(std::string &rName1, std::string &rName2);

    static std::string parse_name(const std::string &name_str);

    bool find_person(const std::string &person_name, Person **ppPerson);
    bool find_person(const std::string &person_name);
};

char read_in_char_to_upper();

#endif //CHAFFEY2021F_CS2G1_9_2_PEOPLEWORLD_H
