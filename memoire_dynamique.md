```c
#include <stdio.h>
#include <stdlib.h>

#define TAILLE 7

int main(void) {
    int source[TAILLE] = { 12, 7, 9, 24, 8, 33, 42 };
    size_t nb_pairs = 0;

    // 1. DÜZELTME: Maksimum kapasite kadar RAM'den yer rezerve ediyoruz (Allocation)
    int *pairs = malloc(TAILLE * sizeof(int));
    if (pairs == NULL) return 1;

    // 2. Artık pairs geçerli bir bellek adresi, içine güvenle yazabiliriz
    for (int i = 0; i < TAILLE; ++i) {
        if (source[i] % 2 == 0) {
            pairs[nb_pairs++] = source[i];
        }
    }

    // 3. SHRINK-TO-FIT (Fazlalığı Kesmek)
    // Eğer hiç çift sayı bulamadıysak (nb_pairs == 0), realloc(0) tehlikelidir, free yaparız.
    if (nb_pairs == 0) {
        free(pairs);
        pairs = NULL;
    } else {
        // Sadece bulduğumuz miktar kadar küçültüyoruz
        int *temp = realloc(pairs, nb_pairs * sizeof(int));
        if (temp != NULL) {
            pairs = temp;
        }
    }

    // 4. EKRANA YAZDIRMA
    if (nb_pairs > 0) {
        printf("Nombres pairs trouves : ");
        for (size_t i = 0; i < nb_pairs; i++) {
            printf("%d ", pairs[i]);
        }
        printf("\n");
    } else {
        printf("Aucun nombre pair trouve.\n");
    }

    free(pairs);
    return 0; // Başarı!
}

```

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    int lignes;
    int colonnes;

    if (scanf("%d", &lignes) != 1 || lignes <= 0) return 1;
    if (scanf("%d", &colonnes) != 1 || colonnes <= 0) return 1;

    // ==========================================
    // 1. MATRICE ORIGINALE (L x C)
    // ==========================================
    int **tab = malloc(lignes * sizeof(int *));
    if (tab == NULL) return 1;

    for (int i = 0; i < lignes; ++i) {
        tab[i] = malloc(colonnes * sizeof(int));
        if (tab[i] == NULL) {
            for (int k = 0; k < i; ++k)
            {
                free(tab[k]);
            }
            free(tab);
            return 1;
        }
    }

    // ==========================================
    // 2. MATRICE TRANSPOSEE (C x L) -> BOYUTLAR TERS!
    // ==========================================
    int **tr = malloc(colonnes * sizeof(int *));
    if (tr == NULL) {
        // Hata yönetimi: tr başarısız olursa, eski tab'ı tamamen sil!
        for (int i = 0; i < lignes; ++i) free(tab[i]);
        free(tab);
        return 1;
    }

    for (int i = 0; i < colonnes; ++i) { // DÜZELTME: Satır sayısı artık 'colonnes'
        tr[i] = malloc(lignes * sizeof(int)); // DÜZELTME: Sütun sayısı artık 'lignes'
        if (tr[i] == NULL) {
            for (int k = 0; k < i; ++k) free(tr[k]);
            free(tr);
            // tab'ı da silmeyi unutma
            for (int k = 0; k < lignes; ++k) free(tab[k]);
            free(tab);
            return 1;
        }
    }

    // ==========================================
    // 3. LECTURE ET TRANSPOSITION
    // ==========================================
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            if (scanf("%d", &tab[i][j]) != 1) {
                // Temizlik
                for (int k = 0; k < lignes; ++k) free(tab[k]);
                free(tab);
                for (int k = 0; k < colonnes; ++k) free(tr[k]);
                free(tr);
                return 1;
            }
            // Transpoze ataması (Mantığın kusursuz)
            tr[j][i] = tab[i][j];
        }
    }

    // ==========================================
    // 4. AFFICHAGE
    // ==========================================
    printf("\nMatrice Originale :\n");
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            printf("%3d", tab[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrice Transposee :\n");
    for (int i = 0; i < colonnes; ++i) { // DÜZELTME: Limit 'colonnes'
        for (int j = 0; j < lignes; ++j) { // DÜZELTME: Limit 'lignes'
            printf("%3d", tr[i][j]);
        }
        printf("\n");
    }

    // ==========================================
    // 5. LIBERATION
    // ==========================================
    for (int i = 0; i < lignes; ++i) free(tab[i]);
    free(tab);

    for (int i = 0; i < colonnes; ++i) free(tr[i]); // DÜZELTME: Limit 'colonnes'
    free(tr);

    return 0; // Başarı!
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// --- DEBUT PARTIE A COMPLETER -----------------------------------------------

/* =========================================================================
 * 🔴 HAP BİLGİ (Retour multiple) :
 * C dilinde birden fazla değer döndürmenin yolu, o değerlerin bellekteki
 * adreslerini (*min_ptr, *max_ptr) fonksiyona yollamaktır.
 * Böylece fonksiyon bitse bile main() içindeki değişkenler değişmiş olur.
 * ========================================================================= */

void trouver_min_max(int **matrice, int lignes, int colonnes, int *min_ptr, int *max_ptr) {
    // 1. Güvenlik kontrolü (Matris boş mu?)
    if (matrice == NULL || lignes <= 0 || colonnes <= 0) return;

    // 2. Başlangıç değerlerini INT_MIN / INT_MAX yerine doğrudan matrisin ilk elemanı yapıyoruz.
    // Bu çok daha güvenli ve profesyonel bir tekniktir.
    *min_ptr = matrice[0][0];
    *max_ptr = matrice[0][0];

    // 3. Matrisi gez ve pointer'ların gösterdiği adreslerdeki değerleri güncelle
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            if (matrice[i][j] < *min_ptr) {
                *min_ptr = matrice[i][j]; // Adresteki değeri değiştir
            }
            if (matrice[i][j] > *max_ptr) {
                *max_ptr = matrice[i][j]; // Adresteki değeri değiştir
            }
        }
    }
}

