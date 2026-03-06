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
#include <stdio.h>
#include <limits.h>

int main() {
    int n, val;
    int min, max;

    // 1. Kaç sayı girilecek? (Nombre de valeurs à lire)
    printf("Combien de valeurs voulez-vous entrer ? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erreur : n doit etre positif.\n");
        return 1;
    }

    // 2. İlk sayıyı referans olarak oku (La référence initiale)
    printf("Valeur 1 : ");
    scanf("%d", &val);
    min = val;
    max = val;

    // 3. Geri kalan (n-1) tane sayı için döngü (La boucle pour le reste)
    for (int i = 2; i <= n; i++) {
        printf("Valeur %d : ", i);
        scanf("%d", &val);

        if (val > max) {
            max = val;
        }
        if (val < min) {
            min = val;
        }
    }

    // 4. Sonuçlar (Affichage des résultats)
    printf("\nMax : %d", max);
    printf("\nMin : %d\n", min);

    return 0;
}

```

```c
#include <stdio.h>

int main() {
    int val, count;
    int somme = 0; // daha guvenlisi long long somme = 0

    printf("Combien de nombres voulez-vous entrer : ");
    // Vérification de la saisie (Saisie sécurisée)
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Erreur : veuillez entrer un entier positif.\n");
        return 1;
    }

    for (int i = 1; i <= count; ++i) {
        printf("Entrez le nombre %d : ", i);
        if (scanf("%d", &val) != 1) {
            printf("Erreur de lecture.\n");
            return 1;
        }
        somme += val;
    }

    // Le Transtypage (Casting) est crucial ici pour ne pas perdre la précision
    float moyenne = (float)somme / count;

    printf("\nLa moyenne des %d nombres est : %.2f\n", count, moyenne);

    return 0;
}

```

```c
#include <stdio.h>

int main() {
    int val;
    int nb_elements = 0; // Sayıcı (Compteur)
    long long somme = 0; // Akümülatör (Accumulateur)

    printf("Entrez des nombres (0 pour arreter) :\n");

    while (1) {
        printf("Valeur %d : ", nb_elements + 1);

        // Lecture avec vérification (Saisie sécurisée)
        if (scanf("%d", &val) != 1) {
            printf("Erreur de saisie.\n");
            while(getchar() != '\n');
            continue;
        }

        // Condition d'arrêt (Sentinelle)
        if (val == 0) {
            break; // Döngüden anında çık, 0'ı ne toplama ekle ne de say
        }

        somme += val;
        nb_elements++;
    }

    // Affichage des résultats (Gestion du pluriel)
    if (nb_elements == 0) {
        printf("Aucun nombre n'a ete saisi.\n");
    } else {
        printf("\nVous avez entre %d nombre%s.\n", nb_elements, (nb_elements > 1 ? "s" : ""));
        printf("La somme totale est : %lld\n", somme);
        //long long kullandığın için printf içinde %d yerine %lld kullanman gerekir. Eğer %d kullanırsan, sayı çok büyüdüğünde yanlış sonuçlar yazdırılır.
    }

    return 0;
}

```

```c
//Sentinel ile okuma: negatif gelince dur
#include <stdio.h>

int main() {
    int nb_elements = 0;
    int val;
    long long somme = 0;

    printf("Entrez des nombres (negatif pour arreter) :\n");

    while (1) {
        printf("Valeur %d : ", nb_elements + 1);
        if (scanf("%d", &val) != 1) {
            printf("Erreur de saisie.\n");
            while (getchar() != '\n');
            continue;
        }

        // Condition d'arret : nombre negatif
        if (val < 0) {
            break;
        }

        somme += val;
        nb_elements++;
    }

    // Securite : Ne pas diviser par zero (Eviter le crash)
    if (nb_elements > 0) {
        float moyenne = (float)somme / nb_elements;
        printf("\nVous avez entre %d nombre(s) positif(s).\n", nb_elements);
        printf("La moyenne est : %.2f\n", moyenne);
    } else {
        // Cas ou aucun nombre positif n'a ete saisi
        printf("Aucune valeur\n");
    }

    return 0;
}

