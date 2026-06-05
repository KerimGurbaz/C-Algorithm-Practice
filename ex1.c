// // #include <stdio.h>
// // #include <stdlib.h>

// // typedef struct Node {
// //     int data;
// //     struct Node *next;
// // }Node;

// // typedef struct Queue {
// //     Node *head;
// //     Node *tail;
// // }Queue;


// // void push_in_queue(Queue *q, int value) {

// //     if (q == NULL)return;
// //     Node *new_node = malloc(sizeof(Node));
// //     if (new_node == NULL) {
// //         return;
// //     }

// //     new_node->data = value;
// //     new_node->next = NULL;

// //     if (q->head == NULL) {
// //         q->head = new_node;
// //         q->tail = new_node;
// //     } else {
// //         q->tail->next = new_node;
// //         q->tail = new_node;

// //     }

// // }

// // int pop_from_queue(Queue *q) {
// //     if (q->head == NULL) {
// //         return -1;
// //     }

// //     Node *temp_node = q->head;
// //     int pop_value = temp_node->data;

// //     q->head = q->head->next;

// //     if (q->head == NULL) {
// //         q->tail = NULL;
// //     }

// //     free(temp_node);

// //     return pop_value;

// // }


// // int main() {

// //     Queue q;
// //     q.head = NULL;
// //     q.tail = NULL;

// //     Queue q2 = { NULL, NULL };

// //     push_in_queue(&q2, 5);


// //     return 0;
// // }


// #include <stdlib.h>
// #include <stdio.h>
// #include "queue.h"



// void init_queue(Queue *q) {
//     if (q != NULL) {
//         q->head = NULL;
//         q->tail = NULL;
//         q->size = 0;
//     }
// }

// void push_in_queue(Queue *q, int value) {
//     if (q == NULL) return;

//     Node *new_node = malloc(sizeof(Node));

//     if (new_node == NULL) {
//         fprintf(stderr, "Erreur d'allocation memoire.\n");
//         exit(EXIT_FAILURE);
//     }

//     new_node->value = value;
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

// int pop_from_queue(Queue *q) {
//     if (q == NULL || q->head == NULL) {
//         fprintf(stderr, "Erreur...");
//         exit(EXIT_FAILURE);
//     }
//     Node *temp = q->head;
//     int pop_value = temp->value;

//     q->head = temp->next;

//     if (q->head == NULL) {
//         q->tail = NULL;
//     }

//     free(temp);
//     q->size--;

//     return pop_value;
// }


// int is_empty(Queue *q) {
//     return (q == NULL || q->head == NULL);
// }



// int  main() {
//     Queue q;

//     init_queue(&q);

//     for (int i = 0; i < 10; ++i) {
//         printf("%d ", push_in_queue(&q));
//     }

//     for (int i = 0; i < 5; ++i) {
//         printf("%d ", pop_from_queue(&q));
//     }
//     printf("\n");

//     if (!is_empty(&q)) {
//         printf("%d elements remain in queue, from %d to %d.\n",
//             q.size,
//             q.head->value,
//             q.tail->value);
//     }
//     return 0;
// }
#include <stdio.h>
#include "queue.h"

int main() {
    void *q = new_queue();

    for (int i = 0; i < 10; ++i) {
        push_in_queue(q, i * i);
        if (i % 2 == 0) {
            printf("%d ", front_of_queue(q));
            pop_from_queue(q);
        }
    }

    printf("\n%d elements remain in queue, from %d to %d.\n",
        size_of_queue(q),
        front_of_queue(q),
        back_of_queue(q));

    free_queue(q);
}
