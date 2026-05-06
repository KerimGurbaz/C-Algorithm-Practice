#include <stdio.h>


// char *my_strchr(const char *str, int ch) {
//     while (*str != '\0') {
//         if (*str == (char)ch) {
//             return (char *)str;
//         }
//         ++str;
//     }

//     if ((char)ch == '\0') {
//         return (char *)str;
//     }

//     return NULL;
// }

// int main() {

//     printf("=== TEST my_strchr ===\n\n");
//     char texte[] = "Hello World";
//     char *resultat;
//     printf("Test 1: 'Hello World' icinde 'o' ara\n");


//     resultat = my_strchr(texte, 'o');
//     if (resultat != NULL) {
//         printf("  Bulundu! Adres farki: %d\n", resultat - texte);
//         printf("Karacter : %c \n", *resultat);
//         printf("  Kalan string: '%s'\n", resultat);
//     }
//     printf("\n");



//     return 0;
// }

#include <stdio.h>
#include <string.h> 


char *my_strncpy(char *dest, const char *src, size_t count) {


    int i;
    for (i = 0; i < count && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }

    while (i < count) {
        dest[i] = '\0';
        ++i;
    }

}

void afficher_buffer(const char *buf, size_t taille) {
    printf("  [");
    for (size_t i = 0; i < taille; ++i) {
        if (buf[i] == '\0') printf("\\0");
        else {
            printf("%c", buf[i]);
        }
        if (i < taille - 1)printf("][");
    }

    printf("]\n");
}

int main() {
    printf("=== TEST my_strncpy ===\n\n");

    // Test 1: src, count'tan KISA (padding olmalı)
    printf("Test 1: src='AB', count=5 (src < count)\n");
    char dest1[10];
    memset(dest1, 'X', 10);  // Çöple doldur (görelim)
    my_strncpy(dest1, "AB", 5);
    afficher_buffer(dest1, 6);
    printf("  Beklenen: [A][B][\\0][\\0][\\0][\\0]\n\n");
}
