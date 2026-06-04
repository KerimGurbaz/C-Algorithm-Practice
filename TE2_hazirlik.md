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
#include <stdio.h>
#include <stdlib.h>

// --- VERİ YAPISI ---
struct Audio {
    int sample_rate;
    int nb_samples;
    short *samples; // Ses verisi için dinamik dizi
};

// ==========================================
// 1. YAZMA FONKSİYONU (Serialization)
// ==========================================
void write_audio(const struct Audio *a, const char *filename) {
    // 1. Aç ("wb" -> Write Binary)
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Dosya yazma icin acilamadi.\n");
        return;
    }

    // 2. Header 1: Sample Rate (4 byte)
    fwrite(&a->sample_rate, sizeof(int), 1, f);

    // 3. Header 2: Number of Samples (4 byte)
    fwrite(&a->nb_samples, sizeof(int), 1, f);

    // 4. Data: Tüm samples dizisini tek seferde yaz
    // short *samples zaten bir adres olduğu için başına & konmaz
    fwrite(a->samples, sizeof(short), a->nb_samples, f);

    // 5. Kapat
    fclose(f);
}

// ==========================================
// 2. OKUMA FONKSİYONU (Deserialization)
// ==========================================
struct Audio *read_audio(const char *filename) {
    // 1. Aç ("rb" -> Read Binary)
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    int sr, nb;

    // 2. Header 1: Sample Rate
    if (fread(&sr, sizeof(int), 1, f) != 1) {
        fclose(f);
        return NULL;
    }

    // 3. Header 2: Number of Samples
    if (fread(&nb, sizeof(int), 1, f) != 1) {
        fclose(f);
        return NULL;
    }

    // 4. Bellek Tahsisi (Struct ve Dizi)
    struct Audio *a = malloc(sizeof(struct Audio));
    if (!a) {
        fclose(f);
        return NULL;
    }

    a->sample_rate = sr;
    a->nb_samples = nb;
    a->samples = malloc(nb * sizeof(short));

    if (!a->samples) {
        free(a);
        fclose(f);
        return NULL;
    }

    // 5. Data: Tüm samples dizisini tek seferde oku
    if (fread(a->samples, sizeof(short), nb, f) != (size_t)nb) {
        free(a->samples);
        free(a);
        fclose(f);
        return NULL;
    }

    // 6. Kapat ve Döndür
    fclose(f);
    return a;
}

// ==========================================
// 3. TEST (MAIN)
// ==========================================
int main(void) {
    // A. TEST VERİSİ HAZIRLA
    struct Audio a_out;
    a_out.sample_rate = 44100;
    a_out.nb_samples = 4;

    short test_data[] = {100, 200, -100, -200};
    a_out.samples = test_data;

    // B. DOSYAYA YAZ
    printf("Dosyaya yaziliyor...\n");
    write_audio(&a_out, "audio.bin");

    // C. DOSYADAN GERİ OKU
    printf("Dosyadan okunuyor...\n");
    struct Audio *a_in = read_audio("audio.bin");

    // D. SONUÇLARI KONTROL ET VE YAZDIR
    if (a_in) {
        printf("Sample Rate: %d\n", a_in->sample_rate);
        printf("Samples: ");
        for (int i = 0; i < a_in->nb_samples; i++) {
            printf("%d ", a_in->samples[i]);
        }
        printf("\n");

        // E. BELLEĞİ TEMİZLE (Sadece read_audio içinde malloc yaptığımız için)
        free(a_in->samples);
        free(a_in);
    }

    return 0;
}
// Okurken ekstradan yapman gereken tek şey, veriyi koyacağın "kabı" (malloc) hazırlamaktır. Header değişkenlerini okurken de güvenli tarafta kalmak için önce yerel değişkenlere (int sr, nb;) alıp, dosyanın sağlam olduğundan emin olduktan sonra malloc yapmak kodu çöküşlerden koruyan en sağlam mimari tekniktir.

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // offsetof makrosu icin (Çok önemli!)

// --- VERİ YAPISI ---
struct Student {
    int id;
    char name[50];
    float grade;
};

// ==========================================
// 1. BELİRLİ BİR KAYDI OKUMA (Random Read)
// ==========================================
int read_student(FILE *f, int index, struct Student *out) {
    // FORMÜL: Header (int) + atlamak istediğin kadar Student bloğu
    long offset = sizeof(int) + (index * sizeof(struct Student));

    // Cursor'ı dosyanın başından (SEEK_SET) itibaren offset kadar ileri taşı
    if (fseek(f, offset, SEEK_SET) != 0) {
        return -1; // Atlama başarısız
    }

    // Oraya ulaştık, şimdi tam o noktadan 1 tane Student oku
    if (fread(out, sizeof(struct Student), 1, f) != 1) {
        return -1; // Okuma başarısız
    }

    return 0; // Başarılı
}

