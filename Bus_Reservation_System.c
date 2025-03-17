#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100

struct Booking {
    int booking_id;
    char passenger_name[50];
    int bus_number;
    int seat_number;
};

struct Booking bookings[MAX_BOOKINGS];
int booking_count = 0;

void add_booking() {
    if (booking_count >= MAX_BOOKINGS) {
        printf("No more seats available!\n");
        return;
    }
    printf("Enter Booking ID: ");
    scanf("%d", &bookings[booking_count].booking_id);
    getchar(); // To consume the newline character left by scanf
    printf("Enter Passenger Name: ");
    fgets(bookings[booking_count].passenger_name, 50, stdin);
    strtok(bookings[booking_count].passenger_name, "\n"); // Remove newline
    printf("Enter Bus Number: ");
    scanf("%d", &bookings[booking_count].bus_number);
    printf("Enter Seat Number: ");
    scanf("%d", &bookings[booking_count].seat_number);
    
    booking_count++;
    printf("Booking Successful!\n");
}

void view_bookings() {
    if (booking_count == 0) {
        printf("No bookings available.\n");
        return;
    }
    printf("\n--- Booking List ---\n");
    for (int i = 0; i < booking_count; i++) {
        printf("Booking ID: %d | Name: %s | Bus No: %d | Seat No: %d\n",
               bookings[i].booking_id, bookings[i].passenger_name, bookings[i].bus_number, bookings[i].seat_number);
    }
}

void search_booking() {
    int id, found = 0;
    printf("Enter Booking ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < booking_count; i++) {
        if (bookings[i].booking_id == id) {
            printf("Booking Found - Name: %s | Bus No: %d | Seat No: %d\n",
                   bookings[i].passenger_name, bookings[i].bus_number, bookings[i].seat_number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Booking not found!\n");
    }
}

void cancel_booking() {
    int id, found = 0;
    printf("Enter Booking ID to cancel: ");
    scanf("%d", &id);
    for (int i = 0; i < booking_count; i++) {
        if (bookings[i].booking_id == id) {
            found = 1;
            for (int j = i; j < booking_count - 1; j++) {
                bookings[j] = bookings[j + 1];
            }
            booking_count--;
            printf("Booking canceled successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Booking not found!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nBus Reservation System\n");
        printf("1. Add Booking\n2. View Bookings\n3. Search Booking\n4. Cancel Booking\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_booking(); break;
            case 2: view_bookings(); break;
            case 3: search_booking(); break;
            case 4: cancel_booking(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
