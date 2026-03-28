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
#include <stdio.h>
#include <stdlib.h>

// La fonction retourne un pointeur alloué dynamiquement
int* decouper_en_chiffres(int nombre, int *taille) {
    // 1. Gérer le signe : on travaille avec la valeur absolue pour l'extraction
    // Note : On utilise 'long long' en interne pour éviter le bug de l'overflow
    // sur le plus petit entier (INT_MIN : -2147483648).
    long long temp = nombre;
    if (temp < 0) {
        temp = -temp;
    }

    // 2. Calcul de la taille (L'algorithme que tu as écrit)
    int count = 0;
    long long calcul_taille = temp;
    do {
        calcul_taille /= 10;
        count++;
    } while (calcul_taille != 0);

    *taille = count; // Transmission de la taille au main

    // 3. Allocation STRICTE
    int *tableau = malloc(count * sizeof(int));
    if (tableau == NULL) {
        return NULL; // Échec d'allocation
    }

    // 4. Extraction et Remplissage
    // L'opérateur % donne les chiffres de la fin vers le début (LSB vers MSB).
    // On doit donc remplir le tableau à l'envers, de l'index (count - 1) vers 0.
    for (int i = count - 1; i >= 0; i--) {
        tableau[i] = temp % 10; // Extraire le dernier chiffre
        temp /= 10;             // Réduire le nombre
    }

    return tableau;
}

