#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


void menuUser()
{
    int pilihan;

    printf("===============================================================\n");
    printf("                          MAIN MENU\n");
    printf("===============================================================\n\n");

    printf("1. Pesan Tiket Konser\n");
    printf("2. Cari Konser\n");
    printf("3. Urutkan Konser (Sorting)\n");
    printf("4. Lihat Tiket Saya\n");
    printf("5. Logout\n\n");
    printf("===============================================================\n\n");

    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        countdownClear(2);
        lihatDaftarKonser();
        break;
    case 2:
        countdownClear(2);
        searchConcert();
        break;
    case 3:
        countdownClear(1);
        sortingKonser();
        break;
    case 4:
        countdownClear(1);
        lihatTiketSaya();
        break;
    case 5:
        printf("\nLogout berhasil. Kembali ke menu utama.\n\n");
        countdownClear(3);
        tampilMenuAwal();
        break;
    default:
        printf("\nPilihan tidak valid.\n\n");
        countdownClear(2);
        menuUser();
        break;
    }
}

void lihatDaftarKonser()
{
    printf("===========================================================================\n");
    printf("                          DAFTAR KONSER\n");
    printf("===========================================================================\n");
    printf(" %-3s | %-25s | %-15s | %-11s | %-10s\n",
           "No", "Nama Konser", "Lokasi", "Tanggal", "Harga");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahKonser; i++)
    {
        printf(" %-3d | %-25s | %-15s | %-11s | %d\n",
               konserList[i].id, konserList[i].nama, konserList[i].lokasi, konserList[i].tanggal, konserList[i].harga);
    }
    printf("===========================================================================\n");
    int idKonser;
    printf("\nMasukkan No konser yang ingin dipesan (0 untuk kembali): ");
    scanf("%d", &idKonser);
    if (idKonser == 0)
    {
        countdownClear(1);
        menuUser();
        return;
    }
    else
    {
        countdownClear(1);
        detailKonser(idKonser);
    }
}

void detailKonser(int idKonser)
{
    int target = -1;
    for (int i = 0; i < jumlahKonser; i++)
    {
        if (konserList[i].id == idKonser)
        {
            target = i;
            break;
        }
    }

    if (target == -1)
    {
        printf("\n[!] ID konser tidak ditemukan!\n");
        printf("Layar akan kembali ke menu sebelumnya...\n");
        countdownClear(2);
        lihatDaftarKonser();
        return;
    }

    struct Konser k = konserList[target];

    printf("\n===============================================================\n");
    printf("                          DETAIL KONSER\n");
    printf("===============================================================\n");
    printf("ID Konser      : %d\n", k.id);
    printf("Nama           : %s\n", k.nama);
    printf("Lokasi         : %s\n", k.lokasi);
    printf("Tanggal        : %s\n", k.tanggal);
    printf("Harga          : %d\n", k.harga);
    printf("Deskripsi      :\n%s\n", k.deskripsi);
    printf("===============================================================\n\n");
    printf("1. Pesan Tiket\n");
    printf("2. Kembali\n");
    printf("===============================================================\n\n");

    int menu;
    printf("\nPilih menu: ");
    scanf("%d", &menu);
    getchar(); 

    if (menu == 1)
    {
        countdownClear(1);
        char kursiTerpilih[5];
        tampilanKursi(kursiTerpilih); 

        if (kursiTerpilih[0] != '\0')
        { formPemesananTiket(k.nama, k.harga, kursiTerpilih, k.tanggal);
        }
    }
    else if (menu == 2)
    {
        countdownClear(1);
        lihatDaftarKonser();
    }
    else
    {
        printf("\n[!] Menu tidak valid!\n");
        printf("Layar akan refresh...\n");
        countdownClear(1);
        detailKonser(idKonser);
    }
}


void tampilanKursi(char kursiTerpilih[]) {
    char seats[3][10] = {
        {'O','O','X','O','O','O','X','O','O','O'},
        {'O','X','X','O','O','O','O','O','O','O'},
        {'O','O','O','O','X','O','O','X','O','O'}
    };

    char barisLabel[] = {'A', 'B', 'C'};

    printf("===============================================================\n");
    printf("                          PILIH KURSI\n");
    printf("===============================================================\n\n");
    printf("Legenda: [O] = Kosong     [X] = Terisi\n\n");
    printf("           PANGGUNG\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("  %c ", barisLabel[i]);
        for (int j = 0; j < 10; j++) {
            printf("[%c]", seats[i][j]);
        }
        printf("\n");
    }

    char pilihBaris;
    int pilihKursi;
    int idxBaris;

    printf("\nPilih Baris (A/B/C): ");
    scanf(" %c", &pilihBaris);

    if (pilihBaris == 'A' || pilihBaris == 'a') idxBaris = 0;
    else if (pilihBaris == 'B' || pilihBaris == 'b') idxBaris = 1;
    else if (pilihBaris == 'C' || pilihBaris == 'c') idxBaris = 2;
    else {
        printf("[!] Baris tidak valid!\n");
        kursiTerpilih[0] = '\0';
        return;
    }

    printf("Pilih Nomor Kursi (1-10): ");
    scanf("%d", &pilihKursi);

    if (pilihKursi < 1 || pilihKursi > 10) {
        printf("[!] Nomor kursi tidak valid!\n");
        kursiTerpilih[0] = '\0';
        return;
    }

    if (seats[idxBaris][pilihKursi - 1] == 'X') {
        printf("[!] Kursi sudah terisi!\n");
        kursiTerpilih[0] = '\0';
        return;
    }

    kursiTerpilih[0] = barisLabel[idxBaris];
    kursiTerpilih[1] = '-';

    if (pilihKursi == 10) {
        kursiTerpilih[2] = '1';
        kursiTerpilih[3] = '0';
        kursiTerpilih[4] = '\0';
    } else {
        kursiTerpilih[2] = pilihKursi + '0';
        kursiTerpilih[3] = '\0';
    }

    printf("\n[✓] Kursi %s berhasil dipilih!\n", kursiTerpilih);
}


