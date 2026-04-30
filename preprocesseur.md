
```c
#include <stdbool.h>
#include <stdio.h>

// --- KONFİGÜRASYON BÖLÜMÜ ---
#define CONFIG_VERSION 23
#define CONFIG_STACK_PROTECTION

//#define CONFIG_OS_WIN     
#define CONFIG_OS_LINUX     

// GÖREV 3: Eğer ne WIN ne de LINUX tanımlanmamışsa derlemeyi durdur.
// Bunu struct'ın içine değil, en tepeye yazmak en güvenli mühendislik pratiğidir.
#if !defined(CONFIG_OS_WIN) && !defined(CONFIG_OS_LINUX)
#error "Erreur de compilation : Aucun OS defini (WIN ou LINUX requis)."
#endif


// GÖREV 4: Yapının tüm üyeleri 16 byte'a hizalanmalı.
// Derleyiciye bu struct'ın bellekteki yerleşimini 16 byte bloklar halinde yapmasını söyler.
typedef struct __attribute__((aligned(16))) {

// GÖREV 1: Sadece WIN config ve versiyon 23 ise (Tek satırda ifade)
#if defined(CONFIG_OS_WIN) && (CONFIG_VERSION == 23)
        unsigned int addr;
#endif

// GÖREV 2: Sadece Linux config ise
#ifdef CONFIG_OS_LINUX
        unsigned long addrl;
#endif

        // Her durumda var olan ortak alanlar
        unsigned long size;
        bool valid;
} mem_desc_t;


// GÖREV 5: Fonksiyon sadece CONFIG_STACK_PROTECTION varsa var olacak.
#ifdef CONFIG_STACK_PROTECTION
void stack_validate(void) {
        printf("Stack validation\n");
}
#endif


int main() {
        /* ... */

        printf("Size of mem_desc: %lu\n", sizeof(mem_desc_t));
      
        // SINAV TUZAĞI: Fonksiyonun tanımını sildiysen, çağrıldığı yeri de silmelisin!
        // Aksi takdirde derleyici main içinde "stack_validate is undefined" hatası fırlatır.
#ifdef CONFIG_STACK_PROTECTION
        stack_validate();
#endif
                                                                          
        /* ... */
        return 0;
}


```

```c
#include <stdbool.h>
#include <stdio.h>

// Une certaine configuration 
#define CONFIG_VERSION 23
#define CONFIG_STACK_PROTECTION

//#define CONFIG_OS_WIN     
#define CONFIG_OS_LINUX     

// 1. ALIGNEMENT (Hizalama): Struct'ı 16 byte sınırına hizalıyoruz
typedef struct __attribute__((aligned(16))) {

// 2. TEK SATIRDA ÇOKLU KOŞUL: Hem WIN tanımlı olmalı, HEM DE versiyon 23 olmalı
#if defined(CONFIG_OS_WIN) && (CONFIG_VERSION == 23)
        unsigned int addr;
#endif

// 3. BASİT KOŞUL: Sadece Linux için
#ifdef CONFIG_OS_LINUX
        unsigned long addrl;
#endif

// 4. GÜVENLİK KALKANI: Eğer ikisi de seçilmediyse derlemeyi patlat!
#if !defined(CONFIG_OS_WIN) && !defined(CONFIG_OS_LINUX)
    #error "[!] ERREUR FATALE : L'OS cible (Windows ou Linux) n'est pas defini."
#endif

        // Autres champs présents dans tous les cas
        unsigned long size;
        bool valid;
} mem_desc_t;
 
// 5. FONKSİYON FİLTRELEME: Eğer koruma açıksa bu fonksiyonu derle
#ifdef CONFIG_STACK_PROTECTION
void stack_validate(void) {
        printf("Stack validation\n");
}
#endif

int main(void) {

        /* ... */

        printf("Size of mem_desc: %lu\n", sizeof(mem_desc_t));
      
        // 6. PROFESYONEL DETAY: Fonksiyon çağrısını da koruma altına almalısın!
        // Eğer CONFIG_STACK_PROTECTION kapalıysa, fonksiyon var olmayacaktır.
        // main içinde çağırmaya çalışırsan "Undefined reference" hatası alırsın.
#ifdef CONFIG_STACK_PROTECTION
        stack_validate();
#endif
                                                                          
        /* ... */
        
        return 0;
}

```

```c
#include <stdbool.h>
#include <stdio.h>

#define CONFIG_VERSION 23
#define CONFIG_STACK_PROTECTION
#define CONFIG_OS_LINUX

// C11 standardı ile kesin 16-byte hizalama
typedef struct {
#if defined(CONFIG_OS_WIN) && (CONFIG_VERSION == 23)
        unsigned int addr;
#elif defined(CONFIG_OS_LINUX)
        unsigned long addr;
#else
        #error OS Not selected correctly
#endif
        unsigned long size;
        bool valid;
} _Alignas(16) mem_desc_t;

#ifdef CONFIG_STACK_PROTECTION
void stack_validate(void) {
        printf("Stack validation\n");
}
#endif

int main(void) {
        printf("Size of mem_desc: %lu\n", sizeof(mem_desc_t));

#ifdef CONFIG_STACK_PROTECTION
        stack_validate();
#endif

        return 0;
}

```

