//
// Created by Andrey Tabakov on 27.10.2019.
//

#ifndef CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_QUEUE_H
#define CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_QUEUE_H

typedef struct cpq_node cpq_node_t;
typedef struct cpq cpq_t;

struct cpq_node {
    void* data;
    cpq_node_t* next;
    cpq_node_t* prev;
};

struct cpq {
    cpq_node_t* head;
    cpq_node_t* tail;
};

int init(cpq_t *);
int enqueue(cpq_t* q, void *data);
int dequeue(cpq_t* q, void **data);
void printList(cpq_node_t* node);

#endif //CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_QUEUE_H
