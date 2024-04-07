#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//1.Seçenek 1.Algoritma

// Dizi elemanlarını sıralamak için yardımcı fonksiyon
void Sirala(int dizi[], int n) {
    int i, j;
    // Bubble sort algoritmasını kullanarak diziyi sıralama
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                // Elemanları yer değiştirme
                int temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

// En küçük farkı bulan fonksiyon
int EnKucukFark_Siralama(int dizi[], int n) {
    // Diziyi sırala
    Sirala(dizi, n);

    // En küçük farkı bul
    int minimumFark = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        int fark = dizi[i + 1] - dizi[i];
        if (fark < minimumFark) {
            minimumFark = fark;
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
    int minFark = EnKucukFark_Siralama(dizi, n);
    printf("Dizideki ardışık elemanlar arasındaki en küçük fark: %d\n", minFark);

    return 0;
}
