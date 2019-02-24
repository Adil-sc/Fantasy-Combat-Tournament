/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: Barbarian.cpp contains the class functions for the Barbarian class
*********************************************************************/

#include "Barbarian.h"


/*********************************************************************
** Constructor that uses an initalizer list to set the characters Name, Armor, and Strength point values
*********************************************************************/
Barbarian::Barbarian()
        : Character("Barbarian", 0, 12) {


}


/*********************************************************************
** Override Base class attack function
*********************************************************************/
int Barbarian::attack() {

    //Calculate a random value for each attackers die
    firstDieAttack = rand() % 6 + 1;
    secondDieAttack = rand() % 6 + 1;

    totalAttackPower = firstDieAttack + secondDieAttack;
    //Output the value of each die roll and the total attack power (which is the sum of all die rolls)
  //  cout << this->enemyType << " attacks! rolls a " << firstDieAttack << " and " << secondDieAttack << " for a total attack power of " << totalAttackPower << std::endl;

    return totalAttackPower;

}


/*********************************************************************
** Override Base class defence function. Takes as a parameter an int which is to represent the total attack power returned from the Attack() function
*********************************************************************/
void Barbarian::defence(int attackersTotalAttackPower) {

    //Outputs the basic stats of the defender including the current Armor and Strength points
  //  cout << this->getEnemyType() << "Stats:" << "[Armor: " << this->getAmor() << ", Strength points: " << this->getStrength() << "]" << std::endl;

    //Calculates a random value for each defenders die
    firstDieDefence = rand() % 6 + 1;
    secondDieDefence = rand() % 6 + 1;

    totalDefencePower = firstDieDefence + secondDieDefence;

    //Calculates the inflicted damage
    damage = attackersTotalAttackPower - totalDefencePower - armor;

    //Outputs the value for each die roll and the total defence power (which is the sum of all die rolls)
 //   cout << this->getEnemyType() << " defends, rolls a " << firstDieDefence << " and " << secondDieDefence << ". For a total defensive power of " << totalDefencePower << std::endl;

    //If the damage <= 0, we say that the attack was too weak to inflict any damage
    if (damage <= 0) {
      //  cout << "The attack was ineffective! " << this->getEnemyType() << " is not phased." << std::endl;
    } else {

        //If the attack was >=0, we subtract the damage from the characters current Strength points
        setStrength(this->strength - damage);

        //If the current Strength is <= 0, we say the character has been defeated
        if (this->getStrength() <= 0) {

   //         cout << this->getEnemyType() << " took " << damage << " damage, it has been defeated!" << std::endl;

        //Else, we output how much damage the character took, and what their Strength points are after
        } else {
   //         cout << this->getEnemyType() << " took " << damage << " damage, its strength has been reduced to "
    //             << this->getStrength() << std::endl;
        }

    }

}