#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed onto the stack.\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("%d popped from the stack.\n", stack[top]);
    top--;
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element is: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("  %d\n", stack[i]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Bye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
