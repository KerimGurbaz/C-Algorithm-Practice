// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <stdint.h>


// // typedef struct __attribute__((packed)) {
// //     uint16_t id;
// //     uint32_t horodatage;
// //     uint8_t type;
// //     float valeur;
// // }DonneesCapteur;

// // void afficher_capteur(const DonneesCapteur *capteur) {
// //     if (capteur == NULL) return;

// //     printf("-- Releve du capteur --\n");

// //     printf("ID      : %u\n", capteur->id);
// //     printf("Horodatage      : %u\n", capteur->horodatage);
// //     printf("Type        : %u\n", capteur->type);
// //     printf("Valeur      : %f\n", capteur->valeur);


// // }

// // int main() {

// //     DonneesCapteur *zone_memoire = malloc(sizeof(DonneesCapteur));

// //     if (zone_memoire == NULL) {
// //         printf("Erreur : Impossible d'allouer la memoire.\n");
// //         return 1;
// //     }

// //     zone_memoire->id = 12345;
// //     zone_memoire->horodatage = 161803398;
// //     zone_memoire->type = 2;
// //     zone_memoire->valeur = 3.14159f;

// //     afficher_capteur(zone_memoire);
// //     printf("Taille exact : %zu octet\n", sizeof(*zone_memoire));


// //     free(zone_memoire);

// //     return 0;
// // }

// // #include <stdio.h>
// // #include <string.h>
// // #include <stdbool.h>

// // bool detecter_motif(const char *chaine, const char *motif) {
// //     if (chaine == NULL || motif == NULL) return false;

// //     return strstr(chaine, motif) != NULL;
// // }

// // int main() {
// //     const char *const motif = "subcmd";

// //     const char *const chaines[] = {
// //         "commande1 subcmd",
// //         "autre commende",
// //         "encore subcmd ici",
// //         "derniere chaine"
// //     };

// //     const int nb_chaines = sizeof(chaines) / sizeof(chaines[0]);

// //     printf("--Detection--\n");

// //     for (int i = 0; nb_chaines; ++i) {
// //         if (detecter_motif(chaines[i], motif)) {
// //             printf("Trouve  : \"%s\"\n", chaines[i]);
// //         } else {
// //             printf("Absent : \"%s\"\n", chaines[i]);
// //         }
// //     }

// //     return 0;
// // }
// // #include <stdio.h>
// // #include <string.h>
// // #include <stdbool.h>

// // #define NB_CHAINES 4
// // #define CIBLE "subcmd"

// // bool detecter(const char *texte, const char *motif) {
// //     if (texte == NULL || motif == NULL)return false;

// //     if (strstr(texte, motif) != NULL) {
// //         return true;
// //     }
// //     return false;
// // }


// // int main() {
// //     const char *const tableau[NB_CHAINES] = {
// //         "commande1 subcmd",
// //         "autre commande",
// //         "encore subcmd ici",
// //         "derniere chaine"
// //     };

// //     printf("--- Analyse des commandes (Recherche de '%s') ---\n\n", CIBLE);

// //     for (int i = 0; i < NB_CHAINES; ++i) {
// //         if (detecter(tableau[i], CIBLE)) {
// //             printf("Trouve : \"%s\"\n", tableau[i]);
// //         } else {
// //             printf("Ignore : \"%s\"\n", tableau[i]);
// //         }
// //     }


// //     return 0;
// // }


// #include <stdio.h>

// typedef enum {
//     ARRET,
//     DEMARRAGE,
//     MARCHE,
//     ALARM
// }EtatMoteur;


// void afficher_etat(EtatMoteur e) {
//     switch (e) {
//     case ARRET: printf("Arret**\n");
//         break;
//     case DEMARRAGE: printf("demarrage**\n");
//         break;
//     case MARCHE: printf("MARCHE**\n");
//         break;
//     case ALARM: printf("ALARM**\n");
//         break;
//     default:
//         printf("Aucune sense..\n");
//         break;
//     }

// }

// int main() {

//     EtatMoteur etat = ARRET;

//     afficher_etat(etat);
//     return 0;
// }

#include <stdio.h>

// typedef struct {
//     int id;
//     float solde;
// }CompteBancaire;

// void crediter(CompteBancaire *compte, float montant) {

//     if (compte == NULL || montant < 0)return;

//     compte->solde += montant;
// }

// void afficher(const CompteBancaire *c) {
//     if (c == NULL)return;
//     printf("ID  : %d\n", c->id);
//     printf("SOLDE  : %.2f\n", c->solde);
// }

// int main() {

//     CompteBancaire account = { 1, 100.9f };
//     afficher(&account);
//     crediter(&account, 150);

//     afficher(&account);
//     return 0;
// }

// typedef struct {
//     char title[50];
//     int date;
// }Livre;

// void afficher_titre_livre(const Livre *l) {
//     //l->date= 2024;
//     printf("Title       : %s\n", l->title);
//     printf("Year       : %d\n", l->date);

// }

// int main() {
//     Livre L = { .title = "Selam", .date = 2000 };
//     afficher_titre_livre(&L);
//     L.date = 2024;
//     afficher_titre_livre(&L);

//     return 0;

// }
#include <stdio.h>
#include <string.h>

typedef enum {
    TEXTE,
    CODE_ERREUR
}TypeMessage;

typedef union {
    char texte[20];
    int code;
}Payload;

typedef struct {
    TypeMessage type;
    Payload  donnees;
}TrameReseau;

void afficher_trame(const TrameReseau *trame) {
    if (trame == NULL) return;
    printf("Trame : ");

    switch (trame->type) {
    case TEXTE:
        printf("[MSG] %s\n", trame->donnees.texte);
        break;

    }
}

int main() {
    TrameReseau trame1;
    trame1.type = TEXTE;
    strncpy(trame1.donnees.texte, "Connexion OK", sizeof(trame1.donnees.texte) - 1);
    trame1.donnees.texte[sizeof(trame1.donnees.texte) - 1] = '\0';

    TrameReseau trame2 = {
        .type = CODE_ERREUR,
        .donnees = {.code = 404}
    };

    printf("--- LECTURE DES TRAMES ---\n");
    afficher_trame(&trame1);
    afficher_trame(&trame2);

    // Bellek tasarrufunun kanıtı
    printf("\n[INFO] Memoire utilisee par l'Union (Payload) : %lu octets\n", sizeof(Payload));
    printf("[INFO] Memoire utilisee par le Struct complet : %lu octets\n", sizeof(TrameReseau));


    return 0;
}
