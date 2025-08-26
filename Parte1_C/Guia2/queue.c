/*            QUEUE
Se debe usar tambien la struct Node
La queue tiene que soportar las siguientes operaciónes:
--> enqueue: encolar un elemento
--> dequeue: desencola un elemento y lo devuelve. Devuelve -1 si no hay elementos
--> is_empty: devolver 1 si la queue esta vacia, 0 sino
--> free: liberar el espacio de memoria dedicado a la queue
*/

#include <stdio.h>
#include <stdlib.h>

// Definirlo como typedef hace que no tenga que escribir todo el tiempo "struct"
typedef struct Node {
    int data;              
    struct Node* next;     
} Node;

typedef struct Queue {
    Node* front;   // primer elemento
    Node* rear;    // último elemento
} Queue;

// Crear una queue vacía
Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Insertar al final
void enqueue(Queue* q, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (q->rear == NULL) {
        // si la cola estaba vacía, front y rear apuntan al nuevo nodo
        q->front = q->rear = new_node;
    } else {
        // si ya había elementos, engancho el nuevo nodo al final
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Sacar del frente
int dequeue(Queue* q) {
    if (q->front == NULL) {
        // cola vacía
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    // si la cola quedó vacía, rear también debe ser NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int is_empty(Queue* q) {
    return q->front == NULL ? 1 : 0;
}

// Liberar memoria
void free_queue(Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

int main() {
    Queue* q = create_queue();

    printf("\nAgrego elementos: 10, 20 y 30\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Dequeue: %d\n", dequeue(q)); // 10
    printf("Dequeue: %d\n", dequeue(q)); // 20

    printf("Is empty? %d\n", is_empty(q)); // 0 (todavía queda 30)

    printf("Dequeue: %d\n", dequeue(q)); // 30
    printf("Dequeue: %d\n", dequeue(q)); // -1 (ya vacía)

    free_queue(q);
    return 0;
}
