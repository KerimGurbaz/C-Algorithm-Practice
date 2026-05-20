```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int countc(FILE *f) {
    int c;
    int count = 0;

    // AMPUL 1: Karakterleri okuyan değişken (c) ASLA 'char' tipinde tanımlanmaz.
    // 'int' olmalıdır çünkü dosya sonu işareti olan EOF genelde -1'dir.
    // Char kullanırsan 255 değerli ASCII karakterlerle EOF birbirine karışır (Sonsuz döngü).
    while ((c = fgetc(f)) != EOF) {
        count++;
    }
    return count;
}

int countw(FILE *f) {
    int c;
    int count = 0;
    bool in_word = false; // State Machine (Durum Makinesi) anahtarı

    // AMPUL 2: Kelime saymak boşluk saymak değildir. Yan yana 5 boşluk 1 kelime etmez.
    // 'in_word' bayrağı ile boşlukta yürüme (false) ve kelimeye çarpma (true) durumlarını izleriz.
    while ((c = fgetc(f)) != EOF) {
        // isspace() fonksiyonu <ctype.h> nimetidir. Boşluk, tab (\t), alt satır (\n) hepsini yakalar.
        if (isspace(c)) {
            in_word = false; // Kelimeden çıktık
        } else if (!in_word) {
            in_word = true;  // Yeni bir kelimeye girdik
            count++;
        }
    }
    return count;
}

int countl(FILE *f) {
    int c;
    int count = 0;

    // AMPUL 3: Dosyalarda fiziksel olarak "Satır" diye bir yapı yoktur.
    // İşletim sistemi dosyayı tek bir ip gibi görür. Biz sadece o ipin üzerindeki '\n' düğümlerini sayarız.
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {

    // Argüman kontrolü hayati güvenlik adımıdır.
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    // open file for reading
    FILE *fin = fopen(argv[1], "r");
    // AMPUL 4: Dosya açılışını kontrol etmemek Segmentation Fault'a (çökmeye) davetiyedir.
    if (!fin) {
        perror("Error opening file");
        return 1;
    }

    // count characters in file
    printf("%s contains %d characters\n", argv[1], countc(fin));

    // reopen file and count words
    // AMPUL 5: İmleç sona dayandığı için freopen ile dosyayı OS seviyesinde kapatıp aynı pointer'a tekrar atıyoruz. (Pahalı ve yavaş işlem).
    fin = freopen(argv[1], "r", fin);
    if (!fin) return 1;
    printf("%s contains %d words\n", argv[1], countw(fin));

    // rewind can be used in place of freopen to move at the beginning
    // AMPUL 6: rewind, işletim sistemini yormaz. RAM'deki okuma imlecini (cursor) doğrudan 0. byte'a ışınlar. (Verimli ve profesyonel yöntem).
    rewind(fin);
    printf("%s contains %d lines\n", argv[1], countl(fin));
    // fseek(f, 0, SEEK_SET);

    // closing
    // AMPUL 7: fclose kullanılmazsa dosya "kilitli" kalır ve işletim sisteminde "Memory Leak" (Bellek sızıntısı) başlar.
    fclose(fin);

    return 0;
}

```

```c
#include <stdio.h>
#include <errno.h>

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
} etudiant;

void lire_etudiant_index(const char *filename, int index) {
    // 1. Dosyayı "rb" modunda aç
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        perror("Fichier introuvable");
        return; // DÜZELTME 2: void olduğu için sadece return
    }

    // DÜZELTME 1: Boyutu bulmak için önce imleci dosyanın sonuna gönder
    fseek(f, 0, SEEK_END);
    long taille = ftell(f);
    int nbEtudiant = (int)(taille / sizeof(etudiant));

    // DÜZELTME 3: Geçerli bir indeks mi? (Sınırları aşma kontrolü)
    if (index < 0 || index >= nbEtudiant) {
        printf("Erreur : Index invalide. Il y a %d etudiants.\n", nbEtudiant);
        fclose(f); // Çıkmadan önce dosyayı kapatmayı unutma!
        return;
    }

    etudiant student;

    // 4. İmleci baştan (SEEK_SET) başlayarak hedef indekse kaydır
    fseek(f, index * sizeof(etudiant), SEEK_SET);

    // 5. Kaydı oku
    fread(&student, sizeof(etudiant), 1, f);

    // 6. Bilgileri yazdır (Sorunun senden istediği son adım)
    printf("--- Etudiant %d ---\n", index);
    printf("ID      : %d\n", student.id);
    printf("Nom     : %s\n", student.nom);
    printf("Prenom  : %s\n", student.prenom);
    printf("Moyenne : %.2f\n", student.moyenne);

    // 7. Dosyayı kapat
    fclose(f);
}

```

