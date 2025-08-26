// PROGRAMAR LA LINKED LIST
// Nota: Cada operación cuenta como una oportunidad de presentar por separado que cada alumno por separado puede presentar
// Se debe implementar usando un Node, como los presentados en clase, que almacena ints
// La lista tiene que soportar las siguientes operaciónes

#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
struct Node {
    int value;
    struct Node* next; 
};

// Append: agrega un elemento al final de la lista
// Cuando hacemos operaciones que pueden cambiar head de la lista, como: append y prepend, necesitamos modificar el valor de head en la función.
// `head` → es el puntero original que tenemos en `main`.
// Si solo pasáramos `struct Node* head`, cambiarlo dentro de la función no afectaría su head original.
void append(struct Node** head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (!new_node) {
        perror("Error al asignar memoria en append");
        return;
    }
    new_node->value = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node; // Cambio su head real
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

// Prepend: agrega un elemento al principio de la lista
void prepend(struct Node** head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); // Creo el nuevo nodo
    if (!new_node) {
        perror("Error al asignar memoria en prepend");
        return;
    }
    new_node->value = val; // Asigno el valor dado al nuevo nodo
    new_node->next = *head; // Apunto next del nuevo nodo a la head actual
    *head = new_node; // Actualizo head para que apunte al nuevo nodo
}

// Delete: elimina la primera ocurrencia del valor dado. 
// Devuelve 1 si encontró y eliminó el valor, 0 si no lo pudo encontrar.
// Uso un Node** porque necesito modificar la cabeza de la lista si el nodo a eliminar es el primero
int delete(struct Node** head, int val) {
    struct Node* current = *head;
    struct Node* prev = NULL; // Guarda el nodo anterior para poder juntar lo que queda de la lista cuando borremos

    if (current == NULL) return 0; // Si la lista está vacía, no hay nada que borrar

    while (current != NULL) {
        if (current->value == val) {
            if (prev == NULL) {
                // borrar el primer nodo
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0; // no encontrado
}

// Find: devuelve 1 si existe val, 0 si no
// No necesito pasar un Node** (puntero doble) porque no voy a cambiar la head de la lista, solo la recorro
int find(struct Node* head, int val) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->value == val) return 1;
        current = current->next;
    }
    return 0;
}