int main(void) {
    int valeur;
    int statut;

    do {
        printf("Entrez un nombre entier : ");
        statut = scanf("%d", &valeur);
        if (statut != 1) {
            printf("Saisie invalide.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (statut != 1);

    int taille_tab;

    // Appel de la fonction
    int *chiffres = decouper_en_chiffres(valeur, &taille_tab);

    // KONTROL NOKTASI
    if (chiffres == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Affichage formaté
    printf("Les %d chiffres du nombre %d sont : [ ", taille_tab, valeur);
    for (int i = 0; i < taille_tab; i++) {
        printf("%d ", chiffres[i]);
    }
    printf("]\n");

    // TEMIZLIK: Libération de la mémoire
    free(chiffres);

    return 0;
}

```

```c
#include <stdio.h>

// Fonksiyon: Sayının palindrom olup olmadığını kontrol eder
int est_palindrome(const int nombre) {
    // Negatif sayılar palindrom olamaz
    if (nombre < 0) return 0;

    int temp = nombre;
    int inverse = 0;

    // Sayıyı matematiksel olarak tersine çevirme (Inversion mathématique)
    while (temp != 0) {
        int dernier_chiffre = temp % 10;

        // Yeni sayıyı basamak kaydırarak inşa et
        inverse = (inverse * 10) + dernier_chiffre;

        temp /= 10;
    }

    // Tersine çevrilmiş hali orijinaline eşit mi?
    return (nombre == inverse);
}

int main(void) {
    int number;
    int status;

    printf("[?] Entrez un nombre entier : ");

    do {
        status = scanf("%d", &number);
        if (status != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("[!] Erreur. Entrez un entier : ");
        }
    } while (status != 1);

    if (est_palindrome(number)) {
        printf("[i] %d est un nombre palindrome.\n", number);
    } else {
        printf("[i] %d n'est pas un nombre palindrome.\n", number);
    }

    return 0;
}

```

```c
#include <stdio.h>
#include <stdbool.h>

bool palindrome(int n) {
    if (n < 0) return false;

    int temp = n;
    long long inverse = 0;

    do {
        int der = temp % 10;
        inverse = inverse * 10 + der;
        temp /= 10;
    } while (temp != 0);

    return inverse == n;
}

int main(void) {
    int valeur;
    int status;

    printf("Entrez un entier positif : ");

    do {
        status = scanf("%d", &valeur);

        // HATA KONTROLÜ: Harf girildiyse veya sayı negatifse
        if (status != 1 || valeur < 0) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            // KULLANICIYI BİLGİLENDİR (Sessizce beklememesi için)
            printf("[!] Erreur. Entrez un entier positif valide : ");
        }

    // Döngü şartımızı güncelledik: Hatalı giriş VEYA negatif sayı
    } while (status != 1 || valeur < 0);

    // CRITIQUE : Satır sonundaki '\n' eklendi!
    // %s için ternary operator ( ? : ) kullanımın çok profesyonelce.
    printf("%d sayisi -> %s\n", valeur, palindrome(valeur) ? "Palindrome" : "Non-Palindrome");

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1. FONCTION D'EXTRACTION DYNAMIQUE
int* extraire_chiffres(int nombre, int *taille) {
    if (nombre < 0) nombre = -nombre; // Valeur absolue

    // Étape A : Compter les chiffres
    int count = 0;
    int temp = nombre;
    do {
        count++;
        temp /= 10;
    } while (temp != 0);

    *taille = count;

    // Étape B : Allocation stricte
    int *tableau = malloc(count * sizeof(int));
    if (tableau == NULL) return NULL;

    // Étape C : Remplissage
    // Modulo donne les chiffres à l'envers, on les place de droite à gauche
    temp = nombre;
    for (int i = count - 1; i >= 0; i--) {
        tableau[i] = temp % 10;
        temp /= 10;
    }

    return tableau;
}

// 2. FONCTION DE VÉRIFICATION DE SYMÉTRIE (Les Deux Pointeurs)
bool est_symetrique(const int *tableau, int taille) {
    if (tableau == NULL || taille <= 0) return false;

    int gauche = 0;
    int droite = taille - 1;

    // On avance jusqu'à ce que les index se croisent
    while (gauche < droite) {
        if (tableau[gauche] != tableau[droite]) {
            return false; // Dès qu'il y a une différence, ce n'est pas un palindrome
        }
        gauche++;
        droite--;
    }

    return true; // Tout correspond
}

int main(void) {
    int valeur;
    int status;

    // Saisie Sécurisée
    do {
        printf("Entrez un nombre pour tester la symetrie : ");
        status = scanf("%d", &valeur);
        if (status != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Saisie invalide.\n");
        }
    } while (status != 1);

    int taille_tab;

    // Appel Fonction 1
    int *chiffres = extraire_chiffres(valeur, &taille_tab);

    if (chiffres == NULL) {
        printf("Erreur d'allocation.\n");
        return 1;
    }

    // Appel Fonction 2
    bool symetrique = est_symetrique(chiffres, taille_tab);

    // Affichage
    printf("Les chiffres du nombre forment-ils un palindrome ? %s\n", symetrique ? "OUI" : "NON");

    // TEMIZLIK
    free(chiffres);

    return 0;
}

```

```c
#include <stdio.h>

int second_max(const int *tab, int taille, int *erreur) {
    // 1. Güvenlik Kontrolleri
    if (tab == NULL || erreur == NULL || taille <= 1) {
        if (erreur != NULL) *erreur = 1;
        return -1; // Hata durumunda ne döndüğünün pek önemi yok, erreur 1 oldu
    }

    int maxVal = tab[0];
    int secVal = tab[0];
    int a_trouve_second = 0; // Flag: İkinci bir sayı bulduk mu? (0 = Hayır, 1 = Evet)

    // 2. Diziyi Tarama (O(N) karmaşıklığı)
    for (int i = 1; i < taille; ++i) {

        // SENARYO A: Yeni bir mutlak maksimum bulduk
        if (tab[i] > maxVal) {
            secVal = maxVal;      // Eski kral, 2. sıraya düşer
            maxVal = tab[i];      // Yeni kral tahta geçer
            a_trouve_second = 1;  // Kesinlikle 2. bir sayımız var artık
        }

        // SENARYO B: Sayı max'tan küçük. Peki secVal'den büyük mü?
        else if (tab[i] < maxVal) {
            // Eğer henüz 2. bir sayı bulamadıysak VEYA bu sayı mevcut secVal'den büyükse
            if (a_trouve_second == 0 || tab[i] > secVal) {
                secVal = tab[i];
                a_trouve_second = 1;
            }
        }
    }

    // 3. Hata Yönetimi: Döngü bittiğinde hiç 2. sayı bulamadıysak (örn: [5, 5, 5])
    if (a_trouve_second == 0) {
        *erreur = 1;
    } else {
        *erreur = 0;
    }

    return secVal;
}

int main(void) {
    int dataset1[] = {10, 5, 8, 20, 20, 15}; // Beklenen: 15
    int dataset2[] = {7, 7, 7, 7};           // Beklenen: Erreur 1
    int erreur = 0;

    int sec1 = second_max(dataset1, 6, &erreur);
    if (!erreur) printf("Dataset 1 - Second Max : %d\n", sec1);
    else printf("Dataset 1 - Pas de second max.\n");

    int sec2 = second_max(dataset2, 4, &erreur);
    if (!erreur) printf("Dataset 2 - Second Max : %d\n", sec2);
    else printf("Dataset 2 - Pas de second max.\n");

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int* fusionner(const int *t1, int taille1, const int *t2, int taille2) {
    if (t1 == NULL || t2 == NULL) return NULL;

    // 1. Yeni dizi için toplam boyut kadar bellek aç
    int *resultat = malloc((taille1 + taille2) * sizeof(int));
    if (resultat == NULL) return NULL;

    int i = 0; // t1'in indeksi
    int j = 0; // t2'nin indeksi
    int k = 0; // resultat'ın indeksi

    // 2. İki diziyi karşılıklı yarıştır
    while (i < taille1 && j < taille2) {
        if (t1[i] < t2[j]) {
            resultat[k] = t1[i];
            i++;
        } else {
            resultat[k] = t2[j];
            j++;
        }
        k++;
    }

    // 3. Eğer t1'de hala eleman kaldıysa, kalanları olduğu gibi sona ekle
    while (i < taille1) {
        resultat[k] = t1[i];
        i++;
        k++;
    }

    // 4. Eğer t2'de hala eleman kaldıysa, kalanları olduğu gibi sona ekle
    while (j < taille2) {
        resultat[k] = t2[j];
        j++;
        k++;
    }

    return resultat;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// 1. Fonksiyon int** döndürmelidir
int **transpoze(int **m, int lignes, int colonnes) {
    if (m == NULL || lignes <= 0 || colonnes <= 0) return NULL; // return 1 yasak, pointer dönmeli

    // 2. Yeni matrisin boyutları yer değiştirir: colonnes x lignes
    // Ana dizi pointer tuttuğu için sizeof(int *) zorunludur.
    int **temp = calloc(colonnes, sizeof(int *));
    if (temp == NULL) return NULL;

    // 3. Alt satırların tahsisi ve GERÇEK hata yönetimi
    for (int i = 0; i < colonnes; ++i) {
        temp[i] = malloc(lignes * sizeof(int));

        if (temp[i] == NULL) {
            // Eğer i. satır başarısız olursa, önceki başarılı satırları temizle
            for (int k = 0; k < i; ++k) {
                free(temp[k]);
            }
            free(temp); // En son ana diziyi temizle
            return NULL;
        }
    }

    // 4. Doğru indeksleme ile Transpoz işlemi
    // Orijinal matrisin (lignes x colonnes) üzerinde geziyoruz
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            // temp'in satırı = m'nin sütunu, temp'in sütunu = m'nin satırı
            temp[j][i] = m[i][j];
        }
    }

    // free(temp) YOK! Main'e gönderiyoruz.
    return temp;
}

// Yardımcı Fonksiyon: Matrisi serbest bırakır
void liberer_matrice(int **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; ++i) {
        free(m[i]);
    }
    free(m);
}

void display(int **m, int l, int c) {
    for (int i = 0; i < l; ++i) {
        printf("[");
        for (int j = 0; j < c; ++j) {
            printf("%3d", m[i][j]);
        }
        printf(" ]\n");
    }
    printf("\n");
}

int main(void) {
    int lignes, colonnes;
    int status;

    printf("Entrez les dimensions (lignes colonnes) : ");

    // Sağlam okuma (Lecture robuste)
    if (scanf("%d %d", &lignes, &colonnes) != 2 || lignes <= 0 || colonnes <= 0) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    // Matris tahsisi
    int **matric = calloc(lignes, sizeof(int *));
    if (matric == NULL) return 1;

    for (int i = 0; i < lignes; ++i) {
        matric[i] = malloc(colonnes * sizeof(int));
        if (matric[i] == NULL) {
            liberer_matrice(matric, i); // Yazdığımız temizlik fonksiyonunu kullandık
            return 1;
        }
    }

    // Doldurma
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            matric[i][j] = (i + 1) * 10 + (j + 1); // 11, 12, 21, 22 gibi net anlaşılan sayılar
        }
    }

    printf("Matrice Originale (%dx%d) :\n", lignes, colonnes);
    display(matric, lignes, colonnes);

    // 5. Fonksiyonun sonucunu yeni bir pointer'a YAKALAMAK ZORUNDASIN
    int **matric_T = transpoze(matric, lignes, colonnes);

    if (matric_T != NULL) {
        printf("Matrice Transposee (%dx%d) :\n", colonnes, lignes);
        display(matric_T, colonnes, lignes);
    } else {
        printf("Erreur lors de la transposition.\n");
    }

    // 6. HER İKİ MATRİSİ DE TEMİZLE (Libération de toute la mémoire)
    liberer_matrice(matric, lignes);
    liberer_matrice(matric_T, colonnes); // Transpozun satır sayısı 'colonnes' kadardır!

    return 0;
}

```

```c
#include <stdlib.h>
#include <stdio.h>

#define LIGNES 5
#define COLONNES 5

// 1. İMZAYA UYULDU: Dönüş tipi void, 'sonuc' dizisi dışarıdan geliyor.
void satir_toplamlari(int **mat, int lignes, int colonnes, int *sonuc) {
    // Güvenlik kontrolü
    if (mat == NULL || sonuc == NULL || lignes <= 0 || colonnes <= 0) return;

    // 2. HARDCODING KALDIRILDI: Döngüler parametrelere (lignes, colonnes) bağlandı.
    for (int i = 0; i < lignes; ++i) {
        int total = 0;
        for (int j = 0; j < colonnes; ++j) {
            total += mat[i][j];
        }
        sonuc[i] = total; // Dışarıdan gelen dinamik diziye yazıyoruz
    }
}

void libere(int **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; ++i) {
        free(m[i]); // Önce satırları (çocukları) sil
    }
    free(m); // Sonra ana omurgayı sil
}

