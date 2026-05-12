#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


// int countc(FILE *f) {
//     int count = 0;

//     while (fgetc() != EOF) {
//         count++;
//     }
//     return count;
// }


// int countw(FILE *f) {
//     int count = 0;
//     int c;
//     bool in_word = false;

//     while ((c = fgetc(f)) != EOF) {
//         if (isspace(c)) {
//             in_word = false;
//         } else if (!in_word) {
//             in_word = true;
//             count++;
//         }
//     }
//     return count;
// }

// int countl(FILE *f) {
//     int count = 0;
//     int c;
//     while ((c = fgetc(f)) != EOF) {
//         if (c == '\n') {
//             ++count;
//         }
//     }
//     return count;
// }
// #include <stdio.h>

// typedef struct{
//     int id;
//     char nom[50];
//     char prenom[50];
//     float moyenne;
// }etudiant;

// int compter_etudiants(const char* filename){
//     FILE *f = fopen(filename, "rb");
//     if(!f){
//         return -1;
//     }

//     fseek(f, 0, SEEK_END);

//     long total = ftell(f);

//     fclose(f);

//     return (int)(total)/sizeof(etudiant);
// }
// #include <stdio.h>
// #include <errno.h>

// typedef struct {
//     int id;
//     char nom[50];
//     char prenom[50];
//     float moyenne;
// }etudiant;

// void lire_etudiant_index(const char *filename, int index) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {
//         perror("introuvable..");
//         return;
//     }

//     fseek(f, 0, SEEK_END);
//     long taille = ftell(f);
//     int nbEtudiant = (int)(taille) / sizeof(etudiant);

//     if (index < 0 || index >= nbEtudiant) {
//         perror("invalid index");
//         return;
//     }

//     etudiant student;

//     fseek(f, index * sizeof(etudiant), SEEK_SET);

//     fread(&student, sizeof(etudiant), 1, f);
//     printf("ID : %d\n", student.id );
//     printf("nom : %s\n", student.nom );
//     printf("ID : %s\n", student.prenom );
//     printf("Moyenne : %.2f\n", student.moyenne );


//     fclose(f);
// }

// #include <stdio.h>
// #include <errno.h>

// typedef struct {
//     int id;
//     char nom[50];
//     char prenom[50];
//     float moyenne;
// }etudiant_t;

// void mettre_A_jour_moyenne(const char*filename, int id, float nouvelle_moyenne){
//     FILE *f = fopen(filename, "r+b");
//     if(f ==NULL){
//         perror("Error..");
//         return;
//     }
//     etudiant_t student;
//     while(fread(&student, sizeof(etudiant_t), 1, f) ==1){
//         if(student.id == id){
//             student.moyenne = nouvelle_moyenne;
//             fseek(f, -(long)sizeof(etudiant_t), SEEK_CUR);
//             fwrite(&student, sizeof(etudiant_t), 1, f);
//             printf("mettre a jour moyenne %.2f", student.moyenne);
//             break;
//         }
//     }

//     fclose(f);

//     }


#include <stdio.h>
#include <errno.h>

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
}etudiant_t;

void lire_a_rebours(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Error ... ");
        return;
    }

    fseek(f, 0, SEEK_END);
    long taille = ftell(f);
    int nb_etudiant = (int)taille / sizeof(etudiant_t);

    etudiant_t student;

    for (int i = nb_etudiant - 1; i >= 0; --i) {
        fseek(f, i * sizeof(etudiant_t), SEEK_SET);
        fread(&student, sizeof(etudiant_t), 1, f);

        printf("ID %d\n", student.id);
        printf("nom %s\n", student.nom);
        printf("ID %s\n", student.prenom);
        printf("ID %.2f\n", student.moyenne);
    }

    fclose(f);
}
