#include "queue.h"
#include <time.h>

int main() {
    int n;

    struct queue* queue1 = createQueue();
    struct queue* queue2 = createQueue();
    struct queue* queue3;

    srand(time(NULL));

    printf("\nEnter the number of random items you want to insert into queue1: ");
    scanf("%d", &n);

    for (int i=0; i < n; i++) enqueue(queue1, rand() % 1000);

    printf("\nEnter the number of random items you want to insert into queue2: ");
    scanf("%d", &n);

    for (int i=0; i < n; i++) enqueue(queue2, rand() % 1000);

    printf("\nPrinting the random queue1 with %d items: ", getSize(queue1));
    printQueue(queue1);

    printf("\nPrinting the random queue2 with %d items: ", getSize(queue2));
    printQueue(queue2);

    printf("\nRemoving the front element from the queue (the last element to enter the queue): %d", dequeue(queue1));
    printf("\nPeeking at the front element of the random queue: %d", peek(queue1));

    printf("\nEnter a value to check if the random queue1 contains it: ");
    scanf("%d", &n);

    if (contains(queue1, n)) printf("\nThe random queue1 contains the value!");
    else printf("\nThe random queue1 does not contain the value");

    printf("\nReversing queue1: ");
    reverseQueue(&queue1);
    printQueue(queue1);

    printf("\nMerging queue 1 and 2: ");
    queue3 = mergeQueues(&queue1, &queue2);
    printQueue(queue3);

    printf("\nRemoving the middle element from queue3: %d", removeMiddle(queue3));

    printf("\nDeleting the random queue3... ");
    deleteQueue(&queue3);
    printf("Deleted!\n");
}