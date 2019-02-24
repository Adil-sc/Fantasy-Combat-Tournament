/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: Vampire.h is the class definition file for the Vampire class
*********************************************************************/

#ifndef PROJECT3_VAMPIRE_H
#define PROJECT3_VAMPIRE_H

#include "Character.h"

class Vampire: public Character{

private:

    int firstDieAttack;
    int totalAttackPower;

    int firstDieDefence;
    int totalDefencePower;

    int damage;


public:

    Vampire();
    ~Vampire(){}

    virtual int attack();
    virtual void defence(int attackersTotalAttackPower);


};


#endif //PROJECT3_VAMPIRE_H
