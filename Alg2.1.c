#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//2.Seçenek 1.Algoritma

// Dizi elemanlarını sıralamak için yardımcı fonksiyon
void BubbleSort(int dizi[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                int temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

// En küçük n/2 farkı bulan fonksiyon (Algoritma 1)
int EnKucukNFark_Algoritma1(int dizi[], int n) {
    // Diziyi sırala
    BubbleSort(dizi, n);

    // Dizinin ilk n/2 elemanını al ve her bir ardışık elemanın farkını hesapla
    int n2 = n / 2;
    int* farklar = (int*)malloc(sizeof(int) * n2);
    for (int i = 0; i < n2; i++) {
        farklar[i] = dizi[i + n2] - dizi[i];
    }

    // Farkları sırala
    BubbleSort(farklar, n2);

    // En küçük n/2 farkı döndür
    int minNFark = INT_MAX;
    for (int i = 0; i < n2; i++) {
        if (farklar[i] < minNFark) {
            minNFark = farklar[i];
        }
    }

    free(farklar); // Belleği serbest bırak
    return minNFark;
}

int main() {
    int n;
    printf("Kac eleman gireceksiniz? ");
    scanf("%d", &n);

    if (n < 2) {
        printf("En az iki eleman girmelisiniz.\n");
        return 1;
    }

    int* dizi = (int*)malloc(sizeof(int) * n);

    printf("Elemanlari giriniz:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &dizi[i]);
    }

    int minNFark = EnKucukNFark_Algoritma1(dizi, n);

    printf("Dizideki en küçük n/2 fark: %d\n", minNFark);

    free(dizi); // Belleği serbest bırak

    return 0;
}
