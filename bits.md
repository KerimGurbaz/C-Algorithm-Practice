```c
#include <stdio.h>
#include <stdint.h>

// 1. Adım: Haklar için Bit Maskelerinin Tanımlanması (Shift operatörü ile)
// Her bir hak, sadece tek bir biti '1' olan eşsiz bir sayıdır.
#define LECTURE    (1 << 0)  // 0000 0001 (Decimal: 1, Hex: 0x01)
#define ECRITURE   (1 << 1)  // 0000 0010 (Decimal: 2, Hex: 0x02)
#define EXECUTION  (1 << 2)  // 0000 0100 (Decimal: 4, Hex: 0x04)
#define ADMIN      (1 << 3)  // 0000 1000 (Decimal: 8, Hex: 0x08)

// Sınavlarda hayat kurtaran, 8 bitlik sayıyı ikilik (binary) formatta yazdıran fonksiyon
void afficher_binaire(uint8_t octet) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (octet >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Başlangıçta hiçbir hak yok (0000 0000)
    uint8_t droits = 0;

    printf("--- GESTION DES DROITS D'ACCES ---\n\n");

    // 2. Adım: Hakları BİRLEŞTİRME (Opérateur OU : | )
    // LECTURE (0000 0001) | ECRITURE (0000 0010) = 0000 0011
    droits = LECTURE | ECRITURE;
    printf("1. Ajout Lecture et Ecriture (L|E) : ");
    afficher_binaire(droits);

    // 3. Adım: Mevcut hakların üzerine yeni hak EKLEME (Opérateur OU assignation : |= )
    // 0000 0011 |= 0000 0100 -> 0000 0111
    droits |= EXECUTION;
    printf("2. Ajout Execution (L|E|X)         : ");
    afficher_binaire(droits);

    // 4. Adım: Bir hakkın varlığını KONTROL ETME (Opérateur ET : & )
    // Sınavlarda "OU" ile hak verilir, "ET" ile kontrol edilir.
    printf("\n--- VERIFICATION ---\n");
    if (droits & ECRITURE) {
        printf("[OK] Le droit d'ECRITURE est present.\n");
    }

    if (!(droits & ADMIN)) {
        printf("[NO] Le droit d'ADMIN n'est PAS present.\n");
    }

    // 5. Adım: Bir hakkı GERİ ALMA (Opérateur ET INVERSE : & ~) - Sınavların Favorisi
    // ECRITURE (0000 0010) ters çevrilir (~0000 0010 = 1111 1101)
    // 0000 0111 & 1111 1101 = 0000 0101 (Sadece Lecture ve Execution kalır)
    droits &= ~ECRITURE;
    printf("\n3. Retrait de l'Ecriture (L|X)     : ");
    afficher_binaire(droits);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdint.h> // Pour uint8_t (entier non signé sur 8 bits)

// 1. Définition des masques (Puissances de 2)
#define PERM_EXEC  0x01  // Binaire : 0000 0001 (1)
#define PERM_WRITE 0x02  // Binaire : 0000 0010 (2)
#define PERM_READ  0x04  // Binaire : 0000 0100 (4)

// Fonction utilitaire pour vérifier l'état des bits
void afficher_droits(uint8_t droits) {
    // L'opérateur ET (&) agit ici comme un filtre/scanner.
    // Il isole le bit demandé. Si le résultat est > 0, le droit est actif.
    printf("Lecture   : %s\n", (droits & PERM_READ)  ? "[X] AUTORISE" : "[ ] REFUSE");
    printf("Ecriture  : %s\n", (droits & PERM_WRITE) ? "[X] AUTORISE" : "[ ] REFUSE");
    printf("Execution : %s\n", (droits & PERM_EXEC)  ? "[X] AUTORISE" : "[ ] REFUSE");
    printf("-> Valeur mémoire : %d (Hex: 0x%02X)\n\n", droits, droits);
}

int main(void) {
    // Initialisation d'un fichier vierge (0000 0000)
    uint8_t mes_droits = 0x00;

    printf("--- ETAPE 1 : Fichier nouvellement cree ---\n");
    afficher_droits(mes_droits);

    // L'opérateur OU (|) "allume" le bit sans éteindre les autres
    printf("--- ETAPE 2 : Ajout du droit de LECTURE ---\n");
    mes_droits = mes_droits | PERM_READ;
    afficher_droits(mes_droits);

    // Syntaxe raccourcie (|=) et combinaison simultanée
    printf("--- ETAPE 3 : Ajout ECRITURE et EXECUTION d'un coup ---\n");
    mes_droits |= (PERM_WRITE | PERM_EXEC);
    afficher_droits(mes_droits);

    printf("--- ETAPE 4 : Retrait du droit d'ECRITURE ---\n");
    // Maskenin tersini al (~) ve mevcut haklarla VE'le (&)
    mes_droits &= ~PERM_WRITE;
    afficher_droits(mes_droits);

    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#define CLIGNOTEMENTS 20

// Guirlande'ı ekrana basan fonksiyon
void afficher_guirlande(uint8_t etat) {
    // \r (Carriage Return) imleci satırın en başına alır, alt satıra geçmez.
    printf("\r");

    // 8 biti MSB'den (En Anlamlı Bit) LSB'ye (En Az Anlamlı Bit) doğru okuyoruz
    for (int i = 7; i >= 0; i--) {
        if ((etat >> i) & 1) {
            printf("*");
        } else {
            printf("-");
        }
    }

    // \n kullanmadığımız için çıktının ekranda hemen görünmesini zorluyoruz
    fflush(stdout);
}

int main() {
    // Rastgele sayı üretecini başlat (Sınavda unutursan hep aynı sürelerde yanıp söner)
    srand(time(NULL));

    // Başlangıç durumu: *-*-*-*-
    // Yıldızları 1, tireleri 0 olarak düşün: 10101010 (Binaire) = 0xAA (Hexadecimal)
    uint8_t guirlande = 0xAA;

    printf("Simulation de la guirlande en cours...\n");

    for (int i = 0; i < CLIGNOTEMENTS; i++) {
        afficher_guirlande(guirlande);

        // 0.1s (100,000 µs) ile 1.0s (1,000,000 µs) arası rastgele gecikme
        int delai = (rand() % 900001) + 100000;
        usleep(delai);

        // Clignotement (Yanıp Sönme) Mantığı:
        // Tüm bitleri tersine çeviriyoruz (1'ler 0, 0'lar 1 olur).
        // Bitwise NOT (~) operatörü bu iş için kusursuzdur.
        guirlande = ~guirlande;
    }

    printf("\nTermine.\n");
    return 0;
}

```

