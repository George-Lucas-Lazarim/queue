#include "queue.h"

struct queue* createQueue() {
    struct queue* queue = (struct queue*) malloc (sizeof(struct queue));
    if (queue == NULL) return queue;

    queue->front = queue->rear = NULL;
    return queue;
}

bool isEmpty (struct queue* queue) {
    return (queue->front == NULL);
}

void enqueue (struct queue* queue, int data) {
    struct queueNode* newNode = (struct queueNode*) malloc (sizeof(struct queueNode));

    if (newNode == NULL) {
        printf("Error! Memory allocation failure");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue (struct queue* queue) {
    if (queue->front == NULL) {
        printf("Error! The Queue is Empty");
        return -1;
    } else {
        struct queueNode* tempNode = queue->front;
        int data = tempNode->data;

        queue->front = queue->front->next;

        if (queue->front == NULL) queue->rear = NULL;
        
        free(tempNode);

        return data;
    }
}