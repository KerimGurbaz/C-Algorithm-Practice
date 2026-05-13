```c
#include <CUnit/Basic.h>
#include <math.h>

// Fonction à tester
int calculer(int nombre1, int nombre2, char operateur) {
        switch (operateur) {
        case '+':
                return nombre1 + nombre2;
        case '-':
                return nombre1 - nombre2;
        case '*':
                return nombre1 * nombre2;
        case '/':
                if (nombre2 == 0) {
                        // Gérer l'erreur de division par zéro
                        return -1;
                } else {
                        return nombre1 / nombre2;
                }
        case '^':
                // Puissance non implémentée avec des entiers
                return (int) pow((double) nombre1, (double) nombre2);
        default:
                // Gérer l'opérateur invalide
                return -1;
        }
}

/* 1. Test Fonksiyonlarının Yazılması (Adım Adım İnşa) */

void test_addition(void) {
    // CU_ASSERT_EQUAL, beklenen değer ile fonksiyonun döndürdüğü değeri kıyaslar.
    CU_ASSERT_EQUAL(calculer(2, 3, '+'), 5);
    CU_ASSERT_EQUAL(calculer(-2, 2, '+'), 0);
}

void test_soustraction(void) {
    CU_ASSERT_EQUAL(calculer(10, 4, '-'), 6);
}

void test_multiplication(void) {
    CU_ASSERT_EQUAL(calculer(5, 3, '*'), 15);
}

void test_division_normale(void) {
    CU_ASSERT_EQUAL(calculer(10, 2, '/'), 5);
    // Tamsayı bölmesi olduğu için 5/2 = 2 çıkmalıdır.
    CU_ASSERT_EQUAL(calculer(5, 2, '/'), 2);
}

void test_division_par_zero(void) {
    // Hata durumunda fonksiyonun -1 döndürmesi bekleniyor.
    CU_ASSERT_EQUAL(calculer(10, 0, '/'), -1);
}

void test_puissance(void) {
    CU_ASSERT_EQUAL(calculer(2, 3, '^'), 8);
}

void test_operateur_invalide(void) {
    // Tanımsız bir operatör ('x') gönderildiğinde hata yakalanmalı.
    CU_ASSERT_EQUAL(calculer(5, 5, 'x'), -1);
}

/* 2. Ana Program (CUnit Test Motorunun Kurulumu) */

int main() {
    // Adım A: CUnit test kayıt defterini başlat
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Adım B: Yeni bir Test Paketi (Suite) oluştur
    // Parametreler: (isim, init_fonksiyonu, clean_fonksiyonu) -> Setup/Teardown yoksa NULL verilir.
    CU_pSuite suite = CU_add_suite("Suite_Calculatrice", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Adım C: Yazdığımız testleri paketimize (suite) ekle
    if ((NULL == CU_add_test(suite, "Test Addition", test_addition)) ||
        (NULL == CU_add_test(suite, "Test Soustraction", test_soustraction)) ||
        (NULL == CU_add_test(suite, "Test Multiplication", test_multiplication)) ||
        (NULL == CU_add_test(suite, "Test Division Normale", test_division_normale)) ||
        (NULL == CU_add_test(suite, "Test Division par Zero", test_division_par_zero)) ||
        (NULL == CU_add_test(suite, "Test Puissance", test_puissance)) ||
        (NULL == CU_add_test(suite, "Test Operateur Invalide", test_operateur_invalide)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Adım D: Testleri konsolda okunabilir bir formatta (Basic) çalıştır
    CU_basic_set_mode(CU_BRM_VERBOSE); // VERBOSE modu, her testin sonucunu tek tek ekrana yazar
    CU_basic_run_tests();

    // Adım E: Belleği temizle ve çık (Memory Leak önlemi)
    CU_cleanup_registry();
    return CU_get_error();
}

```

```c
#include <stdio.h>

void afficher_message(void) {
    // Eğer derleme sırasında -DDEBUG bayrağı verildiyse (veya #define DEBUG yazıldıysa)
#ifdef DEBUG
    printf("Debug: message affiché\n");
#endif
}

int get_value(void) {
#ifdef DEBUG
    return 99;
#else
    return 0;
#endif
}

```

