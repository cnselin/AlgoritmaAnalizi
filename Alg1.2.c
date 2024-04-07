#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//1.Seçenek 2.Algoritma

// En küçük farkı bulan fonksiyon
int EnKucukFark_SiralamaYapmadan(int dizi[], int n) {
    // En küçük farkı bul
    int minimumFark = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int fark = abs(dizi[j] - dizi[i]);
            if (fark < minimumFark) {
                minimumFark = fark;
            }
        }
    }

    return minimumFark;
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

    // En küçük farkı bul ve ekrana yazdır
    int minFark = EnKucukFark_SiralamaYapmadan(dizi, n);
    printf("Dizideki ardışık elemanlar arasındaki en küçük fark: %d\n", minFark);

    return 0;
}
