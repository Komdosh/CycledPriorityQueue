#include <stdio.h>
#include "cycled_priority_queue.h"
#include <stdlib.h>

int init(cpq_t *q) {
    q->head = NULL;
    return 0;
};

cpq_node_ptr_t *selectEnqueueNode(const cpq_t *q, void **data) {
    cpq_node_ptr_t *current = q->head;
    while (current->first->next != q->head && current->second->next != q->head) {
        if ((int) current->first->data < (int) data) {
            current = current->second->next;
        } else {
            current = current->first->next;
        }
    }
    return current;
}

cpq_node_ptr_t *selectDequeueNode(const cpq_t *q) {
    cpq_node_ptr_t *current = q->head;
    while (current->first->next != q->head && current->second->next != q->head) {
        if ((int) current->first->data < (int) current->second->data) {
            current = current->second->next;
        } else {
            current = current->first->next;
        }
    }
    return current;
}

cpq_node_t *initNode(const cpq_t *q, void *data) {
    cpq_node_t *node = (cpq_node_t *) malloc(sizeof(cpq_node_t));
    node->data = data;
    node->next = q->head;
    node->prev = q->head;
    return node;
}

void insertFirst(cpq_node_ptr_t *node, cpq_node_ptr_t *nodeToInsert) {
    node->first->prev = nodeToInsert;
    node->first->next = nodeToInsert->first->next;
    nodeToInsert->first->next->first->prev = node;
    nodeToInsert->first->next = node;
}

void insertSecond(cpq_node_ptr_t *node, cpq_node_ptr_t *nodeToInsert) {
    node->second->prev = nodeToInsert;
    node->second->next = nodeToInsert->second->next;
    nodeToInsert->second->next->second->prev = node;
    nodeToInsert->second->next = node;
}

int enqueue(cpq_t *q, void *data) {
    cpq_node_ptr_t *node = (cpq_node_ptr_t *) malloc(sizeof(cpq_node_ptr_t));

    node->second = (cpq_node_t *) malloc(sizeof(cpq_node_t));
    node->first = initNode(q, data);
    node->second = initNode(q, data);

    if (q->head == NULL) {
        q->head = node;
        q->head->first->next = q->head;
        q->head->first->prev = q->head;

        q->head->second->next = q->head;
        q->head->second->prev = q->head;
        return 0;
    }

    cpq_node_ptr_t *nodeToInsert = selectEnqueueNode(q, data);

    insertFirst(node, nodeToInsert);
    insertSecond(node, nodeToInsert);

    return 0;
};

void deleteLinks(const cpq_node_t *nodeToDelete) {
    nodeToDelete->prev->first->next = nodeToDelete->next;
    nodeToDelete->next->first->prev = nodeToDelete->prev;
}

int dequeue(cpq_t *q, void **data) {
    *data = NULL;

    cpq_node_ptr_t *nodeToDelete = selectDequeueNode(q);

    deleteLinks(nodeToDelete->first);

    deleteLinks(nodeToDelete->second);

    *data = nodeToDelete->first->data;
    *data = nodeToDelete->second->data;
    free(nodeToDelete);

    return 0;
};

void printList(cpq_t q) {
    cpq_node_ptr_t *current = q.head;
    do {
        printf(" %d ", (int) current->first->data);
        printf(" %d ", (int) current->second->data);

        if ((int) current->first->data < (int) current->second->data) {
            current = current->second->next;
        } else {
            current = current->first->next;
        }
        current = current->first->next;
    } while (current != q.head);
}