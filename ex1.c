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

// #include <stdio.h>

// #define LIGNES 6
// #define COLONNES 7

// int main() {


//     int tab[LIGNES][COLONNES];

//     for (int i = 0; i < LIGNES; ++i) {
//         for (int j = 0; j < COLONNES; ++j) {
//             tab[i][j] = (i + 1) * (j + 1);
//         }
//     }

//     for (int i = 0; i < LIGNES; ++i) {
//         for (int j = 0; j < COLONNES; ++j) {
//             printf("%2d ", tab[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// typedef double mat3x3[3][3];
// typedef double vec3[3];


// void mat_vec_mult(const mat3x3 m, const vec3 v, vec3 res) {
//     for (int i = 0; i < 3; ++i) {
//         double somme = 0.0;
//         for (int j = 0; j < 3; ++j) {
//             somme += m[i][j] * v[j];
//         }
//         res[i] = somme;
//     }
// }



// int main() {
//     mat3x3 m = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     vec3 v = { 1, 2, 3 };

//     // UYARI: Orijinal sorudaki "vec3 w = {};" yapisi C23 oncesi standartlarda warning verir. 
//     // Derleyicinin (gcc) warning vermemesi icin "{0}" seklinde sifirlamak en guvenlisidir.
//     vec3 w = { 0 };

//     mat_vec_mult(m, v, w);

//     // Çıktı: [[1, 2, 3], [4, 5, 6], [7, 8, 9]] * [1, 2, 3] = [14, 32, 50]
//     print_mat("%m * %v = %v\n", m, v, w);

//     return 0;
// }
// int main() {
//     long long nombre;
//     long long inverse = 0;

//     printf("Le nombre d'entree est : ");
//     if (scanf("%lld", &nombre) != 1) {
//         return 1;
//     }

//     long long temp = nombre;

//     do {
//         int reste = temp % 10;
//         inverse = inverse * 10 + reste;
//         temp /= 10;

//     }
//     while (temp > 0);


//     return 0;
// }

// int *extraire_chiffre(int nombre, int *taille_tableau) {
//     if (nombre == 0) {
//         *taille_tableau = 1;
//         int *tab = malloc(1 * sizeof(int));
//         if (tab == NULL) return NULL;

//         tab[0] = 0;
//         return tab;
//     }

//     int temp = nombre;
//     int count = 0;
//     while (temp > 0) {
//         count++;
//         temp /= 10;
//     }

//     *taille_tableau = count;

//     int *tab = malloc(count * sizeof(int));
//     if (tab == NULL) {
//         return NULL;
//     }

//     temp = nombre;
//     for (int i = 0; i < count; ++i) {
//         tab[i] = temp % 10;
//         temp = temp / 10;
//     }
//     return tab;

// }
// int main() {

//     int nombre_utilisateur;
//     int taille;

//     printf("Entrez un nombre positif : ");
//     if (scanf("%d", &nombre_utilisateur) != 1 || nombre_utilisateur < 0) {
//         printf("Saisie invalide :\n");
//         return 1;
//     }

//     int *chiffres = extraire_chiffre(nombre_utilisateur, &taille);
//     if (chiffres == NULL) {
//         printf("Erreur d'allocation memoire.\n");
//         return 1;
//     }

//     printf("Les chiffres extraits(unites d'abors) : ");
//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", chiffres[i]);
//     }
//     printf("\n");

//     free(chiffres);
//     return 0;
// }


// #include <stdio.h>
// #define TAILLE 5

// void sommeTab(const int *t1, const int *t2, int *res, int taille) {
//     for (int i = 0; i < taille; ++i) {
//         res[i] = t1[i] + t2[i];
//     }
// }

// void afficher(const char *nom, const int *t, int taille) {
//     printf("%s : [", nom);
//     for (int i = 0; i < taille; ++i) {
//         printf("%d", t[i]);
//         if (i < taille - 1) {
//             printf(", ");
//         }
//     }
//     printf("]\n");
// }
// void readAndFillArrays(int *tab1, int *tab2) {
//     char line[1000];
//     // Read the input line
//     if (fgets(line, sizeof(line), stdin)) {
//         // Parse the input line to fill in tab1 and tab2
//         sscanf(line, "[%d,%d,%d,%d,%d], [%d,%d,%d,%d,%d]",
//             &tab1[0], &tab1[1], &tab1[2], &tab1[3], &tab1[4],
//             &tab2[0], &tab2[1], &tab2[2], &tab2[3], &tab2[4]);
//     }
// }

