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
        if (!temp) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for Node %d: ", i);
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
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data for the new node: ");
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
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data for the new node: ");
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

void addpos(int pos) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data for the new node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if (pos == 1) {
        addfront();
        return;
    }

    p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL || p == tail) {
        addrear();
    } else {
        temp->next = p->next;
        temp->prev = p;
        p->next->prev = temp;
        p->next = temp;
    }
}

void displayforward() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    p = head;
    printf("List in forward order:\n");
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}

void displaybackward() {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }
    p = tail;
    printf("List in backward order:\n");
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->prev;
    }
    printf("\n");
}

int main() {
    int choice, pos;
    while (1) {
        printf("\n\n******* Menu *******");
        printf("\n1. Create DLL");
        printf("\n2. Add node at front");
        printf("\n3. Add node at rear");
        printf("\n4. Add node at specific position");
        printf("\n5. Display DLL forward");
        printf("\n6. Display DLL backward");
        printf("\n7. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create();
                    break;
            case 2: addfront();
                    break;
            case 3: addrear();
                    break;
            case 4: printf("Enter the position where you want to add the element: ");
                    scanf("%d", &pos);
                    addpos(pos);
                    break;
            case 5: displayforward();
                    break;
            case 6: displaybackward();
                    break;
            case 7: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}