// ==========================================
// 2. SADECE NOTU GÜNCELLEME (Targeted Update)
// ==========================================
int update_grade(FILE *f, int index, float new_grade) {
    // FORMÜL: Header + Atlanan Student Blokları + Grade değişkeninin Struct içindeki konumu
    // offsetof(struct_adi, degisken_adi) makrosu bu işin endüstri standardıdır.
    long offset = sizeof(int) + (index * sizeof(struct Student)) + offsetof(struct Student, grade);

    // Cursor'ı tam olarak değiştireceğimiz float'ın üzerine koy!
    if (fseek(f, offset, SEEK_SET) != 0) {
        return -1;
    }

    // Tam o noktaya yeni float değerini yazarak eskisini ez.
    if (fwrite(&new_grade, sizeof(float), 1, f) != 1) {
        return -1;
    }

    // Çoğu sistemde okuma ve yazma arasında cursor senkronizasyonu için flush yapmak güvenlidir
    fflush(f);
    return 0;
}

// ==========================================
// 3. TEST (MAIN)
// ==========================================
int main(void) {
    const char *filename = "db.bin";

    // --- A. TEST İÇİN SAHTE DOSYA YARATMA (Sınavda hoca bunu hazır verir) ---
    FILE *init = fopen(filename, "wb");
    int total_students = 2;
    fwrite(&total_students, sizeof(int), 1, init); // Header

    struct Student s0 = {100, "Ahmet", 45.5};
    struct Student s1 = {101, "Ayse", 60.0};
    fwrite(&s0, sizeof(struct Student), 1, init); // Index 0
    fwrite(&s1, sizeof(struct Student), 1, init); // Index 1
    fclose(init);

    // --- B. ASIL İŞLEM: r+b MODUYLA GÜNCELLEME ---
    // "r+b" = Dosyayı okumak ve yazmak için aç, ama İÇERİĞİNİ SİLME.
    FILE *f = fopen(filename, "r+b");
    if (!f) {
        fprintf(stderr, "Dosya acilamadi!\n");
        return 1;
    }

    struct Student current;

    // 1. Index 1'i (Ayse) oku ve notunu gör
    printf("--- Guncellemeden Once ---\n");
    if (read_student(f, 1, &current) == 0) {
        printf("ID: %d, Isim: %s, Not: %.2f\n", current.id, current.name, current.grade);
    }

    // 2. Index 1'in notunu 95.5 olarak güncelle
    printf("\nNot guncelleniyor (Hedef: 95.50)...\n");
    update_grade(f, 1, 95.5f);

    // 3. Index 1'i tekrar oku ve değiştiğini doğrula
    printf("\n--- Guncellemeden Sonra ---\n");
    if (read_student(f, 1, &current) == 0) {
        printf("ID: %d, Isim: %s, Not: %.2f\n", current.id, current.name, current.grade);
    }

    fclose(f);
    return 0;
}

```

```c
#include <stdint.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// --- VERİ YAPISI VE PROTOTİPLER ---
struct Image {
    uint32_t w;
    uint32_t h;
    uint32_t bpp;
    uint8_t pixels[]; // Flexible array (tek free ile temizlenir)
};

struct Image *read_image(const char *filename);
void init_image_file(void); // Kara kutu

// ==========================================
// 1. GEÇERLİ DOSYA TESTİ (Success Path)
// ==========================================
void test_read_valid(void) {
    // 1. HAZIRLA (Arrange)
    init_image_file();

    // 2. ÇALIŞTIR (Act)
    struct Image *img = read_image("image1.img");

    // 3. ASSERT ET (Assert)
    CU_ASSERT_PTR_NOT_NULL(img);

    // Çökme yaşamamak için pointer'ın NULL olmadığını teyit edip değerleri okuyoruz
    if (img != NULL) {
        CU_ASSERT_TRUE(img->w > 0);
        CU_ASSERT_TRUE(img->h > 0);

        // Temizlik (Bellek sızıntısını önler)
        free(img);
    }
}

// ==========================================
// 2. GEÇERSİZ DOSYA TESTİ (Failure Path)
// ==========================================
void test_read_invalid(void) {
    // 1. HAZIRLA
    // Olmayan bir dosyayı test edeceğimiz için init_image_file() çağırmaya gerek yok.

    // 2. ÇALIŞTIR
    struct Image *img = read_image("kesinlikle_olmayan_dosya.img");

    // 3. ASSERT ET
    // Dosya okunamadığı için fonksiyon kesinlikle NULL döndürmelidir
    CU_ASSERT_PTR_NULL(img);
}

