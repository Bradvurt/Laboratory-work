#ifndef bin_tree_h
#define bin_tree_h
#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"

typedef struct node {
    struct node* left;
    struct node* right;
    int key;
} node;

node * creating_a_node(int key);
void deleting_a_tree(node * n);
void print_parent(node *n, int deep);
void print_tree(node *n, int deep);
node * node_search(node *n, int key);
void entering_a_node(node *n, int key);
node * min_node(node *n);
node * deleting_a_node(node *n, int key);
bool is_symmetric(node *n);
bool is_similarity(node *n1, node *n2);
#endif
