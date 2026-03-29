// // #include <stdio.h>
// // #include <stdlib.h>

// // int **transpoze(int **m, int lignes, int colonnes) {
// //     if (m == NULL || lignes <= 0 || colonnes <= 0) {
// //         return NULL;
// //     }

// //     int **temp = calloc(colonnes, sizeof(int *));
// //     if (temp == NULL) {
// //         return NULL;
// //     };

// //     for (int i = 0; i < colonnes; ++i) {
// //         temp[i] = malloc(lignes * sizeof(int));
// //         if (temp[i] == NULL) {
// //             for (int k = 0; k < i; ++k) {
// //                 free(temp[k]);
// //             }
// //             free(temp);

// //             return NULL;
// //         }

// //     }

// //     for (int i = 0; i < lignes;++i) {
// //         for (int j = 0; j < colonnes; ++j) {
// //             temp[j][i] = m[i][j];
// //         }
// //     }

// //     return temp;
// // }
// // void libere(int **m, int l) {
// //     if (m == NULL) return;
// //     for (int i = 0; i < l; ++i) {
// //         free(m[i]);
// //     }
// //     free(m);
// // }

// // void display(int **m, int l, int c) {
// //     for (int i = 0; i < l; ++i) {
// //         printf("[");
// //         for (int j = 0; j < c; ++j) {
// //             printf("%3d", m[i][j]);
// //         }
// //         printf("]\n");
// //     }
// //     printf("\n");
// // }

// // int main() {

// //     int lignes;
// //     int colonnes;

// //     if (scanf("%d %d", &lignes, &colonnes) != 2 || lignes <= 0 || colonnes <= 0) {
// //         printf("Erreur de saisie.\n");
// //         return 1;
// //     }

// //     int **matric = calloc(lignes, sizeof(int *));
// //     if (matric == NULL) {
// //         return 1;
// //     }

// //     for (int i = 0; i < lignes; ++i) {
// //         matric[i] = malloc(colonnes * sizeof(int));
// //         if (matric[i] == NULL) {
// //             libere(matric, i);
// //             return 1;
// //         }
// //     }

// //     for (int i = 0; i < lignes; ++i) {
// //         for (int j = 0; j < colonnes;++j) {
// //             matric[i][j] = (i + 1) * 10 + (j + 1);
// //         }
// //     }
// //     printf("Matrice Originale (%dx%d) :\n", lignes, colonnes);
// //     display(matric, lignes, colonnes);

// //     int **matric_T = transpoze(matric, lignes, colonnes);
// //     display(matric_T, lignes, colonnes);


// //     libere(matric, lignes);
// //     libere(matric_T, colonnes);

// //     return 0;
// // }
// // #include <stdlib.h>
// // #include <stdio.h>

// // #define LIGNES 5
// // #define COLONNES 5

// // int *sommeLignes(int **m, int l, int c) {
// //     if (m == NULL || l <= 0 || c <= 0)return NULL;
// //     int *tab = malloc(LIGNES * sizeof(int));
// //     if (tab == NULL) {
// //         return NULL;
// //     }
// //     for (int i = 0; i < LIGNES; ++i) {
// //         int total = 0;
// //         for (int j = 0; j < COLONNES; ++j) {
// //             total += m[i][j];
// //         }
// //         tab[i] = total;
// //     }
// //     return tab;
// // };

// // void libere(int **m, int l) {
// //     if (m == NULL) return;
// //     for (int i = 0; i < l; ++i) {
// //         free(m[i]);
// //     }
// //     free(m);
// // };
// // void display(int **m, int l, int c) {

// //     for (int i = 0; i < LIGNES; ++i) {
// //         for (int j = 0; j < COLONNES; ++j) {
// //             printf("%3d", m[i][j]);
// //         }
// //         printf("\n");
// //     }
// //     printf("\n");
// // };

// // int main() {

// //     int **matrice = calloc(LIGNES, sizeof(int *));
// //     if (matrice == NULL) {
// //         libere(matrice, LIGNES);
// //         return 1;
// //     }
// //     for (int i = 0; i < LIGNES; ++i) {
// //         matrice[i] = malloc(COLONNES * sizeof(int));
// //         if (matrice[i] == NULL) {
// //             libere(matrice, i);
// //             return 1;
// //         }
// //     }

