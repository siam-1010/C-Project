#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold customer details
struct Customer {
    int accountNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount(struct Customer *customer, int *count);
void displayAccount(struct Customer *customer, int count);
void depositMoney(struct Customer *customer, int count);
void withdrawMoney(struct Customer *customer, int count);

int main() {
    struct Customer customers[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(customers, &count);
                break;
            case 2:
                displayAccount(customers, count);
                break;
            case 3:
                depositMoney(customers, count);
                break;
            case 4:
                withdrawMoney(customers, count);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
void createAccount(struct Customer *customer, int *count) {
    printf("\nEnter account number: ");
    scanf("%d", &customer[*count].accountNumber);
    printf("Enter name: ");
    scanf("%s", customer[*count].name);
    printf("Enter initial balance: ");
    scanf("%f", &customer[*count].balance);

    (*count)++;
    printf("Account created successfully!\n");
}

// Function to display all accounts
void displayAccount(struct Customer *customer, int count) {
    if (count == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\nAccount Details:\n");
    for (int i = 0; i < count; i++) {
        printf("Account Number: %d\n", customer[i].accountNumber);
        printf("Name: %s\n", customer[i].name);
        printf("Balance: %.2f\n", customer[i].balance);
        printf("----------------------------\n");
    }
}

// Function to deposit money into an account
void depositMoney(struct Customer *customer, int count) {
    int accountNumber;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < count; i++) {
        if (customer[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customer[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", customer[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdrawMoney(struct Customer *customer, int count) {
    int accountNumber;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < count; i++) {
        if (customer[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > customer[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                customer[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", customer[i].balance);
            }
            return;
        }
    }

    printf("Account not found.\n");
}