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

void Tournament::moveToLosers(Tournament::CharacterLinkedList *&userPlayer,CharacterLinkedList *playerToAddToLosers, Tournament::CharacterLinkedList *&tail) {

    if (isEmpty(userPlayer)) {

        userPlayer = new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), userPlayer, userPlayer, 0);
        userPlayer->next = userPlayer;
        userPlayer->prev = userPlayer;

    } else {

        tail = userPlayer->prev;
        CharacterLinkedList *n =  new CharacterLinkedList(playerToAddToLosers->fighter, playerToAddToLosers->fighter->getEnemyType(), tail, userPlayer, 0);
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


//    printCharacters(player1);
 //   printCharacters(player2);
    // cout<<"Removing from player 1 linked list"<<std::endl;
    // removeFront(player1,player1Tail);
    // printCharacters(player1);

//    cout << "Move front to back" << std::endl;
 //   moveToBack(player1, player1Tail);
  //  printCharacters(player1);

    cout<<"Player 1, how many characters do you want?"<<std::endl;
    addPlayers(player1, player1Tail);

    cout<<"Player 2, how many characters do you want?"<<std::endl;
    addPlayers(player2, player2Tail);

    CharacterLinkedList *temp1 = player1;
    CharacterLinkedList *temp2 = player2;

    //Main comabt loop
    while (gameOver == false) {
        //If player 1s strength is 0 or the game is over, subtract fighter count from roster,
        if (temp1->fighter->getStrength() <= 0 || gameOver == true) {
            temp1->numberOfFighers = temp1->numberOfFighers - 1;


            //Move player 1 figher to losers list
            moveToLosers(losers,temp1,player1Tail);


            if (temp1->numberOfFighers <= 0) {
                gameOver = true;
            } else {



                //If player 1 still has fighters, select the next fighter in the roster
                temp1 = temp1->next;

                //Restore health for players 2 fighter before the next fighert in the roster is selected
                int regenHealth = rand()%10 + 1;
                temp2->fighter->setStrength(temp2->fighter->getStrength()+regenHealth);
            //    cout<<temp2->fighter->getEnemyType()<<" goes to the back of the roster and regenerates "<<regenHealth<<" strength points"<<std::endl;

                // Pick the next fighter in the roster for player 2s team
                temp2 = temp2->next;

                //   cout<<temp1->numberOfFighers<<"********";
            }

        } else {
            temp2->fighter->defence(temp1->fighter->attack());
        }

        if (temp2->fighter->getStrength() <= 0 || gameOver == true) {
            temp2->numberOfFighers = temp2->numberOfFighers - 1;

            //Move player 2 figher to losers list
            moveToLosers(losers,temp2,loserTail);

            if (temp2->numberOfFighers <= 0) {
                gameOver = true;
            } else {




                //If player 2 still has fighters, select the next fighter in the roster
                temp2 = temp2->next;

                //Restore health for players 2 fighter before the next fighert in the roster is selected
                int regenHealth = rand()%10 + 1;
                temp1->fighter->setStrength(temp1->fighter->getStrength()+regenHealth);
              //  cout<<temp1->fighter->getEnemyType()<<" goes to the back of the roster and regenerates "<<regenHealth<<" strength points"<<std::endl;

                //Pick the next fighter in the roster for player 1s team
                temp1 = temp1->next;

                //  cout<<temp2->numberOfFighers<<"$$$$$$$";
            }
        } else {
            temp1->fighter->defence(temp2->fighter->attack());

        }


    }

    cout<<"Losers list"<<std::endl;
    printCharacters(temp1);
    cout<<"*****"<<std::endl;
    printCharacters(losers);


}





