// #include <stdio.h>
// #include <stdbool.h>
// #include <ctype.h>


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


// #include <stdio.h>
// #include <errno.h>

// typedef struct {
//     int id;
//     char nom[50];
//     char prenom[50];
//     float moyenne;
// }etudiant_t;

// void lire_a_rebours(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (!f) {
//         perror("Error ... ");
//         return;
//     }

//     fseek(f, 0, SEEK_END);
//     long taille = ftell(f);
//     int nb_etudiant = (int)taille / sizeof(etudiant_t);

//     etudiant_t student;

//     for (int i = nb_etudiant - 1; i >= 0; --i) {
//         fseek(f, i * sizeof(etudiant_t), SEEK_SET);
//         fread(&student, sizeof(etudiant_t), 1, f);

//         printf("ID %d\n", student.id);
//         printf("nom %s\n", student.nom);
//         printf("ID %s\n", student.prenom);
//         printf("ID %.2f\n", student.moyenne);
//     }

//     fclose(f);
// }


// #include <CUnit/CUnit.h>

// #include <CUnit/Basic.h>
// #include <math.h>


// int calculer(int nom1, int nom2, char op) {
//     switch (op) {
//     case '+': return nom1 + nom2;
//     case '-': return nom1 - nom2;
//     case '*': return nom1 * nom2;
//     case '/': if (nom2 != 0) {
//         return nom1 + nom2;
//     } else {

//         return -1;
//     }
//     case '^': return (int)pow((double)nom1, (double)nom2);
//     default: return -1;
//     }
// }

// void test_addition(void) {
//     CU_ASSERT_EQUAL(calculer(2, 3, '+'), 5);
//     CU_ASSERT_EQUAL(calculer(-2, 2, '+'), 0);
// }

// void test_soustraction(void) {
//     CU_ASSERT_EQUAL(calculer(10, 4, '-'), 6)
// }

// void test_multiplication(void) {
//     CU_ASSERT_EQUAL(calculer(5, 3, '*'), 15);
// }

// void test_division_normale(void) {
//     CU_ASSERT_EQUAL(calculer(10, 2, '/'), 5);
//     // Tamsayı bölmesi olduğu için 5/2 = 2 çıkmalıdır.
//     CU_ASSERT_EQUAL(calculer(5, 2, '/'), 2);
// }

// void test_division_par_zero(void) {
//     // Hata durumunda fonksiyonun -1 döndürmesi bekleniyor.
//     CU_ASSERT_EQUAL(calculer(10, 0, '/'), -1);
// }

// void test_puissance(void) {
//     CU_ASSERT_EQUAL(calculer(2, 3, '^'), 8);
// }


// void test_operateur_invalide(void) {
//     // Tanımsız bir operatör ('x') gönderildiğinde hata yakalanmalı.
//     CU_ASSERT_EQUAL(calculer(5, 5, 'x'), -1);
// }
// int main() {
//     // Adım A: CUnit test kayıt defterini başlat
//     if (CUE_SUCCESS != CU_initialize_registry()) {
//         return CU_get_error();
//     }

//     // Adım B: Yeni bir Test Paketi (Suite) oluştur
//     // Parametreler: (isim, init_fonksiyonu, clean_fonksiyonu) -> Setup/Teardown yoksa NULL verilir.
//     CU_pSuite suite = CU_add_suite("Suite_Calculatrice", NULL, NULL);
//     if (NULL == suite) {
//         CU_cleanup_registry();
//         return CU_get_error();
//     }

//     // Adım C: Yazdığımız testleri paketimize (suite) ekle
//     if ((NULL == CU_add_test(suite, "Test Addition", test_addition)) ||
//         (NULL == CU_add_test(suite, "Test Soustraction", test_soustraction)) ||
//         (NULL == CU_add_test(suite, "Test Multiplication", test_multiplication)) ||
//         (NULL == CU_add_test(suite, "Test Division Normale", test_division_normale)) ||
//         (NULL == CU_add_test(suite, "Test Division par Zero", test_division_par_zero)) ||
//         (NULL == CU_add_test(suite, "Test Puissance", test_puissance)) ||
//         (NULL == CU_add_test(suite, "Test Operateur Invalide", test_operateur_invalide))) {
//         CU_cleanup_registry();
//         return CU_get_error();
//     }

