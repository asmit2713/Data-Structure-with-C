#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL, *tail = NULL, *temp = NULL, *p = NULL;

void create() {
    int n, i;
    printf("\nHow many nodes do you want to create? ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data for node %d: ", i);
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
}

void addfront() {
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter data for node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void addrear() {
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter data for node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void displayforward() {
    if (head == NULL) {
        printf("\nNo linked list exists.");
    } else {
        p = head;
        while (p != NULL) {
            printf("\nData = %d", p->data);
            p = p->next;
        }
    }
}

void displaybackward() {
    if (tail == NULL) {
        printf("\nNo linked list exists.");
    } else {
        p = tail;
        while (p != NULL) {
            printf("\nData = %d", p->data);
            p = p->prev;
        }
    }
}

void reverse() {
    struct Node *tempNode = NULL;
    p = head;
    
    while (p != NULL) {
        tempNode = p->next;
        p->next = p->prev;
        p->prev = tempNode;
        p = p->prev;
    }
    
    if (tempNode != NULL) {
        head = tempNode->prev;
    }
}

int main() {
    int choice, pos;

    while (1) {
        printf("\n\n*******Menu********");
        printf("\n1. Create DLL.");
        printf("\n2. Add node at front.");
        printf("\n3. Add node at rear.");
        printf("\n4. Display DLL forward.");
        printf("\n5. Display DLL backward.");
        printf("\n6. Reverse DLL.");
        printf("\n7. Exit.");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                addfront();
                break;
            case 3:
                addrear();
                break;
            case 4:
                displayforward();
                break;
            case 5:
                displaybackward();
                break;
            case 6:
                reverse();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
}