// --- FIN PARTIE A COMPLETER -------------------------------------------------

int main() {
    int lignes = 2, colonnes = 3;
    int **tab = malloc(lignes * sizeof(int *));
    for (int i = 0; i < lignes; i++) tab[i] = malloc(colonnes * sizeof(int));

    // Manuel doldurma (Test için)
    tab[0][0] = 42; tab[0][1] = 7;  tab[0][2] = 88;
    tab[1][0] = -5; tab[1][1] = 14; tab[1][2] = 3;

    int minimum, maximum; // İlk değer atamaya gerek yok, fonksiyon dolduracak

    // Fonksiyonu çağırırken değişkenlerin ADRESLERİNİ (&) gönderiyoruz
    trouver_min_max(tab, lignes, colonnes, &minimum, &maximum);

    printf("Minimum : %d\n", minimum);
    printf("Maximum : %d\n", maximum);

    // Temizlik
    for (int i = 0; i < lignes; i++) free(tab[i]);
    free(tab);

    return 0;
}

```

```c
char *dupliquer_mot(const char *source) {
    if (source == NULL) return NULL;

    size_t longeur = 0;
    const char *ptr = source;
    while (*ptr != '\0') {
        longeur++;
        ptr++;
    }

    char *copie = malloc((longeur + 1) * sizeof(char));
    if (copie == NULL) return NULL;

    const char *ptr_source = source;
    char *ptr_dest = copie;

    while (*ptr_source != '\0') {
        *ptr_dest = *ptr_source;
        ptr_dest++;
        ptr_source++;
    }

    *ptr_dest = '\0';

    return copie;
}


int main() {
    char mot_statique[30];

    printf("Entrez un mot : ");
    if (scanf("%29s", mot_statique) != 1) return 1;

    char *mot_dynamique = dupliquer_mot(mot_statique);
    if (mot_dynamique == NULL) return 1;

    printf("Copie dynamique : %s\n", mot_dynamique);

    free(mot_dynamique);


    return 0;
}


```

```c
#include <stdio.h>

// --- DEBUT PARTIE A COMPLETER -----------------------------------------------

