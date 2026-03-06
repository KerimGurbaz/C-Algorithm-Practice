// #include <stdio.h>

// int main() {
//     int n;

//     // 1. Girdi Alma (2pts - scanf / printf)
//     // Güvenlik: Kullanıcı pozitif bir sayı girene kadar döngüde tutuyoruz.
//     do {
//         printf("Entrez un entier positif : ");
//         if (scanf("%d", &n) != 1) {
//             printf("Erreur de saisie.\n");
//             // Eğer harf girilirse buffer'ı temizleme refleksimiz (Q3'ten hatırlarsın)
//             while(getchar() != '\n'); 
//             continue; 
//         }
//     } while (n <= 0);

//     // 2. Dizi Üretimi (3pts - génération de la suite correcte)
//     // Sayı 1'e ULAŞMADIĞI sürece döngüye devam et.
//     while (n > 1) {
//         printf("%d ", n); // Mevcut sayıyı formülü uygulamadan ÖNCE yazdır.

//         // Sayı çift mi? (Pair)
//         if (n % 2 == 0) {
//             n = n / 2;
//         } 
//         // Sayı tek mi? (Impair)
//         else {
//             n = 3 * n + 1;
//         }
//     }

//     // Döngü bittiğinde n artık 1'dir. Son sayıyı yazdırıp bitiriyoruz.
//     printf("1\n");

//     return 0;
// }


#include <stdio.h>

// int main() {
//     int n;
//     int count = 0;

//     do {
//         printf("Entrez un number\n");
//         if (scanf("%d", &n) != 1) {
//             printf("Erreur de saisie.\n");
//             while (getchar() != '\n');
//             continue;
//         }


//     }
//     while (n <= 0);

//     while (n > 1) {
//         printf("%d ", n);
//         if (n % 2 == 0) {
//             n /= 2;
//         } else {
//             n = 3 * n + 1;
//         }
//         ++count;
//     }

//     printf("Nomre d'etapes %d: %d", count, n);

//     return 0;
// }


// int main() {
//     int a, b;
//     int count = 0;

//     printf("Entrez premier number a\n");
//     if (scanf("%d", &a) != 1) {
//         return 1;
//     };


//     printf("Entrez deuxieme number b\n");
//     if (scanf("%d", &b) != 1) return 1;

//     for (int i = a; i <= b; ++i) {
//         if (i % 2 == 0) {
//             printf("%d ", i);
//             ++count;
//         }
//     }

//     printf("il y a %d numbers \n", count);


//     return 0;
// }

// int main() {
//     int a, b;
//     int somme = 0;

//     printf("entrez premier number a\n");
//     if (scanf("%d", &a) != 1) return 1;
//     printf("entrez premier number b\n");
//     if (scanf("%d", &b) != 1) return 1;

//     if (a > b) {
//         int temp = b;
//         b = a;
//         a = temp;
//     }

//     for (int i = a; i <= b; ++i) {
//         if (i % 3 == 0 || i % 5 == 0) {
//             somme += i;
//             printf("%d ", i);
//         }
//     }
//     printf("\nsomme = %d\n", somme);



//     return 0;
// }


// #include <stdio.h>
// #include <limits.h>

// int main() {
//     int nombres, val;
//     int count = 1;
//     printf("Vous-voulez Combien de valeur  entre\n");
//     scanf("%d", &nombres);
//     int min = INT_MAX;
//     int max = INT_MIN;

//     while (nombres > 0) {

//         printf("votre %d. number est : ", count++);
//         scanf("%d", &val);
//         printf("%d\n", val);
//         if (val >= max) {
//             max = val;
//         }
//         if (val <= min) {
//             min = val;
//         }
//         --nombres;
//     }

//     printf("Maximum Integer Value: %d\n", max);
//     printf("Minimum Integer Value: %d\n", min);

//     return 0;
// }


// #include <stdio.h>
// #include <limits.h>

// int main() {
//     int n, val;
//     int min, max;

//     printf("Combien de valeurs voulez-vous entrer ? ");
//     if (scanf("%d", &n) != 1 || n <= 0) {
//         printf("Erreur :  n doit etre positif.\n");
//         return 1;
//     }

//     printf("Valeur 1 : ");
//     scanf("%d", &val);
//     min = val;
//     max = val;

//     for (int i = 2; i <= n; ++i) {
//         printf("Valeur %d :", i);
//         scanf("%d", &val);

