#include "../include/node.h"
#include "../include/deque.h"

#include <stdlib.h>

void make_deque(deque* deque, int max_size){
    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;
    deque->max_size = max_size;
}
int get_deques_len(deque *deque){

}
int is_empty(deque *deque){
    return deque->size == 0;
}
void add_first(deque *deque, int value){
    node* new_node = make_node(value);
    if (is_empty(deque)){
        deque->head = new_node;
        deque->tail = new_node;
    } else if (deque->max_size <= deque->size + 1){
        new_node->next = deque->head;
        deque->head->before = new_node;
        deque->head = new_node;
    }
    deque->size++;
}
void add_last(deque *deque, int value){
    node* new_node = make_node(value);
    if (is_empty(deque)){
        deque->head = new_node;
        deque->tail = new_node;
    } else if (deque->max_size <= deque->size + 1){
        new_node->before = deque->tail;
        deque->tail->next = new_node;
        deque->tail = new_node;
    }
    deque->size++;

}
void rem_first(deque *deque){
    if (deque->size == 1){
        deque->head = NULL;
        deque->tail = NULL;
    } else {
        deque->tail = deque->tail->before;
        deque->tail->next = NULL;
    }
    deque->size--;
}
void rem_last(deque *deque){
    if (deque->size == 1){
        deque->head = NULL;
        deque->tail = NULL;
    } else {
        deque->head = deque->head->next;
        deque->head->before = NULL;
    }
    deque->size--;
}
node* peek_last(deque *deque){
    return deque->head->next;
}
node* peek_first(deque *deque){
    return deque->tail->before;
}
node* peek_n(deque *deque, int n){
    node* current = deque->head;
    int k = 0;
    while (current != NULL) {
        if (k == n){
            return current;
        }
        k++;
        current = current->next;
    }
}