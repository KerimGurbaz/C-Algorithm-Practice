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

// typedef enum {
//     TEXTE,
//     CODE_ERREUR
// }TypeMessage;

// typedef union {
//     char texte[20];
//     int code;
// }Payload;

// typedef struct {
//     TypeMessage type;
//     Payload  donnees;
// }TrameReseau;

// void afficher_trame(const TrameReseau *trame) {
//     if (trame == NULL) return;
//     printf("Trame : ");

//     switch (trame->type) {
//     case TEXTE:
//         printf("[MSG] %s\n", trame->donnees.texte);
//         break;
//     }
// }

// int main() {
//     TrameReseau trame1;
//     trame1.type = TEXTE;
//     strncpy(trame1.donnees.texte, "Connexion OK", sizeof(trame1.donnees.texte) - 1);
//     trame1.donnees.texte[sizeof(trame1.donnees.texte) - 1] = '\0';

//     TrameReseau trame2 = {
//         .type = CODE_ERREUR,
//         .donnees = {.code = 404}
//     };

//     printf("--- LECTURE DES TRAMES ---\n");
//     afficher_trame(&trame1);
//     afficher_trame(&trame2);

//     // Bellek tasarrufunun kanıtı
//     printf("\n[INFO] Memoire utilisee par l'Union (Payload) : %lu octets\n", sizeof(Payload));
//     printf("[INFO] Memoire utilisee par le Struct complet : %lu octets\n", sizeof(TrameReseau));


//     return 0;
// }


// #include <stdint.h>

// typedef struct {
//     uint8_t rouge;
//     uint32_t identifiant;
//     uint8_t bleu;
// }PixelStandard;

// typedef struct __attribute__((packed)) {
//     uint8_t rouge;
//     uint32_t identifiant;
//     uint8_t bleu;
// }PixelPacked;

// int main() {
//     printf("--- Analyse De La Memoire---\n");
//     printf("Taille theorique attendue : 1 + 4 + 1 = 6 octets\n\n");

//     printf("Taille PixelStandart : %zu octets\n", sizeof(PixelStandard));

//     printf("Taille PixelPacked : %zu octets\n", sizeof(PixelPacked));

//     return 0;
// }


// #include <stdio.h>
// #include <stdint.h>

// typedef union {
//     uint32_t grand_nombre;
//     uint8_t octets[4];
// }Test;

// int main() {
//     Test t;

//     t.grand_nombre = 0xAABBCCDD;
//     printf("--- ESPIONNAGE MEMOIRE (ENDIANNESS) ---\n");
//     printf("Valeur ecrite (32 bits) : 0x%08X\n\n", t.grand_nombre);

//     printf("Lecture par la lunette 'Tableau d'octets' :\n");

//     // On lit avec la deuxième "lunette"
//     for (int i = 0; i < 4; i++) {
//         // L'opérateur (void*) évite les warnings du compilateur avec %p (pointeur)
//         printf("Adresse : %p | octets[%d] = 0x%02X\n", (void *)&t.octets[i], i, t.octets[i]);
//     }

//     return 0;

// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef enum {
//     EN_LIGNE,
//     HORS_LIGNE
// }StatutJoueur;

// typedef struct {
//     char nom[50];
//     StatutJoueur statut;
// }Joueur;

// Joueur *creer_joueur(const char *nom) {
//     Joueur *nouveau_joueur = malloc(sizeof(Joueur));

//     if (nouveau_joueur == NULL) {
//         printf("Erreur critique..");
//         return NULL;
//     }

//     strncpy(nouveau_joueur->nom, nom, sizeof(nouveau_joueur->nom) - 1);
//     nouveau_joueur->nom[sizeof(nouveau_joueur->nom) - 1] = '\0';

//     nouveau_joueur->statut = EN_LIGNE;

//     return nouveau_joueur;
// }

// int main() {
//     printf("--- SYSTEME DE GESTION DES JOUEURS ---\n");
//     Joueur *j1 = creer_joueur("Kerim_GURBAZ");

//     if (j1 != NULL) {
//         printf("Joueur cree avec succes !\n");
//         printf("NOM : %s\n", j1->nom);
//         printf("Statut : %s\n", (j1->statut == EN_LIGNE) ? "En Ligne" : "Hors Ligne");

//         free(j1);
//         j1 = NULL;
//         printf("\nMemoire liberee. fin du programme.\n");

//         return  0;
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// typedef struct __attribute__((packed)) {
//     uint16_t id;
//     uint32_t horodatage;
//     uint8_t type;
//     float valeur;
// }Capteur;

// int main() {
//     int nombre_capteurs;

//     printf("Combien de capteurs voulez-vous allouer?");
//     if (scanf("%d", &nombre_capteurs) != 1 || nombre_capteurs <= 0) {
//         printf("Errur: Entree invalide.\n");
//         return 1;
//     }

//     Capteur *tableau = malloc(nombre_capteurs * sizeof(Capteur));
//     if (tableau == NULL) {
//         printf("Memoire insuffisant..\n");
//         return 1;
//     }

//     printf("\n[INFO] %d capteurs alloues avec succes(%lu octets au total).\n", nombre_capteurs, nombre_capteurs * sizeof(Capteur));

//     for (int i = 0; i < nombre_capteurs; ++i) {
//         tableau[i].id = 1000 + i;

//         tableau[i].horodatage = 161800000 + (i * 10);

//         tableau[i].type = i % 3;

//         tableau[i].valeur = 20.5f + (float)i;
//     }

//     printf("\n--- LECTURE DU TABLEAU ---\n");
//     for (int i = 0; i < nombre_capteurs; i++) {
//         printf("Capteur [%d] -> ID: %u | Type: %u | Valeur: %.2f\n",
//             i, tableau[i].id, tableau[i].type, tableau[i].valeur);
//     }

//     free(tableau);
//     tableau = NULL;
//     printf("\n[INFO] Memoire liberee avec succes.\n");
//     return 0;

// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *titre;
    int annee;
}Livre;

Livre *creer_livre(const char *nom, int annee) {
    Livre *nouveau_livre = malloc(sizeof(Livre));
    if (nouveau_livre == NULL) return NULL;

    nouveau_livre->titre = malloc((strlen(nom) + 1) * sizeof(char));

    if (nouveau_livre->titre == NULL) {
        free(nouveau_livre);
        return NULL;
    }

    strcpy(nouveau_livre->titre, nom);
    nouveau_livre->annee = annee;
}

void detruire_livre(Livre *l) {
    if (l == NULL) return;
    free(l->titre);
    free(l);
}

int main() {
    printf("--- ALLOCATION IMBRIQUEE ---\n");

    Livre *mon_livre = creer_livre("Le C en 20 Heures", 1972);
    if (mon_livre != NULL) {
        printf("Livre cree   : %s (%d)\n", mon_livre->titre, mon_livre->annee);
        detruire_livre(mon_livre);
        mon_livre = NULL;
        printf("Livre detruit sans fuite de memoire.\n");

    }

    return 0;
}
