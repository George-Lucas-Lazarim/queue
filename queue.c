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

void enqueue (struct queue* queue, int data) {
    struct queueNode* newNode = (struct queueNode*) malloc (sizeof(struct queueNode));
    newNode->data = data;

    if (queue->front == NULL) {
        newNode->next = NULL;
        queue->front = queue->rear = newNode;
    } else {
        newNode->next = queue->rear;
        queue->rear = newNode;
    }
}