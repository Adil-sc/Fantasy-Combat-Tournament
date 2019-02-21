//
// Created by Sandybridge W10 on 2/19/2019.
//

#include "Tournament.h"


bool Tournament::isEmpty() {

    if(head == nullptr){
        return true;
    }else{
        return false;
    }

}



void Tournament::addPlayers(Tournament::CharacterLinkedList *&userPlayer) {

    int numberOfFighters;
    Character *characterChoice;
    string characterName;

    cout<<"Player 1, how many fighters would you like?"<<std::endl;
    cin>>numberOfFighters;

    for(int i = 0; i <numberOfFighters; i++){

        characterChoice = characterSelectionMenu();
        cout<<"Enter the characters name"<<std::endl;
        cin.ignore();
        getline(cin,characterName);

        userPlayer = new CharacterLinkedList(characterChoice,characterName,userPlayer);

    }

//Configuring the Characters LinkedList
    if(isEmpty()){

        player1 = userPlayer;
        player1->next = player1;
        player1->prev = player1;


    }



}

//Returns a character type depending on what the player has selected
Character* Tournament::characterSelectionMenu() {
    int menuChoice = 0;
    vector<string> myMenu = {"Vampire(barbarian for now)", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
    Menu characterMenu("", myMenu);
    cout << "Player 1, select your character to battle" << std::endl;
    menuChoice = characterMenu.displayMenu();
    switch (menuChoice) {
        case 1:
            return new Barbarian;
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

}


void Tournament::printCharacters() {

   CharacterLinkedList *temp = head;
    if(!isEmpty()) {

        cout << "-------------------" << std::endl;
        do {
            cout << temp->fighter->getEnemyType()<<" ";
            temp = temp->next;

        } while (temp != head);
        cout<<""<<std::endl;
        cout << "-------------------" << std::endl;

    } else{
        cout<<"The linked list is empty"<<std::endl;
    }
    cout<<""<<std::endl;

}



void Tournament::gameStart() {

    addPlayers(player1);
    printCharacters();




}