```c
#include <stdio.h>
#include <errno.h>

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
} etudiant_t;

void mettre_a_jour_moyenne(const char *filename, int id, float nouvelle_moyenne) {
    // 1. "r+b" modu: Dosya zaten var olmali (r), hem okunup hem yazilabilmeli (+) ve binary formatta (b).
    FILE *f = fopen(filename, "r+b");
    if (f == NULL) {
        perror("Dosya acilirken hata olustu");
        return;
    }

    etudiant_t student;

    // 2. Sequential (Sirali) Arama
    // Dosya sonuna kadar veya eslesme bulunana kadar her kaydi sirayla oku.
    while (fread(&student, sizeof(etudiant_t), 1, f) == 1) {

        if (student.id == id) {
            // RAM uzerindeki yapiyi (struct) guncelle
            student.moyenne = nouvelle_moyenne;

            // 3. Imleci Geri Alma (Rewind the Cursor)
            // Okuma yaptigimiz icin imlec su an bir SONRAKI kaydin basinda.
            // Uzerine yazmak icin mevcut pozisyondan (SEEK_CUR) 1 kayit boyutu kadar geriye (-) gidiyoruz.
            fseek(f, -(long)sizeof(etudiant_t), SEEK_CUR);

            // 4. Overwrite (Uzerine Yazma)
            // Guncellenmis veriyi diske yaz.
            fwrite(&student, sizeof(etudiant_t), 1, f);

            printf("Basarili: ID %d olan ogrencinin yeni ortalamasi %.2f olarak guncellendi.\n", id, student.moyenne);

            // Hedefi bulduk ve guncelledik, dosyayi gereksiz okumamak icin donguden cikiyoruz.
            break;
        }
    }

    // 5. Temizlik
    fclose(f);
}

```

```c
#include <stdio.h>
#include <errno.h>

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
} etudiant_t;

void lire_a_rebours(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    // Dosya boyutunu ve eleman sayısını bulma
    fseek(f, 0, SEEK_END);
    long taille = ftell(f);
    int nb_etudiant = (int)(taille / sizeof(etudiant_t));

    etudiant_t student;

    // Sondan başa doğru indeksleri say
    for (int i = nb_etudiant - 1; i >= 0; --i) {
        // DÜZELTME 1: Dosyanın BAŞINDAN itibaren (SEEK_SET) hesaplanan adrese atla
        fseek(f, i * sizeof(etudiant_t), SEEK_SET);

        // Kaydı oku
        fread(&student, sizeof(etudiant_t), 1, f);

        // DÜZELTME 2: Etiketleri doğru yazdır
        printf("--- Etudiant %d ---\n", i);
        printf("ID      : %d\n", student.id);
        printf("Nom     : %s\n", student.nom);
        printf("Prenom  : %s\n", student.prenom);
        printf("Moyenne : %.2f\n", student.moyenne);
    }

    fclose(f);
}

```

