#include "queue.h"

struct queue* createQueue() {
    struct queue* queue = (struct queue*) malloc (sizeof(struct queue));
    if (queue == NULL) return NULL;
    queue->front = queue->rear = NULL;

    return NULL;
}

bool isEmpty (struct queue* queue) {
    if (queue->front == NULL) return true;
    else return false;
}