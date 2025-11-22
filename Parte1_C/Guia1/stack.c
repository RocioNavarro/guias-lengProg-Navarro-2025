#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node** Stack;

// Prototipos
Stack create_stack();
void push(Stack stack, int value);
int pop(Stack stack);
void delete_stack(Stack stack);

// PUSH
void push(Stack stack, int value) {
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->next = *stack; // next apunta al que antes era el tope
    *stack = node; // el tope ahora es el nuevo nodo
}

// POP
int pop(Stack stack) {
    struct Node* node = *stack; // nodo tope
    int value = node->value; // obtener el valor
    *stack = node->next; // actualizar el tope
    free(node);
    return value;
}

// CREATE STACK
Stack create_stack() {
    Stack s = (struct Node**) malloc(sizeof(struct Node*));
    *s = NULL; // inicializar tope como NULL
    return s;
}

// DELETE STACK
void delete_stack(Stack stack) {
    struct Node* node = *stack;
    while (node != NULL) {
        struct Node* current = node; // nodo actual
        node = node->next; // avanzar al siguiente
        free(current); // liberar el nodo actual
    }
    free(stack);
}


int main() {

    // Using the stack
    Stack s = create_stack();   // Create the stack

    push(s, 10);                // Push values
    push(s, 20);

    printf("%d\n", pop(s)); // Prints 20    
    printf("%d\n", pop(s)); // Prints 10

    delete_stack(s);           // Delete the stack

    return 0;
}