```

```c
//Basamak sayısı
#include <stdio.h>

int main() {
    int val;
    int nb_chiffres = 0;

    printf("Entrez un nombre entier : ");
    if (scanf("%d", &val) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    // On utilise une copie pour ne pas perdre la valeur originale
    int temp = val;

    // Cas particulier pour le nombre 0
    if (temp == 0) {
        nb_chiffres = 1;
    } else {
        // Pour gérer les nombres négatifs si l'utilisateur en entre un
        if (temp < 0) temp = -temp;

        while (temp > 0) {
            temp /= 10; // Division entière par 10 (on enlève le dernier chiffre)
            nb_chiffres++;
        }
    }

    printf("Le nombre %d possede %d chiffre(s).\n", val, nb_chiffres);

    return 0;
}

```

```c
//Basamakların toplamı
#include <stdio.h>

int main() {
    int val;
    int somme = 0;

    printf("Entrez un nombre entier : ");
    // Saisie sécurisée : on arrête si ce n'est pas un nombre
    if (scanf("%d", &val) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    int original = val;

    // Valeur absolue pour gérer les nombres négatifs
    if (val < 0) val = -val;

    // Algorithme d'extraction des chiffres
    while (val > 0) {
        somme += val % 10; // On ajoute le reste de la division par 10
        val /= 10;         // On effectue la division entière
    }

    printf("La somme des chiffres de %d est : %d\n", original, somme);

    return 0;
}


```

```c
#include <stdio.h>

int main() {
    int val;
    long long inverse = 0; // On utilise long long pour éviter le débordement

    printf("Entrez un nombre entier : ");
    if (scanf("%d", &val) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    int original = val;

    // Gestion du signe pour les nombres négatifs
    int signe = (val < 0) ? -1 : 1;
    if (val < 0) val = -val;

    while (val > 0) {
        int reste = val % 10;
        inverse = (inverse * 10) + reste; // Décalage vers la gauche
        val /= 10;                        // Réduction du nombre
    }

    // On remet le signe à la fin
    long long resultat_final = inverse * signe;

    printf("%d => %lld\n", original, resultat_final);

    return 0;
}

```

```c
//Palindrom sayı mı?
#include <stdio.h>
#include <stdbool.h>

// Fonction pure : Compare deux entiers
bool est_palindrome(const int original, const long long inverse) {
    return (long long)original == inverse;
}

int main() {
    int val;
    printf("Entrez un nombre positif : ");

    if (scanf("%d", &val) != 1 || val < 0) {
        printf("Erreur de saisie.\n");
        // On ne nettoie le buffer que si on boucle, ici on sort.
        return 1;
    }

    long long inverse = 0;
    int temp = val;

    // Algorithme d'inversion
    while (temp > 0) {
        int reste = temp % 10;
        inverse = (inverse * 10) + reste;
        temp /= 10;
    }

    // Affichage du résultat
    if (est_palindrome(val, inverse)) {
        printf("Oui, %d est un palindrome.\n", val);
    } else {
        printf("Non, %d n'est pas un palindrome.\n", val);
    }

    return 0;
}


```

```c
//13) Üs alma
#include <stdio.h>

int main() {
    int a, b;
    long long resultat = 1;

    printf("Entrez la base (a) et l'exposant (b >= 0) : \n");
    // Saisie sécurisée avec validation de b
    if (scanf("%d %d", &a, &b) != 2 || b < 0) {
        printf("Erreur : b doit etre positif ou nul.\n");
        return 1;
    }

    // Boucle d'exponentiation itérative
    // Si b = 0, la boucle est ignorée et resultat reste 1.
    for (int i = 0; i < b; ++i) {
        resultat *= a;
    }

    // Affichage avec le bon spécificateur (%lld)
    printf("Le resultat est : %lld\n", resultat);

    return 0;
}

```

```c
//14) Faktöriyel (güvenli aralık)
#include <stdio.h>

int main() {
    int nombre;
    int resultat = 1;

    printf("Entrez un nombre (0 <= n <= 12) : ");

    // Saisie sécurisée + Validation des limites
    if (scanf("%d", &nombre) != 1 || nombre < 0 || nombre > 12) {
        printf("Erreur : Valeur hors limites ou invalide.\n");
        return 1;
    }

    int n_original = nombre; // Çıktı ekranında kullanmak için orijinali sakla

    while (nombre > 0) {
        resultat *= nombre--;
    }

    printf("Factorielle: %d! = %d\n", n_original, resultat);

    return 0;
}


```

```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Entrez deux nombres entiers positifs : \n");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Erreur : Entrees invalides.\n");
        return 1;
    }

    int original_a = a;
    int original_b = b;

    // Algorithme d'Euclide
    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;
    }

    // Le resultat (PGCD) est stocké dans 'a'
    printf("Le PGCD de %d et %d est : %d\n", original_a, original_b, a);

    return 0;
}
// EKOK bulmak için ayrı bir döngü yazmaya, sistemi yormaya gerek yoktur. Matematiksel bir teorem bize der ki: İki sayının çarpımı, onların EBOB ve EKOK'larının çarpımına eşittir.$a \times b = PGCD(a,b) \times PPCM(a,b)$Dolayısıyla programın sonuna şu tek satırı eklemen yeterlidir:int ppcm = (original_a * original_b) / a;


