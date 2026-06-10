#include <stdio.h>



// void fibo(int n);
// int main() {
//     int count = 0;
//     int n;
//     printf("Entrez un value\n");
//     if (scanf("%d", &n) != 1) return 1;
//     fibo(n);
//     printf("\n");

//     return 0;
// }

// void fibo(int n) {
//     int premier = 0;
//     int seconde = 1;

//     if (n >= 1) printf("%d ", premier);
//     if (n >= 2)printf("%d ", seconde);

//     for (int i = 3; i <= n; ++i) {
//         int suivant = premier + seconde;
//         printf("%d ", suivant);
//         premier = seconde;
//         seconde = suivant;
//     }
// }

// void trouver_min_max(const int tab[], int size, int *mn, int *mx) {
//     for (int i = 1; i < size;++i) {
//         if (tab[i] > *mx) {
//             *mx = tab[i];
//         }
//         if (tab[i] < *mn) {
//             *mn = tab[i];
//         }
//     }
// }


// int main() {

//     int tab[] = { 12, 5, 8, 19, 1, 7 };
//     int size = sizeof(tab) / sizeof(tab[0]);
//     int minVal = tab[0];
//     int maxVal = tab[0];

//     trouver_min_max(tab, size, &minVal, &maxVal);
//     printf("min_value = %d \n", minVal);
//     printf("max_value = %d \n", maxVal);

//     return 0;
// }

// void supprimer_espaces(char *str) {
//     char *p_left = str;
//     char *p_right = str;

//     while (*p_right != '\0') {

//         if (*p_right != ' ') {
//             *p_left = *p_right;
//             p_left++;
//             p_right++;
//         } else {
//             p_right++;
//         }

//     }
//     *p_left = '\0';

// }

// int main() {
//     char str[] = "Programmation en C";
//     printf("%s\n", str);
//     supprimer_espaces(str);
//     printf("%s\n", str);
//     return 0;
// }

// #include <stdlib.h>

// int main() {
//     int n = 0;
//     int capacty = 2;
//     int valeur;

//     int *tab = malloc(capacty * sizeof(int));
//     if (tab == NULL) {
//         fprintf(stderr, "Erreur allocation memoire");
//         return 1;
//     }
//     printf("Entrez des nombres positifs (négatif pour arrêter):\n");
//     while (1) {
//         printf("  Nombre %d: ", n + 1);
//         if (scanf("%d", &valeur) != 1) {
//             printf("Entrée invalide, ignorée.\n");
//             while (getchar() != '\n');
//             continue;
//         }
//         if (valeur < 0) {
//             printf("Nombre négatif détecté, arrêt de la saisie.\n");
//             break;
//         }

//         if (n >= capacty) {
//             capacty *= 2;
//             int *temp = realloc(tab, capacty * sizeof(int));
//             if (temp == NULL) {
//                 fprintf(stderr, "Erreur de reallocation memoire\n");
//                 free(tab);
//                 return 1;
//             }
//             tab = temp;
//         }
//         tab[n++] = valeur;
//     }

//     printf("\n=== RÉSULTATS ===\n");
//     printf("Nombre d'éléments: %d\n", n);
//     printf("Capacité finale: %d\n", capacty);
//     printf("Contenu du tableau: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");

//     free(tab);



//     return 0;
// }


// int main() {
//     char nom[50];
//     int age;
//     int item_lus;

//     while (1) {
//         printf("Entrez votre nom (un mot) et votre age : ");
//         item_lus = scanf("%49s %d", nom, &age);
//         if (item_lus == 2) {
//             break;
//         } else {
//             printf("Erreur : Saisie invalide. Veuillez reessayer.\n");
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//         }
//     }
//     printf("\n Saisie reussie \n");
//     printf("NOM: %s\n", nom);
//     printf("Age: %d\n", age);

// }

// char *my_strcpy(char *dest, const char *src) {
//     char *debut = dest;

//     while (*src != '\0') {
//         *dest++ = *src++;
//     }