void display(int **m, int l, int c) {
    if (m == NULL) return;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    // Matris tahsisi (Senin kodun, tamamen doğru)
    int **matrice = calloc(LIGNES, sizeof(int *));
    if (matrice == NULL) return 1;

    for (int i = 0; i < LIGNES; ++i) {
        matrice[i] = malloc(COLONNES * sizeof(int));
        if (matrice[i] == NULL) {
            libere(matrice, i);
            return 1;
        }
    }

    // Doldurma işlemi
    for (int i = 0; i < LIGNES; ++i) {
        for (int j = 0; j < COLONNES; ++j) {
            matrice[i][j] = (i + 1) + (j + 1);
        }
    }

    // 3. İSTERİN YERİNE GETİRİLMESİ: Sonuç dizisi main'de allocate ediliyor.
    // Her satır için bir toplam olacağından, boyutu LIGNES kadar olmalıdır.
    int *somme = malloc(LIGNES * sizeof(int));
    if (somme == NULL) {
        libere(matrice, LIGNES);
        return 1;
    }

    // Fonksiyon çağrısı (Passage par adresse)
    satir_toplamlari(matrice, LIGNES, COLONNES, somme);

    printf("--- Matrice ---\n");
    display(matrice, LIGNES, COLONNES);

    printf("--- Somme des Lignes ---\n");
    for (int i = 0; i < LIGNES; ++i) {
        printf("Ligne %d : %2d\n", i, somme[i]);
    }

    // 4. TEMİZLİK DÜZELTİLDİ: libere fonksiyonu çağrıldı.
    libere(matrice, LIGNES);
    free(somme); // 1D dizi tek hamlede silinir

    return 0;
}

