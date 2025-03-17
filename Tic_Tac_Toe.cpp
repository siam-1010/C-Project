#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

// Function to display the current state of the game board
void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to swap between players after each turn
void swapPlayer() {
    current_player = (current_player == 1) ? 2 : 1;
    current_marker = (current_marker == 'X') ? 'O' : 'X';
}

// Function to mark the player's choice on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

// Function to start the game
void startGame() {
    cout << "Player 1, choose your marker (X/O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    displayBoard();

    int player_won = 0;

    while (true) {
        cout << "Player " << current_player << "'s turn. Enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Choose a slot between 1 and 9.\n";
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try a different slot.\n";
            continue;
        }

        displayBoard();

        if (checkWin()) {
            cout << "Player " << current_player << " wins!\n";
            player_won = current_player;
            break;
        }

        if (isBoardFull()) {
            cout << "It's a draw!\n";
            break;
        }

        swapPlayer();
    }
}

// Main function to run the game
int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    startGame();
    return 0;
}
