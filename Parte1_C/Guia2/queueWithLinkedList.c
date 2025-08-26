#include <stdio.h>
#include <stdlib.h>
#include "linkedList.c" // asumimos que tiene struct Node y funciones append, free_list, etc.

typedef struct Queue {
    struct Node* head; // apuntará al primer nodo
} Queue;

// Crear una queue vacía
Queue* create_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    return q;
}

// Encolar al final
void enqueue(Queue* q, int value) {
    append(&(q->head), value); // usamos append de linkedList
}

// Desencolar del frente
int dequeue(Queue* q) {
    if (q->head == NULL) return -1; // vacía

    int value = q->head->value;
    struct Node* temp = q->head;
    q->head = q->head->next;
    free(temp);

    return value;
}

// Verificar si está vacía
int is_empty(Queue* q) {
    return q->head == NULL;
}

// Liberar memoria
void free_queue(Queue* q) {
    free_list(&(q->head));
    free(q);
}

// Ejemplo de uso
int main() {
    Queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Dequeue: %d\n", dequeue(q)); // 10
    printf("Dequeue: %d\n", dequeue(q)); // 20
    printf("Is empty? %d\n", is_empty(q)); // 0
    printf("Dequeue: %d\n", dequeue(q)); // 30
    printf("Dequeue: %d\n", dequeue(q)); // -1

    free_queue(q);
    return 0;
}
