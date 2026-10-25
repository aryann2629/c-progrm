#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at the end.\n", value);
}

void insertAfter(int key, int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted after %d.\n", value, key);
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("%d deleted from the beginning.\n", temp->data);
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("%d deleted from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteAfter(int key) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }
    if (temp->next == NULL) {
        printf("There is no node after %d.\n", key);
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("%d deleted (it was after %d).\n", toDelete->data, key);
    free(toDelete);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a given node\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Delete node after a given node\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: "); scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Insert after which node value? "); scanf("%d", &key);
                printf("Enter new value: "); scanf("%d", &value);
                insertAfter(key, value);
                break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6:
                printf("Delete the node after which node value? "); scanf("%d", &key);
                deleteAfter(key);
                break;
            case 7: display(); break;
            case 8: printf("Bye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
