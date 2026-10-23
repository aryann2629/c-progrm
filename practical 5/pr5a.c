#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is Full! Cannot insert %d.\n", value);
        return;
    }
    rear++;
    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

void dequeue() {
    if (front > rear) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("%d removed from the queue.\n", queue[front]);
    front++;
}

void display() {
    if (front > rear) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- SIMPLE QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Bye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
