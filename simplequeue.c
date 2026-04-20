#include "queue.h"
#include <time.h>

int main() {
    int n;

    struct queue* queue = createQueue();

    srand(time(NULL));

    printf("\nEnter the number of random elements you want to insert into the queue: ");
    scanf("%d", &n);

    for (int i=0; i < n; i++) enqueue(queue, rand() % 1000);

    if (!isEmpty(queue)) printf("\nRemoving the front element from the list (the first element to enter the list): %d\n", dequeue(queue));

}