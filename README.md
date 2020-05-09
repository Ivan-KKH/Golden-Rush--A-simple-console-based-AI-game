# COMP-2113-Group-5-Project -Golden Rush!

Group members: Kwok Ka Ho (3035689142), Lo Sai Kwan (3035686188)

## Description
Golden Rush! a competitive hunting game. Two game modes are available, 1 player vs. computer or PVP. The adventurers battle on a n x n square gameboard, Resources are generated randomly on it. Players can control their adeventurers and get the resources on the gameboard. Each type of resource (Diamond/Gold/Silver/Bronze) carries different points. The round ends once all the resources have been collected. The player who gets more points wins the round, the game will end once one of the player wins two games in total, and the winner will be the one who scores more in total(Note: winners are determined by their cumulated scores, you may still lose even if you have won two of the three rounds). The top scorers will be permanently stored in a scoreboard table.

Here is a table of the points carried by different resources:
Diamond: 100 points
Gold: 50 points
Silver: 20 points
Bronze: 10 points

Display Sample of gameboard:
![image](Display_view.png)

## Features/Functions: (vis-a-vis 1-5 requirement) * Note: Code Requirements are represented in []

### Input header file(store the input functions in a seperated header file) [5]
   Functions used:
1) **Number of players (PVP/ Person vs. Computer), Username of the adventurers, Difficulty (easy/ hard)** 
     - Users can choose to play PVP(2 players), or PVC which has two mode to choose. 
     - Users input their usernames for counting scores in gameboard display and leaderboard purposes.
     - The easy mode will let the bot move randomly, while the hard mode will make the bot moves base on the AI algorithm.

2) **Player Structure** [2]
     - A struct is made for the adventurers that contain their attributes (Username, score, coordinates)
     
3) **Coordinate Structure** [2]
     - A struct is made for resources and players attributes (types of resources, coordinates)
     
4) **board size** 
     - User can decide the gameboard size on their own (at least 5x5, at most 25x25)

### Process header file(store the process functions in a seperated header file) [5]
   Functions used:
1) **Clear Screen**

2) **Create Gameboard**
     - Create gameboard according to user input size. 
     
3) **Display Gameboard**
     - Display the updated gameboard after user input direction.
     
4) **Who go first**
     - Determine who has the first move for the sake of fairness.
     
5) **Easy Mode**
     - Determine the move of computer for easy mode.
     
6) **Convert Score**
     - Calculate score for both adventurer and computer.
     
7) **Randomize the resources allocation** [1,3]
     - Number of resources will be randomized, ensuring there will be resources in the board.
     
8) **Assign Resouces**[1,3]
     - Assign resources onto the gameboard
     
9) **Randomize adventurers’ location** [1,3]
     - Location of the adventurers will be randomized for the sake of fairness.

10) **Check end of game** [3]
     - Check whether the game has ended.

11) **Movement Valid** [3]
     - Check whether the movements of adventurer and computer are valid.
     
12) **Target resource (Hard mode)** [3]
     - Used in AI Algorithm for hard mode to calculate the best move for the computer.
     
14) **Check step valid (Hard mode)** [3]
     - Used in AI Algorithm for hard mode to check whether the computer movement is valid.
     
15) **Process** [3]
     - To continue the game until all resources on the gameboard have been collected.
     
### Output header file (store the output functions in a seperated header file) [5]
   Functions used:
1) **Display Game Rules** [4]
     - Retrieve and display the game rules upon entering the main.
     - game rules are stored in a separate file ("gamerule.txt").

2) **Show round winner**
     - display the winner of the round.

### Leaderboard header file (store the leaderboard functions in a seperated header file) [5]
   Functions used:
1) **Print Leaderboard** [4]
     - Print the leaderboard after the game has ended.
     - Top 3 scores of adventurers winners would be stored permanently.   
    
