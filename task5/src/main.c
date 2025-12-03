#include "../include/deque.h"
#include <stdio.h>

int main(){
    deque dq;
    int size = 5; 
    make_deque(&dq, size);
    
    printf("Adding elements...\n");
    for (int i = 0; i < size; i++){
        add_last(&dq, i*i - 1);
    }
    
    printf("Printing elements...\n");
    for (int i = 0; i < size; i++){
        node* n = peek_n(&dq, i);
        if (n != NULL) {
            printf("%d - %d\n", i, n->value);
        } else {
            printf("%d - NULL\n", i);
        }
    }
    
    // Очистка памяти
    while (!is_empty(&dq)) {
        rem_first(&dq);
    }
    
    return 0;
}