```c
#include <stdio.h>
#include <stdint.h>

void activate_bit(uint8_t *val, int bit_index) {
    if (val == NULL) return;
    // Pointer kullanarak orijinal değeri heap/stack üzerinde değiştiriyoruz
    *val |= (1 << bit_index);
}

int main() {
    uint8_t status = 0; // Başlangıçta her şey kapalı: 00000000

    printf("Baslangic: %u\n", status);

    activate_bit(&status, 3); // 3. biti yak
    printf("3. Bit Aktif: %u\n", status); // Ekranda 8 görmelisin

    activate_bit(&status, 0); // 0. biti yak
    printf("0. ve 3. Bit Aktif: %u\n", status); // 8 + 1 = 9 görmelisin

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h> // strncpy için zorunlu

#define MAX_LIVRES 100
#define MAX_TITRE 100
#define MAX_AUTEUR 50

// 1. Struct Tanımlaması (typedef ile)
typedef struct {
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int annee_publication;
    int nombre_copies;
} Livre;

// 2. Yeni kitap ekleme fonksiyonu
// Envanter dizisini ve mevcut kitap sayısının adresini (&) alıyoruz ki kalıcı olarak artırabilelim.
int ajouter_livre(Livre inventaire[], int *nb_livres, const char *titre, const char *auteur, int annee, int copies) {
    if (*nb_livres >= MAX_LIVRES) {
        printf("Erreur : Inventaire plein.\n");
        return 0; // Başarısız
    }

    // DİKKAT: C'de struct içindeki bir array'e '=' ile atama YAPILAMAZ.
    // Güvenli kopyalama için strncpy kullanılır.
    strncpy(inventaire[*nb_livres].titre, titre, MAX_TITRE - 1);
    inventaire[*nb_livres].titre[MAX_TITRE - 1] = '\0'; // Güvenlik kilidi (Null terminator)

    strncpy(inventaire[*nb_livres].auteur, auteur, MAX_AUTEUR - 1);
    inventaire[*nb_livres].auteur[MAX_AUTEUR - 1] = '\0';

    inventaire[*nb_livres].annee_publication = annee;
    inventaire[*nb_livres].nombre_copies = copies;

    (*nb_livres)++; // Kitap sayacını bir artır

    return 1; // Başarılı
}

// 3. Stok güncelleme fonksiyonu (Emprunt / Retour)
// Kitabın kopyası değil, doğrudan kendisi değişeceği için Livre * (pointer) alıyoruz.
void maj_stock(Livre *livre, int variation) {
    if (livre == NULL) return;

    // variation: Ödünç alma için -1, İade için +1 gönderilecek
    if (livre->nombre_copies + variation < 0) {
        printf("Erreur : Impossible d'emprunter '%s', stock insuffisant (0 copie).\n", livre->titre);
    } else {
        livre->nombre_copies += variation;
        printf("Succes : Stock de '%s' mis a jour. Nouvel etat : %d copie(s).\n", livre->titre, livre->nombre_copies);
    }
}

int main() {
    Livre bibliotheque[MAX_LIVRES];
    int total_livres = 0;

    printf("--- INITIALISATION DE L'INVENTAIRE ---\n");
    ajouter_livre(bibliotheque, &total_livres, "Le C en 20 Heures", "Denis Ritchie", 1972, 3);
    ajouter_livre(bibliotheque, &total_livres, "Pointeurs Avances", "Jean Michel", 2021, 1);

    printf("\n--- OPERATIONS SUR LE STOCK ---\n");

    // İşlem 1: Birinci kitabı ödünç al (Stok 3 -> 2)
    maj_stock(&bibliotheque[0], -1);

    // İşlem 2: İkinci kitabı ödünç al (Stok 1 -> 0)
    maj_stock(&bibliotheque[1], -1);

    // İşlem 3: İkinci kitabı tekrar ödünç almaya çalış (HATA vermelidir)
    maj_stock(&bibliotheque[1], -1);

    // İşlem 4: Birinci kitabı iade et (Stok 2 -> 3)
    maj_stock(&bibliotheque[0], 1);

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TITRE 100
#define MAX_AUTEUR 50
#define MAX_INVENTAIRE 1000 // Capacité de notre base de données

// 1. DÉFINITION DE LA STRUCTURE (Le Schéma de Données)
// On utilise 'typedef' pour éviter d'écrire "struct Livre" à chaque fois.
typedef struct {
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int annee_publication;
    int nombre_copies;
} Livre;

// 2. FONCTION D'AJOUT (Création d'une nouvelle entrée)
// On passe le total par adresse (*total_livres) pour le mettre à jour dans le main.
bool ajouter_livre(Livre *inventaire, int *total_livres, const char *titre, const char *auteur, int annee, int copies) {
    if (inventaire == NULL || total_livres == NULL || *total_livres >= MAX_INVENTAIRE) {
        printf("[!] Erreur : Inventaire plein ou pointeur invalide.\n");
        return false;
    }

    int index = *total_livres;

    // SÉCURITÉ : On utilise strncpy pour éviter les débordements de mémoire (Buffer Overflow)
    // et on s'assure que le dernier caractère est bien un '\0'.
    strncpy(inventaire[index].titre, titre, MAX_TITRE - 1);
    inventaire[index].titre[MAX_TITRE - 1] = '\0';

    strncpy(inventaire[index].auteur, auteur, MAX_AUTEUR - 1);
    inventaire[index].auteur[MAX_AUTEUR - 1] = '\0';

    inventaire[index].annee_publication = annee;
    inventaire[index].nombre_copies = copies;

    (*total_livres)++; // On incrémente le compteur global

    printf("[+] Livre ajoute : '%s' (%d copies)\n", titre, copies);
    return true;
}

// 3. FONCTION DE MISE À JOUR (Opération Transactionnelle)
// 'variation' : -1 pour un emprunt, +1 pour un retour, etc.
bool modifier_stock(Livre *inventaire, int total_livres, const char *titre_recherche, int variation) {
    if (inventaire == NULL || titre_recherche == NULL) return false;

    // Recherche linéaire dans la base de données
    for (int i = 0; i < total_livres; i++) {
        // strcmp renvoie 0 si les chaînes sont identiques
        if (strcmp(inventaire[i].titre, titre_recherche) == 0) {

            // Vérification de la logique métier (on ne peut pas emprunter un livre en rupture)
            if (inventaire[i].nombre_copies + variation < 0) {
                printf("[-] Emprunt refuse : Plus de stock pour '%s'.\n", titre_recherche);
                return false;
            }

            // Mise à jour
            inventaire[i].nombre_copies += variation;

            if (variation < 0) {
                printf("[>] Emprunt reussi : '%s' (Reste: %d)\n", titre_recherche, inventaire[i].nombre_copies);
            } else {
                printf("[<] Retour reussi : '%s' (Nouveau stock: %d)\n", titre_recherche, inventaire[i].nombre_copies);
            }

            return true; // Opération terminée
        }
    }

    printf("[!] Erreur : Le livre '%s' n'existe pas dans l'inventaire.\n", titre_recherche);
    return false;
}

// Fonction utilitaire pour l'affichage
void afficher_inventaire(const Livre *inventaire, int total_livres) {
    printf("\n--- INVENTAIRE ACTUEL (%d livres) ---\n", total_livres);
    for (int i = 0; i < total_livres; i++) {
        printf("ID %d | %s par %s (%d) - Stock : %d\n",
               i, inventaire[i].titre, inventaire[i].auteur,
               inventaire[i].annee_publication, inventaire[i].nombre_copies);
    }
    printf("------------------------------------\n\n");
}

int main(void) {
    // Allocation de l'inventaire dans la pile (Stack)
    Livre bibliotheque[MAX_INVENTAIRE];
    int nombre_de_livres = 0;

    // Tests d'ajout
    ajouter_livre(bibliotheque, &nombre_de_livres, "Le C en 20 Heures", "Dennis Ritchie", 1978, 5);
    ajouter_livre(bibliotheque, &nombre_de_livres, "Algorithmique Avancee", "Thomas Cormen", 2009, 2);

    afficher_inventaire(bibliotheque, nombre_de_livres);

    // Tests de gestion de stock
    modifier_stock(bibliotheque, nombre_de_livres, "Le C en 20 Heures", -1); // Emprunt (Reste 4)
    modifier_stock(bibliotheque, nombre_de_livres, "Algorithmique Avancee", -2); // Emprunt de tout le stock (Reste 0)

    // Tentative d'emprunt sur un stock vide (Doit échouer)
    modifier_stock(bibliotheque, nombre_de_livres, "Algorithmique Avancee", -1);

    // Retour d'un livre
    modifier_stock(bibliotheque, nombre_de_livres, "Algorithmique Avancee", +1);

    afficher_inventaire(bibliotheque, nombre_de_livres);

    return 0;
}

```

