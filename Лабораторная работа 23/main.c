#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "bin_tree.h"

bool is_int(const char *str) {
    while (*str) {
        if ((*str < '0' || *str > '9') && *str != '-' && *str != '.')
            return false;
        *str++;
    }
    return true;
}

int main() {
    node *n;
    bool program_works = true;
    bool tree_not_created = true;
    printf("Program start\n");
    while (program_works) {
        if (tree_not_created) {
            printf("\n");
            int root;
            char c[] = "";
            bool value_is_incorrect = true;
            while (value_is_incorrect) {
                printf("Creating a new tree, enter the root key:\n");
                scanf("%s", c);
                if (is_int(c)) {
                    root = atoi(c);
                    value_is_incorrect = false;
                } else {
                    printf("Error, is not number!\n");
                }
            }
            n = creating_a_node(root);
            printf("The tree was created.\n\n");
            tree_not_created = false;
        } else {
            char menu[] = "0";
            while (!strcmp("0", menu)) {
                printf("What you want to do?\n1: Add new element\n2: Print tree\n3: Delete element\n4: Output whether the tree is symmetric\n5: Exit\n");
                scanf("%s", menu);
                if (!strcmp("1", menu)) {
                    int key;
                    char c[] = "";
                    bool value_is_incorrect = true;
                    while (value_is_incorrect) {
                        printf("Adding a new node, enter the key:\n");
                        scanf("%s", c);
                        if (is_int(c)) {
                            key = atoi(c);
                            value_is_incorrect = false;
                        } else {
                            printf("Error, is not number!\n");
                        }
                    }
                    entering_a_node(n, key);
                } else if (!strcmp("2", menu)) {
                    printf("\n");
                    print_tree(n, 0);
                    printf("\n");
                } else if (!strcmp("3", menu)) {
                    int key;
                    char c[] = "";
                    bool value_is_incorrect = true;
                    while (value_is_incorrect) {
                        printf("Enter the key:\n");
                        scanf("%s", c);
                        if (is_int(c)) {
                            key = atoi(c);
                            value_is_incorrect = false;
                        } else {
                            printf("Error, is not number!\n");
                        }
                    }
                    if (!node_search(n, key)) {
                        printf("Error, tree haven't this element!\n");
                    } else {
                        if (n->key == key) {
                            if (!n->right && !n->left) {
                                deleting_a_tree(n);
                                n = NULL;
                                tree_not_created = true;
                            } else {
                                n = deleting_a_node(n, key);
                            }
                        } else {
                            n = deleting_a_node(n, key);
                        }
                    }
                } else if (!strcmp("4", menu)) {
                    if (is_symmetric(n)) {
                        printf("True\n\n");
                    } else {
                        printf("False\n\n");
                    }
                } else if (!strcmp("5", menu)) {
                    printf("End of program.\n");
                    program_works = false;
                } else {
                    printf("Error, incorrect input!\n");
                }
            }
        }
    }
    if (!tree_not_created) {
        deleting_a_tree(n);
    }
    return 0;
}