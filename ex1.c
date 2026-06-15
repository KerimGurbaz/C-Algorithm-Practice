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

// void somme_lignes(int **mat, int lignes, int colonnes) {
//     for (int i = 0; i < lignes;++i) {
//         int somme = 0;
//         for (int j = 0; j < colonnes; ++j) {
//             somme += mat[i][j];
//         }
//         printf("Somme lignes %d : %d\n", i, somme);
//     }
// }


// int main() {
//     int lignes, colonnes;

//     printf("Lignes : ");
//     scanf("%d", &lignes);
//     printf("Colonnes : ");
//     scanf("%d", &colonnes);

//     if (lignes <= 0 || colonnes <= 0) {
//         printf("Erreur..");
//         return 1;
//     }

//     int **matrice = malloc(lignes * sizeof(int *));
//     if (matrice == NULL) {
//         fprintf(stderr, "Erreur..");
//         return 1;
//     }

//     for (int i = 0; i < lignes; ++i) {
//         matrice[i] = malloc(colonnes * sizeof(int));
//         if (matrice[i] == NULL) {
//             fprintf(stderr, "Erreur..\n");
//             for (int j = 0; j < i; ++j) {
//                 free(matrice[j]);
//             }
//             free(matrice);
//             return 1;
//         }
//     }
//     printf("Entrez les valeurs (%d x %d) :\n", lignes, colonnes);
//     for (int i = 0; i < lignes; i++) {
//         for (int j = 0; j < colonnes; j++) {
//             printf("Ligne %d, colonne %d : ", i, j);
//             scanf("%d", &matrice[i][j]);  // & UNUTMA!
//         }
//     }

//     printf("\n");
//     somme_lignes(matrice, lignes, colonnes);

//     for (int i = 0; i < lignes; ++i) {
//         free(matrice[i]);
//     }
//     free(matrice);

//     return 0;
// }


// int combien(int n) {
//     int count = 0;
//     do {
//         n /= 10;
//         ++count;
//     }
//     while (n > 0);
//     return count;

// }
// int main() {
//     int n;
//     int c;
//     if (scanf("%d", &n) != 1) {
//         fprintf(stderr, "erreor..");
//         while ((c = getchar()) != '\n' && c != EOF) {
//             continue;
//         }
//         return 1;
//     };

//     int result = combien(n);
//     printf("%d", result);

//     return 0;
// }

// float produit_scalaire(const float *tab1, const float *tab2, int size) {
//     float somme = 0.0f;
//     const float *fin = size + tab1;

//     while (tab1 < fin) {
//         somme += (*tab1++) * (*tab2++);
//     }
//     return somme;

// }


// int main() {

//     float v1[] = { 1.0f, 2.0f, 3.0f };
//     float v2[] = { 4.0f, 5.0f, 6.0f };

//     int taille = sizeof(v1) / sizeof(v1[0]);

//     float result = produit_scalaire(v1, v2, taille);

//     printf("Result : %.0f\n", result);
// }

// int est_palindrome(const char *str) {

//     if (str == NULL) {
//         return 0;
//     }

//     const char *start = str;
//     const char *end = str;

//     while (*end) {
//         ++end;
//     }
//     if (start == end) {
//         return 1;
//     }
//     end--;
//     while (start < end) {
//         if (*start != *end) {
//             return 0;
//         }
//         ++start;
//         --end;
//     }

//     return 1;
// }


// int main() {
//     char *test1 = "kayak";
//     char *test2 = "radar";
//     printf("'%s' palindrom mu? %d\n", test1, est_palindrome(test1));
//     printf("'%s' palindrom mu? %d\n", test2, est_palindrome(test2));

// }


// int main() {
//     int capacite = 1;
//     int nb_elements = 0;
//     int valeur;

//     int *tab = malloc(capacite * sizeof(int));
//     if (tab == NULL) {
//         fprintf(stderr, "Erreur d'allocation memoire\n");
//         return 1;
//     }
//     printf("Entrez des nombres entiers ('q' pour quitter):\n");
//     printf("(Seuls les nombres pairs seront stockés)\n\n");

//     while (1) {
//         if (scanf("%d", &valeur) == 1) {
//             if (valeur % 2 != 0) {
//                 printf("  %d est impair, ignoré.\n", valeur);
//                 continue;
//             }
//             if (nb_elements >= capacite) {
//                 capacite *= 2;

