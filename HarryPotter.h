/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: HarryPotter.h is the class definition file for the Medussa class
*********************************************************************/

#ifndef PROJECT3_HARRYPOTTER_H
#define PROJECT3_HARRYPOTTER_H

#include "Character.h"

class HarryPotter: public Character {


private:

    int firstDieAttack;
    int secondDieAttack;
    int totalAttackPower;

    int firstDieDefence;
    int secondDieDefence;
    int totalDefencePower;

    int damage;
    bool secondLifeUsed = false;

public:
    HarryPotter();
    ~HarryPotter(){}

    virtual int attack();
    virtual void defence(int attackersTotalAttackPower);

};


#endif //PROJECT3_HARRYPOTTER_H