void nettoyer_chaine(char *str) {
    if (str == NULL) return;

    char *lecture = str;
    char *ecriture = str;

    while (*lecture != '\0') {
        char c = *lecture;

        // 1. Karakterin harf veya rakam olup olmadığını kontrol et
        int est_minuscule = (c >= 'a' && c <= 'z');
        int est_majuscule = (c >= 'A' && c <= 'Z');
        int est_chiffre   = (c >= '0' && c <= '9');

        if (est_minuscule || est_majuscule || est_chiffre) {

            // 2. Majuscule ise Minuscule'e çevir
            // ASCII tablosunda büyük harfler ile küçük harfler arasında 32 fark vardır.
            // 'A' (65) + 32 = 'a' (97)
            if (est_majuscule) {
                c = c + 32;
            }

            // Geçerli karakteri yazma pointer'ının gösterdiği yere kaydet
            *ecriture = c;
            ecriture++; // Yazma pointer'ını sadece geçerli bir harf bulduğumuzda ilerletiyoruz
        }

        // Okuma pointer'ı her döngüde bir harf ilerler
        lecture++;
    }

    // Kelimenin yeni sonunu belirle (Geriye kalan çöp karakterleri keser)
    *ecriture = '\0';
}

// --- FIN PARTIE A COMPLETER -------------------------------------------------

int main() {
    char texte[] = "Hello, World! 2026... C'est top.";

    printf("Original : %s\n", texte);
    nettoyer_chaine(texte);
    printf("Nettoye  : %s\n", texte); // Çıktı: helloworld2026cesttop

    return 0;
}


```

```c
#include <stdio.h>
#define N 3

typedef int mat3x3[3][3];

// Const doğruluğu (Const correctness) eklendi
void mat_mult(const mat3x3 a, const mat3x3 b, mat3x3 res) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int somme = 0;
            for (int k = 0; k < N; ++k) {
                somme += a[i][k] * b[k][j];
            }
            res[i][j] = somme;
        }
    }
}