// int main() {
//     int tab1[TAILLE];
//     int tab2[TAILLE];
//     int resultat[TAILLE];

//     readAndFillArrays(tab1, tab2);

//     sommeTab(tab1, tab2, resultat, TAILLE);

//     afficher("Premier Tab", tab1, TAILLE);
//     afficher("Deuxieme tab", tab2, TAILLE);
//     afficher("Resultat : ", resultat, TAILLE);



//     return 0;
// }


// #define TAILLE 5

// void traiter_tableau(int *t, int taille, int *min, int *max) {
//     if (taille <= 0) return;
//     *min = t[0];
//     *max = t[0];

//     for (int i = 0; i < taille / 2; ++i) {
//         int temp = t[i];
//         t[i] = t[taille - 1 - i];
//         t[taille - 1 - i] = temp;
//     }

//     for (int i = 0; i < taille; ++i) {
//         if (t[i] > *max) {
//             *max = t[i];
//         }
//         if (t[i] < *min) {
//             *min = t[i];
//         }
//     }

// }

// int main() {
//     int nombres[TAILLE] = { 15,42,8,99,23 };

//     int minimum;
//     int maximum;

//     printf("AVANT : [ ");
//     for (int i = 0; i < TAILLE; ++i) printf("%d ", nombres[i]);
//     printf("\n");

//     traiter_tableau(nombres, TAILLE, &minimum, &maximum);
//     printf("Apres : [ ");
//     for (int i = 0; i < TAILLE; i++) printf("%d ", nombres[i]);
//     printf("]\n");

//     printf("Valeur minimale : %d\n", minimum);
//     printf("Valeur maximale : %d\n", maximum);


//     return 0;
// }

// #include <stdio.h>    // printf, scanf
// #include <stddef.h>   // size_t
// #include <stdlib.h>   // calloc, free, malloc
// #include <stdint.h>   // int64_t 
// #include <inttypes.h> // SCNd64

// size_t lire_size_t(const char *message) {
//     // lecture avec vérification d'un entier de type size_t 

//     int64_t n;
//     printf("%s", message);
//     while (scanf("%" SCNd64, &n) != 1 || n <= 0) {
//         printf("Erreur de saisie. Entrez un entier positif : ");
//         while (getchar() != '\n')
//             ;
//     }
//     return (size_t)n;
// }

// int main() {
//     size_t lignes;
//     size_t colonnes;
//     int **tab;

//     lignes = lire_size_t("Nombre de lignes ? ");
//     colonnes = lire_size_t("Nombre de colonnes ? ");
//     printf("\n");

//     // allocation du tableau de tableaux
//     tab = calloc(lignes, sizeof(int *));
//     if (tab == NULL) goto liberation;

//     // allocation des tableaux pour chaque ligne
//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colonnes * sizeof(int));
//         if (tab[i] == NULL) goto liberation;
//     }


//     // remplissage avec les valeurs de la table de multiplication

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             tab[i][j] = (i + 1) * (j + 1);
//         }
//     }


//     // affichage
//     for (int i = 0; i < lignes; ++i) {
//         for (size_t j = 0; j < colonnes; ++j) {
//             printf("%2d ", tab[i][j]);
//         }
//         printf("\n");
//     }


// liberation:
//     if (tab != NULL) {
//         for (int i = 0; i < lignes; ++i) {
//             if (tab[i] != NULL) {
//                 free(tab[i]);
//             }
//         }
//         free(tab);
//     }

//     return 0;

// }
// #include <stdlib.h>
// #include <stdio.h>

// int **cree_matrice_triangulaire(size_t taille) {
//     if (taille == 0) return NULL;

//     int **matrice = calloc(taille, sizeof(int *));
//     if (matrice == NULL) return NULL;

//     int compteur = 1;

//     for (int i = 0; i < taille; ++i) {
//         matrice[i] = malloc((i + 1) * sizeof(int));

//         if (matrice[i] == NULL) {
//             for (size_t k = 0; k < i; ++k) {
//                 free(matrice[k]);
//             }
//             free(matrice);
//             return NULL;
//         }
//         for (size_t j = 0; j < i; ++j) {
//             matrice[i][j] = compteur++;
//         }

//     }
//     return matrice;
// }


// void liberer_triangulaire(int **matrice, size_t taille) {
//     if (matrice == NULL) return;

//     for (size_t i = 0; i < taille; ++i) {
//         if (matrice[i] == NULL);
//         free(matrice[i]);
//     }
//     free(matrice);
// }



