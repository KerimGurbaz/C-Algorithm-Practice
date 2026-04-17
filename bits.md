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


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```

```c


```