// //     for (int i = 0; i < LIGNES; ++i) {
// //         for (int j = 0; j < COLONNES; ++j) {
// //             matrice[i][j] = (i + 1) + (j + 1);
// //         }
// //     }

// //     int *somme = sommeLignes(matrice, LIGNES, COLONNES);

// //     display(matrice, LIGNES, COLONNES);

// //     for (int i = 0;i < LIGNES; ++i) {
// //         printf("%2d ", somme[i]);
// //     }
// //     printf("\n");

// //     free(matrice);
// //     free(somme);


// //     return 0;
// // }

// // #include <stdlib.h>
// // #include <stdio.h>
// // void Identity(int **m, int lignes) {
// //     if (m == NULL || lignes <= 0) return;
// //     for (int i = 0; i < lignes; ++i) {
// //         for (int j = 0; j < lignes; ++j) {
// //             if (i == j) {
// //                 m[i][j] = 1;
// //             } else {
// //                 m[i][j] = 0;
// //             }
// //         }
// //     }
// // }

// // void libere(int **m, int l) {
// //     if (m == NULL)return;
// //     for (int i = 0; i < l;++i) {
// //         free(m[i]);
// //     }
// //     free(m);
// // }

// // void display(int **m, int l) {

// //     for (int i = 0; i < l; ++i) {
// //         printf("[");
// //         for (int j = 0; j < l; ++j) {
// //             printf("%2d ", m[i][j]);
// //         }
// //         printf("]\n");
// //     }
// //     printf("\n");
// // }
// // int main() {
// //     int N;
// //     if (scanf("%d", &N) != 1 || N <= 0) {
// //         int c;
// //         while ((c = getchar()) != '\n' || c != EOF);
// //         return 1;
// //     }

// //     int **matrice = calloc(N, sizeof(int *));
// //     if (matrice == NULL) {
// //         return 1;
// //     }

// //     for (int i = 0; i < N; ++i) {
// //         matrice[i] = malloc(N * sizeof(int));
// //         if (matrice[i] == NULL) {
// //             libere(matrice, i);
// //         }
// //     }

// //     int **identityMatrice = Identity(matrice, N);

// //     display(identityMatrice, N);
// //     libere(identityMatrice, N);
// //     libere(matrice, N);



// //     return 0;
// // }

// #include <stdio.h>

// int main() {
//     char bloc_memoire[] = "Pazartesi\0Sali\0Carsamba\0Persembe\0Cuma\0Cumartesi\0Pazar";

//     char *jours[7];

//     int idx_jour = 0;
//     jours[idx_jour++] = &bloc_memoire[0];

//     size_t taille = sizeof(bloc_memoire);

//     for (int i = 0; i < taille - 1; ++i) {
//         if (bloc_memoire[i] == '\0') {
//             if (idx_jour < 7) {
//                 jours[idx_jour] = &bloc_memoire[i + 1];
//                 ++idx_jour;
//             }
//         }
//     }

//     printf("Les jours de la semaine :\n");
//     for (int i = 0; i < 7; ++i) {
//         printf("Jour %d : %s\n", i + 1, jours[i]);
//     };

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>


// int sommeIdx(int *t, int *p, int taille) {
//     int *begin = p + 1;
//     int *end = p + taille - 1;
//     int total = 0;
//     printf("%d -> %d ", *begin, *end);
//     while (begin <= end) {
//         printf("%d ", *begin);
//         total += *begin;
//         begin += 2;
//     }

//     return total;
// }
// int main() {

//     int tab[] = { 10, 20, 30, 40, 50 };
//     int *p = tab;
//     int taille = sizeof(tab) / sizeof(tab[0]);

//     int somme = sommeIdx(tab, p, taille);


//     printf("total : %d ", somme);

//     return 0;
// }
// #include <stdio.h>

// int filtrer_negatifs(int *p, int taille) {
//     if (p == NULL || taille <= 0) return 0;

//     int *read = p;
//     int *write = p;

//     const int *fin = p + taille;


//     while (read < fin) {
//         if (*read >= 0) {
//             *write = *read;
//             ++write;
//         }
//         ++read;
//     }

