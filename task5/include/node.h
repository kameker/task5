typedef struct node{
    int value;
    struct node *next;
    struct node *before;
} node;

node* make_node(int value);