//     // Adım D: Testleri konsolda okunabilir bir formatta (Basic) çalıştır
//     CU_basic_set_mode(CU_BRM_VERBOSE); // VERBOSE modu, her testin sonucunu tek tek ekrana yazar
//     CU_basic_run_tests();

//     // Adım E: Belleği temizle ve çık (Memory Leak önlemi)
//     CU_cleanup_registry();
//     return CU_get_error();
// }


// #include <stdio.h>
// void afficher() {
// #ifdef DEBUG
//     printf("Debug: mesage affiche\n");
// #endif
// }

// int get_Value() {
// #ifdef DEBUG
//     return 99;
// #else
//     return 0;
// #endif
// }


// int calculer(int a, int b) {
// #ifdef FEATURE
//     return (int)pow((double)a, (double)b) + (a * b);
// #else
//     return a + b;
// #endif
// }


// #include <CUnit/Basic.h>

// int my_strlen(const char *str) {
//     int len = 0;
//     while (*str) {
//         ++len;
//         ++str;
//     }
//     return len;
// }

// int my_strcmp(const char *str1, const char *str2) {
//     while (*str1 && (*str1 == *str2)) {
//         ++str1;
//         ++str2;
//     }
//     return (int)((unsigned char)*str1 - (unsigned char)*str2);
// }

// char *my_strcat(char *dest, const char *src) {
//     char *ptr = dest;
//     while (*ptr) {
//         ptr++;
//     }
//     while (*src != '\0') {
//         *ptr = *src;
//         ++ptr;
//         ++src;
//     }
//     *ptr = '\0';
//     return dest;
// }

// void test_my_strlen(void){
//     CU_ASSERT_EQUAL(my_strlen(""), 0);
//     CU_ASSERT_EQUAL(my_strlen("hELLO"), 5);
//     CU_ASSERT_EQUAL(my_strlen("a"), 1);
//     CU_ASSERT_EQUAL(my_strlen("A B\N"), 0);
// }

// void test_strcat(void){
//     CU_ASSERT_EQUAL(my_strcmp("abc", "abc"), 0);
//     CU_ASSERT_TRUE(my_strcmp("abc", "abd") < 0);
// }

// #include <CUnit/CUnit.h>
// #include <CUnit/Basic.h>
// #include <string.h>

// #define MAX 100

// typedef struct {
//     int id;
//     char titre[50];
//     float prix;
// }Livre;

// void ajouter_livre(Livre tab[], int *n, Livre l) {
//     if (*n < MAX) {
//         tab[*n] = l;
//         (*n)++;
//     }
// }

// Livre *chercher(Livre tab[], int n, int id) {
//     for (int i = 0;i < n;++i) {
//         if (tab[i].id == id) {
//             return &tab[i];
//         }
//     }
//     return NULL;
// }

// int cop_par_prix(Livre tab[], int n, float min) {
//     int count = 0;
//     for (int i = 0; i < n; ++i) {
//         if (tab[i].prix >= min) {
//             count++;
//         }
//     }

//     return count;
// }

// void test_ajouter(void) {
//     Livre bib[MAX];
//     int n = 0;
//     Livre l1 = { 1, "Le C en 20 Jours", 45.5 };
//     ajouter_livre(bib, &n, l1);
//     CU_ASSERT_EQUAL(n, 1);
//     CU_ASSERT_EQUAL(bib[0].id, 1);
//     CU_ASSERT_STRING_EQUAL(bib[0].titre, "Le C en 20 Jours");
// }


#include <stdio.h>
#include <stdlib.h>
// #include <CUnit/CUnit.h>
// #include <CUnit/Basic.h>

// int fac(int n) {
//     if (n <= 1) return 1;
//     return n * fac(n - 1);
// }

// void test_fac(void) {
//     CU_ASSERT_EQUAL(fac(0), 1);
//     CU_ASSERT_EQUAL(fac(1), 1);
//     CU_ASSERT_EQUAL(fac(5), 120);
// }

#include <stdint.h>

// int check(uint32_t mots) {
//     int count = 0;
//     for (int i = 31; i >= 0; --i) {
//         if ((mots >> i) & 1U) {
//             ++count;
//         }
//     }
//     return count;
// }


// uint32_t invert_bits(uint32_t word, int start, int length) {
//     uint32_t mask = (((1U - length) - 1U) << start);
//     word ^= mask;
// }


