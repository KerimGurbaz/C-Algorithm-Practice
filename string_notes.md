```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_UZUNLUK 256

// Görev 1: Cümleyi boşluklarıyla beraber eksiksiz okumak
int lire_ligne(char *buffer, int max_len) {
    int i = 0;
    int c;

    // getchar() bize kullanıcının girdiği her harfi tek tek getirir.
    // Kullanıcı Enter'a (\n) basana kadar veya dosya sonuna (EOF) gelene kadar oku.
    while ((c = getchar()) != '\n' && c != EOF) {

        // Güvenlik: Kullanıcı 300 harf girerse RAM'imiz (256) taşar ve program çöker.
        // Bu yüzden 'i' indeksimizin maksimum uzunluktan küçük olduğundan emin oluyoruz.
        if (i < max_len - 1) {
            buffer[i] = (char)c; // Harfi diziye yerleştir
            i++;
        }
    }

    // C dilinde bir karakter dizisinin (string) bittiğini belirtmek ZORUNLUDUR.
    // Son elemana '\0' (Null terminator) koymazsan program bellekteki çöpleri de okur.
    buffer[i] = '\0';

    // Hiçbir şey okunmadıysa hata (-1) döndür
    if (i == 0 && c == EOF) {
        return -1;
    }

    return i; // Okunan harf sayısını döndür
}

// Görev 2: Algoritmayı işletmek
bool verifier_parentheses(const char *texte) {
    int sayac = 0;

    // Metnin başından, bitiş karakterine ('\0') kadar dön
    for (int i = 0; texte[i] != '\0'; i++) {

        if (texte[i] == '(') {
            sayac++;
        }
        else if (texte[i] == ')') {
            sayac--;

            // Eğer sayaç eksiye düştüyse, ters parantez durumu vardır: ")( "
            if (sayac < 0) {
                return false;
            }
        }
    }

    // Döngü bittiğinde sayaç 0 ise (bütün açılanlar kapandıysa) true, değilse false döndür
    return sayac == 0;
}

int main(void) {
    char satir[MAX_UZUNLUK];

    printf("[?] Saisissez une ligne de mots et parentheses : ");

    // Önce okuma fonksiyonumuzu çağırıyoruz. Hata verdiyse programı durdur.
    if (lire_ligne(satir, MAX_UZUNLUK) == -1) {
        printf("[!] Okuma sirasinda hata olustu.\n");
        return 1;
    }

    // Okuduğumuz metni parantez testine sokuyoruz.
    if (verifier_parentheses(satir)) {
        printf("[i] Les parentheses sont bien equilibrees :)\n");
    } else {
        printf("[i] Il manque des parentheses :(\n");
    }

    return 0;
}

```

