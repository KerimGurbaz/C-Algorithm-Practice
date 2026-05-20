```c
#include <stdio.h>
#include <stdlib.h> // İpucu 2: malloc kullanacağımız için şart!

struct Record {
    int score;
    char name[20];
};

struct Record *read_record(const char *filename) {
    // ----------------------------------------------------
    // Aşama 1: AÇ (Open)
    // ----------------------------------------------------
    // İpucu 1: .bin uzantısı gördük, modu "rb" yaptık.
    FILE *fp = fopen(filename, "rb");

    // İpucu 3: Başarısızlık testi zorunlu!
    if (fp == NULL) {
        printf("Hata: Dosya acilamadi.\n");
        return NULL; // Hata durumunda erkenden çıkış
    }

    // ----------------------------------------------------
    // Aşama 2: AYIR (Allocate)
    // ----------------------------------------------------
    // İpucu 2: Fonksiyon struct Record* döndüreceği için o boyutta yer ayırıyoruz.
    struct Record *rec = malloc(sizeof(struct Record));

    // İpucu 3: Malloc her zaman NULL dönebilir, koruma duvarı şart.
    if (rec == NULL) {
        printf("Hata: Bellek tahsis edilemedi.\n");
        fclose(fp); // ÖNEMLİ: Yukarıda açtığımız dosyayı kapatıp öyle çıkmalıyız!
        return NULL;
    }

    // ----------------------------------------------------
    // Aşama 3: OKU (Read)
    // ----------------------------------------------------
    // Sihirli Sorularımızı soruyoruz:
    // 1. Nereye yaz? malloc ile ayırdığımız 'rec' adresine.
    // 2. Bir eleman kaç byte? sizeof(struct Record) yani 24 byte.
    // 3. Kaç eleman? Sadece 1 tane kayıt okuyoruz.
    // 4. Hangi dosya? 'fp' isimli dosyadan.

    // fread okuduğu eleman sayısını döner. 1 eleman bekliyorduk, 1 döndü mü?
    if (fread(rec, sizeof(struct Record), 1, fp) != 1) {
        printf("Hata: Veri okunamadi veya eksik veri.\n");

        // TEMİZLİK KURALLARI: Hata anında arkamızda çöp bırakmıyoruz.
        free(rec);  // Ayırdığımız belleği geri verdik.
        fclose(fp); // Açtığımız dosyayı kapattık.
        return NULL;
    }

    // ----------------------------------------------------
    // Aşama 4: KAPAT VE DÖNDÜR (Close & Return)
    // ----------------------------------------------------
    // Her şey başarıyla tamamlandı.
    fclose(fp); // İşimiz bitti, işletim sistemine dosya kilidini geri veriyoruz.
    return rec; // İçerisi doldurulmuş RAM adresini başarıyla döndürüyoruz.
}

```

