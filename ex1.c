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


// int main() {
//     int lignes;
//     int colones;
//     long long int somme = 0;

//     if (scanf("%d", &lignes) != 1 || lignes <= 0) return 1;
//     if (scanf("%d", &colones) != 1 || colones <= 0) return 1;

//     int **tab = malloc(lignes * sizeof(int *));
//     if (tab == NULL) return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colones * sizeof(int));
//         if (tab[i] == NULL) {
//             for (int k = 0; k < i; ++k) {
//                 free(tab[k]);
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
//             printf("%3d", tab[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\nSomme : %lld \n ", somme);

//     for (int i = 0; i < lignes; ++i) {
//         free(tab[i]);
//     }
//     free(tab);
//     return 0;

// }


// #include <stdio.h>
// #define TAILLE_MAX 10

// int iTab[TAILLE_MAX] = { 3, 6, 0, 8, 97, 0, 5, 6, 0, 8 };

// int main() {

//     int *p = iTab;
//     int *fin = iTab + TAILLE_MAX;

//     for (; p < fin; ++p) {
//         if (*p == 0) {
//             printf("%td ", p - iTab);
//         }
//     }

//     return 0;

// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main() {
//     int lignes;
//     int colonnes;
//     int max_element = INT_MIN;

//     if (scanf("%d", &lignes) != 1 || lignes <= 1) return 1;
//     if (scanf("%d", &colonnes) != 1 || colonnes <= 1) return 1;

//     int **tab = malloc(lignes * sizeof(int *));
//     if (tab == NULL) return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colonnes * sizeof(int));
//         if (tab[i] == NULL) {
//             for (int j = 0; j < i;++j) {
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
//             if (tab[i][j] > max_element) {
//                 max_element = tab[i][j];
//             }
//         }

//     }

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             printf("%3d", tab[i][j]);
//         }
//         printf("\n");
//     }



//     printf("\nMax element : %d ", max_element);
//     for (int i = 0; i < lignes; ++i) {
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
//             for (int k = 0; k < i; ++k) {
//                 free(tab[k]);
//             }
//             free(tab);
//             return 1;
//         }
//     }

//     int **tr = malloc(lignes * sizeof(int *));
//     if (tr == NULL) return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tr[i] = malloc(colonnes * sizeof(int));
//         if (tr[i] == NULL) {
//             for (int k = 0; k < i; ++k) {
//                 free(tr[k]);
//             }
//             free(tr);
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
//             tr[j][i] = tab[i][j];
//         }