//                 int *temp = realloc(tab, capacite * sizeof(int));
//                 if (temp == NULL) {
//                     fprintf(stderr, "Erreur de reallocation memoire\n");
//                     free(tab);
//                     return 1;
//                 }
//                 tab = temp;
//                 printf("  [Capacité augmentée à %d]\n", capacite);
//             }
//             tab[nb_elements] = valeur;
//             nb_elements++;
//             printf("  %d stocké.\n", valeur);
//         } else {
//             char fin;
//             scanf("%c", &fin);

//             if (fin == 'q' || fin == 'Q') {
//                 break;
//             } else {
//                 printf("  Entrée invalide. Utilisez 'q' pour quitter.\n");
//                 while (getchar() != '\n');
//             }
//         }
//     }

//     printf("\n=== RÉSULTATS ===\n");
//     printf("Vous avez stocké %d nombre(s) pair(s) :\n", nb_elements);
//     if (nb_elements > 0) {
//         for (int i = 0; i < nb_elements; i++) {
//             printf("%d", tab[i]);
//             if (i < nb_elements - 1) printf(" ");
//         }
//         printf("\n");
//     } else {
//         printf("(aucun)\n");
//     }
//     printf("Capacité finale du tableau : %d\n", capacite);

//     free(tab);

// }


// #include <stdlib.h>

// int main() {
//     int N;
//     printf("Satir sayisini (N) girin: ");
//     if (scanf("%d", &N) != 1 || N <= 0) return 1;

//     int **jagged_array = malloc(N * sizeof(int *));
//     if (jagged_array == NULL) {
//         printf("Erreur..");
//         return 1;
//     }
//     for (int i = 0; i < N; ++i) {
//         jagged_array[i] = malloc((i + 1) * sizeof(int));
//         if (jagged_array[i] == NULL) {
//             printf("%d. satir bellek tahsisi basarisiz..\n", i);
//             for (int k = 0; k < i; ++k) {
//                 free(jagged_array[k]);
//             }
//             free(jagged_array);
//             return 1;
//         }