// Print: imprime la lista
// No necesito pasar un Node** (puntero doble) porque no voy a cambiar la head de la lista, solo la recorro
void print(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Free: libera toda la memoria reservada para la lista
void free_list(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Len: devuelve la longitud de la lista
int len(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//----------------------------------------------- SORTERS --------------------------------------------------------------

// ---------- SELECTION SORT ----------
// Busca el mínimo de la sublista y lo intercambia con el nodo actual
// Mueve el puntero a la siguiente posición, toma como mas chico al primero y busca uno menor para intercambiarlo
// EJ: 4 → 7 → 2 → 9 , i=4, min_node=2  --> intercambia valores y avanza i
//     2 → 7 → 4 → 9 , i=7, min_node=4  --> intercambia valores y avanza i
//     2 → 4 → 7 → 9 , i=7, min_node=7  --> no hay swap, avanza i
//     2 → 4 → 7 → 9 , i=9, min_node=9  --> listo, i en posicion final

void selection_sort(struct Node* head) {
    struct Node* i = head;
    while (i != NULL) {
        struct Node* min_node = i; // tomo el primero como minimo
        struct Node* j = i->next; // empiezo a buscar desde el siguiente
        while (j != NULL) {
            if (j->value < min_node->value) {
                min_node = j;
            }
            j = j->next;
        }
        // swap de valores, no de punteros
        if (min_node != i) { // si encontré un nuevo mínimo (no esta en la primera posicion)
            // intercambio para que el valor mas chico quede al principio de la sublista 
            int tmp = i->value;
            i->value = min_node->value;
            min_node->value = tmp;
        }
        i = i->next;
    }
}

// ---------- BUBBLE SORT ----------
// Recorre la lista varias veces, intercambiando nodos adyacentes si están desordenados
void bubble_sort(struct Node* head) {
    if (head == NULL) return; // lista vacia
    int swapped; // indica si hubo cambios
    struct Node* end = NULL; // marca hasta donde esta ordenado

    do {
        swapped = 0;
        struct Node* current = head; 

        // recorro la lista hasta el final menos el último ordenado
        while (current->next != end) {
            if (current->value > current->next->value) {
                // swap de valores, no punteros
                int tmp = current->value;
                current->value = current->next->value;
                current->next->value = tmp;
                swapped = 1;
            }
            current = current->next;
        }
        end = current; // cada pasada el mayor queda al final
    } while (swapped);
}

// ---------- INSERTION SORT ----------
// Es como ordenar un mazo de cartas, pasando por cada una y poniendola en su posicion correcta sobre una mesa (sorted list)
// EJ: tengo 4 → 3 → 1 → 2 , me paro en el 4 y lo pongo en sorted como primero
//     avanzo al 3 y veo que va a la izq del 4, lo pongo ahí y avanzo
//     avanzo al 1 y veo que va a la izq del 3, lo pongo ahí y avanzo
//     avanzo al 2 y veo que va a la izq del 3, lo pongo ahí y avanzo
// Crea una lista ordenada nueva e inserta cada nodo en el lugar correcto
void insertion_sort(struct Node** head) {
    if (*head == NULL) return;

    struct Node* sorted = NULL; // lista en la que voy a agregar los elementos ordenados
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* next = current->next;

        // insertar current en la lista sorted
        if (sorted == NULL || current->value <= sorted->value) {  
            // si esta vacia o el current es menor/igual al primero de la lista ordenada, lo pongo primero
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            // busco la posicion correcta en la lista ordenada avanzando hasta que el next sea menor al current
            while (temp->next != NULL && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}

// -----------------------------------------------------------------------------------------------

// Ejemplo de uso
int main() {

    struct Node* head = NULL; // inicializo la lista con un nodo vacio

    printf("\n--------- EJ LINKED LIST ---------\n");

    printf("\nLista inicial:\n");
    append(&head, 10); // Paso &list para darle la referencia a esa lista, si le pasara solo list le daria una copia
    append(&head, 20);
    append(&head, 30);
    print(head); // NULL
    
    // Agregar un elemento al final
    printf("\nAgergo 42 al final:\n");
    append(&head, 42);
    print(head); // 42 -> NULL

    // Agregar un elemento al principio
    printf("\nAgrego 13 al principio:\n");
    prepend(&head, 13);
    print(head); // 13 -> 42 -> NULL

    // Busco elementos
    printf("\nExiste el 1? %d\n", find(head, 1));
    printf("\nExiste el 13? %d\n", find(head, 13));

    // Calculo logitud
    printf("\nLongitud: %d\n", len(head));

    // Borro un elemento
    printf("\nBorro el 13:\n");
    delete(&head, 13);
    print(head); // Muestro lista final

    free_list(&head);

    // -------------------------------------------------

    printf("\n--------- EJ SORTERS ---------\n");

    append(&head, 5);
    append(&head, 1);
    append(&head, 8);
    append(&head, 3);
    append(&head, 2);

    printf("\nLista original:\n");
    print(head);

    // Selection sort
    printf("\nOrdeno con Selection Sort:\n");
    selection_sort(head);
    print(head);

    // Reinicio la lista
    free_list(&head);
    append(&head, 5);
    append(&head, 1);
    append(&head, 8);
    append(&head, 3);
    append(&head, 2);

    // Insertion sort
    printf("\nOrdeno con Insertion Sort:\n");
    insertion_sort(&head);
    print(head);

    // Reinicio la lista
    free_list(&head);
    append(&head, 5);
    append(&head, 1);
    append(&head, 8);
    append(&head, 3);
    append(&head, 2);

    // Bubble sort
    printf("\nOrdeno con Bubble Sort:\n");
    bubble_sort(head);
    print(head);

    free_list(&head);

    return 0;
}