```

```c
#include <stdlib.h>
#include <stdio.h>

// Fonction d'aplatissement (Flatten)
void aplatir_matrice(int **matrice, int lignes, int colonnes, int *vecteur_plat) {
    if (matrice == NULL || vecteur_plat == NULL || lignes <= 0 || colonnes <= 0) return;

    int index_vecteur = 0;

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            // Matristeki elemanı 1D vektöre sırayla kopyala
            vecteur_plat[index_vecteur] = matrice[i][j];
            index_vecteur++; // Vektörün indeksini her eklemede manuel artır
        }
    }
}

// Fonction de libération stricte
void libere_matrice(int **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; ++i) {
        free(m[i]);
    }
    free(m);
}

int main(void) {
    int L = 3;
    int C = 4;

    // 1. Allocation de la matrice 2D
    int **image_2d = calloc(L, sizeof(int *));
    if (image_2d == NULL) return 1;

    for (int i = 0; i < L; ++i) {
        image_2d[i] = malloc(C * sizeof(int));
        if (image_2d[i] == NULL) {
            libere_matrice(image_2d, i);
            return 1;
        }
    }

    // Remplissage avec des valeurs simulées
    int compteur = 10;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            image_2d[i][j] = compteur++;
        }
    }

    // 2. Allocation du Vecteur 1D dans le main (Architecture imposée)
    // La taille totale est lignes * colonnes
    int taille_totale = L * C;
    int *vecteur_1d = malloc(taille_totale * sizeof(int));

    if (vecteur_1d == NULL) {
        libere_matrice(image_2d, L);
        return 1;
    }

    // 3. Appel de la fonction
    aplatir_matrice(image_2d, L, C, vecteur_1d);

    // Affichage des résultats
    printf("Matrice 2D (%dx%d) :\n", L, C);
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%d ", image_2d[i][j]);
        }
        printf("\n");
    }

    printf("\nVecteur 1D Aplati (Taille %d) :\n", taille_totale);
    for (int i = 0; i < taille_totale; ++i) {
        printf("%d ", vecteur_1d[i]);
    }
    printf("\n");

    // 4. Nettoyage
    libere_matrice(image_2d, L);
    free(vecteur_1d);

    return 0;
}