//     return (int)(write - p);
// }

// void afficher_pointeurs(const int *p, int taille) {
//     const int *fin = p + taille;
//     printf("[");
//     while (p < fin) {
//         printf("%d ", *p);
//         ++p;
//     }
//     printf("]\n");
// }


// int main(void) {
//     int donnees[] = { 10, -5, 20, -3, 30, -99, 40 };
//     int taille_initiale = sizeof(donnees) / sizeof(donnees[0]);

//     printf("Avant le filtrage (%d elements) : \n", taille_initiale);
//     afficher_pointeurs(donnees, taille_initiale);

//     // Appel de la fonction in-place
//     int nouvelle_taille = filtrer_negatifs(donnees, taille_initiale);

//     printf("\nApres le filtrage (%d elements valides) : \n", nouvelle_taille);
//     // DİKKAT: Artık sadece yeni boyut kadar ekrana basıyoruz
//     afficher_pointeurs(donnees, nouvelle_taille);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// void libere(int **m, int l) {
//     if (m == NULL) return;
//     for (int i = 0; i < l; ++i) {
//         free(*(m + i));
//     }
//     free(m);
// }

// int calculer_trace(int **m, int taille) {
//     if (m == NULL || taille <= 0) return 0;

//     int trace = 0;

//     for (int i = 0; i < taille; ++i) {

//         trace += *(*(m + i) + i);
//     }
//     return trace;
// }

// int main() {
//     int N = 3;

//     int **matrice = calloc(N, sizeof(int *));
//     if (matrice == NULL) return 1;


//     for (int i = 0; i < N; ++i) {
//         *(matrice + i) = malloc(N * sizeof(int));
//         if (*(matrice + i) == NULL) {
//             libere(matrice, i);
//             return 1;
//         }
//     }

//     int compteur = 1;

//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             *(*(matrice + i) + j) = compteur++;
//         }
//     }

//     int resultat = calculer_trace(matrice, N);

//     printf("La trace de la matrice est : %d\n", resultat);

//     libere(matrice, N);

//     return 0;

// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <stdbool.h>
// #include <string.h>


// bool palindrome_mu(const char *mot) {
//     if (mot == NULL) return false;

//     int taille = strlen(mot);

//     const char *begin = mot;

//     const char *end = mot + taille - 1;


//     while (begin < end) {
//         if (tolower(*begin) != tolower(*end)) {
//             return false;
//         }
//         ++begin;
//         --end;
//     }
//     return true;
// }

// int main() {

//     char mot[50];
//     int status;

//     printf("Enterz un mot :");

//     do {
//         status = scanf("%49s", mot);
//         if (status != 1) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//             printf("Erreur. Reessayez : ");
//         }

//     }
//     while (status != 1);

//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);


//     printf("\nLe mot '%s' %s un  palindrome.\n", mot, palindrome_mu(mot) ? "EST" : "N'EST PAS");
//     return 0;
// }
// #include <stdbool.h>
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>


// bool phrase_palindrome(const char *mot) {
//     if (mot == NULL) return false;

//     int taille = strlen(mot);
//     if (taille == 0)return true;

//     const char *begin = mot;
//     const char *end = mot + taille - 1;

//     while (begin < end) {
//         while (begin < end && !isalnum(*begin)) {
//             ++begin;
//         }
//         while (begin < end && !isalnum(*end)) {
//             --end;
//         }
//         if (begin < end) {
//             if (tolower(*begin) != tolower(*end)) {
//                 return false;
//             }
//             ++begin;
//             --end;
//         }

//     }
//     return true;

// }

// int main(void) {

//     // Statik test cümleleri
//     const char *test1 = "Engage le jeu que je le gagne";
//     const char *test2 = "A l'etape, epate-la";
//     const char *test3 = "HEIG-VD est genial"; // Palindrom değil

//     printf("Test 1 : [%s] -> %s\n", test1, phrase_palindrome(test1) ? "PALINDROME" : "NON");
//     printf("Test 2 : [%s] -> %s\n", test2, phrase_palindrome(test2) ? "PALINDROME" : "NON");
//     printf("Test 3 : [%s] -> %s\n", test3, phrase_palindrome(test3) ? "PALINDROME" : "NON");

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h> 
// #include <string.h>

