/*********************************************************************
** Program Name: Project 4
** Author: Adil Chaudhry
** Date: 3/1/2019
** Description: Tournament.cpp contains the class functions for the Tournament class
*********************************************************************/

#include "Tournament.h"


/*********************************************************************
** Description: Destructor
*********************************************************************/
Tournament::~Tournament() {

    cleanUp();


}


/*********************************************************************
** Description: Function that goes through player 1, player 2, and the Losers linked list and removes all values
*********************************************************************/
void Tournament::cleanUp() {

    while (!isEmpty(losers)) {
        removeFront(losers, loserTail);
    }
    while (!isEmpty(player1)) {
        removeFront(player1, player1Tail);
    }
    while (!isEmpty(player2)) {
        removeFront(player2, player2Tail);
    }

}


/*********************************************************************
** Description: Function that checks if a linked list is empty
*********************************************************************/
bool Tournament::isEmpty(CharacterLinkedList *head) {

    if (head == nullptr) {
        return true;
    } else {
        return false;
    }

}


/*********************************************************************
** Description: Function that allows a player to select their fighters and add them to the linked list
*********************************************************************/
void Tournament::addPlayers(CharacterLinkedList *&head, CharacterLinkedList *&tail) {

    int numberOfFighters;
    Character *characterChoice = nullptr;
    string characterName;

    //Captures how many fighters the user wants
    cin >> numberOfFighters;
    isValidIntRange(numberOfFighters, 1, 6, "Please enter a value between 1-6");


    //For each fighter, asks the user to select the character type and provide a name
    for (int i = 0; i < numberOfFighters; i++) {

        characterChoice = characterSelectionMenu();

        cout << "Enter the characters name" << std::endl;
        cin.ignore();
        getline(cin, characterName);


        //Configuring the Characters LinkedList
        if (isEmpty(head)) {

            head = new CharacterLinkedList(characterChoice, characterName + characterType, head, head, numberOfFighters);
            head->next = head;
            head->prev = head;


        } else {

            tail = head->prev;
            CharacterLinkedList *n = new CharacterLinkedList(characterChoice, characterName + characterType, tail, head, numberOfFighters);
            tail->next = n;
            head->prev = n;

        }

    }

}


/*********************************************************************
** Description: Function that returns a character type depending on what the player has selected
*********************************************************************/
Character *Tournament::characterSelectionMenu() {


   Character *charSelect = nullptr;
    int menuChoice = 0;
    vector<string> myMenu = {"Barbarian", "Vampire", "Blue Men", "Medusa", "Harry Potter"};
    Menu characterMenu("", myMenu);
    cout << "Select your character to battle" << std::endl;
    menuChoice = characterMenu.displayMenu();

    switch (menuChoice) {
        case 1:
            charSelect = new Barbarian();
            characterType = "[Barbarian]";
            break;
        case 2:
            charSelect = new Vampire();
            characterType = "[Vampire]";
            break;
        case 3:
            charSelect = new BlueMen();
            characterType = "[Blue Men]";
            break;
        case 4:
            charSelect = new Medusa();
            characterType = "[Medusa]";
            break;
        case 5:
            charSelect = new HarryPotter();
            characterType = "[Harry Potter]";
            break;

    }

    return charSelect;

}


/*********************************************************************
** Description: Function that prints the contents of a players roster or Losers linked list
*********************************************************************/
void Tournament::printCharacters(CharacterLinkedList *head) {

    CharacterLinkedList *temp = head;
    if (!isEmpty(temp)) {

        cout << "-------------------" << std::endl;
        do {
            cout << temp->fighter->getEnemyType() << " ";
            temp = temp->next;

        } while (temp != head);
        cout << "" << std::endl;
        cout << "-------------------" << std::endl;

    } else {
        cout << "The linked list is empty" << std::endl;
    }
    cout << "" << std::endl;

}


/*********************************************************************
** Description: Function that removes a fighter from the front of the Character linked list
*********************************************************************/
void Tournament::removeFront(CharacterLinkedList *&head, CharacterLinkedList *&tail) {

    CharacterLinkedList *temp = nullptr;


    if (!isEmpty(head)) {

        //If there is only one fighter in the linked list
        if (head->next == head) {
            delete head;
            head = nullptr;

            //If there is more than one fighter in the linked list
        } else {

            temp = head;
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;

            delete temp;

        }

    }

}


/*********************************************************************
** Description: Function moves the fighters to the Losers linked list
*********************************************************************/
void Tournament::moveToLosers(Tournament::CharacterLinkedList *&head, CharacterLinkedList *playerToAddToLosers, Tournament::CharacterLinkedList *&tail) {

    if (isEmpty(head)) {

        head = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), head, head, 0);
        head->next = head;
        head->prev = head;

        //If the Losers list already has fighters in it
    } else {

        //Stack:
        tail = head->next;
        CharacterLinkedList *n = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), tail, head, 0);
        head->prev = n;
        head = head->prev;

        tail->next = head;

        //Queue:

        /*    tail = head->prev;
             CharacterLinkedList *n = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), tail, head, 0);
             tail->next = n;
           head->prev = n;
             */
    }


}


