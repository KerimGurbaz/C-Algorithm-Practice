// #include <stdio.h>
// #include <stdlib.h>
// #include "queue.h"

// typedef struct Node {
//     int value;
//     struct Node *next;
// }Node;

// typedef struct {
//     Node *head;
//     Node *tail;
//     int size;
// }Queue;

// void *new_queue() {
//     Queue *q = malloc(sizeof(Queue));
//     q->head = NULL;
//     q->tail = NULL;
//     q->size = 0;

//     return q;
// }

// void push_in_queue(void *q_ptr, int val) {
//     Queue *q = (Queue *)q_ptr;

//     Node *new_node = malloc(sizeof(Node));
//     new_node->value = val;
//     new_node->next = NULL;

//     if (q->tail == NULL) {
//         q->head = new_node;
//         q->tail = new_node;
//     } else {
//         q->tail->next = new_node;
//         q->tail = new_node;
//     }
//     q->size++;
// }

// void pop_from_queue(void *q_ptr) {
//     Queue *q = (Queue *)q_ptr;

//     if (q->head == NULL)return;

//     Node *temp = q->head;
//     q->head = q->head->next;

//     if (q->head == NULL) {
//         q->tail = NULL;
//     }

//     free(temp);
//     q->size--;
// }

// int front_of_queue(void **q_ptr) {
//     Queue *q = (Queue *)q_ptr;
//     if (q->head == NULL) return -1;
//     return q->head->value;
// }

// int back_of_queue(void *q_ptr) {
//     Queue *q = (Queue *)q_ptr;

//     if (q->tail == NULL) return -1;
//     return q->tail->value;
// }

// int size_of_queue(void *q_ptr) {
//     Queue *q = (Queue *)q_ptr;
//     return q->size;
// }

// void free_queue(void *q_ptr) {
//     Queue *q = (Queue *)q_ptr;

//     Node *current = q->head;

//     while (current != NULL) {
//         Node *temp = current;
//         current = current->next;
//         free(temp);
//     }

//     free(q);
// }
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct Node {
    int val;
    struct Node *next;
}Node;

typedef struct File {
    Node *premier;
    Node *dernier;
    int size;
}File;

void *new_queue() {
    File *f = (File *)malloc(sizeof(File));
    if (f == NULL) {
        return NULL;
    }
    f->premier = NULL;
    f->dernier = NULL;
    f->size = 0;

    return (void *)f;
}

void push_in_queue(void *q, int i) {
    File *f = (File *)q;

    Node *nouveau = (Node *)malloc(sizeof(Node));
    if (nouveau == NULL) return;

    nouveau->val = i;
    nouveau->next = NULL;

    if (f->size == 0) {
        f->premier = nouveau;
        f->dernier = nouveau;
    } else {
        f->dernier->next = nouveau;
        f->dernier = nouveau;
    }
    f->size++;
}

void pop_front_queue(void *q) {
    File *f = (File *)q;

    if (f->size == 0) return;

    Node *a_supprimer = f->premier;
    f->premier = f->premier->next;

    free(a_supprimer);
    f->size--;

    if (f->size == 0) {
        f->dernier = NULL;
    }
}

int front_of_queue(void *q) {
    File *f = (File *)q;
    if (f->premier != NULL) return f->premier->val;

    return -1;
}

int back_of_queue(void *q) {
    File *f = (File *)q;
    if (f->dernier != NULL) return f->dernier->val;
    return -1;
}

int size_of_queue(void *q) {
    File *f = (File *)q;
    return f->size;
}


void free_queue(void *q) {
    File *f = (File *)q;
    if (f == NULL) return;

    while (f->size > 0) {
        pop_from_queue(q);
    }
    free(q);
}
