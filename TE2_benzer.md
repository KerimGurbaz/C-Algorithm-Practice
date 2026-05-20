```c
//1- Directives de préprocesseur
// Ajouter uniquement des directives de préprocesseur pour que le programme affiche la bonne ligne en fonction de l'existence et de la valeur du symbole A1

#include <stdio.h>


int main() {

    printf("A1 est défini et vaut 1 \n");

    printf("A1 est défini et vaut 2 \n");

    printf("A1 est défini mais ne vaut ni 1 ni 2 \n");

    printf("A1 n'est pas défini \n");
}

```

```c
// 2- Analyse d'erreurs dans des macros
// Dans le programme ci-contre, la macro SQUARE a été définie de manière maladroite, de sorte qu'elle n'est pas toujours équivalente à la fonction square

// Modifiez les définitions de ARG1 et ARG2 pour que le programme affiche
9 == 9
9 != 5
9 != -1

/src/main.c
#include <stdio.h>
#include "args.h"

#define SQUARE(x) x * x

int square(int x) {
   return x * x;
}

int main() {
   printf("%d == %d \n", square(3), SQUARE(3));
   printf("%d != %d \n", square(ARG1), SQUARE(ARG1));
   printf("%d != %d \n", square(ARG2), SQUARE(ARG2));
}

/src/args.h
#define ARG1 3
#define ARG2 3

```

```c
// 3- Lecture et affichage d'image depuis un fichier binaire
// Le fichier image1.img contient une image au format binaire codée selon le format suivant :

// 1 entier non signé sur 4 octets pour la largeur (W)
// 1 entier non signé sur 4 octets pour la hauteur (H)
// 1 entier non signé sur 4 octets pour le nombre de composantes par pixel, chacune codée sur 1 octet (BPP)
// les WxH pixels codés chacuns sur BPP octets, 1 octet par composante (3 octets pour des données RGB par exemple)
// Vous devez définir

// une structure Image qui permet de stocker ces informations
// une fonction read_image qui reçoit le nom du fichier en entrée et retourne une structure Image allouée dynamiquement
// une fonction image_info qui reçoit une image en entrée et affiche des informations sur son contenu
// La fonction read_image retourne NULL en cas d'échec de la lecture, par ailleurs, elle affiche quand c'est approprié les message suivants à la sortie d'erreur

// Impossible d'ouvrir le fichier
// Impossible de lire le header
// Impossible de lire les pixels
// Impossible d'allouer la mémoire
// Par ailleurs elle n'a pas de fuite de mémoire et laisse le ferme le fichier dans tous les cas.

// La fonction image_info affiche les informations sur le contenu de l'image. Par exemple
Taille: 10 x 10
BPP : 3
Valeur moyenne composante 0 : 6.020000
Valeur moyenne composante 1 : 13.500000
Valeur moyenne composante 2 : 112.660000
ou

Taille: 20 x 10
BPP : 1
Valeur moyenne composante 0 : 7.855000

/src/main.c
#include <stdlib.h>

// à définir par vous
struct Image;
struct Image *read_image(const char* filename);
void image_info(const struct Image* image);

// défini dans un fichier caché
void init_image_file();

int main() {
   init_image_file();

   struct Image *image = read_image("image1.img");
   if(image != NULL) {
      image_info(image);
      free(image);
   }
}

/src/image.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Image {
   // à définir
};

struct Image *read_image(const char *filename) {
     // à définir
}

void image_info(struct Image* image) {
     // à définir
}

```

