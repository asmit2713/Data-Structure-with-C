#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char items[MAX];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % MAX);
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue* queue, char value) {
    if (isFull(queue)) {
        printf("Queue Overflow: Cannot insert %c\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    printf("Inserted %c into the queue\n", value);
}

char dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow: Cannot delete from an empty queue\n");
        return '\0';
    }
    char item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return item;
}

void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue status: ");
    int i = queue->front;
    while (1) {
        printf("%c ", queue->items[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    printf("Asmit's (1AY23CS044) program!\n\n");
    CircularQueue queue;
    initializeQueue(&queue);
    char choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("a. Insert an Element onto Circular Queue\n");
        printf("b. Delete an Element from Circular Queue\n");
        printf("c. Demonstrate Overflow and Underflow\n");
        printf("d. Display the status of Circular Queue\n");
        printf("e. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter a character to insert: ");
                scanf(" %c", &value);
                enqueue(&queue, value);
                break;
            case 'b':
                value = dequeue(&queue);
                if (value != '\0') {
                    printf("Deleted %c from the queue\n", value);
                }
                break;
            case 'c':
                for (int i = 0; i < MAX + 1; i++) {
                    enqueue(&queue, 'A' + (i % 26));
                }
                for (int i = 0; i < MAX + 1; i++) {
                    dequeue(&queue);
                }
                break;
            case 'd':
                displayQueue(&queue);
                break;
            case 'e':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
