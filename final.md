```c
#include <stdio.h>

void fibo(int n) {
    int premier = 0;
    int seconde = 1;
    int suivant; // Gelecekteki sayıyı tutmak için

    // Tam olarak 'n' defa dönecek bir döngü kuruyoruz
    for (int i = 0; i < n; i++) {
        // Adım 1: Mevcut terimi yazdır
        printf("%d ", premier);

        // Adım 2: Bir sonraki sayıyı hesapla
        suivant = premier + seconde;

        // Adım 3: Pencereyi sağa kaydır (Değişkenleri güncelle)
        // Dikkat: Kaydırma sırası önemlidir. Önce premier güncellenmeli.
        premier = seconde;
        seconde = suivant;
    }
    printf("\n"); // Çıktıyı temiz bitirmek için yeni satır
}

int main() {
    int n;
    printf("Entrez une valeur : "); // Kullanıcı dostu ve dilbilgisi düzeltilmiş mesaj

    // Güvenli girdi alma. Girdi rakam değilse veya negatifse sonlandır.
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Erreur : Veuillez entrer un entier positif.\n");
        return 1;
    }

    fibo(n);

    return 0;
}

```

```c
#include <stdio.h>

/**
 * Bir dizideki minimum ve maksimum değerleri TEK geçişte bulur.
 *
 * @param tab  İncelenecek dizi (const: değiştirilmeyecek)
 * @param size Dizinin boyutu
 * @param mn   Minimum değerin YAZILACAĞI adres (çıktı parametresi)
 * @param mx   Maksimum değerin YAZILACAĞI adres (çıktı parametresi)
 */
void trouver_min_max(const int tab[], int size, int *mn, int *mx) {

    // İlk elemanı başlangıç değeri olarak ata
    *mn = tab[0];  // pointer'ın gösterdiği yere tab[0] yaz
    *mx = tab[0];  // pointer'ın gösterdiği yere tab[0] yaz

    // 1. indexten başla (0'ı zaten atadık)
    for (int i = 1; i < size; i++) {

        // Maksimumdan büyük bir değer bulundu mu?
        if (tab[i] > *mx) {
            *mx = tab[i];  // Maksimumu güncelle
        }

        // Minimumdan küçük bir değer bulundu mu?
        if (tab[i] < *mn) {
            *mn = tab[i];  // Minimumu güncelle
        }
    }
    // Fonksiyon bitince mn ve mx güncellenmiş olur!
}

/**
 * Diziyi ekrana yazdırır
 */
void afficher_tableau(const int tab[], int size) {
    printf("Tableau: [");
    for (int i = 0; i < size; i++) {
        printf("%d", tab[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    // Test dizisi
    int tab[] = {12, 5, 8, 19, 1, 7};

    // Dizi boyutunu hesapla (toplam byte / bir elemanın byte'ı)
    int size = sizeof(tab) / sizeof(tab[0]);

    // Minimum ve maksimum için değişkenler (BOŞ!)
    int minimum = 0;
    int maximum = 0;

    // Diziyi göster
    afficher_tableau(tab, size);
    printf("Taille du tableau: %d elements\n\n", size);

    // Fonksiyonu çağır: değişkenlerin ADRESLERİNİ geç!
    trouver_min_max(tab, size, &minimum, &maximum);
    //                          │         │
    //                          │         └─ maximum'un adresi
    //                          └─ minimum'un adresi

    // Fonksiyon içinde *mn ve *mx bu değişkenleri GÜNCELLEDİ!
    printf("Resultats:\n");
    printf("  Valeur minimale: %d\n", minimum);
    printf("  Valeur maximale: %d\n", maximum);

    // Doğrulama
    printf("\nVerification: min=1, max=19 → %s\n",
           (minimum == 1 && maximum == 19) ? "CORRECT ✓" : "ERREUR ✗");

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h>  // strcpy için

/**
 * Bir string'deki TÜM boşluk karakterlerini siler.
 * İşlem YERİNDE (in-place) yapılır, yeni bellek ayrılmaz.
 *
 * Çalışma mantığı: İKİ POINTER TEKNİĞİ
 *   - p_lecture:  Kaynak karakterleri okur
 *   - p_ecriture: Boşluk olmayanları YAZAR (sola kaydırır)
 *
 * @param str Üzerinde işlem yapılacak string (DEĞİŞTİRİLİR!)
 */
void supprimer_espaces(char *str) {

    // İki pointer: biri OKUR, diğeri YAZAR
    char *p_lecture  = str;  // Kaynak (nereden okuyacağız)
    char *p_ecriture = str;  // Hedef (nereye yazacağız)

    // String sonuna kadar tara
    while (*p_lecture != '\0') {

        // Boşluk DEĞİLSE: karakteri sola KOPYALA
        if (*p_lecture != ' ') {
            *p_ecriture = *p_lecture;  // Karakteri yaz
            p_ecriture++;              // Yazma pointer'ını İLERLET
        }
        // Boşluk ise: ATLA (yazma pointer'ı İLERLEMEZ!)

        p_lecture++;  // Okuma pointer'ı HER ZAMAN ilerler
    }

    // String'i SONLANDIR (yeni sona null karakter koy)
    *p_ecriture = '\0';
}

int main() {
    // ✅ DİZİ olarak tanımla (DEĞİŞTİRİLEBİLİR!)
    char str[] = "Programmation en C";
    // VEYA: char str[50]; strcpy(str, "Programmation en C");

    printf("Avant:  \"%s\"\n", str);

    supprimer_espaces(str);

    printf("Apres:  \"%s\"\n", str);
    printf("Attendu: \"ProgrammationenC\"\n");

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;              // Kaç eleman var
    int capacity = 2;       // Mevcut kapasite
    int valeur;             // Kullanıcıdan okunan değer

    // 1. BAŞLANGIÇ BELLEĞİ AYIR (2 elemanlık)
    int *tab = malloc(capacity * sizeof(int));
    if (tab == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    printf("Entrez des nombres positifs (négatif pour arrêter):\n");

    // 2. KULLANICIDAN SAYILARI OKU
    while (1) {
        printf("  Nombre %d: ", n + 1);
        if (scanf("%d", &valeur) != 1) {
            printf("Entrée invalide, ignorée.\n");
            while (getchar() != '\n');  // Tamponu temizle
            continue;
        }

        // Negatif sayı → DUR!
        if (valeur < 0) {
            printf("Nombre négatif détecté, arrêt de la saisie.\n");
            break;
        }

        // 3. DOLU MU? → KAPASİTEYİ İKİ KATINA ÇIKAR
        if (n >= capacity) {
            int nouvelle_capacity = capacity * 2;

            // realloc: eski belleği KORUR, yeni boyuta genişletir
            int *temp = realloc(tab, nouvelle_capacity * sizeof(int));

            if (temp == NULL) {
                fprintf(stderr, "Erreur de réallocation mémoire\n");
                free(tab);  // Eski belleği temizle!
                return 1;
            }

            // Başarılı! Yeni adresi ata
            tab = temp;
            capacity = nouvelle_capacity;

            printf("  [Capacité augmentée à %d]\n", capacity);
        }

        // 4. DEĞERİ EKLE
        tab[n] = valeur;
        n++;
    }

    // 5. SONUÇLARI GÖSTER
    printf("\n=== RÉSULTATS ===\n");
    printf("Nombre d'éléments: %d\n", n);
    printf("Capacité finale: %d\n", capacity);
    printf("Contenu du tableau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    // 6. BELLEĞİ TEMİZLE
    free(tab);-
    // tab = NULL;  // İyi pratik: dangling pointer'ı önle

    return 0;
}

```

