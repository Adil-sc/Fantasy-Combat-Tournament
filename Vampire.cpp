/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: Vampire.cpp contains the class functions for the Vampire class
*********************************************************************/
#include "Vampire.h"


/*********************************************************************
** Constructor that uses an initalizer list to set the characters Name, Armor, and Strength point values
*********************************************************************/
Vampire::Vampire()
        : Character("Vampire", 1, 18) {
    srand(time(0));
}


/*********************************************************************
** Override Base class attack function
*********************************************************************/
int Vampire::attack() {

    firstDieAttack = rand() % 12 + 1;
    totalAttackPower = firstDieAttack;
  //  cout << this->enemyType << " attacks! rolls a " << firstDieAttack << " for a total attacking power of " << totalAttackPower << std::endl;
    return totalAttackPower;
}


/*********************************************************************
** Override Base class defence function. Takes as a parameter an int which is to represent the total attack power returned from the Attack() function
*********************************************************************/
void Vampire::defence(int attackersTotalAttackPower) {

    //Outputs the basic stats of the defender including the current Armor and Strength points
   // cout << this->getEnemyType() << "Stats:" << "[Armor: " << this->getAmor() << ", Strength points: " << this->getStrength() << "]" << std::endl;


    //Calculates a random value for each defenders die
    firstDieDefence = rand() % 6 + 1;
    totalDefencePower = firstDieDefence;

    //Calculates the inflicted damage
    damage = attackersTotalAttackPower - totalDefencePower - armor;

    //Outputs the value for each die roll and the total defence power (which is the sum of all die rolls)
  //  cout << this->getEnemyType() << " defends, rolls a " << firstDieDefence << " for a total defensive power of " << totalDefencePower << std::endl;

    //Special ability: Charm
    //Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them.
    int array[] = {1, 2};
    int charm = rand() % 2;

    //Based on the 50-50 outcome of the charm value, we use a switch statement to determine if the ability has activated or not
    switch (array[charm]) {

        case 1:
     //       cout << this->getEnemyType() << " activates Charm! The attack is ineffective. ";
     //       cout << "Strength remains at " << this->getStrength() << std::endl;
            break;

        case 2:

            //If the damage <= 0, we say that the attack was too weak to inflict any damage
            if (damage <= 0) {
        //        cout << "The attack was ineffective! " << this->getEnemyType() << " is not phased." << std::endl;
            } else {

                //If the attack was >=0, we subtract the damage from the characters current Strength points
                setStrength(this->strength - damage);

                //If the current Strength is <= 0, we say the character has been defeated
                if (this->getStrength() <= 0) {

          //          cout << this->getEnemyType() << " took " << damage << " damage, it has been defeated!" << std::endl;
                 //Else, we output how much damage the character took, and what their Strength points are after
                } else {
         //           cout << this->getEnemyType() << " took " << damage << " damage, its strength has been reduced to "
         //                << this->getStrength() << std::endl;
                }

            }

            break;
    }


}