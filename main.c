#include <stdio.h>
#include <stdlib.h>
#include "cycled_priority_queue.h"


int main() {
    cpq_t cpq;
    init(&cpq);
    enqueue(&cpq, (void *)1);
    enqueue(&cpq, (void *)2);
    enqueue(&cpq, (void *)3);
    enqueue(&cpq, (void *)4);
    int* a = (int*)malloc(sizeof(int));
    dequeue(&cpq, (void**)&a);
    printf("%d|   ", a);
    printList(cpq);
    return 0;
}