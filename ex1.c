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

// int main() {

//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     float *tab = malloc(n * sizeof * tab);

//     if (tab == NULL) {
//         return 1;
//     }

//     float somme = 0;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%f", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//         somme += tab[i];

//     }



//     printf("\nSomme : %d", somme);
//     printf("\nMoyenne  : %.2f", (somme / n));
//     free(tab);

//     return 0;
// }


// #include <stdlib.h>

// int main() {

//     int n;
//     printf("Enterz un valeur\n");
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab1 = malloc(n * sizeof * tab1);

//     if (tab1 == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab1[i]) != 1) {
//             printf("Erreur...");
//             free(tab1);
//             return 1;
//         }
//     }
//     int *tab2 = malloc(n * sizeof * tab2);

//     if (tab2 == NULL)return 1;

//     for (int i = 0; i < n; ++i) {
//         tab2[i] = tab1[i];
//     }


//     printf("\nTab1 : ");
//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab1[i]);
//     }

//     printf("\nTab2 : ");
//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab2[i]);
//     }

//     free(tab1);
//     free(tab2);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// bool chercer(const int tab[], int x, int n) {
//     for (int i = 0; i < n; ++i) {
//         if (tab[i] == x) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {

//     int n;
//     printf("Enterz un valeur: \n");
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     printf("\nEntre un valeur que  vous voulez chercher : ");
//     int x;
//     if (scanf("%d", &x) != 1) return 1;

//     printf(chercer(tab, x, n) ? "\nValeur trouvee" : "\nValeur absente");

//     free(tab);
//     return  0;
// }

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// const int *chercher(const int *tab, int n) {
//     if (n <= 0) return NULL;
//     const int *ptr_max = &tab[0];

//     for (int i = 1; i < n; ++i) {
//         if (tab[i] > *ptr_max) {
//             ptr_max = &tab[i];
//         }
//     }

//     return ptr_max;
// }


// int main() {
//     int n, max_val;
//     printf("Enterz un valeur: \n");
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }



//     const int *p = chercher(tab, n);

//     printf("\nMax value address : %p", (void *)p);
//     printf("\nMax value  : %d", *p);

//     free(tab);
//     tab = NULL;
//     return 0;
// }

// void trouve(const int *tab, int n) {
//     int min_val = tab[0];
//     int idx = 0;

//     for (int i = 0; i < n; ++i) {
//         if (tab[i] < min_val) {
//             min_val = tab[i];
//             idx = i;
//         }
//     }
//     printf("\nMinimum : %d ", min_val);
//     printf("\nIndice : %d ", idx);
// }

// int main() {

//     int n, min_val;
//     printf("Enterz un valeur: \n");
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }
//     int idx = 0;

//     trouve(tab, n);

//     free(tab);

//     return 0;
// }

// #include <stdlib.h>
// #include <stdio.h>


// int main() {
//     int n;
//     if (scanf("%d", &n) != 1) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }
//     int *temp = realloc(tab, (2 * n) * sizeof * temp);

//     if (temp == NULL) {
//         printf("Erreur :...\n");
//         free(tab);
//         return 1;
//     }
//     tab = temp;

//     for (int i = 0; i < 2 * n; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");

//     return 0;
// }


// int main() {
//     int n;
//     if (scanf("%d", &n) != 1) return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) return 1;

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

//     int *temp = realloc(tab, (2 * n) * sizeof * temp);
//     if (temp == NULL) {
//         free(tab);
//         return 1;
//     }
//     tab = temp;
//     for (int i = n; i <= n; ++i) {
//         if (scanf("%d", &tab[i]) != 1)return 1;
//     }

//     for (int i = 0; i <= n; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");
//     free(tab);
//     free(temp);


//     return 0;
// }


// int main() {
//     int n;
//     printf("Enterz une valeur : ");
//     if (scanf("%d", &n) != 1 || n <= 0)return 1;

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             free(tab);
//             return 1;
//         }
//     }

//     int *temp = realloc(tab, (n - 1) * sizeof * temp);
//     if (temp != NULL) {
//         tab = temp;
//     }

//     for (int i = 0; i < n - 1; ++i) {
//         printf("%d ", tab[i]);
//     }

//     free(tab);
//     tab = NULL;

//     return 0;
// }


// int main() {

//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) {
//         return 1;
//     }

//     int *tab = malloc(n * sizeof * tab);
//     if (tab == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i] != 1)) {
//             free(tab);
//             return 1;
//         }
//     }

//     int k;
//     if (scanf("%d", &k) != 1 || k < 0 || k >= n) {
//         free(tab);
//         return 1;
//     }

//     for (int i = k; i < n - 1; ++i) {
//         tab[i] = tab[i + 1];
//     }

//     int *temp = realloc(tab, (n - 1) * sizeof * tab);
//     if (temp != NULL) {
//         tab = temp;
//     }

//     for (int i = 0;i < n - 1; ++i) {
//         printf("%d", tab[i]);
//     }
//     printf("\n");

