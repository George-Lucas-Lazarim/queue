#include "queue.h"
#include <time.h>

int main() {
    int n;

    struct queue* queue = createQueue();

    srand(time(NULL));

    printf("\nEnter the number of random elements you want to insert into the queue: ");
    scanf("%d", &n);

    for (int i=0; i < n; i++) enqueue(queue, rand() % 1000);

    printf("\nPrinting the random list: ");
    printQueue(queue);

    printf("\nRemoving the front element from the list (the last element to enter the list): %d", dequeue(queue));
    printf("\nPeeking at the front element of the random list: %d", peek(queue));

    printf("\nDeleting the random list... ");
    deleteQueue(&queue);
    printf("Deleted!\n");
}