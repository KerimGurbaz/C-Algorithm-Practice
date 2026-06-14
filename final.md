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
    free(tab);
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
#include <stdio.h>

// 1. Fonksiyon işaretçisi tipini (op_func) tanımla
// Anlamı: "İki int alıp bir int döndüren fonksiyonun adresi"
typedef int (*op_func)(int, int);

// --- TEST İÇİN HİPOTETİK FONKSİYONLAR ---
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int main() {
    // 2. Fonksiyon işaretçilerinden oluşan diziyi tanımla ve başlat
    op_func operations[] = {add, sub};

    // --- SINAV SENARYOSU: KULLANIM TESTİ ---
    int x = 10;
    int y = 4;

    // operations[0] -> add fonksiyonuna işaret eder
    // operations[1] -> sub fonksiyonuna işaret eder

    printf("Toplama (operations[0]): %d + %d = %d\n", x, y, operations[0](x, y));
    printf("Cikarma (operations[1]): %d - %d = %d\n", x, y, operations[1](x, y));

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // assert makrosu için gerekli kütüphane

// Düğüm yapısı
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// DİKKAT: Sınav sorusundaki imza Node **head olarak düzeltilmiştir.
void push_front(Node **head, int value) {
    // 1. Yeni düğüm için bellek ayır
    Node *new_node = (Node *)malloc(sizeof(Node));

    // 2. Bellek tahsisinin başarılı olduğundan emin ol
    // Eğer new_node NULL ise, program burada hata verip durur (abort).
    assert(new_node != NULL);

    // 3. Veriyi yeni düğüme kopyala
    new_node->data = value;

    // 4. Yeni düğümü mevcut listenin en başına bağla
    new_node->next = *head;

    // 5. Listenin başlangıç işaretçisini (head) yeni düğümü gösterecek şekilde güncelle
    *head = new_node;
}

// --- EKRANA YAZDIRMA (YARDIMCI FONKSİYON) ---
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// --- BELLEĞİ TEMİZLEME (YARDIMCI FONKSİYON) ---
void free_list(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    // Başlangıçta listemiz boş (head işaretçisi NULL)
    Node *head = NULL;

    printf("Listeye elemanlar ekleniyor...\n");

    // Fonksiyonu çağırırken 'head' işaretçisinin ADRESİNİ gönderiyoruz (&head)
    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);

    // Beklenen çıktı: 30 -> 20 -> 10 -> NULL
    print_list(head);

    // İşimiz bitince ayırdığımız dinamik belleği işletim sistemine iade ediyoruz
    free_list(head);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * Insère un nouveau maillon en tête de liste.
 * @param head  adresse du pointeur de tête (double pointeur pour modification)
 * @param value valeur à stocker dans le nouveau maillon
 */
void push_front(Node **head, int value) {
    // Allocation du nouveau maillon
    Node *new_node = (Node *)malloc(sizeof(Node));

    // Gestion des erreurs d'allocation avec assert
    assert(new_node != NULL);  // Stoppe le programme si malloc échoue

    // Initialisation du maillon
    new_node->data = value;
    new_node->next = *head;    // L'ancien premier devient le suivant

    // Mise à jour de la tête de liste
    *head = new_node;
}

int main() {
    Node *head = NULL;

    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);

    // Affichage : 30 -> 20 -> 10
    for (Node *p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");

    // Libération (basique)
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}

```

```c
#include <stdio.h>

int main() {
    // 1. Gerekli değişkenlerin tanımlanması
    int num1, num2;
    float float_num;

    // 2. Kullanıcıdan verilerin alınması
    printf("Iki tam sayi girin (aralarinda bosluk birakarak): ");
    // scanf fonksiyonunda '&' kullanımı kritiktir, değerin yazılacağı adresi gösterir.
    scanf("%d %d", &num1, &num2);

    printf("Bir ondalikli sayi girin: ");
    scanf("%f", &float_num);

    // 3. Hesaplamaların yapılması
    int sum = num1 + num2;

    // sum (int) ve float_num (float) toplandığında sonuç float olur.
    // 2 yerine 2.0 (veya 2.0f) kullanarak bölme işleminin float formatında kalmasını garantiliyoruz.
    float average = (sum + float_num) / 2.0f;

    // 4. Sonuçların formatlı şekilde ekrana yazdırılması
    printf("Tam sayilarin toplami: %d\n", sum);

    // %.3f belirleyicisi ile virgülden sonra tam olarak 3 basamak gösterilir.
    printf("Toplam ve ondalikli sayinin ortalamasi: %.3f\n", average);

    return 0;
}

```

```c
#include <stdio.h>

// Makro tanımı. Derleyici kodda VALUES gördüğü her yere süslü parantezli bloğu yazar.
#define VALUES {1, 2, 3, 4, 5, 6}

// Fonksiyon prototipi. int *arr yerine int arr[] de yazılabilir, derleyici için ikisi de aynıdır.
// Sadece bir bellek adresi (pointer) beklediğini belirtir.
void afficher_pairs(int *arr, int size) {
    printf("Elements pairs : ");

    // Gelen adresten başlayıp, boyut kadar ileri gidiyoruz
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    // 1. Diziyi makro ile başlat.
    int my_array[] = VALUES;

    // 2. Boyutu main içerisinde HESAPLA.
    // sizeof(my_array) -> Tüm dizinin bayt boyutu (örneğin 6 * 4 = 24 byte)
    // sizeof(my_array[0]) -> Tek bir int elemanın boyutu (örneğin 4 byte)
    // 24 / 4 = 6 eleman.
    int size = sizeof(my_array) / sizeof(my_array[0]);

    // 3. Fonksiyonu çağır. Dizinin adını yazmak, adresini (&my_array[0]) vermekle aynıdır.
    afficher_pairs(my_array, size);

    return 0;
}

void hatali_fonksiyon(int arr[]) {
    // BURASI YANLIŞTIR!
    int size = sizeof(arr) / sizeof(arr[0]);
    // arr artık bir dizi değil, sadece bir İŞARETÇİDİR (pointer).
    // 64-bit bir sistemde sizeof(arr) her zaman 8 byte döndürür.
    // 8 / 4 yaparsın ve size her zaman 2 çıkar. Dizi kaç elemanlı olursa olsun döngün 2. turda biter.
}

// KURAL: Dizi bir fonksiyona geçirildiği an boyut bilgisini kaybeder ve bir pointer'a dönüşür.
// Boyut hesaplaması her zaman dizinin orijinal olarak tanımlandığı scope'ta (kapsamda) yapılmalıdır.

```

```c
#include <stdio.h>

// Fonksiyon sadece işaretçi kabul ediyor.
void inverser_chaine(char *str) {
    // Güvenlik: Eğer boş bir adres gelirse çökmeyi engelle
    if (str == NULL) {
        return;
    }

    // 1. İşaretçileri başlangıç noktasına koy
    char *start = str;
    char *end = str;

    // 2. 'end' işaretçisini string'in sonuna ('\0') kadar götür
    while (*end != '\0') {
        end++;
    }

    // 3. '\0' karakterini ters çevirmek istemiyoruz, bir adım geri gelip son harfe odaklan
    end--;

    // 4. İşaretçiler ortada buluşana kadar karakterleri takas et (Swap)
    // Bellek adreslerini kıyaslıyoruz: start adresi, end adresinden daha küçük (solda) olduğu sürece
    while (start < end) {
        // Geçici değişkende start'ın GÖSTERDİĞİ değeri tut
        char temp = *start;

        // end'in gösterdiği değeri, start'ın gösterdiği yere kopyala
        *start = *end;

        // geçici değişkeni end'in gösterdiği yere kopyala
        *end = temp;

        // İşaretçileri birbirine doğru birer adım kaydır (Pointer Arithmetic)
        start++;
        end--;
    }
}

int main() {
    // --- KRİTİK NOKTA ---
    // char *text = "HEIG-VD"; YAZILAMAZ! (Read-Only)
    // char text[] formatı karakterleri değiştirilebilir Stack belleğine kopyalar.
    char text[] = "HEIG-VD";

    printf("Orijinal hali: %s\n", text);

    // Fonksiyonu çağırıyoruz. Dizinin ismi (text), ilk elemanın bellekteki adresini temsil eder.
    inverser_chaine(text);

    printf("Ters cevrilmis hali: %s\n", text);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int capacite = 2;            // Başlangıç kapasitesi
    int nb_elements = 0;         // Dizideki mevcut eleman sayısı
    int valeur;                  // Kullanıcıdan okunan sayı
    char fin;                    // 'q' kontrolü için karakter

    // 1. BAŞLANGIÇ BELLEĞİNİ AYIR (2 elemanlık)
    int *tab = (int*)malloc(capacite * sizeof(int));
    if (tab == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    printf("Entrez des nombres ('q' pour quitter):\n");

    // 2. KULLANICIDAN VERİ OKUMA DÖNGÜSÜ
    while (1) {
        // Önce bir tam sayı okumayı DENE
        if (scanf("%d", &valeur) == 1) {
            // Sayı başarıyla okundu

            // 2.1. DİZİ DOLU MU? → KAPASİTEYİ İKİ KATINA ÇIKAR
            if (nb_elements >= capacite) {
                int nouvelle_capacite = capacite * 2;

                // realloc: eski veriyi KORUR, yeni boyuta GENİŞLETİR
                int *temp = (int*)realloc(tab, nouvelle_capacite * sizeof(int));

                if (temp == NULL) {
                    fprintf(stderr, "Erreur de réallocation mémoire\n");
                    free(tab);  // Eski belleği temizle!
                    return 1;
                }

                // Başarılı: yeni adresi ata, kapasiteyi güncelle
                tab = temp;
                capacite = nouvelle_capacite;

                printf("  [Capacité augmentée à %d]\n", capacite);
            }

            // 2.2. SAYIYI DİZİYE EKLE
            tab[nb_elements] = valeur;
            nb_elements++;
        }
        else {
            // Sayı okunamadı → buffer'da ne var?
            scanf("%c", &fin);

            if (fin == 'q') {
                break;  // 'q' girildi → DÖNGÜDEN ÇIK
            }
            else {
                printf("  Entrée invalide, recommencez\n");
                // Buffer'ı temizle (kalan karakterleri at)
                while (getchar() != '\n');
            }
        }
    }

    // 3. SONUÇLARI YAZDIR
    printf("Vous avez saisi %d nombres\n", nb_elements);
    for (int i = 0; i < nb_elements; i++) {
        printf("%d", tab[i]);
        if (i < nb_elements - 1) {
            printf(" ");  // Son elemandan sonra boşluk YOK
        }
    }
    printf("\n");

    // 4. BELLEĞİ TEMİZLE
    free(tab);
    // tab = NULL;  // İyi pratik: dangling pointer'ı önle

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

/**
 * Matrisin her satırının toplamını hesaplar ve ekrana yazdırır.
 *
 * @param matrice  Satır başlıklarının başlangıç adresi (int **)
 * @param lignes   Toplam satır sayısı
 * @param colonnes Toplam sütun sayısı
 */
void somme_lignes(int **matrice, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        int somme = 0;

        // i. satırdaki tüm sütunları topla
        for (int j = 0; j < colonnes; j++) {
            somme += matrice[i][j];
        }

        printf("Somme ligne %d : %d\n", i, somme);
    }
}

int main() {
    int lignes, colonnes;

    // ===== 1. BOYUTLARI AL =====
    printf("Lignes : ");
    scanf("%d", &lignes);
    printf("Colonnes : ");
    scanf("%d", &colonnes);

    if (lignes <= 0 || colonnes <= 0) {
        printf("Dimensions invalides!\n");
        return 1;
    }

    // ===== 2. SATIR BAŞLIKLARI İÇİN BELLEK AYIR =====
    int **matrice = (int**)malloc(lignes * sizeof(int*));
    if (matrice == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    // ===== 3. HER SATIR İÇİN BELLEK AYIR =====
    for (int i = 0; i < lignes; i++) {
        matrice[i] = (int*)malloc(colonnes * sizeof(int));
        if (matrice[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            // Hata durumunda önceki satırları temizle!
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }

    // ===== 4. KULLANICIDAN DEĞERLERİ AL =====
    printf("Entrez les valeurs (%d x %d) :\n", lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("Ligne %d, colonne %d : ", i, j);
            scanf("%d", &matrice[i][j]);  // & UNUTMA!
        }
    }

    // ===== 5. SATIR TOPLAMLARINI HESAPLA VE YAZDIR =====
    printf("\n");
    somme_lignes(matrice, lignes, colonnes);

    // ===== 6. BELLEĞİ TEMİZLE (TERS SIRADA!) =====
    for (int i = 0; i < lignes; i++) {
        free(matrice[i]);  // ÖNCE her satır
    }
    free(matrice);          // SONRA satır başlıkları

    return 0;
}

```

```c
#include <stdio.h>

int main() {
    int nombre;

    // 1. KULLANICIDAN SAYI AL
    printf("Entrez un entier positif : ");
    if (scanf("%d", &nombre) != 1 || nombre <= 0) {
        printf("Veuillez entrer un entier positif valide.\n");
        return 1;
    }

    // 2. BASAMAK SAYISINI BUL (do..while)
    int compteur = 0;
    int temp = nombre;  // Orijinali koru

    do {
        temp = temp / 10;   // Sayıyı 10'a böl (bir basamak eksilt)
        compteur++;         // Basamak sayacını artır
    } while (temp > 0);     // Sayı 0 olana kadar DEVAM

    // 3. SONUCU YAZDIR
    printf("Le nombre %d contient %d chiffres\n", nombre, compteur);

    return 0;
}

```

```c
#include <stdio.h>

// Fonksiyon imzası: İki float işaretçisi ve dizinin boyutu
float produit_scalaire(float *v1, float *v2, int size) {
    float sum = 0.0f; // Toplamı tutacak değişken

    // Dizinin eleman sayısı kadar dönüyoruz
    for (int i = 0; i < size; i++) {
        // İşaretçilerin GÖSTERDİĞİ değerleri (*) al, çarp ve toplama ekle
        sum += (*v1) * (*v2);

        // İşaretçilerin kendisini (adresleri) bellekte bir sonraki elemana kaydır
        v1++;
        v2++;
    }

    return sum;
}

int main() {
    // --- SINAV SENARYOSU: KULLANIM TESTİ ---
    // Örnek iki vektör (dizi) tanımlıyoruz
    float array_A[] = {1.5f, 2.0f, 3.0f};
    float array_B[] = {2.0f, -1.0f, 4.0f};

    // Boyutu hesapla (sizeof numarasını önceki sorudan hatırlıyorsun)
    int size = sizeof(array_A) / sizeof(array_A[0]);

    // Dizilerin isimleri ilk elemanlarının adresleridir, bu yüzden doğrudan gönderiyoruz
    float result = produit_scalaire(array_A, array_B, size);

    // Beklenen hesap: (1.5 * 2.0) + (2.0 * -1.0) + (3.0 * 4.0) = 3.0 - 2.0 + 12.0 = 13.0
    printf("Produit scalaire: %.2f\n", result);

    return 0;
}

```

```c
#include <stdio.h>

// 1 ise palindrom, 0 ise değil
int est_palindrome(char *str) {
    // Güvenlik kontrolü
    if (str == NULL) {
        return 0;
    }

    char *start = str;
    char *end = str;

    // 1. 'end' işaretçisini string'in sonuna ('\0') kadar götür
    while (*end != '\0') {
        end++;
    }

    // İstisnai Durum: String tamamen boşsa (""), start ve end aynı yerdedir ('\0').
    // end-- yaparsak bellekte kendimize ait olmayan bir yere kayarız.
    // Boş string genelde palindrom kabul edilir (1 döndürürüz).
    if (start == end) {
        return 1;
    }

    // 2. İşaretçiyi '\0' karakterinden son gerçek karaktere geri çek
    end--;

    // 3. İşaretçiler birbirine doğru yaklaşırken karakterleri kıyasla
    while (start < end) {
        // Karakterler eşleşmiyorsa anında reddet (Büyük/küçük harf duyarlı)
        if (*start != *end) {
            return 0;
        }

        // Eşleşiyorsa bir sonraki harflere geç
        start++;
        end--;
    }

    // Döngü sorunsuz bittiyse kelime palindromdur
    return 1;
}

int main() {
    // --- SINAV SENARYOSU: KULLANIM TESTLERİ ---

    // Palindrom olanlar
    char *test1 = "kayak";
    char *test2 = "radar";
    char *test3 = "a";          // Tek harf palindromdur

    // Palindrom olmayanlar
    char *test4 = "HEIG-VD";
    char *test5 = "Radar";      // Büyük 'R' ve küçük 'r' eşit değildir (Sensible à la casse)
    char *test6 = "kayak ";     // Sonda boşluk var, baştaki 'k' ile eşleşmez

    printf("'%s' palindrom mu? %d\n", test1, est_palindrome(test1));
    printf("'%s' palindrom mu? %d\n", test2, est_palindrome(test2));
    printf("'%s' palindrom mu? %d\n", test3, est_palindrome(test3));
    printf("'%s' palindrom mu? %d\n", test4, est_palindrome(test4));
    printf("'%s' palindrom mu? %d\n", test5, est_palindrome(test5));
    printf("'%s' palindrom mu? %d\n", test6, est_palindrome(test6));

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 1;
    int count = 0;
    int input;

    // 1. Başlangıç için 1 elemanlık bellek tahsisi (malloc)
    int *arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("Baslangic bellek tahsisi basarisiz!\n");
        return 1;
    }

    printf("Tam sayilar girin (Durdurmak icin 'q' veya herhangi bir harf girin):\n");

    // 2. Kullanıcı geçerli bir tam sayı girdiği sürece döngü çalışır.
    // 'q' girildiğinde scanf 0 döndüreceği için döngü otomatik biter.
    while (scanf("%d", &input) == 1) {

        // 3. Sadece çift sayıları kabul et (Filtreleme)
        if (input % 2 == 0) {

            // 4. Kapasite doldu mu kontrolü
            if (count == capacity) {
                int new_capacity = capacity * 2;

                // KRİTİK NOKTA: Realloc işlemi için geçici bir pointer kullanıyoruz.
                int *temp = (int *)realloc(arr, new_capacity * sizeof(int));

                if (temp == NULL) {
                    // Bellek tahsisi başarısız oldu!
                    printf("Yeniden boyutlandirma sirasinda bellek hatasi!\n");
                    // Eski belleği kaybetmedik, güvenle iade edebiliriz.
                    free(arr);
                    return 1; // Programı hata koduyla sonlandır
                }

                // Tahsis başarılıysa, orijinal pointer'ımızı yeni adrese yönlendir
                arr = temp;
                capacity = new_capacity;
            }

            // 5. Sayıyı diziye kaydet ve eleman sayısını artır
            arr[count] = input;
            count++;
        }
    }

    // 6. Sonuçları ekrana yazdır
    printf("\nStocked even numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 7. Belleği iade et (Memory leak önleme)
    free(arr);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // 1. Kullanıcıdan N değerini al
    printf("Satir sayisini (N) girin: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Gecersiz giris.\n");
        return 1;
    }

    // 2. Ana omurgayı tahsis et (N adet int işaretçisi tutacak dizi)
    int **jagged_array = (int **)malloc(N * sizeof(int *));
    if (jagged_array == NULL) {
        printf("Omurga bellek tahsisi basarisiz!\n");
        return 1;
    }

    // 3. Her satır için merdiven mantığıyla bellek tahsis et ve doldur
    for (int i = 0; i < N; i++) {
        // i. satır için (i + 1) adet tam sayılık yer ayır
        jagged_array[i] = (int *)malloc((i + 1) * sizeof(int));

        // Hata Yönetimi: Eğer bu satırda bellek dolarsa,
        // şu ana kadar başarılı olan önceki satırları silip çıkmalıyız.
        if (jagged_array[i] == NULL) {
            printf("%d. satir icin bellek tahsisi basarisiz!\n", i);
            for (int k = 0; k < i; k++) {
                free(jagged_array[k]);
            }
            free(jagged_array);
            return 1;
        }

        // Veriyi doldur
        for (int j = 0; j < (i + 1); j++) {
            jagged_array[i][j] = i;
        }
    }

    // 4. Ekrana Yazdırma
    printf("\nTableau 'en escalier' (%d lignes):\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (i + 1); j++) {
            printf("%d ", jagged_array[i][j]);
        }
        printf("\n"); // Her satır bitiminde alt satıra geç
    }

    // 5. Belleği Temizleme (İçten dışa doğru)
    // Önce satırların (basamakların) kendisini iade et
    for (int i = 0; i < N; i++) {
        free(jagged_array[i]);
    }

    // Son olarak ana omurgayı (işaretçi dizisini) iade et
    free(jagged_array);

    return 0;
}

```

```c
#include <stdio.h>

int main() {
    char letter;
    int number;
    int scanf_result;

    printf("Saisissez un identifiant (Lettre-Chiffre, ex: X-42) : ");

    // Doğru giriş yapılana kadar sonsuz döngü
    while (1) {
        // 1. scanf'in kaç tane veriyi başarıyla okuduğunu değişkene kaydet
        scanf_result = scanf(" %c-%d", &letter, &number);

        // 2. BUFFER TEMİZLİĞİ (Vider le buffer d'entrée)
        // scanf okumayı başarsa da başaramasa da, kullanıcının bastığı 'Enter' (\n)
        // ve sonrasındaki olası çöp karakterleri bellekten siliyoruz.
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // İçeride hiçbir şey yapmıyoruz. Sadece karakterleri buffer'dan çekip yok ediyoruz.
        }

        // 3. Formata uyulup uyulmadığını kontrol et
        if (scanf_result == 2) {
            // Başarılı! İki eleman da formata uygun okundu.
            break; // Döngüden çık
        } else {
            // Hata! İstenen format sağlanmadı.
            printf("Format invalide, réessayez : ");
        }
    }

    // 4. Sonucu yazdır
    printf("\nIdentifiant valide !\n");
    printf("Lettre extraite : %c\n", letter);
    printf("Chiffre extrait : %d\n", number);

    return 0;
}

```

```c
#include <stdio.h>

// Fonksiyon sadece işaretçi ve boyut (size_t) kabul ediyor
void reverse_array(int *arr, size_t size) {
    // 1. Güvenlik kontrolü
    if (arr == NULL || size == 0) {
        return;
    }

    // 2. İşaretçileri konumlandır
    // Doğrudan son elemanın adresine zıpla (Pointer Arithmetic)
    // n - 1 yapıyoruz çünkü indisler 0'dan başlıyor.
    int *start = arr;                  // İlk elemanın adresi
    int *end = arr + size - 1;         // Son elemanın adresi

    // 3. İşaretçiler ortada buluşana kadar takas et
    while (start < end) {
        // Değerleri oku ve yer değiştir
        int temp = *start;
        *start = *end;
        *end = temp;

        // 4. İşaretçileri birbirine doğru kaydır (Pointer Arithmetic)
        start++;
        end--;
    }
}

int main() {
    // --- SINAV SENARYOSU: KULLANIM TESTİ ---
    int numbers[] = {1, 2, 3, 4, 5, 6};

    // Dizinin eleman sayısını hesapla
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Orijinal dizi: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Fonksiyonu çağır (dizinin adını göndermek, ilk elemanın adresini göndermektir)
    reverse_array(numbers, size);

    printf("Ters cevrilmis dizi: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

```

```c
#include <stdio.h>

// 1 ise Little-Endian, 0 ise Big-Endian döndürür
int is_little_endian(void) {
    // 1. Test sayımızı oluştur (Hex: 0x00000001)
    unsigned int test_val = 1;

    // 2. Sayının bellek adresini al ve bir karakter işaretçisine (char *) dönüştür.
    // char pointer, belleği sadece 1 baytlık (8-bit) pencerelerden görmemizi sağlar.
    char *first_byte = (char *)&test_val;

    // 3. İşaretçinin gösterdiği ilk baytı oku.
    // Eğer mimari Little-Endian ise (örn: Intel mimarisi), 1 değeri en başa yazılmıştır (*first_byte == 1).
    // Eğer Big-Endian ise, 0 değeri en başa yazılmıştır (*first_byte == 0).
    if (*first_byte == 1) {
        return 1;
    } else {
        return 0;
    }

    // Not: Sınavda zaman kazanmak için tüm fonksiyonu tek satırda şöyle yazabilirsin:
    // return (int)(*((char *)&test_val));
}

int main() {
    // --- SINAV SENARYOSU: KULLANIM TESTİ ---
    if (is_little_endian()) {
        printf("Mimari: Little-Endian\n");
    } else {
        printf("Mimari: Big-Endian\n");
    }

    return 0;
}

```

```c
#include <stdio.h>

/**
 * Makinenin Little-Endian olup olmadığını test eder.
 *
 * Mantık: int x = 1 bellekte ya [01][00][00][00] (Little)
 *         ya da [00][00][00][01] (Big) olarak saklanır.
 *         İlk byte'a bakarak anlarız.
 *
 * @return 1 → Little-Endian, 0 → Big-Endian
 */
int is_little_endian(void) {
    int x = 1;                           // 0x00000001
    char *ptr = (char*)&x;               // int'in adresini char* olarak al

    // ptr[0] = bellekteki İLK byte
    if (*ptr == 1) {                     // İlk byte 1 ise
        return 1;                        // → Little-Endian [01][00][00][00]
    } else {
        return 0;                        // → Big-Endian    [00][00][00][01]
    }
}

int main() {
    if (is_little_endian()) {
        printf("Bu makine Little-Endian.\n");
        printf("(Intel x86/AMD64 gibi)\n");
    } else {
        printf("Bu makine Big-Endian.\n");
        printf("(Motorola, PowerPC gibi)\n");
    }

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h> // malloc ve free için gerekli

// Parametredeki 'const' kelimesi, kopyalanacak orijinal string'i
// kazara değiştirmeyeceğimizin garantisini derleyiciye verir.
char *my_strdup(const char *s) {
    // 1. Güvenlik: Boş (NULL) bir pointer gelirse direkt NULL döndür.
    if (s == NULL) {
        return NULL;
    }

    // 2. Uzunluğu bul (strlen fonksiyonunun manuel hali)
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    // 3. Bellek Tahsisi
    // len kadar harf, +1 tane de '\0' karakteri için yer ayırıyoruz.
    char *new_str = (char *)malloc((len + 1) * sizeof(char));

    // 4. Bellek tahsisinin başarısız olma durumunu yönet (Kritik Adım)
    if (new_str == NULL) {
        return NULL;
    }

    // 5. Verileri kopyala
    // Döngü koşulunu "i <= len" yaptık.
    // Böylece i, len değerine ulaştığında sondaki '\0' karakterini de kopyalamış oluruz.
    for (int i = 0; i <= len; i++) {
        new_str[i] = s[i];
    }

    // 6. Yeni ayırdığımız ve içini doldurduğumuz belleğin adresini geri döndür
    return new_str;
}

int main() {
    // --- SINAV SENARYOSU: KULLANIM TESTİ ---
    const char *orijinal_metin = "HEIG-VD Data Engineering";

    // Kendi yazdığımız fonksiyonu çağırıyoruz
    char *kopya_metin = my_strdup(orijinal_metin);

    if (kopya_metin != NULL) {
        printf("Orijinal : %s\n", orijinal_metin);
        printf("Kopya    : %s\n", kopya_metin);

        // Orijinal metin ve kopya metin farklı bellek adreslerindedir.
        // Bunu kanıtlamak için kopyanın ilk harfini değiştirelim:
        kopya_metin[0] = 'X';
        printf("Degistirilmis Kopya: %s\n", kopya_metin);
        printf("Orijinal metin degismedi: %s\n", orijinal_metin);

        // my_strdup içinde malloc kullandık.
        // İşi biten bu belleği işletim sistemine iade etme sorumluluğu artık bizde.
        free(kopya_metin);
    } else {
        printf("Bellek tahsisi basarisiz oldu.\n");
    }

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