```c
#include <stdio.h>
// DİKKAT: <string.h> dahil edilmedi!

#define MAX_LIGNE 256

int main() {
    char ligne[MAX_LIGNE];
    char sous_chaine[MAX_LIGNE];

    printf("[?] Saisissez une ligne de mots: ");

    // 1. ADIM: fgets ile güvenli okuma
    if (fgets(ligne, MAX_LIGNE, stdin) == NULL) {
        printf("[!] Erreur de lecture.\n");
        return 1;
    }

    // 2. ADIM: Kendi strlen() fonksiyonumuzu yazıyoruz ve '\n' temizliyoruz
    int longueur = 0;
    while (ligne[longueur] != '\0') {
        // Eğer Enter tuşuna denk gelirsek, onu dizinin bitiş noktası yap
        if (ligne[longueur] == '\n') {
            ligne[longueur] = '\0';
            break;
        }
        longueur++;
    }

    // 3. ADIM: Boş satır kontrolü
    if (longueur == 0) {
        printf("[!] Erreur: La ligne est vide!\n");
        return 1;
    }

    printf("[i] La ligne contient %d caracteres.\n", longueur);

    // 4. ADIM: Başlangıç pozisyonunu güvenle alma
    int pos;
    printf("[?] Extraire APRES combien de caracteres? ");

    // scanf 1 dönmezse (harf girildiyse) VEYA pozisyon string'in dışındaysa hata ver.
    if (scanf("%d", &pos) != 1 || pos < 0 || pos >= longueur) {
        printf("[!] Erreur: position impossible!\n");
        return 1;
    }

    // 5. ADIM: Çıkarılacak karakter sayısını güvenle alma
    int len;
    printf("[?] Extraire combien de caracteres? ");

    // scanf 1 dönmezse VEYA sayı 0 ve altındaysa hata ver.
    if (scanf("%d", &len) != 1 || len <= 0) {
        printf("[!] Erreur: longueur impossible!\n");
        return 1;
    }

    // 6. ADIM: Alt Metin Çıkarma (Substring Extraction)
    int i = 0;
    // Orijinal dizinin sonuna ('\0') gelmediğimiz sürece VE
    // istenen 'len' miktarına ulaşana kadar harfleri kopyala.
    while (i < len && ligne[pos + i] != '\0') {
        sous_chaine[i] = ligne[pos + i];
        i++;
    }

    // YENİ DİZİNİN KURALI: C dilinde oluşturduğun her yeni metni '\0' ile mühürlemelisin.
    sous_chaine[i] = '\0';

    printf("[i] La sous-chaine extraite de la chaine est : \"%s\"\n", sous_chaine);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>   // strtoll taşmalarını (ERANGE) yakalamak için
#include <stdbool.h> // bool veri tipini kullanabilmek için

/* --- 1. KENDİ KÜTÜPHANEMİZ (<string.h> yasak) --- */

// Kendi strlen fonksiyonumuz: Bellekte '\0' görene kadar sayar
int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Girilen metnin tamamen sayılardan oluşup oluşmadığını denetler
bool isInteger(const char *str) {
    if (str == NULL || *str == '\0') return false;

    int i = 0;
    // İlk karakter işaret (+ veya -) olabilir
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    // Sadece işaret girildiyse (örneğin "+") geçersizdir
    if (str[i] == '\0') return false;

    // Kalan tüm karakterler rakam olmak zorundadır
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}

// Diziye dışarıdan karakter sıkıştırma (Sağa Kaydırma Algoritması)
void insChar(char *str, int pos, char c) {
    int len = my_strlen(str);

    // Sondaki '\0' dahil olmak üzere verileri pos'a kadar 1 birim sağa itiyoruz.
    // DİKKAT: Kaydırma işlemi daima SONDAN BAŞA doğru yapılmalıdır,
    // aksi takdirde harfleri birbirinin üstüne yazarak ezersiniz.
    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    }
    str[pos] = c; // Açılan boşluğa karakteri yerleştir
}

/* --- 2. ANA PROGRAM --- */

int main(int argc, char *argv[]) {
    // 1. Argüman sayısı kontrolü
    if (argc != 3) {
        printf("Usage: %s <integer 1> <integer 2>\n", argv[0]);
        return 1;
    }

    // 2. Tip kontrolü
    if (!isInteger(argv[1]) || !isInteger(argv[2])) {
        // Hoca örneklerde bu durum için özel bir çıktı belirtmemiş,
        // ancak programın çökmesini engellemek için durduruyoruz.
        printf("[e] Les arguments doivent etre des entiers.\n");
        return 1;
    }

    // 3. strtoll ile dönüşüm ve Overflow (Taşma) kontrolü
    errno = 0;
    long long a = strtoll(argv[1], NULL, 10);
    if (errno == ERANGE) {
        printf("[e] %s is too long!\n", argv[1]);
        return 1;
    }

    errno = 0;
    long long b = strtoll(argv[2], NULL, 10);
    if (errno == ERANGE) {
        printf("[e] %s is too long!\n", argv[2]);
        return 1;
    }

    // 4. Çarpma İşlemi Taşma (Multiplication Overflow) Kontrolü
    long long result = a * b;
    // StackOverflow matematiği: a sıfır değilse ve sonuç a'ya bölündüğünde b'yi vermiyorsa taşma vardır.
    if (a != 0 && result / a != b) {
        printf("[e] %lld * %lld is too long!\n", a, b);
        return 1;
    }

    // 5. Bellek İhtiyacını Hesaplama
    long long temp = result;
    int digits = 0;
    do {
        digits++;
        temp /= 10;
    } while (temp != 0);

    int is_neg = (result < 0) ? 1 : 0;
    int commas = (digits - 1) / 3; // Her 3 basamakta 1 ayraç

    // '\0' hariç ekranda görünecek toplam karakter sayısı
    int total_chars = digits + is_neg + commas;

    printf("[i] %d characters needed to store %lld\n", total_chars, result);

    // 6. Dinamik Bellek Tahsisi (Heap)
    // +1 eklemeyi unutmuyoruz çünkü C dilinde stringler '\0' ile mühürlenmek zorundadır.
    char *res_str = (char *)malloc((total_chars + 1) * sizeof(char));
    if (res_str == NULL) {
        printf("[!] Erreur d'allocation memoire.\n");
        return 1;
    }

    // 7. Ham sayıyı belleğe yazma (sprintf <stdio.h> kütüphanesine aittir, yasaklı değildir)
    sprintf(res_str, "%lld", result);

    // 8. Binlik ayraçları (Apostrof) yerleştirme
    int raw_len = digits + is_neg;
    int count = 0;

    // Sağdan sola (sondan başa) doğru okuyarak 3 adımda bir virgül koyuyoruz.
    // i > is_neg şartı, sayı negatifse en baştaki '-' işaretinin arkasına virgül konmasını engeller.
    for (int i = raw_len - 1; i > is_neg; i--) {
        count++;
        if (count % 3 == 0) {
            insChar(res_str, i, '\'');
        }
    }

    // 9. Sonucu yazdırma
    printf("[i] Result = %s\n", res_str);

    // Not: Normalde burada free(res_str) olmalıdır ancak sorudaki
    // "nous nous en dispenserons" (bunu es geçeceğiz) notundan dolayı yazılmadı.

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>  // strtoll, malloc
#include <stdbool.h> // bool
#include <errno.h>   // errno ve ERANGE kalkanı
#include <limits.h>  // LLONG_MAX, LLONG_MIN sabitleri

// -----------------------------------------------------------------------------
// 1. AŞAMA: KENDİ STRING ARAÇLARIMIZ (<string.h> YASAK)
// -----------------------------------------------------------------------------

size_t my_strlen(const char *str) {
    if (!str) return 0;
    const char *p = str;
    while (*p) p++;
    return (size_t)(p - str);
}

void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// -----------------------------------------------------------------------------
// 2. AŞAMA: GÜVENLİK VE DOĞRULAMA (VALIDATION)
// -----------------------------------------------------------------------------

// Kullanıcının "123A" veya sadece "+" girmesini engeller
bool isInteger(const char *str) {
    if (!str || !*str) return false;

    int i = 0;
    if (str[i] == '+' || str[i] == '-') i++;

    if (str[i] == '\0') return false; // Sadece işaret girildiyse reddet

    while (str[i]) {
        if (str[i] < '0' || str[i] > '9') return false;
        i++;
    }
    return true;
}

// Çarpma işlemi öncesi işlemcinin taşma (overflow) yaşayıp yaşamayacağını test eder
bool safe_multiply(long long a, long long b, long long *res) {
    if (a > 0 && b > 0 && a > LLONG_MAX / b) return false;
    if (a > 0 && b <= 0 && b < LLONG_MIN / a) return false;
    if (a <= 0 && b > 0 && a < LLONG_MIN / b) return false;
    if (a <= 0 && b <= 0 && a != 0 && b < LLONG_MAX / a) return false;

    *res = a * b;
    return true;
}

// -----------------------------------------------------------------------------
// 3. AŞAMA: FORMATLAMA VE KAYDIRMA
// -----------------------------------------------------------------------------

// Sayıyı string'e çevirir (sprintf yasaklı olduğu için)
void lltostr(long long val, char *buf) {
    if (val == 0) {
        buf[0] = '0'; buf[1] = '\0';
        return;
    }

    int i = 0;
    bool is_neg = false;
    unsigned long long uval;

    // LLONG_MIN (-9223372036854775808) tuzağı:
    // Doğrudan -1 ile çarparsan LLONG_MAX sınırını 1 birim aşar ve çöker.
    if (val < 0) {
        is_neg = true;
        uval = (unsigned long long)(-(val + 1)) + 1;
    } else {
        uval = val;
    }

    // Sayıyı sondan başa doğru metne dönüştür
    while (uval > 0) {
        buf[i++] = (uval % 10) + '0';
        uval /= 10;
    }
    if (is_neg) buf[i++] = '-';
    buf[i] = '\0';

    // Diziyi tersine çevir (örneğin "321" -> "123")
    for (int j = 0; j < i / 2; j++) {
        char tmp = buf[j];
        buf[j] = buf[i - 1 - j];
        buf[i - 1 - j] = tmp;
    }
}

// Dizinin içindeki harfleri sağa kaydırarak istenen indekse karakter sokar
void insChar(char *str, int pos, char c) {
    int len = my_strlen(str);
    // '\0' dahil olmak üzere her şeyi sağa itiyoruz
    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    }
    str[pos] = c;
}

// -----------------------------------------------------------------------------
// 4. AŞAMA: ANA PROGRAM BEYNİ
// -----------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    // 1. Argüman Kontrolü
    if (argc != 3) {
        printf("Usage: %s <integer 1> <integer 2>\n", argv[0]);
        return 1;
    }

    // 2. Karakter kirliliği kontrolü
    if (!isInteger(argv[1]) || !isInteger(argv[2])) {
        // Soru özel olarak isInteger hatasını yazdırmayı zorunlu kılmamış,
        // ancak güvende kalmak için kontrol ediyoruz.
        return 1;
    }

    // 3. Dönüşüm ve 64-bit Sınır Kontrolü (ERANGE)
    errno = 0;
    long long a = strtoll(argv[1], NULL, 10);
    if (errno == ERANGE) {
        printf("[e] %s is too long!\n", argv[1]);
        return 1;
    }

    errno = 0;
    long long b = strtoll(argv[2], NULL, 10);
    if (errno == ERANGE) {
        printf("[e] %s is too long!\n", argv[2]);
        return 1;
    }

    // 4. Çarpma Taşması Kontrolü
    long long res;
    if (!safe_multiply(a, b, &res)) {
        printf("[e] %lld * %lld is too long!\n", a, b);
        return 1;
    }

    // 5. Bellek (RAM) İhtiyaç Analizi
    char temp_buf[30];
    lltostr(res, temp_buf);

    int raw_len = my_strlen(temp_buf); // İşaret dahil uzunluk
    int is_neg = (res < 0) ? 1 : 0;
    int digits = raw_len - is_neg;     // Sadece rakamların sayısı
    int num_seps = (digits - 1) / 3;   // Gereken "'" ayracı sayısı

    int total_len = raw_len + num_seps; // '\0' hariç gerekli toplam karakter sayısı

    printf("[i] %d characters needed to store %lld\n", total_len, res);

    // 6. Dinamik Bellek Tahsisi (+1 Null Terminator için)
    char *final_str = malloc(total_len + 1);
    if (!final_str) {
        return 1; // Bellek ayrılamazsa çık
    }

    // Ham metni yeni belleğe kopyala
    my_strcpy(final_str, temp_buf);

    // 7. Ayıraçları Ekleme (SAĞDAN SOLA DOĞRU)
    // Soldan başlarsak eklenen her ayıraç dizinin indekslerini sağa kaydıracağı için
    // matematik şaşar. Bu yüzden dizinin sonundan başa doğru geliyoruz.
    int i = raw_len - 3;
    while (i > is_neg) {
        insChar(final_str, i, '\'');
        i -= 3;
    }

    printf("[i] Result = %s\n", final_str);

    // Sorunun 'NB' notuna istinaden free(final_str) atlanmıştır.
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
