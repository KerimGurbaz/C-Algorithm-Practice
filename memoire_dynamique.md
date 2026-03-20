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
            for (int k = 0; k < i; ++k) free(tab[k]);
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
