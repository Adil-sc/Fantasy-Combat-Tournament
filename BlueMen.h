/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: BlueMen.h is the class definition file for the BlueMen class
*********************************************************************/

#ifndef PROJECT3_BLUEMEN_H
#define PROJECT3_BLUEMEN_H

#include "Character.h"

class BlueMen: public Character {

private:

    int firstDieAttack;
    int secondDieAttack;
    int totalAttackPower;

    int firstDieDefence;
    int secondDieDefence;
    int thirdDieDefence;
    int totalDefencePower;

    int damage;


public:

    BlueMen();
    ~BlueMen(){}

    virtual int attack();
    virtual void defence(int attackersTotalAttackPower);


};


#endif //PROJECT3_BLUEMEN_H