#include <stdint.h>

// void droit(uint16_t droits, char *output) {
//     const char *symboles = "rwxrwxrwx";;

//     for (int i = 0; i < 9; ++i) {
//         if ((droits >> (8 - i)) & 1U) {
//             output[i] = symboles[i];
//         } else {
//             output[i] = '-';
//         }
//     }
//     output[9] = '\0';
// }

// void print_binary_full(uint32_t num) {
//     for (int i = 31; i >= 0; --i) {
//         if ((num >> i) & 1U) {
//             putchar('1');
//         } else {
//             putchar('0');
//         }
//     }
// }


// #define SWAP(a, b) do{   \
//     int (temp) = a;  \
//     (a) =(b);             \
//     (b) =(temp);  \
// } while(0)  


// #include <stdio.h>
// #include <stdint.h>

// typedef struct {
//     uint32_t flags;
// }registre_t;

// void set_flag(registre_t *r, int pos) {
//     r->flags |= (1U << pos);
// }

// void print_binary(uint32_t w) {
//     for (int i = 31; i >= 0; --i) {
//         printf("%d", (w >> i) & 1U);
//         if (i % 4 == 0) printf(" ");
//     }
//     printf("\n");
// }

// void clear_flag(registre_t *r, int pos) {
//     r->flags &= ~(1U << pos);
// }

// void print_compact(uint32_t w) {
//     while (w == 0) {
//         printf("0\n");
//         return;
//     }
//     uint32_t mask = 1U << 31;
//     while ((w & mask) == 0) {
//         mask >>= 1;
//     }
//     while (mask != 0) {
//         printf("%d", (w & mask) ? 1 : 0);
//         mask >>= 1;
//     }
//     printf("\n");
// }

// void toggle_flag(registre_t *r, int pos) {
//     r->flags ^= (1U << pos);
// }

// int main() {
//     registre_t start = { 0 };

//     printf("=== REGISTER BIT OPERATIONS ===\n\n");

//     printf("Initial state:\n");

//     printf(" flags =0x%03X = ", start.flags);
//     print_binary(start.flags);

//     printf("1. SET bits 0, 3, 7:\n");

//     set_flag(&start, 0);
//     set_flag(&start, 3);
//     set_flag(&start, 7);
//     printf(" flags =0x%08X = ", start.flags);
//     print_binary(start.flags);

//     printf("2. CLEAR bit 3:\n");
//     clear_flag(&start, 3);
//     printf(" flags =0x%08X = ", start.flags);
//     print_binary(start.flags);

//     printf("  Compact: ");
//     print_compact(start.flags);

//     return 0;

// }


// #include <stdio.h>
// #include <stdint.h>

// typedef struct {
//     uint32_t flags;
// }registre_t;

// void set_flag(registre_t *r, int pos) {
//     if (r && pos >= 0 && pos < 32) {
//         r->flags |= (1U << pos);
//     }
// }

// void clear_flag(registre_t *r, int pos) {
//     if (r && pos >= 0 && pos < 32) {
//         r->flags &= ~(1U << pos);
//     }
// }

// void toggle_flag(registre_t *r, int pos) {
//     if (r && pos > 0 && pos < 32) {
//         r->flags ^= (1U << pos);
//     }
// }


// void print_binary(uint32_t w) {
//     for (int i = 31; i >= 0; --i) {
//         putchar(((w >> i) & 1U) ? '1' : '0');
//         if (i % 4 == 0) {
//             putchar(' ');
//         }
//     }
//     printf("\n");
// }

// int main() {
//     registre_t reg = { 0 };

//     set_flag(&reg, 0);
//     set_flag(&reg, 3);
//     set_flag(&reg, 7);

//     clear_flag(&reg, 3);

//     toggle_flag(&reg, 7);

//     // Sonucu ekrana bas
//     printf("Resultat final (Binary) : ");
//     print_binary(reg.flags);

//     return 0;
// }


// #include <stdio.h>
// #include <stdint.h>

// #define SET_BIT(word, pos) ((word) |= (1U<<(pos)))
// #define CLEAR_BIT(word, pos) ((word) &= ~(1U<<(pos)))
// #define TOGGLE_BIT(word, pos) ((word) ^= (1U<<(pos)))
// #define CHECK_BIT(word, pos) ((word) & (1U<<(pos)))