```c
#include <stdio.h>
#include <errno.h>

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
} etudiant_t;

int fusionner_fichiers(const char *fichier1, const char *fichier2, const char *fichier_sortie) {
    // 1. Çıkış dosyasını "wb" (Write Binary) modunda aç
    FILE *f_out = fopen(fichier_sortie, "wb");
    if (!f_out) {
        perror("Erreur: Impossible de creer le fichier de sortie");
        return -1;
    }

    int total_records = 0;
    etudiant_t student;

    // 2. Birinci dosyayı aç ve kopyala
    FILE *f1 = fopen(fichier1, "rb");
    if (f1) {
        // Okuma başarılı oldukça (1 döndürdükçe) döngüye gir
        while (fread(&student, sizeof(etudiant_t), 1, f1) == 1) {
            // DİKKAT: Yazma işlemi de başarılı olmalı
            if (fwrite(&student, sizeof(etudiant_t), 1, f_out) == 1) {
                total_records++;
            } else {
                // Disk doldu veya yazma hatası
                break;
            }
        }
        fclose(f1); // 4. Birinciyi kapat
    } else {
        perror("Avertissement: Fichier 1 introuvable");
        // Programı durdurmuyoruz, belki sadece dosya 2 vardır.
    }

    // 5. İkinci dosyayı aç ve kopyala
    FILE *f2 = fopen(fichier2, "rb");
    if (f2) {
        while (fread(&student, sizeof(etudiant_t), 1, f2) == 1) {
            if (fwrite(&student, sizeof(etudiant_t), 1, f_out) == 1) {
                total_records++;
            } else {
                break;
            }
        }
        fclose(f2); // 7. İkinciyi kapat
    } else {
        perror("Avertissement: Fichier 2 introuvable");
    }

    // 8. Çıkış dosyasını kapat ve toplamı döndür
    fclose(f_out);
    return total_records;
}

```

```c
// /src/image.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// 1. Flexible Array Member (Esnek Dizi Elemanı) kullanımı zorunludur.
// main() fonksiyonunda sadece free(image) çağrıldığı için, struct ve
// pixel verisi tek bir malloc ile bitişik tahsis edilmelidir.
struct Image {
    uint32_t width;
    uint32_t height;
    uint32_t bpp;
    uint8_t pixels[]; // Boyutu çalışma zamanında belirlenecek
};

struct Image *read_image(const char *filename) {
    // Dosyayı Binary (rb) modda açmak hayati önem taşır
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Impossible d'ouvrir le fichier\n");
        return NULL;
    }

    // Header: W (4 byte), H (4 byte), BPP (4 byte)
    uint32_t header[3];
    if (fread(header, sizeof(uint32_t), 3, f) != 3) {
        fprintf(stderr, "Impossible de lire le header\n");
        fclose(f);
        return NULL;
    }

    uint32_t w = header[0];
    uint32_t h = header[1];
    uint32_t bpp = header[2];

    // Pixel verisinin toplam bayt boyutunu hesapla
    size_t total_bytes = (size_t)w * h * bpp;

    // Struct başlığı + Pixel verisi için tek bir yekpare bellek bloğu ayır
    struct Image *img = malloc(sizeof(struct Image) + total_bytes);
    if (!img) {
        fprintf(stderr, "Impossible d'allouer la mémoire\n");
        fclose(f);
        return NULL;
    }

    img->width = w;
    img->height = h;
    img->bpp = bpp;

    // Tüm pikselleri tek seferde esnek diziye (pixels) oku
    if (total_bytes > 0 && fread(img->pixels, 1, total_bytes, f) != total_bytes) {
        fprintf(stderr, "Impossible de lire les pixels\n");
        free(img);
        fclose(f);
        return NULL;
    }

    // Her durumda dosyayı kapat ve başarılı okunan resmi döndür
    fclose(f);
    return img;
}

void image_info(struct Image* image) {
    if (!image) return;

    printf("Taille: %u x %u\n", image->width, image->height);
    printf("BPP : %u\n", image->bpp);

    size_t num_pixels = (size_t)image->width * image->height;
    if (num_pixels == 0) return;

    // Her bir renk bileşeni (0, 1, 2...) için ayrı ayrı dolaş
    for (uint32_t c = 0; c < image->bpp; ++c) {
        double sum = 0.0;

        // Bellekteki doğru komponente atlayarak (BPP kadar ilerleyerek) oku
        for (size_t p = 0; p < num_pixels; ++p) {
            sum += image->pixels[p * image->bpp + c];
        }

        // Ortalamayı yazdır (%f double yazdırır)
        printf("Valeur moyenne composante %u : %f\n", c, sum / num_pixels);
    }
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
