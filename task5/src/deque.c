#include "../include/node.h"
#include "../include/deque.h"
#include <stdlib.h>

void make_deque(deque* dq, int max_size){
    dq->head = NULL;
    dq->tail = NULL;
    dq->size = 0;
    dq->max_size = max_size;
    omp_init_lock(&dq->lock);
}

int get_deques_len(deque *dq){
    return dq->size;
}

int is_empty(deque *dq){
    return dq->size == 0;
}

void add_first(deque *dq, int value){
    // Проверяем максимальный размер
    omp_set_lock(&dq->lock);
    if (dq->max_size > 0 && dq->size >= dq->max_size) {
        rem_last(dq); // Удаляем последний элемент если достигли максимума
    }
    
    node* new_node = make_node(value);
    if (is_empty(dq)){
        dq->head = new_node;
        dq->tail = new_node;
    } else {
        new_node->next = dq->head;
        dq->head->before = new_node;
        dq->head = new_node;
    }
    dq->size++;
    omp_unset_lock(&dq->lock);
}

void add_last(deque *dq, int value){
    // Проверяем максимальный размер
    omp_set_lock(&dq->lock);
    if (dq->max_size > 0 && dq->size >= dq->max_size) {
        rem_first(dq); // Удаляем первый элемент если достигли максимума
    }
    
    node* new_node = make_node(value);
    if (is_empty(dq)){
        dq->head = new_node;
        dq->tail = new_node;
    } else {
        new_node->before = dq->tail;
        dq->tail->next = new_node;
        dq->tail = new_node;
    }
    dq->size++;
    omp_unset_lock(&dq->lock);
}

void rem_first(deque *dq){
    omp_set_lock(&dq->lock);
    if (is_empty(dq)) return;
    
    if (dq->size == 1){
        free(dq->head);
        dq->head = NULL;
        dq->tail = NULL;
    } else {
        node* temp = dq->head;
        dq->head = dq->head->next;
        dq->head->before = NULL;
        free(temp);
    }
    dq->size--;
    omp_unset_lock(&dq->lock);
}

void rem_last(deque *dq){
    omp_set_lock(&dq->lock);
    if (is_empty(dq)) return;
    
    if (dq->size == 1){
        free(dq->tail);
        dq->head = NULL;
        dq->tail = NULL;
    } else {
        node* temp = dq->tail;
        dq->tail = dq->tail->before;
        dq->tail->next = NULL;
        free(temp);
    }
    dq->size--;
    omp_unset_lock(&dq->lock);
}

node* peek_last(deque *dq){
    if (is_empty(dq)) return NULL;
    return dq->tail;
}

node* peek_first(deque *dq){
    if (is_empty(dq)) return NULL;
    return dq->head;
}

node* peek_n(deque *dq, int n){
    if (n < 0 || n >= dq->size) return NULL;
    
    node* current = dq->head;
    int k = 0;
    while (current != NULL) {
        if (k == n){
            return current;
        }
        k++;
        current = current->next;
    }
    return NULL;
}