//         if (val > max) {
//             max = val;
//         }if (val < min) {
//             min = val;
//         }
//     }
//     printf("\nMax : %d", max);
//     printf("\nMin : %d\n", min);
//     return 0;
// }


#include <stdio.h>

// int main() {
//     int val, count;
//     printf("Vous-voulez entre combien de nombres : ");
//     int somme = 0;

//     if (scanf("%d", &count) != 1 || count <= 0) {
//         printf("Erreur");
//         return 1;
//     }

//     for (int i = 1; i <= count; ++i) {
//         printf("Entrez votre %d. number : ", i);
//         scanf("%d", &val);
//         somme += val;
//     }

//     printf("Moyenne de %d number est %.2f :", count, (float)somme / count);

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int val;
//     int nb_elements = 0;
//     long long somme = 0;

//     printf("Entrez des nombres(0 pour arreter) : \n");

//     while (1) {
//         printf("Valeur %d : ", nb_elements + 1);

//         if (scanf("%d", &val) != 1) {
//             printf("Erreur de saisie.\n");
//             while (getchar() != '\n');
//             continue;
//         }

//         if (val == 0) {
//             break;
//         }
//         somme += val;
//         nb_elements++;
//     }

//     if (nb_elements == 0) {
//         printf("Aucun nombre n'a ete saisi.\n");
//     } else {
//         printf("\nVous avet entre %d nombre%s.\n", nb_elements, (nb_elements > 1 ? "s" : ""));
//         printf("La somme totale est %lld\n", somme);
//     }

//     return 0;
// }


#include <stdio.h>

// int main() {
//     int nb_elements = 0;
//     int val;
//     long long int somme = 0;

//     while (1) {
//         printf("Entrez votre number : ");
//         if (scanf("%d", &val) != 1) {
//             printf("Erreur de saisi\n");
//             while (getchar() != '\n');
//             continue;
//         }
//         if (val < 0) {
//             break;
//         } else {
//             somme += val;
//             ++nb_elements;
//         }

//     }

//     float moyenne = (float)somme / nb_elements;

//     if (somme) {
//         printf("\nEntrez %d number positif et moyenne est %.2f ", nb_elements, moyenne);
//     } else {
//         printf("Aucune valeur\n");
//     }

//     return 0;

// }


// int main() {
//     int nb_elements = 0;
//     int val;
//     long long somme = 0;

//     printf("Entrez des nombres(negatif pour arreter) : \n");

//     while (1) {
//         printf("Valeur %d : ", nb_elements + 1);
//         if (scanf("%d", &val) != 1) {
//             printf("Erreur de saisie.\n");
//             while (getchar() != '\n');
//             continue;
//         }

//         if (val < 0) {
//             break;
//         }

//         somme += val;
//         nb_elements++;
//     }

//     if (nb_elements > 0) {
//         float moyenne = (float)somme / nb_elements;
//         printf("\nVous avez entre %d nombre(s) positif(s).\n");
//         printf("La moyenne est %.2f\n", moyenne);
//     } else {
//         printf("Aucune Valeur\n");
//     }

//     return 0;
// }


// int main() {
//     int val;
//     int bas = 0;

//     printf("Entrez votre number : ");
//     if (scanf("%d", &val) != 1) {
//         while (getchar() != '\n');
//     };
//     int temp = val;
//     if (temp == 0) {
//         bas = 1;
//     } else {
//         while (temp > 0) {
//             temp /= 10;
//             ++bas;
//         }
//     }


//     printf("%d => %d\n", val, bas);
//     return 0;
// }

// int main() {
//     int val;
//     printf("entrez votre valeur : ");
//     if (scanf("%d", &val) != 1) {
//         while (getchar() != '\n');
//     }
//     int somme = 0;
//     int orj = val;

//     if (val < 0) {
//         val = -val;
//     }

//     while (val > 0) {
//         int last_element = val % 10;
//         somme += last_element;
//         val /= 10;
//     }

//     printf("\nLa somme de valeur %d est %d \n", orj, somme);
//     return 0;
// }

// int main() {
//     int val;
//     long long inverse = 0;

//     printf("Entrez un nobre entier : ");
//     if (scanf("%d", &val) != 1) {
//         printf("Erreur de saisie.\n");
//         while (getchar() != '\n');
//         return 1;
//     }

//     int orj = val;

