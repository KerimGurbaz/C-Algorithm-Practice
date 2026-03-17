```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *tab = calloc(n, sizeof(int));
    if (tab == NULL) {
        printf("Erreur...");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", tab[i]);
    }


    free(tab);
    return 0;
}


```

```c
//Somme d’un tableau dynamique
#include <stdio.h>  // Pour printf, scanf
#include <stdlib.h> // Pour malloc, free, NULL

int main() {
    int n;

    // 1. Validation de la taille
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    // 2. Allocation dynamique sur le Tas (Heap)
    // On demande 'n' blocs de la taille d'un entier
    int *tab = (int *)malloc(n * sizeof(int));

    // 3. Vérification de l'allocation (Très important !)
    if (tab == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    int somme = 0;

    // 4. Lecture et calcul simultanés (Algorithme à un seul passage)
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab); // Libération avant de quitter en cas d'erreur (Excellent !)
            return 1;
        }
        somme += tab[i]; // Accumulation
    }

    // 5. Affichage propre (le \n à la fin est préférable)
    printf("Somme : %d\n", somme);

    // 6. Libération de la mémoire
    free(tab);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include "copie.h"
//Copier un tableau dynamique
int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *tab1 = malloc(n * sizeof *tab1);
    if (tab1 == NULL) return 1;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab1[i]) != 1) {
            free(tab1);
            return 1;
        }
    }

    // Appel de la fonction
    int *tab2 = copier_tableau_dynamique(tab1, n);

    // Si la copie a échoué (plus de RAM), on nettoie l'original
    if (tab2 == NULL) {
        free(tab1);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", tab2[i]);
    }
    printf("\n");

    free(tab1);
    free(tab2);

    return 0;
}

```

```c
//Exercice 6 — Recherche dans un tableau dynamique
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Utilisation du terme correct et 'const' pour la sécurité
bool rechercher(const int *tab, int x, int n) {
    for (int i = 0; i < n; ++i) {
        if (tab[i] == x) return true; // Succès immédiat
    }
    return false;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *tab = (int *)malloc(n * sizeof *tab);
    if (tab == NULL) return 1;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
    }

    int x;
    if (scanf("%d", &x) != 1) {
        free(tab); // Libération obligatoire avant le return
        return 1;
    }

    // Affichage strict selon la consigne
    if (rechercher(tab, x, n)) {
        printf("Valeur trouvee\n");
    } else {
        printf("Valeur absente\n");
    }

    free(tab);
    tab = NULL; // Bonne pratique : éviter les pointeurs "fous" (dangling pointers)
    return 0;
}

```

```c
// La fonction retourne un pointeur (int*)
int* trouver_pointeur_maximum(int *tab, int taille) {
    if (taille <= 0) return NULL;

    int *ptr_max = &tab[0]; // On pointe sur le premier élément

    for (int i = 1; i < taille; ++i) {
        // On compare la valeur pointée (*ptr_max) avec la valeur actuelle (tab[i])
        if (tab[i] > *ptr_max) {
            ptr_max = &tab[i]; // On met à jour l'adresse !
        }
    }

    // On retourne une adresse valide qui pointe vers le Tas (Heap)
    return ptr_max;
}

/* Utilisation dans le main :
   int *p_max = trouver_pointeur_maximum(tab, n);
   if (p_max != NULL) {
       printf("Adresse du max : %p\n", (void*)p_max);
       printf("Valeur du max : %d\n", *p_max);
   }
*/

```

