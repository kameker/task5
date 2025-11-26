#include "node.h"
typedef struct {
    node *head;
    node *tail;
    int size;
    int max_size;
} deque;

void make_deque(deque* deque, int max_size);
int get_deques_len(deque *deque);
int is_empty(deque *deque);
void add_first(deque *deque, int value);
void add_last(deque *deque, int value);
void rem_first(deque *deque);
void rem_last(deque *deque);
node* peek_last(deque *deque);
node* peek_first(deque * deque);
node* peek_n(deque *deque, int n);