// #define EXTRACT_BITS(word, start, len)  \
// (((word)>>(start)) & ((1U<<len) -1U))   \

// void print_binary8(uint8_t w) {
//     for (int i = 7; i >= 0; --i) {
//         putchar(((w >> i) & 1U) ? '1' : '0');
//     }
//     printf("\n");
// }



// int main() {
//     uint32_t x = 0b11010110;  // 214 decimal

//     printf("=== TEST DES MACROS BITWISE ===\n\n");

//     printf("Valeur initiale:\n");
//     printf("  x = 0x%02X = ", x);
//     print_binary8(x);
//     printf(" (decimal: %u)\n\n", x);

//     // Test 1: CHECK_BIT
//     printf("1. CHECK_BIT:\n");
//     printf("  CHECK_BIT(x, 7) = %s (bit 7 = 1? Evet)\n",
//         CHECK_BIT(x, 7) ? "SET" : "CLEAR");
//     printf("  CHECK_BIT(x, 4) = %s (bit 4 = 1? Evet)\n",
//         CHECK_BIT(x, 4) ? "SET" : "CLEAR");
//     printf("  CHECK_BIT(x, 0) = %s (bit 0 = 0? Evet)\n\n",
//         CHECK_BIT(x, 0) ? "SET" : "CLEAR");

//     // Test 2: SET_BIT
//     printf("2. SET_BIT(x, 0):\n");
//     SET_BIT(x, 0);
//     printf("  x = ");
//     print_binary8(x);
//     printf(" (bit 0 = 1 yapildi)\n\n");

//     // Test 3: CLEAR_BIT
//     printf("3. CLEAR_BIT(x, 7):\n");
//     CLEAR_BIT(x, 7);
//     printf("  x = ");
//     print_binary8(x);
//     printf(" (bit 7 = 0 yapildi)\n\n");

//     // Test 4: EXTRACT_BITS - ASIL SORU!
//     printf("4. EXTRACT_BITS(x, 2, 3):\n");
//     printf("  bits [2..4] cikariliyor (len=3)\n");

//     uint32_t resultat = EXTRACT_BITS(x, 2, 3);
//     printf("  x           = ");
//     print_binary8(x);
//     printf("\n");
//     printf("  x >> 2      = ");
//     print_binary8(x >> 2);
//     printf("\n");
//     printf("  maske (0x07) = 00000111\n");
//     printf("  SONUC       = ");
//     print_binary8(resultat);
//     printf(" = %u\n", resultat);
//     printf("  Beklenen: 0b101 = 5\n\n");

//     // Bonus: Farklı bir aralık testi
//     printf("5. EXTRACT_BITS(x, 1, 4):\n");
//     printf("  bits [1..4] cikariliyor (len=4)\n");
//     uint32_t r2 = EXTRACT_BITS(x, 1, 4);
//     printf("  SONUC = %u\n", r2);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct noeud {
//     int valeur;
//     struct noeud *next;
// }noeud_t;

// void push(noeud_t **head, int val) {
//     noeud_t *nouveau = (noeud_t *)malloc(sizeof(noeud_t));
//     if (nouveau == NULL) {
//         fprintf(stderr, "erreur");
//         return;
//     }

//     nouveau->valeur = val;

//     nouveau->next = *head;
//     *head = nouveau;
// }


// void sauvegarder(noeud_t *head, const char *file) {
//     FILE *f = fopen(file, "wb");
//     if (f == NULL) {
//         fprintf(stderr, "erreur");
//     }
//     int count = 0;

//     noeud_t *cour
// }
#include <stdio.h>

// typedef struct {
//     int id;
//     char nom[50];
//     float moy;
// }etudiant_t;

// int lire_etudiant(FILE *f, int idx, etudiant_t *out) {
//     if (f == NULL || out == NULL || idx < 0) {
//         return 0;
//     }


//     if (fseek(f, idx * sizeof(etudiant_t), SEEK_SET) != 0) {
//         return 0;
//     }

//     if (fread(out, sizeof(etudiant_t), 1, f) != 1) {
//         return 0;
//     }

//     return 1;
// }

// typedef struct {
//     int id;
//     char nom[50];
//     float moy;
// }etudiant_t;