```c
#include <stdio.h>
#include <stdlib.h>

// 1. Le type de retour devient 'const int *'
const int *chercher_pointeur_max(const int *tab, int n) {
    if (n <= 0) return NULL;

    // 2. Le pointeur local devient 'const'
    const int *ptr_max = &tab[0];

    for (int i = 1; i < n; ++i) {
        if (tab[i] > *ptr_max) {
            ptr_max = &tab[i];
        }
    }

    return ptr_max;
}

int main() {
    int n;
    printf("Entrez une valeur : \n");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *tab = malloc(n * sizeof *tab);
    if (tab == NULL) return 1;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
    }

    // 3. Le pointeur de réception dans le main doit aussi être 'const'
    const int *p = chercher_pointeur_max(tab, n);

    if (p != NULL) {
        printf("Max value address : %p\n", (void *)p);
        printf("Max value  : %d\n", *p);
    }

    free(tab);
    tab = NULL;
    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    // 1. Allocation initiale
    int *tab = malloc(n * sizeof *tab);
    if (tab == NULL) return 1;

    // 2. Lecture des n premières valeurs
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
    }

    // 3. Redimensionnement sécurisé (2*n)
    // On utilise un pointeur temporaire pour ne pas perdre 'tab' en cas d'échec
    int *temp = realloc(tab, (2 * n) * sizeof *temp);

    if (temp == NULL) {
        printf("Erreur : Realloc a echoue.\n");
        free(tab); // On nettoie l'ancien avant de quitter
        return 1;
    }
    tab = temp; // Tout est bon, on met à jour notre pointeur principal

    // 4. Lecture des n nouvelles valeurs (de n à 2n-1)
    for (int i = n; i < 2 * n; i++) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
    }

    // 5. Affichage final
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);
    return 0;
}#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    // 1. Allocation initiale
    int *tab = malloc(n * sizeof *tab);
    if (tab == NULL) return 1;

    // 2. Lecture des n premières valeurs
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
    }

    // 3. Redimensionnement sécurisé (2*n)
    // On utilise un pointeur temporaire pour ne pas perdre 'tab' en cas d'échec
    int *temp = realloc(tab, (2 * n) * sizeof *temp);

    if (temp == NULL) {
        printf("Erreur : Realloc a echoue.\n");
        free(tab); // On nettoie l'ancien avant de quitter
        return 1;
    }
    tab = temp; // Tout est bon, on met à jour notre pointeur principal

    // 4. Lecture des n nouvelles valeurs (de n à 2n-1)
    for (int i = n; i < 2 * n; i++) {
        if (scanf("%d", &tab[i]) != 1) {
            free(tab);
            return 1;
        }
    }

    // 5. Affichage final
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);
    return 0;
}


```

```c
//Écrire un programme qui lit des entiers jusqu’à ce que l’utilisateur entre 0
#include <stdio.h>
#include <stdlib.h>

int main() {
    int taille_logique = 0;
    // Consigne : taille initiale = 1
    int *tab = malloc(1 * sizeof *tab);
    if (tab == NULL) return 1;

    int valeur;
    while (1) {
        if (scanf("%d", &valeur) != 1) {
            free(tab);
            return 1;
        }

        if (valeur == 0) break; // Sortie immédiate, le 0 n'est pas stocké

        tab[taille_logique] = valeur;
        taille_logique++; // Un élément a été validé

        // Consigne : agrandir de +1 à chaque lecture
        int *temp = realloc(tab, (taille_logique + 1) * sizeof *temp);
        if (temp == NULL) {
            free(tab);
            return 1;
        }
        tab = temp;
    }

    // Affichage des valeurs valides
    for (int i = 0; i < taille_logique; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);
    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int taille = 0;
    int capacity = 1;
    int valeur;

    int *tab = malloc(capacity * sizeof *tab);
    if (tab == NULL) return 1;

    // Lecture jusqu'à trouver un 0
    while (scanf("%d", &valeur) == 1) {
        if (valeur == 0) break; // Sortie si c'est 0
        
        tab[taille++] = valeur; // Ajout de la valeur et incrémentation

        // Si le tableau est plein, on double sa capacité
        if (taille == capacity) {
            capacity *= 2;
            int *temp = realloc(tab, capacity * sizeof *temp);
            if (temp == NULL) {
                free(tab);
                return 1;
            }
            tab = temp;
        }
    }

    // Affichage propre sur une seule ligne
    for (int i = 0; i < taille; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);
    return 0;
}

```

```c
//(Le vrai Shrink-to-fit
#include <stdio.h>
#include <stdlib.h>

int main() {
    int taille = 0;
    int capacity = 1;
    int valeur;

    int *tab = malloc(capacity * sizeof * tab);
    if (tab == NULL) return 1;

    while (scanf("%d", &valeur) == 1) {
        if (valeur == 0) break;

        // 1. On ajoute d'abord
        tab[taille++] = valeur;

        // 2. On double SEULEMENT si c'est plein
        if (taille == capacity) {
            capacity *= 2;
            int *temp = realloc(tab, capacity * sizeof * tab);
            if (temp == NULL) {
                free(tab);
                return 1;
            }
            tab = temp;
        }
    }

    // --- LE VRAI SHRINK-TO-FIT ---
    // Si la RAM allouée (capacity) est plus grande que les données utiles (taille)
    // ET qu'il y a au moins 1 donnée (taille > 0).
    if (capacity > taille && taille > 0) {
        int *temp = realloc(tab, taille * sizeof * tab);
        if (temp != NULL) {
            tab = temp;
            capacity = taille; // Maintenant, l'étiquette correspond à la réalité physique
        }
    }

    for (int i = 0; i < taille; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\nTaille : %d  && Capacity : %d\n", taille, capacity);

    free(tab);
    return 0;
}


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
