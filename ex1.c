#include <stdio.h>

// int main() {
//     int n;

//     if (scanf("%d", &n) != 1 || n <= 0) {
//         return 1;
//     }

//     int tab[n];
//     int somme = 0;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) return 1;
//         somme += tab[i];
//     }
//     printf("Somme : %d\n", somme);
//     return 0;
// }


// int main() {
//     int n;
//     printf("entrez un entier : \n");
//     if (scanf("%d", &n) != 1 || n < 1 || n>10) {
//         return 1;
//     }

//     float tab[n];
//     float somme = 0;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%f", &tab[i]) != 1)return 1;
//         somme += tab[i];
//     }

//     printf("Moyenne : %.2f \n", (float)somme / n);
// }


// int main() {

//     int n;
//     printf("Entrez un nombre : \n");
//     if (scanf("%d", &n) != 1 || n < 2) {
//         return 1;
//     }

//     int tab[n];

//     for (int i = 0; i < n; ++i) {

//         if (scanf("%d", &tab[i]) != 1)return 1;

//     }

//     int max_el = tab[0];

//     for (int i = 1; i < n; ++i) {
//         if (tab[i] > max_el) {
//             max_el = tab[i];
//         }
//     }

//     printf("Maximum : %d\n", max_el);


//     return 0;
// }


int main() {
    int n;
    printf("entrez un valeur : \n");
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int tab[n];


    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1)return 1;
    }
    int min_el = tab[0];
    int idx = 0;

    for (int i = 0; i < n; ++i) {
        if (tab[i] < min_el) {
            min_el = tab[i];
            idx = i;
        }
    }
    printf("Minumum : %d\n", min_el);
    printf("Indice : %d\n", idx);
}
