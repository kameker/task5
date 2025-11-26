#include "deque.h"

int main(){
    deque* deque;
    int size = 20;
    make_deque(&deque, size);
    for (int i = 0 ;i < size; i++){
        add_last(&deque, i*i - 1);
    }
    for (int i = 0 ; i < size ; i++){
        printf("%d - %d\n", i , peek_n(&deque, i));
    }
}