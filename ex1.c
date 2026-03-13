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


int main() {

    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *tab = malloc(n * sizeof * tab);
    if (tab == NULL) return 1;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i] != 1)) {
            free(tab);
            return 1;
        }
    }

    int k;
    if (scanf("%d", &k) != 1 || k < 0 || k >= n) {
        free(tab);
        return 1;
    }

    for (int i = k; i < n - 1; ++i) {
        tab[i] = tab[i + 1];
    }

    int *temp = realloc(tab, (n - 1) * sizeof * tab);
    if (temp != NULL) {
        tab = temp;
    }

    for (int i = 0;i < n - 1; ++i) {
        printf("%d", tab[i]);
    }
    printf("\n");

    free(tab);


    return 0;
}