//     int signe = (val < 0) ? -1 : 1;
//     if (val < 0) val = -val;

//     while (val > 0) {
//         int reste = val % 10;
//         inverse = (inverse * 10) + reste;
//         val /= 10;
//     }

//     long long resultat_final = inverse * signe;

//     printf("%d => %lld\n", orj, resultat_final);


//     return 0;
// }

// #include <stdbool.h>

// bool estPalindrom(const int a, const int b) {
//     return a == b;

// }


// int main() {
//     int val;
//     printf("entrez un number");
//     if (scanf("%d", &val) != 1) {
//         while (getchar() != '\n');
//         return 1;
//     }

//     int inverse = 0;
//     int orj = val;

//     while (val > 0) {
//         int reste = val % 10;
//         inverse = inverse * 10 + reste;
//         val /= 10;
//     }

//     printf(estPalindrom(orj, inverse) ? "Oui" : "Non");


//     return 0;
// }


// int main() {
//     int a, b;
//     long long resultat = 1;
//     printf("Pour a**b Etre a et b : ");
//     if (scanf("%d%d", &a, &b) != 2) {
//         while (getchar() != '\n');
//         return 1;
//     }

//     for (int i = 0; i < b; ++i) {
//         resultat *= a;
//     }

//     if (b == 0) {
//         printf("la resultat : 1");
//     } else {
//         printf("Le resultat est %d ", resultat);
//     }
//     return 0;
// }


// int main() {
//     int resultat = 1;
//     int nombre;
//     printf("Entrez un numbre : \n");
//     if (scanf("%d", &nombre) != 1 || nombre < 0 || nombre>12) {
//         printf("Erreur : Valeur hors limites ou invalide.\n");
//         return 1;
//     }

//     int n_orj = nombre;


//     while (nombre > 0) {
//         resultat *= nombre--;
//     }

//     printf("Factorielle: %d! = %d\n", n_orj, resultat);

//     return 0;

// }


// int main() {

//     int a, b, r;
//     printf("Entrez deux  integer valeurs : ");
//     if (scanf("%d%d", &a, &b) != 2) {
//         while (getchar() != '\n');
//         return 1;
//     }

//     while (b != 0) {
//         r = a % b;
//         a = b;
//         b = r;
//     }

//     printf("%d", a);
//     return 0;
// }

// #include <stdbool.h>

// bool isPrime(int n) {
//     if (n <= 1) return false;

//     if (n == 2) return true;

//     for (int i = 2; i * i <= n; ++i) {
//         if (n % i == 0) {
//             return false;
//         }
//     }

//     return true;
// }

// int main() {

//     int number;

//     printf("Entrez un number: \n");
//     if (scanf("%d", &number) != 1) {
//         return 1;
//     }


//     printf("%s\n", isPrime(number) ? "Premier" : "Non Premier");

//     return 0;
// }
// #include <stdio.h>
// #include <stdbool.h>

// bool isPrime(int n) {
//     if (n <= 1) return false;
//     if (n == 2) return true;

//     for (int i = 2; i * i <= n; ++i) {
//         if (n % i == 0) {
//             return false;
//         }
//     }

//     return true;
// }

// int main() {
//     int num;
//     printf("Entrez un num : \n");

//     if (scanf("%d", &num) != 1) {
//         return 1;
//     }

//     for (int i = 1; i <= num; ++i) {
//         if (isPrime(i)) {
//             printf("%d ", i);
//         }
//     }

//     return 0;
// }

// int main() {
//     int num;
//     do {
//         printf("Entrez un nombre(1-10) : \n");
//         if (scanf("%d", &num) != 1) {
//             return 1;
//         }

//     }
//     while (num < 1 || num>10);

//     for (int i = 1; i <= 10; ++i) {
//         printf("%d * %d = %d\n", num, i, num * i);
//     }


//     printf("\n\n\n");

//     for (int i = 1; i <= 10; ++i) {
//         for (int j = 1; j <= 10; ++j) {
//             printf("%4d", i * j);
//         }
//         printf("\n");
//     }


//     return 0;
// }


int main() {
    int val;

    do {
        printf("Entre un valeur : \n");
        if (scanf("%d", &val) != 1) {
            while (getchar() != '\n');
            continue;
        }
    }
    while (val < 1 || val>20);


    for (int i = 0; i < val; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf(" * ");
        }
        printf("\n");
    }
}
