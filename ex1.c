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


#include <stdio.h>

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

int main() {

    printf("Entrez des nombres pour additionner(0 pour terminer): \n");
    int num = 0;
    int sum = 0;


    while (num != 0) {
        scanf("%d", &num);
        sum += num;
    }


    printf("La somme des nobres est: %d", sum);

    return 0;
}
