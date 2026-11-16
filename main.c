#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int sinirla(int d) { return d < 0 ? 0 : (d > 100 ? 100 : d); }

int main() {
    srand(time(NULL));
    int saglik = 100, enerji = 100, oksijen = 100, su = 50, parca = 5, hasar = 10, kilit = 0;
    int gun = 1, tur = 0, oyun = 1, girilenSu, i;
    char zorluk, komut;

    do {
        printf("Zorluk Sec (K: Kolay, N: Normal, Z: Zor): ");
        scanf(" %c", &zorluk);
        zorluk = toupper(zorluk);
        if (zorluk == 'K') { su = 60; parca = 7; hasar = 5; }
        else if (zorluk == 'N') { su = 50; parca = 5; hasar = 10; }
        else if (zorluk == 'Z') { su = 30; parca = 3; hasar = 25; }
        else zorluk = 0;
    } while (!zorluk);

    do {
        if (saglik <= 0 || oksijen <= 0) { printf("\nOyun Bitti: Olum!\n"); break; }
        if (gun > 15) { printf("\nTebrikler, Kazandiniz!\n"); break; }

        printf("\n--------------------------------------------------\n");
        printf("Gun: %d | Tur: %d | Saglik: %d | Enerji: %d | Oksijen: %d\n", gun, tur, saglik, enerji, oksijen);
        printf("Su: %d | Parca: %d | Hasar: %d | Kilit: %d\n", su, parca, hasar, kilit);
        printf("--------------------------------------------------\n");
        printf("KOMUTLAR:\n");
        printf("  [G] - Gezi / Kesif Gorevi\n");
        printf("  [O] - Oksijen Uret\n");
        printf("  [T] - Tamir Et\n");
        printf("  [D] - Durum Raporu\n");
        printf("  [U] - Uyu / Dinlen\n");
        printf("  [K] - Kum Firtinasi\n");
        printf("  [H] - Hava Kilidi Sifresi\n");
        printf("  [Q] - Cikis\n");
        printf("--------------------------------------------------\n");
        printf("Bir komut seciniz: ");
        
        scanf(" %c", &komut);
        komut = toupper(komut);

        int turGecerli = 1;

        switch (komut) {
            case 'G':
                if (enerji < 15) { printf("Yetersiz enerji!\n"); turGecerli = 0; break; }
                enerji -= 15; oksijen -= 10;
                {
                    int zar = rand() % 100, esik = (enerji > 40 && oksijen > 30) ? 40 : 70;
                    printf("Kesif Zari: %d / Esik: %d -> ", zar, esik);
                    if (zar < esik) { su += 15; printf("Basarili! 15 Su bulundu.\n"); }
                    else { parca += 2; printf("Basarili! 2 Parca bulundu.\n"); }
                }
                break;
            case 'O':
                if (su < 2 || enerji < 10) { printf("Yetersiz kaynak!\n"); turGecerli = 0; break; }
                enerji -= 10;
                printf("Kullanilacak su (Mevcut: %d): ", su);
                scanf("%d", &girilenSu);
                if (girilenSu > su || girilenSu <= 0) { printf("Gecersiz!\n"); enerji += 10; turGecerli = 0; break; }
                if (girilenSu % 2 != 0) girilenSu--;
                su -= girilenSu;
                oksijen += (girilenSu / 2) * 3;
                printf("Oksijen uretildi.\n");
                break;
            case 'T':
                if (parca <= 0 || hasar == 0) { printf("Tamir yapilamaz!\n"); turGecerli = 0; break; }
                parca--;
                hasar -= (hasar > 70) ? 30 : (hasar > 31 ? 25 : 15);
                printf("Tamir edildi.\n");
                break;
            case 'D':
                turGecerli = 0;
                if (oksijen < 25 || saglik < 30 || hasar > 70) printf("DIKKAT: Kritik degerler var!\n");
                else printf("TUM SISTEMLER NORMAL.\n");
                break;
            case 'U':
                enerji += 25; oksijen -= 5;
                if (oksijen < 20) { saglik -= 10; printf("Dusuk oksijen saglik dusurdu!\n"); }
                else { saglik += 10; printf("Dinlenildi.\n"); }
                break;
            case 'K':
                {
                    int sure = (zorluk == 'Z') ? 7 : (zorluk == 'N' ? 5 : 3);
                    for (i = 1; i <= sure; i++) {
                        if (saglik <= 0 || oksijen <= 0) break;
                        int zar = rand() % 100;
                        printf("Firtina Tur %d (Zar:%d) -> ", i, zar);
                        if (zar < 50) {
                            int kat = (i % 2 == 0) ? 2 : 1;
                            saglik -= 5 * kat; oksijen -= 8 * kat; hasar += 10 * kat;
                            printf("Hasar alindi!\n");
                        } else { printf("Zararsiz.\n"); }
                    }
                }
                break;
            case 'H':
                {
                    char dogru = 'A' + (gun % 26), giris;
                    int hak = 3, basarili = 0;
                    printf("IPUCU: Sifre A + gun (%d) harf ileride.\n", gun);
                    do {
                        printf("Sifre gir (%d hak): ", hak);
                        scanf(" %c", &giris);
                        if (toupper(giris) == dogru) { basarili = 1; break; }
                        hak--; enerji -= 5;
                        printf(toupper(giris) < dogru ? "Ileri git!\n" : "Geri git!\n");
                    } while (hak > 0);
                    if (basarili) { kilit = 1; printf("Kilit muhurlendi!\n"); }
                    else { hasar += 20; printf("Basarisiz, hasar artti!\n"); }
                }
                break;
            case 'Q':
                oyun = 0;
                break;
            default:
                printf("Tanimsiz komut!\n");
                turGecerli = 0;
        }

        saglik = sinirla(saglik); enerji = sinirla(enerji); oksijen = sinirla(oksijen); hasar = sinirla(hasar);
        if (su < 0) su = 0; if (parca < 0) parca = 0;

        if (turGecerli) {
            tur++;
            if (tur % 3 == 0) {
                gun++; oksijen -= 8;
                if (hasar > 70) saglik -= 5;
            }
        }
    } while (oyun);

    printf("\nOYUN BITTI. Puan: %d\n", (gun * 100) + saglik + oksijen - hasar);
    return 0;
}