````c
Dinamik 2D matrisler (iki boyutlu diziler), C programlamada bellek yönetiminin en zorlu ama en öğretici konularından biridir. Sınavlarda bu sorunun çıkma nedeni, senin `int ` (işaretçinin işaretçisi) kavramını ve çoklu `malloc` / `free` döngülerini doğru kurgulayıp kurgulayamadığını ölçmektir.

### Zihinsel Model: İşaretçilerin İşaretçisi (`int `)

C dilinde 2D dinamik dizi yaratırken tek bir büyük blok ayırmayız. İşlem iki aşamalıdır:

1. **Dikey Eksen (Ana Dizi):** Önce satırların *başlangıç adreslerini* tutacak olan bir işaretçi dizisi ayırırız. Bunun tipi `int ` olur (Çünkü içinde `int *` tutar).
2. **Yatay Eksen (Satırlar):** Sonra bir `for` döngüsüyle ana dizinin her bir elemanı için bellekte ayrı bir dizi (satır) ayırırız (`int *`).

Bu yapı, `matrice[i][j]` sözdizimini (syntax) kullanabilmeni sağlar. `i` satırı, `j` ise o satırdaki sütunu bulur.

### Kritik Kırılma Noktaları (Sınav Tuzakları)

* **Temizlik Sırası:** Yaratırken "önce ana dizi, sonra satırlar" sırasını izlersin. Yıkarken (free) ise **tam tersi** sırayı izlemek zorundasın: "Önce satırlar, en son ana dizi".