// ==========================================
// 3. TEST MOTORU (Main)
// ==========================================
int main(void) {
    // Kayıt defterini başlat
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Suite oluştur (Hazırlık ve temizlik fonksiyonlarına ihtiyacımız yok -> NULL, NULL)
    CU_pSuite suite = CU_add_suite("Read_Image_Suite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Testleri suite'e bağla
    CU_add_test(suite, "Gecerli Dosya Okuma Testi", test_read_valid);
    CU_add_test(suite, "Gecersiz Dosya Okuma Testi", test_read_invalid);

    // Testleri Basic arayüz ile detaylı (VERBOSE) modda çalıştır
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Sistemi temizle ve çık
    CU_cleanup_registry();
    return CU_get_error();
}

```

```c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// --- TEST EDİLECEK FONKSİYON (Prototip) ---
int calculer(int a, int b, char op);

// ==========================================
// 1. TEST FONKSİYONLARI (Hazırla -> Çalıştır -> Assert)
// ==========================================

void test_addition(void) {
    // CU_ASSERT_EQUAL(gerceklesen_deger, beklenen_deger);
    CU_ASSERT_EQUAL(calculer(3, 4, '+'), 7);
    CU_ASSERT_EQUAL(calculer(-2, 5, '+'), 3);
}

void test_soustraction(void) {
    CU_ASSERT_EQUAL(calculer(10, 3, '-'), 7);
    CU_ASSERT_EQUAL(calculer(0, 5, '-'), -5);
}

void test_division_zero(void) {
    // Sınavın trick noktası: Özel hata durumunun doğru değeri (-1) döndürdüğünü kanıtlamak
    CU_ASSERT_EQUAL(calculer(8, 0, '/'), -1);
}

// ==========================================
// 2. ANA TEST MOTORU (Değişmez 5 Adımlı Şablon)
// ==========================================
int main(void) {
    // ADIM 1: Initialize (Kayıt defterini başlat)
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // ADIM 2: Add Suite (Test grubunu oluştur)
    // Init ve cleanup fonksiyonlarına ihtiyacımız yoksa NULL, NULL geçeriz
    CU_pSuite s = CU_add_suite("Calculatrice_Suite", NULL, NULL);
    if (s == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // ADIM 3: Add Test (Fonksiyonları suite'e bağla)
    CU_add_test(s, "Test de l'addition", test_addition);
    CU_add_test(s, "Test de la soustraction", test_soustraction);
    CU_add_test(s, "Test de la division par zero", test_division_zero);

    // ADIM 4: Run (Testleri detaylı/verbose modda çalıştır)
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // ADIM 5: Cleanup (Sistemi temizle)
    CU_cleanup_registry();
    return CU_get_error();
}

```

```c
#include <stdlib.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// ============ STRUCT VE FONKSİYON ============
struct Person {
    int id;
    char name[50];
    int age;
};

struct Person *find_by_name(struct Person arr[], int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return &arr[i];
        }
    }
    return NULL;
}

// ============ TEST VERİSİ ============
struct Person people[4] = {
    {1, "Ali", 25},
    {2, "Ayse", 30},
    {3, "Mehmet", 22},
    {4, "Zeynep", 28}
};
int nb = 4;

// ============ TEST 1: BAŞARILI ARAMA ============
void test_find_success(void) {
    // 1. ÇALIŞTIR
    struct Person *found = find_by_name(people, nb, "Ayse");

    // 2. NULL DEĞİL MI? (bulundu mu?)
    CU_ASSERT_PTR_NOT_NULL(found);

    // 3. DOĞRU ADRES MI?
    CU_ASSERT_PTR_EQUAL(found, &people[1]);  // Ayse = index 1

    // 4. İÇERİK DOĞRU MU?
    CU_ASSERT_EQUAL(found->id, 2);
    CU_ASSERT_STRING_EQUAL(found->name, "Ayse");
    CU_ASSERT_EQUAL(found->age, 30);
}

// ============ TEST 2: BAŞARISIZ ARAMA ============
void test_find_fail(void) {
    // Olmayan isim
    struct Person *found = find_by_name(people, nb, "Ahmet");
    CU_ASSERT_PTR_NULL(found);

    // Boş string
    found = find_by_name(people, nb, "");
    CU_ASSERT_PTR_NULL(found);
}

// ============ TEST 3: SINIR TESTLERİ ============
void test_find_boundaries(void) {
    // İlk eleman
    struct Person *first = find_by_name(people, nb, "Ali");
    CU_ASSERT_PTR_NOT_NULL(first);
    CU_ASSERT_PTR_EQUAL(first, &people[0]);
    CU_ASSERT_EQUAL(first->id, 1);

    // Son eleman
    struct Person *last = find_by_name(people, nb, "Zeynep");
    CU_ASSERT_PTR_NOT_NULL(last);
    CU_ASSERT_PTR_EQUAL(last, &people[3]);
    CU_ASSERT_EQUAL(last->age, 28);
}