//     *dest = '\0';
//     return debut;

// }

// int main() {
//     char buffer[50];
//     my_strcpy(buffer, "Bonjour");
//     printf("%s\n", buffer);

//     return 0;
// }
#include <stdio.h>

// #define PRINT_VAR( val)  _Generic((val), \
// int : printf("%s = %d\n", #val, val), \
// float :printf("%s = %.2f\n",#val, val), \
// double: printf("%s = %.2f\n", #val, val), \
// char: printf("%s = %c\n",#val, val) \
//     )


// int main() {
//     int a = 42;
//     float b = 3.14;
//     char c = 'Z';

//     PRINT_VAR(a);
//     PRINT_VAR(b);
//     PRINT_VAR(c);

//     return 0;
// }


// void print_binary(unsigned int n) {

//     unsigned int mask = 1U << 31;
//     while ((mask & n) == 0) {
//         mask >>= 1;
//     }

//     while (mask != 0) {
//         if (mask & n) {
//             printf("1");
//         } else {
//             printf("0");
//         }
//         mask >>= 1;
//     }

//     printf("\n");
// }


// int main() {
//     print_binary(10);  // Affiche: 1010
//     print_binary(0);   // Affiche: 0

//     return 0;
// }

// #include <stdio.h>

// /**
//  * Bir unsigned int sayısını binary formatta yazdırır.
//  * BAŞTAKİ SIFIRLARI ATLAR!
//  * SADECE bitwise operatörler ve ++/-- kullanır.
//  *
//  * @param n Yazdırılacak sayı
//  */
// void print_binary(unsigned int n) {

//     // Özel durum: 0
//     if (n == 0) {
//         printf("0\n");
//         return;
//     }

//     // 1. EN SOLDAKİ 1 BİTİNİ BUL
//     // mask: en soldan başla (bit 31)
//     unsigned int mask = 1U << 31;

//     // Baştaki sıfırları ATLA (ilk 1'i bulana kadar)
//     while ((mask & n) == 0) {
//         mask >>= 1;  // Bir bit SAĞA kaydır (>>= ile DEĞİŞTİR!)
//     }

//     // 2. İLK 1'DEN İTİBAREN TÜM BİTLERİ YAZDIR
//     while (mask != 0) {
//         // Bu bit 1 mi 0 mı?
//         if (n & mask) {
//             printf("1");
//         } else {
//             printf("0");
//         }
//         mask >>= 1;  // Sonraki bit
//     }

//     printf("\n");
// }

// int main() {
//     printf("=== TEST print_binary ===\n\n");

//     printf("print_binary(10): ");
//     print_binary(10);  // 1010

//     printf("print_binary(0):  ");
//     print_binary(0);   // 0

//     printf("print_binary(42): ");
//     print_binary(42);  // 101010

//     printf("print_binary(255):");
//     print_binary(255); // 11111111

