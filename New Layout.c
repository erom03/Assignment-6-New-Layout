#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Struct Definitions
// Node of the linked list
typedef struct Node {
    int data;
    struct Node * next;
} Node;

// Stack
typedef struct Stack {
    Node * head;
} Stack;

// Linked List Function Prototypes
Node * createNode(int data);
Node * insertHead(Node * head, int data);
Node * removeHead(Node * head);

// Stack Function Prototypes
Stack * createStack();
int isEmpty(Stack * stack);
void push(Stack * stack, int data);
void pop(Stack * stack);
int top(Stack * stack);
void deleteStack(Stack * stack);

int main() {
    // Create stack for current values
    Stack * currStack = createStack();

    // Create stack for previous values
    Stack * prevStack = createStack();

    // Initialize stacks with initial values to avoid problems
    push(currStack, -1);
    push(prevStack, -1);

    // Keeps track of numbers user is inputting
    int userInput;

    // Get first number from user
    scanf("%d", &userInput);

    //Keep looping until user inputs -1
    while(userInput != -1) {
        if(userInput == prevStack->head->data) {
            printf("We went back!\n");
            pop(currStack);
            pop(prevStack);
        } else {
            printf("Adding number to stack!\n");
            push(prevStack, currStack->head->data);
            push(currStack, userInput);
        }
        
        scanf("%d", &userInput);
    }

    // Delete stack, free memory, and exit program
    deleteStack(currStack);
    deleteStack(prevStack);
    return 0;
}

// Linked List Functions
Node * createNode(int data) {
    Node * res = (Node *) malloc(sizeof(Node));
    res->data = data;
    res->next = NULL;
    return res;
}

// Function to insert a node to the head of a linked list
// Return the resulting head
Node * insertHead(Node * head, int data) {
    // Create and link the new head
    Node * newHead = createNode(data);
    newHead->next = head;

    // Return the resulting head
    return newHead;
}

// Function to remove the head of a given linked list
// Return the resulting head
Node * removeHead(Node * head) {
    // Empty list case
    if (head == NULL) {
        return NULL;
    }

    // Prevent Use after free by storing the new head pointer
    Node * newHead = head->next;

    // Delete the old head
    free(head);

    // Return the new head
    return newHead;
}

// Stack functions
// Function to dynamically create a stack implemented using a Linked List
Stack * createStack() {
    Stack * res = (Stack *) malloc(sizeof(Stack));

    // Make the list empty
    res->head = NULL;

    // Return the resulting stack
    return res;
}

// Function to check if the stack is empty
int isEmpty(Stack * stack) {
    return stack->head == NULL;
}

// Function to add an element to the top of the stack
void push(Stack * stack, int data) {
    stack->head = insertHead(stack->head, data);
}

// Function to remove the top of a stack
void pop(Stack * stack) {
    stack->head = removeHead(stack->head);
}

// Function to access the top element of the stack
int top(Stack * stack) {
    // Ensure that the stack has something on top
    assert(stack->head != NULL);

    // Return the value on top
    return stack->head->data;
}

// Function to clean up the memory associated with a stack
void deleteStack(Stack * stack) {
    // Remove the values in the stack
    while (!isEmpty(stack))
        pop(stack);

    // Clean up the memory of the stack
    free(stack);
}