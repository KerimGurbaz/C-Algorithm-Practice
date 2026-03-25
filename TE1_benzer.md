```c
#include <stdio.h>
#include <string.h>

// Ekstra bellek kullanmadan diziyi yerinde ters çevirir
void reverseString(char *str) {
    // Güvenlik kontrolü
    if (str == NULL) return;

    int len = strlen(str);
    if (len <= 1) return; // 0 veya 1 harfse işlem yapmaya gerek yok

    char *start = str;                  // İlk harf
    char *end = str + len - 1;          // Son harf (\0'dan bir önceki)
    char temp;

    // Pointer'lar ortada kesişene kadar takas et
    while (start < end) {
        // Swap işlemi
        temp = *start;
        *start = *end;
        *end = temp;

        // Pointer'ları birbirine yaklaştır
        start++;
        end--;
    }
}

int main(void) {
    // Sınav kuralı: char *str = "..." YASAK (Salt okunur bellek).
    // char str[] = "..." DOĞRU (Stack'te değiştirilebilir kopya).
    char str[] = "Programmation en C";

    printf("Avant : %s\n", str);
    reverseString(str);
    printf("Apres : %s\n", str);

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h>

// Yardımcı fonksiyon: Belirli bir başlangıç ve bitiş adresi arasındaki harfleri ters çevirir
void reverse_portion(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Ana fonksiyon
void inverser_mots(char *str) {
    if (str == NULL || *str == '\0') return;

    int len = strlen(str);

    // Adım 1: Tüm cümleyi ters çevir
    reverse_portion(str, str + len - 1);

    // Adım 2: Her bir kelimeyi kendi içinde tekrar ters çevir
    char *word_start = str;
    char *word_end = str;

    // Metnin sonuna kadar gezin
    while (*word_end != '\0') {

        // Bir kelimenin sonunu (boşluk veya \0) bulana kadar ilerle
        while (*word_end != ' ' && *word_end != '\0') {
            word_end++;
        }

        // Kelimeyi bulduk, sadece o kelimelik kısmı ters çevir
        // word_end şu an boşluğu (veya \0) gösteriyor. Harf bir gerisindedir (-1).
        reverse_portion(word_start, word_end - 1);

        // Eğer cümlenin sonuna gelmediysek, bir sonraki kelimeye geçmek için pointer'ları ayarla
        if (*word_end != '\0') {
            word_end++; // Boşluğu atla
            word_start = word_end; // Yeni kelimenin başlangıcı
        }
    }
}

int main(void) {
    char phrase[] = "Data Engineering HEIG";

    printf("Originale : \"%s\"\n", phrase);

    inverser_mots(phrase);

    printf("Inversee  : \"%s\"\n", phrase);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// La fonction retourne un pointeur alloué dynamiquement
char* creer_miroir(const char *str) {
    if (str == NULL) return NULL;

    int len = strlen(str);

    // 1. Allocation STRICTE
    // La nouvelle chaîne fait 2 fois la taille originale + 1 pour le '\0'
    char *miroir = malloc((2 * len + 1) * sizeof(char));

    if (miroir == NULL) {
        return NULL; // Échec d'allocation
    }

    // 2. Remplissage de la première moitié (Copie normale)
    for (int i = 0; i < len; i++) {
        miroir[i] = str[i];
    }

    // 3. Remplissage de la deuxième moitié (Copie inversée)
    // On place les caractères de 'str' (de la fin vers le début)
    // dans 'miroir' (à la suite de la première moitié)
    for (int i = 0; i < len; i++) {
        // miroir[len + i] -> La suite logique
        // str[len - 1 - i] -> On lit l'original à l'envers
        miroir[len + i] = str[len - 1 - i];
    }

    // 4. Mühürleme (Scellement de la chaîne)
    // L'index final est exactement 2 * len
    miroir[2 * len] = '\0';

    return miroir;
}

int main(void) {
    const char *mot_original = "HEIG-VD";

    printf("Mot original : %s\n", mot_original);

    // Appel de la fonction
    char *mot_miroir = creer_miroir(mot_original);

    // KONTROL NOKTASI: Malloc başarılı oldu mu?
    if (mot_miroir == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Affichage du résultat ("HEIG-VDDV-GIEH")
    printf("Mot miroir   : %s\n", mot_miroir);

    // TEMIZLIK: Toujours libérer ce qui a été créé dynamiquement
    free(mot_miroir);

    return 0;
}

```

```c
#include <stdio.h>

int main(void) {
    int i;
    float f;
    char str[50];

    printf("Entrez un entier : ");
    // Girdi başarılı değilse (kullanıcı harf girdiyse) programı güvenlice bitir
    if (scanf("%d", &i) != 1) return 1;

    // TAMPON TEMİZLİĞİ: Sayıdan sonraki boşlukları/hatalı girişleri yut
    while(getchar() != '\n');

    printf("Entrez un flottant : ");
    if (scanf("%f", &f) != 1) return 1;
    while(getchar() != '\n');

    printf("Entrez une chaine (sans espaces) : ");
    if (scanf("%49s", str) != 1) return 1;
    // Güvenlik için son temizlik
    while(getchar() != '\n');

    printf("\nResultats :\n");
    printf("Entier   : %d\n", i);
    printf("Flottant : %.2f\n", f);
    printf("Chaine   : %s\n", str);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h> // malloc ve free için zorunlu

int main(void) {
    // 1. Dinamik olarak 50 karakterlik bellek talep et (Heap üzerinde)
    char *prenom = malloc(50 * sizeof(char));

    // KURAL: Malloc yaptıktan sonra daima NULL kontrolü yap.
    if (prenom == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1; // Başarısız çıkış
    }

    printf("Prenom : ");
    // 2. Buffer Overflow koruması (49 karakter oku, 1'i '\0' için)
    // Sınavda scanf("%s", prenom); yazarsan sıfır alırsın. Daima sınır belirtmelisin.
    scanf("%49s", prenom);

    // Kullanıcı çok uzun isim girmişse, buffer'da kalanları temizle ki sonraki kodlar patlamasın
    while (getchar() != '\n');

    printf("Votre prenom est : %s\n", prenom);

    // 3. Malloc ile alınan bellek DAİMA free ile iade edilir.
    free(prenom);

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
