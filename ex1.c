// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>


// bool est_palindrome(const char *mot) {
//     if (mot == NULL) return false;

//     int gauche = 0;
//     int droite = strlen(mot) - 1;

//     while (gauche < droite) {
//         if (tolower((unsigned char)mot[gauche]) != tolower((unsigned char)mot[droite])) {
//             return false;
//         }
//         gauche++;
//         droite--;
//     }

//     return true;
// }


// int main() {
//     char mot[100];
//     printf("[?] Saisir un mot (que des lettres dans [a-z,A-Z]");

//     if (scanf("%99s", mot) == 1) {
//         if (est_palindrome(mot)) {
//             printf("[i] %s est un palindrome\n", mot);
//         } else {
//             printf("[i] %s n'est pas un palindrome\n", mot);
//         }

//     } else {
//         printf("Erreur de lecture\n");
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIGNE 256

// int lire_ligne(char *tampon, int max_len) {
//     int i = 0;
//     int c;

//     while ((c = getchar()) != '\n' && c != EOF) {
//         if (i < max_len - 1) {
//             tampon[i++] = (char)c;
//         } else {
//             while ((c = getchar()) != '\n' && c != EOF);
//             return -2;
//         }
//     }

//     tampon[i] = '\0';


//     if (c == EOF && i == 0) {
//         return -1;
//     }

//     return i;
// }

// bool verifier_parentheses(const char *ligne) {
//     int compteur = 0;
//     for (int i = 0; ligne[i] != '\0'; ++i) {
//         if (ligne[i] == '(') {
//             compteur++;
//         } else if (ligne[i] == ')') {
//             compteur--;

//             if (compteur < 0) {
//                 return false;
//             }
//         }
//     }
//     return (compteur == 0);
// }

// int main() {
//     char ligne[MAX_LIGNE];
//     printf("[?] Saisissez une ligne de mots et parentheses: ");

//     // int status = lire_ligne(ligne, MAX_LIGNE);
//     // if (status == -2) {
//     //     printf("[!] Erreur : La ligne saisie depasse la capacite maximale (%d caracteres).\n", MAX_LIGNE);
//     //     return 1;
//     // } else if (status == -1) {
//     //     printf("[!] Erreur de lecture.\n");
//     //     return 1;
//     // }

//     if (verifier_parentheses(ligne)) {
//         printf("[i] Les parentheses sont correctes\n");
//     } else {
//         printf("[i] Il manque des parentheses :(\n");
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdbool.h>

// #define MAX_UZUNLUK 256

// int lire_ligne

// #include <stdio.h>
// #define MAX_LIGNE 256

// int main() {
//     char ligne[MAX_LIGNE];
//     char sous_chaine[MAX_LIGNE];
//     printf("[?] Saisissez une ligne de mots: ");

//     if (fgets(ligne, MAX_LIGNE, stdin) == NULL) {
//         printf("[!] erreur de lecture.\n");
//         return 1;
//     }

//     int longuer = 0;
//     while (ligne[longuer] != '\0') {
//         if (ligne[longuer] == '\n') {
//             ligne[longuer] = '\0';
//             break;
//         }
//         ++longuer;
//     }

//     if (longuer == 0) {
//         printf("[!] Erreur: La ligne est vide!\n");
//         return 1;
//     }

//     printf("[i] la ligne contient %d caracteres.\n", longuer);


//     int pos;
//     printf("[?] Extraire APRES combien de caracteres? ");
//     if (scanf("%d", &pos) != 1 || pos < 0 || pos >= longuer) {
//         printf("[i] Erreur : position impossible !\n");
//         return 1;
//     }

//     int len;
//     printf("[?] Extraire combien de caracteres?");

//     if (scanf("%d", &len) != 1 || len <= 0) {
//         printf("[!] Erreur: longueur impossible!\n");
//         return 1;
//     }

//     int i = 0;