// int lire(FILE *f, int idx, etudiant_t *out) {
//     if (f == NULL || out == NULL || idx < 0) {
//         return 0;
//     }

//     fseek(f, idx * sizeof(etudiant_t), SEEK_SET);

//     fread(out, sizeof(etudiant_t), 1, f);
// }


// #include <stdio.h>
// #include <CUnit/CUnit.h>
// #include <CUnit/Basic.h>

// #define MAXSTACK 100


// typedef struct {
//     int data[MAXSTACK];
//     int top;
// }Stack;

// void init_stack(Stack *s) {
//     s->top = -1;
// }

// int is_empty(Stack *s) {
//     return s->top == -1;
// }


// int is_full(Stack *s) {
//     return s->top == MAXSTACK - 1;
// }

// int push(Stack *s, int val) {
//     if (is_full(s)) {
//         return 0;
//     }
//     s->top++;
//     s->data[s->top] = val;
//     return 1;
// }

// int pop(Stack *s) {
//     if (is_empty(s)) {
//         return -1;
//     }
//     int val = s->data[s->top];
//     s->top--;
//     retunr val;
// }

// int peek(Stack *s) {
//     if (is_empty(s)) {
//         return -1;
//     }
//     return s->data[s->top];
// }

// void test(void) {
//     init_stack(&s);

//     CU_ASSERT_EQUAL(push(&s, 10), 1);
//     CU_ASSEERT_EQUAL(push(&s, 20), 1);
//     CU_ASSERT_EQUAL(push(&s, 30), 1);

//     CU_ASSERT_EQUAL(pop(&s), 30);
//     CU_ASSERT_EQUAL(pop(&s), 20);
// }

// #ifndef DEBUG
// #define DBG_PRINT(...) do{}while(0)
// #elif DEBUG == 0
// #define DBG_PRINT(...)printf(__VA_ARGS__)
// #elif DEBUG ==1
// #define DBG_PRINF(...)  \
//     do{ \
//         printf("%d", __LINE__); \
//         printf(__VA_ARGS__);    \

//     }
// while (0)
// #else 
// #define DBG_PRINT(...) do{}while(0)
// #endif

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// struct image{
//     unsigned int width;
//     unsigned int height;
//     unsigned int bpp;
//     unsigned char *pixels;
// };

// struct image *read_image(const char *filename){
//     FILE *f= fopen(filename, "rb");
//     if(f==NULL){
//         fprintf(stderr, "Impossible d'ouvrir le fichier..\n");
//         return NULL;
//     }

//     if


// }

#include <stdio.h>
#include <stdlib.h>

// struct Record {
//     int score;
//     char name[20];
// };

// struct Record *read_record(const char *filename) {
//     FILE *f = // ???

//     if (!f) {
//         // stderr'e hata yaz
//         return NULL;
//     }

//     struct Record *r = // malloc

//     if (!r) {
//         // hata
//         // dosyayı kapat!
//         return NULL;
//     }

//     // fread ile struct'ı tek seferde oku
//     // VEYA score ve name'i ayrı ayrı oku

//     fclose(f);
//     return r;
// }

// struct Record {
//     int score;
//     char name[20];
// };

// struct Record *read_record(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {
//         fprintf(stderr, "Erreur...%s\n", filename);
//         return NULL;
//     }

//     struct Record *rec = (struct Record *)malloc(sizeof(struct Record));
//     if (rec == NULL) {
//         fprintf(stderr, "Erreur....%s\n", filename);
//         fclose(f);
//         return NULL;
//     }

//     if (fread(rec, sizeof(struct Record), 1, f) != 1) {
//         fprintf(stderr, "Erreur...");
//         free(rec);
//         fclose(f);
//         return NULL;
//     }

//     fclose(f);
//     return rec;
// }

// #include <stdlib.h>


// struct Record {
//     int score;
//     char name[20];
// };

// struct Record *read_record(const char *file_name) {
//     FILE *f = fopen(file_name, "rb");
//     if (f == NULL) {
//         fprintf(stderr, "error...impossoible d'ouvrir le fichier%s\n", file_name);
//         return NULL;
//     }

//     struct Record *rec = malloc(sizeof(struct Record));

//     if (rec == NULL) {
//         fprintf(stderr, "error...");
//         fclose(f);
//         return NULL;
//     }

