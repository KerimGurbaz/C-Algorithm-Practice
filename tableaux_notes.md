```c
//Exercice 1 — Somme des éléments d’un tableau
#include <stdio.h>

int main() {
    int n;

    // 1. Lecture de la taille
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1; // Contrainte : n > 0
    }

    // 2. Déclaration du tableau AUTOMATIQUE (VLA)
    // Attention: Ceci est alloué sur la Pile (Stack), pas sur le Tas (Heap)
    int tab[n];
    int somme = 0;

    // 3. Remplissage et calcul simultané
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
        somme += tab[i]; // Akümülatör
    }

    // 4. Sortie stricte selon la consigne
    printf("Somme : %d\n", somme);

    return 0;
}

```

```c
//Exercice 2 — Moyenne des valeurs d’un tableau
#include <stdio.h>

int main() {
    int n;

    // 1. Lecture de la taille (Contrainte: n > 0)
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    // 2. Déclaration du tableau automatique (VLA - Variable Length Array)
    float tab[n];
    float somme = 0.0f; // Initialisation explicite en float

    // 3. Remplissage et sommation (Lecture des valeurs)
    for (int i = 0; i < n; ++i) {
        if (scanf("%f", &tab[i]) != 1) {
            return 1;
        }
        somme += tab[i];
    }

    // 4. Calcul et affichage strict
    float moyenne = somme / n;
    printf("Moyenne : %.2f\n", moyenne);

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
