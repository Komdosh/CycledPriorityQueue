//
// Created by Andrey Tabakov on 27.10.2019.
//

#ifndef CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_QUEUE_H
#define CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_QUEUE_H

struct cycled_priority_queue {

};

typedef struct cycled_priority_queue cycled_priority_queue_t;

int init(cycled_priority_queue_t *);
int enqueue(cycled_priority_queue_t* q, void *data);
int dequeue(cycled_priority_queue_t* q, void **data);

#endif //CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_QUEUE_H