### Sınav Standardında Çözüm

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Entrez la dimension N de la matrice carree : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erreur : Veuillez entrer un entier positif strict.\n");
        return 1;
    }

    // 1. Allocation du tableau principal (Ana dizi: Satir isaretcilerini tutar)
    // Tipi int** cunku elemanlari int* olacak.
    int **matrice = malloc(n * sizeof(int *));
    if (matrice == NULL) {
        printf("Erreur d'allocation pour le tableau de pointeurs.\n");
        return 1;
    }

    // 2. Allocation des lignes (Satirlarin bagimsiz olarak tahsisi)
    for (int i = 0; i < n; i++) {
        matrice[i] = malloc(n * sizeof(int));

        // Hata Yonetimi: Eger bir satir icin bellek ayrilamazsa
        if (matrice[i] == NULL) {
            printf("Erreur d'allocation pour la ligne %d.\n", i);

            // O ana kadar basariyla ayrilmis tum satirlari temizle
            for (int k = 0; k < i; k++) {
                free(matrice[k]);
            }
            // Son olarak ana diziyi temizle ve cik
            free(matrice);
            return 1;
        }
    }

    // 3. Remplissage de la matrice identite (Matrisi doldurma)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Ana kosegen uzerindeki elemanlarin satir ve sutun indeksleri esittir
            if (i == j) {
                matrice[i][j] = 1;
            } else {
                matrice[i][j] = 0;
            }
        }
    }

    // 4. Affichage (Ekrana yazdirma)
    printf("\nMatrice Identite %d x %d :\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n"); // Her satir bitiminde alt satira gec
    }

    // 5. Liberation de la memoire (Hafizayi iade etme)
    // DIKKAT: Sildigimiz sira, yarattigimiz siranin tam tersidir!
    for (int i = 0; i < n; i++) {
        free(matrice[i]); // Once yapraklari (satirlari) kopar
    }
    free(matrice); // En son agacin govdesini (ana diziyi) kes

    return 0;
}

````

```c
#include <stdio.h>

char *my_strcpy(char *dest, const char *src) {
    // 1. Capa (Ancre) atiyoruz.
    // Fonksiyon sonunda bu adresi dondurecegiz.
    char *debut = dest;

    // 2. Kopyalama dongusu.
    // src'nin isaret ettigi karakter \0 (kelime sonu) olmadigi surece don.
    while (*src != '\0') {
        *dest = *src; // Karakteri kopyala
        dest++;       // Hedef adresi bir ileri kaydir
        src++;        // Kaynak adresi bir ileri kaydir
    }

    // 3. Terminaison (Sonlandirma)
    // Dongu bittiginde src \0 uzerindedir ama bunu dest'e kopyalamadik.
    // Metnin sonuna bitis sinyalini manuel olarak ekliyoruz.
    *dest = '\0';

    // 4. Kaydettigimiz baslangic adresini geri dondur.
    return debut;
}

int main() {
    char buffer[50]; // Degistirilebilir yigin (stack) bellegi

    // Fonksiyonu hem calistirip hem de donen adresi printf ile okuyabiliriz
    printf("Resultat : %s\n", my_strcpy(buffer, "Bonjour"));

    return 0;
}


```

```c
char *my_strcpy_pro(char *dest, const char *src) {
    char *debut = dest; // Adresi mutlaka kaydetmeliyiz

    // Kopyala, kontrol et ve ilerle. Her sey tek satirda.
    // Dongu icinde yapilacak is kalmadigi icin govde bos kalir (;).
    while (*dest++ = *src++);

    return debut;
}

```

