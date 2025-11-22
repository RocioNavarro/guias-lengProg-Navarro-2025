#include <stdlib.h>
#include <stdio.h>

int main() {
    int num_elements = 10;

    // Allocate memory for 10 integers
    // Use sizeof to ensure portability across different systems
    int *ptr = (int*) malloc(num_elements * sizeof(int));

    // Check if allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the allocated memory (e.g., assign values)
    for (int i = 0; i < num_elements; i++) {
        ptr[i] = i * 2;
    }

    // Print the values
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free the allocated memory when it is no longer needed
    free(ptr);
    printf("ptr: " "%p\n", (void*)ptr);
    
    ptr = NULL; // Good practice to prevent dangling pointers

    return 0;
}