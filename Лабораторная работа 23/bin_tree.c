#include "bin_tree.h"

node *creating_a_node(int key) {
    node *n = (node *) malloc(sizeof(node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void deleting_a_tree(node *n) {
    printf("The tree has been removed\n");
    if (n->left)
        deleting_a_tree(n->left);
    if (n->right)
        deleting_a_tree(n->right);
    free(n);
}

void print_parent(node *n, int deep) {
    if (deep != 0) {
        printf("=%d", n->key);
    } else {
        printf("%d", n->key);
    }
}

void print_tree(node *n, int deep) {
    for (int i = 0; i < deep - 1; ++i) {
        printf("| ");
    }
    if (deep != 0)
        printf("|");
    print_parent(n, deep);
    printf("\n");
    int deep_copy = deep;
    if (n->right) {
        print_tree(n->right, ++deep_copy);
    }
    deep_copy = deep;
    if (n->left) {
        print_tree(n->left, ++deep_copy);
    }
}

node *node_search(node *n, int key) {
    if (n == NULL || n->key == key) {
        return n;
    }
    if (key < n->key) {
        return node_search(n->left, key);
    } else {
        return node_search(n->right, key);
    }
}

void entering_a_node(node *n, int key) {
    if (node_search(n, key)) {
        printf("Error, element already created\n");
    } else {
        if (n->key > key) {
            if (!n->left)
                n->left = creating_a_node(key);
            else
                entering_a_node(n->left, key);
        } else {
            if (!n->right)
                n->right = creating_a_node(key);
            else
                entering_a_node(n->right, key);
        }
    }
}

node *min_node(node *n) {
    if (!n->left) {
        return n;
    }
    return min_node(n->left);
}

node *deleting_a_node(node *n, int key) {
    if (n->key > key) {
        n->left = deleting_a_node(n->left, key);
    } else if (n->key < key) {
        n->right = deleting_a_node(n->right, key);
    } else {
        if (n->right && n->left) {
            n->key = min_node(n->right)->key;
            n->right = deleting_a_node(n->right, n->key);
        } else if (n->right) {
            node *t = n->right;
            free(n);
            n = t;
        } else if (n->left) {
            node *t = n->left;
            free(n);
            n = t;
        } else {
            free(n);
            n = NULL;
        }
    }
    return n;
}

bool is_symmetric(node *n) {
    if (n->left && n->right) {
        return is_similarity(n->left, n->right);
    } else if (!n->left && !n->right){
        return true;
    } else {
        return false;
    }
}

bool is_similarity(node *root1, node *root2) {
    if (((!root1->left && !root2->right) || (root1->left && root2->right)) &&
        ((!root1->right && !root2->left) || (root1->right && root2->left))) {
        if (root1->left && root1->right && root2->left && root2->right) {
            return is_similarity(root1->left, root2->right) && is_similarity(root1->right, root2->left);
        } else if (root1->left) {
            return is_similarity(root1->left, root2->right);
        } else if (root1->right) {
            return is_similarity(root1->right, root2->left);
        } else {
            return true;
        }
    } else {
        return false;
    }
}
