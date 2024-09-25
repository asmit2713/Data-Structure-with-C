#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

struct Stack {
    int items[MAX];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int element) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", element);
    } else {
        s->items[++(s->top)] = element;
        printf("%d pushed onto the stack.\n", element);
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop an element from the stack.\n");
        return -1;
    } else {
        int poppedElement = s->items[s->top--];
        printf("%d popped from the stack.\n", poppedElement);
        return poppedElement;
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

void checkPalindrome() {
    char str[100], revStr[100];
    struct Stack s;
    initialize(&s);

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < strlen(str); i++) {
        revStr[i] = pop(&s);
    }
    revStr[strlen(str)] = '\0';

    if (strcmp(str, revStr) == 0) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
}

int main() {
    printf("Asmit's(1AY23CS044) Program!\n\n");
    struct Stack stack;
    initialize(&stack);

    int choice, element;

    while (1) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push an element onto the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Check palindrome using stack\n");
        printf("4. Demonstrate overflow/underflow\n");
        printf("5. Display stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                if (isFull(&stack)) {
                    printf("The stack is full (Overflow condition).\n");
                } else if (isEmpty(&stack)) {
                    printf("The stack is empty (Underflow condition).\n");
                } else {
                    printf("Neither overflow nor underflow.\n");
                }
                break;
            case 5:
                display(&stack);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