//         for (int j = 0; j < (i + 1); ++j) {
//             jagged_array[i][j] = i;
//         }
//     }
//     printf("\nTableau 'en escalier' (%d lignes):\n", N);
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < (i + 1); j++) {
//             printf("%d ", jagged_array[i][j]);
//         }
//         printf("\n"); // Her satır bitiminde alt satıra geç
//     }

//     for (int i = 0; i < N; i++) {
//         free(jagged_array[i]);
//     }

//     free(jagged_array);
//     return 0;
// }


// #define DEFINE_AND_PRINT(type, name, val) \
//     type var_##name = val; \
//     printf("%s = %d\n", #name, var_##name)
//     // printf(#name " = %d\n", var_##name)

// int main() {
//     // Sınav sorusundaki örnek çağrı
//     DEFINE_AND_PRINT(int, age, 38);

//     // İşlemin başarılı olduğunu ve 'var_age' değişkeninin
//     // makro dışında da gerçekten var olduğunu kanıtlayalım:
//     printf("Makro disinda erisim: var_age'in karesi = %d\n", var_age * var_age);

//     // Farklı tiplerle de çalıştığını görelim
//     DEFINE_AND_PRINT(char, initial, 65); // 65, 'A' karakterinin ASCII kodudur (integer olarak yazdırılır)

//     return 0;
// }


// #include <stdio.h>
// #include <stddef.h>

// void reserve_array(int *tab, size_t n) {
//     if (tab == NULL || n < 0)return;

//     int *start = tab;
//     int *fin = tab + n - 1;

//     while (start < fin) {
//         int temp = *start;
//         *start = *fin;
//         *fin = temp;
//         ++start;
//         --fin;
//     }

// }



// int main() {
//     int tab[] = { 1,2,3,4,5,6,7 };
//     size_t taille = sizeof(tab) / sizeof(tab[0]);

//     printf("Avant : ");
//     for (size_t i = 0; i < taille; i++) printf("%d ", tab[i]);

//     reserve_array(tab, taille);

//     printf("Apres : ");
//     for (size_t i = 0; i < taille; i++) printf("%d ", tab[i]);

//     printf("\n");
//     return 0;

// }

// #define MAX(a,b) ((a) > (b) ? (a) :(b))


// char *my_strdup(const char *s) {
//     if (s == NULL) {
//         return NULL;
//     }

//     size_t len = 0;
//     const char *p = s;
//     while (*p++) ++len;

//     char *copy = malloc((len + 1) * sizeof(char));
//     if (copy == NULL) {
//         return NULL;
//     }
//     char *dest = copy;
//     while (*dest++ = *s++);

//     return copy;


// }


// int main() {
//     const char *originale = "HEIG_VD";
//     char *dupliquee = my_strdup(originale);

//     if (dupliquee) {
//         printf("Originale : %s\n", originale);
//         printf("Dupliquée : %s\n", dupliquee);
//         printf("Adresses différentes : %p vs %p\n", &originale, &dupliquee);
//         free(dupliquee);
//     } else {
//         printf("Erreur d'allocation\n");
//     }

//     return 0;

// }


// int main() {
//     const char *original = "HEIG-VD Data Engineering";

//     char *kopya = my_strdup(original);

//     if (kopya != NULL) {
//         printf("Orijinal : %s\n", original);
//         printf("Kopya    : %s\n", kopya);

//         kopya[0] = 'X';
//         printf("Orijinal : %s\n", original);
//         printf("degistirilmis_Kopya    : %s\n", kopya);

//         free(kopya);

//     } else {
//         printf("Bellek tahsisi basarisiz oldu.\n");
//     }

//     return 0;
// }

// typedef struct {
//     int id;
//     char nom[50];
//     float moyenne;
// }etudiant_t;


// int save_students(const char *filename, const etudiant_t *tab, size_t count) {
//     if (filename == NULL || tab == NULL || count == 0) {
//         return 0;
//     }

//     FILE *f = fopen(filename, "wb");
//     if (f == NULL) {
//         perror("Error d'ouverture du fcihier");
//         return 0;
//     }

//     size_t written = fwrite(tab, sizeof(etudiant_t), count, f);
//     fclose(f);

//     if (written == count) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// int main() {
//     etudiant_t etudiants[] = {
//        {1, "Ali Yilmaz", 85.5},
//        {2, "Ayse Demir", 92.0},
//        {3, "Mehmet Kaya", 78.5}
//     };

//     size_t count = sizeof(etudiants) / sizeof(etudiants[0]);

//     if (save_students("etudiants.dat", etudiants, count)) {
//         printf("✅ %zu öğrenci başarıyla kaydedildi.\n", count);

//         // Dosya boyutunu kontrol et
//         printf("   Beklenen dosya boyutu: %zu byte\n",
//             count * sizeof(etudiant_t));
//     } else {
//         printf("❌ Kayıt başarısız!\n");
//     }

//     return 0;
// }


// union FloatBytes {
//     float f;
//     unsigned char bytes[4];
// };

// int main() {
//     union FloatBytes fb;
//     fb.f = 3.14f;

//     printf("Float degeri : %.2f\n", fb.f);
//     printf("\nByte'lar (hex olarak):\n");

//     for (int i = 0; i < 4; ++i) {
//         printf("Byte %d : 0x%02X\n", i, fb.bytes[i]);
//     }
//     // 3. İLK byte'ı hex olarak yazdır
//     printf("\nİlk byte (hex): 0x%02X\n", fb.bytes[0]);

//     printf("\nBellek adresi: %p\n", (void *)&fb);
//     printf("sizeof(FloatBytes) = %zu byte\n", sizeof(union FloatBytes));

// }

// typedef struct DNode {
//     int data;
//     struct DNode *prev;
//     struct DNode *next;

// }DNode;

// void delete_note(DNode **head, DNode *to_delete) {
//     if (head == NULL || *head == NULL || to_delete == NULL) {

//         return;
//     }

//     if (*head == to_delete) {
//         *head = to_delete->next;
//     }
//     if (to_delete->prev != NULL) {
//         to_delete->prev->next = to_delete->next;
//     }
//     if (to_delete->next != NULL) {
//         to_delete->next->prev = to_delete->prev;
//     }

//     free(to_delete);

// }
// void push_front(DNode **head, int data) {
//     DNode *n = malloc(sizeof(DNode));

//     n->data = data;
//     n->prev = NULL;
//     n->next = *head;
//     if (*head) {
//         (*head)->prev = n;
//         *head = n;
//     }
// }

// void free_list(DNode *head) {
//     while (head) {
//         DNode *tmp = head;
//         head = head->next;
//         free(tmp);
//     }
// }

// typedef struct DNode {
//     int data;
//     struct DNode *prev;
//     struct DNode *next;
// }DNode;

// void delete_node(DNode **head, DNode *to_delete) {
//     if (*head == NULL || to_delete == NULL) {
//         return;
//     }

//     if (*head == to_delete) {
//         *head = to_delete->next;
//     }
//     if(to_delete->next != NULL){
//         to_delete->next->prev = to_delete->prev;
//     }
// }


// typedef struct DNode {
//     int data;
//     struct DNode *prev;
//     struct DNode *next;
// }DNode;

// void insert_sorted(DNode **head, int value) {
//     if (head == NULL) return;
//     DNode *new_node = malloc(sizeof(DNode));
//     if (new_node == NULL) return;
//     new_node->data = value;
//     new_node->prev = NULL;
//     new_node->next = NULL;

//     if(*head == NULL){
//         *head = new_node;
//         return;
//     }

//     DNode *current = *head;

//     while(current != NULL && current->data < value){
//         current = current->next;
//     }
//     if(current == *head){
//         (*head)->prev = new_node;
//         *head = new_node;
//     }


// }

// void reverse_array(int *tab, size_t size) {

//     if(tab == NULL || size<=1) return;

//     int *start = tab;
//     int *end = tab + size - 1;

//     while (start < end) {
//         int temp = *start;
//         *start = *end;
//         *end = temp;
//         ++start;
//         --end;
//     }

//     for (int *i = tab; i < tab + size + 1; ++i) {
//         printf("%d \n", *i);
//     }
// }


// int main() {

//     int t[] = { 1, 2, 3, 4, 5 };
//     reverse_array(t, 5);


//     return 0;

// }


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int id;
//     char nom[50];
//     char prenom[50];
//     float moyenne;
// }etudiant_t;

// void lire_fichier(const char *nom_fichier) {
//     FILE *f = fopen(nom_fichier, "rb");
//     if (f == NULL) {
//         fprintf(stderr, "Erreur d'ouverture du fichier\n");
//         return;
//     }

//     etudiant_t e;

//     while (1) {
//         if (fread(&e, sizeof(etudiant_t), 1, f) != 1) {
//             break;
//         }
//         printf("ID : %d\n", e.id);
//         printf("Nom : %s\n", e.nom);
//         printf("Prenom : %s\n", e.prenom);
//         printf("Moyenne : %.2f\n", e.moyenne);
//         printf("--------------------\n");

//         fseek(f, sizeof(etudiant_t), SEEK_CUR);
//     }

//     fclose(f);
// }


// typedef struct {
//     int id;
//     char nom[50];
//     char prenom[50];
//     float moyenne;
// }etudiant_t;


// void lire_fichier(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {
//         return;
//     }

//     etudiant_t e;

//     while (1) {
//         if (fread(&e, sizeof(etudiant_t), 1, f) != 1) {
//             break;
//         }
//         printf("ID: %d\n", e.id);
//         printf("Nom: %s\n", e.nom);
//         printf("Prénom: %s\n", e.prenom);
//         printf("Moyenne: %.2f\n", e.moyenne);
//         printf("--------------------\n"); // Tam olarak 20 tire

//         fseek(f, sizeof(etudiant_t), SEEK_CUR);
//     }

//     fclose(f);

// }
// int main() {
//     // Fonksiyonunu test etmek icin cagiriyorsun
//     lire_fichier("ogrenciler.bin");

//     return 0;
// }

// size_t my_strlen(const char *str) {
//     const char *p = str;
//     while (*p++);
//     --p;
//     return p - str;
// }

// int main() {

//     printf("%d\n", my_strlen("Bonjour le monde!"));
//     printf("%d\n", my_strlen(""));

//     return 0;

// }

typedef struct image {
    unsigned w;
    unsigned h;
    unsigned byte_per_pixel;
    char data[];

}image_t;

image_t *read_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        fprintf(stderr, "impossible d'ouvrir le fichier\n");
        return NULL;
    }

    unsigned int w, h, bpp;
    if (fread(&w, sizeof(unsigned int), 1, f) != 1 ||
        fread(&h, sizeof(unsigned int), 1, f) != 1 ||
        fread(&bpp, sizeof(unsigned int), 1, f) != 1
        ) {
        fprinf(stderr, "Impossible de lire le header\n");
        fclose(f);
        return NULL;
    }

    size_t data_size = w * h * bpp;
    image_t *img = malloc(sizeof(image_t) + data_size);
    if (img == NULL) {
        fprintf(stderr, "impossible d'allouer la memoire\n");
        fclose(f);
        return NULL;
    }

    img->byte_per_pixel = bpp;
    img->w = w;
    img->h = h;

    if (fread(img->data, 1, data_size, f) != data_size) {
        fprintf(stderr, "Impossible de lire les pixels\n");
        free(img);
        fclose(f);
        return NULL;
    }

    fclose(f);
    return;



}