/*********************************************************************
** Description: Function that moves a fighter to the back of the Character linked list
*********************************************************************/
void Tournament::moveToBack(Tournament::CharacterLinkedList *&head, Tournament::CharacterLinkedList *&tail) {

    CharacterLinkedList *temp = nullptr;

    if (!isEmpty(head)) {

        if (head->next == head) {
            return;
        } else {

            temp = head;
            //Head is now head > next
            head = head->next;
            temp->prev = tail;
            temp->next = head;
            head->prev = temp;

        }

    }
}


/*********************************************************************
** Description: Menu that allows the user to start or quit the game
*********************************************************************/
void Tournament::menu(bool &quit) {

    int menuuChoice = 0;
    vector<string> myMenuOptions = {"Play", "Quit"};
    Menu myMenu("", myMenuOptions);
    menuuChoice = myMenu.displayMenu();

    switch (menuuChoice) {

        case 1:
            gameStart();
            break;
        case 2:
            cleanUp();

            quit = true;
            break;

    }


}


/*********************************************************************
** Description: Primary function that starts the game torunament
*********************************************************************/
void Tournament::gameStart() {
    bool gameOver = false;
    int p1Score = 0;
    int p2Score = 0;

    //Asks player 1 how many fighters they want and adds those fithters to the linked list
    cout << "Player 1, how many characters do you want? Please enter a value between 1-6" << std::endl;
    addPlayers(player1, player1Tail);

    //Asks player 2 how many fighters they want and adds those fithters to the linked list
    cout << "Player 2, how many characters do you want? Please enter a value between 1-6" << std::endl;
    addPlayers(player2, player2Tail);

    //Main combat loop where fighters from each team fighter each other
    while (gameOver == false) {
        // cout<<isEmpty(player1)<<"*";
        while (!isEmpty(player1) && !isEmpty(player2)) {

            if (player1->fighter->getStrength() <= 0) {
                //cout << "debug:1" << std::endl;

                cout << "Player 1: " << player1->fighter->getEnemyType() << " vs " << "Player 2: " << player2->fighter->getEnemyType() << " - " << player2->fighter->getEnemyType() << " Wins!"
                     << std::endl;

                //If player 1 is defeated
                p2Score++;
                moveToLosers(losers, player1, loserTail);
                removeFront(player1, player1);

                //Health regen
                int regenHealth = rand() % 10 + 1;
                player2->fighter->setStrength(player2->fighter->getStrength() + regenHealth);
                moveToBack(player2, player2Tail);

                //If player 1 is still alive and player 2 is not out of fighters, player 1 will attack player 2
            } else if (player1->fighter->getStrength() > 0 && !isEmpty(player2)) {

                //cout << "debug:2" << std::endl;
                player2->fighter->defence(player1->fighter->attack());

            }


            if (player2->fighter->getStrength() <= 0) {

                //  cout << "debug:3" << std::endl;
                cout << "Player 1: " << player1->fighter->getEnemyType() << " vs " << "Player 2: " << player2->fighter->getEnemyType() << " - " << player1->fighter->getEnemyType() << " Wins!"
                     << std::endl;

                //If player 2 is defeated
                p1Score++;
                moveToLosers(losers, player2, loserTail);
                removeFront(player2, player1);

                //Health regen
                int regenHealth = rand() % 10 + 1;
                player1->fighter->setStrength(player1->fighter->getStrength() + regenHealth);
                moveToBack(player1, player1Tail);

                //If player 2 is still alive and player 1 is not out of fighters, player 2 will attack player 1
            } else if (player2->fighter->getStrength() > 0 && !isEmpty(player1)) {
                //  cout << "debug:4" << std::endl;
                player1->fighter->defence(player2->fighter->attack());

            }


        }

        gameOver = true;

    }

    cout << "+-----------------------+" << std::endl;
    cout << "|      FINAL SCORES     |" << std::endl;
    cout << "+-----------------------+" << std::endl;
    cout << "Score for Player 1: " << p1Score << std::endl;
    cout << "Score for Player 2: " << p2Score << std::endl;

    //Determins the winner based on each players score count
    if (p1Score > p2Score) {
        cout << "+------------------+" << std::endl;
        cout << "|   Player 1 wins  |" << std::endl;
        cout << "+------------------+" << std::endl;

    } else if (p2Score > p1Score) {
        cout << "+------------------+" << std::endl;
        cout << "|   Player 2 wins  |" << std::endl;
        cout << "+------------------+" << std::endl;

    } else {
        cout << "+------------------+" << std::endl;
        cout << "|     Its a tie    |" << std::endl;
        cout << "+------------------+" << std::endl;

    }


    int menuChoice = 0;
    vector<string> myMenuOptions = {"Back to main menu to play again or quit", "View losers"};
    Menu myMenu("", myMenuOptions);
    menuChoice = myMenu.displayMenu();
    switch (menuChoice) {

        case 1:
            gameOver = false;
            p1Score = 0;
            p2Score = 0;
            cleanUp();
            break;

        case 2:
            cout << "****LOSERS****" << std::endl;
            printCharacters(losers);
            gameOver = false;
            p1Score = 0;
            p2Score = 0;
            cleanUp();

            break;

    }

}





