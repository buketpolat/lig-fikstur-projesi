#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAKIM_SAYISI 19
#define HAFTA_SAYISI 38

// Takım isimlerini dosyadan okuyan fonksiyon
void takim_listesini_oku(char takimlar[TAKIM_SAYISI][50], char *dosya_adi) {
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        perror("Dosya açma hatası");
        exit(1);
    }

    for (int i = 0; i < TAKIM_SAYISI; i++) {
        fgets(takimlar[i], 50, dosya);
        // Satır sonu karakterini temizle
        takimlar[i][strcspn(takimlar[i], "\n")] = 0;
    }

    fclose(dosya);
}

// Fikstür oluşturan fonksiyon
void fikstur_olustur(char takimlar[TAKIM_SAYISI][50], char fikstur[HAFTA_SAYISI][TAKIM_SAYISI / 2][2][50]) {
    int eslesmeler[TAKIM_SAYISI];
    for (int i = 0; i < TAKIM_SAYISI; i++) {
        eslesmeler[i] = i;
    }

    for (int hafta = 0; hafta < HAFTA_SAYISI; hafta++) {
        for (int i = 0; i < TAKIM_SAYISI / 2; i++) {
            strcpy(fikstur[hafta][i][0], takimlar[eslesmeler[i]]);
            strcpy(fikstur[hafta][i][1], takimlar[eslesmeler[TAKIM_SAYISI - 1 - i]]);
        }

        // Takımları döndür (ilk takım hariç)
        int son_takim = eslesmeler[TAKIM_SAYISI - 1];
        for (int i = TAKIM_SAYISI - 1; i > 1; i--) {
            eslesmeler[i] = eslesmeler[i - 1];
        }
        eslesmeler[1] = son_takim;
    }
}

// Fikstürü ekrana ve dosyaya yazdıran fonksiyon
void fiksturu_yazdir(char fikstur[HAFTA_SAYISI][TAKIM_SAYISI / 2][2][50], char *dosya_adi) {
    FILE *dosya = fopen(dosya_adi, "w");
    if (dosya == NULL) {
        perror("Dosya açma hatası");
        exit(1);
    }

    for (int hafta = 0; hafta < HAFTA_SAYISI; hafta++) {
        printf("\n%d. Hafta\n", hafta + 1);
        fprintf(dosya, "\n%d. Hafta\n", hafta + 1);
        for (int i = 0; i < TAKIM_SAYISI / 2; i++) {
            printf("%s vs %s\n", fikstur[hafta][i][0], fikstur[hafta][i][1]);
            fprintf(dosya, "%s vs %s\n", fikstur[hafta][i][0], fikstur[hafta][i][1]);
        }
    }

    fclose(dosya);
}

// Mevcut fikstür dosyasını okuyan ve içeriğini ekrana yazdıran fonksiyon
void fikstur_dosyasini_oku_ve_yazdir(char *dosya_adi) {
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        perror("Dosya açma hatası");
        exit(1);
    }

    char satir[100];
    printf("\nMevcut Fikstür İçeriği:\n");
    while (fgets(satir, 100, dosya) != NULL) {
        printf("%s", satir);
    }

    fclose(dosya);
}

int main() {
    char takimlar[TAKIM_SAYISI][50];
    char fikstur[HAFTA_SAYISI][TAKIM_SAYISI / 2][2][50];

    // Takım isimlerini dosyadan oku
    takim_listesini_oku(takimlar, "takimlar.txt");

    // Fikstür oluştur
    fikstur_olustur(takimlar, fikstur);

    // Fikstürü ekrana ve dosyaya yazdır
    fiksturu_yazdir(fikstur, "fikstur.txt");

    // Mevcut fikstür dosyasını oku ve ekrana yazdır
    fikstur_dosyasini_oku_ve_yazdir("fikstur.txt");

    return 0;
}