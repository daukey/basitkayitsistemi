#include <stdio.h>
#include <string.h>


void veri_al(char dizi[], int uzunluk) {
    fgets(dizi, uzunluk, stdin);
    size_t len = strlen(dizi); // dizinin karakter uzunlugunu incele
    if (len > 0 && dizi[len - 1] == '\n') { 
        dizi[len - 1] = '\0'; // son karakteri sil (\n)
    } 
	else {
        buffer_temizle();
    }
}

void buffer_temizle() {
    int c;
    while ((c = getchar()) != '\n'); // fgets ve scanf cakýsýyor. arada alýnan karakteri silmezsem duzgun calýsmýyor.
}

int main() {
    int secim;
    int kayit = 0;     
	int max_kayit=30;
    int max_uzunluk=30;
    int seri_numaralari[max_kayit];
    char musteriadsoyad[max_kayit][2][max_uzunluk];

    while(1) {
        printf("\n--- ARIZA KAYIT SISTEMI ---\n");
        printf("1) Yeni ariza kaydi olustur\n");
        printf("2) Tamirdeki cihazlari listele\n");
        printf("0) Cikis\n");
        printf("Seciminiz: ");

        if (scanf("%d", &secim) != 1) { 
            printf("Hata: Gecerli bir rakam girin!\n");
            buffer_temizle();
            continue;
        }

        if (secim == 1) {
            if (kayit < max_kayit) {
                buffer_temizle();

                printf("Musteri Adini Girin: ");
                veri_al(musteriadsoyad[kayit][0], max_uzunluk);

                printf("Musteri Soyadini Girin: ");
                veri_al(musteriadsoyad[kayit][1], max_uzunluk);

                printf("Cihaz Seri No (10 Rakam): ");
                while (scanf("%d", &seri_numaralari[kayit]) != 1) { 
                    printf("Hata: Seri no sadece sayi olmali: ");
                    buffer_temizle();
                }
                
                printf("\n*** KAYIT TAMAM: %s %s (No: %d) ***\n", 
                       musteriadsoyad[kayit][0], musteriadsoyad[kayit][1], seri_numaralari[kayit]);
                
                kayit++;
            } 
			else {
                printf("Hata: Kayit kapasitesi dolu.(Maksimum %d cihaz)\n",max_kayit);
            }
        } 
        else if (secim == 2) {
            printf("\n--- SISTEMDE KAYITLI CIHAZLAR (Toplam: %d) ---\n", kayit);
            if (kayit == 0) {
                printf("Kayitli cihaz yok.\n");
            } 
			else {
                printf("NO | Seri No    | Musteri Adi Soyadi\n");
                int i;
                for (i=0; i < kayit; i++) {
                    printf("%02d | %10d | %s %s\n", 
                           i + 1, seri_numaralari[i],musteriadsoyad[i][0],musteriadsoyad[i][1]);
                }
            }
        } 
        else if (secim == 0) {
            printf("Cikis yapiliyor.\n");
            break; 
        }
    }
    return 0;
}