```c
#include <stdio.h>
#include <stdlib.h>

struct Notes {
    int n;          // Kaç not var
    float *vals;    // Notlar dizisi (dinamik)
};

struct Notes *read_notes(const char *filename) {

    // 1. DOSYAYI AÇ
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Impossible d'ouvrir le fichier\n");
        return NULL;
    }

    // 2. HEADER OKU: n (kaç not var?)
    int n;
    if (fread(&n, sizeof(int), 1, f) != 1) {
        fprintf(stderr, "Impossible de lire le header\n");
        fclose(f);
        return NULL;
    }

    // 3. n GEÇERLİ Mİ?
    if (n <= 0) {
        fprintf(stderr, "Nombre de notes invalide\n");
        fclose(f);
        return NULL;
    }

    // 4. STRUCT İÇİN BELLEK AYIR
    struct Notes *notes = malloc(sizeof(struct Notes));
    if (!notes) {
        fprintf(stderr, "Impossible d'allouer la mémoire\n");
        fclose(f);
        return NULL;
    }
    notes->n = n;

    // 5. FLOAT DİZİSİ İÇİN BELLEK AYIR
    notes->vals = malloc(n * sizeof(float));
    if (!notes->vals) {
        fprintf(stderr, "Impossible d'allouer la mémoire\n");
        free(notes);
        fclose(f);
        return NULL;
    }

    // 6. NOTLARI OKU (n tane float)
    if (fread(notes->vals, sizeof(float), n, f) != (size_t)n) {
        fprintf(stderr, "Impossible de lire les notes\n");
        free(notes->vals);
        free(notes);
        fclose(f);
        return NULL;
    }

    // 7. BAŞARILI
    fclose(f);
    return notes;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Image {
    uint32_t w;
    uint32_t h;
    uint32_t bpp;
    unsigned char *pixels;
};

// ==========================================
// 1. GÖRÜNTÜ OKUMA FONKSİYONU
// ==========================================
struct Image *read_image(const char *filename) {
    // 1. DOSYAYI AÇ
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Impossible d'ouvrir le fichier\n");
        return NULL;
    }

    // 2. HEADER OKU (W, H, BPP olmak üzere 3 tane uint32_t)
    uint32_t header[3];
    if (fread(header, sizeof(uint32_t), 3, f) != 3) {
        fprintf(stderr, "Impossible de lire le header\n");
        fclose(f);
        return NULL;
    }

    uint32_t w = header[0];
    uint32_t h = header[1];
    uint32_t bpp = header[2];

    // Boyutlar mantıklı mı kontrolü (0'a çarpma hatasını önlemek için)
    if (w == 0 || h == 0 || bpp == 0) {
        fprintf(stderr, "Dimensions de l'image invalides\n");
        fclose(f);
        return NULL;
    }

    // 3. STRUCT İÇİN YER AYIR
    struct Image *img = malloc(sizeof(struct Image));
    if (!img) {
        fprintf(stderr, "Impossible d'allouer la mémoire\n");
        fclose(f);
        return NULL;
    }
    img->w = w;
    img->h = h;
    img->bpp = bpp;

    // Toplam okunacak byte sayısını hesapla
    size_t total_bytes = (size_t)w * h * bpp;

    // 4. PİXELLER İÇİN YER AYIR
    img->pixels = malloc(total_bytes);
    if (!img->pixels) {
        fprintf(stderr, "Impossible d'allouer la mémoire\n");
        free(img); // Struct'ı geri ver
        fclose(f);
        return NULL;
    }

    // 5. TÜM PİXELLERİ TEK SEFERDE OKU
    // Soru: Nereye yaz? img->pixels
    // Soru: Kaç byte? 1 byte (unsigned char)
    // Soru: Kaç tane? total_bytes kadar
    if (fread(img->pixels, 1, total_bytes, f) != total_bytes) {
        fprintf(stderr, "Impossible de lire les pixels\n");
        free(img->pixels); // Önce diziyi geri ver
        free(img);         // Sonra struct'ı geri ver
        fclose(f);
        return NULL;
    }

    // 6. BAŞARILI BİTİŞ
    fclose(f);
    return img;
}

// ==========================================
// 2. BİLGİ YAZDIRMA FONKSİYONU
// ==========================================
void image_info(const struct Image *image) {
    if (!image) return;

    printf("Taille: %u x %u\n", image->w, image->h);
    printf("BPP : %u\n", image->bpp);

    // Görüntüdeki toplam piksel sayısı (Genişlik * Yükseklik)
    size_t num_pixels = (size_t)image->w * image->h;

    // Her bir renk kanalı (bileşeni) için ayrı ayrı dön
    for (uint32_t c = 0; c < image->bpp; c++) {
        double sum = 0.0;

        // Bütün pikselleri gez
        for (size_t p = 0; p < num_pixels; p++) {
            // Sınavın en kritik formülü: p * BPP + c
            sum += image->pixels[p * image->bpp + c];
        }

        // Ortalamayı yazdır
        printf("Valeur moyenne composante %u : %f\n", c, sum / num_pixels);
    }
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Image {
    uint32_t w, h, bpp;
    unsigned char *pixels;
};

struct Image *read_image(const char *filename) {
    // 1. DOSYAYI AÇ
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    // 2. HEADER BİLGİLERİNİ OKU (Genişlik, Yükseklik, Kanal Sayısı)
    uint32_t w, h, bpp;
    if (fread(&w, sizeof(uint32_t), 1, f) != 1 ||
        fread(&h, sizeof(uint32_t), 1, f) != 1 ||
        fread(&bpp, sizeof(uint32_t), 1, f) != 1) {
        fclose(f);
        return NULL;
    }

    // 3. STRUCT İÇİN BELLEK AYIR
    struct Image *img = malloc(sizeof(struct Image));
    if (!img) {
        fclose(f);
        return NULL;
    }
    img->w = w;
    img->h = h;
    img->bpp = bpp;

    // 4. PİKSELLER İÇİN BELLEK AYIR (W * H * BPP kadar byte)
    uint32_t total_bytes = w * h * bpp;
    img->pixels = malloc(total_bytes);
    if (!img->pixels) {
        free(img);
        fclose(f);
        return NULL;
    }

    // 5. TÜM PİKSELLERİ TEK SEFERDE OKU
    if (fread(img->pixels, 1, total_bytes, f) != total_bytes) {
        free(img->pixels);
        free(img);
        fclose(f);
        return NULL;
    }

    // 6. BAŞARILI
    fclose(f);
    return img;
}

void image_info(const struct Image *img) {
    if (!img) return;

    // Boyutları yazdır
    printf("Taille: %u x %u\n", img->w, img->h);
    printf("BPP : %u\n", img->bpp);

    uint32_t total_pixels = img->w * img->h;

    // HER KANAL İÇİN ORTALAMA HESAPLA
    for (uint32_t c = 0; c < img->bpp; c++) {
        double sum = 0;

        for (uint32_t p = 0; p < total_pixels; p++) {
            // Kritik Formül: Şimdiki pikselin c'inci kanalına eriş
            sum += img->pixels[p * img->bpp + c];
        }

        printf("Valeur moyenne composante %u : %f\n", c, sum / total_pixels);
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

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
