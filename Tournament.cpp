//
// Created by Sandybridge W10 on 2/19/2019.
//

#include "Tournament.h"

Tournament::~Tournament() {

    cleanUp();

}

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


bool Tournament::isEmpty(CharacterLinkedList *head) {

    if (head == nullptr) {
        return true;
    } else {
        return false;
    }

}


void Tournament::addPlayers(CharacterLinkedList *&userPlayer, CharacterLinkedList *&tail) {

    int numberOfFighters;
    Character *characterChoice;
    string characterName;

    // cout << "Player 1, how many fighters would you like?" << std::endl;
    cin >> numberOfFighters;

    for (int i = 0; i < numberOfFighters; i++) {

        characterChoice = characterSelectionMenu();
        cout << "Enter the characters name" << std::endl;
        cin.ignore();
        getline(cin, characterName);

        // userPlayer = new CharacterLinkedList(characterChoice,characterName,userPlayer);

        //Configuring the Characters LinkedList
        if (isEmpty(userPlayer)) {

            userPlayer = new CharacterLinkedList(characterChoice, characterName + characterType, userPlayer, userPlayer, numberOfFighters);
            userPlayer->next = userPlayer;
            userPlayer->prev = userPlayer;

        } else {

            tail = userPlayer->prev;
            CharacterLinkedList *n = new CharacterLinkedList(characterChoice, characterName + characterType, tail, userPlayer, numberOfFighters);
            tail->next = n;
            userPlayer->prev = n;

        }


    }


}

//Returns a character type depending on what the player has selected
Character *Tournament::characterSelectionMenu() {
    Character *charSelect;
    int menuChoice = 0;
    vector<string> myMenu = {"Barbarian", "Vampire", "Blue Men", "Medusa", "Harry Potter"};
    Menu characterMenu("", myMenu);
    cout << "Select your character to battle" << std::endl;
    menuChoice = characterMenu.displayMenu();
    switch (menuChoice) {
        case 1:
            charSelect = new Barbarian;
            characterType = "[Barbarian]";
            break;
        case 2:
            charSelect = new Vampire;
            characterType = "[Vampire]";
            break;
        case 3:
            charSelect = new BlueMen;
            characterType = "[Blue Men]";
            break;
        case 4:
            charSelect = new Medusa;
            characterType = "[Medusa]";
            break;
        case 5:
            charSelect = new HarryPotter;
            characterType = "[Harry Potter]";
            break;

    }
    return charSelect;
}


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

void Tournament::removeFront(CharacterLinkedList *&userPlayer, CharacterLinkedList *&tail) {

    CharacterLinkedList *temp = nullptr;


    if (!isEmpty(userPlayer)) {

        if (userPlayer->next == userPlayer) {
            delete userPlayer;
            userPlayer = nullptr;
        } else {

            temp = userPlayer;
            userPlayer = userPlayer->next;
            userPlayer->prev = temp->prev;
            temp->prev->next = userPlayer;

            delete temp;

        }

    }



    /*if(isEmpty(userPlayer)){
        return;
    } else{

        temp = userPlayer;

        userPlayer = userPlayer->next;
        userPlayer->prev = tail;
        temp->prev->next = userPlayer;

        delete temp;

    }*/


}

void Tournament::moveToLosers(Tournament::CharacterLinkedList *&userPlayer, CharacterLinkedList *playerToAddToLosers, Tournament::CharacterLinkedList *&tail) {

    if (isEmpty(userPlayer)) {

        userPlayer = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), userPlayer, userPlayer, 0);
        userPlayer->next = userPlayer;
        userPlayer->prev = userPlayer;

    } else {

        //Stack:
        tail = userPlayer->next;
        CharacterLinkedList *n = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), tail, userPlayer, 0);
        userPlayer->prev = n;
        userPlayer = userPlayer->prev;

        tail->next = userPlayer;

        //Queue:

        /*    tail = userPlayer->prev;
             CharacterLinkedList *n = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), tail, userPlayer, 0);
             tail->next = n;
           userPlayer->prev = n;
             */
    }


}