```c
// FEATURE_ADVANCED tanımlıysa:
//   int calculer(int a, int b) → a^b + a*b döndürsün
// FEATURE_ADVANCED tanımlı değilse:
//   int calculer(int a, int b) → a + b döndürsün
// votre_code.c
#include <math.h>

int calculer(int a, int b) {
// Eğer derleme sırasında -DFEATURE_ADVANCED bayrağı kullanıldıysa bu blok derlenir
#ifdef FEATURE_ADVANCED
    // pow() fonksiyonu double döndürdüğü için veri kaybı uyarılarını
    // önlemek adına (int) ile bilinçli bir dönüştürme (casting) yapıyoruz.
    return (int)pow((double)a, (double)b) + (a * b);

// Kullanılmadıysa standart blok derlenir
#else
    return a + b;
#endif
}

```

```c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/* 1. Kendi String Fonksiyonlarımız */

int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int my_strcmp(const char *a, const char *b) {
    // Karakterler eşleştiği ve string bitmediği sürece ilerle
    while (*a != '\0' && *a == *b) {
        a++;
        b++;
    }
    // Farkı bulduğumuzda unsigned char olarak çıkarıp döndür
    return *(unsigned char *)a - *(unsigned char *)b;
}

char* my_strcat(char *dest, const char *src) {
    char *orig_dest = dest; // Orijinal başlangıç adresini sakla

    // dest string'inin sonuna (\0) kadar ilerle
    while (*dest != '\0') {
        dest++;
    }

    // src string'ini kopyala
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    // Yeni string'in sonuna null terminator ekle
    *dest = '\0';

    return orig_dest;
}

/* 2. CUnit Test Fonksiyonları */

void test_my_strlen(void) {
    CU_ASSERT_EQUAL(my_strlen("hello"), 5);
    CU_ASSERT_EQUAL(my_strlen(""), 0);         // Boş string
    CU_ASSERT_EQUAL(my_strlen("a"), 1);        // Tek karakter
    CU_ASSERT_EQUAL(my_strlen("1234567890"), 10); // Sayısal string
}

void test_my_strcmp(void) {
    // Eşit durum
    CU_ASSERT_EQUAL(my_strcmp("abc", "abc"), 0);
    // Küçük durum (İlk farklı karakter 'c' < 'd')
    CU_ASSERT_TRUE(my_strcmp("abc", "abd") < 0);
    // Büyük durum ('d' > 'c')
    CU_ASSERT_TRUE(my_strcmp("abd", "abc") > 0);
    // Boş stringler
    CU_ASSERT_EQUAL(my_strcmp("", ""), 0);
    CU_ASSERT_TRUE(my_strcmp("a", "") > 0);
    CU_ASSERT_TRUE(my_strcmp("", "a") < 0);
    // Uzun stringler (Kısa olan uzun olandan küçüktür)
    CU_ASSERT_TRUE(my_strcmp("longstring", "longstring!") < 0);
}

void test_my_strcat(void) {
    char buffer1[50] = "hello";
    CU_ASSERT_STRING_EQUAL(my_strcat(buffer1, " world"), "hello world");

    char buffer2[50] = "";
    CU_ASSERT_STRING_EQUAL(my_strcat(buffer2, "test"), "test"); // Boş hedefe ekleme

    char buffer3[50] = "test";
    CU_ASSERT_STRING_EQUAL(my_strcat(buffer3, ""), "test"); // Boş kaynağı ekleme
}

/* 3. Ana Program ve CUnit Kurulumu */

int main() {
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    CU_pSuite suite = CU_add_suite("Suite_String_Fonksiyonlari", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(suite, "Test my_strlen", test_my_strlen)) ||
        (NULL == CU_add_test(suite, "Test my_strcmp", test_my_strcmp)) ||
        (NULL == CU_add_test(suite, "Test my_strcat", test_my_strcat))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

```