//     free(tab);


//     return 0;
// }
#include <stdlib.h>

// int main() {
//     int taille = 1;
//     int nb = 0;
//     int val;

//     int *tab = malloc(taille * sizeof * tab);
//     if (tab == NULL)return 1;

//     while (scanf("%d", &val) == 1 && val != 0) {
//         tab[nb++] = val;


//         int *temp = realloc(tab, (taille++) * sizeof * tab);
//         if (temp == NULL) {
//             free(tab);
//             return 1;
//         }
//         tab = temp;

//     }

//     for (int i = 0; i < nb;++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");

//     free(tab);
//     return 0;
// }


// int main() {
//     int taille = 0;
//     int *tab = malloc(1 * sizeof * tab);
//     if (tab == NULL) return 1;

//     int valuer;
//     while (1) {
//         if (scanf("%d", &valuer) != 1) {
//             free(tab);
//             return 1;
//         }
//         if (valuer == 0) break;
//         tab[taille++] = valuer;

//         int *temp = realloc(tab, (taille + 1) * sizeof * tab);
//         if (temp == NULL) {
//             free(tab);
//             return 1;
//         }
//         tab = temp;

//     }

//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");
//     free(tab);
//     return 0;
// }


// int main() {
//     int taille = 0;
//     int capacity = 1;
//     int valeur;

//     int *tab = malloc(capacity * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     while (scanf("%d", &valeur) == 1) {
//         if (valeur == 0)break;
//         tab[taille++] = valeur;

//         if (taille == capacity) {
//             capacity *= 2;
//             int *temp = realloc(tab, capacity * sizeof * tab);
//             if (temp == NULL) {
//                 free(tab);
//                 return 1;
//             }
//             tab = temp;

//         }

//     }
//     if (capacity > taille && taille > 0) {
//         int *temp = realloc(tab, taille * sizeof * tab);

//         if (temp != NULL) {
//             tab = temp;
//             capacity == taille;
//         }
//     }

//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\ntaille : %d   && capacity : %d", taille, capacity);

//     free(tab);


//     return 0;


// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int taille = 0;
//     int capacity = 1;
//     int valeur;

//     int *tab = malloc(capacity * sizeof * tab);
//     if (tab == NULL) return 1;

//     while (scanf("%d", &valeur) == 1) {
//         if (valeur == 0) break;

//         // 1. On ajoute d'abord
//         tab[taille++] = valeur;

//         // 2. On double SEULEMENT si c'est plein
//         if (taille == capacity) {
//             capacity *= 2;
//             int *temp = realloc(tab, capacity * sizeof * tab);
//             if (temp == NULL) {
//                 free(tab);
//                 return 1;
//             }
//             tab = temp;
//         }
//     }

//     // --- LE VRAI SHRINK-TO-FIT ---
//     // Si la RAM allouée (capacity) est plus grande que les données utiles (taille)
//     // ET qu'il y a au moins 1 donnée (taille > 0).
//     if (capacity > taille && taille > 0) {
//         int *temp = realloc(tab, taille * sizeof * tab);
//         if (temp != NULL) {
//             tab = temp;
//             capacity = taille; // Maintenant, l'étiquette correspond à la réalité physique
//         }
//     }

//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", tab[i]);
//     }
//     printf("\nTaille : %d  && Capacity : %d\n", taille, capacity);

//     free(tab);
//     return 0;
// }


// int main() {
//     int taille = 0;
//     int capacity = 1;
//     float valeur;



//     float *tab = malloc(capacity * sizeof * tab);
//     if (tab == NULL) {
//         return 1;
//     }

//     while (scanf("%f", &valeur) == 1) {
//         if (valeur == 'q') {
//             break;
//         }

//         tab[taille++] = valeur;
//         if (capacity == taille) {
//             capacity *= 2;
//             float *temp = realloc(tab, capacity * sizeof * tab);
//             if (temp == NULL) {
//                 free(tab);
//                 return 1;
//             }
//             tab = temp;
//         }

//     }

//     for (int i = 0; i < taille;++i) {
//         printf("%f", tab[i]);
//     }

//     printf("\n");
//     free(tab);
//     return 0;

// }


// int main() {
//     int taille = 0, capacity = 1;

//     float *tab = malloc(capacity * sizeof * tab);
//     if (tab == NULL)return 1;

//     char buffer[32];

//     while (scanf("%31s", &buffer) == 1) {
//         if (buffer[0] == 'q') break;

//         float valeur = atof(buffer);

//         tab[taille++] = valeur;

//         if (taille == capacity) {
//             capacity *= 2;

//             float *temp = realloc(tab, capacity * sizeof * tab);
//             if (temp == NULL) {
//                 free(tab);
//                 return 1;
//             }
//             tab = temp;
//         }

//     }