```c
// 4- Test avec CUnit de l'application de lecture d'image
// Écrire un programme de tests unitaires en C avec CUnit pour valider uniquement les fonctions read_image() et image_info() du fichier image.c.

// La fonction init_image_file() pourra être utilisée pour préparer les fichiers de test, mais elle ne fait pas partie du périmètre à tester. Elle doit être considérée comme une boîte noire servant à générer des cas d’entrée.

// Travail demandé
// Les tests doivent vérifier :

// les cas de lecture correcte de read_image() ;
// les cas d’échec de read_image() ;
// les messages envoyés sur la sortie d’erreur par read_image() quand c’est pertinent ;
// le texte produit par image_info() ;
// l’absence de régression sur plusieurs fichiers générés par init_image_file().
// Contraintes
// Votre programme de tests doit :

// utiliser CUnit ;
// définir une ou plusieurs suites de tests ;
// contenir des tests distincts pour read_image() et pour image_info() ;
// ne pas chercher à tester le comportement interne de init_image_file() ;
// exécuter les tests avec l’interface Basic de CUnit.
// Organisation attendue
// On utilisera plusieurs suites/tests CUnit, avec :

// initialisation du registre par CU_initialize_registry() ;
// ajout des suites par CU_add_suite() ;
// ajout des tests par CU_add_test() ;
// exécution avec l’interface Basic, par exemple avec :
// CU_basic_set_mode(CU_BRM_VERBOSE);
// CU_basic_run_tests();
// nettoyage final avec CU_cleanup_registry().
// Important
// Le code source de init.c n’est pas fourni.
// Par conséquent, init_image_file() doit être utilisée uniquement pour préparer les données d’entrée nécessaires aux tests de read_image() et image_info(). Les assertions et les vérifications portent exclusivement sur le comportement observable de ces deux fonctions.

/src/main.c
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int main(void)
{

}

/src/image.c
struct Image {
   // à définir
};

struct Image *read_image(const char *filename) {
     // à définir
     return NULL;
}

void image_info(struct Image* image) {
     // à définir
/src/inputs.txt
0
1
2
3
4
5
6

```

```c
// TE2B-5 génération de blocs dans des fichiers binaires
// Compléter ce programme pour qu'il génère un bloc de données d'apparence aléatoire et le sauvegarde dans un fichier binaire.

// La fonction myrand() génère un byte d'apparence aléatoire ainsi:

// multiplie myrand_statepar la valeur seed passée en argument
// garde le résultat de la multiplication dans [0, SEED_MAX] par modulo
// remet à 0 les bytes de poids fort de myrand_state pour ne garder que le byte de poids faible
// Le programme doit gérer proprement les éventuelles entrées interactives, allocations mémoire et ouvertures de fichier.

// Le code fourni ne doit pas être supprimé, modifié ou étendu et les déclarations qui y sont effectuées doivent être utilisées comme attendu dans le code ajouté dans les parties à compléter.

// Les parties de code à compléter sont indiquées entre des commentaires de début et de fin de section.

// Les autres précisions utiles sur l'attendu sont fournies en commentaires dans le code fourni.

/src/teb_genblock.c
#include <stdio.h>
#include <stdlib.h>
#include "teb_block.h"

#define SEED_MAX 0x7FFFFFFF // Maximum value for the seed
#define LOW_BYTE_MASK 0xFF // Mask to get the low byte of the random number

static int myrand_state = 5669; // Internal state initialized with a constant
// value from https://en.wikipedia.org/wiki/List_of_prime_numbers

// Function to generate a pseudo-random number based on the seed
// and the internal state
int myrand(int seed) {

// *** COMPLETER ***

    return myrand_state;
}

int main(int argc, char *argv[]) {
    const char *filepath = argv[1];
    int seed = /*** COMPLETER ***/;
    int size = /*** COMPLETER ***/;
    unsigned char buffer[BLOCK_SIZE];
    FILE *f = NULL;

    // The program expects the name of the output file, a seed, and a block size
    // as arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <output_file> <seed> <bloc size>\n", argv[0]);
        return 1;
    }

    // Check that the seed is a positive integer less than SEED_MAX
    if ((seed < 1) || (seed > SEED_MAX)) {
        // Check if the seed is a positive integer
        fprintf(stderr, "Invalid seed. Must be a positive integer > 1.\n");
        return 1;
    }

    // Check that the block size is a positive integer less than BLOCK_SIZE
    if (size <= 0 || size > BLOCK_SIZE) {
        fprintf(stderr, "Invalid block size. Must be between 1 and %d.\n", BLOCK_SIZE);
        return 1;
    }

    // Open the output file for writing

// *** COMPLETER ***


    // Allocate a buffer for the block and fill it with random data

// *** COMPLETER ***


    // DEBUG: Print the generated block in a formatted way
    printf("Generated block:\n");
    for (int i = 0; i < size; ++i) {
        if (i % 16 == 0) {
            printf("buffer[%04d] = ", i);
            for (int j = 0; j < 16; j++) {
                if (i + j < size)
                    printf("%02X ", buffer[i + j]);
            }
            printf("\n");
        }
    }

    // Write the size of the block at the beginning of the file

// *** COMPLETER ***


    // Write the block to the file

// *** COMPLETER ***


    // properly terminate the program

// *** COMPLETER ***

    return 0;
}

/src/teb_block.h
#ifndef TEB_BLOCK_H
#define TEB_BLOCK_H

#define BLOCK_SIZE 4096  // Max size of the block to generate

#endif


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
