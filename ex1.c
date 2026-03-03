#include <stdio.h>

// int main() {
    // char prenom[50];
    // int age;

    // printf("Entrez votre prenom : ");
    // scanf("%49s", prenom);

    // printf("Entrez votre age : ");
    // scanf("%d", age);

    // printf("Bienvenu %s, vous avez %d ans.\n", prenom, age);


    // int nombre;
    // printf("Entrez un nombre: ");
    // scanf("%d", &nombre);

    // if ((nombre % 3 == 0) && (nombre % 13 == 0)) {
    //     printf("%d est divisible par 3 et 13\n", nombre);
    // } else {
    //     printf("%d n'est pas divisible par 3 et 13 a la fois\n", nombre);
    // }

    // return 0;

    // int x, y, z;
    // scanf("%d%d%d", &x, &y, &z);

    // if (x > y) {
    //     if (x > z) {
    //         printf("Le maximum est : %d\n", x);
    //     } else {
    //         printf("Le maximum est : %d\n", z);
    //     }
    // } else if (y > z) {
    //     printf("Le maximum est : %d\n", y);
    // } else {
    //     printf("Le maximum est : %d\n", z);
    // }


    // int num;
    // printf("entre un numbre");
    // scanf("%d", &num);

    // switch (num) {
    // case 1:printf("Lundi");
    //     break;
    // case 2:printf("Mardi");
    //     break;
    // case 3:printf("Mecredi");
    //     break;
    // case 4:printf("Jeudi");
    //     break;
    // case 5:printf("Vendredi");
    //     break;
    // case 6:printf("Samedi");
    //     break;
    // case 7:printf("Dimance");
    //     break;
    // default: printf("Error");
    // }

    // int day;
    // const char *days[] = { "Lundi", "Mardi", "Mercredi",
    //     "Jeudi", "Vendredi", "Samedi", "Dimanche" };

    // printf("Saisir le numero du jour (1-7)");
    // scanf("%d", &day);

    // if (day >= 1 && day <= 7) {
    //     printf("%s\n", days[day - 1]);
    // } else {
    //     printf("Erreur: numero invalide.\n");
    // }

    // return 0;




// }

// #include <stdio.h>

// int minOperation(int *nums, int numsSize, int k) {
//     long long sum = 0;

//     for (int i = 0; i < numsSize; ++i) {
//         sum += nums[i];
//     }

//     return (int)(sum % k);
// }


// int main() {
//     int nums1[] = { 3, 7, 9 };

//     int k1 = 5;

//     printf("Output : %d\n", minOperation(nums1, 3, k1));

//     return 0;
// }


// #include <stdio.h>

// int main() {
//     double num1, num2;

//     char op;

//     printf("Entrez l'operation(ex : 7-2): ");

//     if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
//         printf("Erreur : Format d'entree invalide.\n");
//         return 1;
//     }

//     switch (op) {
//     case '+': printf("Resultat : %.2lf\n", num1 + num2);
//         break;
//     case '-': printf("Resultat : %.2lf\n", num1 - num2);
//         break;

//     case '*': printf("Resultat : %.2lf\n", num1 * num2);
//         break;

//     case '/': if (num2 == 0) {
//         printf("Erreur: division par zero.\n");
//     } else {
//         printf("Resultat : %.2lf\n", num1 / num2);
//     }
//             break;

//     default:
//         printf("Erreur : operateur invalide.\n");
//     }

//     return 0;
// }


// // #include <stdio.h>

// int main() {
//     int num;

//     scanf("%d", &num);
//     for (int i = 1;i <= 10; ++i) {
//         printf("%d * %d = %d \n", num, i, num * i);
//     }


//     return 0;
// }

// int main() {
//     int somme = 0;

//     for (int i = 1; i <= 100; ++i) {
//         somme += i;
//     }

//     printf("La somme est : %d\n", somme);



//     return 0;
// }

// int main() {

//     printf("Entrez des nombres pour additionner(0 pour terminer): \n");
//     int num = -11;
//     int sum = 0;


//     while (num != 0) {
//         scanf("%d", &num);
//         sum += num;
//     }


//     printf("La somme des nobres est: %d", sum);

//     return 0;
// }
// #include <limits.h>
// #include <stdio.h>

// int main() {
//     int num;
//     int maxNumber;

//     printf("Entrez des nombres pour trouver le maximum (-1 pour terminer):\n");

//     scanf("%d", &num);

//     if (num == -1) {
//         printf("Aucun nombre saisi.\n");
//         return  0;
//     }

