// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>


// typedef struct __attribute__((packed)) {
//     uint16_t id;
//     uint32_t horodatage;
//     uint8_t type;
//     float valeur;
// }DonneesCapteur;

// void afficher_capteur(const DonneesCapteur *capteur) {
//     if (capteur == NULL) return;

//     printf("-- Releve du capteur --\n");

//     printf("ID      : %u\n", capteur->id);
//     printf("Horodatage      : %u\n", capteur->horodatage);
//     printf("Type        : %u\n", capteur->type);
//     printf("Valeur      : %f\n", capteur->valeur);


// }

// int main() {

//     DonneesCapteur *zone_memoire = malloc(sizeof(DonneesCapteur));

//     if (zone_memoire == NULL) {
//         printf("Erreur : Impossible d'allouer la memoire.\n");
//         return 1;
//     }

//     zone_memoire->id = 12345;
//     zone_memoire->horodatage = 161803398;
//     zone_memoire->type = 2;
//     zone_memoire->valeur = 3.14159f;

//     afficher_capteur(zone_memoire);
//     printf("Taille exact : %zu octet\n", sizeof(*zone_memoire));


//     free(zone_memoire);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>

// bool detecter_motif(const char *chaine, const char *motif) {
//     if (chaine == NULL || motif == NULL) return false;

//     return strstr(chaine, motif) != NULL;
// }

// int main() {
//     const char *const motif = "subcmd";

//     const char *const chaines[] = {
//         "commande1 subcmd",
//         "autre commende",
//         "encore subcmd ici",
//         "derniere chaine"
//     };

//     const int nb_chaines = sizeof(chaines) / sizeof(chaines[0]);

//     printf("--Detection--\n");

//     for (int i = 0; nb_chaines; ++i) {
//         if (detecter_motif(chaines[i], motif)) {
//             printf("Trouve  : \"%s\"\n", chaines[i]);
//         } else {
//             printf("Absent : \"%s\"\n", chaines[i]);
//         }
//     }

//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NB_CHAINES 4
#define CIBLE "subcmd"

bool detecter(const char *texte, const char *motif) {
    if (texte == NULL || motif == NULL)return false;

    if (strstr(texte, motif) != NULL) {
        return true;
    }
    return false;
}


int main() {
    const char *const tableau[NB_CHAINES] = {
        "commande1 subcmd",
        "autre commande",
        "encore subcmd ici",
        "derniere chaine"
    };

    printf("--- Analyse des commandes (Recherche de '%s') ---\n\n", CIBLE);

    for (int i = 0; i < NB_CHAINES; ++i) {
        if (detecter(tableau[i], CIBLE)) {
            printf("Trouve : \"%s\"\n", tableau[i]);
        } else {
            printf("Ignore : \"%s\"\n", tableau[i]);
        }
    }


    return 0;
}