//     if (fread(rec, sizeof(struct Record), 1, f) != 1) {
//         if (f == NULL) {
//             fprintf(stderr, "error...impossoible d'ouvrir le fichier%s\n", file_name);
//             free(rec);
//             fclose(f);
//             return NULL;
//         }
//     }

//    fclose(f);
//    return rec;
// }

// #include <stdio.h>

// #include <stdlib.h>

// struct Record {
//     int score;
//     char name[20];
// };

// struct Record *read_record(const char *file_name) {
//     FILE *f = fopen(file_name, "rb");
//     if (f == NULL) {
//         fprintf(stderr, "error...\n");
//         return NULL;
//     }

//     struct Record *rec = malloc(sizeof(struct Record));
//     if (rec == NULL) {
//         fprintf(stderr, "error...\n");
//         fclose(f);
//         return NULL;
//     }

//     if (fread(rec, sizeof(struct Record), 1, f) != 1) {

//         fprintf(stderr, "error...\n");
//         free(rec);
//         fclose(f);
//         return NULL;
//     }

//     fclose(f);
//     return rec;

// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Notes {
//     int n;
//     float *vals;
// };

// struct Notes *read_notes(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {
//         fprintf(stderr, "Error...\n");
//         return NULL;
//     }

//     struct Notes *img = malloc(sizeof(struct Notes));
//     if (img == NULL) {
//         fprintf(stderr, "Error...\n");
//         fclose(f);
//         return NULL;
//     }

//     if (fread(img->n, sizeof(int), 1, f) != 1) {
//         fprintf(stderr, "Error...\n");
//         free(img);
//         fclose(f);
//         return NULL;
//     }

//     if (img->n <= 0) {
//         fprintf(stderr, "error..\n");
//         free(img);
//         fclose(f);
//         return NULL;
//     }

//     img->vals = malloc(img->n * sizeof(float));
//     if (img->vals == NULL) {
//         fprintf(stderr, "error..\n");
//         free(img);
//         fclose(f);
//         return NULL;
//     }

//     if (fread(img->vals, sizeof(float), img->n, f) != img->n) {
//         fprintf(stderr, "Hata: Dizi elemanlari eksik veya hatali okundu.\n");
//         free(img->vals);
//         free(img);
//         fclose(f);
//         return NULL;
//     }

//     fclose(f);
//     return img;



// }

#include <stdio.h>
#include <stdlib.h>

// struct Notes {
//     int n;
//     float *vals;
// };

// struct Notes *read_notes(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {
//         fprintf(stderr, "Error ...\n");
//         return NULL;
//     }

//     struct Notes *notes = malloc(sizeof(struct Notes));
//     if (notes == NULL) {
//         fprintf(stderr, "Error ...\n");
//         fclose(f);
//         return NULL;
//     }

//     if (fread(&(notes->n), sizeof(int), 1, f) != 1) {
//         fprintf(stderr, "Error ...\n");
//         free(notes);
//         fclose(f);
//         return NULL;
//     }

//     notes->vals = malloc(notes->n * sizeof(float));
//     if (notes->vals == NULL) {
//         fprintf(stderr, "Error ...\n");
//         free(notes);
//         fclose(f);
//         return NULL;
//     }

//     if(fread(notes->vals, sizeof(float), notes->n, f) != (size_t)notes->n){
//         fprintf(stderr, "Erreur : Impossible de lire les donnees (float)\n");

//         // ZİNCİRLEME TEMİZLİK (Sıfır bellek sızıntısı kuralı)
//         free(notes->vals); // İçteki dinamik diziyi sil
//         free(notes);       // Dıştaki ana struct'ı sil
//         fclose(f);         // Dosyayı kapat
//         return NULL;
//     }

//     fclose(f);
//     return notes;
// }


// #include <stdint.h>

// struct Image {
//     uint32_t w;
//     uint32_t h;
//     uint32_t bpp;
//     unsigned char *pixels;
// };

// struct Image *read_image(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {
//         fprintf(stderr, "Error..\n");
//         return NULL;
//     }


//     uint32_t header[3];
//     if (fread(header, sizeof(uint32_t), 3, f) != 3) {
//         fprintf(stderr, "Error..\n");
//         fclose(f);
//         return NULL;
//     }

//     uint32_t w = header[0];
//     uint32_t h = header[1];
//     uint32_t bpp = header[2];

