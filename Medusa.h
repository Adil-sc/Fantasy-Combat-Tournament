/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: Medussa.h is the class definition file for the Medussa class
*********************************************************************/

#ifndef PROJECT3_MEDUSA_H
#define PROJECT3_MEDUSA_H

#include "Character.h"

class Medusa: public Character {

private:
    int firstDieAttack;
    int secondDieAttack;
    int totalAttackPower;

    int firstDieDefence;
    int totalDefencePower;

    int damage;


public:

    Medusa();
    ~Medusa(){}

    virtual int attack();
    virtual void defence(int attackersTotalAttackPower);


};


#endif //PROJECT3_MEDUSA_H
