
// #include <stdio.h>

// int somme(int num) {
//     if (num <= 0) {
//         return 0;
//     }

//     int total = 0;
//     int temp = num;

//     do {
//         total += temp % 10;
//         temp /= 10;

//     }
//     while (temp > 0);

//     return total;
// }

// int main() {
//     int number;
//     int status;

//     printf("Entrez un nombre positif : ");
//     do {
//         status = scanf("%d", &number);
//         if (status != 1 || number <= 0) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//             printf("Erreur. ");
//         }

//     }
//     while (status != 1 || number <= 0);

//     int res = somme(number);
//     printf("La somme : %d\n", res);

//     return 0;

// }

// #include <stdio.h>
// #include <stdlib.h>
// void inverser_chaine(char *str, int idx) {
//     int debut = 0;
//     int fin = idx - 1;

//     while (debut < fin) {
//         char temp = str[debut];
//         str[debut] = str[fin];
//         str[fin] = temp;
//         ++debut;
//         --fin;
//     }
// }

// char *entier_vers_binaire(unsigned int valeur) {
//     int capacite_max = 33;
//     char *buffer_temp = malloc(capacite_max * sizeof(char));
//     if (buffer_temp == NULL) return NULL;


//     unsigned int temp = valeur;

//     int index = 0;

//     do {
//         buffer_temp[index] = (temp % 2) + '0';
//         ++index;
//         temp /= 2;

//     }
//     while (temp > 0);
//     buffer_temp[index] = '\0';

//     inverser_chaine(buffer_temp, index);

//     char *resultat_final = realloc(buffer_temp, (index + 1) * sizeof(char));
//     if (resultat_final != NULL) {
//         return resultat_final;
//     }

//     return buffer_temp;

// }

// int main() {
//     unsigned int valeur;
//     int status;

//     do {
//         printf("enterz un entier positif\n");
//         status = scanf("%d", &valeur);
//         if (status != 1) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF) {

//             }
//         }

//     }
//     while (status != 1);

//     char *binaire_str = entier_vers_binaire(valeur);

//     if (binaire_str == NULL) {
//         printf("Erreur critique d'allocation memoire.\n");
//         return 1;
//     }

//     printf("Le nombre %u en binaire est : %s\n", valeur, binaire_str);

//     free(binaire_str);


//     return 0;
// }

// int longeur(const int number) {
//     int temp = number;
//     int counter = 0;

//     do {
//         temp /= 10;
//         ++counter;

//     }
//     while (temp != 0);

//     return counter;
// }

// int main() {
//     int number;
//     int status;

//     do {
//         status = scanf("%d", &number);
//         if (status != 1) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//         }

//     }
//     while (status != 1);

//     int result = longeur(number);
//     printf(" %d sayisi -> %d basamaklidir\n", number, result);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <ctype.h>
// #include <string.h>

// int *decouper(int nombre, int *taille) {
//     long long temp = nombre;
//     if (temp < 0) {
//         temp = -temp;
//     }

//     int count = 0;

//     do {
//         temp /= 10;
//         ++count;
//     }
//     while (temp != 0);

//     *taille = count;

//     int *tableau = malloc(count * sizeof(int));
//     if (tableau == NULL) return NULL;

//     for (int i = count - 1; i >= 0; --i) {
//         tableau[i] = nombre % 10;
//         nombre /= 10;
//     }
//     return tableau;
// }
// int main() {
//     int valuer;
//     int status;

//     do {
//         printf("Entrez un nombre entier : ");
//         status = scanf("%d", &valuer);
//         if (status != 1) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//         }
//     }
//     while (status != 1);
//     int taille;

//     int *chiffre = decouper(valuer, &taille);
//     if (chiffre == NULL) {
//         printf("Erreur d'allocation memoire.\n");
//         return 1;
//     }

//     printf("Les %d chiffres du nombre %d sont : [ ", taille, valuer);
//     for (int i = 0; i < taille; i++) {
//         printf("%d ", chiffre[i]);
//     }
//     printf("]\n");

//     free(chiffre);


