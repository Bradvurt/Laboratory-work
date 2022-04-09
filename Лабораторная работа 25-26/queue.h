#ifndef QUEUE_H
#define QUEUE_H

#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

typedef struct item {
    int data;
    struct item *next;
} item;

typedef struct queue {
    struct item *front;
    struct item *rear;
} queue;

queue *init(void);

bool is_empty(queue *q);

int len(queue *q);

void insert(queue *q, int t);

void removal(queue *q);

void print(queue *q);

void delite(queue *q);

void replace(queue *q);

queue *sort(queue *q);

#endif