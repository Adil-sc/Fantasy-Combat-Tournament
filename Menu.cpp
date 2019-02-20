/*********************************************************************
** Author: Adil Chaudhry
** Date: Late December
** Description: Outlines the class functions for the Menu class
** Citation: Inspired by https://github.com/jessicaspeigel/cs162-fantasy-combat-game/blob/master/Menu.cpp
*********************************************************************/

#include "Menu.h"
#include <string>

using std::cout;
using std::cin;

/*********************************************************************
** Setter Functions
*********************************************************************/
void Menu::setMenuOptions(vector<string> newMenuOptions) {

    menuOptions.clear();
    //For each string item in the newMenuOptions vector paramater, push it to the menuOptions vector
    for (int i = 0; i < newMenuOptions.size(); i++) {
        menuOptions.push_back(newMenuOptions[i]);
    }

}

void Menu::setMenuHeader(string t) {

    menuHeader = t;

}

string Menu::getMenuHeader() {

    return menuHeader;

}


/*********************************************************************
** Default Constrtuctor
*********************************************************************/
Menu::Menu(vector<string> newMenuOptions) {

    setMenuOptions(newMenuOptions);
    setMenuHeader("");

}


/*********************************************************************
** Overloaded Constructor that accepts a menu header
*********************************************************************/
Menu::Menu(string menuHeader, vector<string> newMenuOptions) {

    setMenuHeader(menuHeader);
    setMenuOptions(newMenuOptions);

}


/*********************************************************************
** Display Menu Options list
*********************************************************************/
void Menu::displayMenuOptions() {

//Loop through the vector and display each element as a startGame option
    for (int i = 0; i < menuOptions.size(); i++) {
        //Display the list of options in the startGame
        cout << i + 1 << ". " << menuOptions[i] << "\n";
    }

}


/*********************************************************************
** Display Menu, get the users menu choice as well as input validation for that choice. Return an int repersenting the menu choice
*********************************************************************/
int Menu::displayMenu() {

    int menuChoice = 0;

    if (getMenuHeader() != "") {
        cout << "\n" << getMenuHeader() << "\n";
    }

    displayMenuOptions();
    cin >> menuChoice;
    while (cin.fail() || (menuChoice < 1 || menuChoice > menuOptions.size()) || (cin.peek() != '\r' && cin.peek() != '\n') ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please select an option between 1 and " << menuOptions.size() << std::endl;
        cout << getMenuHeader() << std::endl;
        displayMenuOptions();
        cin >> menuChoice;
    }

    return menuChoice;
}
