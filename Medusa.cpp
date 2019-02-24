/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: Medussa.cpp contains the class functions for the Medussa class
*********************************************************************/
#include "Medusa.h"


/*********************************************************************
** Constructor that uses an initalizer list to set the characters Name, Armor, and Strength point values
*********************************************************************/
Medusa::Medusa()
    :Character("Medusa",3,8)
{

}


/*********************************************************************
** Override Base class attack function
*********************************************************************/
int Medusa::attack() {

    //Calculate a random value for each attackers die
    firstDieAttack = rand()%6 + 1;
    secondDieAttack = rand()%6 + 1;

    totalAttackPower = firstDieAttack + secondDieAttack;

    //Special ability: Glare
    //If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life.
    if(totalAttackPower == 12){
        cout<<this->enemyType<<" rolls a 12!"<<this->getEnemyType()<<" activates Glare, It is supper effective"<<std::endl;

        //Set a artifically high attack power that will kill any character
        totalAttackPower = 100;

    }else{

        //Output the value of each die roll and the total attack power (which is the sum of all die rolls)
        cout<<this->enemyType<<" attacks! Rolls a "<<firstDieAttack<<" and "<<secondDieAttack<<" for a total attack power of "<<totalAttackPower<<std::endl;
    }

    return totalAttackPower;

}


/*********************************************************************
** Override Base class defence function. Takes as a parameter an int which is to represent the total attack power returned from the Attack() function
*********************************************************************/
void Medusa::defence(int attackersTotalAttackPower) {

    //Outputs the basic stats of the defender including the current Armor and Strength points
    cout<<this->getEnemyType()<<"Stats:"<<"[Armor: "<<this->getAmor()<<", Strength points: "<<this->getStrength()<<"]"<<std::endl;

    //Calculates a random value for each defenders die
    firstDieDefence = rand()% 6 + 1;
    totalDefencePower = firstDieDefence;

    //Calculates the inflicted damage
    damage = attackersTotalAttackPower - totalDefencePower - armor;

    //Outputs the value for each die roll and the total defence power (which is the sum of all die rolls)
    cout<<this->getEnemyType()<<" defends, rolls a "<<firstDieDefence<<" for a total defensive power of "<<totalDefencePower<<std::endl;

    //If the damage <= 0, we say that the attack was too weak to inflict any damage
    if (damage <= 0 ){
        cout<<"The attack was ineffective! "<<this->getEnemyType()<<" is not phased."<<std::endl;
    }else{

        //If the attack was >=0, we subtract the damage from the characters current Strength points
        setStrength(this->strength - damage);

        //If the current Strength is <= 0, we say the character has been defeated
        if(this->getStrength() <= 0){

            cout << this->getEnemyType() << " took " << damage << " damage, it has been defeated!" << std::endl;

        }else {
            //Else, we output how much damage the character took, and what their Strength points are after
            cout << this->getEnemyType() << " took " << damage << " damage, its strength has been reduced to "
                 << this->getStrength() << std::endl;
        }
    }

}