```

```c
#include <stdlib.h>
#include <stdio.h>

// Fonksiyon zaten var olan matrisi modifiye ediyor,
// yeni bir adres döndürmesine gerek yok (void kullanmak daha güvenlidir).
void remplir_identite(int **m, int n) {
    if (m == NULL || n <= 0) return;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

void libere(int **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; ++i) {
        free(m[i]);
    }
    free(m);
}

void display(int **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; ++i) {
        printf("[");
        for (int j = 0; j < l; ++j) {
            printf("%2d ", m[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

int main(void) {
    int N;
    int status;

    // 1. Saisie Sécurisée (Güvenli Girdi Alma Döngüsü)
    do {
        printf("Entrez la dimension de la matrice (N x N) : ");
        // HATA DÜZELTİLDİ: &N eklendi
        status = scanf("%d", &N);
        if (status != 1 || N <= 0) {
            int c;
            // HATA DÜZELTİLDİ: || yerine && kullanıldı
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Saisie invalide.\n");
        }
    } while (status != 1 || N <= 0);

    // 2. Allocation
    int **matrice = calloc(N, sizeof(int *));
    if (matrice == NULL) return 1;

    for (int i = 0; i < N; ++i) {
        matrice[i] = malloc(N * sizeof(int));
        if (matrice[i] == NULL) {
            libere(matrice, i);
            return 1; // HATA DÜZELTİLDİ: Döngüden ve programdan çık!
        }
    }

    // 3. İşlem ve Çıktı
    remplir_identite(matrice, N);

    printf("Matrice Identite (%dx%d) :\n", N, N);
    display(matrice, N);

    // 4. TEMİZLİK (Sadece bir kez!)
    libere(matrice, N);

    return 0;
}

```

```c
#include <stdio.h>

int main(void) {
    // 1. Le bloc de mémoire contigu (Tek parça bellek bloğu)
    // Çift tırnak içindeki \0'lar kelimeleri ayırır.
    // Derleyici en sona otomatik olarak fazladan bir \0 daha ekler.
    char bloc_memoire[] = "Pazartesi\0Sali\0Carsamba\0Persembe\0Cuma\0Cumartesi\0Pazar";

    // 2. Tableau de pointeurs (Pointer dizisi - 7 günlük)
    char *jours[7];

    // İlk kelimenin adresi her zaman 0. indekstir
    int index_jour = 0;
    jours[index_jour] = &bloc_memoire[0];
    index_jour++;

    // 3. Parcours de la mémoire (Bellek taraması)
    // sizeof(bloc_memoire) bize dizinin tüm bayt boyutunu (içindeki \0'lar dahil) verir.
    // Son \0 karakterini kontrol etmemize gerek yok, bu yüzden -1 yapıyoruz.
    size_t taille_memoire = sizeof(bloc_memoire);

    for (size_t i = 0; i < taille_memoire - 1; i++) {
        // Eğer mevcut karakter bir ayırıcıysa (\0)
        if (bloc_memoire[i] == '\0') {
            // Sınır kontrolü (Sécurité)
            if (index_jour < 7) {
                // Bir sonraki harf, yeni kelimenin başlangıcıdır (Pointeur sur le prochain mot)
                jours[index_jour] = &bloc_memoire[i + 1];
                index_jour++;
            }
        }
    }

    // 4. Affichage (Yazdırma)
    printf("Les jours de la semaine :\n");
    for (int i = 0; i < 7; i++) {
        // %s formatı, verdiğimiz adresten başlar ve ilk \0'ı görene kadar okur.
        printf("Jour %d : %s\n", i + 1, jours[i]);
    }

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

// Fonksiyon: Matrisin izini (Trace) pointer aritmetiğiyle hesaplar
int calculer_trace(int **m, int taille) {
    if (m == NULL || taille <= 0) return 0;

    int trace = 0;

    for (int i = 0; i < taille; ++i) {
        // Ana köşegende satır ve sütun indeksi aynıdır (i == j).
        // Normalde m[i][i] yazardık.
        // Pointer aritmetiği ile: *(*(m + i) + i)

        trace += *(*(m + i) + i);
    }

    return trace;
}

// Yardımcı temizlik fonksiyonu
void libere_matrice(int **m, int taille) {
    if (m == NULL) return;
    for (int i = 0; i < taille; ++i) {
        // free(m[i]) yerine pointer aritmetiği:
        free(*(m + i));
    }
    free(m);
}

int main(void) {
    int N = 3;

    // Tahsis (Allocation) - Ana dizi
    int **matrice = calloc(N, sizeof(int *));
    if (matrice == NULL) return 1;

    // Tahsis - Satırlar
    for (int i = 0; i < N; ++i) {
        *(matrice + i) = malloc(N * sizeof(int));
        if (*(matrice + i) == NULL) {
            libere_matrice(matrice, i);
            return 1;
        }
    }

    // Matrisi doldurma: 1'den 9'a kadar
    int compteur = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // matrice[i][j] = compteur; yerine:
            *(*(matrice + i) + j) = compteur++;
        }
    }

    /* Görselleştirme (Matris şu şekilde olur):
       1  2  3  -> Köşegen: 1
       4  5  6  -> Köşegen: 5
       7  8  9  -> Köşegen: 9
       Beklenen Trace = 15
    */

    int resultat = calculer_trace(matrice, N);

    printf("La trace de la matrice est : %d\n", resultat);

    libere_matrice(matrice, N);

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
