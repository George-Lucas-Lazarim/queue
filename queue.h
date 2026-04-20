#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queueNode {
    int data;
    struct queueNode* next;
};

struct queue {
    struct queueNode* front;
    struct queueNode* rear;
};

struct queue* createQueue();
bool isEmpty (struct queue* queue);
void enqueue (struct queue* queue, int data);
int dequeue (struct queue* queue);
int peek (struct queue* queue);

#endif