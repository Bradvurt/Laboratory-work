#include "queue.h"

queue *init() {
    queue *q = malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool is_empty(queue *q) {
    return (q->front == NULL) ? true : false;;
}

int len(queue *q) {
    int k = 0;
    for (item *i = q->front; i != NULL; i = i->next) {
        k += 1;
    }
    return k;
}

void insert(queue *q, int t) {
    item *i = (item *)malloc(sizeof(item));
    i->data = t;
    i->next = NULL;
    if (is_empty(q)) {
        q->front = i;
        q->rear = i;
    } else {
        q->rear->next = i;
        q->rear = i;
    }
}

void removal(queue *q) {
    if (is_empty(q)) {
        printf("\nThe queue is empty!\n\n");
        return;
    }
    item *i = q->front;
    q->front = q->front->next;
    free(i);
    return;
}

void print(queue *q) {
    item *i = q->front;
    if(is_empty(q)) {
        printf("The queue is empty!\n");
    }
    else {
        while(i != NULL) {
            printf("%d ", i->data);
            i = i->next;
        }
        printf("\n");
    }
}

void delite(queue * q) {
    while (!is_empty(q)) {
        removal(q);
    }
    q->front = q->rear = NULL;
}

queue *copy(queue *q) {
    queue *q1;
    q1 = init();
    for (item *i = q->front; i != NULL; i = i->next) {
        insert(q1, i->data);
    }
    return q1;
}

void replace(queue *q) {
    queue *q1;
    int j;
    q1 = copy(q);
    delite(q);
    bool flag = false;
    item *i = q1->front;
    for (int _ = 0; _ < len(q1) - 1; _++) {
        if (!flag && i->data > i->next->data) {
            insert(q, i->next->data);
            j = i->data;
            flag = 1;
        }
        else if (flag) {
            if (j > i->next->data) {
                insert(q, i->next->data);
            }
            else {
                insert(q, j);
                flag = 0;
            }
        }
        else {
            insert(q, i->data);
        }
        i = i->next;
    }
    if (flag) {
        insert(q, j);
    }
    else {
        insert(q, i->data);
    }
}

queue *sort(queue *q) {
    for (int i = 0; i < len(q) - 1; i++) {
        replace(q);
    }
    return q;
}