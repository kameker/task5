#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
#include <stdio.h>
#include <omp.h>

typedef struct {
    node *head;
    node *tail;
    int size;
    int max_size;
    omp_lock_t lock;
} deque;

void make_deque(deque* dq, int max_size);
int get_deques_len(deque *dq);
int is_empty(deque *dq);
void add_first(deque *dq, int value);
void add_last(deque *dq, int value);
void rem_first(deque *dq);
void rem_last(deque *dq);
node* peek_last(deque *dq);
node* peek_first(deque *dq);
node* peek_n(deque *dq, int n);

#endif