```c
#include <stdio.h>

// 1. Enum Tanımlaması (typedef ile)
// Eğer değer atamazsak derleyici otomatik olarak 0'dan başlar:
// EN_LIGNE=0, HORS_LIGNE=1, EN_JEU=2, EN_PAUSE=3
typedef enum {
    EN_LIGNE,
    HORS_LIGNE,
    EN_JEU,
    EN_PAUSE
} StatutJoueur;

// 2. Durum Güncelleme Fonksiyonu
// Orijinal değişkeni değiştireceğimiz için Pointer (*) kullanmak ZORUNDAYIZ.
void maj_statut(StatutJoueur *statut_actuel, StatutJoueur nouveau_statut) {
    if (statut_actuel == NULL) return;
    *statut_actuel = nouveau_statut;
}

// 3. Durum Görüntüleme Fonksiyonu
// Sadece okuma yapacağımız için doğrudan değeri (Pass by Value) alıyoruz.
void afficher_statut(StatutJoueur statut) {
    // Enum'ların en iyi dostu switch bloğudur.
    switch (statut) {
        case EN_LIGNE:
            printf("Le joueur est en ligne.\n");
            break;
        case HORS_LIGNE:
            printf("Le joueur est hors ligne.\n");
            break;
        case EN_JEU:
            printf("Le joueur est actuellement en jeu.\n");
            break;
        case EN_PAUSE:
            printf("Le joueur est en pause.\n");
            break;
        default:
            // Beklenmeyen bir tamsayı gelme ihtimaline karşı her zaman default ekle
            printf("Statut inconnu.\n");
            break;
    }
}

int main() {
    // Başlangıç durumu ataması
    StatutJoueur joueur1 = HORS_LIGNE;

    printf("--- CONNEXION ---\n");
    afficher_statut(joueur1);

    // Durumu güncelle (Referans adresi & ile gönderilir)
    maj_statut(&joueur1, EN_LIGNE);
    afficher_statut(joueur1);

    printf("\n--- DEMARRAGE DE PARTIE ---\n");
    maj_statut(&joueur1, EN_JEU);
    afficher_statut(joueur1);

    printf("\n--- AFK (Away From Keyboard) ---\n");
    maj_statut(&joueur1, EN_PAUSE);
    afficher_statut(joueur1);

    return 0;
}

```

