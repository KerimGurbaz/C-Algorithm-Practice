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


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
