#include <stdio.h>

int main() {
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

    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);

    if (x > y) {
        if (x > z) {
            printf("Le maximum est : %d\n", x);
        } else {
            printf("Le maximum est : %d\n", z);
        }
    } else if (y > z) {
        printf("Le maximum est : %d\n", y);
    } else {
        printf("Le maximum est : %d\n", z);
    }

}
