#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    int data;
    struct queueNode* next;
};

struct queue {
    struct queueNode* front;
    struct queueNode* rear;
};

#endif