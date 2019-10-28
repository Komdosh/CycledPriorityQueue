#include <stdio.h>
#include "cycled_priority_queue.h"
#include <stdlib.h>

int init(cpq_t *q) {
    q->head = NULL;
    return 0;
};

cpq_node_t *selectNode(const cpq_t *q, cpq_node_t *nodeToInsert) {
    while(nodeToInsert->next != q->head){
        nodeToInsert=nodeToInsert->next;
    }
    return nodeToInsert;
}

int enqueue(cpq_t *q, void *data) {
    cpq_node_t *node = (cpq_node_t *) malloc(sizeof(cpq_node_t));
    node->data = data;
    node->next = q->head;
    node->prev = q->head;
    if(q->head==NULL){
        q->head=node;
        q->head->next=q->head;
        q->head->prev=q->head;
        return 0;
    }

    cpq_node_t *nodeToInsert = selectNode(q,  q->head);

    node->prev = nodeToInsert;
    node->next = nodeToInsert->next;
    nodeToInsert->next->prev = node;
    nodeToInsert->next = node;
    return 0;
};

int dequeue(cpq_t *q, void **data) {
    *data = NULL;

    cpq_node_t *nodeToDelete = selectNode(q,  q->head);

    nodeToDelete->prev->next = nodeToDelete->next;
    nodeToDelete->next->prev = nodeToDelete->prev;

    *data = nodeToDelete->data;
    free(nodeToDelete);

    return 0;
};

void printList(cpq_node_t *head) {
    cpq_node_t *current = head;
    do {
        printf(" %d ", (int) current->data);
        current = current->next;
    }while (current != head);
}