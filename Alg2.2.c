#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//2.Seçenek 2.Algoritma

// Karşılaştırma fonksiyonu (qsort için gereklidir)
int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// En küçük n/2 farkı bulan fonksiyon (Algoritma 2)
int EnKucukNFark_Algoritma2(int dizi[], int n) {
    int n2 = n / 2;
    int* farklar = (int*)malloc(sizeof(int) * (n * (n - 1) / 2)); // Tüm farklar için bellek ayır
    int k = 0;

    // Tüm farkları hesapla ve farklar dizisine kaydet
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            farklar[k++] = abs(dizi[j] - dizi[i]);
        }
    }

    // Farkları sırala
    qsort(farklar, n * (n - 1) / 2, sizeof(int), cmpfunc);

    // Sıralı farklar dizisinin ilk n/2 elemanının ortalamasını bul
    int minNFark = 0;
    for (int i = 0; i < n2; i++) {
        minNFark += farklar[i];
    }
    minNFark /= n2;

    free(farklar); // Belleği serbest bırak
    return minNFark;
}

int main() {
    int dizi[100]; // Maksimum 100 elemanlık dizi
    int n = 0; // Dizinin eleman sayısı

    // Kullanıcıdan dizinin eleman sayısını alma
    printf("Kac eleman gireceksiniz? ");
    scanf("%d", &n);

    // En az iki eleman girmesi gerektiğini kontrol etme
    if (n < 2) {
        printf("En az iki eleman girmelisiniz.\n");
        return 1; // Programdan çıkış
    }

    // Kullanıcıdan dizinin elemanlarını alma
    printf("Elemanlari giriniz:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &dizi[i]);
    }

    // En küçük n/2 farkı bul ve ekrana yazdır
    int minNFark = EnKucukNFark_Algoritma2(dizi, n);
    printf("Dizideki en kucuk n/2 fark: %d\n", minNFark);

    return 0;
}
