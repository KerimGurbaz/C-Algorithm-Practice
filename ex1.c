// #include <stdio.h>

// int main() {
//     int n;

//     // 1. Girdi Alma (2pts - scanf / printf)
//     // Güvenlik: Kullanıcı pozitif bir sayı girene kadar döngüde tutuyoruz.
//     do {
//         printf("Entrez un entier positif : ");
//         if (scanf("%d", &n) != 1) {
//             printf("Erreur de saisie.\n");
//             // Eğer harf girilirse buffer'ı temizleme refleksimiz (Q3'ten hatırlarsın)
//             while(getchar() != '\n'); 
//             continue; 
//         }
//     } while (n <= 0);

//     // 2. Dizi Üretimi (3pts - génération de la suite correcte)
//     // Sayı 1'e ULAŞMADIĞI sürece döngüye devam et.
//     while (n > 1) {
//         printf("%d ", n); // Mevcut sayıyı formülü uygulamadan ÖNCE yazdır.

//         // Sayı çift mi? (Pair)
//         if (n % 2 == 0) {
//             n = n / 2;
//         } 
//         // Sayı tek mi? (Impair)
//         else {
//             n = 3 * n + 1;
//         }
//     }

//     // Döngü bittiğinde n artık 1'dir. Son sayıyı yazdırıp bitiriyoruz.
//     printf("1\n");

//     return 0;
// }


#include <stdio.h>

// int main() {
//     int n;
//     int count = 0;

//     do {
//         printf("Entrez un number\n");
//         if (scanf("%d", &n) != 1) {
//             printf("Erreur de saisie.\n");
//             while (getchar() != '\n');
//             continue;
//         }


//     }
//     while (n <= 0);

//     while (n > 1) {
//         printf("%d ", n);
//         if (n % 2 == 0) {
//             n /= 2;
//         } else {
//             n = 3 * n + 1;
//         }
//         ++count;
//     }

//     printf("Nomre d'etapes %d: %d", count, n);

//     return 0;
// }


// int main() {
//     int a, b;
//     int count = 0;

//     printf("Entrez premier number a\n");
//     if (scanf("%d", &a) != 1) {
//         return 1;
//     };


//     printf("Entrez deuxieme number b\n");
//     if (scanf("%d", &b) != 1) return 1;

//     for (int i = a; i <= b; ++i) {
//         if (i % 2 == 0) {
//             printf("%d ", i);
//             ++count;
//         }
//     }

//     printf("il y a %d numbers \n", count);


//     return 0;
// }

int main() {
    int a, b;
    int somme = 0;

    printf("entrez premier number a\n");
    if (scanf("%d", &a) != 1) return 1;
    printf("entrez premier number b\n");
    if (scanf("%d", &b) != 1) return 1;

    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }

    for (int i = a; i <= b; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            somme += i;
            printf("%d ", i);
        }
    }
    printf("\nsomme = %d\n", somme);



    return 0;
}
