// #include <stdio.h>
// #include <stdint.h>

// #define LIRE  0x01
// #define ECRITURE  0x02
// #define EXECUTER  0x04


// #define USERS{"proprietaire", "groupe", "autres"}

// int main() {
//     uint16_t droitsAcces = 0x00;
//     char *users[] = USERS;

//     printf("Entrer un nombre entre 0 et 511 pour coder un accès Linux: ");
//     if ((scanf("%d", &droitsAcces) != 1) || (droitsAcces > 511)) {
//         printf("Desole...");
//         return 1;
//     }

//     printf("Droits d'accès après modification: 0x%X\n", droitsAcces);

//     int prop = (droitsAcces >> 6) & 0x07;
//     int groupe = (droitsAcces >> 3) & 0x07;
//     int autres = droitsAcces & 0x07;
// }
// #include <stdio.h>
// #include <stdint.h>


// int verifier_execution_globale(uint16_t droits) {
//     int prop_x = (droits >> 6) & 0x01;
//     int grp_x = (droits >> 3) & 0x01;
//     int aut_x = (droits) & 0x01;

//     return prop_x && grp_x && aut_x;
// }


// int main() {
//     printf("=== TEST verifier_execution_globale ===\n\n");

//     // Test 1: Hepsi x (111 111 111 = 511)
//     uint16_t d1 = 511;
//     printf("Test 1: 511 (rwx rwx rwx)\n");
//     printf("  Sonuc: %d (beklenen: 1)\n", verifier_execution_globale(d1));
//     printf("\n");

//     // Test 2: Sadece 2 tanesinde x var (111 111 110 = 510)
//     uint16_t d2 = 510;
//     printf("Test 2: 510 (rwx rwx rw-)\n");
//     printf("  Sonuc: %d (beklenen: 0)\n", verifier_execution_globale(d2));
//     printf("\n");

//     // Test 3: Hiç x yok (110 110 110 = 438)
//     uint16_t d3 = 438;
//     printf("Test 3: 438 (rw- rw- rw-)\n");
//     printf("  Sonuc: %d (beklenen: 0)\n", verifier_execution_globale(d3));
//     printf("\n");

//     // Test 4: Sadece autres'de x yok (111 111 001 = 505)
//     uint16_t d4 = 505;
//     printf("Test 4: 505 (rwx rwx --x)\n");
//     printf("  Sonuc: %d (beklenen: 0)\n", verifier_execution_globale(d4));
//     printf("\n");

//     // Test 5: Hepsi x var farklı kombinasyon (101 101 101 = 365)
//     uint16_t d5 = 365;
//     printf("Test 5: 365 (r-x r-x r-x)\n");
//     printf("  Sonuc: %d (beklenen: 1)\n", verifier_execution_globale(d5));
//     printf("\n");

//     // Test 6: chmod 111 (001 001 001 = 73)
//     uint16_t d6 = 73;
//     printf("Test 6: 73 (--x --x --x)\n");
//     printf("  Sonuc: %d (beklenen: 1)\n", verifier_execution_globale(d6));
//     printf("\n");

//     return 0;
// }


// #include <stdint.h>

// int verifier_execution_globale(uint16_t droits) {
//     uint16_t masque = (1 << 6) | (1 << 3) | (1 << 0);

//     if ((droits & masque) == masque) {
//         return 1;
//     } else {
//         return 0;
//     }

// }


// uint16_t ajouter(uint16_t droits) {
//     uint16_t masque = (1 << 4);

//     return droits | masque;
// }


// uint16_t revoquer(uint16_t droits) {
//     uint16_t masque = (1 << 2) | (1 << 1) | (1 << 0);

//     return droits & ~masque;
// }

// uint16_t basculer(uint16_t droits) {
//     uint16_t masque = (1 << 8);

//     return droits ^ masque;
// }

#include <stdio.h>
#include <stdint.h>

// int compteur(const char *nom_fichier) {
//     FILE *f = fopen(nom_fichier, "rb");
//     if (f == NULL) {
//         return -1;
//     }

//     int compteur = 0;

//     uint16_t droits;

//     uint16_t masque = (1 << 8) | (1 << 7);

//     while (fread(&droits, sizeof(uint16_t), 1, f) == 1) {
//         if ((droits & masque) == masque) {
//             compteur++;
//         }
//     }


//     fclose(f);

//     return compteur;

// }




