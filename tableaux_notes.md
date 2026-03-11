```c
//Exercice 1 — Somme des éléments d’un tableau
#include <stdio.h>

int main() {
    int n;

    // 1. Lecture de la taille
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1; // Contrainte : n > 0
    }

    // 2. Déclaration du tableau AUTOMATIQUE (VLA)
    // Attention: Ceci est alloué sur la Pile (Stack), pas sur le Tas (Heap)
    int tab[n];
    int somme = 0;

    // 3. Remplissage et calcul simultané
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
        somme += tab[i]; // Akümülatör
    }

    // 4. Sortie stricte selon la consigne
    printf("Somme : %d\n", somme);

    return 0;
}

```

```c
//Exercice 2 — Moyenne des valeurs d’un tableau
#include <stdio.h>

int main() {
    int n;

    // 1. Lecture de la taille (Contrainte: n > 0)
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    // 2. Déclaration du tableau automatique (VLA - Variable Length Array)
    float tab[n];
    float somme = 0.0f; // Initialisation explicite en float

    // 3. Remplissage et sommation (Lecture des valeurs)
    for (int i = 0; i < n; ++i) {
        if (scanf("%f", &tab[i]) != 1) {
            return 1;
        }
        somme += tab[i];
    }

    // 4. Calcul et affichage strict
    float moyenne = somme / n;
    printf("Moyenne : %.2f\n", moyenne);

    return 0;
}

```

```c
#include <stdio.h>

int main() {
    int n;

    // 1. Validation stricte (n doit être positif)
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    // Allocation sur la pile (VLA)
    int tab[n];

    // 2. Remplissage
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
    }

    // 3. Initialisation avec le premier élément
    int min_el = tab[0];
    int idx = 0;

    // 4. Recherche linéaire (On commence à i = 1)
    for (int i = 1; i < n; ++i) {
        if (tab[i] < min_el) { // Strictement inférieur pour garder le PREMIER indice
            min_el = tab[i];
            idx = i;
        }
    }

    // 5. Affichage exact
    printf("Minimum : %d\n", min_el);
    printf("Indice : %d\n", idx);

    return 0;
}

```

```c
//Exercice 5 — Compter les valeurs paires
#include <stdio.h>

int main() {
    int n;

    // 1. Lecture de la taille du tableau
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    // 2. Déclaration du tableau (VLA)
    int tab[n];
    int count_paires = 0; // Compteur pour les valeurs paires

    // 3. Lecture stricte de 'n' éléments
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) {
            return 1;
        }
    }

    // 4. Parcours du tableau pour compter les paires (Traitement a posteriori)
    for (int i = 0; i < n; ++i) {
        if (tab[i] % 2 == 0) {
            count_paires++;
        }
    }

    // 5. Affichage exact demandé par la consigne
    printf("Il y a %d valeurs paires\n", count_paires);

    return 0;
}

```

```c
//tablo palindrome mi kontrol edin
#include <stdio.h>

int is_palindrome(int tab[], int n){

    for(int i = 0; i < n/2; i++){
        if(tab[i] != tab[n-1-i])
            return 0;
    }

    return 1;
}

int main(){

    int n;
    scanf("%d",&n);

    int tab[n];

    for(int i=0;i<n;i++)
        scanf("%d",&tab[i]);

    if(is_palindrome(tab,n))
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}

```

```c
//Addition de deux tableaux
#include <stdio.h>

// t3 hedef dizidir, 'const' konmaz çünkü içini değiştireceğiz.
void somme_tableaux(const int *t1, const int *t2, int *t3, int n) {
    for (int i = 0; i < n; ++i) {
        t3[i] = t1[i] + t2[i];
    }
}

int main() {
    int num;
    printf("Entrez la taille des tableaux : \n");
    if (scanf("%d", &num) != 1 || num <= 0) return 1;

    int tab1[num], tab2[num], tab3[num];

    printf("Saisie du Tableau 1 :\n");
    for (int i = 0; i < num; ++i) {
        if (scanf("%d", &tab1[i]) != 1) return 1;
    }

    printf("Saisie du Tableau 2 :\n");
    for (int i = 0; i < num; ++i) {
        if (scanf("%d", &tab2[i]) != 1) return 1;
    }

    // Fonksiyonu çağırıyoruz
    somme_tableaux(tab1, tab2, tab3, num);

    printf("Tableau somme :\n");
    for (int i = 0; i < num; ++i) {
        printf("%d ", tab3[i]);
    }
    printf("\n");

    return 0;
}

```

```c
// Recherche Dichotomique (İkili Arama)
bool trouve_dichotomique(const int *t, int n, int x) {
    int debut = 0;
    int fin = n - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2; // Ortayı bul (Overflow riskine karşı güvenli formül)

        if (t[milieu] == x) {
            return true; // Bulundu
        }
        if (t[milieu] < x) {
            debut = milieu + 1; // Sağ yarıya geç
        } else {
            fin = milieu - 1;   // Sol yarıya geç
        }
    }
    return false; // Bulunamadı
}

#include <stdio.h>
#include <stdbool.h>

// Diziyi degistirmeyecegimiz icin 'const' ile korumaya aliyoruz.
bool trouve(const int *t, int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (t[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, x;

    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int tab[n];

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
    }

    if (scanf("%d", &x) != 1) return 1;

    // Ternary operatorunun profesyonel kullanimi:
    printf("%s\n", trouve(tab, n, x) ? "Valeur trouvee" : "Valeur absente");

    return 0;
}

```

