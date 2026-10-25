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

struct Node* getLast() {
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    return temp;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *last = getLast();
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *last = getLast();
        last->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at the end.\n", value);
}

void insertAfter(int key, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        if (temp->data == key) {
            struct Node *newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("%d inserted after %d.\n", value, key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node %d not found.\n", key);
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *toDelete = head;
    printf("%d deleted from the beginning.\n", toDelete->data);
    if (head->next == head) {
        head = NULL;
    } else {
        struct Node *last = getLast();
        head = head->next;
        last->next = head;
    }
    free(toDelete);
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        printf("%d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    printf("%d deleted from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = head;
}

void deleteAfter(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        if (temp->data == key) {
            struct Node *toDelete = temp->next;
            if (toDelete == temp) {
                printf("There is no other node after %d.\n", key);
                return;
            }
            temp->next = toDelete->next;
            if (toDelete == head) {
                head = toDelete->next;
            }
            printf("%d deleted (it was after %d).\n", toDelete->data, key);
            free(toDelete);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node %d not found.\n", key);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head %d)\n", head->data);
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
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