```c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char titre[50];
    float prix;
} Livre;

/* --- TEST EDİLECEK FONKSİYONLAR --- */

void ajouter_livre(Livre tab[], int *n, Livre l) {
    if (*n < MAX) {
        tab[*n] = l;
        (*n)++;
    }
}

Livre* chercher_par_id(Livre tab[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (tab[i].id == id) {
            return &tab[i];
        }
    }
    return NULL; // Bulunamazsa NULL döner
}

int compter_par_prix_min(Livre tab[], int n, float min) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (tab[i].prix >= min) {
            count++;
        }
    }
    return count;
}

/* --- CUNIT TEST FONKSİYONLARI --- */

void test_ajouter(void) {
    Livre bibliotheque[MAX];
    int n = 0;

    Livre l1 = {1, "Le C en 20 Jours", 45.5};
    ajouter_livre(bibliotheque, &n, l1);

    // 1. Dizi boyutu arttı mı?
    CU_ASSERT_EQUAL(n, 1);

    // 2. Struct verileri belleğe doğru kopyalandı mı?
    CU_ASSERT_EQUAL(bibliotheque[0].id, 1);
    CU_ASSERT_STRING_EQUAL(bibliotheque[0].titre, "Le C en 20 Jours");
    // Float karşılaştırmalarında tolerans (epsilon) değeri kullanılır (0.01)
    CU_ASSERT_DOUBLE_EQUAL(bibliotheque[0].prix, 45.5, 0.01);

    // Sınır Testi (Edge Case): MAX kapasite aşılmamalı
    n = MAX;
    Livre l2 = {2, "Livre Trop Tard", 10.0};
    ajouter_livre(bibliotheque, &n, l2);
    CU_ASSERT_EQUAL(n, MAX); // Değerin 101'e çıkmadığından emin oluyoruz
}

void test_chercher(void) {
    // Test verisi hazırlama (Mocking)
    Livre bibliotheque[] = {
        {10, "Data Engineering", 50.0},
        {20, "Machine Learning", 65.0},
        {30, "Systemes d'Exploitation", 40.0}
    };
    int n = 3;

    // Mevcut bir kitabı arama
    Livre *resultat = chercher_par_id(bibliotheque, n, 20);

    // DİKKAT: Önce NULL olmadığını doğrula, sonra içindeki değere bak
    CU_ASSERT_PTR_NOT_NULL(resultat);
    if (resultat != NULL) {
        CU_ASSERT_STRING_EQUAL(resultat->titre, "Machine Learning");
    }

    // Olmayan bir kitabı arama
    Livre *introuvable = chercher_par_id(bibliotheque, n, 99);
    CU_ASSERT_PTR_NULL(introuvable);
}

void test_compter(void) {
    Livre bibliotheque[] = {
        {1, "Livre A", 10.0},
        {2, "Livre B", 25.5},
        {3, "Livre C", 25.5},
        {4, "Livre D", 100.0}
    };
    int n = 4;

    // Hepsi dâhil
    CU_ASSERT_EQUAL(compter_par_prix_min(bibliotheque, n, 0.0), 4);

    // Ara değerler ve sınır koşulları
    CU_ASSERT_EQUAL(compter_par_prix_min(bibliotheque, n, 25.5), 3); // B, C, D
    CU_ASSERT_EQUAL(compter_par_prix_min(bibliotheque, n, 50.0), 1); // Sadece D

    // Hiçbiri eşleşmiyor
    CU_ASSERT_EQUAL(compter_par_prix_min(bibliotheque, n, 150.0), 0);
}

/* --- ANA PROGRAM --- */

int main() {
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    CU_pSuite suite = CU_add_suite("Suite_Bibliotheque", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(suite, "Test Ajouter", test_ajouter)) ||
        (NULL == CU_add_test(suite, "Test Chercher", test_chercher)) ||
        (NULL == CU_add_test(suite, "Test Compter", test_compter))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int factorielle(int n) {
    if (n <= 1) return 1;
    return n * factorielle(n - 1);
}

// Eğer derleme sırasında -DTEST_MODE bayrağı verilmişse bu blok çalışır
#ifdef TEST_MODE

// AMPOULE 1: CUnit kütüphanelerini global (en üste) koymak yerine
// sadece TEST_MODE içindeyken dâhil ediyoruz. Böylece üretim (production)
// derlemesinde gereksiz bağımlılıklar yaratmıyoruz.
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_factorielle(void) {
    // Normal durumlar
    CU_ASSERT_EQUAL(factorielle(0), 1);
    CU_ASSERT_EQUAL(factorielle(1), 1);
    CU_ASSERT_EQUAL(factorielle(5), 120);

    // Negatif sayı sınırı (Senin fonksiyonun negatiflerde 1 döndürüyor)
    CU_ASSERT_EQUAL(factorielle(-5), 1);
}

int main() {
    // Test Modu Main Fonksiyonu
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    CU_pSuite suite = CU_add_suite("Suite_Factorielle", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(suite, "Test Factorielle", test_factorielle)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

// Eğer -DTEST_MODE bayrağı YOKSA bu blok çalışır
#else

int main() {
    // Normal Mod Main Fonksiyonu
    int n;
    printf("Entrez un nombre entier pour calculer sa factorielle : ");

    // AMPOULE 2: scanf dönüş değerini kontrol etmek güvenlik standartıdır.
    // Kullanıcı harf girerse programın rastgele çökmesini engeller.
    if (scanf("%d", &n) != 1) {
        printf("Erreur : Entree invalide.\n");
        return 1;
    }

    printf("La factorielle de %d est : %d\n", n, factorielle(n));
    return 0;
}

#endif

```

