# Fantasy Combat Tournament

This game is a one-user-two-player game, so one user should be able to play setup fighters for both teams. 

The flow of gameplay is as follows:

At the start of the tournament, it should prompt the user to enter the number of fighters for both team. After that, for each fighter, the game should ask the user to choose the type of character, and enter a name for the fighter. For example: assume the user chooses Harry Potter for player No.1’s team lineup, the user can name the Harry Potter character “Larry Snotter” or just “Harry Potter No.1”. The game should allow more than 1 of the same character for team lineups. For example, Team A has 3 members: 2 barbarians and 1 Harry Potter. The order of the lineup should be the same as the order user entered.

After the user supplied the lineup of fighters in order, for Team No.1, and Team No.2, the tournament starts. In the tournament, the fighter at the head/front of each lineup will battle, in the same way they fight in project 3. The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container (There should only be one containers to hold defeated fighters on both team).

If a fighter won, it may have taken damage, so the game should restore some percentage of the damage they took when they get back in line.

The lineup order cannot be changed, meaning that the game cannot modify the order of the lineup except when putting winner at the back of lineup and loser at the top of the loser container.

The tournament finishes when one of the team does not have any more fighters to fight. 

#Characters
Note: “1d12” means rolling one 12-sided die, and “2d6” means rolling 2 6-sided dice, etc.

## Vampire
```
Attack: 1d12
Defense: 1d6
Armor: 1
Strength Points: 18
Special Ability: Charm - Vampires can charm an opponent into not attacking. 
For a given attack there is a 50% chance that their opponent does not actually attack them.
```

## Barbarian
```
Attack: 2d6
Defense: 2d6
Armor: 0
Strength Points: 12
Special Ability: None
```

## Blue Men
```
Attack: 2d10
Defense: 3d6
Armor: 3
Strength Points: 12
Special Ability: Mob - Blue Men are actually a swarm of small individuals. 
For every 4 points of damage, they lose one defense die. 
For example, if they have a strength of 8, they would have 2d6 for defense.
```

## Medusa
```
Attack: 2d6
Defense: 1d6
Armor: 3
Strength Points: 8
Special Ability: Glare - If a Medusa rolls a 12 when attacking then the target 
instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter 
on his first life, then Harry Potter comes back to life.
```

## Harry Potter
```
Attack: 2d6
Defense: 2d6
Armor: 0
Strength Points: 10/20
Special Ability: Hogwarts - If Harry Potter's strength reaches 0 or below, 
he immediately recovers and his total strength becomes 20. If he were to die 
again, then he’s dead.
```

## Notes
```
If Medusa uses “glare” on Harry Potter on his first life, 
then Harry Potter comes back to life after using “hogwarts”.

If the Vampire’s “charm” ability activates when Medusa uses “glare”, 
the Vampire’s charm trumps Medusa’s glare.
```

## Installation and Usage
Compile the program with this command:
```
make FinalProject
```
Run with the following command:
```unix
./FinalProject
```

## Built With
c++

