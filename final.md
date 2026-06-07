```c
#include <stdio.h>

void fibo(int n) {
    int premier = 0;
    int seconde = 1;
    int suivant; // Gelecekteki sayıyı tutmak için

    // Tam olarak 'n' defa dönecek bir döngü kuruyoruz
    for (int i = 0; i < n; i++) {
        // Adım 1: Mevcut terimi yazdır
        printf("%d ", premier);

        // Adım 2: Bir sonraki sayıyı hesapla
        suivant = premier + seconde;

        // Adım 3: Pencereyi sağa kaydır (Değişkenleri güncelle)
        // Dikkat: Kaydırma sırası önemlidir. Önce premier güncellenmeli.
        premier = seconde;
        seconde = suivant;
    }
    printf("\n"); // Çıktıyı temiz bitirmek için yeni satır
}

int main() {
    int n;
    printf("Entrez une valeur : "); // Kullanıcı dostu ve dilbilgisi düzeltilmiş mesaj

    // Güvenli girdi alma. Girdi rakam değilse veya negatifse sonlandır.
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Erreur : Veuillez entrer un entier positif.\n");
        return 1;
    }

    fibo(n);

    return 0;
}

```

```c
#include <stdio.h>

/**
 * Bir dizideki minimum ve maksimum değerleri TEK geçişte bulur.
 *
 * @param tab  İncelenecek dizi (const: değiştirilmeyecek)
 * @param size Dizinin boyutu
 * @param mn   Minimum değerin YAZILACAĞI adres (çıktı parametresi)
 * @param mx   Maksimum değerin YAZILACAĞI adres (çıktı parametresi)
 */
void trouver_min_max(const int tab[], int size, int *mn, int *mx) {

    // İlk elemanı başlangıç değeri olarak ata
    *mn = tab[0];  // pointer'ın gösterdiği yere tab[0] yaz
    *mx = tab[0];  // pointer'ın gösterdiği yere tab[0] yaz

    // 1. indexten başla (0'ı zaten atadık)
    for (int i = 1; i < size; i++) {

        // Maksimumdan büyük bir değer bulundu mu?
        if (tab[i] > *mx) {
            *mx = tab[i];  // Maksimumu güncelle
        }

        // Minimumdan küçük bir değer bulundu mu?
        if (tab[i] < *mn) {
            *mn = tab[i];  // Minimumu güncelle
        }
    }
    // Fonksiyon bitince mn ve mx güncellenmiş olur!
}

/**
 * Diziyi ekrana yazdırır
 */
void afficher_tableau(const int tab[], int size) {
    printf("Tableau: [");
    for (int i = 0; i < size; i++) {
        printf("%d", tab[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    // Test dizisi
    int tab[] = {12, 5, 8, 19, 1, 7};

    // Dizi boyutunu hesapla (toplam byte / bir elemanın byte'ı)
    int size = sizeof(tab) / sizeof(tab[0]);

    // Minimum ve maksimum için değişkenler (BOŞ!)
    int minimum = 0;
    int maximum = 0;

    // Diziyi göster
    afficher_tableau(tab, size);
    printf("Taille du tableau: %d elements\n\n", size);

    // Fonksiyonu çağır: değişkenlerin ADRESLERİNİ geç!
    trouver_min_max(tab, size, &minimum, &maximum);
    //                          │         │
    //                          │         └─ maximum'un adresi
    //                          └─ minimum'un adresi

    // Fonksiyon içinde *mn ve *mx bu değişkenleri GÜNCELLEDİ!
    printf("Resultats:\n");
    printf("  Valeur minimale: %d\n", minimum);
    printf("  Valeur maximale: %d\n", maximum);

    // Doğrulama
    printf("\nVerification: min=1, max=19 → %s\n",
           (minimum == 1 && maximum == 19) ? "CORRECT ✓" : "ERREUR ✗");

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
