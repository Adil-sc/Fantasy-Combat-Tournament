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

    CharacterLinkedList *head;
    CharacterLinkedList *tail;

    CharacterLinkedList *player1 = nullptr;
    CharacterLinkedList *player2 = nullptr;
    CharacterLinkedList *loserr = nullptr;



public:

    Tournament(){head = nullptr; tail = nullptr;}

    bool isEmpty(CharacterLinkedList *head);
    void addBack(int val);
    int getFront();
    void addBack();
    void gameStart();
    void addPlayers(CharacterLinkedList *&userPlayer);
    Character *characterSelectionMenu();
    void printCharacters(CharacterLinkedList *head);


};





#endif //PROJECT4_TOURNAMENT_H