```c
#include <stdbool.h>
#include <stdio.h>

/* --- CONFIGURATION --- */
#define CONFIG_VERSION 23
#define CONFIG_STACK_PROTECTION

//#define CONFIG_OS_WIN     
#define CONFIG_OS_LINUX     

/* 1. PORTATİF BELLEK HİZALAMASI */
// Mevcut bellek ayarını hafızaya al (push) ve 16 byte hizalamasına geç
#pragma pack(push, 16)

typedef struct {

// 2. DIŞLAYAN MANTIK ZİNCİRİ (Mutually Exclusive)
#if defined(CONFIG_OS_WIN) && (CONFIG_VERSION == 23)
        // Sadece Win ve Versiyon 23 ise
        unsigned int addr;

#elif defined(CONFIG_OS_LINUX)
        // Win değilse ama Linux ise (Değişken adını aynı tutmak harika bir pratiktir)
        unsigned long addr;

#else
        // İkisi de değilse derlemeyi tam burada, struct'ın içinde durdur
        #error "OS Not selected correctly"
#endif

        // Her durumda var olan ortak alanlar
        unsigned long size;
        bool valid;

} mem_desc_t;

// Hizalama işlemini bitir ve eski ayarlara geri dön (pop)
#pragma pack(pop)


/* 3. KOŞULLU FONKSİYON TANIMLAMASI */
#ifdef CONFIG_STACK_PROTECTION
void stack_validate(void) {
        printf("Stack validation\n");
}
#endif /* CONFIG_STACK_PROTECTION */


int main() {
        /* ... */

        printf("Size of mem_desc: %lu\n", sizeof(mem_desc_t));

/* 4. KOŞULLU FONKSİYON ÇAĞRISI */
// Eğer yukarıda fonksiyonu sildiysek, burada çağırmamızı da engellemeliyiz
#ifdef CONFIG_STACK_PROTECTION
        stack_validate();
#endif /* CONFIG_STACK_PROTECTION */

        /* ... */
        
        return 0; // Programın güvenli çıkışı
}

```

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Définition des macros */

// KURAL 1: Parametreler HER ZAMAN parantez içine alınır. (c) gibi.
// Eğer CHIFFRE(c) c >= '0' yazılsaydı ve kullanıcı CHIFFRE(x + 1) gönderseydi, 
// makro x + 1 >= '0' olarak açılır ve işlem önceliği yüzünden patlardı.
#define CHIFFRE(c)      (((c) >= '0' && (c) <= '9'))
#define MINUSCULE(c)    (((c) >= 'a' && (c) <= 'z'))
#define MAJUSCULE(c)    (((c) >= 'A' && (c) <= 'Z'))

// KURAL 2: ASCII Aritmetiği
// 'a' ile 'A' arasında tam 32 (decimal) fark vardır. 
// Sihirli sayı (32) yazmak yerine ('a' - 'A') yazmak niyetini belli eder.
#define MIN_MAJ(c)      (MINUSCULE(c) ? ((c) - ('a' - 'A')) : (c))
#define MAJ_MIN(c)      (MAJUSCULE(c) ? ((c) + ('a' - 'A')) : (c))

// KURAL 3: Çok satırlı makrolar için do-while(0) zırhı.
// Eğer bu blok kullanılmazsa if-else yapıları içinde bu makro programı çökertir.
#define PERMUTE(a, b)   do { int _tmp = (a); (a) = (b); (b) = _tmp; } while(0)

// string.h dahil edildiği için en güvenli yol standart kütüphaneyi sarmalamaktır.
#define COPIE(s, t)     strcpy((t), (s))


