// #include <stdio.h>
// #include <stdlib.h>

// int **transpoze(int **m, int lignes, int colonnes) {
//     if (m == NULL || lignes <= 0 || colonnes <= 0) {
//         return NULL;
//     }

//     int **temp = calloc(colonnes, sizeof(int *));
//     if (temp == NULL) {
//         return NULL;
//     };

//     for (int i = 0; i < colonnes; ++i) {
//         temp[i] = malloc(lignes * sizeof(int));
//         if (temp[i] == NULL) {
//             for (int k = 0; k < i; ++k) {
//                 free(temp[k]);
//             }
//             free(temp);

//             return NULL;
//         }

//     }

//     for (int i = 0; i < lignes;++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             temp[j][i] = m[i][j];
//         }
//     }

//     return temp;
// }
// void libere(int **m, int l) {
//     if (m == NULL) return;
//     for (int i = 0; i < l; ++i) {
//         free(m[i]);
//     }
//     free(m);
// }

// void display(int **m, int l, int c) {
//     for (int i = 0; i < l; ++i) {
//         printf("[");
//         for (int j = 0; j < c; ++j) {
//             printf("%3d", m[i][j]);
//         }
//         printf("]\n");
//     }
//     printf("\n");
// }

// int main() {

//     int lignes;
//     int colonnes;

//     if (scanf("%d %d", &lignes, &colonnes) != 2 || lignes <= 0 || colonnes <= 0) {
//         printf("Erreur de saisie.\n");
//         return 1;
//     }

//     int **matric = calloc(lignes, sizeof(int *));
//     if (matric == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < lignes; ++i) {
//         matric[i] = malloc(colonnes * sizeof(int));
//         if (matric[i] == NULL) {
//             libere(matric, i);
//             return 1;
//         }
//     }

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes;++j) {
//             matric[i][j] = (i + 1) * 10 + (j + 1);
//         }
//     }
//     printf("Matrice Originale (%dx%d) :\n", lignes, colonnes);
//     display(matric, lignes, colonnes);

//     int **matric_T = transpoze(matric, lignes, colonnes);
//     display(matric_T, lignes, colonnes);


//     libere(matric, lignes);
//     libere(matric_T, colonnes);

//     return 0;
// }
// #include <stdlib.h>
// #include <stdio.h>

// #define LIGNES 5
// #define COLONNES 5

// int *sommeLignes(int **m, int l, int c) {
//     if (m == NULL || l <= 0 || c <= 0)return NULL;
//     int *tab = malloc(LIGNES * sizeof(int));
//     if (tab == NULL) {
//         return NULL;
//     }
//     for (int i = 0; i < LIGNES; ++i) {
//         int total = 0;
//         for (int j = 0; j < COLONNES; ++j) {
//             total += m[i][j];
//         }
//         tab[i] = total;
//     }
//     return tab;
// };

// void libere(int **m, int l) {
//     if (m == NULL) return;
//     for (int i = 0; i < l; ++i) {
//         free(m[i]);
//     }
//     free(m);
// };
// void display(int **m, int l, int c) {

//     for (int i = 0; i < LIGNES; ++i) {
//         for (int j = 0; j < COLONNES; ++j) {
//             printf("%3d", m[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// };

// int main() {

//     int **matrice = calloc(LIGNES, sizeof(int *));
//     if (matrice == NULL) {
//         libere(matrice, LIGNES);
//         return 1;
//     }
//     for (int i = 0; i < LIGNES; ++i) {
//         matrice[i] = malloc(COLONNES * sizeof(int));
//         if (matrice[i] == NULL) {
//             libere(matrice, i);
//             return 1;
//         }
//     }

//     for (int i = 0; i < LIGNES; ++i) {
//         for (int j = 0; j < COLONNES; ++j) {
//             matrice[i][j] = (i + 1) + (j + 1);
//         }
//     }

//     int *somme = sommeLignes(matrice, LIGNES, COLONNES);

//     display(matrice, LIGNES, COLONNES);

//     for (int i = 0;i < LIGNES; ++i) {
//         printf("%2d ", somme[i]);
//     }
//     printf("\n");

//     free(matrice);
//     free(somme);


//     return 0;
// }

// #include <stdlib.h>
// #include <stdio.h>
// void Identity(int **m, int lignes) {
//     if (m == NULL || lignes <= 0) return;
//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < lignes; ++j) {
//             if (i == j) {
//                 m[i][j] = 1;
//             } else {
//                 m[i][j] = 0;
//             }
//         }
//     }
// }

// void libere(int **m, int l) {
//     if (m == NULL)return;
//     for (int i = 0; i < l;++i) {
//         free(m[i]);
//     }
//     free(m);
// }

// void display(int **m, int l) {

//     for (int i = 0; i < l; ++i) {
//         printf("[");
//         for (int j = 0; j < l; ++j) {
//             printf("%2d ", m[i][j]);
//         }
//         printf("]\n");
//     }
//     printf("\n");
// }
// int main() {
//     int N;
//     if (scanf("%d", &N) != 1 || N <= 0) {
//         int c;
//         while ((c = getchar()) != '\n' || c != EOF);
//         return 1;
//     }

//     int **matrice = calloc(N, sizeof(int *));
//     if (matrice == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < N; ++i) {
//         matrice[i] = malloc(N * sizeof(int));
//         if (matrice[i] == NULL) {
//             libere(matrice, i);
//         }
//     }

//     int **identityMatrice = Identity(matrice, N);

//     display(identityMatrice, N);
//     libere(identityMatrice, N);
//     libere(matrice, N);



//     return 0;
// }

#include <stdio.h>

int main() {
    char bloc_memoire[] = "Pazartesi\0Sali\0Carsamba\0Persembe\0Cuma\0Cumartesi\0Pazar";

    char *jours[7];

    int idx_jour = 0;
    jours[idx_jour++] = &bloc_memoire[0];

    size_t taille = sizeof(bloc_memoire);

    for (int i = 0; i < taille - 1; ++i) {
        if (bloc_memoire[i] == '\0') {
            if (idx_jour < 7) {
                jours[idx_jour] = &bloc_memoire[i + 1];
                ++idx_jour;
            }
        }
    }

    printf("Les jours de la semaine :\n");
    for (int i = 0; i < 7; ++i) {
        printf("Jour %d : %s\n", i + 1, jours[i]);
    };

    return 0;
}
