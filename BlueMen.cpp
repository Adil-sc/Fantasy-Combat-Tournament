/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: BlueMen.cpp contains the class functions for the BlueMen class
*********************************************************************/

#include "BlueMen.h"


/*********************************************************************
** Constructor that uses an initalizer list to set the characters Name, Armor, and Strength point values
*********************************************************************/
BlueMen::BlueMen()
        : Character("Blue Men", 3, 12) {


}


/*********************************************************************
** Override Base class attack function
*********************************************************************/
int BlueMen::attack() {

    //Calculate a random value for each attackers die
    firstDieAttack = rand() % 10 + 1;
    secondDieAttack = rand() % 10 + 1;
    totalAttackPower = firstDieAttack + secondDieAttack;

    //Output the value of each die roll and the total attack power (which is the sum of all die rolls)
    cout << this->enemyType << " attacks! Rolls a " << firstDieAttack << " and " << secondDieAttack << " for a total attack power of " << totalAttackPower << std::endl;

    return totalAttackPower;

}


/*********************************************************************
** Override Base class defence function. Takes as a parameter an int which is to represent the total attack power returned from the Attack() function
*********************************************************************/
void BlueMen::defence(int attackersTotalAttackPower) {

    //Outputs the basic stats of the defender including the current Armor and Strength points
    cout << this->getEnemyType() << "Stats:" << "[Armor: " << this->getAmor() << ", Strength points: " << this->getStrength() << "]" << std::endl;


    //Special ability: Mob
    //Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense
    if (this->getStrength() > 8) {

        firstDieDefence = rand() % 6 + 1;
        secondDieDefence = rand() % 6 + 1;
        thirdDieDefence = rand() % 6 + 1;
        totalDefencePower = firstDieDefence + secondDieDefence + thirdDieDefence;
        cout << "Strength points near full, defending with 3 die" << std::endl;

    } else if (this->getStrength() >= 4) {
        firstDieDefence = rand() % 6 + 1;
        secondDieDefence = rand() % 6 + 1;
        totalDefencePower = firstDieDefence + secondDieDefence;
        cout << "Strength points low, defending with 2 die" << std::endl;
    } else if (this->getStrength() < 4) {
        firstDieDefence = rand() & 6 + 1;
        totalDefencePower = firstDieDefence;
        cout << "Strength points critical, defending with 1 die" << std::endl;
    }

    //Calculates the inflicted damage
    damage = attackersTotalAttackPower - totalDefencePower - armor;

    //Outputs the value for each die roll and the total defence power (which is the sum of all die rolls)
    cout << this->getEnemyType() << " defends, rolls a " << firstDieDefence << " and " << secondDieDefence << " and " << thirdDieDefence << ". For a total defensive power of " << totalDefencePower
         << std::endl;

    //If the damage <= 0, we say that the attack was too weak to inflict any damage
    if (damage <= 0) {
        cout << "The attack was ineffective! " << this->getEnemyType() << " is not phased." << std::endl;
    } else {

        //Subtract the value from the defenders strength points.
        setStrength(this->strength - damage);

        //If the current Strength is <= 0, we say the character has been defeated
        if (this->getStrength() <= 0) {

            cout << this->getEnemyType() << " took " << damage << " damage, it has been defeated!" << std::endl;

            //Else, we output how much damage the character took, and what their Strength points are after
        } else {
            cout << this->getEnemyType() << " took " << damage << " damage, its strength has been reduced to "
                 << this->getStrength() << std::endl;
        }

    }

}