void Tournament::moveToBack(Tournament::CharacterLinkedList *&userPlayer, Tournament::CharacterLinkedList *&tail) {


    CharacterLinkedList *temp = nullptr;


    if (!isEmpty(userPlayer)) {

        if (userPlayer->next == userPlayer) {
            return;
        } else {

            temp = userPlayer;
            //Head is now head > next
            userPlayer = userPlayer->next;
            temp->prev = tail;
            temp->next = userPlayer;
            userPlayer->prev = temp;
            //addPlayers(temp, tail);
        }

    }
}


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


void Tournament::gameStart() {
    bool gameOver = false;
    int p1Score = 0;
    int p2Score = 0;

//    printCharacters(player1);
    //   printCharacters(player2);
    // cout<<"Removing from player 1 linked list"<<std::endl;
    // removeFront(player1,player1Tail);
    // printCharacters(player1);

//    cout << "Move front to back" << std::endl;
    //   moveToBack(player1, player1Tail);
    //  printCharacters(player1);

    cout << "Player 1, how many characters do you want?" << std::endl;
    addPlayers(player1, player1Tail);

    cout << "Player 2, how many characters do you want?" << std::endl;
    addPlayers(player2, player2Tail);

    /*       cout<<"Player1 contains"<<std::endl;
       printCharacters(player1);
         cout<<player1->fighter->getEnemyType()<<" Fighter<<std::endl;";
         cout<<"Move player 1 value to losers"<<std::endl;
         moveToLosers(losers, player1, loserTail);
         cout<<"Player 1 list still contains: "<<std::endl;
         printCharacters(player1);
         cout<<"And losers list now contains"<<std::endl;
         printCharacters(losers);
         cout<<"Move player 1 value to back"<<std::endl;
         moveToBack(player1,player1Tail);
         printCharacters(player1);
         cout<<player1->fighter->getEnemyType()<<" Fighter<<std::endl;";
         cout<<"rempve player2 value from front"<<std::endl;
          removeFront(player1,player1Tail);
         printCharacters(player1);
   */

    //Main comabt loop

    while (gameOver == false) {
        // cout<<isEmpty(player1)<<"*";
        while (!isEmpty(player1) && !isEmpty(player2)) {

            if (player1->fighter->getStrength() <= 0) {
                cout << "debug:1" << std::endl;
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
                // cout<<isEmpty(player1)<<"***a";
            } else if (player1->fighter->getStrength() > 0 && !isEmpty(player2)) {
                cout << "debug:2" << std::endl;
                player2->fighter->defence(player1->fighter->attack());

            }


            if (player2->fighter->getStrength() <= 0) {
                cout << "debug:3" << std::endl;
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
                // cout<<isEmpty(player1)<<"***b";
            } else if (player2->fighter->getStrength() > 0 && !isEmpty(player1)) {
                cout << "debug:4" << std::endl;
                player1->fighter->defence(player2->fighter->attack());

            }


        }
        gameOver = true;

    }

    cout<<"+-----------------------+"<<std::endl;
    cout<<"|      FINAL SCORES     |"<<std::endl;
    cout<<"+-----------------------+"<<std::endl;
    cout << "Score for Player 1: " << p1Score << std::endl;
    cout << "Score for Player 2: " << p2Score << std::endl;

    if (p1Score > p2Score) {
      cout<<"+------------------+"<<std::endl;
      cout<<"|   Player 1 wins  |"<<std::endl;
      cout<<"+------------------+"<<std::endl;

    } else if (p2Score > p1Score) {
        cout<<"+------------------+"<<std::endl;
        cout<<"|   Player 2 wins  |"<<std::endl;
        cout<<"+------------------+"<<std::endl;

    } else {
        cout<<"+------------------+"<<std::endl;
        cout<<"|     Its a tie    |"<<std::endl;
        cout<<"+------------------+"<<std::endl;

    }


    int menuChoice = 0;
    vector<string> myMenuOptions = {"Back to main menu to play again or quit", "View losers"};
    Menu myMenu("", myMenuOptions);
    menuChoice = myMenu.displayMenu();
    switch (menuChoice) {

        case 1: {

            gameOver = false;
            p1Score = 0;
            p2Score = 0;
            cleanUp();

        }
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