//     printf("print_binary(1):  ");
//     print_binary(1);   // 1

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct {
//     size_t size;
//     union {
//         char data[16];
//         struct {
//             char *ptr;
//             size_t capacity;
//         }sdata;
//     };
// }string_t;

// string_t to_string(const char *str) {
//     string_t s;

//     s.size = strlen(str);

//     if (s.size < 16) {
//         strcpy(s.data, str);
//     } else {
//         s.sdata.capacity = s.size + 1;
//         s.sdata.ptr = malloc(s.sdata.capacity);

//         if (s.sdata.ptr != NULL) {
//             strcpy(s.sdata.ptr, str);
//         } else {
//             s.size = 0;
//             s.data[0] = '\0';
//         }
//     }
//     return s;
// }

// void clear_string(string_t *s){
//     if(s==NULL) return;

//     if(s->size>=16){
//         free(s->size >=16);
//             free(s->sdata.ptr);
//             s->sdata.ptr=NULL;
//             s->sdata.capacity=0;
//     }
//     s->size=0;
//     s->data[0]='\0';

// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct{
//     size_t size;
//     union{
//         char data[16];
//         struct{
//             char *ptr;
//             size_t capacity;
//         }sdata;
//     };
// }struct_t;

// typedef struct {
//     size_t size;
//     union {
//         char data[16];
//         struct {
//             char *ptr;
//             size_t capacity;
//         }sdata;
//     };
// } string_t;


// string_t to_string(const char *str) {
//     string_t s;

//     if (str == NULL) {
//         s.size = 0;
//         s.data[0] = '\0';
//         return s;
//     }

//     s.size = strlen(str);

//     if (s.size <= 15) {
//         strcpy(s.data, str);
//     } else {
//         s.sdata.capacity = s.size + 1;

//         s.sdata.ptr = malloc(s.sdata.capacity);

//         if (s.sdata.ptr != NULL) {
//             strcpy(s.sdata.ptr, str);
//         } else {
//             s.size = 0;
//             s.data[0] = '\0';
//         }
//     }

//     return s;
// }


// void clear_string(string_t *s) {
//     if (s == NULL) return;
//     if (s->size > 15) {
//         free(s->sdata.ptr);
//     }
//     s->size = 0;
//     s->data[0] = '\0';
// }


// #include <stdio.h>
// #define MODE 39

// int main() {
// #if MODE ==1

//     printf("Mode DEBUG actif\n");
// #elif MODE ==2
//     printf("Mode RELEASE actif\n");
// #elif MODE ==3
//     printf("Mode TEST actif\n");
// #else
//     printf("Mode inconnu\n");
// #endif

//     return 0;
// }



// #define SET_BIT(word, pos)       ( (word) |= (1U<<(pos)))
// #define CLEAR_BIT(word, pos)       ((word) &=~(1U<<(pos)))
// #define TOGGLE_BIT(word, pos)    ( (word) ^= (1U<<(pos)))
// #define CHECK_BIT(word, pos)    (( (word)>>(pos))&1U)
// #define SET_RANGE(word, start, length, value) \ 
// unsigned mask = ((1U<<(length))-1U)\
// (word) =( ((word)&(~mask)) | (((value)<<(start)) &mask))


// #define  GET_NIBBLE(word, n) ((word)>>(n) &0xF)

// char *my_strcat(char *dest, const char *src) {
//     char *debut = dest;

//     while (*dest)dest++;
//     while (*dest++ = *src++);
//     return debut;
// }

// void my_strcat(char *dest, const char* src){
//     while(*dest != '\0'){
//         dest++;
//     }

//     while(*src !='\0'){
//         *dest++ =*src++;
//     }
//     *dest = '\0';
// }
// int main() {
//     char buffer[50] = "Hello";

//     printf("=== TEST my_strcat ===\n\n");

//     // Test 1: Normal birleştirme
//     printf("Avant: \"%s\"\n", buffer);
//     my_strcat(buffer, " World!");
//     printf("Après: \"%s\"\n", buffer);
//     printf("Attendu: \"Hello World!\"\n\n");

//     // Test 2: Boş string ekleme
//     char buffer2[50] = "Test";
//     printf("Avant: \"%s\"\n", buffer2);
//     my_strcat(buffer2, "");
//     printf("Après: \"%s\"\n", buffer2);
//     printf("Attendu: \"Test\"\n\n");

//     // Test 3: Boş dest'e ekleme
//     char buffer3[50] = "";
//     printf("Avant: \"%s\"\n", buffer3);
//     my_strcat(buffer3, "Bonjour");
//     printf("Après: \"%s\"\n", buffer3);
//     printf("Attendu: \"Bonjour\"\n\n");

//     // Test 4: Zincirleme çağrı
//     char buffer4[100] = "C ";
//     my_strcat(my_strcat(buffer4, "est "), "puissant!");
//     printf("Chaîné: \"%s\"\n", buffer4);
//     printf("Attendu: \"C est puissant!\"\n");

//     return 0;
// }

// typedef struct {
//     int id;
//     double valeur;
// }record_t;

// int read_nth_record(FILE *f, int n, record_t *out) {
//     if (f == NULL || out == NULL || n < 0) {
//         return 0;

//         long offset = 64 + (n * sizeof(record_t));

//         if (fseek(f, offset, SEEK_SET) != 0) {
//             return 0;
//         }

//         size_t items_lus = fread(out, sizeof(record_t), 1, f);
//         if (items_lus == 1)return 1;
//     }
//     return 0;
// }


// int main() {

//     FILE *fichier = fopen("data.bin", "rb");

//     if (fichier == NULL) {
//         printf(stderr, "Erreur...");
//         return 1;
//     }

//     record_t mon_enregistrement;

//     int index=2;

//     int succes= read_nth_record(fichier, index, &mon_enregistrement);

//     return 0;
// }
// #include <stdio.h>

// #define DEFINE_AND_PRINT(type, name, val) \
// type var_##name = (val);                   \
//     printf("%s = %d\n", #name, var_##name)

// int main() {
//     DEFINE_AND_PRINT(int, age, 38);

//     DEFINE_AND_PRINT(int, size, 100);
//     return 0;
// }


// typedef int(*op_func)(int, int);

// int add(int a, int b) { return a + b; };
// int sub(int a, int b) { return a - b; };



// int main() {
//     op_func operations[] = { add, sub };

//     int x = 10, y = 5;
//     printf("add(%d, %d) = %d\n", x, y, operations[0](x, y));
//     printf("add(%d, %d) = %d\n", x, y, operations[1](x, y));

// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>

// typedef struct Node {
//     int data;
//     struct Node *next;
// }Node;

// void push_front(Node **head, int value) {
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     assert(new_node != NULL);

//     new_node->data = value;
//     new_node->next = *head;

//     *head = new_node;
// }


// int main() {
//     Node *head = NULL;
//     push_front(&head, 10);
//     push_front(&head, 20);
//     push_front(&head, 30);

//     for (Node *p = head; p != NULL; p->next) {
//         printf("%d ", p->data);
//         printf('\n');
//     }

//     while (head) {
//         Node *temp = head;
//         head = head->next;
//         free(temp);
//     }
//     return 0;
// }

// #include <stdlib.h>
// #include <stdio.h>
// #include <assert.h>

// typedef struct Node {
//     int data;
//     struct Node *next;
// }Node;

// void push_front(Node **head, int value) {
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     assert(new_node != NULL);

//     new_node->data = value;
//     new_node->next = *head;

//     *head = new_node;
// }

// void print_list(Node *head) {
//     for (Node *p = head; p != NULL; ++p) {
//         printf("%d\n", p->data);
//     }
//     printf("\n");
// }

// void free_list(Node *head) {
//     while (head) {
//         Node *temp = head;
//         head = head->next;
//         free(temp);
//     }
// }

// int main() {
//     Node *head = NULL;
//     // Fonksiyonu çağırırken 'head' işaretçisinin ADRESİNİ gönderiyoruz (&head)
//     push_front(&head, 10);
//     push_front(&head, 20);
//     push_front(&head, 30);

//     print_list(head);

//     free_list(head);
//     return 0;


// }

// #define PRINT_VAR(val) _Generic((val), \
//     int: printf("%s = %d\n", #val, val), \
//     float: printf("%s = %.2f\n", #val, val), \
//     double: printf("%s = %.2f\n", #val, val), \
//     char: printf("%s = %c\n", #val, val) \
// )

// int main() {
//     int a = 42;
//     float b = 3.14;
//     char c = 'Z';

//     PRINT_VAR(a);
//     PRINT_VAR(b);
//     PRINT_VAR(c);

//     return 0;
// }


// int main() {
//     int say1, say2;
//     float ondalik;
//     int top;
//     float ort;

//     scanf("%d, %d", &say1, &say2);
//     scanf("%f", &ondalik);
//     top = say1 + say2;

//     ort=( top+ondalik)/2.0f;

// }

// #define VALUES {1,2,3,4,5,6}

// void afficher_pairs(int tab[], int size) {
//     for (int i = 0; i < size; ++i) {
//         if (tab[i] % 2 == 0) {
//             printf("%d ", tab[i]);
//         }
//     }
//     printf("\n");
// }

// int main() {
//     int my_array[] = VALUES;

//     int size = sizeof(my_array) / sizeof(my_array[0]);
//     afficher_pairs(my_array, size);
// }

// void inverser_chaine(char *str) {
//     if (str == NULL || *str == '\0') return;

//     char *end = str;
//     while (*end) {
//         ++end;
//     }
//     --end;
//     char *start = str;

//     while (start < end) {
//         char temp = *start;
//         *start = *end;
//         *end = temp;

//         ++start;
//         --end;
//     }
// }


// int main() {
//     char str[] = "HEIG-VD";

//     printf("=== STRING TERS ÇEVİRME ===\n\n");
//     printf("Orijinal: \"%s\"\n", str);
//     inverser_chaine(str);
//     printf("Ters:     \"%s\"\n", str);
//     printf("Beklenen: \"DV-GIEH\"\n\n");


// }
// #include <stdlib.h>
// #include <ctype.h>

// int main() {

//     int capacite = 2;
//     int nb_elements = 0;
//     int valuer;
//     char fin;

//     int *tab = malloc(capacite * sizeof(int));
//     if (tab == NULL) {
//         fprintf(stderr, "Erreur allocation");
//         return 1;
//     }
//     printf("Entrez des nombres ('q' pour quitter):\n");

//     while (1) {

//         if (scanf("%d", &valuer) == 1) {
//             if (nb_elements >= capacite) {
//                 capacite *= 2;

//                 int *temp = realloc(tab, capacite * sizeof(int));
//                 if (temp == NULL) {
//                     fprintf(stderr, "erreur de reallocation..");
//                     free(tab);
//                     return 1;
//                 }
//                 tab = temp;
//                 printf("  [Capacité augmentée à %d]\n", capacite);
//             }

//             tab[nb_elements++] = valuer;
//         } else {
//             scanf("%c", &fin);
//             if (fin == 'q') {
//                 break;
//             } else {
//                 printf("  Entrée invalide, recommencez\n");
//                 while (getchar() != '\n');
//             }
//         }
//     }
//     printf("Vous avez saisi %d nombres\n", nb_elements);
//     for (int i = 0; i < nb_elements; i++) {
//         printf("%d", tab[i]);
//         if (i < nb_elements - 1) {
//             printf(" ");  // Son elemandan sonra boşluk YOK
//         }
//     }
//     printf("\n");

//     free(tab);
// }

void somme_lignes(int **mat, int lignes, int colonnes) {
    for (int i = 0; i < lignes;++i) {
        int somme = 0;
        for (int j = 0; j < colonnes; ++j) {
            somme += mat[i][j];
        }
        printf("Somme lignes %d : %d\n", i, somme);
    }
}


int main() {
    int lignes, colonnes;

    printf("Lignes : ");
    scanf("%d", &lignes);
    printf("Colonnes : ");
    scanf("%d", &colonnes);

    if (lignes <= 0 || colonnes <= 0) {
        printf("Erreur..");
        return 1;
    }

    int **matrice = malloc(lignes * sizeof(int *));
    if (matrice == NULL) {
        fprintf(stderr, "Erreur..");
        return 1;
    }

    for (int i = 0; i < lignes; ++i) {
        matrice[i] = malloc(colonnes * sizeof(int));
        if (matrice[i] == NULL) {
            fprintf(stderr, "Erreur..\n");
            for (int j = 0; j < i; ++j) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }
    printf("Entrez les valeurs (%d x %d) :\n", lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("Ligne %d, colonne %d : ", i, j);
            scanf("%d", &matrice[i][j]);  // & UNUTMA!
        }
    }

    printf("\n");
    somme_lignes(matrice, lignes, colonnes);

    for (int i = 0; i < lignes; ++i) {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}