```c
#include <stdio.h>
#include <string.h>

// 1. DÉFINITION DE L'ENUM (Le vocabulaire des états)
// Le compilateur assigne automatiquement : HORS_LIGNE=0, EN_LIGNE=1, etc.
typedef enum {
    HORS_LIGNE,
    EN_LIGNE,
    EN_JEU,
    EN_PAUSE
} StatutJoueur;

// Intégration de l'enum dans une structure métier
typedef struct {
    char pseudo[50];
    StatutJoueur statut;
} Joueur;

// 2. FONCTION DE MISE À JOUR (Passage par adresse pour modifier l'original)
void mettre_a_jour_statut(Joueur *j, StatutJoueur nouveau_statut) {
    if (j == NULL) return;

    // On pourrait ajouter une logique métier ici (ex: on ne peut pas
    // passer de HORS_LIGNE directement à EN_PAUSE sans être EN_LIGNE d'abord).
    j->statut = nouveau_statut;
}

// 3. FONCTION D'AFFICHAGE (Le Switch est obligatoire en ingénierie)
void afficher_statut(StatutJoueur statut) {
    printf("Statut actuel : ");

    switch (statut) {
        case HORS_LIGNE:
            printf("[ ] Le joueur est deconnecte.\n");
            break; // OBLIGATOIRE pour ne pas exécuter les cas suivants
        case EN_LIGNE:
            printf("[*] Le joueur est en ligne, dans les menus.\n");
            break;
        case EN_JEU:
            printf("[!] Le joueur est actuellement en jeu. Ne pas deranger.\n");
            break;
        case EN_PAUSE:
            printf("[zZ] Le joueur est en pause.\n");
            break;
        default:
            // Le filet de sécurité (Au cas où la RAM serait corrompue)
            printf("[?] Statut inconnu ou erreur systeme.\n");
            break;
    }
}

int main(void) {
    // Initialisation
    Joueur joueur1;
    strncpy(joueur1.pseudo, "AlexData", sizeof(joueur1.pseudo) - 1);
    joueur1.pseudo[sizeof(joueur1.pseudo) - 1] = '\0';

    // Départ
    joueur1.statut = HORS_LIGNE;
    printf("Connexion de %s...\n", joueur1.pseudo);

    // Simulation de la vie du joueur
    mettre_a_jour_statut(&joueur1, EN_LIGNE);
    afficher_statut(joueur1.statut);

    mettre_a_jour_statut(&joueur1, EN_JEU);
    afficher_statut(joueur1.statut);

    mettre_a_jour_statut(&joueur1, EN_PAUSE);
    afficher_statut(joueur1.statut);

    mettre_a_jour_statut(&joueur1, HORS_LIGNE);
    afficher_statut(joueur1.statut);

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
