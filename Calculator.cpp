#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

void showMenu() {
    cout << "\nAdvanced Calculator" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Power" << endl;
    cout << "6. Square Root" << endl;
    cout << "7. Logarithm" << endl;
    cout << "8. Trigonometric Functions" << endl;
    cout << "9. Factorial" << endl;
    cout << "10. Matrix Operations" << endl;
    cout << "11. Exit" << endl;
    cout << "Select an option: ";
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

long long factorial(int n) {
    if (n < 0) return -1; // Invalid input
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

void matrixMultiplication() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));
    vector<vector<double>> result(n, vector<double>(n, 0));
    
    cout << "Enter elements of first matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    
    cout << "Enter elements of second matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    cout << "Resultant Matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    double num1, num2;

    while (true) {
        showMenu();
        cin >> choice;
        
        if (cin.fail()) {
            clearInput();
            cout << "Invalid input! Please enter a number between 1 and 11." << endl;
            continue;
        }

        if (choice == 11) {
            cout << "Exiting calculator. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1: // Addition
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 + num2 << endl;
                break;
            case 2: // Subtraction
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3: // Multiplication
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 * num2 << endl;
                break;
            case 4: // Division
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 == 0) {
                    cout << "Error: Division by zero!" << endl;
                } else {
                    cout << "Result: " << num1 / num2 << endl;
                }
                break;
            case 5: // Power
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                cout << "Result: " << pow(num1, num2) << endl;
                break;
            case 6: // Square Root
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 < 0) {
                    cout << "Error: Negative number!" << endl;
                } else {
                    cout << "Result: " << sqrt(num1) << endl;
                }
                break;
            case 7: // Logarithm
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 <= 0) {
                    cout << "Error: Logarithm undefined for non-positive numbers!" << endl;
                } else {
                    cout << "Result: " << log(num1) << endl;
                }
                break;
            case 8: // Trigonometry
                int trigChoice;
                cout << "Select function: 1. Sin 2. Cos 3. Tan: ";
                cin >> trigChoice;
                cout << "Enter angle in degrees: ";
                cin >> num1;
                num1 = num1 * M_PI / 180.0; // Convert to radians
                if (trigChoice == 1)
                    cout << "Result: " << sin(num1) << endl;
                else if (trigChoice == 2)
                    cout << "Result: " << cos(num1) << endl;
                else if (trigChoice == 3)
                    cout << "Result: " << tan(num1) << endl;
                else
                    cout << "Invalid choice!" << endl;
                break;
            case 9: // Factorial
                int num;
                cout << "Enter a number: ";
                cin >> num;
                if (num < 0) {
                    cout << "Error: Factorial of negative number is undefined!" << endl;
                } else {
                    cout << "Result: " << factorial(num) << endl;
                }
                break;
            case 10: // Matrix Operations
                matrixMultiplication();
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }
    return 0;
}
