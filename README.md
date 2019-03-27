# Fantasy Combat Tournament

This game is a one-user-two-player game, so one user should be able to play setup fighters for both teams. For simplicity, we will call the order of fighters in each team “lineup”, like a batting order in baseball or softball.

The flow of gameplay is as follows:

At the start of the tournament, it should prompt the user to enter the number of fighters for both team. After that, for each fighter, the game should ask the user to choose the type of character, and enter a name for the fighter. For example: assume the user chooses Harry Potter for player No.1’s team lineup, the user can name the Harry Potter character “Larry Snotter” or just “Harry Potter No.1”. The game should allow more than 1 of the same character for team lineups. For example, Team A has 3 members: 2 barbarians and 1 Harry Potter. The order of the lineup should be the same as the order user entered.

After the user supplied the lineup of fighters in order, for Team No.1, and Team No.2, the tournament starts. In the tournament, the fighter at the head/front of each lineup will battle, in the same way they fight in project 3. The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container (There should only be one containers to hold defeated fighters on both team).

If a fighter won, it may have taken damage, so the game should restore some percentage of the damage they took when they get back in line.

The lineup order cannot be changed, meaning that the game cannot modify the order of the lineup except when putting winner at the back of lineup and loser at the top of the loser container.

The tournament finishes when one of the team does not have any more fighters to fight. 

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