void formPemesananTiket(char namaKonser[], int hargaKonser, char kursi[], char tanggal[]) {

    strcpy(tiketSaya[jumlahTiket].namaKonser, namaKonser);
    strcpy(tiketSaya[jumlahTiket].kursi, kursi);
    strcpy(tiketSaya[jumlahTiket].tanggal, tanggal);
    tiketSaya[jumlahTiket].harga = hargaKonser;
    jumlahTiket++;

    printf("\n===============================================================\n");
    printf("                      PEMESANAN BERHASIL\n");
    printf("===============================================================\n\n");

    printf("Nama Konser : %s\n", namaKonser);
    printf("Kursi       : %s\n", kursi);
    printf("Harga       : %d\n", hargaKonser);

    printf("\nTekan ENTER untuk kembali...");
    getchar(); 
    getchar();

    menuUser();
}


void lihatTiketSaya() {
    printf("===============================================================\n");
    printf("                           TIKET SAYA\n");
    printf("===============================================================\n\n");

    if (jumlahTiket == 0) {
        printf("Anda belum memesan tiket apapun.\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        getchar();
        return;
    }

    printf("No | Nama Konser            | Kursi | Tanggal      | Harga\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < jumlahTiket; i++) {
        printf("%-3d| %-22s | %-5s | %-12s | %d\n", i+1, tiketSaya[i].namaKonser, tiketSaya[i].kursi, tiketSaya[i].tanggal, tiketSaya[i].harga);
    }

    printf("\nTekan ENTER untuk kembali...");
    getchar();
    getchar();
}

char lower(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

int panjang(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int cocok(char nama[], char cari[]) {
    int ln = panjang(nama);
    int lc = panjang(cari);

    for (int i = 0; i <= ln - lc; i++) {
        int sama = 1;
        for (int j = 0; j < lc; j++) {
            if (lower(nama[i + j]) != lower(cari[j])) {
                sama = 0;
                break;
            }
        }
        if (sama) return 1;
    }

    return 0;
}

void searchConcert() {
    char cari[50];
    int ketemu = 0;

    printf("===============================================================\n");
    printf("                          CARI KONSER\n");
    printf("===============================================================\n\n");

    printf("Masukkan nama konser yang dicari: ");
    scanf(" %[^\n]", cari);

    printf("\nHasil Pencarian:\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        if (cocok(konserList[i].nama, cari)) {
            ketemu = 1;
            printf("%d. %s\n", konserList[i].id, konserList[i].nama);
            printf("   Lokasi : %s\n", konserList[i].lokasi);
            printf("   Harga  : %d\n", konserList[i].harga);
            printf("---------------------------------------------------------------\n");
        }
    }

    if (!ketemu) {
        printf("Tidak ada konser dengan nama tersebut.\n");
        printf("---------------------------------------------------------------\n");
    }

    printf("\nTekan ENTER untuk kembali...");
    getchar();
    getchar();

    menuUser();
}

void sortingKonser() {
    int pilihan;

    printf("===============================================================\n");
    printf("                       SORTING DAFTAR KONSER\n");
    printf("===============================================================\n\n");

    printf("Urutkan berdasarkan:\n");
    printf("1. Harga Termurah → Termahal\n");
    printf("2. Harga Termahal → Termurah\n");
    printf("3. Tanggal Terdekat\n");
    printf("4. Nama (A-Z)\n\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);
    getchar(); 

    struct Konser tempList[100];
    for (int i = 0; i < jumlahKonser; i++) {
        tempList[i] = konserList[i];
    }

    for (int i = 0; i < jumlahKonser - 1; i++) {
        for (int j = 0; j < jumlahKonser - i - 1; j++) {

            int swap = 0;

            if (pilihan == 1 && tempList[j].harga > tempList[j+1].harga)
                swap = 1;

            if (pilihan == 2 && tempList[j].harga < tempList[j+1].harga)
                swap = 1;

            if (pilihan == 3 && strcmp(tempList[j].tanggal, tempList[j+1].tanggal) > 0)
                swap = 1;

            if (pilihan == 4 && strcmp(tempList[j].nama, tempList[j+1].nama) > 0)
                swap = 1;

            if (swap) {
                struct Konser t = tempList[j];
                tempList[j] = tempList[j+1];
                tempList[j+1] = t;
            }
        }
    }

    printf("\n===============================================================\n");
    printf("                    HASIL SORTING KONSER\n");
    printf("===============================================================\n");
    printf(" %-3s | %-25s | %-15s | %-11s | %-10s\n",
           "No", "Nama Konser", "Lokasi", "Tanggal", "Harga");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < jumlahKonser; i++) {
        printf(" %-3d | %-25s | %-15s | %-11s | %d\n",
               tempList[i].id, tempList[i].nama, tempList[i].lokasi,
               tempList[i].tanggal, tempList[i].harga);
    }

    printf("===============================================================\n");
    printf("Tekan ENTER untuk kembali...");
    getchar();

    menuUser();
}


