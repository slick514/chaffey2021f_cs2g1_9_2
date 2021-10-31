//
// Created by Justin Gries on 10/13/2021.
//
#ifndef CHAFFEY2021F_CS2G1_9_2_PERSON_H
#define CHAFFEY2021F_CS2G1_9_2_PERSON_H
#include <vector>
#include <iostream>

const std::string NO_FRIENDS_MSG = "This person has no friends."; /* NOLINT */

/**
 * Prompt: A Person has a name (just a first name for simplicity) and friends.
 *
 *  Store the names of the friends in a std::string, separated by spaces.
 *
 *  Provide a constructor that constructs a person with a given name
 *  and no friends.
 *
 *  Provide member functions:
 *      void befriend(Person p)
 *      void unfriend(Person p)
 *      std::string get_friend_names()
 *
 * Note: See header file for class and function defs.
 */
class Person {
public:
    /**
     * Instantiates a person, with a name and no friends
     * @param name The person's name
     */
    explicit Person(const std::string &name);

    /**
     * We are considering names to be unique identifiers
     * @param new_friend Person object representing new friend
     */
    void befriend(const Person &new_friend);

    /**
     * removes the ex_friend from this person's friends
     * @param ex_friend
     */
    void unfriend(const Person &ex_friend);

    /**
     *
     * @return A list of this person's friends
     */
    std::string get_friend_names() const;

    /**
     *
     * @return this person's name
     */
    std::string get_name() const ;

    /**
     * Displays this person's name and friends
     */
    void print_person() const;

private:
    std::string name;
    std::string friend_names;
};

#endif //CHAFFEY2021F_CS2G1_9_2_PERSON_H
