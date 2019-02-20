//
// Created by Sandybridge W10 on 2/19/2019.
//

#ifndef PROJECT4_TOURNAMENT_H
#define PROJECT4_TOURNAMENT_H

#include "Character.h"

class Tournament {
private:
    struct CharacterLinkedList{

        CharacterLinkedList *next;
        CharacterLinkedList *prev;
        Character *fighter;

        CharacterLinkedList(Character *fighter, CharacterLinkedList *next){
            this->fighter = fighter;
            this->next = next;
        }


    };

    CharacterLinkedList *head;
    CharacterLinkedList *tail;

public:

    Tournament(){head = nullptr; tail = nullptr;}

    bool isEmpty();
    void addBack(int val);
    int getFront();

};





#endif //PROJECT4_TOURNAMENT_H