```c
//Rechercher une valeur et afficher son premier indice
#include <stdio.h>

int trouver_premier_indice(const int *tab, int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (tab[i] == x) {
            return i; // Bulduğumuz an 'ilk' indeksi döndürür ve fonksiyondan çıkarız
        }
    }
    return -1; // Döngü bitti ve bulunamadıysa
}

int main() {
    int n, x;

    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int tab[n];
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
    }

    if (scanf("%d", &x) != 1) return 1;

    // KURAL: Fonksiyonu BİR KERE çağır ve sonucu bir değişkende sakla
    int resultat = trouver_premier_indice(tab, n, x);

    if (resultat != -1) {
        printf("Indice : %d\n", resultat);
    } else {
        printf("-1\n");
    }

    return 0;
}

```

```c
// "Bir dizinin artan (croissant) MI, azalan (décroissant) MI, yoksa tamamen sırasız (non trié) MI olduğunu tek bir for döngüsü içinde bulan fonksiyonu yazın."

// Çözüm (Les drapeaux / Flags): Başlangıçta dizinin hem artan hem de azalan olabileceğini varsayarız (true). Döngü ilerledikçe, eğer bir artış görürsek "azalan" kuralını iptal ederiz (false). Bir azalış görürsek "artan" kuralını iptal ederiz.

void analyser_tri(const int *tab, int n) {
    bool est_croissant = true;
    bool est_decroissant = true;

    for (int i = 1; i < n; ++i) {
        if (tab[i] > tab[i - 1]) {
            est_decroissant = false; // Artış var, demek ki azalan değil
        }
        if (tab[i] < tab[i - 1]) {
            est_croissant = false; // Azalış var, demek ki artan değil
        }
    }

    if (est_croissant) {
        printf("Ordre croissant\n");
    } else if (est_decroissant) {
        printf("Ordre decroissant\n");
    } else {
        printf("Non trie\n");
    }
}

```

```c
//Supprimer mentalement les doublons consécutifs à l’affichage
#include <stdio.h>

void supprimer_doublon_affichage(const int *tab, int n) {
    if (n <= 0) return;

    // 1. İlk elemanı her zaman yazdırıyoruz
    printf("%d ", tab[0]);

    // 2. Kalan elemanları sadece bir öncekiyle FARKLIYSA yazdırıyoruz
    for (int i = 1; i < n; ++i) {
        if (tab[i] != tab[i - 1]) {
            printf("%d ", tab[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int tab[n];
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
    }

    supprimer_doublon_affichage(tab, n);

    return 0;
}

```

```c
//tableau dan eleman silmeini yontemi
int supprimer_element(int *tab, int taille, int index_a_supprimer) {
    // Güvenlik kontrolü (Validation de l'indice)
    if (index_a_supprimer < 0 || index_a_supprimer >= taille) {
        return taille; // Hatalı indekse dokunma, eski boyutu geri döndür
    }

    // Décalage vers la gauche (Sola kaydırma)
    for (int i = index_a_supprimer; i < taille - 1; ++i) {
        tab[i] = tab[i + 1];
    }

    // Mantıksal boyutu 1 küçült (Taille logique décrémentée)
    return taille - 1;
}

```

```c
#include <stdio.h>

void decaler_droite(int *tab, int n) {
    if (n <= 1) return; // 1 elemanlıysa veya boşsa kaydırmaya gerek yok

    // Sondan başla, bir öncekini kopyala (Parcours inversé)
    for (int i = n - 1; i > 0; --i) {
        tab[i] = tab[i - 1];
    }

    // İlk kutuyu sıfırla
    tab[0] = 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int tab[n];
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &tab[i]) != 1) return 1;
    }

    decaler_droite(tab, n);

    // Çıktı işlemi main'de yapılır
    for (int i = 0; i < n; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}

```

```c
//Bu işlemi yaparken [] (indeksleme) operatörünü ve left/right gibi tam sayı indekslerini KULLANMAYIN. Yalnızca Arithmétique des Pointeurs (İşaretçi Aritmetiği) kullanarak diziyi tersine çevirin.
void inverser_pointeurs(int *t, int taille) {
    if (taille <= 1) return;

    int *ptr_debut = t;                 // Dizinin ilk elemanının adresi
    int *ptr_fin = t + taille - 1;      // Dizinin son elemanının adresi

    while (ptr_debut < ptr_fin) {
        // Adreslerin içindeki değerleri değiştir (Déréférencement)
        int temp = *ptr_debut;
        *ptr_debut = *ptr_fin;
        *ptr_fin = temp;

        // Adresleri birbirine doğru kaydır (Pointer arithmetic)
        ptr_debut++;
        ptr_fin--;
    }
}

```

```c
#include <stdio.h>

// Fonksiyon tam olarak yönergedeki gibi tanımlandı
int compter_superieures(const float t[], int n, float moyenne) {
    int compteur = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] > moyenne) {
            ++compteur;
        }
    }
    return compteur;
}

int main() {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    float tab[n]; // Dizi artık float tipinde
    float somme = 0.0f;

    for (int i = 0; i < n; ++i) {
        if (scanf("%f", &tab[i]) != 1) return 1; // %f ile okunuyor
        somme += tab[i];
    }

    float moyenne = somme / n;
    int an_super = compter_superieures(tab, n, moyenne);

    // Çıktı formatı düzeltildi (%.2f)
    printf("Moyenne : %.2f\n", moyenne);
    printf("Valeurs superieures a la moyenne : %d\n", an_super);

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