```c
#include <stdio.h>

// AMPOULE 1: Ön-işlemci Güvenlik Kalkanı
// Eğer MODE hiç tanımlanmadıysa, ona varsayılan olarak -1 değerini veriyoruz.
// Bunu yapmazsak başımıza ne geleceğini aşağıdaki Ampul 1 notunda okuyacaksın.
#ifndef MODE
    #define MODE -1
#endif

void afficher_mode(void) {
#if MODE == 0
    printf("Mode Basique\n");
#elif MODE == 1
    printf("Mode Intermediaire\n");
#elif MODE == 2
    printf("Mode Avance\n");
#else
    printf("Mode par defaut\n");
#endif
}

int obtenir_valeur(void) {
#if MODE == 0
    return 10;
#elif MODE == 1
    return 50;
#elif MODE == 2
    return 100;
#else
    return 0;
#endif
}

```

```c
#include <math.h>

// Temel hesaplama fonksiyonu
int operation(int a, int b, int op) {
    switch (op) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
        case 3:
            if (b == 0) return -1;
            return a / b;
        case 4:
            return (int)pow((double)a, (double)b);
        default:
            return -1;
    }
}

// Sadece TEST_MODE aktifken derlenecek olan blok
#ifdef TEST_MODE
#include <CUnit/Basic.h>

void test_addition(void) {
    CU_ASSERT_EQUAL(operation(2, 2, 0), 4);
    CU_ASSERT_EQUAL(operation(-5, 10, 0), 5);
}

void test_soustraction(void) {
    CU_ASSERT_EQUAL(operation(10, 3, 1), 7);
    CU_ASSERT_EQUAL(operation(0, 5, 1), -5);
}

void test_multiplication(void) {
    CU_ASSERT_EQUAL(operation(4, 5, 2), 20);
    CU_ASSERT_EQUAL(operation(-2, 3, 2), -6);
}

void test_division(void) {
    CU_ASSERT_EQUAL(operation(10, 2, 3), 5);
    // Tamsayı bölmesi (5/2 = 2.5 degil, 2'dir)
    CU_ASSERT_EQUAL(operation(5, 2, 3), 2);
    // Sifira bolme hatasi kontrolu
    CU_ASSERT_EQUAL(operation(8, 0, 3), -1);
}

void test_puissance(void) {
    CU_ASSERT_EQUAL(operation(2, 3, 4), 8);
    // Herhangi bir sayinin 0. kuvveti 1'dir
    CU_ASSERT_EQUAL(operation(5, 0, 4), 1);
}

void test_operation_invalide(void) {
    CU_ASSERT_EQUAL(operation(5, 5, 99), -1);
    CU_ASSERT_EQUAL(operation(5, 5, -1), -1);
}

void run_tests(void) {
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return;
    }

    CU_pSuite suite = CU_add_suite("Suite_Operations", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return;
    }

    // Testleri suite'e ekle
    CU_add_test(suite, "Test Addition", test_addition);
    CU_add_test(suite, "Test Soustraction", test_soustraction);
    CU_add_test(suite, "Test Multiplication", test_multiplication);
    CU_add_test(suite, "Test Division", test_division);
    CU_add_test(suite, "Test Puissance", test_puissance);
    CU_add_test(suite, "Test Operateur Invalide", test_operation_invalide);

    // Modu ayarla ve calistir
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
}
#endif

```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
