#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int value;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
}Queue;

void init_queue(Queue *q);
void push_in_queue(Queue *q, int value);
int pop_from_queue(Queue *q);
int is_empty(Queue *q);

#endif
