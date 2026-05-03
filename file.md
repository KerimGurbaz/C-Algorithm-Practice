```c
#include <stdio.h>
#include <stdbool.h>

// 1. Karakter Sayıcı
int countc(FILE *fin) {
    int count = 0;
    int c;
    while ((c = fgetc(fin)) != EOF) count++;
    return count;
}

// 2. Kelime Sayıcı
int countm(FILE *f) {
    int c;
    int cpt = 0;
    bool curw = false;

    while ((c = fgetc(f)) != EOF) {
        if (c == ' ' || c == '\n') {
            curw = false;
        } else if (!curw) {
            curw = true;
            cpt++;
        }
    }
    return cpt;
}

// 3. Satır Sayıcı
int countl(FILE *f) {
    int c;
    int cpt = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') cpt++;
    }
    return cpt;
}

int main(int argc, char **argv) {

    // Güvenlik: Argüman eksik mi?
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *fin;

    // Dosyayı aç ve güvenliği sağla
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("[!] Erreur: Impossible d'ouvrir le fichier '%s'\n", argv[1]);
        return 1;
    }

    // AŞAMA 1: Karakterleri Say
    printf("%s contains %d characters\n", argv[1], countc(fin));

    // AŞAMA 2: Kelimeleri Say
    rewind(fin); // İmleci dosyanın en başına sar (freopen yerine daha performanslı)
    printf("%s contains %d words\n", argv[1], countm(fin));

    // AŞAMA 3: Satırları Say
    rewind(fin); // İmleci tekrar dosyanın en başına sar
    printf("%s contains %d lines\n", argv[1], countl(fin));

    // Dosyayı kapat
    fclose(fin);

    return 0;
}

```

```c
#include <stdio.h>

#define MAXLEN 256 // Bellekte yer ayırmak için sihirli sayılar yerine sabit kullanmak hocaların hoşuna gider.

int main(int argc, char **argv) {

    // 1. KLASİK GÜVENLİK: Dosya adı girilmiş mi?
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    // 2. ZAMAN KAZANDIRAN KISALTMA (!fin)
    FILE *fin = fopen(argv[1], "r");
    
    // "!fin" yazmak, "fin == NULL" yazmakla tamamen aynıdır. 
    // Sınavda saniyeler değerlidir, bu kısaltmayı kullan.
    if (!fin) {
        printf("[e] could not open %s\n", argv[1]);
        return 1;
    }

    // 3. DEĞİŞKENLER (Aynı tipleri yan yana yazarak satır tasarrufu)
    char brand[MAXLEN]; 
    char item[MAXLEN];
    float unit, total; 
    int qty;

    // 4. SINAVIN ALTIN VURUŞU: Tek satırda hem okuma hem döngü (fscanf)
    // fscanf(Dosya_Köprüsü, "Format", &Değişkenler)
    // Bu fonksiyon dosyadan verileri okur değişkenlere atar. 
    // Dosyanın sonuna geldiğinde ise otomatik olarak EOF (-1) üretir.
    // Yani "Dosya bitmediği sürece oku ve içine gir" demenin en kısa yoludur.
    while (fscanf(fin, "%s %s %f %d %f", brand, item, &unit, &qty, &total) != EOF) {
        
        // Okunanları ekrana bas. 
        // %.2f -> Küsüratlı sayının sadece virgülden sonraki 2 basamağını gösterir.
        printf("reading %s,%s,%.2f,%d,%.2f\n", brand, item, unit, qty, total);
    }

    // 5. ÇIKIŞ
    fclose(fin);
    return 0;
//     fin == NULL yerine !fin kullan: Kodun daha temiz görünür, yazması 1 saniye sürer.

// while(fscanf(...) != EOF) kalıbını ezberle: Veri formatı belli olan yapılandırılmış dosyaları (Örn: "İsim Yaş Maaş") okumanın en hızlı yoludur. Ekstra tampon (buffer) değişkenleri yaratman gerekmez.

// Metinler (%s) için & kullanılmaz: fscanf içinde unit, qty, total sayı oldukları için başlarına & koyuyoruz. Ama brand ve item birer dizi (metin) oldukları için & işareti konmaz. Hocaların en çok puan kırdığı basit hata budur.
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
