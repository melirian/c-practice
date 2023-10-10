#include <stdio.h>
#include <stdlib.h>

// Define a structure for a stack
struct Stack {
    int* data;
    int top;
    int capacity;
};

// Function to create a new stack with a given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(sizeof(int) * capacity);
    if (stack->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack* stack = createStack(5);

    // Push some elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Pop and display elements from the stack
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    return 0;
}