int main() {

    char test_char = '5';
    char test_min_char = 'a';
    char test_maj_char = 'Z';
    int a = 10, b = 20;
    char lower_char = 't';
    char upper_char = 'K';
    char source[] = "Hello, world!";
    char destination[50];

    /* Teste si <test_char> est un chiffre */
    // Makrolar true(1) veya false(0) döner.
    printf("Est-ce un chiffre ? %d\n", CHIFFRE(test_char));

    /* Teste si <test_min_char> est une minuscule */
    printf("Est-ce une minuscule ? %d\n", MINUSCULE(test_min_char));

    /* Teste si <test_maj_char> est une majuscule */
    printf("Est-ce une majuscule ? %d\n", MAJUSCULE(test_maj_char));

    /* Converti <lower_char> en majuscule SI minuscule */
    printf("En majuscule si minuscule : %c\n", MIN_MAJ(lower_char));

    /* Converti <upper_char> en minuscule SI majuscule */
    printf("En minuscule si majuscule : %c\n", MAJ_MIN(upper_char));

    printf("Avant permutation : a = %d, b = %d\n", a, b);

    /* A compléter */
    PERMUTE(a, b);

    printf("Après permutation : a = %d, b = %d\n", a, b);

    /* Effectue une copie de destination dans source avec la macro COPIE */
    /* A compléter */
    COPIE(source, destination);

    printf("Chaîne copiée : %s\n", destination);

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --- Définition des macros --- */

/* 1. Tests basés sur la table ASCII. 
   Les parenthèses autour de (c) sont vitales pour éviter les erreurs de priorité. */
#define CHIFFRE(c)   (((c) >= '0' && (c) <= '9') ? 1 : 0)
#define MINUSCULE(c) (((c) >= 'a' && (c) <= 'z') ? 1 : 0)
#define MAJUSCULE(c) (((c) >= 'A' && (c) <= 'Z') ? 1 : 0)

/* 2. Conversions ASCII. 
   La distance entre 'A' (65) et 'a' (97) est de 32. */
#define MIN_MAJ(c)   (MINUSCULE(c) ? ((c) - 32) : (c))
#define MAJ_MIN(c)   (MAJUSCULE(c) ? ((c) + 32) : (c))

/* 3. Permutation sécurisée avec variable temporaire locale */
#define PERMUTE(a, b) do { int _temp = (a); (a) = (b); (b) = _temp; } while(0)

/* 4. Copie de chaîne. 
   Puisque <string.h> est inclus, on route la macro vers la fonction native optimisée. 
   Note : t est la destination, s est la source. */
#define COPIE(s, t)   strcpy((t), (s))

/* Si le prof interdit <string.h>, la version manuelle (pointeurs) serait :
 * #define COPIE(s, t) do { char *_s = (s), *_t = (t); while((*_t++ = *_s++)); } while(0)
 */

int main(void) {

    char test_char = '5';
    char test_min_char = 'a';
    char test_maj_char = 'Z';
    int a = 10, b = 20;
    char lower_char = 't';
    char upper_char = 'K';
    char source[] = "Hello, world!";
    char destination[50];

    /* Teste si <test_char> est un chiffre */
    printf("Est-ce un chiffre ? %d\n", CHIFFRE(test_char));

    /* Teste si <test_min_char> est une minuscule */
    printf("Est-ce une minuscule ? %d\n", MINUSCULE(test_min_char));

    /* Teste si <test_maj_char> est une majuscule */
    printf("Est-ce une majuscule ? %d\n", MAJUSCULE(test_maj_char));

    /* Convertit <lower_char> en majuscule SI minuscule */
    printf("En majuscule si minuscule : %c\n", MIN_MAJ(lower_char));

    /* Convertit <upper_char> en minuscule SI majuscule */
    printf("En minuscule si majuscule : %c\n", MAJ_MIN(upper_char));

    printf("Avant permutation : a = %d, b = %d\n", a, b);

    /* Exécution de la permutation */
    PERMUTE(a, b);

    printf("Après permutation : a = %d, b = %d\n", a, b);

    /* Effectue une copie de source dans destination avec la macro COPIE */
    COPIE(source, destination);

    printf("Chaîne copiée : %s\n", destination);

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --- MAKRO TANIMLAMALARI --- */

// 1. Karakter Test Makroları
// isdigit, islower ve isupper fonksiyonları <ctype.h> kütüphanesinden gelir.
// != 0 ile dönen değeri kesin bir 1 veya 0 (Boolean) sonucuna eşitliyoruz.
#define CHIFFRE(c)      (isdigit((unsigned char)(c)) != 0)
#define MINUSCULE(c)    (islower((unsigned char)(c)) != 0)
#define MAJUSCULE(c)    (isupper((unsigned char)(c)) != 0)

// 2. Dönüştürme Makroları
// Sadece ilgili şart sağlanıyorsa toupper/tolower çalışır, yoksa karakterin kendisi döner.
#define MIN_MAJ(c)      (MINUSCULE(c) ? toupper((unsigned char)(c)) : (c))
#define MAJ_MIN(c)      (MAJUSCULE(c) ? tolower((unsigned char)(c)) : (c))

// 3. İşlem Makroları
// do { ... } while(0) zırhı ile değişken takası ve güvenli kopyalama.
#define PERMUTE(a, b) \
    do { \
        int _temp = (a); \
        (a) = (b); \
        (b) = _temp; \
    } while (0)

#define COPIE(s, t) \
    do { \
        strcpy((t), (s)); \
    } while (0)

/* --- MAIN FONKSİYONU --- */
int main() {
    char test_char = '5';
    char test_min_char = 'a';
    char test_maj_char = 'Z';
    int a = 10, b = 20;
    char lower_char = 't';
    char upper_char = 'K';
    char source[] = "Hello, world!";
    char destination[50];

    printf("Est-ce un chiffre ? %d\n", CHIFFRE(test_char));
    printf("Est-ce une minuscule ? %d\n", MINUSCULE(test_min_char));
    printf("Est-ce une majuscule ? %d\n", MAJUSCULE(test_maj_char));
    printf("En majuscule si minuscule : %c\n", MIN_MAJ(lower_char));
    printf("En minuscule si majuscule : %c\n", MAJ_MIN(upper_char));

    printf("Avant permutation : a = %d, b = %d\n", a, b);
    PERMUTE(a, b);
    printf("Apres permutation : a = %d, b = %d\n", a, b);

    COPIE(source, destination);
    printf("Chaine copiee : %s\n", destination);

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

```c


```

```c


```

```c


```

```c


```
