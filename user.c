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
        printf("\n>> Fitur cari konser belum dibuat.\n\n");
        break;
    case 3:
        printf("\n>> Fitur sorting konser belum dibuat.\n\n");
        break;
    case 4:
        printf("\n>> Fitur lihat tiket belum dibuat.\n\n");
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
        tampilanKursi();
        formPemesananTiket(k.nama, k.harga);
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

void tampilanKursi()
{
    char seats[3][10] = {
        {'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O'},
        {'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O'}};

    printf("===============================================================\n");
    printf("                          PILIH KURSI\n");
    printf("===============================================================\n\n");

    printf("Legenda: [O] = Kosong     [X] = Terisi\n\n");
    printf("           PANGGUNG\n");
    printf("-----------------------------------\n");

    char barisLabel[] = {'A', 'B', 'C'};

    for (int i = 0; i < 3; i++)
    {
        printf("  %c ", barisLabel[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("[%c]", seats[i][j]);
        }
        printf("\n");
    }

    char pilihBaris;
    int pilihKursi;
    int idxBaris;

    printf("\nPilih Baris (A/B/C): ");
    scanf(" %c", &pilihBaris);

    if (pilihBaris == 'A' || pilihBaris == 'a')
        idxBaris = 0;
    else if (pilihBaris == 'B' || pilihBaris == 'b')
        idxBaris = 1;
    else if (pilihBaris == 'C' || pilihBaris == 'c')
        idxBaris = 2;
    else
    {
        printf("[!] Baris tidak valid!\n");
        return;
    }

    printf("Pilih Nomor Kursi (1-10): ");
    scanf("%d", &pilihKursi);

    if (pilihKursi < 1 || pilihKursi > 10)
    {
        printf("[!] Nomor kursi tidak valid!\n");
        return;
    }

    int idxKursi = pilihKursi - 1;

    if (seats[idxBaris][idxKursi] == 'X')
    {
        printf("[!] Kursi sudah terisi!\n");
    }
    else
    {
        seats[idxBaris][idxKursi] = 'X';
        printf("\n[✓] Kursi %c%d berhasil dipilih!\n", barisLabel[idxBaris], pilihKursi);
    }

    printf("Tekan ENTER untuk kembali...\n");
    getchar();
}

void formPemesananTiket(char namaKonser[], int hargaKonser)
{
    printf("\n===============================================================\n");
    printf("                      FORM PEMESANAN TIKET\n");
    printf("===============================================================\n\n");

    printf("Nama Konser : %s\n", namaKonser);
    printf("Harga       : %d\n\n", hargaKonser);

    printf("[✓] Pemesanan berhasil!\n");

    printf("\nTekan ENTER untuk kembali ke menu utama...");
    getchar();
}
