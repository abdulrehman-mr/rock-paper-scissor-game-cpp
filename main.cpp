/*
* Rock Paper Scissor - Single User Console Based Game
* 
*/

#include <iostream> // Standard Libarary
#include <cstdlib> // Included Libarary for Random Number Generation and Clearing Screen Functions
#include <ctime>  // Included Libarary to get time and use as seed for Random Number Generation

using namespace std;

// Global Variables
int pc_count = 0;
int user_count = 0;

// Score Function
void score_counter(int user_move, int pc_move) {
    // Rules:
    // 1) Rock vs Scissor -> Rock wins
    // 2) Rock vs Paper -> Paper wins
    // 3) Paper vs Scissor -> Scissor wins
    // 4) If both select the same shapes -> Draw

    // As we know that 1=rock, 2=paper, 3=scissor

    // User=rock vs Computer=paper -> Computer=Paper wins
    if (user_move == 1 && pc_move == 2) {
        pc_count++;
    }
    // User=paper vs Computer=rock -> User=Paper wins
    else if (user_move == 2 && pc_move == 1) {
        user_count++;
    }
    // User=scissor vs Computer=paper -> Computer=Scissor win
    else if (user_move == 2 && pc_move == 3) {
        pc_count++;
    }
    // User=scissor vs Computer=paper -> User=Scissor win
    else if (user_move == 3 && pc_move == 2) {
        user_count++;
    }
    // User=Rock vs Computer=scissor -> Computer=Scissor win
    else if (user_move == 3 && pc_move == 1) {
        pc_count++;
    }
    // User=scissor vs Computer=Rock -> User=Scissor win
    else if (user_move == 1 && pc_move == 3) {
        user_count++;
    }
}

// Value to Name Function
string value_to_Name(int value) {
    if (value == 1) {
        return "Rock";
    } else if (value == 2) {
        return "Paper";
    } else if (value == 3) {
        return "Scissor";
    }
}

// Get and Validate User Input Function
int getUserInput() {
    int usermove = 0;
    cout << " Please Enter 1 for Rock, 2 for Paper, 3 for Scissor:";
    cin >> usermove;

    // Use a while loop instead of an if statement to repeat until valid input
    while (usermove != 1 && usermove != 2 && usermove != 3) {
        cout << "Wrong input! Please Enter Correct Input!" << endl;
        cout << "Please Enter 1 for Rock, 2 for Paper, 3 for Scissor:";
        cin >> usermove;
    }
    return usermove; // Return the valid input
}

// Main Function
int main() {
    // Resetting the Values to 0
    pc_count = 0;
    user_count = 0;
    cout << "Welcome to Rock Paper Scissor Game - Single Player Game" << endl
         << "Note*" << endl
         << "This game is played between Player/User and Computer." << endl
         << "Rules*" << endl
         << "1) Rock vs Scissor -> Rock wins" << endl
         << "2) Rock vs Paper -> Paper wins" << endl
         << "3) Paper vs Scissor -> Scissor wins" << endl
         << "4) If both select the same shapes -> Draw" << endl
         << endl;

    for (int i = 1; i <= 5; i++) {
        cout << "Round - " << i << endl;

        // Getting User Move values as 1=rock, 2=paper, 3=scissor
        int usermove = getUserInput(); // Called Function to Get User Move Securely

        // Getting Computer Move
        srand(time(NULL));
        int pcmove = (rand() % 3) + 1;

        // Last Scores
        int user_old_score = user_count;
        int pc_old_score = pc_count;

        // Updating Scores
        score_counter(usermove, pcmove);

        // Checking Winner
        string roundWinner = "Draw";
        if (pc_old_score < pc_count) {
            roundWinner = "Computer Wins";
        } else if (user_old_score < user_count) {
            roundWinner = "Player Wins";
        }

        // Displaying Result of Move
        cout << " [Player] " << value_to_Name(usermove)
             << " [Computer] " << value_to_Name(pcmove)
             << " ->" << roundWinner << endl;
    }
    
	// Displaying Result of Game
    cout << "___________" << endl;
    cout << "Total Scores | "
         << "Player:" << user_count
         << "/ Computer:" << pc_count
         << " | ";

    if (user_count > pc_count) {
        cout << "Player Wins" << endl;
    } else if (user_count < pc_count) {
        cout << "Computer Wins" << endl;
    } else if (user_count == pc_count) {
        cout << "Game Draw" << endl;
    }
    
	// Asking If Player Want to Play Again
    char playAgain;
    cout << "Want to Play Again (y/n)?";
    cin >> playAgain;
    if (playAgain == 'y') {
        system("cls"); // Assuming you are using Windows
        main();
    }

    return 0;
}
