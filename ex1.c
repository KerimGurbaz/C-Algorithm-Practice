#include <stdio.h>



// void fibo(int n);
// int main() {
//     int count = 0;
//     int n;
//     printf("Entrez un value\n");
//     if (scanf("%d", &n) != 1) return 1;
//     fibo(n);
//     printf("\n");

//     return 0;
// }

// void fibo(int n) {
//     int premier = 0;
//     int seconde = 1;

//     if (n >= 1) printf("%d ", premier);
//     if (n >= 2)printf("%d ", seconde);

//     for (int i = 3; i <= n; ++i) {
//         int suivant = premier + seconde;
//         printf("%d ", suivant);
//         premier = seconde;
//         seconde = suivant;
//     }
// }

// void trouver_min_max(const int tab[], int size, int *mn, int *mx) {
//     for (int i = 1; i < size;++i) {
//         if (tab[i] > *mx) {
//             *mx = tab[i];
//         }
//         if (tab[i] < *mn) {
//             *mn = tab[i];
//         }
//     }
// }


// int main() {

//     int tab[] = { 12, 5, 8, 19, 1, 7 };
//     int size = sizeof(tab) / sizeof(tab[0]);
//     int minVal = tab[0];
//     int maxVal = tab[0];

//     trouver_min_max(tab, size, &minVal, &maxVal);
//     printf("min_value = %d \n", minVal);
//     printf("max_value = %d \n", maxVal);

//     return 0;
// }

// void supprimer_espaces(char *str) {
//     char *p_left = str;
//     char *p_right = str;

//     while (*p_right != '\0') {

//         if (*p_right != ' ') {
//             *p_left = *p_right;
//             p_left++;
//             p_right++;
//         } else {
//             p_right++;
//         }

//     }
//     *p_left = '\0';

// }

// int main() {
//     char str[] = "Programmation en C";
//     printf("%s\n", str);
//     supprimer_espaces(str);
//     printf("%s\n", str);
//     return 0;
// }

#include <stdlib.h>

int main() {
    int n = 0;
    int capacty = 2;
    int valeur;

    int *tab = malloc(capacty * sizeof(int));
    if (tab == NULL) {
        fprintf(stderr, "Erreur allocation memoire");
        return 1;
    }
    printf("Entrez des nombres positifs (négatif pour arrêter):\n");
    while (1) {
        printf("  Nombre %d: ", n + 1);
        if (scanf("%d", &valeur) != 1) {
            printf("Entrée invalide, ignorée.\n");
            while (getchar() != '\n');
            continue;
        }
        if (valeur < 0) {
            printf("Nombre négatif détecté, arrêt de la saisie.\n");
            break;
        }

        if (n >= capacty) {
            capacty *= 2;
            int *temp = realloc(tab, capacty * sizeof(int));
            if (temp == NULL) {
                fprintf(stderr, "Erreur de reallocation memoire\n");
                free(tab);
                return 1;
            }
            tab = temp;
        }
        tab[n++] = valeur;
    }

    printf("\n=== RÉSULTATS ===\n");
    printf("Nombre d'éléments: %d\n", n);
    printf("Capacité finale: %d\n", capacty);
    printf("Contenu du tableau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);



    return 0;
}
