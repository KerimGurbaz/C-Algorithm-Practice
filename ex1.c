#include <stdio.h>

double resultat;


int main() {
    int a = 15, b = 10;

    float r1 = 25.5f, r2 = 5.2f;

    resultat = a + b;
    printf("Addition : %d + %d = %.2f\n", a, b, resultat);

    resultat = r1 - r2;
    printf("Soustraction: %.2f - %.2f = %.2f\n", r1, r2, resultat);

    resultat = a * b;
    printf("Multiplication : %d * % d = %.2f\n", a, b, resultat);

    resultat = r1 / r2;
    printf("Division : %.2f / %.2f = %.2f\n", r1, r2, resultat);
}