//     return 0;
// }

// #include <stdio.h>
// #include <stdbool.h>

// bool palindrome(int n) {
//     if (n < 0)return false;
//     int temp = n;
//     long long inverse = 0;

//     do {
//         int der = temp % 10;
//         inverse = inverse * 10 + der;
//         temp /= 10;
//     }
//     while (temp != 0);

//     return inverse == n;
// }

// int main() {
//     int valeur;
//     int status;

//     printf("Entrez un entier positif : ");

//     do {
//         status = scanf("%d", &valeur);
//         if (status != 1 || valeur < 0) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//             printf("[!] Erreur. Entrez un entier positif valide :");
//         }

//     }
//     while (status != 1 || valeur < 0);

//     printf("%d sayisi -> %s\n", valeur, palindrome(valeur) ? "Palindrome" : "Non-Palindrome");

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// int *extraire(int nombre, int *taille) {
//     if (nombre < 0) nombre = -nombre;

//     int compteur = 0;

//     int temp = nombre;

//     do {
//         compteur++;
//         temp /= 10;

//     }
//     while (temp != 0);

//     *taille = compteur;

//     int *tab = malloc(compteur * sizeof(int));
//     if (tab == NULL) return NULL;

//     temp = nombre;

//     for (int i = compteur - 1; i >= 0; --i) {
//         tab[i] = temp % 10;
//         temp /= 10;
//     }
//     return tab;
// }

// bool est_symetrique(const int *tab, int taille) {
//     if (tab == NULL || taille <= 0) {
//         return false;
//     }
//     int gauche = 0;
//     int droite = taille - 1;

//     while (gauche < droite) {
//         if (tab[gauche] != tab[droite]) {
//             return false;
//         }
//         gauche++;
//         droite--;
//     }

//     return true;
// }



// int main() {
//     int valeur;
//     int status;


//     do {
//         printf("Entrez un nombre pour tester la symetrie : ");
//         status = scanf("%d", &valeur);
//         if (status != 1) {
//             printf("Saisie invalide.\n");
//             int c;
//         }

//     }
//     while (status != 1);

//     int taille_tab;

//     int *chiffres = extraire(valeur, &taille_tab);
//     if (chiffres == NULL) {
//         printf("Erreur d'allocation.\n");
//         return 1;
//     }

//     bool symetrique = est_symetrique(chiffres, taille_tab);

//     printf("Les chiffres du nombre palindrome ?  %s\n", symetrique ? "OUI" : "NON");

//     free(chiffres);


//     return 0;
// }

// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>

// bool est_matrice_symetrique(int **m, const int taille) {
//     if (m == NULL || taille <= 0) return false;

//     for (int i = 0; i < taille; ++i) {
//         for (int j = i + 1; j < taille; ++j) {
//             if (m[i][j] != m[j][i]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void liberer_matrice(int **m, int N) {
//     if (m == NULL) return;
//     for (int i = 0; i < N; ++i) {

//         if (m[i] != NULL) {
//             free(m[i]);
//         }
//     }
//     free(m);

// }

// int main() {
//     int N;

//     printf("Entrez la dimension N de la matrice carree (ex: 3 pour 3x3) : ");

//     if (scanf("%d", &N) != 1 || N <= 0) {
//         int c;
//         while ((c = getchar()) != 1 || N <= 0);
//         printf("Saisie invalide.\n");
//         return 1;
//     }

//     int **matrice = calloc(N, sizeof(int *));
//     if (matrice == NULL) {
//         return 1;
//     }

//     for (int i = 0; i < N; ++i) {
//         matrice[i] = malloc(N * sizeof(int));
//         liberer_matrice(matrice, N);
//         return 1;
//     }
//     printf("Entrez les %d valeurs de la matrice :\n", N * N);

//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             printf("Ligne %d, Colonne %d : ", i, j);
//             scanf("%d", &matrice[i][j]);
//         }
//     }
//     printf("\nVotre Matrice :\n");

//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             printf("%3d", matrice[i][j]);
//         }
//         printf("\n");
//     }