//     maxNumber = num;

//     while (1) {
//         scanf("%d", &num);
//         if (num == -1) {
//             break;
//         }
//         if (num > maxNumber)
//             maxNumber = num;
//     }

//     printf("Le plus grand nombre est %d\n", maxNumber);
//     return 0;
// }


// #include <stdio.h>

// int main() {

//     int age;

//     do {
//         printf("saisir votre age : ");
//         scanf("%d", &age);

//     }
//     while (age < 18);

//     printf("Acces accorde.");

//     return 0;
// }

#include <stdio.h>

// int main() {
//     int num;
//     int result = 0;

//     scanf("%d", &num);

//     while (num > 0) {
//         int res = num % 10;
//         result = result * 10 + res;
//         num /= 10;
//     }

//     printf("%d", result);


//     return 0;
// }


// int main() {
//     int num, result = 0;
//     printf("Entrez un nombre pour inverser ses chiffres: ");
//     scanf("%d", &num);

//     do {
//         int res = num % 10;
//         result = result * 10 + res;
//         num /= 10;
//     }
//     while (num != 0);
//     printf("Le nombre inversé est: %d\n", result);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main() {

//     int nombre = 42;
//     int *ptr;
//     ptr = &nombre;


//     printf("La vlaeur de nombre est : %d\n", *ptr);

//     return 0;
// }


// int main() {

//     // char nom;
//     // int age;

//     // char *ptr_nom = &nom;
//     // int *ptr_age = &age;

//     // char **ptr_ptr_nom = &ptr_nom;
//     // int **ptr_ptr_age = &ptr_age;

//     // **ptr_ptr_nom = 'V';

//     // **ptr_ptr_age = 31;

//     // printf("Nom (Initiale) : %c\n", nom);

//     // printf("Age : %d\n", age);

//     // return 0;
// }

#include <stdio.h>


// int main() {

//     char mem[40] = {
//         0,0,0,0,0,0,0,0,0,0,
//         'M','A', 'R', 'D','I','\0',
//         0,0,0,0,
//         'L','U','N','D','I','\0',
//         0,0,0,0,
//         'M','E','C','R','E','D','I','\0',
//         0
//     };

//     char *jours[3];
//     jours[0] = &mem[20];
//     jours[1] = &mem[10];
//     jours[2] = &mem[30];

//     for (int i = 0; i < 3; ++i) {
//         printf("%s\n", jours[i]);
//     }

//     char s[4] = { 'A', 'B', 'C' ,'\0' };
//     printf("%s", s);

//     return 0;


// }


// int main() {
//     char memoire[5][10] = { 0 };

//     sprintf(&memoire[1][4], "Mardi");
//     sprintf(&memoire[2][3], "Lundi");
//     sprintf(&memoire[4][0], "Mecredi");

//     char *jours_semaine[3];

//     jours_semaine[2] = &memoire[4][0];
//     jours_semaine[0] = &memoire[2][3];
//     jours_semaine[1] = &memoire[1][4];


//     printf("Les premiers jours de la semaine : \n");

//     for (int i = 0; i < 3; ++i) {
//         printf("- %s\n", jours_semaine[i]);
//     }

//     return 0;
// }


#include <stdio.h>

// int main(void) {

//     char array[60];
//     char *ptr;
//     char *strs[3];
//     int i;

//     ptr = array;
//     sprintf(ptr, "%s", "Mercredi");

//     strs[2] = ptr;

//     ptr += 28;
//     sprintf(ptr, "%s", "Lundi");

//     strs[0] = ptr;

//     ptr = array + 42;
//     sprintf(ptr, "%s", "Mardi");

//     strs[1] = ptr;

//     for (i = 0; i < 3; i++)
//         printf("%s\n", strs[i]);

// } 


#include <stdio.h>
#define SIZE 20

void somme_tableaux(int a[], int b[], int resault[], int size) {
    for (int i = 0; i < size; ++i) {
        resault[i] = a[i] + b[i];
    }
}

void afficher(int t[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main() {
    int tab1[SIZE];
    int tab2[SIZE];
    int tab3[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        tab1[i] = i;
        tab2[i] = i * 2;
    }

    somme_tableaux(tab1, tab2, tab3, SIZE);

    printf("Tableau 1 : ");
    afficher(tab1, SIZE);

    printf("Tableau 2 : ");
    afficher(tab2, SIZE);

    printf("Tableau 3 (SOMME) : ");
    afficher(tab3, SIZE);

    return 0;
}
