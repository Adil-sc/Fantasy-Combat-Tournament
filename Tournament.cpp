//
// Created by Sandybridge W10 on 2/19/2019.
//

#include "Tournament.h"


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

            userPlayer = new CharacterLinkedList(characterChoice, characterName, userPlayer, userPlayer, numberOfFighters);
            userPlayer->next = userPlayer;
            userPlayer->prev = userPlayer;

        } else {

            tail = userPlayer->prev;
            CharacterLinkedList *n = new CharacterLinkedList(characterChoice, characterName, tail, userPlayer, numberOfFighters);
            tail->next = n;
            userPlayer->prev = n;

        }


    }


}

//Returns a character type depending on what the player has selected
Character *Tournament::characterSelectionMenu() {
    Character *charSelect;
    int menuChoice = 0;
    vector<string> myMenu = {"Vampire(barbarian for now)", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
    Menu characterMenu("", myMenu);
    cout << "Player 1, select your character to battle" << std::endl;
    menuChoice = characterMenu.displayMenu();
    switch (menuChoice) {
        case 1:
            charSelect = new Barbarian;
            break;
            /*   case 2:
                   player1 = new Barbarian;
                   break;
               case 3:
                   player1 = new BlueMen;
                   break;
               case 4:
                   player1 = new Medusa;
                   break;
               case 5:
                   player1 = new HarryPotter;
                   break;
           */
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

        tail = userPlayer->prev;
        CharacterLinkedList *n = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), tail, userPlayer, 0);
        tail->next = n;
        userPlayer->prev = n;

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

void Tournament::gameStart() {
    bool gameOver = false;
    int p1Counter = 0;
    int p2Counter = 0;

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

 CharacterLinkedList *temp1 = player1;
    CharacterLinkedList *temp2 = player2;
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
        cout<<isEmpty(player1)<<"*";
        while (!isEmpty(player1) && !isEmpty(player2)){

            if(player1->fighter->getStrength()<=0){
                cout << "debug:1" << std::endl;
                //If player 1 is defeated

                moveToLosers(losers,player1,loserTail);
                removeFront(player1,player1);
                moveToBack(player2,player2Tail);
                cout<<isEmpty(player1)<<"***a";
            }else if(player1->fighter->getStrength()>0 && !isEmpty(player2)){
                cout << "debug:2" << std::endl;
                player2->fighter->defence(player1->fighter->attack());

            }


            if(player2->fighter->getStrength()<=0){
                cout << "debug:3" << std::endl;
                //If player 2 is defeated

                moveToLosers(losers,player2,loserTail);
                removeFront(player2,player1);
                moveToBack(player1,player1Tail);
                cout<<isEmpty(player1)<<"***b";
            }else if(player2->fighter->getStrength()>0 && !isEmpty(player1)){
                cout << "debug:4" << std::endl;
                player1->fighter->defence(player2->fighter->attack());

            }


        }
        gameOver = true;
    }

    cout << "Losers list" << std::endl;
    //printCharacters(temp1);
    //cout << "*****" << std::endl;
    printCharacters(losers);


}





