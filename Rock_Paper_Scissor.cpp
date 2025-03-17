#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char getComputerChoice() {
    srand(time(0));
    int num = rand() % 3; // Generates 0, 1, or 2
    if (num == 0) return 'R';
    else if (num == 1) return 'P';
    else return 'S';
}

char getUserChoice() {
    char choice;
    cout << "Enter R for Rock, P for Paper, or S for Scissors: ";
    cin >> choice;
    choice = toupper(choice);
    
    while (choice != 'R' && choice != 'P' && choice != 'S') {
        cout << "Invalid choice. Please enter R, P, or S: ";
        cin >> choice;
        choice = toupper(choice);
    }
    return choice;
}

void determineWinner(char user, char computer) {
    cout << "Computer chose: " << computer << endl;
    
    if (user == computer) {
        cout << "It's a tie!\n";
    } else if ((user == 'R' && computer == 'S') ||
               (user == 'P' && computer == 'R') ||
               (user == 'S' && computer == 'P')) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
}

int main() {
    char userChoice, computerChoice;
    
    userChoice = getUserChoice();
    computerChoice = getComputerChoice();
    
    determineWinner(userChoice, computerChoice);
    
    return 0;
}
