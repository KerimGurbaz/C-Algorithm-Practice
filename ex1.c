// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// /* Définition des macros */

// // KURAL 1: Parametreler HER ZAMAN parantez içine alınır. (c) gibi.
// // Eğer CHIFFRE(c) c >= '0' yazılsaydı ve kullanıcı CHIFFRE(x + 1) gönderseydi, 
// // makro x + 1 >= '0' olarak açılır ve işlem önceliği yüzünden patlardı.
// #define CHIFFRE(c)      (((c) >= '0' && (c) <= '9'))
// #define MINUSCULE(c)    (((c) >= 'a' && (c) <= 'z'))
// #define MAJUSCULE(c)    (((c) >= 'A' && (c) <= 'Z'))

// // KURAL 2: ASCII Aritmetiği
// // 'a' ile 'A' arasında tam 32 (decimal) fark vardır. 
// // Sihirli sayı (32) yazmak yerine ('a' - 'A') yazmak niyetini belli eder.
// #define MIN_MAJ(c)      (MINUSCULE(c) ? ((c) - ('a' - 'A')) : (c))
// #define MAJ_MIN(c)      (MAJUSCULE(c) ? ((c) + ('a' - 'A')) : (c))

// // KURAL 3: Çok satırlı makrolar için do-while(0) zırhı.
// // Eğer bu blok kullanılmazsa if-else yapıları içinde bu makro programı çökertir.
// #define PERMUTE(a, b)   do { int _tmp = (a); (a) = (b); (b) = _tmp; } while(0)

// // string.h dahil edildiği için en güvenli yol standart kütüphaneyi sarmalamaktır.
// #define COPIE(s, t)     strcpy((t), (s))


// int main() {

//     char test_char = '5';
//     char test_min_char = 'a';
//     char test_maj_char = 'Z';
//     int a = 10, b = 20;
//     char lower_char = 't';
//     char upper_char = 'K';
//     char source[] = "Hello, world!";
//     char destination[50];

//     /* Teste si <test_char> est un chiffre */
//     // Makrolar true(1) veya false(0) döner.
//     printf("Est-ce un chiffre ? %d\n", CHIFFRE(test_char));

//     /* Teste si <test_min_char> est une minuscule */
//     printf("Est-ce une minuscule ? %d\n", MINUSCULE(test_min_char));

//     /* Teste si <test_maj_char> est une majuscule */
//     printf("Est-ce une majuscule ? %d\n", MAJUSCULE(test_maj_char));

//     /* Converti <lower_char> en majuscule SI minuscule */
//     printf("En majuscule si minuscule : %c\n", MIN_MAJ(lower_char));

//     /* Converti <upper_char> en minuscule SI majuscule */
//     printf("En minuscule si majuscule : %c\n", MAJ_MIN(upper_char));

//     printf("Avant permutation : a = %d, b = %d\n", a, b);

//     /* A compléter */
//     PERMUTE(a, b);

//     printf("Après permutation : a = %d, b = %d\n", a, b);

//     /* Effectue une copie de destination dans source avec la macro COPIE */
//     /* A compléter */
//     COPIE(source, destination);

//     printf("Chaîne copiée : %s\n", destination);

//     return 0;
// }

// #define DEFINE_TAB(name, type)\
// \
// struct name##item { \
// int pos;\
// type val;\
// };\
// \
// struct name##item tab##name[10];\
// \
// static inline type get##name##val(int pos) {\
// return tab##name[pos].val;\
// }

#include <stdio.h>                      
#define YAZDIRICI(type, format)         \
void yazdir_##type(type  deger){       \
printf("Gelen deger : " format "\n", deger);\
}


YAZDIRICI(int, "%d")
YAZDIRICI(int, "%.2f")


int main() {
    yazdir(42);
    yazdir(3.1415f);

    return 0;
}