//     while (i < len && ligne[pos + i] != '\0') {
//         sous_chaine[i] = ligne[pos + i];

//         ++i;
//         sous_chaine[i] = '\0';

//         printf("[i] La sous-chaine extraite de la chaine est : \"%s\"\n", sous_chaine);

//         return 0;
//     }

// }


// #include <stdio.h>

// #define MAX_LIGNE 256

// int main() {
//     char ligne[MAX_LIGNE];
//     char sous_chaine[MAX_LIGNE];

//     int pos, len;
//     int length = 0;

//     printf("[?] Saisissez une ligne de mots: ");
//     if (fgets(ligne, MAX_LIGNE, stdin) == NULL) {
//         return 1;
//     }

//     while (ligne[length] != '\0') {
//         if (ligne[length] == '\n') {
//             ligne[length] = '\0';
//             break;
//         }
//         ++length;
//     }

//     if (length == 0) {
//         printf("[!] Erreur: Ligne vide refusee.\n");
//         return 1;
//     }

//     printf("[i] La ligne contient %d caracteres.\n", length);
//     printf("[?] Extraire APRES combien de caracteres? ");
//     if (scanf("%d", &pos) != 1 || pos < 0 || pos >= length) {
//         printf("[!]Erreur: position impossible!\n");
//         return 1;
//     }

//     printf("[?] Extraire combien de caracteres? ");

//     if (scanf("%d", &len) != 1 || len <= 0 || (pos + len) > length) {
//         printf("[!] Erreur: longueur impossible!\n");
//         return 1;
//     }

//     int i;
//     for (i = 0; i < len; ++i) {
//         sous_chaine[i] = ligne[pos + i];
//     }
//     sous_chaine[i] = '\0';

//     printf("[i] La sous-chaîne extraite de la chaîne est : \"%s\"\n", sous_chaine);
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') ++len;

    return len;
}

bool isInteger(const char *str) {
    if (str == NULL || *str == '\0') return false;
    int i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    if (str[i] == '\0') return false;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i]>'9') {
            return false;
        }
        ++i;
    }
    return false;
}

void insChar(char *str, int pos, char c) {
    int len = my_strlen(str);

    for (int i = len; len >= pos; --i) {
        str[i + 1] = str[i];
    }

    str[pos] = c;
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer 1> <integer 2>\n", argv[0]);
        return 1;
    }

    // 2. Tip kontrolü
    if (!isInteger(argv[1]) || !isInteger(argv[2])) {
        // Hoca örneklerde bu durum için özel bir çıktı belirtmemiş,
        // ancak programın çökmesini engellemek için durduruyoruz.
        printf("[e] Les arguments doivent etre des entiers.\n");
        return 1;
    }

    errno = 0;
    long long a = strtoll(argv[1], NULL, 10);
    if (errno == ERANGE) {
        printf("[e] %s is to long", argv[1]);
        return 1;
    }
    errno = 0;
    long long b = strtoll(argv[2], NULL, 10);
    if (errno == ERANGE) {
        printf("[e] %s is to long", argv[2]);
        return 1;
    }

    long long result = a * b;
    if (a != 0 && result / a != b) {
        printf("[e] %lld * %lld is too long!\n", a, b);
        return 1;
    }

    long long temp = result;
    int digits = 0;

    do {
        digits++;
        temp / 10;
    }
    while (temp != 0);
    int is_neg = (result < 0) ? 1 : 0;
    int commas = (digits - 1) / 3;

    int total_chars = digits + is_neg + commas;

    char *res_str = (char *)malloc((total_chars + 1) * sizeof(char));
    if (res_str == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    sprintf(res_str, "%lld", result);

    int raw_len = digits + is_neg;
    int count = 0;

    for (int i = raw_len - 1; i > is_neg;i--) {
        count++;
        if (count % 3 == 0) {
            insChar(res_str, i, '\'');
        }
    }
    printf("[i] Result = %s\n", res_str);

    return 0;
}