```

```c
//16) Asal sayı mı?
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    // Règle 1 : Les nombres <= 1 ne sont pas premiers
    if (n <= 1) return false;

    // Règle 2 : Le cas du 2 est géré naturellement ou explicitement
    if (n == 2) return true;

    // Règle 3 : Optimisation mathématique exigée par l'énoncé
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false; // Un diviseur trouvé, ce n'est pas premier
        }
    }

    return true; // Aucun diviseur trouvé jusqu'à la racine carrée
}

int main() {
    int number;
    printf("Entrez un nombre: \n");
    if (scanf("%d", &number) != 1) return 1;

    // L'opérateur ternaire gère l'affichage direct
    printf("%s\n", isPrime(number) ? "Premier" : "Non Premier");

    return 0;
}

```

```c
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;
    printf("Entrez un num : \n");

    if (scanf("%d", &num) != 1) {
        return 1;
    }

    for (int i = 1; i <= num; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}

```

```c
//Çarpım tablosu (format önemli)
int main() {
    int num;
    do {
        printf("Entrez un nombre(1-10) : \n");
        if (scanf("%d", &num) != 1) {
            return 1;
        }

    }
    while (num < 1 || num>10);

    for (int i = 1; i <= 10; ++i) {
        printf("%d * %d = %d\n", num, i, num * i);
    }


    printf("\n\n\n");

    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            printf("%4d", i * j);
        }
        printf("\n");
    }


    return 0;
}


```

```c
#include <stdio.h>

int main() {
    int n;
    int count = 0;
    float sum = 0.0f; // float başlatırken 0.0f kullanmak iyi bir alışkanlıktır.

    // 1. Önce kaç sayı okuyacağımızı (N) alıyoruz
    printf("Entrez N, puis les nombres : \n");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erreur : N doit etre un entier positif.\n");
        return 1;
    }

    // 2. N defa dönecek okuma döngüsü
    for (int i = 0; i < n; ++i) {
        float val;

        // Lecture robuste (Sağlam okuma) kısmı:
        if (scanf("%f", &val) != 1) {
            // Kullanıcı sayı yerine harf girdiyse programı güvenle kapatıyoruz.
            printf("Erreur de lecture.\n");
            return 1;
        }

        // Sadece pozitif olanları filtrele
        if (val > 0.0f) {
            count++;
            sum += val;
        }
    }

    // Çıktı formatlaması: Yüzde nokta iki (%.2f)
    printf("Count: %d\n", count);
    printf("Somme: %.2f\n", sum);

    return 0;
}


```

```c


```

```c


```