// char *kopyala(const char *phrase) {
//     if (phrase == NULL) NULL;

//     size_t longueur = strlen(phrase);

//     char *copie = malloc((longueur + 1) * sizeof(char));
//     if (copie == NULL) return NULL;
//     int i;
//     for (i = 0; i < longueur; ++i) {
//         copie[i] = phrase[i];
//     }
//     copie[i] = '\0';

//     return copie;
// }

// int main() {

//     const char *text_orj = "Ingenierie des donnees";

//     char *texte_clone = kopyala(text_orj);

//     if (texte_clone != NULL) {
//         printf("Original : %s\n", text_orj);
//         printf("Clone    : %s\n", texte_clone);

//         texte_clone[0] = 'i';
//         printf("Clone modifie : %s\n", texte_clone);

//         free(texte_clone);

//     } else {
//         printf("Erreur d'allocation memoire.\n");
//     }



//     return 0;
// }

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// char *concatener_dynamique(const char *s1, const char *s2) {
//     if (s1 == NULL || s2 == NULL) return NULL;

//     int len1 = strlen(s1);
//     int len2 = strlen(s2);

//     char *resultat = malloc((len1 + len2 + 1) * sizeof(char));
//     if (resultat == NULL) return NULL;

//     int i, j;
//     for (i = 0; i < len1;++i) {
//         resultat[i] = s1[i];
//     }
//     for (j = 0; j < len2;++j) {
//         resultat[i + j] = s2[j];
//     }

//     resultat[i + j] = '\0';

//     return resultat;
// }

// int main() {

//     const char *mot1 = "DATA ";
//     const char *mot2 = "ENGINEERING";
//     char *phraseComplete = concatener_dynamique(mot1, mot2);

//     if (phraseComplete != NULL) {
//         printf("resultat : %s\n", phraseComplete);
//         free(phraseComplete);
//     }
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <ctype.h>

// bool est_phrase_palindrome(const char *ph) {
//     if (ph == NULL)return false;
//     if (*ph == '\n') return true;
//     const char *p = ph;
//     while (*p != '\0') {
//         ++p;
//     }
//     const char *fin = p - 1;
//     const  char *debut = ph;

//     while (debut < fin) {
//         while (debut < fin && !isalnum(*debut))++debut;
//         while (debut < fin && !isalnum(*fin))--fin;
//         if (debut < fin && tolower(*debut) != tolower(*fin)) {
//             return false;
//         }
//         ++debut;
//         --fin;
//     }

//     return true;
// }

// int main() {
//     const char *test1 = "ey edip adanada pide ye"; // İçinde boşluklar var
//     const char *test2 = "tu l as trop ecrase cesar le port salut"; // Fransızca klasik palindrom
//     const char *test3 = "ingenierie des donnees";

//     printf("Test 1 : %s\n", est_phrase_palindrome(test1) ? "VRAI" : "FAUX");
//     printf("Test 2 : %s\n", est_phrase_palindrome(test2) ? "VRAI" : "FAUX");
//     printf("Test 3 : %s\n", est_phrase_palindrome(test3) ? "VRAI" : "FAUX");

//     return 0;
// }
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
    }
    return c;
}


bool est_palindrome_complet(const char *ph) {
    if (ph == NULL) return false;
    const char *p = ph;

    if (*p == '\0') return true;

    while (*p != '\0')++p;
    const char *debut = ph;
    const char *fin = p - 1;

    while (debut < fin) {
        while (debut < fin && !isalnum(*debut))++debut;
        while (debut < fin && !isalnum(*fin))--fin;
        if (toLower(*debut) != toLower(*fin)) {
            return false;
        }
        ++debut;
        --fin;
    }

    return true;
}


int main(void) {
    // Virgül, apostrof, ünlem ve boşluk içeren kompleks bir palindrom
    const char *phrase_complexe = "A l'etape, epate-la !";

    if (est_palindrome_complet(phrase_complexe)) {
        printf("La phrase \"%s\" EST un palindrome parfait.\n", phrase_complexe);
    } else {
        printf("NON palindrome.\n");
    }

    return 0;
}