```c
#include <stdio.h>

// Makro tanimi tek satira sigmadiginda satiri '\' ile kirarak devam ederiz.
// #val ifadesi: Makroya gelen parametrenin ADINI cift tirnak icinde bir string'e cevirir.
#define PRINT_VAR(val) _Generic((val), \
    int: printf("%s = %d\n", #val, val), \
    float: printf("%s = %.2f\n", #val, val), \
    double: printf("%s = %.2f\n", #val, val), \
    char: printf("%s = %c\n", #val, val) \
)

int main() {
    int a = 42;
    float b = 3.14;
    char c = 'Z';

    PRINT_VAR(a);
    PRINT_VAR(b);
    PRINT_VAR(c);

    return 0;
}

```

```c
#include <stdio.h>

/**
 * Değişkenin ADINI ve DEĞERİNİ yazdırır.
 * Tipine göre doğru format'ı OTOMATİK seçer.
 *
 * # operatörü: değişken adını STRING'e çevirir
 * _Generic: değişkenin TİPİNE göre format seçer
 */
#define PRINT_VAR(val) \
    printf("%s = ", #val); \
    _Generic((val), \
        int:    printf("%d", val), \
        float:  printf("%.2f", val), \
        double: printf("%.2f", val), \
        char:   printf("%c", val), \
        default: printf("?") \
    )

int main() {
    int a = 42;
    float b = 3.14f;
    char c = 'Z';

    PRINT_VAR(a);  // a = 42
    PRINT_VAR(b);  // b = 3.14
    PRINT_VAR(c);  // c = Z

    printf("\n");  // Son satır

    // Bonus test
    double d = 2.71828;
    PRINT_VAR(d);  // d = 2.72
    printf("\n");

    return 0;
}

```

```c
#include <stdio.h>

void print_binary(unsigned int n) {
    // Uç durum (Edge Case): Sayı 0 ise maske taramasına girmeye gerek yok.
    if (n == 0) {
        printf("0\n");
        return;
    }

    // Baslangic Maskesi: Sadece en soldaki bit (31. bit) 1, digerleri 0.
    // 1U, "1 sayisini Unsigned (isaretsiz) olarak tut" demektir.
    unsigned int mask = 1U << 31;

    // 1. ASAMA: Bastaki anlamsiz sifirlari (leading zeros) atla.
    // Eger n'in maskelenen biti 0 ise, yazdirma yapmadan maskeyi 1 adim saga kaydir.
    while ((n & mask) == 0) {
        mask >>= 1;
    }

    // 2. ASAMA: Ilk gecerli biti bulduk. Artik maske kaybolana (0 olana) kadar bas.
    while (mask > 0) {
        // n ile maskenin kesisimi 0'dan farkliysa, n'in o anki biti 1'dir.
        if ((n & mask) != 0) {
            printf("1");
        } else {
            printf("0");
        }

        // Bir sonraki bite gecmek icin maskeyi saga kaydir.
        mask >>= 1;
    }

    printf("\n");
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t size;
    // Anonymous union (C11 standardi).
    // Bellekte data dizisi ile sdata struct'i ayni 16 byte'i paylasir.
    union {
        char data[16];
        struct {
            char *ptr;
            size_t capacity;
        } sdata;
    };
} string_t;

// Dizgiyi (string) SSO yapisina ceviren fonksiyon
string_t to_string(const char *str) {
    string_t s;

    // Guvenlik: Null pointer kontrolu
    if (str == NULL) {
        s.size = 0;
        s.data[0] = '\0';
        return s;
    }

    s.size = strlen(str);

    // Kiritik Karar Noktasi: SSO mu Yoksa Dinamik Bellek mi?
    if (s.size <= 15) {
        // SMALL STRING: Malloc YOK. Veriyi dogrudan union icindeki diziye kopyala.
        strcpy(s.data, str);
    } else {
        // LARGE STRING: Malloc VAR. Veri sigmadigi icin disaridan bellek aliyoruz.
        s.sdata.capacity = s.size + 1; // +1 terminatör (\0) icin
        s.sdata.ptr = malloc(s.sdata.capacity);

        // Malloc basarisiz olursa programin cokmemesi icin kontrol
        if (s.sdata.ptr != NULL) {
            strcpy(s.sdata.ptr, str);
        } else {
            // Hata yonetimi: Bellek yoksa bos string dondur
            s.size = 0;
            s.data[0] = '\0';
        }
    }

    return s;
}

// Hafizayi temizleyen (Destructor) fonksiyon
void clear_string(string_t *s) {
    if (s == NULL) return;

    // En Olumcul Tuzak: Sadece dinamik tahsis yapildiysa free() cagrilmalidir!
    if (s->size > 15) {
        free(s->sdata.ptr);
    }

    // Yapiyi sifirlayarak askida kalan (dangling) durumlari onle
    s->size = 0;
    s->data[0] = '\0';
}

```

