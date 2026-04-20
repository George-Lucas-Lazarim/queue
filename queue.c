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

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue (struct queue* queue) {
    if (isEmpty(queue)) {
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

int peek (struct queue* queue) {
    if (isEmpty(queue)) {
        printf("Error! The Queue is Empty");
        return -1;
    }

    return queue->front->data;
}

void deleteQueue (struct queue** queue) {
    struct queueNode* tempNode;

    while (!isEmpty(*queue)) {
        tempNode = (*queue)->front;
        (*queue)->front = (*queue)->front->next;
        free(tempNode);
    }

    free(*queue);
    *queue = NULL;
}

void printQueue (struct queue* queue) {
    struct queueNode* currentNode = queue->front;

    printf("[front] ");

    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL ");
    
    printf("[rear]");
}