//     if (w == 0 || h == 0 || bpp == 0) {
//         fprintf(stderr, "error..\n");
//         fclose(f);
//         return NULL;
//     }

//     struct Image *img = malloc(sizeof(struct Image));
//     if (img == NULL) {
//         fprintf(stderr, "Error..\n");
//         fclose(f);
//         return NULL;
//     }
//     img->w = w;
//     img->h = h;
//     img->bpp = bpp;

//     size_t total_bytes = (size_t)(w * h * bpp);

//     img->pixels = malloc(total_bytes);
//     if (img->pixels = NULL) {
//         fprintf(stderr, "Impossible d'allouer la mémoire\n");
//         free(img);
//         fclose(f);
//         return NULL;
//     }

// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int sample_rate;
//     int nb_samples;
//     short *samples;

// }Audio;

// void write_audio(Audio *a, const char *filename) {
//     FILE *f = fopen(filename, "wb");
//     if (f == NULL) {
//         fprintf(stderr, "Imposible d'ouvrir le fichier..\n");
//         return;
//     }

//     fwrite(&a->sample_rate, sizeof(int), 1, f);

//     fwrite(&a->nb_samples, sizeof(int), 1, f);

//     fwrite(a->samples, sizeof(short), a->nb_samples, f);

//     fclose(f);
// }

// Audio *read_audio(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {

//         fprintf(stderr, "Impossible...\n");
//         return NULL;
//     }

//     int sr;
//     if (fread(&sr, sizeof(int), 1, f) != 1) {
//         fprintf(stderr, "Impossible...\n");
//         fclose(f);
//         return NULL;
//     }

//     int nb;
//     if (fread(&nb, sizeof(int), 1, f) != 1) {
//         fprintf(stderr, "Impossible...\n");
//         fclose(f);
//         NULL;
//     }

//     Audio *a = malloc(sizeof(Audio));
//     if (!a) {
//         fprintf(stderr, "Impossible..\n");
//         fclose(f);
//         return NULL;
//     }

//     a->sample_rate = sr;
//     a->nb_samples = nb;

//     a->samples = malloc(nb * sizeof(short));
//     if (a->samples == NULL) {
//         fprintf(stderr, "impossible...\n");
//         free(a);
//         fclose(f);
//         return NULL;
//     }

//     if (fread(a->samples, sizeof(short), nb, f) != nb) {
//         fprintf(stderr, "impossibles...");
//         free(a->samples);
//         free(a);
//         fclose(f);
//         return NULL;

//     }

//     fclose(f);
//     return a;
// }
// #include <stdio.h>
// #include <stdlib.h>

// struct Audio {
//     int sample_rate;
//     int nb_samples;
//     short *samples;
// };

// void write_audio(const struct Audio *a, const char *filename) {
//     FILE *f = fopen(filename, "wb");
//     if (f == NULL) return;
//     fwrite(&a->sample_rate, sizeof(int), 1, f);
//     fwrite(&a->nb_samples, sizeof(int), 1, f);
//     fwrite(&a->samples, sizeof(short), a->nb_samples, f);
//     fclose(f);
// }

// struct Audio *read_audio(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) return NULL;

//     int sr, nb;
//     if (fread(&sr, sizeof(int), 1, f) != 1 ||
//         fread(&nb, sizeof(int), 1, f) != 1) {
//         fclose(f);
//         return NULL;
//     }

//     if (nb <= 0) {
//         fclose(f);
//         return NULL;
//     }
// }


// struct Audio *read_audio(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (!f) return NULL;


//     int sr, nb;

//     if (fread(&sr, sizeof(int), 1, f) != 1 ||
//         fread(&nb, sizeof(int), 1, f) != 1) {
//         fclose(f);
//         return NULL;
//     }

//     if (nb <= 0) {
//         fclose(f);
//         return NULL;
//     }

//     struct Audio *a = malloc(sizeof(struct Audio));
//     if (!a) {
//         fclose(f);
//         return NULL;
//     }
//     a->sample_rate = sr;
//     a->nb_samples = nb;

//     a->samples = malloc(nb * sizeof(short));

//     if (!a->samples) {
//         free(a);
//         fclose(f);
//         return NULL;
//     }

