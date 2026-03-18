//Soru 1 (çok temel) 
//#include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int n;

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");

//     free(tab);
//     return 1;
// }

// //Soru 2
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int n;
//     float somme = 0.0f;

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     float *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%f", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//         somme += tab[i];

//     }

//     for (int i = 0; i < n; ++i) {
//         printf("%.1f ", tab[i]);
//     }
//     printf("\nSomme = %.1f , Moyenne : %.1f", somme, somme / n);

//     free(tab);
//     return 1;
// }

//soru3
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     if (scanf("%d", &tab[0]) != 1) {
//         free(tab);
//         return 1;
//     }
//     int max = tab[0];

//     for (int i = 1; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//         if (tab[i] > max) {
//             max = tab[i];
//         }

//     }

//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\nMax : %d ", max);

//     free(tab);

//     return 0;
// }


//soru 4;
// #include <stdio.h>
// #include <stdlib.h>

// float somme(const float *t, int n) {
//     float my_somme = 0.0f;
//     for (int i = 0; i < n; ++i) {
//         my_somme += t[i];
//     }
//     return my_somme;
// }

// int main() {
//     int n;

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     float *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%f", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }

//     }

//     float result = somme(tab, n);

//     printf("%.1f ", result);

//     free(tab);


//     return 0;
// }


// #include <stdlib.h>
// #include <stdio.h>

// int max(const int *tab, int n) {
//     int max_val = tab[0];
//     for (int i = 1; i < n; ++i) {
//         if (tab[i] > max_val) {
//             max_val = tab[i];
//         }
//     }
//     return max_val;
// }

// int main() {
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     int result = max(tab, n);

//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\nMax : %d ", result);

//     free(tab);

//     return 0;
// }


//SORU 6
// #include <stdlib.h>
// #include <stdio.h>



// int main() {
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab1 = malloc(n * sizeof * tab1);
//     if (tab1 == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab1[i]) != 1) {
//             free(tab1);
//             return 1;
//         }
//     }

//     int *tab2 = malloc(n * sizeof * tab2);
//     if (tab2 == NULL) {
//         fee(tab1);
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         tab2[i] = tab1[i];
//     }

//     printf("\nTab1 : ");

//     for (int i = 0;i < n; ++i) {
//         printf("%d ", tab1[i]);
//     }

//     printf("\nTab2 : ");

//     for (int i = 0;i < n; ++i) {
//         printf("%d ", tab2[i]);
//     }

//     free(tab1);
//     free(tab2);
//     return 0;
// }

// #include <stdlib.h>
// #include <stdio.h>

// int trouver(const int *t, int n, int x) {
//     for (int i = 0; i < n; ++i) {
//         if (t[i] == x) return 1;
//     }
//     return 0;
// }

// int main() {
//     int n, x;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     printf("saisie la valeur a chercher : ");
//     if (scanf("%d", &x) != 1) {
//         free(tab);
//         return 1;
//     }

//     printf("%s\n", trouver(tab, n, x) ? "Valuer trouvee" : "Non trouve");


//     free(tab);

//     return 0;
// }

#include <stdlib.h>
#include <stdio.h>

// int main() {
//     int n;
//     int compteur = 0;


//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         if (tab[i] > 0) {
//             compteur++;
//         }
//     }

//     printf("\n Positives valeures sont :%d ", compteur);

//     free(tab);

//     return 0;
// }



// int main() {
//     int n;
//     long long int somme = 0;
//     int compteur = 0;


//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//         somme += tab[i];
//         ++compteur;

//     }



//     printf("\n Moyenne :%.2f", somme / (float)compteur);

//     free(tab);

//     return 0;
// }
// #include <stdlib.h>
// #include <stdio.h>
// #include <limits.h>
// int indece(const int *t, int n) {
//     int min_val = INT_MAX;
//     int idx = 0;

//     for (int i = 0; i < n; ++i) {
//         if (t[i] < min_val) {
//             idx = i;
//             min_val = t[i];
//         }
//     }
//     return idx;
// }

// int main() {
//     int n;


//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     int idx = indece(tab, n);

//     printf("\nMin idx = %d et valeur : %d", idx, tab[idx]);


//     free(tab);

//     return 0;
// }

////////////////////////////////////////////////////////////////////

//soru 1
#include <stdlib.h>
#include <stdio.h>


// int main() {
//     int n;

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     int *temp = realloc(tab, (2 * n) * sizeof * temp);
//     if (temp == NULL) {
//         free(tab);
//         return 1;
//     }
//     tab = temp;

//     for (int i = n; i < 2 * n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }
//     printf("\n");
//     for (int i = 0; i < 2 * n; ++i) {
//         printf("%d", tab[i]);
//     }

//     printf("\n");

//     free(tab);


//     return 0;
// }


// int main() {
//     int n;

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     int *temp = realloc(tab, (n + 1) * sizeof * temp);
//     if (temp == NULL) {
//         free(tab);
//         return 1;
//     }
//     tab = temp;

//     for (int i = n; i < n + 1; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }
//     printf("\n");
//     for (int i = 0; i < n + 1; ++i) {
//         printf("%d ", tab[i]);
//     }

//     printf("\n");

//     free(tab);


//     return 0;
// }

// int main() {
//     int n;

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     int *temp = realloc(tab, (n - 1) * sizeof * temp);
//     if (temp == NULL) {
//         free(tab);
//         return 1;
//     }
//     tab = temp;


//     printf("\n");
//     for (int i = 0; i < n - 1; ++i) {
//         printf("%d ", tab[i]);
//     }

//     printf("\n");

//     free(tab);


//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int n;
//     printf("Entrez la taille : \n");
//     if (scanf("%d", &n) != 1 || n <= 1) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (!tab) return 1;

//     for (int i = 0; i < n; ++i) scanf("%d", tab + i);
//     int *ptr_des = tab;
//     int *ptr_src = tab + 1;

//     for (int i = 0; i < n - 1; ++i) {
//         *ptr_des = *ptr_src;
//         ++ptr_des;
//         ++ptr_src;
//     }
//     int *temp = realloc(tab, (n - 1) * sizeof * temp);
//     if (temp != NULL) {
//         tab = temp;
//     }

//     printf("Resultat : ");
//     for (size_t i = 0; i < n - 1; i++) printf("%d ", *(tab + i));
//     printf("\n");

//     free(tab);
//     return 0;


//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1


// int main() {
//     int taille = 0;
//     int valeur;

//     int *tab = malloc(CAPACITY * sizeof * tab);
//     if (tab == NULL) return 1;
//     printf("Entrée: \n");
//     do {
//         if (scanf("%d", &valeur) != 1) {
//             free(tab);
//             return 1;
//         };
//         if (valeur != 0) {

//             tab[taille++] = valeur;
//         }

//         int *temp = realloc(tab, (CAPACITY + 1) * sizeof * temp);
//         if (temp == NULL) {
//             free(tab);
//             return 1;
//         }
//         tab = temp;

//     }
//     while (valeur != 0);


//     printf("Sortie:\n %d valeurs ", taille);
//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", tab[i]);
//     }


//     free(tab);


//     return 0;
// }


// int main() {
//     int taille = 0;
//     int valeur;

//     int *tab = malloc(1 * sizeof * tab);
//     if (tab == NULL) return 1;


//     printf("Entree: \n");

//     while (1) {
//         if (scanf("%d", &valeur) != 1) {
//             free(tab);
//             return 1;
//         }

//         if (valeur == 0) break;
//         tab[taille++] = valeur;
//     }

//     int *temp = realloc(tab, (taille + 1) * sizeof * temp);

//     if (temp == NULL) {
//         free(tab);
//         return 1;
//     }
//     tab = temp;

//     printf("Sortie:\n%d valeurs\n", taille);
//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");

//     free(tab);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

// int main() {
//     int taille = 0;
//     int capacity = 1;
//     int valeur;

//     int *tab = malloc(capacity * sizeof * tab);
//     if (tab == NULL) return 1;

//     while (1) {

//         if (scanf("%d", &valeur) != 1) {
//             free(tab);
//             return 1;
//         }

//         if (valeur == 0) break;
//         if (capacity == taille) {
//             capacity *= 2;
//             int *temp = realloc(tab, capacity * sizeof * temp);
//             if (temp == NULL) {
//                 free(tab);
//                 return 1;
//             }
//             tab = temp;
//         }
//         tab[taille++] = valeur;
//         printf("Capacity : %d\n", capacity);
//     }
//     printf("\n");

//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", tab[i]);
//     }
//     free(tab);
//     return 0;
// }

// void ajouter_valeur(int **t, int *taille, int *cap, int valeur) {
//     if (*taille == *cap) {
//         *cap *= 2;

//         int *temp = realloc(*t, (*cap) * sizeof * temp);
//         if (temp != NULL) {
//             *t = temp;
//         } else {
//             free(*t);
//             return 1;
//         }
//     }

//     (*t)[*taille] = valeur;
//     (*taille)++;
// }

// int main() {
//     int taille = 0;
//     int capacity = 1;
//     int *tab = malloc(capacity * sizeof * tab);
//     if (tab == NULL) return 1;

//     int valeur;
//     while (scanf("%d", &valeur) == 1 && valeur != 0) {

//         ajouter_valeur(&tab, &taille, &capacity, valeur);
//     }

//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", tab[i]);
//     }


//     free(tab);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

// #define TAILLE 5


// int main() {
//     size_t lignes = 5;
//     size_t colonnes = 10;
//     int **tab;

//     tab = malloc(lignes * sizeof(int *));
//     if (tab == NULL) return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colonnes * sizeof(int));
//         if (tab[i] == NULL) {
//             for (size_t j = 0; j < i; j++) {
//                 free(tab[j]);
//             }
//             free(tab);
//             return 1;
//         }
//     }

//     for (size_t i = 0; i < lignes; ++i) {
//         for (size_t j = 0; j < colonnes; ++j) {
//             tab[i][j] = (i + 1) * (j + 1);
//         }
//     }

//     for (size_t i = 0; i < lignes; ++i) {
//         for (size_t j = 0; j < colonnes; ++j) {
//             printf("%4d", tab[i][j]);
//         }
//         printf("\n");
//     }

//     for (size_t i = 0; i < lignes; ++i) {
//         free(tab[i]);
//     }
//     free(tab);

//     return 0;

// }


// int main() {
//     int lignes;
//     int colonnes;

//     if (scanf("%d", &lignes) != 1 || lignes <= 0) return 1;
//     if (scanf("%d", &colonnes) != 1 || colonnes <= 0) return 1;

//     int **tab = malloc(lignes * sizeof(int *));
//     if (tab == NULL) return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colonnes * sizeof(int));
//         if (tab[i] == NULL) {
//             for (int j = 0; j < i; ++j) {
//                 free(tab[j]);
//             }
//             free(tab);
//             return 1;
//         }
//     }


//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             if (scanf("%d", &tab[i][j]) != 1) {
//                 for (int k = 0; k < lignes; ++k) {
//                     free(tab[k]);
//                 }
//                 free(tab);
//                 return 1;
//             }

//         }
//     }
//     printf("\nMatrice:\n");
//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             printf("%4d", tab[i][j]);
//         }
//         printf("\n");
//     }

//     free(tab);

//     return 1;
// }

/// @brief /////////////////////777
/// @return 
// int main() {
//     int lignes;
//     int colonnes;

//     if (scanf("%d", &lignes) != 1 || lignes <= 0) return 1;
//     if (scanf("%d", &colonnes) != 1 || colonnes <= 0) return 1;

//     int **tab = malloc(lignes * sizeof(int *));
//     if (tab == NULL)return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colonnes * sizeof(int));
//         if (tab[i] == NULL) {
//             for (int j = 0; j < i; ++j) {
//                 free(tab[j]);
//             }
//             free(tab);
//             return 1;
//         }
//     }

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             if (scanf("%d", &tab[i][j]) != 1) {
//                 for (int k = 0;k < lignes;++k) {
//                     free(tab[k]);
//                 }
//                 free(tab);
//                 return 1;
//             }
//         }
//     }

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             printf("%4d", tab[i][j]);
//         }
//         printf("\n");
//     }


//     free(tab);
//     return 0;
// }

// #include <stdlib.h>
// #include <stdio.h>

// int main() {
//     int lignes;
//     int colones;
//     long long int somme = 0;

//     if (scanf("%d", &lignes) != 1 || lignes <= 0) return 1;
//     if (scanf("%d", &colones) != 1 || colones <= 0) return 1;

//     int **tab = malloc(lignes * sizeof(int *));
//     if (tab == NULL)return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colones * sizeof(int));
//         if (tab[i] == NULL) {
//             for (int j = 0; j < i; ++j) {
//                 free(tab[j]);
//             }
//             free(tab);
//             return 1;
//         }
//     }

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colones; ++j) {
//             if (scanf("%d", &tab[i][j]) != 1) {
//                 for (int k = 0; k < lignes; ++k) {
//                     free(tab[k]);
//                 }
//                 free(tab);
//                 return 1;
//             }
//             somme += tab[i][j];
//         }
//     }
//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colones; ++j) {
//             printf("%4d ", tab[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\nSomme : %lld ", somme);

//     for (int i = 0; i < lignes; ++i) {
//         free(tab[i]);
//     }

//     free(tab);

//     return 0;
// }


int main() {
    int lignes;
    int colones;

    if (scanf("%d", &lignes) != 1 || lignes <= 0) return 1;
}
