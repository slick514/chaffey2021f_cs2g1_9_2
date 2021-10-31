//
// Created by Justin Gries on 10/30/2021.
//

#ifndef CHAFFEY2021F_CS2G1_9_2_MENU_H
#define CHAFFEY2021F_CS2G1_9_2_MENU_H

#include <vector>
#include <string>

static const std::string LINE_SEPARATOR = "______________________________"; /* NOLINT */

class Menu {
public:
    explicit Menu(const std::string &title);
    void display_menu(const int &num_columns) const;
    void add_item(std::string &menu_item);
    static std::string build_menu_string(const std::string &beginning, const char &middle, const std::string &end);
private:
    std::string menu_title;
    int field_w = 0;
    std::vector<std::string> menu_items;
};


#endif //CHAFFEY2021F_CS2G1_9_2_MENU_H
