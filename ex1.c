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
