#include <stdio.h>

// int main() {

//     int n;

//     if (scanf("%d", &n) != 1 || n <= 0) {
//         return 1;
//     }

//     int tab[n];
//     int count = 0;

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) {
//             return 1;
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         if (tab[i] % 2 == 0) {
//             count++;
//         }
//     }


//     printf("il y a %d valeurs paires\n ", count);
// }


// int main() {

//     int num;
//     int pos = 0;
//     int neg = 0;
//     int zero = 0;

//     if (scanf("%d", &num) != 1 || num <= 0) {
//         return 1;
//     }
//     int tab[num];

//     for (int i = 0; i < num; ++i) {

//         if (scanf("%d", &tab[i]) != 1) {
//             return 1;
//         }
//     }

//     for (int i = 0; i < num; ++i) {
//         if (tab[i] > 0) {
//             ++pos;
//         } else if (tab[i] < 0) {
//             ++neg;
//         } else {
//             ++zero;
//         }

//     }

//     printf("Positives : %d\n", pos);
//     printf("Negatives : %d\n", neg);
//     printf("Zeros : %d\n", zero);

// }


// int main() {

//     int number;
//     if (scanf("%d", &number) != 1 || number<=0) {
//         return 1;
//     }

//     int tab[number];

//     for (int i = 0; i < number; ++i) {

//         if (scanf("%d", &tab[i]) != 1)return 1;
//     }

//     for (int i = number - 1; i >= 0; --i) {
//         printf("%d ", tab[i]);
//     }


//     return 0;
// }

#include <stdio.h>
#include <stdbool.h>

// int main() {
//     int number;
//     if (scanf("%d", &number) != 1 || number <= 0)return 1;

//     int tab1[number];

//     for (int i = 0; i < number; ++i) {
//         if (scanf("%d", &tab1[i]) != 1)return 1;
//     }
//     int tab2[number];
//     for (int i = 0; i < number; ++i) {
//         tab2[i] = tab1[i];
//     }
//     printf("\nTab1 : ");
//     for (int i = 0; i < number; ++i) {
//         printf("%d ", tab1[i]);
//     }
//     printf("\nTab2 : ");
//     for (int i = 0; i < number; ++i) {
//         printf("%d ", tab2[i]);
//     }

//     return 0;
// }

// void somme_tableaux(const int *t1, const int *t2, int *t3, int n) {
//     for (int i = 0; i < n; ++i) {
//         t3[i] = t1[i] + t2[i];
//     }
// }


// int main() {
//     int num;
//     printf("Entrez la taille des tableaux : \n");
//     if (scanf("%d", &num) != 1 || num <= 0) return 1;

//     int tab1[num], tab2[num], tab3[num];

//     printf("Saisie du tableau 1 : \n");
//     for (int i = 0; i < num; ++i) {
//         if (scaf("%d", &tab1[i]) != 1) return 1;
//     }
//     printf("Saisie du tableau 2 : \n");
//     for (int i = 0; i < num; ++i) {
//         if (scaf("%d", &tab2[i]) != 1) return 1;
//     }

//     somme_tableaux(tab1, tab2, tab3, num);

//     printf("Tableau somme \n");
//     for (int i = 0; i < num; ++i) {
//         printf("%d ", tab3[i]);
//     }
//     printf("\n");



//     return 0;
// }

// int produit_tab(const int tab1[], const int tab2[], const int n) {
//     int total = 0;
//     for (int i = 0; i < n; ++i) {
//         total += tab1[i] * tab2[i];
//     }
//     return total;
// }


// int main() {

//     int num;

//     printf("Entrez un number : \n");
//     if (scanf("%d", &num) != 1 || num <= 0)return 1;

//     int tab1[num], tab2[num];

//     printf("Saisie du tableau 1 : \n");
//     for (int i = 0; i < num; ++i) {
//         if (scanf("%d", &tab1[i]) != 1) return 1;
//     }


//     printf("Saisie du tableau 2 : \n");
//     for (int i = 0; i < num; ++i) {
//         if (scanf("%d", &tab2[i]) != 1) return 1;
//     }

//     int somme = produit_tab(tab1, tab2, num);

//     printf("Produit scalaire : %d", somme);
//     return 0;
// }


// #include <stdio.h>
// #include <stdbool.h>

// bool trouve(const int *t, int n, int x) {
//     for (int i = 0; i < n; ++i) {
//         if (t[i] == x) {
//             return true;
//         }
//     }
//     return false;
// }


// int main() {

//     int n;
//     printf("Saisie un nober de tableau :  \n");

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int tab[n];

//     for (int i = 0; i < n; ++i) {

//         printf("entrez your %d. number is : \n", i + 1);
//         if (scanf("%d", &tab[i]) != 1) return 1;
//     }

//     int x;

//     printf("entrez un number qui vouz voulez trouve : \n");
//     if (scanf("%d", &x) != 1) return 1;

//     trouve(tab, n, x) ? printf("%s", "valeur trouve") : printf("%s", "valeur absente");

//     return 0;

// }

// int trouve(const int tab[], int n, int x) {
//     int debut = 0;
//     int fin = n - 1;

//     while (debut <= fin) {
//         int milleu = debut + (fin - debut) / 2;
//         if (tab[milleu] == x) {
//             return milleu;
//         }
//         if (x > tab[milleu]) {
//             debut = milleu + 1;
//         } else {
//             fin = milleu - 1;
//         }
//     }
//     return -1;
// }


// int main() {

//     int n;
//     printf("Saisie un nober de tableau :  \n");

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int tab[n];

//     for (int i = 0; i < n; ++i) {

//         printf("entrez your %d. number is : \n", i + 1);
//         if (scanf("%d", &tab[i]) != 1) return 1;
//     }
//     int x;

//     printf("Entrez une valuer que vous voulez trouve : \n");
//     if (scanf("%d", &x) != 1) return 1;

//     if (trouve(tab, n, x) != -1) {
//         printf("Indice : %d", trouve(tab, n, x));
//     } else {
//         printf("%d", -1);
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdbool.h>

// bool est_trie(const int tab[], int n) {
//     for (int i = 1; i < n; ++i) {
//         if (tab[i - 1] > tab[i]) return false;
//     }
//     return true;
// }

// int main() {

//     int n;
//     printf("Saisie un nober de tableau :  \n");

//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int tab[n];

//     for (int i = 0; i < n; ++i) {

//         printf("entrez your %d. number is : \n", i + 1);
//         if (scanf("%d", &tab[i]) != 1) return 1;
//     }

//     printf("%s", est_trie(tab, n) ? "Trie" : "Non trie");



//     return 0;
// }

// void suprimer_doublon(int tab[], int n) {


//     for (int i = 1; i < n; ++i) {
//         if (tab[i] != tab[i + 1]) {
//             printf("%d ", tab[i]);
//         }
//     }
// }


// int main() {
//     int n;

//     printf("Entrez un number \n");
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int tab[n];

//     for (int i = 0; i < n; ++i) {
//         printf("\nEntrez %d. number ", i + 1);
//         if (scanf("%d", &tab[i]) != 1) return 1;
//     }

//     suprimer_doublon(tab, n);

// }

// void decaler(int tab[], int n) {
//     for (int i = n - 1; i > 0; --i) {

//         tab[i] = tab[i - 1];

//     }

//     tab[0] = 0;
//     for (int i = 0; i < n; ++i) {
//         printf("%d ", tab[i]);
//     }
// }

// int main() {
//     int n;
//     printf("Entrez un numbre : \n");
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int tab[n];

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) return 1;
//     }

//     decaler(tab, n);
// }

// void inverser(int t[], int n) {
//     int left = 0;
//     int right = n - 1;

//     while (left < right) {
//         int temp = t[left];
//         t[left] = t[right];
//         t[right] = temp;
//         ++left;
//         --right;
//     }
//     for (int i = 0; i < n; ++i) {
//         printf("%d ", t[i]);
//     }

// }

// int main() {

//     int n;
//     printf("Entrez un numbre : \n");
//     if (scanf("%d", &n) != 1 || n <= 0) return 1;

//     int tab[n];

//     for (int i = 0; i < n; ++i) {
//         if (scanf("%d", &tab[i]) != 1) return 1;
//     }

//     inverser(tab, n);
// }

int annexe(const int tab[], int n, float m) {
    int comteur = 0;
    for (int i = 0; i < n; ++i) {

        if (tab[i] > m) {
            ++comteur;
        }
    }
    return comteur;
}

int main() {

    int n;
    printf("Entrez un numbre : \n");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int tab[n];
    float somme = 0.0f;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
        somme += tab[i];
    }


    float moyenne = somme / n;

    int an_super = annexe(tab, n, moyenne);

    printf("\nMoyenne : %.2f\n", moyenne);
    printf("\nValeurs superieures a la moyenne :%d", an_super);

    return 0;
}
