//
// Created by Sandybridge W10 on 2/19/2019.
//

#include "Tournament.h"


bool Tournament::isEmpty(CharacterLinkedList *head) {

    if(head == nullptr){
        return true;
    }else{
        return false;
    }

}

void Tournament::addBack() {






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

       // userPlayer = new CharacterLinkedList(characterChoice,characterName,userPlayer);

        //Configuring the Characters LinkedList
        if(isEmpty(userPlayer)){

            userPlayer = new CharacterLinkedList(characterChoice,characterName,userPlayer,userPlayer,numberOfFighters);
            userPlayer->next = userPlayer;
            userPlayer->prev = userPlayer;

//This bit didnt really work. Only seems to be adding one to the node.
        } else{

            tail = userPlayer->prev;
            CharacterLinkedList *n = new CharacterLinkedList(characterChoice,characterName,tail,userPlayer,numberOfFighters);
            tail->next = n;
            userPlayer->prev = n;

        }









    }





}

//Returns a character type depending on what the player has selected
Character* Tournament::characterSelectionMenu() {
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
    if(!isEmpty(temp)) {

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
    bool gameOver = false;
    addPlayers(player1);
    addPlayers(player2);
    printCharacters(player1);
    printCharacters(player2);


    CharacterLinkedList *temp1 = player1;
    CharacterLinkedList *temp2 = player2;

    while (gameOver == false){
        if(temp1->fighter->getStrength()<= 0 || gameOver == true){
            temp1->numberOfFighers = temp1->numberOfFighers-1;
            if(temp1->numberOfFighers <=0){
                gameOver = true;
            }else{
            temp1 = temp1->next;
         //   cout<<temp1->numberOfFighers<<"********";
            }

        }else{
            temp2->fighter->defence(temp1->fighter->attack());
        }

        if(temp2->fighter->getStrength()<=0 || gameOver == true){
            temp2->numberOfFighers = temp2->numberOfFighers-1;
            if(temp2->numberOfFighers <=0){
                gameOver = true;
            }else{

            temp2 = temp2->next;
          //  cout<<temp2->numberOfFighers<<"$$$$$$$";
            }
        }else{
            temp1->fighter->defence(temp2->fighter->attack());

        }




    }


}





