#include <stdio.h>
#include <string.h>

#define MAXSTOCK 100

typedef enum {
    FICTION,
    NON_FICTION,
    SCIENCE,
    BIOGRAPHY,
    HISTORY
}Type;

typedef struct {
    char title[100];
    char auteur[100];
    int year;
    Type typeBook;
}Book;

void ajouterLivre(Book collection[], int *nbLivres) {
    if (*nbLivres >= MAXSTOCK) {
        printf("Erreur la bibliotheque pleine");
        return;
    }

    Book nouveau;

    printf("Entrez le titre du livre (sans espace) : ");
    scanf("%99s", nouveau.auteur);

    printf("Entrez l'auteur du livre (sans espace) : ");
    scanf("%99s", nouveau.auteur);

    printf("Entrez l'annee de publication : ");
    scanf("%d", &nouveau.year);

    printf("Entrez le genre (0:FICTION, 1:NON_FICTION, 2:SCIENCE, 3:BIOGRAPHY, 4:HISTORY) : ");
    scanf("%d", (int *)&nouveau.typeBook);

    collection[*nbLivres++] = nouveau;
    printf("[+] Livre ajoute avec succes !\n");

}
void afficherLivres(Book collection[], int nbLivres) {
    if (nbLivres == 0) {
        printf("[i] La bibliotheque est vide.\n");
        return;
    }
    printf("\n--- LISTE DES LIVRES (%d/%d) ---\n", nbLivres, MAXSTOCK);
    for (int i = 0; i < nbLivres; ++i) {
        printf("Titre : %s\n", collection[i].title);
        printf("Auteur  :%s\n", collection[i].auteur);
        printf("Annee   : %d\n", collection[i].year);

        printf("Genre   : ");
        switch (collection[i].typeBook) {
        case FICTION: printf("FICTIOn\n"); break;
        case NON_FICTION: printf("NON_FICTION\n"); break;
        case SCIENCE: printf("SCIENCE\n"); break;
        case BIOGRAPHY: printf("BIOGRAPHY\n"); break;
        case HISTORY: printf("HISTORY\n"); break;
        default: printf("INCONNU\n"); break;
        }
        printf("--------------------------------\n");
    }

}

Book *rechercherLivreParTitre(const Book collection[], int nbLivres, const char *titre) {
    for (int i = 0; i < nbLivres; ++i) {
        if (strcmp(collection[i].title, titre) == 0) {
            return (Book *)&collection[i];
        }
    }
    return NULL;

}

int main() {
    Book collection[MAXSTOCK];
    int nb_book = 0;
    int choix;

    do {

        printf("\n=== MENU BIBLIOTHEQUE ===\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre par titre\n");
        printf("4. Quitter\n");
        printf("Choisissez une option : ");

        if (scanf("%d", &choix) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (choix == 1) {
            ajouterLivre(collection, &nb_book);
        } else if (choix == 2) {
            afficherLivres(collection, nb_book);
        } else if (choix == 3) {
            char title_search[100];
            printf("Entrez le titre recherce:    ");
            scanf("%99s", title_search);

            Book *found = rechercherLivreParTitre(collection, nb_book, title_search);

            if (found == NULL) {
                printf("Livre introuvable.\n");
            } else {
                printf("\n[TROUVE] titre:%s | Auteur: %s | Annee: %d\n", found->title, found->auteur, found->year);
            }
        }

    }
    while (choix != 4);
    printf("fermeture du program..\n");


    return 0;
}
