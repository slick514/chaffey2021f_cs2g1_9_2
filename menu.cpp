//
// Created by Justin Gries on 10/30/2021.
//

#include <iostream>
#include <iomanip>
#include "menu.h"

using namespace std;

void Menu::display_menu(const int &num_columns) const{
    int counter = 0;
    cout << left;
    cout << LINE_SEPARATOR << endl<< this->menu_title << endl;
    bool first = true;
    for (const string &item : this->menu_items){
        switch(counter % num_columns){
            case 0:
                if(!first){
                    cout << endl;
                }
                first = false;
                cout << "|  " << setw(this->field_w) <<  item << "  |";
                counter = 0;
                break;
            default: {
                cout << "  " << setw(this->field_w) << item << "  |";
            }
        }
        counter ++;
    }
    cout << endl;
}

Menu::Menu(const std::string &title) {
    this->menu_title = title;
}

void Menu::add_item(string &menu_item) {
    this->menu_items.push_back(menu_item);
    if(this->field_w < menu_item.length())
        this->field_w = (int)menu_item.length();
}

std::string Menu::build_menu_string(const string &beginning, const char &middle, const string &end) {
    stringstream stream;
    stream << beginning << middle << end;
    return stream.str();
}
