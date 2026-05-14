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
#include <stdint.h>

/**
 * Belirli bir aralıktaki bitleri ters çevirir.
 * @param word İşlem yapılacak 32-bit sayı
 * @param start Başlangıç bit pozisyonu (0'dan başlar)
 * @param length Ters çevrilecek bit sayısı
 * @return Değiştirilmiş yeni sayı
 */
uint32_t invert_bits(uint32_t word, int start, int length) {
    // 1. İstenilen uzunlukta 1'lerden oluşan bir blok (maske) yarat
    uint32_t mask = (1U << length) - 1;

    // 2. Bu bloğu hedef başlangıç noktasına kaydır
    mask <<= start;

    // 3. XOR işlemi ile sadece maskenin 1 olduğu yerlerdeki bitleri takla attır
    return word ^ mask;
}

```

```c
#include <stdint.h>

void droits_to_string(uint16_t droits, char *output) {
    // Referans dizimiz: Sirasiyla User, Group ve Other izinleri
    const char *symboles = "rwxrwxrwx";

    for (int i = 0; i < 9; ++i) {
        // En soldaki bit (8. bit) User Read, en sagdaki (0. bit) Other Execute'tur.
        // Bu yuzden (8 - i) yaparak bitleri soldan saga dogru kontrol ediyoruz.
        if ((droits >> (8 - i)) & 1U) {
            output[i] = symboles[i]; // Bit 1 ise ilgili harfi koy
        } else {
            output[i] = '-';         // Bit 0 ise tire koy
        }
    }

    // C dilinde string'lerin altin kurali: Null-terminator ekle
    output[9] = '\0';
}

```

```c
#include <stdint.h>

uint16_t set_others_permissions(uint16_t droits, uint8_t new_others) {
    // 1. droits & ~0x07 : Eski 'autres' bitlerini kazıyarak temizle.
    // 2. new_others & 0x07 : Dışarıdan gelen veriyi 3 bit ile sınırla (Güvenlik).
    // 3. | : Temizlenmiş bölgeye yeni bitleri zerk et.
    return (droits & ~0x07) | (new_others & 0x07);
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
