//
// Created by Sandybridge W10 on 2/19/2019.
//

#ifndef PROJECT4_TOURNAMENT_H
#define PROJECT4_TOURNAMENT_H

#include "Character.h"
#include <iostream>
#include "Menu.h"
#include "Barbarian.h"
#include <string>


using std::cin;
using std::cout;
using std::string;

class Tournament {
private:
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

    CharacterLinkedList *player1 = nullptr;
    CharacterLinkedList *player2 = nullptr;
    CharacterLinkedList *losers = nullptr;



public:

    Tournament(){}

    bool isEmpty(CharacterLinkedList *head);
    int getFront();
    void removeFront(CharacterLinkedList *&userPlayer, CharacterLinkedList *&tail);
    void moveToBack(CharacterLinkedList *&userPlayer, CharacterLinkedList *&tail);
    void moveToLosers(CharacterLinkedList *&userPlayer,CharacterLinkedList *playerToAddToLosers ,CharacterLinkedList *&tail);
    void gameStart();
    void addPlayers(CharacterLinkedList *&userPlayer,CharacterLinkedList *&tail);
    Character *characterSelectionMenu();
    void printCharacters(CharacterLinkedList *head);


};





#endif //PROJECT4_TOURNAMENT_H
