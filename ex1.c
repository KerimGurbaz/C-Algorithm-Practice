#include <stdio.h>

// typedef struct {
//     float x;
//     float y;
// }Point2D;

// int main() {

//     Point2D p1;
//     p1.x = 5.5;
//     p1.y = 10.2;

//     printf("x = %.2f && y= %.2f\n", p1.x, p1.y);

//     return 0;
// }


// typedef struct {
//     float x;
//     float y;
// }Point2D;

// void deplacer(Point2D *p, float dx, float dy) {
//     if (p == NULL)return;
//     p->x += dx;
//     p->y += dy;
// };

// int main() {
//     Point2D p1;
//     p1.x = 5.5;
//     p1.y = 10.2;

//     deplacer(&p1, 1.2, 2.2);

//     printf("x = %.1f && y= %.1f\n", p1.x, p1.y);

//     return 0;
// }

// typedef struct {
//     int id;
//     float valeur;
// }Capteur;


// int main() {
//     Capteur cap[3] = {
//         {1, 24.5},
//         {2, 34.5},
//         {3, 44.5}
//     };


//     for (int i = 0; i < 3; ++i) {
//         if (cap[i].valeur > 25) {
//             printf("ID: %d = %.1f\n", i, cap[i].valeur);
//         }
//     }

//     return 0;
// }


// typedef struct {
//     int jour;
//     int mois;
//     int annee;
// }Date;

// typedef struct {
//     int id;
//     float prix;
//     Date date_expiration;
// }Produit;

// int main() {
//     Produit p;
//     p.id = 1;
//     p.prix = 12.99;
//     p.date_expiration.jour = 15;
//     p.date_expiration.mois = 8;
//     p.date_expiration.annee = 2027;

//     Produit p2 = { 2, 45.50, {15,9,2030} };

//     printf("Produit ID :%d | Prix:%.2f | EXpiration : %02d/%02d/%d\n",
//         p.id,
//         p.prix,
//         p.date_expiration.jour,
//         p.date_expiration.mois,
//         p.date_expiration.annee
//     );
//     return 0;
// }
// #include <string.h>

// typedef struct {
//     char nom[50];
//     float notes[5];

// }Etudiant;

// void afficher(const Etudiant *e) {
//     if (e == NULL) return;

//     float somme = 0.0;

//     printf("---Bulletin de %s ---", e->nom);
//     for (int i = 0; i < 5; ++i) {
//         printf("Note %d : %.2f\n", i + 1, e->notes[i]);
//         somme += e->notes[i];
//     }
//     printf(">> Moyenne : %.2f\n\n", somme / 5.0);


// }

// int main() {
//     Etudiant e1;

//     strncpy(e1.nom, "Kerim GURBAZ", sizeof(e1.nom) - 1);
//     e1.nom[sizeof(e1.nom) - 1] = '\0';

//     e1.notes[0] = 14.5;
//     e1.notes[1] = 16.0;
//     e1.notes[2] = 12.5;
//     e1.notes[3] = 18.0;
//     e1.notes[4] = 15.0;

//     afficher(&e1);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_MARQUE 50

// typedef struct {
//     char marque[MAX_MARQUE];
//     int kilomertrage;
// }Vehicule;

// Vehicule *cree_vehicule(const char *marque, int km) {
//     Vehicule *nouveau_vehicule = malloc(sizeof(Vehicule));

//     if (nouveau_vehicule == NULL) {
//         printf("[!]Erreur d'allocation memoire.\n");
//         return NULL;
//     }

//     strncpy(nouveau_vehicule->marque, marque, MAX_MARQUE - 1);
//     nouveau_vehicule->marque[MAX_MARQUE - 1] = '\0';
//     nouveau_vehicule->kilomertrage = km;

//     return nouveau_vehicule;
// }

// int main() {
//     Vehicule *mon_auto = cree_vehicule("Porsche 911", 45000);

//     if (mon_auto != NULL) {

//         printf("--- Vehicule Enregistre -- \n");
//         printf("MArque : %s\n", mon_auto->marque);
//         printf("KM : %d\n", mon_auto->kilomertrage);

//         free(mon_auto);

//     }

//     return 0;
// }

#include <stdio.h>
typedef struct {
    char c1;
    int i;
    char c2;

}StructA;

typedef struct {
    int i;
    char c1;
    char c2;

}StructB;

int main() {
    printf("--- Test de Memoire (Memory Alignment) ---\n");

    // Beklenti: 1 + 4 + 1 = 6 byte olması yönündedir. Ama sonuçlar şaşırtacak.
    printf("Taille de Struct A : %zu octets\n", sizeof(StructA)); // Çıktı: 12
    printf("Taille de Struct B : %zu octets\n", sizeof(StructB)); // Çıktı: 8

    return 0;
}
