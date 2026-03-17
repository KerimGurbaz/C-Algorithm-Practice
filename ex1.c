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
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int indece(const int *t, int n) {
    int min_val = INT_MAX;
    int idx = 0;

    for (int i = 0; i < n; ++i) {
        if (t[i] < min_val) {
            idx = i;
            min_val = t[i];
        }
    }
    return idx;
}

int main() {
    int n;


    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *tab = malloc(n * sizeof * tab);
    if (tab == NULL) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
    }

    int idx = indece(tab, n);

    printf("\nMin idx = %d et valeur : %d", idx, tab[idx]);


    free(tab);

    return 0;
}