void print_mat(const mat3x3 m) {
    for (int i = 0; i < N; ++i) {
        printf("[");
        for (int j = 0; j < N; ++j) {
            // DÜZELTME 1: int için %d kullanılır (Genişlik için %3d şık durur)
            printf("%3d", m[i][j]);

            // DÜZELTME 2: Magic number '2' yerine 'N - 1'
            if (j < N - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main() {
    mat3x3 a = {
     {1, 2, 3},
     {4, 5, 6},
     {7, 8, 9}
    };

    mat3x3 b = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    mat3x3 res = { 0 };

    mat_mult(a, b, res);
    print_mat(res);

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Retourne 1 si c'est un palindrome, 0 sinon
int est_phrase_palindrome(const char *phrase) {
    if (phrase == NULL) return 0;

    const char *debut = phrase;
    const char *fin = phrase + strlen(phrase) - 1;

    while (debut < fin) {
        // 1. Ignorer tout ce qui n'est pas une lettre par la gauche
        // Attention au piège : il faut revérifier (debut < fin) pour ne pas
        // déborder si la phrase ne contient que des espaces ("   ").
        while (debut < fin && !isalpha(*debut)) {
            debut++;
        }

        // 2. Ignorer tout ce qui n'est pas une lettre par la droite
        while (debut < fin && !isalpha(*fin)) {
            fin--;
        }

        // 3. Comparaison stricte des caractères valides
        if (debut < fin) {
            if (tolower(*debut) != tolower(*fin)) {
                return 0; // Fin immédiate si non-correspondance
            }
            // Passage aux lettres suivantes
            debut++;
            fin--;
        }
    }

    return 1; // Si on a tout traversé sans retourner 0, c'est valide
}

int main(void) {
    // Tests avec des pointeurs constants (Read-only)
    const char *test1 = "Engage le jeu que je le gagne";
    const char *test2 = "Elu par cette crapule!";
    const char *test3 = "Bonjour le monde";

    printf("\"%s\" -> %s\n", test1, est_phrase_palindrome(test1) ? "Palindrome" : "Non");
    printf("\"%s\" -> %s\n", test2, est_phrase_palindrome(test2) ? "Palindrome" : "Non");
    printf("\"%s\" -> %s\n", test3, est_phrase_palindrome(test3) ? "Palindrome" : "Non");

    return 0;
}

```

```c
#include <stdio.h>

// 1. Fonction utilitaire : Convertir en minuscule manuellement (Sans <ctype.h>)
// ASCII tablosunda büyük harfler ile küçük harfler arasında 32 birim fark vardır.
static inline char en_minuscule(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

// 2. Fonction principale de vérification (Const correctness appliquée)
int est_palindrome(const char *mot) {
    if (mot == NULL) return 0;

    const char *debut = mot;
    const char *fin = mot;

    // Trouver la fin du mot (Pointer'ı '\0' karakterine kadar götür)
    while (*fin != '\0') {
        fin++;
    }

    // Eğer kelime boş değilse, fin pointer'ını son harfin üzerine (1 adım geri) al
    if (fin > mot) {
        fin--;
    }

    // Les deux pointeurs convergent vers le centre
    while (debut < fin) {
        // Harfleri küçük harfe çevirerek kıyasla
        if (en_minuscule(*debut) != en_minuscule(*fin)) {
            return 0; // Eşleşme yoksa palindrome değildir (Faux)
        }
        debut++; // Soldakini sağa kaydır
        fin--;   // Sağdakini sola kaydır
    }

    return 1; // Tüm harfler eşleşti (Vrai)
}

int main(void) {
    char mot[100]; // Allocation statique suffisante pour un mot

    printf("[?] Saisir un mot (que des lettres dans [a-z,A-Z]): ");
    // %99s : Buffer overflow koruması (Güvenlik standardı)
    if (scanf("%99s", mot) != 1) return 1;

    // Appel de la fonction et affichage exact selon la consigne
    if (est_palindrome(mot)) {
        printf("[i] %s est un palindrome\n", mot);
    } else {
        printf("[i] %s n'est pas un palindrome\n", mot);
    }

    return 0;
}

```

```c
#include <stdio.h>
#include <ctype.h>

// Fonksiyon: Metni yerinde değiştirir (in-place)
void supprimer_voyelles(char *texte) {
    if (texte == NULL) return;

    int ecriture = 0; // Yazma indeksi (Yavaş ilerler)

    // i: Okuma indeksi (Hızlı ilerler, her harfi kontrol eder)
    for (int i = 0; texte[i] != '\0'; i++) {
        char c = tolower(texte[i]);

        // Eğer karakter sesli harf DEĞİLSE
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')) {
            // Karakteri yazma indeksinin olduğu yere kopyala
            texte[ecriture] = texte[i];
            // Yazma indeksini bir sağa kaydır
            ecriture++;
        }
        // Eğer sesli harfse, if bloğuna girmez, 'ecriture' artmaz, ama 'i' okumaya devam eder.
        // Bu sayede sesli harfler atlanmış olur.
    }

    // EN KRİTİK NOKTA: Yeni string'in sonuna manuel olarak \0 koymak zorundayız.
    // Aksi halde eski string'in kuyruğu ekranda görünmeye devam eder.
    texte[ecriture] = '\0';
}

int main(void) {
    // char *phrase = "Data Engineering" YAPAMAYIZ! (Read-only bellek değiştirilemez)
    // char phrase[] kullanarak Stack'te değiştirilebilir bir dizi oluşturuyoruz.
    char phrase[] = "Data Engineering";

    printf("Avant : %s\n", phrase);

    // Adresi gönderiyoruz
    supprimer_voyelles(phrase);

    printf("Apres : %s\n", phrase);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Yardımcı Fonksiyon: Açan ve kapatan parantez eşleşiyor mu?
int correspond(char ouvrant, char fermant) {
    if (ouvrant == '(' && fermant == ')') return 1;
    if (ouvrant == '[' && fermant == ']') return 1;
    if (ouvrant == '{' && fermant == '}') return 1;
    return 0;
}

// Ana Fonksiyon: Stack (Yığın) kullanarak syntax kontrolü
int verifier_syntaxe(const char *texte) {
    size_t len = strlen(texte);
    if (len == 0) return 1; // Boş string geçerlidir

    // 1. Yığın için dinamik bellek ayır (En kötü ihtimalle hepsi açan parantezdir)
    char *pile = malloc(len * sizeof(char));
    if (pile == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 0;
    }

    int sommet = -1; // Yığının en üstünü gösteren indeks (Stack pointer)
    int est_valide = 1; // Başlangıçta geçerli varsayıyoruz

    // 2. Metni karakter karakter işle
    for (size_t i = 0; i < len; i++) {
        char c = texte[i];

        // Açan sembolleri yığına ekle (Push)
        if (c == '(' || c == '[' || c == '{') {
            sommet++;
            pile[sommet] = c;
        }
        // Kapatan sembolleri kontrol et (Pop)
        else if (c == ')' || c == ']' || c == '}') {
            // Yığın boşsa (Açılmadan kapanıyorsa)
            if (sommet == -1) {
                est_valide = 0;
                break;
            }

            // Yığının en üstündeki elemanla eşleşiyor mu?
            char dernier_ouvrant = pile[sommet];
            if (!correspond(dernier_ouvrant, c)) {
                est_valide = 0; // Eşleşme hatası (Örn: [ )
                break;
            }

            // Eşleştiyse yığından çıkar (Pop)
            sommet--;
        }
    }

    // 3. Döngü bittiğinde yığın tamamen boşalmış olmalı (sommet == -1)
    if (sommet != -1) {
        est_valide = 0; // Kapatılmamış semboller kaldı
    }

    // 4. Bellek temizliği (Zorunlu)
    free(pile);

    return est_valide;
}

int main(void) {
    const char *test1 = "int main() { printf(\"OK[1]\"); }"; // Geçerli
    const char *test2 = "if (a[i) == 0]";                     // Geçersiz (Kesişim)
    const char *test3 = "while (true) {";                    // Geçersiz (Kapatılmamış '{')

    printf("Test 1 : %s -> %s\n", test1, verifier_syntaxe(test1) ? "Valide" : "Invalide");
    printf("Test 2 : %s -> %s\n", test2, verifier_syntaxe(test2) ? "Valide" : "Invalide");
    printf("Test 3 : %s -> %s\n", test3, verifier_syntaxe(test3) ? "Valide" : "Invalide");

    return 0;
}

```

```c
#include <stdio.h>
// DİKKAT: <string.h> eklemiyoruz, yasak!

int main(void) {
    char ligne[256];
    int longueur = 0;
    int position, nb_caracteres;

    printf("[?] Saisissez une ligne de mots: ");

    // 1. fgets ile okuma
    if (fgets(ligne, sizeof(ligne), stdin) == NULL) {
        return 1;
    }

    // 2. Kendi strlen() mantığımızı yazıyoruz ve '\n' karakterini siliyoruz
    while (ligne[longueur] != '\0') {
        if (ligne[longueur] == '\n') {
            ligne[longueur] = '\0'; // Enter karakterini string bitirici ile ez
            break; // Döngüden çık, saymayı bırak
        }
        longueur++;
    }

    // 3. Boş satır kontrolü
    if (longueur == 0) {
        printf("[!] Erreur: ligne vide!\n");
        return 1; // Programı hata koduyla bitir
    }

    printf("[i] La ligne contient %d caracteres.\n", longueur);

    // 4. Pozisyonu alma ve doğrulama (Validation)
    printf("[?] Extraire APRES combien de caracteres? ");
    // scanf 1 değer okuyamazsa (örn 'Z' girilirse) veya sınırlar aşılırsa:
    if (scanf("%d", &position) != 1 || position < 0 || position > longueur) {
        printf("[!] Erreur: position impossible!\n");
        return 1;
    }

    // 5. Kesilecek karakter sayısını alma ve doğrulama
    printf("[?] Extraire combien de caracteres? ");
    // Başlangıç pozisyonu + kesilecek miktar, toplam uzunluğu geçemez!
    if (scanf("%d", &nb_caracteres) != 1 || nb_caracteres < 0 || (position + nb_caracteres > longueur)) {
        printf("[!] Erreur: longueur impossible!\n");
        return 1;
    }

    // 6. Alt metni (Sous-chaîne) çıkarma
    char sous_chaine[256];
    int i;

    // Asıl sihir burada: Eski dizinin (position + i) indeksinden al, yeni dizinin i indeksine yaz.
    for (i = 0; i < nb_caracteres; i++) {
        sous_chaine[i] = ligne[position + i];
    }

    // Yeni oluşturduğumuz string'in sonuna BİTİŞ KARAKTERİNİ koymayı ASLA unutma!
    sous_chaine[i] = '\0';

    // 7. Sonucu yazdırma
    printf("[i] La sous-chaîne extraite de la chaîne est : \"%s\"\n", sous_chaine);

    return 0;
}

```

```c


```
