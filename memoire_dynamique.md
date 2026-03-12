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


```

```c


```

```c


```

```c


```