//     if (fread(a->samples, sizeof(short), nb, f) != (size_t)nb) {
//         free(a->samples);
//         free(a);
//         fclose(f);
//         return  NULL;
//     }
// }


// #include <stdio.h>
// #include <stdlib.h>
// struct Audio {
//     int sample_rate;
//     int nb_samples;
//     short *samples;
// };


// struct Audio *write_audio(const struct Audio *a, const char *filename) {
//     FILE *f = fopen(filename, "wb");
//     if (!f) {
//         fprintf(stderr, "Impossible...\n");
//         return NULL;
//     }
//     fwrite(&a->sample_rate, sizeof(int), 1, f);
//     fwrite(&a->nb_samples, sizeof(int), 1, f);
//     fwrite(a->samples, sizeof(short), a->nb_samples, f);
//     fclose(f);
// }

// struct Audio *read_audio(const char *filename) {
//     FILE *f = fopen(filename, "rb");
//     if (f == NULL) {
//         return NULL;
//     }

//     int sr, nb;


//     if (fread(&sr, sizeof(int), 1, f) != 1) {
//         fclose(f);
//         return NULL;
//     }


//     if (fread(&nb, sizeof(int), 1, f) != 1) {
//         fclose(f);
//         return NULL;
//     }

//     struct Audio *a = malloc(sizeof(struct Audio));
//     if (a == NULL) {
//         fclose(f);
//         return NULL;
//     }
//     a->sample_rate = sr;
//     a->nb_samples = nb;
//     a->samples = malloc(nb * sizeof(short));

//     if (a->samples) {
//         free(a);
//         fclose(f);
//         return NULL;
//     }

//     if (fread(a->samples, sizeof(short), nb, f) != (size_t)nb) {
//         free(a->samples);
//         free(a);
//         fclose(f);
//         return NULL;
//     }

//     fclose(f);
//     return a;

// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Student {
//     int id;
//     char name[50];
//     float grade;
// };

// int read_student(FILE *f, int index, struct Student *out) {

//     if (!f || !out || index < 0)return;

//     long offset = sizeof(int) + index * sizeof(struct Student);

//     if (fseek(f, offset, SEEK_SET) != 0) return 0;

//     return 1;
// }

// int update_grade(FILE *f, int index, float new_grade) {
//     if (!f || index < 0) return 0;

//     long offset = sizeof(int) + index * sizeof(struct Student) + sizeof(int) + 50;

//     if (fseek(f, offset, SEEK_SET) != 0) return 0;
//     if (fwrite(&new_grade, sizeof(float), 1, f) != 1) return 0;
//     return 0;
// }



// #include <stdint.h>
// #include <stdlib.h>
// // #include <CUnit/CUnit.h>
// // #include <CUnit/Basic.h>

// struct Image{
//     uint32_t w;
//     uint32_t h;
//     uint32_t bpp;
//     uint32_t pixels[];
// };

// struct Image *read_image(const char *filename);
// void init_image_file(void);



// void test_read_valid(void){
//     init_image_file();

//     struct Image *img = read_image("Image1.img");

//     CU_ASSERT_PTR_NOT_NULL(img);

//     if(!img==NULL){
//         CU_ASSERT_TRUE(img->h>0);
//          CU_ASSERT_TRUE(img->w>0);

//          free(img);
//     }
// }


// int main(){
//     if(CUE_SUCCESS != CU_initialize_registry()){
//         return CU_get_error();
//     }

//     CU_pSuite suite = CU_add_suite("Read_Image_Suite", NULL, NULL);
//     if(suite ==NULL){
//         CU_cleanup_registry();

//         return CU_get_error();
//     }

//     CU_add_test(suite, "gecerli test", test_read_valid);
//     Cu_add_test(suite, "Gecersiz", test_read_invalide);

//     CU_basic_set_mode(CU_BRM_VERBOSE);
//     CU_basic_run_tests();

//     CU_cleanup_registry();
//     return CU_get_error();
// }

#include <stdlib.h>
// #include <CUnit/CUnit.h>
// #include <CUnit/Basic.h>
int calculer(int a, int b, char op);

void test_addition(void) {

    CU_ASSERT_EQUAL(calculer(3, 4, '+'), 7);
    CU_ASSERT_EQUAL(calculer(3, 4, '+'), 7);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Calculatrice test", NULL, NULL);

    CU_add_test(suite, "test addition", test_addition);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
