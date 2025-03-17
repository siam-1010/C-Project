#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
} patients[MAX_PATIENTS];

int patient_count = 0;

void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Hospital is at full capacity!\n");
        return;
    }
    printf("Enter Patient ID: ");
    scanf("%d", &patients[patient_count].id);
    getchar(); // Consume newline left in buffer
    printf("Enter Name: ");
    fgets(patients[patient_count].name, 50, stdin);
    strtok(patients[patient_count].name, "\n"); // Remove newline character
    printf("Enter Age: ");
    scanf("%d", &patients[patient_count].age);
    getchar(); // Consume newline left in buffer
    printf("Enter Disease: ");
    fgets(patients[patient_count].disease, 50, stdin);
    strtok(patients[patient_count].disease, "\n"); // Remove newline character
    
    patient_count++;
    printf("Patient added successfully!\n");
}

void view_patients() {
    if (patient_count == 0) {
        printf("No patients in the system.\n");
        return;
    }
    printf("\n--- Patient List ---\n");
    for (int i = 0; i < patient_count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].disease);
    }
}

void search_patient() {
    int id;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("Patient Found - Name: %s, Age: %d, Disease: %s\n",
                   patients[i].name, patients[i].age, patients[i].disease);
            return;
        }
    }
    printf("Patient not found!\n");
}

void delete_patient() {
    int id, found = 0;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            found = 1;
            for (int j = i; j < patient_count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patient_count--;
            printf("Patient deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Patient not found!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n2. View Patients\n3. Search Patient\n4. Delete Patient\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_patient(); break;
            case 2: view_patients(); break;
            case 3: search_patient(); break;
            case 4: delete_patient(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
