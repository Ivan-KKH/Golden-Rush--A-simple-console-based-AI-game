# COMP-2113-Group-5-Project -Golden Rush!

Group members: Kwok Ka Ho (3035689142), Lo Sai Kwan (3035686188)

## Description
We are planning to make a competitive hunting game. Two game modes are available, 1 player vs. computer or PVP. The adventurers battle on a n x n square gameboard, Resources are generated randomly on it. Players can control their characters and get the resources on the gameboard. Each type of resource (Diamond/Gold/Silver/Bronze) carries different points. The game ends once all resources have been collected. The player who gets the most points wins the set, the first player who gets two sets wins the game. Scores of winners will be permanently stored in a scoreboard table.

Display Sample of gameboard:
![image](Display_view.png)

## Features/Functions: (vis-a-vis 1-5 requirement)

### Input
1) **board size they desire** (3 – create the array with size according to user input)
     - User can decide the gameboard size on their own (at least 5x5, at most 25x25)

2) **Difficulty (easy, hard), number of players (PVP/ Person vs. Computer)**
     - Easy mode will let the bot move randomly; hard mode will make the bot moves base on the ai algorithm we design

3) **Username of adventurer** (2 - the adventurers contain two attributes (Username, score))
     - Players input their usernames for gaming and storage purposes. We apply the data structures here (an array with string username and int score) 

### Output
1) **Display Game Rules** (4,5 – store instructions in a separate file, display when called) 
     - We retrieve the game files from the text file and display to the user 

2) **Gameboard**
     - Display the area that the adventurers can move

3) **Display the gaming process**
     - Gameboard will be updated after each move from user

4) **scoreboard** (4, 5 – store display scoreboard function in a separate file, retreive information when called)
     - We store the scores each time when the game is finished. The highest scores will be displayed on the ranking.

### Process
1) **Algorithm for moving decision**
     * easy difficulty: random movement of computer
     * hard difficulty: AI algorithm (Fitness function, A* search)
     We find out the best move for the computer using the A* search for the hard level

2) **Randomize the resources allocation and adventurers’ location** (1 – Randomization)
     - Number of resources and location of the adventurers will be randomized but ensuring there will be resources in the board

3) **Update score counting system**
     - Scores will be updated after each move to let players know the current scores of themselves and the computer
