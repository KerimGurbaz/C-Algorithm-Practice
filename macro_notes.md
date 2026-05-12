```c
#ifndef TEB_BLOCK_H
#define TEB_BLOCK_H

#define BLOCK_SIZE 4096  // Max size of the block to generate

// 1. Eger DEBUG hic tanimlanmamissa (Uretim - Release modu)
#ifndef DEBUG
    // Makro hicbir sey yapmaz. Guvenlik icin bos do-while kullanilir.
    #define DBG_PRINTF(fmt, ...) do {} while(0)

// 2. Eger DEBUG tanimliysa (Gelistirme - Debug modu)
#else
    // 2.a: DEBUG == 0 ise normal printf
    #if DEBUG == 0
        #define DBG_PRINTF(fmt, ...) printf(fmt, ##__VA_ARGS__)

    // 2.b: DEBUG == 1 ise satir numarali ve \n kontrollu ozel printf
    #elif DEBUG == 1
        #define DBG_PRINTF(fmt, ...) \
            do { \
                /* Eger gelen format string'inin ilk karakteri \n degilse satir numarasini yaz */ \
                if ((fmt)[0] != '\n') { \
                    printf("(%d) ", __LINE__); \
                } \
                /* Sonrasinda asil mesaji aynen yazdir */ \
                printf(fmt, ##__VA_ARGS__); \
            } while(0)
    #endif
#endif

#endif

```

```c
#include <stdio.h>

// Balik Tutma Kurali:
// 1. Tip ismini test kodundan cikar (typedef gerektigini gor).
// 2. Isimleri ## ile dinamiklestir.
// 3. Makro icinde uretilen fonksiyonlara cakismayi onlemek icin 'static inline' ekle.

#define DEFINE_PAIR(name, type1, type2)                                        \
    typedef struct {                                                           \
        type1 first;                                                           \
        type2 second;                                                          \
    } name##_pair;                                                             \
                                                                               \
    static inline name##_pair make_##name(type1 f, type2 s) {                  \
        name##_pair p;                                                         \
        p.first = f;                                                           \
        p.second = s;                                                          \
        return p;                                                              \
    }                                                                          \
                                                                               \
    static inline void print_##name(name##_pair p) {                           \
        printf("(");                                                           \
        printf(_Generic((p.first), int: "%d", float: "%.2f", char*: "%s"), p.first); \
        printf(", ");                                                          \
        printf(_Generic((p.second), int: "%d", float: "%.2f", char*: "%s"), p.second);\
        printf(")\n");                                                         \
    }

// Kullanım
DEFINE_PAIR(point, int, int);
DEFINE_PAIR(etudiant, char*, float);

int main() {
    point_pair p1 = make_point(10, 20);
    printf("Point: ");
    print_point(p1);  // Çıktı: (10, 20)

    etudiant_pair e1 = make_etudiant("Jean", 15.5);
    printf("Etudiant: ");
    print_etudiant(e1);  // Çıktı: (Jean, 15.50)

    return 0;
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