//     }

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             printf("%3d", tab[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             printf("%3d", tr[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");




//     for (int i = 0; i < lignes; ++i) {
//         free(tab[i]);
//     }
//     for (int i = 0; i < lignes; ++i) {
//         free(tr[i]);
//     }
//     free(tab);
//     free(tr);


//     return 0;
// }


// #include <stdio.h>

// int main(void) {
//     int a;
//     float b;
//     char mot[30];

//     printf("Entrez un entier : ");
//     if (scanf("%d", &a) != 1) return 1;

//     printf("Entrez un flottant : ");
//     if (scanf("%f", &b) != 1) return 1;

//     printf("Entrez un mot : ");
//     scanf("%29s", mot);

//     printf("Entier : %d\n", a);
//     printf("Flottant : %.2f\n", b);
//     printf("Mot : %s\n", mot);

//     return 0;
// }

// size_t longueur_chaine(const char *str) {
//     if (str == NULL) return 0;

//     const char *ptr = str;

//     while (*ptr != '\0') {
//         ptr++;
//     }

//     return ptr - str;
// }
// int main() {

//     char mot[30];

//     printf("Entrez un mot : ");
//     if (scanf("%29s", mot) != 1) return 1;

//     size_t longueur = longueur_chaine(mot);
//     printf("Le mot '%s' contient %zu caracters.\n", mot, longueur);


//     return 0;
// }


// #include <stdio.h>

// int main(void) {
//     int age;
//     float taille;
//     char nom[20];

//     printf("Entrez votre age : ");
//     //scanf("%f", age);
//     scanf("%d", &age);

//     printf("Entrez votre taille : ");
//     //scanf("%d", &taille);
//     scanf("%f", &taille);

//     printf("Entrez votre nom : ");
//     scanf("%19s", nom);

//     printf("Age : %d\n", age);
//     printf("Taille : %.2f\n", taille);
//     printf("Nom : %s\n", nom);

//     return 0;
// }

// char *dupliquer_mot(const char *source) {
//     if (source == NULL) return NULL;

//     size_t longeur = 0;
//     const char *ptr = source;
//     while (*ptr != '\0') {
//         longeur++;
//         ptr++;
//     }

//     char *copie = malloc((longeur + 1) * sizeof(char));
//     if (copie == NULL) return NULL;

//     const char *ptr_source = source;
//     char *ptr_dest = copie;

//     while (*ptr_source != '\0') {
//         *ptr_dest = *ptr_source;
//         ptr_dest++;
//         ptr_source++;
//     }

//     *ptr_dest = '\0';

//     return copie;
// }


// int main() {
//     char mot_statique[30];

//     printf("Entrez un mot : ");
//     if (scanf("%29s", mot_statique) != 1) return 1;

//     char *mot_dynamique = dupliquer_mot(mot_statique);
//     if (mot_dynamique == NULL) return 1;

//     printf("Copie dynamique : %s\n", mot_dynamique);

//     free(mot_dynamique);


//     return 0;
// }
// #include <limits.h>

// void calcul_moyenne(int **tab, int lignes, int colonnes, float *moyenne) {
//     if (tab != NULL && lignes >= 0 && colonnes >= 0) {
//         int somme = 0;
//         int element = lignes * colonnes;
//         for (int i = 0; i < lignes;++i) {
//             for (int j = 0; j < colonnes; ++j) {
//                 somme += tab[i][j];
//             }
//         }


//         if (somme != 0) {
//             *moyenne = (float)somme / element;
//         }
//     }
//     printf("\nMoyenne : %.2f ", *moyenne);

// }

// void afficher_superieurs(int **tab, float moyenne, int lignes, int colonnes) {

//     for (int i = 0; i < lignes; ++i) {
//         int lgn = INT_MIN;
//         int somme = 0;
//         for (int j = 0; j < colonnes; ++j) {
//             somme += tab[i][j];
//             if (somme > moyenne) {
//                 printf("\nLigne %d, colonnes %d : %d", i, j, somme);
//             }
//         }
//     }
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
//                 for (int k = 0; k < lignes; ++i) {
//                     free(tab[k]);
//                 }
//                 free(tab);
//                 return 1;
//             }
//         }
//     }
//     float moyenne = 0.0f;

//     calcul_moyenne(tab, lignes, colonnes, &moyenne);

//     afficher_superieurs(tab, moyenne, lignes, colonnes);

//     for (int i = 0; i < lignes; ++i) {
//         free(tab[i]);
//     }


//     free(tab);
//     return 0;
// }

// void calcul_moyenne(int **tab, int lignes, int colonnes, float *moyenne) {
//     if (tab == NULL || lignes <= 0 || colonnes <= 0) return;

//     int somme = 0;
//     int elements = lignes * colonnes;

//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             somme += tab[i][j];
//         }
//     }

//     *moyenne = (float)somme / elements;
// }

// void afficher_superieurs(const int **tab, int lignes, int colonnes, float moyenne) {
//     printf("\n Emenets superieurs à la moyenne %f : \n", moyenne);

//     for (int i = 0; i < lignes; ++i) {
//         printf("Ligne %d :", i);

//         for (int j = 0; j < colonnes; ++j) {
//             if (tab[i][j] > moyenne) {
//                 printf(" %d", tab[i][j]);
//             }
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int lignes, colonnes;

//     printf("Nobre de lignes : ");
//     if (scanf("%d", &lignes) != 1 || lignes <= 0) return 1;
//     printf("Nobre de colonnes : ");
//     if (scanf("%d", &colonnes) != 1 || colonnes <= 0) return 1;

//     int **tab = malloc(lignes * sizeof(int *));
//     if (tab == NULL) return 1;

//     for (int i = 0; i < lignes; ++i) {
//         tab[i] = malloc(colonnes * sizeof(int));
//         if (tab[i] == NULL) {
//             for (int j = 0; j < lignes; ++j) {
//                 free(tab[j]);
//             }
//             free(tab);
//             return 1;
//         }
//     }


//     printf("Entrez les valeur (%d * %d ) : \n", lignes, colonnes);
//     for (int i = 0; i < lignes; ++i) {
//         for (int j = 0; j < colonnes; ++j) {
//             printf("Ligne %d, colonne %d : ", i, j);
//             if (scanf("%d4d", &tab[i][j]) != 1) {
//                 for (int k = 0; k < lignes; ++k) {
//                     free(tab[k]);
//                 }
//                 free(tab);
//                 return 1;
//             }
//         }
//     }

//     float moyenne = 0.0f;
//     calcul_moyenne(tab, lignes, colonnes, &moyenne);

//     afficher_superieurs((const int **)tab, lignes, colonnes, moyenne);


//     for (int i = 0; i < lignes; ++i) {
//         free(tab[i]);
//     }

//     free(tab);

//     return 0;
// }

// void reverseString(char *str) {

//     int longeur = 0;
//     char *first = str;
//     char *ptr = str;


//     while (*ptr != '\0') {
//         ++longeur;
//         ptr++;
//     }

//     char copy[longeur + 1];

//     for (int i = 0; i < longeur + 1; ++i) {
//         copy[i] = str[longeur - 1 - i];
//     }
//     copy[longeur] = '\0';

//     printf("\nApres inversion : %s\n", str);
//     printf("%29s", copy);

// }


// int main() {
//     char str[30] = "Programmation en C";


//     printf("Avant inversion : %s\n", str);
//     reverseString(str);
//     return 0;
// }

// void reverseString(char *str) {

//     if (str == NULL) return;
//     int longeur = 0;

//     while (str[longeur] != '\0') {
//         longeur++;
//     }

//     int gauche = 0;
//     int droite = longeur - 1;

//     while (gauche < droite) {
//         char temp = str[gauche];
//         str[gauche] = str[droite];
//         str[droite] = temp;

//         gauche++;
//         droite--;
//     }
// }


// int main() {

//     char str[30] = "Programation en C";
//     printf("Avant inversion : %s\n", str);

//     reverseString(str);

//     printf("Apres Inversion : %s\n", str);

//     return 0;
// }

// void nettoyer_chaine(char *str) {
//     if (str == NULL) return;

//     char *read = str;
//     char *write = str;

//     while (*read != '\0') {
//         char c = *write;
//         int est_minuscule = (c >= 'a' && c <= 'z');
//         int est_majuscule = (c >= 'A' && c <= 'Z');
//         int est_chiffre = (c >= '0' && c <= '9');

//         if (est_minuscule || est_chiffre || est_majuscule) {
//             if (est_majuscule) {
//                 c = c + 32;
//             }
//             *write++ = c;

//         }

//         ++read;
//     }
//     *read = '\0';
// }


// int main() {
//     char texte[] = "Hello, World! 2026... C'est top.";

//     printf("Original : %s\n", texte);
//     nettoyer_chaine(texte);
//     printf("Nettoye : %s\n", texte);

//     return 0;
// }
// #define N 3

// typedef double mat3x3[3][3];
// typedef double vec3[3];

// void mat_vec_mult(mat3x3 m, vec3 v, vec3 res) {
//     for (int i = 0; i < N; ++i) {
//         double somme = 0.;
//         for (int j = 0; j < N; ++j) {
//             somme += m[i][j] * v[j];
//         }
//         res[i] = somme;
//     }
// }

// void display(vec3 v) {
//     printf("[");
//     for (int i = 0; i < N; ++i) {
//         if (i != 0) {
//             printf(", ");
//         }
//         printf("%.1f", v[i]);
//     }
//     printf("]\n");
// }

// int main() {

//     mat3x3 ma_matrice = {
//             {1.0, 2.0, 3.0},
//             {4.0, 5.0, 6.0},
//             {7.0, 8.0, 9.0}
//     };
//     vec3 v = { 1,2,3 };
//     vec3 res = { 0,0,0 };


//     mat_vec_mult(ma_matrice, v, res);
//     display(res);

//     return 0;
// }
#include <stdio.h>
#define N 3

typedef double mat3x3[3][3];

void mat_mult(mat3x3 a, mat3x3 b, mat3x3 res) {
    for (int i = 0; i < N; ++i) {

        for (int j = 0; j < N; ++j) {
            int somme = 0;
            for (int k = 0; k < N; ++k) {
                somme += a[i][k] * b[k][j];
            }
            res[i][j] = somme;
        }

    }

}

void print_mat(mat3x3 m) {
    for (int i = 0; i < N; ++i) {
        printf("[");
        for (int j = 0; j < N; ++j) {
            printf("%.0f", m[i][j]);
            if (j < N - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main() {


    mat3x3 a = {
     {1, 2, 3},
     {4, 5, 6},
     {7, 8, 9}
    };

    mat3x3 b = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    mat3x3 res = { 0 };

    mat_mult(a, b, res);

    print_mat(res);


    return 0;

}