// ============ MAIN ============
int main(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("find_by_name Tests", NULL, NULL);

    CU_add_test(suite, "Bulma başarılı", test_find_success);
    CU_add_test(suite, "Bulma başarısız", test_find_fail);
    CU_add_test(suite, "Sınır testleri", test_find_boundaries);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

```

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// Fonksiyon prototipleri
struct Image {
    unsigned int w, h, bpp;
    unsigned char *pixels;
};
struct Image *read_image(const char *filename);
void init_image_file(void);

// ============ TEST 1: GEÇERLİ DOSYA ============
void test_read_image_ok(void) {
    // 1. HAZIRLA
    init_image_file();

    // 2. ÇALIŞTIR
    struct Image *img = read_image("image1.img");

    // 3. ASSERT
    CU_ASSERT_PTR_NOT_NULL(img);
    if (img) {
        CU_ASSERT_TRUE(img->w > 0);
        CU_ASSERT_TRUE(img->h > 0);
        CU_ASSERT_TRUE(img->bpp > 0);
        free(img->pixels);
        free(img);
    }
}

// ============ TEST 2: OLMAYAN DOSYA ============
void test_read_image_bad_file(void) {
    char buf[256] = {0};

    // ADIM 1: stderr'i DOSYAYA yönlendir
    // Artık stderr'e yazılan her şey "err.txt"ye gidecek!
    freopen("err.txt", "w", stderr);

    // ADIM 2: Hata üreten fonksiyonu ÇAĞIR
    // Bu fonksiyon stderr'e "Impossible d'ouvrir..." yazacak
    struct Image *img = read_image("nonexistent.img");

    // ADIM 3: stderr'i GERİ AL (çok önemli!)
    // Yoksa sonraki testler de err.txt'ye yazar!
    freopen("/dev/tty", "w", stderr);

    // ADIM 4: Dosyayı OKU ve KONTROL ET
    FILE *f = fopen("err.txt", "r");
    CU_ASSERT_PTR_NOT_NULL(f);  // Dosya açılabilmeli

    fgets(buf, sizeof(buf), f);  // İlk satırı oku
    fclose(f);

    // ASSERT'ler
    CU_ASSERT_PTR_NULL(img);  // Fonksiyon NULL döndürmeli
    CU_ASSERT_STRING_EQUAL(buf, "Impossible d'ouvrir le fichier\n");
    // VEYA içinde geçiyor mu diye:
    // CU_ASSERT_TRUE(strstr(buf, "Impossible d'ouvrir") != NULL);
}

// ============ TEST 3: BOŞ DOSYA (BOZUK HEADER) ============
void test_read_image_bad_header(void) {
    char buf[256] = {0};

    // ADIM 1: Boş bir dosya oluştur
    FILE *f = fopen("empty.img", "wb");
    fclose(f);  // 0 byte'lık dosya

    // ADIM 2: stderr'i yönlendir
    freopen("err.txt", "w", stderr);

    // ADIM 3: Fonksiyonu çağır (header okuyamayacak!)
    struct Image *img = read_image("empty.img");

    // ADIM 4: stderr'i geri al
    freopen("/dev/tty", "w", stderr);

    // ADIM 5: Dosyayı oku
    FILE *err = fopen("err.txt", "r");
    CU_ASSERT_PTR_NOT_NULL(err);

    fgets(buf, sizeof(buf), err);
    fclose(err);

    // ASSERT
    CU_ASSERT_PTR_NULL(img);
    CU_ASSERT_TRUE(strstr(buf, "Impossible de lire le header") != NULL);
}

// ============ MAIN ============
int main(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("read_image Tests", NULL, NULL);

    CU_add_test(suite, "Geçerli dosya", test_read_image_ok);
    CU_add_test(suite, "Olmayan dosya", test_read_image_bad_file);
    CU_add_test(suite, "Bozuk header", test_read_image_bad_header);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <CUnit/CUnit.h>

// --- VERİ YAPISI VE PROTOTİP ---
struct Image {
    uint32_t w, h, bpp;
    uint8_t pixels[];
};

struct Image *read_image(const char *filename);
void init_image_file(void); // Siyah kutu

// ==========================================
// 1. BAŞARILI DOSYA OKUMA TESTİ
// ==========================================
void test_read_image_ok(void) {
    init_image_file(); // Siyah kutu geçerli dosyayı (örn: image1.img) üretir

    struct Image *img = read_image("image1.img");

    CU_ASSERT_PTR_NOT_NULL(img);
    if (img != NULL) {
        CU_ASSERT_TRUE(img->w > 0);
        CU_ASSERT_TRUE(img->h > 0);
        CU_ASSERT_TRUE(img->bpp > 0);
        free(img);
    }
}

// ==========================================
// 2. OLMAYAN DOSYA TESTİ (Dosya Açılamadı)
// ==========================================
void test_read_image_bad_file(void) {
    // 1. Yönlendir
    freopen("stderr_out.txt", "w", stderr);

    // 2. Çalıştır (Kesinlikle olmayan bir isim veriyoruz)
    struct Image *img = read_image("kesinlikle_yok_olan_dosya.img");

    // 3. Geri Al (Test çıktılarının bozulmaması için çok önemli)
    freopen("/dev/tty", "w", stderr);

    // 4. Dosyayı Oku ve Doğrula
    FILE *f = fopen("stderr_out.txt", "r");
    char buf[200] = {0};
    if (f != NULL) {
        fgets(buf, sizeof(buf), f);
        fclose(f);
    }

    // Hocanın tam istediği \n karakterli String Equal kontrolü
    CU_ASSERT_STRING_EQUAL(buf, "Impossible d'ouvrir le fichier\n");
    CU_ASSERT_PTR_NULL(img);
}

// ==========================================
// 3. BOZUK HEADER TESTİ (Eksik Veri)
// ==========================================
void test_read_image_bad_header(void) {
    // A. HAZIRLIK: Kasıtlı olarak içi BOŞ bir dosya yarat (0 byte)
    // Bu sayede fopen başarılı olacak ama fread(header) anında patlayacak.
    FILE *empty = fopen("empty.img", "wb");
    if (empty != NULL) {
        fclose(empty);
    }

    // 1. Yönlendir
    freopen("stderr_out.txt", "w", stderr);

    // 2. Çalıştır (Boş dosyayı ver)
    struct Image *img = read_image("empty.img");

    // 3. Geri Al
    freopen("/dev/tty", "w", stderr);

    // 4. Dosyayı Oku ve Doğrula
    FILE *f = fopen("stderr_out.txt", "r");
    char buf[200] = {0};
    if (f != NULL) {
        fgets(buf, sizeof(buf), f);
        fclose(f);
    }

    CU_ASSERT_STRING_EQUAL(buf, "Impossible de lire le header\n");
    CU_ASSERT_PTR_NULL(img);
}


```

```c
#include <stdio.h>
#include <stdlib.h> // atoi fonksiyonu buradadır

int main(int argc, char *argv[]) {

    // ADIM 1: KAPI KONTROLÜ (Sayım)
    // Kapıda tam olarak 4 paket yoksa içeri kimseyi alma.
    if (argc != 4) {
        fprintf(stderr, "Kullanim hatasi: %s <dosya> <seed> <size>\n", argv[0]);
        return 1; // Programı hata koduyla bitir
    }

    // ADIM 2: DÖNÜŞÜM (Metinden Sayıya)
    // 2. ve 3. vagondaki kelimeleri ('4' '5') sayıya (45) dönüştür.
    int seed = atoi(argv[2]);
    int size = atoi(argv[3]);

    // ADIM 3: GÜVENLİK KONTROLÜ (Sınırlar)
    // Elde ettiğimiz sayılar mantıklı mı?
    if (seed < 1 || seed > 0x7FFFFFFF) {
        fprintf(stderr, "Hata: Seed degeri sinirlarin disinda.\n");
        return 1;
    }

    if (size < 1 || size > 256) {
        fprintf(stderr, "Hata: Size degeri sinirlarin disinda.\n");
        return 1;
    }

    // ADIM 4: MUTLU SON
    // Her şey yolundaysa işleme devam et.
    printf("Basarili! seed=%d ve size=%d\n", seed, size);

    return 0;
}

```

```c
#include <stdio.h>

// ==========================================
// RASTGELE SAYI ÜRETİCİ FONKSİYON
// ==========================================
int myrand(int seed) {
    // 1. HAFIZA: 'static' sayesinde bu değişken ilk çağrılışta 5669 olur,
    // sonraki çağrılarda önceki hesaplamadan kalan değerini korur.
    static int myrand_state = 5669;

    // 2. KAOS: Mevcut durumu seed ile çarparak karıştırıyoruz
    myrand_state = myrand_state * seed;

    // 3. SINIR: 32-bit sınırını aşmasın diye devasa bir sayıya bölüp kalanını alıyoruz
    myrand_state = myrand_state % 0x7FFFFFFF;

    // 4. FİLTRE: Sadece en düşük byte'ı (0-255) bırak, gerisini sıfırla
    myrand_state = myrand_state & 0xFF;

    return myrand_state;
}

// ==========================================
// TEST (MAIN)
// ==========================================
int main(void) {
    int seed = 100;

    printf("Seed %d ile 5 adet rastgele sayi uretiliyor:\n", seed);

    // Aynı seed değeriyle fonksiyonu 5 kez çağırıyoruz.
    // Eger 'static' kelimesini yazmasaydık, bu 5 sonucun hepsi AYNI çıkardı!
    for (int i = 1; i <= 5; i++) {
        int rastgele_deger = myrand(seed);
        printf("%d. Cagri -> Sonuc: %d\n", i, rastgele_deger);
    }

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// Geçmiş konudan hatırladığımız kalıcı (static) durumlu rastgele sayı üretici
int myrand(int seed) {
    static int state = 5669;
    state = state * seed;
    state = state % 0x7FFFFFFF;
    state = state & 0xFF;
    return state;
}

int main(int argc, char *argv[]) {

    // ADIM 1: Girdileri Kontrol Et ve Dönüştür
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filepath> <seed> <size>\n", argv[0]);
        return 1;
    }

    const char *filepath = argv[1];
    int seed = atoi(argv[2]);
    int size = atoi(argv[3]);

    if (size <= 0) {
        fprintf(stderr, "Hata: Gecersiz boyut.\n");
        return 1;
    }

    // ADIM 2: Buffer İçin Bellek Ayır ve Rastgele Veriyle Doldur
    unsigned char *buffer = malloc(size);
    if (!buffer) {
        perror("malloc basarisiz");
        return 1;
    }

    // myrand çarkını size kadar çevirip buffer'a sırayla diziyoruz
    for (int i = 0; i < size; i++) {
        buffer[i] = (unsigned char)myrand(seed);
    }

    // ADIM 3: Dosyayı Yazma Modunda (wb) Aç
    FILE *f = fopen(filepath, "wb");
    if (!f) {
        perror("fopen hatasi"); // İşletim sisteminin hatasını ekrana basar
        free(buffer);           // Çıkmadan önce RAM'i temizlemeyi unutma
        return 1;
    }

    // ADIM 4: Header'ı Yaz (Sadece boyut bilgisini tutan 1 adet int)
    // Ne yazılacak? -> &size
    // Boyutu ne? -> sizeof(int)
    // Kaç tane? -> 1
    if (fwrite(&size, sizeof(int), 1, f) != 1) {
        perror("Header yazilamadi");
        fclose(f);
        free(buffer);
        return 1;
    }

    // ADIM 5: Buffer'ı (Asıl Veriyi) Yaz
    // Ne yazılacak? -> buffer (zaten adres olduğu için & yok)
    // Boyutu ne? -> sizeof(unsigned char) (yani 1 byte)
    // Kaç tane? -> size adet
    if (fwrite(buffer, sizeof(unsigned char), size, f) != (size_t)size) {
        perror("Veri yazilamadi");
        fclose(f);
        free(buffer);
        return 1;
    }

    // ADIM 6: İşlemi Kapat ve Başarı Mesajı Ver
    fclose(f);
    free(buffer);

    printf("Basarili! Toplam %d byte '%s' dosyasina yazildi.\n", size, filepath);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// ==========================================
// BİNARY DOSYA OKUMA VE DOĞRULAMA
// ==========================================
int read_bloc(const char *filepath) {
    // ----------------------------------------------------
    // 1. AÇ (Read Binary)
    // ----------------------------------------------------
    FILE *f = fopen(filepath, "rb");
    if (!f) {
        perror("fopen"); // İşletim sistemi hatasını basar
        return 1;        // Hata durumu
    }

    // ----------------------------------------------------
    // 2. TABELAYI OKU (Header)
    // ----------------------------------------------------
    int size;
    // Soru: Nereye yazılacak? '&size'. Kaç tane? 1 tane int.
    if (fread(&size, sizeof(int), 1, f) != 1) {
        fprintf(stderr, "Hata: Dosyadan boyut bilgisi (header) okunamadi.\n");
        fclose(f);
        return 1;
    }

    // Mantık kontrolü: Boyut 0'dan küçük veya saçma sapan bir değer mi?
    if (size <= 0) {
        fprintf(stderr, "Hata: Gecersiz boyut okundu (size = %d).\n", size);
        fclose(f);
        return 1;
    }

    // ----------------------------------------------------
    // 3. KOVA HAZIRLA (Dinamik Bellek)
    // ----------------------------------------------------
    // Diskte ne kadar veri olduğunu artık 'size' değişkeni sayesinde biliyoruz.
    // O yüzden int buf[256] gibi sabit bir dizi YAZMIYORUZ. Tam gerektiği kadar yer istiyoruz.
    unsigned char *buf = malloc(size * sizeof(unsigned char));
    if (!buf) {
        fprintf(stderr, "Hata: %d byte icin bellek ayrilamadi.\n", size);
        fclose(f);
        return 1;
    }

    // ----------------------------------------------------
    // 4. VERİYİ DOLDUR (Data)
    // ----------------------------------------------------
    // Soru: Nereye yazılacak? 'buf' adresine. Kaç tane? 'size' kadar byte.
    if (fread(buf, 1, size, f) != (size_t)size) {
        fprintf(stderr, "Hata: Veri eksik veya okunamadi.\n");
        free(buf);
        fclose(f);
        return 1;
    }

    // ----------------------------------------------------
    // 5. İŞLE VE DOĞRULA (Hexadecimal Çıktı)
    // ----------------------------------------------------
    printf("Dosya icerigi (%d byte):\n", size);
    for (int i = 0; i < size; i++) {
        // %02X: Sayıyı 16'lık tabanda (Hex) yaz. Tek haneliyse başına '0' koy (Örn: 0A, 1F).
        printf("%02X ", buf[i]);
    }
    printf("\n"); // Döngü bitince alt satıra geç, konsol düzenli görünsün.

    // ----------------------------------------------------
    // 6. TEMİZLE VE ÇIK (Ayna işleminin sonu)
    // ----------------------------------------------------
    free(buf);
    fclose(f);

    return 0; // Başarılı
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// Endüstri standardı: Sihirli sayıları (magic numbers) her zaman #define ile tepeye yaz.
#define SEED_MAX 0x7FFFFFFF
#define BLOCK_SIZE 256

// ==========================================
// 1. RASTGELE SAYI ÜRETİCİ (PRNG)
// ==========================================
int myrand(int seed) {
    static int state = 5669;

    state = state * seed;
    state = state % SEED_MAX;
    state = state & 0xFF; // Sadece en düşük byte (0-255)

    return state;
}

// ==========================================
// 2. ANA PROGRAM (TE2B - Final Sorusu)
// ==========================================
int main(int argc, char *argv[]) {
    // ----------------------------------------------------
    // ADIM 1: Argüman Sayısı Kontrolü
    // ----------------------------------------------------
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filepath> <seed> <size>\n", argv[0]);
        return 1;
    }

    // ----------------------------------------------------
    // ADIM 2: Argümanları Ayrıştırma (Parse)
    // ----------------------------------------------------
    const char *filepath = argv[1];
    int seed = atoi(argv[2]);
    int size = atoi(argv[3]);

    // ----------------------------------------------------
    // ADIM 3 ve 4: Sınır Doğrulamaları (Validation)
    // ----------------------------------------------------
    if (seed < 1 || seed > SEED_MAX) {
        fprintf(stderr, "Hata: Seed 1 ile %d arasinda olmalidir.\n", SEED_MAX);
        return 1;
    }

    if (size < 1 || size > BLOCK_SIZE) {
        fprintf(stderr, "Hata: Size 1 ile %d arasinda olmalidir.\n", BLOCK_SIZE);
        return 1;
    }

    // ----------------------------------------------------
    // ADIM 5: Dosyayı Açma ve Hata Kontrolü
    // ----------------------------------------------------
    FILE *f = fopen(filepath, "wb");
    if (!f) {
        perror("fopen"); // İşletim sisteminden net hata sebebini al
        return 1;
    }

    // ----------------------------------------------------
    // ADIM 6: Veri Tamponunu (Buffer) Oluştur ve Doldur
    // ----------------------------------------------------
    unsigned char *buffer = malloc(size * sizeof(unsigned char));
    if (!buffer) {
        fprintf(stderr, "Hata: Bellek ayrilamadi.\n");
        fclose(f); // GERİ SARMA: Dosyayı kapatmadan çıkma!
        return 1;
    }

    for (int i = 0; i < size; i++) {
        buffer[i] = (unsigned char)myrand(seed);
    }

    // ----------------------------------------------------
    // ADIM 7: Header'ı (Boyut Bilgisini) Yaz
    // ----------------------------------------------------
    if (fwrite(&size, sizeof(int), 1, f) != 1) {
        fprintf(stderr, "Hata: Header dosyaya yazilamadi.\n");
        free(buffer); // GERİ SARMA (Merdiven tipi)
        fclose(f);
        return 1;
    }

    // ----------------------------------------------------
    // ADIM 8: Veriyi (Buffer) Dosyaya Dök
    // ----------------------------------------------------
    if (fwrite(buffer, sizeof(unsigned char), size, f) != (size_t)size) {
        fprintf(stderr, "Hata: Veriler dosyaya yazilamadi.\n");
        free(buffer);
        fclose(f);
        return 1;
    }

    // ----------------------------------------------------
    // ADIM 9 ve 10: Temizlik ve Onay
    // ----------------------------------------------------
    free(buffer);
    fclose(f);

    printf("Islem basarili! %d byte boyutundaki blok '%s' dosyasina yazildi.\n", size, filepath);

    return 0;
}

```

```c
#include <stdio.h>

int main(void) {

#ifdef DEBUG
    printf("Mode debug actif\n");
#else
    printf("Mode release\n");
#endif

    return 0;
}

```

```c
#include <stdio.h>

int main(void) {

#ifdef A1
    #if A1 == 1
        printf("Birinci satir: A1 1'dir\n");
    #elif A1 == 2
        printf("Ikinci satir: A1 2'dir\n");
    #else
        printf("Ucuncu satir: A1 tanimli ama 1 veya 2 degil\n");
    #endif
#else
    printf("Dorduncu satir: A1 hic tanimli degil\n");
#endif

    return 0;
}

```

```c
#ifdef SEMBOL          // 1. ÖNCE: tanımlı mı?
    #if SEMBOL == 1    // 2. SONRA: değeri 1 mi?
        // ...
    #elif SEMBOL == 2  // 3. Değilse: değeri 2 mi?
        // ...
    #else              // 4. Hiçbiri değilse
        // ...
    #endif
#else                  // 5. Tanımlı DEĞİLSE
    // ...
#endif

```

```c
#ifdef = "Acaba A1 diye biri VAR MI?"
#if    = "A1'in DEĞERİ NE?"

Sıralama: ÖNCE var mı, SONRA değeri ne!

```

```c
#include <stdio.h>

// 1. HATALI MAKRO (Sadece kopyala-yapıştır)
#define DOUBLE_BAD(x) x + x

// 2. DOĞRU MAKRO (Kalkanlı yapı)
// Her x kendi parantezinde, tüm ifade genel parantezde.
#define DOUBLE_GOOD(x) ((x) + (x))

// KIYASLAMA İÇİN GERÇEK FONKSİYON
int double_fn(int x) {
    return x + x;
}

int main(void) {
    // Test 1: Bit Kaydırma (1 << 2 yani 4)
    int arg1 = 1 << 2;
    printf("--- ARG1: 1 << 2 ---\n");
    printf("Fonksiyon beklenen: %d\n", double_fn(1 << 2));       // 8
    printf("Hatali Makro      : %d\n", DOUBLE_BAD(1 << 2));      // 32 (HATA!)
    printf("Dogru Makro       : %d\n", DOUBLE_GOOD(1 << 2));     // 8  (DÜZELDİ)

    printf("\n");

    // Test 2: Bitsel VEYA (1 | 2 yani 3)
    int arg2 = 1 | 2;
    printf("--- ARG2: 1 | 2 ---\n");
    printf("Fonksiyon beklenen: %d\n", double_fn(1 | 2));        // 6
    printf("Hatali Makro      : %d\n", DOUBLE_BAD(1 | 2));       // 3  (HATA!)
    printf("Dogru Makro       : %d\n", DOUBLE_GOOD(1 | 2));      // 6  (DÜZELDİ)

    return 0;
}

```

```c
#include <stdio.h>

// 1. HATALI MAKRO
// (Not: Kodu derleyebilmek ve mantık hatasını gösterebilmek için XOR swap kullandık.
// Çünkü if'in hemen altında 'int t = a;' tanımlamaya kalkarsan C derleyicisi anında çöker.)
#define SWAP_BAD(a, b)  (a) ^= (b); (b) ^= (a); (a) ^= (b)

// 2. DOĞRU MAKRO (Endüstri Standardı)
// Kendi scope'u (süslü parantezleri) olduğu için içine güvenle değişken (temp) tanımlayabilirsin.
#define SWAP_GOOD(a, b) do { int temp = (a); (a) = (b); (b) = temp; } while(0)

int main(void) {
    int x = 10, y = 20;

    // ----------------------------------------------------
    // TEST 1: HATALI MAKRO (Koşul: YANLIŞ)
    // ----------------------------------------------------
    // Koşul 0 (false) olduğu için makronun hiç çalışmaması, değerlerin 10 ve 20 kalması gerekir.
    if (0)
        SWAP_BAD(x, y);

    /* Derleyici burayı şöyle gördü:
       if (0)
           x ^= y;    // SADECE İLK SATIR if'e dahil oldu ve ATLANDI.
       y ^= x;        // HER ZAMAN ÇALIŞIR!
       x ^= y;        // HER ZAMAN ÇALIŞIR!
    */

    printf("SWAP_BAD (Hata): x = %d, y = %d\n", x, y); // Beklenen 10,20 ama 20,30 çıkacak!

    // ----------------------------------------------------
    // TEST 2: DOĞRU MAKRO
    // ----------------------------------------------------
    int a = 10, b = 20;

    if (0)
        SWAP_GOOD(a, b);

    // do-while(0) tüm bloğu tek bir satır gibi paketlediği için if kuralı bozulmaz.
    printf("SWAP_GOOD (OK)  : a = %d, b = %d\n", a, b); // Beklendiği gibi 10, 20 kalır.

    return 0;

    Eğer hocan senden 2'den fazla işlem yapan bir makro yazmanı isterse, hiç düşünmeden kodu do { ... } while(0) içine yaz.


}

```

```c
#include <stdio.h>

// ==========================================
// 1. ZIRHLI MAX MAKROSU (Tam Kalkan)
// ==========================================
// Kural: Her argüman kendi parantezine, tüm işlem dış paranteze.
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// ==========================================
// 2. KONDİSYONEL LOG MAKROSU (Sentez)
// ==========================================
#ifndef VERBOSE
    // VERBOSE tanımlı değilse, LOG makrosu hiçbir şey yapmaz.
    // 'do {} while(0)' kullanıyoruz çünkü if(cond) LOG("m"); yazıldığında syntax'ı bozmasın.
    #define LOG(msg) do {} while(0)
#else
    #if VERBOSE == 1
        #define LOG(msg) printf("[INFO] %s\n", msg)
    #elif VERBOSE == 2
        #define LOG(msg) printf("[DEBUG] %s\n", msg)
    #else
        // Hayat kurtaran hamle: Yanlış bir değer girildiyse derlemeyi anında durdur.
        #error "HATA: VERBOSE degeri sadece 1 veya 2 olabilir!"
    #endif
#endif

// ==========================================
// TEST (MAIN)
// ==========================================
int main(void) {

    // MAX makrosunu tehlikeli operatörlerle test ediyoruz
    int sonuc = MAX(1 + 2, 4 - 2); // (((1 + 2) > (4 - 2)) ? (1 + 2) : (4 - 2))
    printf("MAX(3, 2) sonucu: %d\n", sonuc);

    // LOG makrosu derleme anında VERBOSE değerine göre şekillenecek
    LOG("Sistem basariyla baslatildi.");

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

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
