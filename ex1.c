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

#include <stdbool.h>

bool estPalindrom(const int a, const int b) {
    return a == b;

}


int main() {
    int val;
    printf("entrez un number");
    if (scanf("%d", &val) != 1) {
        while (getchar() != '\n');
        return 1;
    }

    int inverse = 0;
    int orj = val;

    while (val > 0) {
        int reste = val % 10;
        inverse = inverse * 10 + reste;
        val /= 10;
    }

    printf(estPalindrom(orj, inverse) ? "Oui" : "Non");


    return 0;
}
