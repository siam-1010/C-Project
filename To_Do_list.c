#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 200

typedef struct {
    char task[TASK_LENGTH];
    int completed;
} Todo;

Todo todoList[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("To-Do list is full!\n");
        return;
    }

    printf("Enter the task: ");
    getchar(); // To consume the newline character left by previous input
    fgets(todoList[taskCount].task, TASK_LENGTH, stdin);
    todoList[taskCount].task[strcspn(todoList[taskCount].task, "\n")] = '\0'; // Remove newline character
    todoList[taskCount].completed = 0;
    taskCount++;
    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, todoList[i].task, todoList[i].completed ? "Completed" : "Pending");
    }
}

void deleteTask() {
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int taskNumber;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = taskNumber - 1; i < taskCount - 1; i++) {
        strcpy(todoList[i].task, todoList[i + 1].task);
        todoList[i].completed = todoList[i + 1].completed;
    }

    taskCount--;
    printf("Task deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}