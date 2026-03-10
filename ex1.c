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


int main() {

    int num;
    int pos = 0;
    int neg = 0;
    int zero = 0;

    if (scanf("%d", &num) != 1 || num <= 0) {
        return 1;
    }
    int tab[num];

    for (int i = 0; i < num; ++i) {

        if (scanf("%d", &tab[i]) != 1) {
            return 1;
        }
    }

    for (int i = 0; i < num; ++i) {
        if (tab[i] > 0) {
            ++pos;
        } else if (tab[i] < 0) {
            ++neg;
        } else {
            ++zero;
        }

    }

    printf("Positives : %d\n", pos);
    printf("Negatives : %d\n", neg);
    printf("Zeros : %d\n", zero);

}
