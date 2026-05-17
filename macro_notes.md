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
#include <stdio.h>
#include <stdint.h>

// 1. Struct Tanımı
typedef struct {
    uint32_t flags;
} registre_t;

// 2. Bit Aktif Etme Fonksiyonu (SET)
void set_flag(registre_t *r, int pos) {
    if (r && pos >= 0 && pos < 32) {
        r->flags |= (1U << pos);
    }
}

// 3. Bit Kapatma Fonksiyonu (CLEAR)
void clear_flag(registre_t *r, int pos) {
    if (r && pos >= 0 && pos < 32) {
        r->flags &= ~(1U << pos);
    }
}

// 4. Bit Tersleme Fonksiyonu (TOGGLE)
void toggle_flag(registre_t *r, int pos) {
    if (r && pos >= 0 && pos < 32) {
        r->flags ^= (1U << pos);
    }
}

// 5. Binary Yazdırma Yardımcı Fonksiyonu
void print_binary(uint32_t num) {
    for (int i = 31; i >= 0; --i) {
        putchar(((num >> i) & 1U) ? '1' : '0');
        // Okunabilirliği artırmak için her 4 bütte bir boşluk bırakır
        if (i % 4 == 0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

int main() {
    // Tüm bitleri 0 olan bir kayıt oluşturulur
    registre_t reg = {0};

    // Adım 1: 0, 3 ve 7. bitleri aktif et (Beklenen: 1000 1001 -> 0x89)
    set_flag(&reg, 0);
    set_flag(&reg, 3);
    set_flag(&reg, 7);

    // Adım 2: 3. biti söndür (Beklenen: 1000 0001 -> 0x81)
    clear_flag(&reg, 3);

    // Adım 3: 7. biti tersine çevir. 1 idi, 0 olacak (Beklenen: 0000 0001 -> 0x01)
    toggle_flag(&reg, 7);

    // Sonucu ekrana bas
    printf("Resultat final (Binary) : ");
    print_binary(reg.flags);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdint.h>

// Durum Değiştirici Makrolar (Değişkeni doğrudan günceller)
#define SET_BIT(word, pos)   ((word) |= (1U << (pos)))
#define CLEAR_BIT(word, pos) ((word) &= ~(1U << (pos)))

// Okuma Makrosu (Değeri değiştirmez, 1 veya 0 döndürür)
#define CHECK_BIT(word, pos) (((word) >> (pos)) & 1U)

// Çok Satırlı Veri Çıkarma Makrosu
#define EXTRACT_BITS(word, start, len) \
    (((word) >> (start)) & ((1U << (len)) - 1))

int main() {
    // 0b11010110 sayısı onluk tabanda 214'e denk gelir.
    uint32_t x = 0b11010110;

    // 2, 3 ve 4. bitleri istiyoruz.
    // Başlangıç (start) = 2, Çekilecek bit sayısı (len) = 3
    uint32_t resultat = EXTRACT_BITS(x, 2, 3);

    printf("Valeur extraite : %u\n", resultat); // Çıktı: 5

    // SET, CLEAR ve CHECK makrolarının sağlaması
    SET_BIT(x, 0);   // x'in son biti 0 idi, 1 oldu.
    CLEAR_BIT(x, 4); // x'in 4. biti 1 idi, 0 oldu.

    printf("Le bit 0 est-il actif ? %u\n", CHECK_BIT(x, 0)); // Çıktı: 1
    printf("Le bit 4 est-il actif ? %u\n", CHECK_BIT(x, 4)); // Çıktı: 0

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// 1. Struct Tanımı
typedef struct noeud {
    int valeur;
    struct noeud *next; // Kendi türünden bir yapıya işaret eden pointer
} noeud_t;

// 2. Listenin Başına Eleman Ekleme (Push)
void push(noeud_t **head, int val) {
    noeud_t *nouveau = (noeud_t *)malloc(sizeof(noeud_t));
    if (!nouveau) {
        perror("Erreur d'allocation memoire");
        return;
    }
    nouveau->valeur = val;
    nouveau->next = *head; // Yeni düğüm eski başı göstersin
    *head = nouveau;       // Listenin yeni başı bu düğüm olsun
}

// 3. Listeyi Binary Dosyaya Kaydetme (Serialization)
void sauvegarder_liste(noeud_t *head, const char *file) {
    FILE *f = fopen(file, "wb");
    if (!f) {
        perror("Erreur d'ouverture en ecriture");
        return;
    }

    noeud_t *courant = head;
    while (courant != NULL) {
        // SADECE değeri (int) diske yazıyoruz, pointer'ı DEĞİL
        fwrite(&(courant->valeur), sizeof(int), 1, f);
        courant = courant->next;
    }
    fclose(f);
}

// 4. Binary Dosyadan Listeyi Yeniden İnşa Etme (Deserialization)
noeud_t* charger_liste(const char *file) {
    FILE *f = fopen(file, "rb");
    if (!f) {
        perror("Erreur d'ouverture en lecture");
        return NULL;
    }

    noeud_t *head = NULL;
    noeud_t *tail = NULL; // O(1) ekleme yapmak için kuyruk pointer'ı
    int val;

    // Dosyadan int değerleri tek tek oku
    while (fread(&val, sizeof(int), 1, f) == 1) {
        noeud_t *nouveau = (noeud_t *)malloc(sizeof(noeud_t));
        if (nouveau) {
            nouveau->valeur = val;
            nouveau->next = NULL;

            if (head == NULL) {
                // Liste boşsa ilk eleman hem baş hem kuyruktur
                head = nouveau;
                tail = nouveau;
            } else {
                // Listede eleman varsa sadece kuyruğa ekle ve kuyruğu ilerlet
                tail->next = nouveau;
                tail = nouveau;
            }
        }
    }
    fclose(f);
    return head;
}

// Yardımcı Fonksiyon: Listeyi Yazdır
void afficher_liste(noeud_t *head) {
    while (head != NULL) {
        printf("%d -> ", head->valeur);
        head = head->next;
    }
    printf("NULL\n");
}

// Yardımcı Fonksiyon: Belleği Temizle (Exam Requirement)
void liberer_liste(noeud_t *head) {
    noeud_t *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    noeud_t *liste_originale = NULL;

    // Listeyi oluştur (Push başa eklediği için sıra 30 -> 20 -> 10 olur)
    push(&liste_originale, 10);
    push(&liste_originale, 20);
    push(&liste_originale, 30);

    printf("Liste originale : ");
    afficher_liste(liste_originale);

    // Diske kaydet
    sauvegarder_liste(liste_originale, "liste.bin");

    // Orijinal belleği temizle (Gerçekten dosyadan geldiğini kanıtlamak için)
    liberer_liste(liste_originale);
    liste_originale = NULL;

    // Dosyadan geri yükle
    noeud_t *liste_restauree = charger_liste("liste.bin");

    printf("Liste restauree : ");
    afficher_liste(liste_restauree);

    // İş bitiminde tekrar temizle
    liberer_liste(liste_restauree);

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
