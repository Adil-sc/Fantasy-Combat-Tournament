/*********************************************************************
** Program Name: Project 4
** Author: Adil Chaudhry
** Date: 3/1/2019
** Description: Modifies Project 3 and turns it into a tournament style game using a linked list structure
*********************************************************************/

#include <iostream>
#include "Tournament.h"
#include <ctime>
#include <cstdlib>

int main() {

    bool quit = false;
    srand(time(0));
    Tournament myTourney;

            while(!quit){
                myTourney.menu(quit);
            }

    return 0;
}