// #include <stdbool.h>
// #include <stdio.h>

// #define CONFIG_VERSION 23
// #define CONFIG_STACK_PROTECTION

// #define CONFIG_OS_WIN
// // #define CONFIG_OS_LINUX

// #if !defined(CONFIG_OS_WIN) && !defined(CONFIG_OS_LINUX)
// #error "Erreur de compilastion :  Aucun OS defini(WIN ou LINUX requis)."
// #endif

// typedef struct __attribute__((aligned(16))) {
// #if defined(CONFIG_OS_WIN) && (CONFIG_VERSION ==23)
//     unsigned int addr;
// #endif

// #ifdef CONFIG_OS_LINUX
//     unsigned long addrl;
// #endif

//     unsigned long size;
//     bool valid;
// }mem_desc_t;

// #ifdef CONFIG_STACK_PROTECTION
// void stack_validite(void) {
//     printf("Stack validation\n");
// }
// #endif

// int main() {
//     printf("Size of mem_desc : %lu\n", sizeof(mem_desc_t));

// #ifdef CONFIG_STACK_PROTECTION
//     stack_validite();
// #endif

//     return 0;
// }
// #include <stdbool.h>
// #include <stdio.h>

// #define CONFIG_VERSION 23
// #define CONFIG_STACK_PROTECTION

// #define CONFIG_OS_LINUX
// #define CONFIG_OS_WIN

// typedef struct __attribute__((aligned(16))) {
// #if defined(CONFIG_OS_WIN)&&(CONFIG_VERSION ==23)
//     unsigned int addr;
// #endif

// #ifdef CONFIG_OS_LINUX
//     unsigned int addrl;
// #endif

// #if !defined(CONFIG_OS_WIN) && !defined(CONFIG_OS_LINUX)
// #error "[!] ERREUR FATALE : L'OS cible (Windows ou Linux) n'est pas defini."
// #endif

//     unsigned long size;
//     bool valid;

// }mem_desc_t;

// #ifdef CONFIG_STACK_PROTECTION
// void stack_validate(void) {
//     printf("Stack validation\n");
// }
// #endif

// int main() {
//     printf("Size of mem.. %lu\n", sizeof(mem_desc_t));

// #ifdef CONFIG_STACK_PROTECTION
//     stack_validate();
// #endif

//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHIFFRE(c)  ((c) >='0' &&(c)<='9')
#define MINUSCULE(c) ((c) >='a' && (c)<='z')
#define MAJUSCULE(c) ((c) >='A' && (c)<='Z')

#define MIN_MAJ(c) MINUSCULE(c) ?((c) - ('a' -'A')) : (c)
#define MAJ_MIN(c) MAJUSCULE(c) ? ((c) +('a'- 'A')) : (c)

#define PERMUTE(a,b) do{int _tmp = (a); (a)=(b); (b)=_tmp;} while(0);

#define COPIE(s,t) strcpy((t), (s))


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
