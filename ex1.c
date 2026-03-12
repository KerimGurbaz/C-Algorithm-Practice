#include <stdio.h>
#include <stdlib.h>

// int main() {

//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0)return 1;

//     int *tab = malloc(n * sizeof(int));

//     if (tab == NULL) return 1;

//     int somme = 0;

//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &tab[i]);
//         somme += tab[i];
//     }

//     printf("Sommme : %d\n", somme);

//     free(tab);


//     return 0;
// }

#include <stdlib.h>

// int main() {

//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof(int));

//     if (tab == NULL) {
//         printf("Erreur :  Allocation memoire echouee.\n");
//     }

//     int somme = 0;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//         somme += tab[i];

//     }

//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n%d", somme);


//     free(tab);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = calloc(n, sizeof(int));
//     if (tab == NULL) {
//         printf("Erreur...");
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab[i]);
//     }


//     free(tab);
//     return 0;
// }


// int main() {
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof(int));

//     if (tab == NULL) {
//         return 1;
//     }

//     int somme = 0;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//         somme += tab[i];

//     }

//     printf("\nSomme : %d", somme);
//     free(tab);

//     return 0;
// }

int main() {

    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    float *tab = malloc(n * sizeof * tab);

    if (tab == NULL) {
        return 1;
    }

    float somme = 0;

    for (int i = 0; i < n; ++i) {
        if (scanf("%f", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
        somme += tab[i];

    }



    printf("\nSomme : %d", somme);
    printf("\nMoyenne  : %.2f", (somme / n));
    free(tab);

    return 0;
}


