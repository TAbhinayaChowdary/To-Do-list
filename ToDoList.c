#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 256

typedef struct {
    char tasks[MAX_TASKS][TASK_LENGTH];
    int count;
} TodoList;

void addTask(TodoList *list, const char *task) {
    if (list->count < MAX_TASKS) {
        strncpy(list->tasks[list->count], task, TASK_LENGTH);
        list->count++;
        printf("Task added: %s\n", task);
    } else {
        printf("Task list is full!\n");
    }
}

void removeTask(TodoList *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid task index!\n");
        return;
    }
    for (int i = index; i < list->count - 1; i++) {
        strncpy(list->tasks[i], list->tasks[i + 1], TASK_LENGTH);
    }
    list->count--;
    printf("Task removed.\n");
}

void viewTasks(const TodoList *list) {
    if (list->count == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("To-Do List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->tasks[i]);
    }
}

int main() {
    TodoList list;
    list.count = 0;
    int choice;
    char task[TASK_LENGTH];
    int index;

    do {
        printf("\nTo-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter the task: ");
                fgets(task, TASK_LENGTH, stdin);
                task[strcspn(task, "\n")] = 0; // Remove newline character
                addTask(&list, task);
                break;
            case 2:
                printf("Enter the task number to remove: ");
                scanf("%d", &index);
                removeTask(&list, index - 1); // Convert to 0-based index
                break;
            case 3:
                viewTasks(&list);
                break;
            case 4:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}