//     if (capacity > taille && taille > 0) {
//         float *temp = realloc(tab, (taille) * sizeof * tab);
//         if (temp == NULL) {
//             free(tab);
//             return 1;
//         }
//         tab = temp;
//         capacity = taille;
//     }

//     for (int i = 0; i < taille; ++i) {
//         printf("%.2f ", tab[i]);
//     }

//     printf("\ntaille : %d", taille);
//     printf("\nCapacity : %d  ", capacity);

//     free(tab);
//     return 0;
// }

// int main() {
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab1 = malloc(n * sizeof * tab1);
//     if (tab1 == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab1[i]) != 1) {
//             free(tab1);
//             return 1;
//         }
//     }

//     int *tab2 = malloc(n * sizeof * tab2);
//     if (tab2 == NULL) {
//         free(tab1);
//         return 1;
//     }
//     for (int i = 0; i < n; ++i) {
//         tab2[i] = tab1[i];
//     }

//     int *temp = realloc(tab2, (2 * n) * sizeof * temp);
//     if (temp == NULL) {
//         free(tab1);
//         free(tab2);
//         return 1;
//     }

//     for (int i = 0; i < 2 * n; ++i) {
//         printf("%d ", tab2[i]);
//     }

//     printf("\n");
//     free(tab1);
//     free(tab2);


//     return 0;
// }



// int main() {
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int *tab1 = malloc(n * sizeof * tab1);
//     if (tab1 == NULL) return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab1[i]) != 1) {
//             free(tab1);
//             return 1;
//         }
//     }

//     int *tab2 = malloc(n * sizeof * tab2);
//     if (tab2 == NULL) {
//         free(tab1);
//         return 1;
//     }

//     for (int i = 0; i < n; ++i) {
//         tab2[i] = tab1[i];
//     }

//     int *temp = realloc(tab2, (2 * n) * sizeof * tab2);
//     if (temp == NULL) {
//         free(tab1);
//         free(tab2);
//         return 1;
//     }

//     tab2 = temp;

//     for (int i = n; i < 2 * n; ++i) {
//         if (scanf("%d", &tab2[i]) != 1) {
//             free(tab1);
//             free(tab2);
//             return 1;
//         }
//     }

//     for(int i = 0; i<n*2; ++i){
//         printf("%d ", tab2[i]);
//     }


//     free(tab1);
//     free(tab2);



//     return 0;
// }


// int main() {
//     int n;
//     if (scanf("%d", &n) != 1) {
//         return 1;
//     }

//     int *tab1 = malloc(n * sizeof * tab1);
//     if (tab1 == NULL)return 1;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab1[i]) != 1) {
//             free(tab1);
//             return 1;
//         }
//     }

//     int *tab2 = malloc(n * sizeof * tab2);
//     if (tab2 == NULL) {
//         free(tab1);
//         return 1;
//     }
//     for (int i = 0; i < n; ++i) {
//         tab2[i] = tab1[n - 1 - i];
//     }

//     int *temp = realloc(tab2, (2 * n) * sizeof * tab2);
//     if (temp == NULL) {
//         free(tab1);
//         free(tab2);
//         return 1;
//     };
//     tab2 = temp;


//     for (int i = n; i < 2 * n; ++i) {
//         if (scanf("%d", &tab2[i]) != 1) {
//             free(tab1);
//             free(tab2);
//             return 1;
//         }
//     }

//     for (int i = 0; i < 2 * n; ++i) {
//         printf("%d ", tab2[i]);
//     }
//     printf("\n");

//     free(tab1);
//     free(tab2);

//     return 1;
// }


int main() {
    int n, m;

    if (scanf("%d", &n) != 1 || n <= 0)return 1;


    int *tab1 = malloc(n * sizeof * tab1);
    if (tab1 == NULL)return 1;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab1[i]) != 1) {
            free(tab1);
            return 1;
        }
    }


    if (scanf("%d", &m) != 1 || m <= 0)return 1;
    int *tab2 = malloc(m * sizeof * tab2);
    if (tab2 == NULL)return 1;

    for (int i = 0; i < m; ++i) {
        if (scanf("%d", &tab2[i]) != 1) {
            free(tab1);
            free(tab2);
            return 1;
        }
    }

    int *tab3 = malloc((m + n) * sizeof * tab3);

    if (tab3 == NULL) {
        free(tab1);
        free(tab2);
        free(tab3);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        tab3[i] = tab1[i];
    }
    for (int i = 0; i < m; ++i) {
        tab3[n + i] = tab1[i];
    }
    printf("\ntab1 :");
    for (int i = 0; i < n + m; ++i) {
        printf("%d ", tab1[i]);
    }
    printf("\ntab2 :");
    for (int i = 0; i < n + m; ++i) {
        printf("%d ", tab2[i]);
    }
    printf("\ntab3 :");

    for (int i = 0; i < n + m; ++i) {
        printf("%d ", tab3[i]);
    }

    printf("\n");
    free(tab1);
    free(tab2);
    free(tab3);

    return 0;
}
