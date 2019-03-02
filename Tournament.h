//
// Created by Sandybridge W10 on 2/19/2019.
//

#ifndef PROJECT4_TOURNAMENT_H
#define PROJECT4_TOURNAMENT_H

#include "Character.h"
#include <iostream>
#include "Menu.h"
#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "HarryPotter.h"
#include "inputValidation.h"
#include "Medusa.h"
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::string;
using std::vector;

class Tournament {
private:

    string characterType= "";

    struct CharacterLinkedList{

        CharacterLinkedList *next;
        CharacterLinkedList *prev;
        Character *fighter;
        int numberOfFighers;

        CharacterLinkedList(Character *fighter,string characterName,CharacterLinkedList *prev, CharacterLinkedList *next,int numberOfFighters){
            this->fighter = fighter;
            this->next = next;
            this->prev = prev;
            fighter->setEnemyType(characterName);
            this->numberOfFighers = numberOfFighters;
        }


    };

  //  CharacterLinkedList *head;
 //   CharacterLinkedList *tail;
    CharacterLinkedList *player1Tail;
    CharacterLinkedList *player2Tail;
    CharacterLinkedList *loserTail;

    CharacterLinkedList *player1;
    CharacterLinkedList *player2;
    CharacterLinkedList *losers;



public:

    Tournament(){

        player1Tail = nullptr;
        player2Tail = nullptr;
      loserTail = nullptr;
        player1 = nullptr;
       player2 = nullptr;
     losers = nullptr;



    }
    ~Tournament();

    bool isEmpty(CharacterLinkedList *head);
    int getFront();
    void cleanUp();
    void menu(bool &quit);
    void removeFront(CharacterLinkedList *&userPlayer, CharacterLinkedList *&tail);
    void moveToBack(CharacterLinkedList *&userPlayer, CharacterLinkedList *&tail);
    void moveToLosers(CharacterLinkedList *&userPlayer,CharacterLinkedList *playerToAddToLosers ,CharacterLinkedList *&tail);
    void gameStart();
    void addPlayers(CharacterLinkedList *&userPlayer,CharacterLinkedList *&tail);
    Character *characterSelectionMenu();
    void printCharacters(CharacterLinkedList *head);



};





#endif //PROJECT4_TOURNAMENT_H
