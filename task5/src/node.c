#include "../include/node.h"
#include <stdlib.h>

node* make_node(int value){
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->value = value;
    new_node->before = NULL;
    new_node->next = NULL;
    return new_node;
}