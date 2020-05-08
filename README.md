# COMP-2113-Group-5-Project -Golden Rush!

Group members: Kwok Ka Ho (3035689142), Lo Sai Kwan (3035686188)

## Description
We are planning to make a competitive hunting game. Two game modes are available, 1 player vs. computer or PVP. The adventurers battle on a n x n square gameboard, Resources are generated randomly on it. Players can control their characters and get the resources on the gameboard. Each type of resource (Diamond/Gold/Silver/Bronze) carries different points. Each round is regarded as a set, the set ends once all the resources have been collected. The player who gets more points wins the set, the game will end once one of the player wins two games in total, and the winner will be the one who scores more in total. The top scorers will be permanently stored in a scoreboard table.

Here is the points carried by different resource:
Diamond: 100 points
Gold: 50 points
Silver: 20 points
Bronze: 10 points

Display Sample of gameboard:
![image](Display_view.png)

## Features/Functions: (vis-a-vis 1-5 requirement)

### Input (5 - store the input functions in a seperated header file) 
1) **number of players (PVP/ Person vs. Computer), Difficulty (easy/ hard)**
     - Users can choose to play PVP(2 players), or PVC which has two mode to choose. The easy mode will let the bot move randomly, while the hard mode will make the bot moves base on the ai algorithm.

2) **Username of the adventurers** (2 - we made a struct for the adventurers that contain two attributes (Username, score))
     - Players input their usernames for gaming and storage purposes. We apply the data structures here (an array with string username and int score) 
     
3) **board size** 
     - User can decide the gameboard size on their own (at least 5x5, at most 25x25)

### Process (5 - store the process functions in a seperated header file) 
1) **Algorithm for moving decision**
     * easy difficulty: random movement of computer
     * hard difficulty: AI algorithm (Fitness function, A* search)
     We find out the best move for the computer using the A* search for the hard level


2) **Randomize the resources allocation and adventurers’ location** (1 – Randomization)
     - Number of resources and location of the adventurers will be randomized but ensuring there will be resources in the board

3) **Update score counting system**
     - Scores will be updated after each move to let players know the current scores of themselves and the computer
     
### Output
1) **Display Game Rules** (4,5 – store instructions in a separate file, display when called) 
     - We retrieve the game files from the text file and display to the user 

2) **Gameboard**
     - Display the area that the adventurers can move

3) **Display the gaming process**
     - Gameboard will be updated after each move from user

4) **scoreboard** (4, 5 – store display scoreboard function in a separate file, retreive information when called)
     - We store the scores each time when the game is finished. The highest scores will be displayed on the ranking.