```c
#include <stdio.h>
#define MODE 3
int main() {

    #if MODE == 1
        printf("Mode DEBUG actif\n");
    #elif MODE == 2
        printf("Mode RELEASE actif\n");
    #elif MODE == 3
        printf("Mode TEST actif\n");
    #else
        printf("Mode inconnu\n");
    #endif

    return 0;
}

```

```c
// ============ bits.h ============

#ifndef BITS_H
#define BITS_H

#include <stdint.h>

/**
 * Belirtilen biti 1 YAPAR.
 * Örnek: SET_BIT(x, 3) → x'in 3. biti 1 olur
 */
#define SET_BIT(word, pos)         ((word) |= (1U << (pos)))

/**
 * Belirtilen biti 0 YAPAR.
 * Örnek: CLEAR_BIT(x, 3) → x'in 3. biti 0 olur
 */
#define CLEAR_BIT(word, pos)       ((word) &= ~(1U << (pos)))

/**
 * Belirtilen biti TERSLER (0→1, 1→0).
 * Örnek: TOGGLE_BIT(x, 3) → x'in 3. biti terslenir
 */
#define TOGGLE_BIT(word, pos)      ((word) ^= (1U << (pos)))

/**
 * Belirtilen biti TEST EDER.
 * @return 1 ise 1, 0 ise 0
 * Örnek: if (CHECK_BIT(x, 3)) → bit 3 = 1 ise TRUE
 */
#define CHECK_BIT(word, pos)       (((word) >> (pos)) & 1U)

/**
 * Belirtilen bit ARALIĞINI değiştirir.
 * [start, start+length-1] aralığına value yazılır.
 *
 * @param word   Değiştirilecek değişken
 * @param start  Başlangıç bit pozisyonu
 * @param length Kaç bit değişecek
 * @param value  Yeni değer (length bitlik)
 *
 * Örnek: SET_RANGE(x, 4, 4, 0b1010) → bit 4-7 arası = 1010
 *
 * do-while(0): if(x) SET_RANGE(...); else ... → SORUNSUZ!
 */
#define SET_RANGE(word, start, length, value) \
    do { \
        uint32_t mask = ((1U << (length)) - 1U) << (start); \
        (word) = ((word) & ~mask) | (((value) << (start)) & mask); \
    } while(0)

#endif // BITS_H

```

