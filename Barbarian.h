/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: Barbarian.h is the class definition file for the Barbarian class
*********************************************************************/
#ifndef PROJECT3_BARBARIAN_H
#define PROJECT3_BARBARIAN_H

#include "Character.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cout;

class Barbarian: public Character {

private:

    int firstDieAttack;
    int secondDieAttack;
    int totalAttackPower;

    int firstDieDefence;
    int secondDieDefence;
    int totalDefencePower;

    int damage;

public:
    Barbarian();
    ~Barbarian(){}

   virtual int attack();
   virtual void defence(int attackersTotalAttackPower);

};


#endif //PROJECT3_BARBARIAN_H