// int main() {

//     size_t N;
//     printf("Entrez la taille de la matrice .. : ");
//     if (scanf("%d", &N) != 1 || N <= 0) {
//         printf("Saisie invalide .\n");
//         return 1;
//     }

//     int **mat_triangulaire = cree_matrice_triangulaire(N);
//     if (mat_triangulaire == NULL) {
//         return 1;
//     }

//     printf("\nMatrice Triangulaire Inferieure :\n");
//     for (size_t i = 0; i < N; ++i) {
//         for (size_t j = 0; j <= i; ++j) {
//             printf("%3d ", mat_triangulaire[i][j]);
//         }
//         printf("\n");
//     }

//     liberer_triangulaire(mat_triangulaire, N);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// void libere_matrice(int **matrice, size_t n) {
//     if (matrice != NULL) {
//         for (int i = 0; i < n; ++i) {
//             free(matrice[i]);
//         }
//         free(matrice);
//     }
// }

// int **rotation_droite(int **matrice, size_t n) {
//     int **resultat = calloc(n, sizeof(int *));
//     if (resultat == NULL) return NULL;

//     for (size_t i = 0; i < n; ++i) {
//         resultat[i] = malloc(n * sizeof(int));
//         if (resultat[i] == NULL) {
//             for (size_t k = 0; k < i; ++k) {
//                 free(resultat[k]);
//             }
//             free(resultat);
//             return NULL;
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             resultat[j][n - 1 - i] = matrice[i][j];
//         }
//     }

//     return resultat;

// }


// int main() {

//     size_t n = 3;

//     int **image = malloc(n * sizeof(int *));
//     if (image == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         image[i] = malloc(n * sizeof(int));
//         if (image[i] == NULL) {
//             libere_matrice(image, i);
//             return 1;
//         }
//         for (size_t j = 0; j < n; ++j) {
//             image[i][j] = (i * n) + j + 1;
//         }
//     }

//     printf("Image originale :\n");
//     for (size_t i = 0; i < n; i++) {
//         for (size_t j = 0; j < n; j++) printf("%2d ", image[i][j]);
//         printf("\n");
//     }

//     int **image_tourne = rotation_droite(image, n);

// }

// #include <stdio.h>
// int main() {
//     char memoire[] = "Mardi\0Lundi\0Mercredi\0";

//     char *jours[3];

//     jours[0] = &memoire[6];
//     jours[1] = &memoire[0];
//     jours[2] = &memoire[12];

//     for (int i = 0; i < 3; ++i) {
//         printf("- %s\n", jours[i]);
//     }

//     return 0;
// }

// void *trier_jours(char **tableau, int taille) {
//     if (tableau == NULL || taille <= 1) return;

//     for (int i = 0; i < taille - 1; ++i) {
//         for (int j = 0; j < taille - i - 1; ++j) {
//             if (strcmp(tableau[j], tableau[j + 1]) > 0) {
//                 char *temp = tableau[j];
//                 tableau[j] = tableau[j + 1];
//                 tableau[j + 1] = temp;
//             }
//         }
//     }

// }


// int main() {
//     char *semaine[] = {
//         "Vendredi",
//         "Lundi",
//         "Mardi",
//         "Jeudi",
//         "Mercredi"
//     };

//     int taille = sizeof(semaine) / sizeof(semaine[0]);

//     printf("AVANT\n");
//     for3 (int i = 0; i < taille; ++i) {
//         printf("-%s\n", semaine[i]);
//     }

//     trier_jours(semaine, taille);

//     printf("\n--- Apres le tri (Alphabetique) ---\n");
//     for (int i = 0; i < taille; i++) {
//         printf("%s\n", semaine[i]);
//     }
// }

int extraire_valeurs(const char *buffer, const char *valeurs[]) {
    int count = 0;
    const char *ptr = buffer;

    while (*ptr != '\0') {
        while (*ptr != '=' && *ptr != '\0') {
            ++ptr;
        }
        if (*ptr == '=') {
            ptr++;
            valeurs[count++] = ptr;
        }

        while (*ptr != '\0') {
            ptr++;
        }
        ptr++;
    }
    return count;
}


int main() {
    const char env_buffer = "USER=ahmet\0LANG=fr\0PATH=/bin\0";

    const char *valeurs_extraites[10];

    int nb_valeurs = extraire_valeurs(env_buffer, valeurs_extraites);

    for (int i = 0; i < nb_valeurs; ++i) {
        printf("- %s\n", valeurs_extraites[i]);
    }
}
