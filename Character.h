/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: Character.h is the class definition file for the Character class
*********************************************************************/

#ifndef PROJECT3_CHARACTER_H
#define PROJECT3_CHARACTER_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::string;
using std::cout;

class Character {

protected:

    string enemyType;

    int armor;
    int strength;


public:

    virtual int attack() = 0;
    virtual void defence(int attackersTotalAttackPower) = 0;

    //https://stackoverflow.com/questions/10024796/c-virtual-functions-but-no-virtual-destructors
    virtual ~Character(){}

    //Constructor
    Character(){ srand(time(0));}
    Character(string NewEnemyType,int NewArmor, int NewStrength)
        :enemyType(NewEnemyType),armor(NewArmor),strength(NewStrength)
        {

        }

    //Setters
    void setArmor(int armor){this->armor = armor;}
    void setStrength(int strength){this->strength = strength;}

    //Getters
    string getEnemyType(){return enemyType;}
    void setEnemyType(string enemyType){this->enemyType = enemyType;}
    int getAmor(){ return armor;}
    int getStrength(){ return strength;}

};


#endif //PROJECT3_CHARACTER_H
