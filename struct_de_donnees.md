```c
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// Tekil veri bloklarımız. Her biri bir sonrakini işaret eder.
typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;

// Kuyruğun durumunu tutan ana yapı.
// O(1) karmaşıklığında ekleme/çıkarma yapmak için hem başı hem sonu tutmalıyız.
typedef struct File {
    Noeud* premier; // Çıkarma (pop) işlemi buradan yapılır
    Noeud* dernier; // Ekleme (push) işlemi buraya yapılır
    int taille;     // O(N) döngülerinden kaçınmak için boyutu önbellekte tutuyoruz
} File;

void* new_queue() {
    File* f = (File*)malloc(sizeof(File));
    if (f == NULL) {
        return NULL; // Güvenlik kuralı: malloc başarısız olursa patlamayı önle.
    }
    f->premier = NULL;
    f->dernier = NULL;
    f->taille = 0;
    return (void*)f; // void* dönüş türünü karşılamak için cast ediyoruz.
}

void push_in_queue(void* q, int i) {
    File* f = (File*)q; // void* gelen pointer'ı kullanabilmek için File* tipine geri çeviriyoruz

    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) return; // Bellek kontrolü

    nouveau->valeur = i;
    nouveau->suivant = NULL; // Son eleman olacağı için ilerisi yok

    if (f->taille == 0) {
        // Liste boş senaryosu
        f->premier = nouveau;
        f->dernier = nouveau;
    } else {
        // Liste dolu senaryosu
        f->dernier->suivant = nouveau; // Eski sonuncuyu yeniye bağla
        f->dernier = nouveau;          // Kuyruk yöneticisini yeni sona güncelle
    }
    f->taille++;
}

void pop_from_queue(void* q) {
    File* f = (File*)q;

    if (f->taille == 0) return; // Boş listeden eleman çıkarılamaz

    Noeud* a_supprimer = f->premier;     // Silinecek düğümü sakla
    f->premier = f->premier->suivant;    // Başı bir sonrakine kaydır

    free(a_supprimer);                   // Hafızayı iade et
    f->taille--;

    // Eğer çıkardığımız eleman son elemansa (liste boşaldıysa), dernier askıda kalır.
    // Askıda kalan pointer (dangling pointer) hatasını önlemek için NULL'a çekiyoruz.
    if (f->taille == 0) {
        f->dernier = NULL;
    }
}

int front_of_queue(void* q) {
    File* f = (File*)q;
    // Hata yönetimi (Gerçek hayatta assert veya özel hata kodları kullanılır)
    if (f->premier != NULL) return f->premier->valeur;
    return -1;
}

int back_of_queue(void* q) {
    File* f = (File*)q;
    if (f->dernier != NULL) return f->dernier->valeur;
    return -1;
}

int size_of_queue(void* q) {
    File* f = (File*)q;
    return f->taille;
}

void free_queue(void* q) {
    File* f = (File*)q;
    if (f == NULL) return;

    // Liste boşalana kadar baştan eleman çıkar
    while (f->taille > 0) {
        pop_from_queue(q);
    }

    // Son olarak yöneticinin kendisini sil
    free(f);
}


```

```c
Liste Doublement Chainée (Çift Yönlü Bağlı Liste)
// Tek yönlü:               // Çift yönlü:
struct Node {               struct Node {
    int value;                  int value;
    struct Node *next;          struct Node *next;
};                              struct Node *prev;  // ← YENİ!
                            };

 typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;   // Geriye pointer
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;

void push_in_queue(void *q_ptr, int value) {
    Queue *q = (Queue*)q_ptr;

    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = q->tail;  // ← Geriye bağla!

    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->size++;
}

void pop_from_queue(void *q_ptr) {
    Queue *q = (Queue*)q_ptr;
    if (q->head == NULL) return;

    Node *temp = q->head;
    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    } else {
        q->head->prev = NULL;  // ← Yeni başın prev'ini NULL yap
    }

    free(temp);
    q->size--;
}



```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