//     bool resultat = est_matrice_symetrique(matrice, N);

//     if (resultat) {
//         printf("\n[i] Cette matrice EST symetrique (A = A^T).\n");
//     } else {
//         printf("\n[i] Cette matrice N'EST PAS symetrique.\n");
//     }

//     liberer_matrice(matrice, N);


//     return 0;
// }
// #include <stdio.h>
// #define TAILLE 5

// void max_et_min(const int *tab, int taille, int *minVal, int *maxVal) {
//     if (tab == NULL || taille <= 0) return;
//     *minVal = tab[0];
//     *maxVal = tab[0];


//     for (int i = 1; i < taille; ++i) {
//         if (tab[i] > *maxVal) {
//             *maxVal = tab[i];
//         }
//         if (tab[i] < *minVal) {
//             *minVal = tab[i];
//         }
//     }
// }

// int main() {

//     int t[5] = { 1,2,3,4,5 };


//     int min_val;
//     int max_val;



//     max_et_min(t, TAILLE, &min_val, &max_val);

//     printf("max_val : %3d,  min_val : %2d\n", max_val, min_val);

//     return 0;
// }
// #include <stdlib.h>
// #include <stdio.h>



// double *normalise_donnees(const int *tab, int taille) {
//     if (tab == NULL || taille <= 0) return NULL;

//     int minVal = tab[0];
//     int maxVal = tab[0];
//     for (int i = 1; i < taille; ++i) {
//         if (tab[i] > maxVal) maxVal = tab[i];
//         if (tab[i] < minVal) minVal = tab[i];
//     }

//     double *temp = malloc(taille * sizeof(double));
//     if (temp == NULL) {
//         return NULL;
//     }

//     double diff = (double)(maxVal - minVal);

//     for (int i = 0; i < taille; ++i) {
//         if (diff == 0.0) {
//             temp[i] = diff;
//         } else {
//             temp[i] = (tab[i] - minVal) / diff;
//         }

//     }
//     return temp;
// }

// int second_max(const int *tab, int taille, int *erreur) {
//     if (tab == NULL || erreur == NULL || taille <= 1) return -1;
//     int maxVal = tab[0];
//     int secVal = tab[0];

//     for (int i = 0; i < taille;++i) {
//         if (tab[i] > maxVal) {
//             secVal = maxVal;
//             maxVal = tab[i];
//         }
//     }
//     return secVal;
// }

// int main() {

//     int dataset[] = { 10, 20, 30, 40, 50 };

//     int taille = sizeof(dataset) / sizeof(dataset[0]);
//     int erreur = 0;
//     int sec = second_max(dataset, taille, &erreur);
//     printf("SECOND-VAL : %d\n", sec);


//     printf("Original :");
//     for (int i = 0; i < taille; ++i) {
//         printf("%d ", dataset[i]);
//     }
//     printf("\n");

//     double *donne_normalisees = normalise_donnees(dataset, taille);
//     if (donne_normalisees == NULL) {
//         printf("Erreur...\n");
//         return 1;
//     }

//     printf("Dataset normalise : ");
//     for (int i = 0; i < taille; ++i) {
//         printf("%.2f ", donne_normalisees[i]);
//     }
//     printf("\n");


//     free(donne_normalisees);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

int diziler_esit_mi(int *t1, int *t2) {
    if (t1 == NULL || t2 == NULL) return -1;
    int *p1 = t1;
    int lenght1 = 0;
    int *p2 = t2;
    int lenght2 = 0;

    while (*p1 != '\0') {
        ++lenght1;
        ++p1;
    }
    while (*p2 != '\0') {
        ++lenght2;
        ++p2;
    }
    if (lenght1 != lenght2) {
        return 0;
    } else {
        for (int i = 0; i < lenght1; ++i) {
            if (t1[i] != t2[i]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {

    int t1[5] = { 1,2,3,4,5 };

    int t2[5] = { 1,2,3,4,5 };

    printf("diziler %s\n", diziler_esit_mi(t1, t2) ? "ESIT" : "ESIT-DEGIL");


    return 0;
}
