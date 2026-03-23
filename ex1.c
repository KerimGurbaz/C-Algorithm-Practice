#include <stdio.h>
#include <stdlib.h>


// int main() {

//     int capacity = 2;
//     int taille = 0;

//     int *tab = malloc(capacity * sizeof(int));

//     if (tab == NULL) {
//         return 1;
//     }
//     int valeur;
//     while (1) {

//         printf("Entrez un entier positif (une lettre pour finir): ");

//         if (scanf("%d", &valeur) != 1) {
//             free(tab);
//             return 1;
//         }

//         if (taille == capacity) {
//             capacity *= 2;
//             int *temp = realloc(tab, sizeof(int));
//             if (temp == NULL) {
//                 free(tab);
//                 return 1;
//             }
//             tab = temp;
//         }

//         tab[taille++] = valeur;


//     }

//     for (int i = 0; i < taille; ++i) {
//         printf("%d", tab[i]);
//     }

//     free(tab);



//     return 0;
// }


// #define WIDTH 7
// #define HEIGHT 6

// int main() {

//     int tab[WIDTH * HEIGHT];

//     for (int i = 0; i < HEIGHT;++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             tab[i * WIDTH + j] = (i + 1) * (j + 1);
//         }
//     }

//     for (int i = 0; i < HEIGHT; ++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             printf("%2d ", tab[i * WIDTH + j]);
//         }
//         printf("\n");
//     }



//     return 0;
// }


// #define WIDTH 7
// #define HEIGHT 6

// int main() {
//     int tab[HEIGHT][WIDTH];

//     for (int i = 0; i < HEIGHT; ++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             tab[i][j] = (i + 1) * (j + 1);
//         }
//     }

//     for (int i = 0; i < HEIGHT; ++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             printf("%2d ", tab[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

#include <stdio.h>

#define LIGNES 6
#define COLONNES 7

int main() {


    int tab[LIGNES][COLONNES];

    for (int i = 0; i < LIGNES; ++i) {
        for (int j = 0; j < COLONNES; ++j) {
            tab[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < LIGNES; ++i) {
        for (int j = 0; j < COLONNES; ++j) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}