```c
#include <stdio.h>
#include <stdint.h>

// Makro Aciklamasi:
// 1. (n << 2)       : n'i 4 ile carpar (Aritmetik operator kullanmadan).
// 2. word >> (...)  : Hedef nibble'i en saga (0. bite) yaslar.
// 3. & 0xFU         : Diger tum sol bitleri siler, sadece en sagdaki 4 biti birakir. (U = Unsigned guvenligi)
#define GET_NIBBLE(word, n) (((word) >> ((n) << 2)) & 0xFU)

int main() {
    // Test icin anlasilmasi kolay bir Hexadecimal (On altilik) sayi seciyoruz.
    // Her bir harf/rakam tam olarak 1 Nibble'a (4 bit) denk gelir.
    uint32_t data = 0xDEADBEEF;

    // Nibble'lari tersten (en sagdan baslayarak) okuyoruz
    printf("0. Nibble (En sag): %X\n", GET_NIBBLE(data, 0)); // Beklenen: F
    printf("1. Nibble         : %X\n", GET_NIBBLE(data, 1)); // Beklenen: E
    printf("2. Nibble         : %X\n", GET_NIBBLE(data, 2)); // Beklenen: E
    printf("3. Nibble         : %X\n", GET_NIBBLE(data, 3)); // Beklenen: B
    printf("7. Nibble (En sol): %X\n", GET_NIBBLE(data, 7)); // Beklenen: D

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// Sınavda genellikle yapının içi verilmez, sadece adı verilir.
// Test edebilmemiz için örnek bir yapı tanımlıyorum.
typedef struct {
    int id;
    float value;
} record_t;

// Asıl istenen fonksiyon
int read_nth_record(FILE *f, int n, record_t *out) {
    // 1. Parametrelerin geçerliliğini kontrol et
    if (f == NULL || out == NULL || n < 0) {
        return 0; // Başarısız
    }

    // 2. Atlama (offset) miktarını bayt cinsinden hesapla
    // n=0 için sadece 64 byte atlar, n=1 için 64 + 1 kayıt boyutu kadar atlar.
    long offset = 64 + (n * sizeof(record_t));

    // 3. Dosya imlecini hesaplanan offset'e taşı
    // SEEK_SET: Hesaplamaya dosyanın en başından başla demektir.
    if (fseek(f, offset, SEEK_SET) != 0) {
        return 0; // Başarısız (Örn: Dosya o kadar uzun değil)
    }

    // 4. Veriyi oku
    // okunan_oge_sayisi = fread(yazilacak_adres, oge_boyutu, oge_sayisi, dosya)
    size_t read_count = fread(out, sizeof(record_t), 1, f);

    // 5. Başarı durumunu döndür
    if (read_count == 1) {
        return 1; // Başarılı
    }

    return 0; // Başarısız (Örn: Dosya sonuna - EOF - gelindi)
}

int main() {
    // --- TEST ORTAMI HAZIRLIĞI ---
    // Önce hayali "data.bin" dosyamızı oluşturup içine veri yazalım ki okuyabilelim.
    FILE *f_write = fopen("data.bin", "wb");
    if (f_write) {
        char header[64] = {0}; // 64 baytlık çöp veri (başlık)
        fwrite(header, 1, 64, f_write);

        record_t r0 = {100, 1.5f}; // İndeks 0
        record_t r1 = {200, 2.5f}; // İndeks 1
        record_t r2 = {300, 3.5f}; // İndeks 2

        fwrite(&r0, sizeof(record_t), 1, f_write);
        fwrite(&r1, sizeof(record_t), 1, f_write);
        fwrite(&r2, sizeof(record_t), 1, f_write);
        fclose(f_write);
    }

    // --- SINAV SENARYOSU BAŞLANGICI ---
    FILE *f = fopen("data.bin", "rb");
    if (f == NULL) {
        return 1;
    }

    record_t my_record;
    int target_index = 2; // 2 numaralı indeksi (3. kaydı) okumak istiyoruz

    if (read_nth_record(f, target_index, &my_record)) {
        printf("Basarili! %d. indeksteki kayit: ID = %d, Deger = %.2f\n",
                target_index, my_record.id, my_record.value);
    } else {
        printf("Kayit okunamadi.\n");
    }

    fclose(f);
    return 0;
}

```

```c
// 1. fseek DÖNÜŞ DEĞERİ (En sık yapılan hata)
// C fonksiyonlarının çoğu başarı durumunda 1 döndürür algısı yanlıştır.
// fseek başarı durumunda 0 (sıfır) döndürür.
if (fseek(f, offset, SEEK_SET) != 0) {
    return 0; // Hata durumuna düştük!
}

// 2. YAPI HİZALAMASI (Struct Padding)
// Boyut hesaplarken ASLA yapının içindeki değişkenlerin boyutlarını
// manuel toplama: (sizeof(int) + sizeof(float)).
// Derleyici performansı artırmak için araya gizli boşluklar (padding) atabilir.
// Daima derleyicinin hesapladığı gerçek boyutu kullan:
long offset = 64 + (n * sizeof(record_t));

```

```c
#include <stdio.h>

// Makroyu çok satırlı yazmak okunabilirliği artırır.
// Her satırın sonundaki '\' (ters slaş) makronun alt satırda devam ettiğini belirtir.
#define DEFINE_AND_PRINT(type, name, val) \
    type var_##name = val; \
    printf("%s = %d\n", #name, var_##name)
    // printf(#name " = %d\n", var_##name)

int main() {
    // Sınav sorusundaki örnek çağrı
    DEFINE_AND_PRINT(int, age, 38);

    // İşlemin başarılı olduğunu ve 'var_age' değişkeninin
    // makro dışında da gerçekten var olduğunu kanıtlayalım:
    printf("Makro disinda erisim: var_age'in karesi = %d\n", var_age * var_age);

    // Farklı tiplerle de çalıştığını görelim
    DEFINE_AND_PRINT(char, initial, 65); // 65, 'A' karakterinin ASCII kodudur (integer olarak yazdırılır)

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

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
