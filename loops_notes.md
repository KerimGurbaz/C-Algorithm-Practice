## Exercice 1 — Lecture d’un entier positif

```c
#include <stdio.h>

int main() {
    int n;

    // 1. Girdi Alma (2pts - scanf / printf)
    // Güvenlik: Kullanıcı pozitif bir sayı girene kadar döngüde tutuyoruz.
    do {
        printf("Entrez un entier positif : ");
        if (scanf("%d", &n) != 1) {
            printf("Erreur de saisie.\n");
            // Eğer harf girilirse buffer'ı temizleme refleksimiz (Q3'ten hatırlarsın)
            while(getchar() != '\n');
            continue;
        }
    } while (n <= 0);

    // 2. Dizi Üretimi (3pts - génération de la suite correcte)
    // Sayı 1'e ULAŞMADIĞI sürece döngüye devam et.
    while (n > 1) {
        printf("%d ", n); // Mevcut sayıyı formülü uygulamadan ÖNCE yazdır.

        // Sayı çift mi? (Pair)
        if (n % 2 == 0) {
            n = n / 2;
        }
        // Sayı tek mi? (Impair)
        else {
            n = 3 * n + 1;
        }
    }

    // Döngü bittiğinde n artık 1'dir. Son sayıyı yazdırıp bitiriyoruz.
    printf("1\n");

    return 0;
}
```

```c

#include <stdio.h>

int main() {
    int n;
    int count = 0; // Compteur d'étapes (Nombre d'itérations)

    // 1. Validation de la saisie (Gestion des I/O)
    do {
        printf("Entrez un nombre positif : \n");
        if (scanf("%d", &n) != 1) {
            printf("Erreur de saisie.\n");
            while (getchar() != '\n'); // Vidage du buffer clavier en cas de lettres
            continue;
        }
    } while (n <= 0);

    // 2. Algorithme de Syracuse (Calcul de la trajectoire)
    while (n > 1) {
        // Parité : Utilisation du modulo
        if (n % 2 == 0) {
            n /= 2;        // Règle pour les nombres pairs
        } else {
            n = 3 * n + 1; // Règle pour les nombres impairs
        }
        ++count; // Incrémentation du compteur à chaque étape
    }

    // 3. Affichage final (Strictement conforme à l'énoncé)
    printf("Nombre d'etapes: %d\n", count);

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
