#include <stdio.h>
#include <stdint.h>

// #define LECTURE (1<<0)
// #define ECRITURE (1<<1)
// #define EXECUTION (1<<2)
// #define ADMIN (1<<3)


// void afficher_binaire(uint8_t octet) {
//     for (int i = 7; i >= 0; --i) {
//         printf("%d", (octet >> i) & 1);
//     }
//     printf("\n");
// }

// int main() {


//     uint8_t droits = 0;

//     printf("---Gestion DES Droit d'acces--\n\n");

//     droits = LECTURE | ECRITURE;
//     printf("1. ajout Lectre et Ecriture [L | E] : ");
//     afficher_binaire(droits);

//     droits |= EXECUTION;
//     printf("2. Ajout Execution (L|E|X)  : ");
//     afficher_binaire(droits);

//     printf("\n--VERIFICATION--\n");
//     if (droits & ECRITURE) {
//         printf("[OK] le droit d'ECRITURE est present.\n");
//     }
//     if (!(droits & ADMIN)) {
//         printf("[NO] le lecture d'ADMIN n'est pas present.\n");
//     }


//     droits &= ~ECRITURE;
//     printf("\n3. Retrait de l'ecriture (L|X)    : ");
//     afficher_binaire(droits);

//     return 0;
// }



// #define LECTURE (1<<0)
// #define ECRITURE (1<<1)
// #define EXECUTION (1<<2)
// #define ADMIN (1<<3)


// void afficher_binaire(uint8_t octet) {
//     for (int i = 7; i >= 0; --i) {
//         printf("%d", (octet >> i) & 1);
//     }
//     printf("\n");
// }

// int main() {
//     uint8_t droits = 0;
//     printf("---Gestion DES Droit d'acces--\n\n");

//     droits = LECTURE | ECRITURE;

//     printf("1. ajout Lectre et Ecriture [L | E] : ");
//     afficher_binaire(droits);

//     droits |= EXECUTION;
//     printf("2.Ajout EXECUTION : ");
//     afficher_binaire(droits);

//     printf("\n--- VERIFICATION ---\n");

//     if (droits & ECRITURE) {
//         printf("ok\n");
//     }
//     if (!(droits & ADMIN)) {
//         printf("no\n");
//     }

//     droits &= ~ECRITURE;
//     printf("Retrait de l'ecriture : ");
//     afficher_binaire(droits);

//     return 0;

// }

// #include <stdio.h>
// #include <stdint.h>

// #define PERM_EXEC 0x01
// #define PERM_WRITE 0x02
// #define PERM_READ 0x04

// //Foction utilitaire pour verifier l'etat des bits

// void affciher_droits(uint8_t droits) {
//     printf("Lecture : %s\n", (droits & PERM_READ) ? "[X] AUTORISE" : "[ ] REFUSE");
//     printf("Ecriture :%s\n", (droits & PERM_WRITE) ? "[X] AUTORISE" : "[ ] REFUSE");
//     printf("Execution : %s\n", (droits & PERM_EXEC) ? "[X] AUTORISE" : "[ ] REFUSE");
//     printf("-> valeur memoire : %d (Hex: 0x%02X)\n\n", droits, droits);
// }

// int main() {
//     uint8_t droits = 0x00;
//     printf("ETAPE 1: Fichier nouvellement cree---\n");
//     affciher_droits(droits);

//     printf("ETAPE 2: Ajout du droit de LECTURE\n");
//     droits |= PERM_READ;
//     affciher_droits(droits);

//     printf("ETAPE 3 : Ajout ECRITURE et EXECUTION d'un coup\n");
//     droits |= (PERM_WRITE | PERM_EXEC);
//     affciher_droits(droits);

//     printf("ETAPE 4 : Retrait du droit d'ecriture\n");
//     droits &= ~PERM_WRITE;
//     affciher_droits(droits);


//     return 0;

// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <time.h>
// #include <unistd.h>

// #define CLIGNOTEMENTS 20

// void afficher(uint8_t etat) {
//     printf("\r");

//     for (int i = 7; i >= 0; --i) {
//         if ((etat >> i) & 1) {
//             printf("*");
//         } else {
//             printf("-");
//         }
//     }

//     fflush(stdout);
// }
// int main() {
//     srand(time(NULL));

//     uint8_t guirlande = 0xAA;

//     printf("simulation de la guirlande en cours...\n");

//     for (int i = 0; i < CLIGNOTEMENTS; ++i) {
//         afficher(guirlande);

//         int delai = (rand() % 900001) + 100000;
//         usleep(delai);

//         guirlande = ~guirlande;
//     }
//     printf("\nTermine.\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#define CLIOGNOTEMENTS 20

void afficher_guirlande(uint8_t etat) {
    printf("\r");

    for (int i = 7; i >= 0; --i) {
        if ((etat >> i) & 1) {
            printf("*");
        } else {
            printf("-");
        }
    }
    fflush(stdout);
}

int main() {
    srand(time(NULL));
    uint8_t guirlande = 0xAA;

    printf("Simulation de la guirlande (%d clignotements) : \n\n", CLIOGNOTEMENTS);

    for (int i = 0; i < CLIOGNOTEMENTS; ++i) {
        afficher_guirlande(guirlande);

        int min_us = 100000;
        int max_us = 1000000;
        int delai = min_us + (rand() % (max_us - min_us + 1));

        usleep(delai);

        guirlande = ~guirlande;
    }
    printf("\n\nJoyeuses FETES!\n");

    return 0;
}
