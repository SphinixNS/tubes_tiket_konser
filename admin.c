#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

void menuAdmin()
{
    int pilihan;

    printf("===============================================================\n");
    printf("                          MAIN MENU\n");
    printf("===============================================================\n\n");
    printf("1. Lihat Daftar Konser\n");
    printf("2. Tambah Konser\n");
    printf("3. Hapus Konser\n");
    printf("4. Logout\n\n");
    printf("===============================================================\n\n");

    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        countdownClear(2);
        daftarKonserAdmin();
        break;
    case 2:
        countdownClear(2);
        tambahKonser();
        break;
    case 3:
        countdownClear(2);
        hapusKonser();
        break;
    case 4:
        printf("\nLogout berhasil. Kembali ke menu utama.\n\n");
        countdownClear(3);
        tampilMenuAwal();
        break;
    default:
        printf("\nPilihan tidak valid.\n\n");
        break;
    }
}

void daftarKonserAdmin()
{
    printf("===========================================================================\n");
    printf("                          DAFTAR KONSER\n");
    printf("===========================================================================\n");
    printf(" %-3s | %-25s | %-15s | %-11s | %-10s\n",
           "ID", "Nama Konser", "Lokasi", "Tanggal", "Harga");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahKonser; i++)
    {
        printf(" %-3d | %-25s | %-15s | %-11s | Reg:%d  VIP:%d\n",
               konserList[i].id, konserList[i].nama, konserList[i].lokasi, konserList[i].tanggal, konserList[i].hargaReguler, konserList[i].hargaVIP);
    }
    printf("===========================================================================\n");
    int idKonser;
    printf("\nMasukkan konser yang ingin dilihat (0 untuk kembali): ");
    scanf("%d", &idKonser);
    if (idKonser == 0)
    {
        countdownClear(1);
        menuAdmin();
        return;
    }
    else
    {
        countdownClear(1);
        detailKonserAdmin(idKonser);
    }
}

void detailKonserAdmin(int idKonser)
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
        daftarKonserAdmin();
    }

    struct Konser k = konserList[target];

    printf("\n===============================================================\n");
    printf("                          DETAIL KONSER\n");
    printf("===============================================================\n");
    printf("ID Konser       : %d\n", k.id);
    printf("Nama            : %s\n", k.nama);
    printf("Lokasi          : %s\n", k.lokasi);
    printf("Tanggal         : %s\n", k.tanggal);
    printf("Harga VIP       : %d\n", k.hargaVIP);
    printf("Kuota VIP       : %d\n", k.jumlahTiketVIP);
    printf("Harga Reguler   : %d\n", k.hargaReguler);
    printf("Kuota Reguler   : %d\n", k.jumlahTiketReguler);
    printf("Deskripsi       :\n%s\n", k.deskripsi);
    printf("===============================================================\n");
    printf("1. Edit\n");
    printf("2. Kembali\n");
    printf("===============================================================\n\n");

    int menu;
    printf("\nPilih menu: ");
    scanf("%d", &menu);
    getchar();

    if (menu == 1)
    {
        countdownClear(1);
        editKonser(k.id - 1);
    }
    else if (menu == 2)
    {
        countdownClear(1);
        daftarKonserAdmin();
    }
    else
    {
        printf("\n[!] Menu tidak valid!\n");
        printf("Layar akan refresh...\n");
        countdownClear(1);
        detailKonserAdmin(idKonser);
    }
}

void tambahKonser()
{
    struct Konser k;
    printf("=====================================================\n");
    printf("                 TAMBAH DATA KONSER                  \n");
    printf("=====================================================\n\n");
    printf("Nama konser : ");
    scanf(" %[^\n]", k.nama);
    printf("Lokasi konser : ");
    scanf(" %[^\n]", k.lokasi);
    printf("Tanggal konser : ");
    scanf(" %[^\n]", k.tanggal);
    printf("Deskripsi konser : ");
    scanf(" %[^\n]", k.deskripsi);
    printf("\n== Input Harga Tiket ==\n");
    printf("Harga tiket VIP      : ");
    scanf("%d", &k.hargaVIP);
    printf("Jumlah tiket VIP     : ");
    scanf("%d", &k.jumlahTiketVIP);
    printf("Harga tiket Reguler  : ");
    scanf("%d", &k.hargaReguler);
    printf("Jumlah tiket Reguler : ");
    scanf("%d", &k.jumlahTiketReguler);

    jumlahKonser++;
    k.id = jumlahKonser;
    konserList[jumlahKonser - 1] = k;
    printf("Konser berhasil ditambahkan!\n");
    countdownClear(2);
    daftarKonserAdmin();
}

void editKonser(int idKonser)
{

    struct Konser *k = &konserList[idKonser];

    printf("\n=================== DATA LAMA =======================\n");
    printf("ID Konser       : %d\n", k->id);
    printf("Nama            : %s\n", k->nama);
    printf("Lokasi          : %s\n", k->lokasi);
    printf("Tanggal         : %s\n", k->tanggal);
    printf("Harga VIP       : %d\n", k->hargaVIP);
    printf("Kuota VIP       : %d\n", k->jumlahTiketVIP);
    printf("Harga Reguler   : %d\n", k->hargaReguler);
    printf("Kuota Reguler   : %d\n", k->jumlahTiketReguler);
    printf("Deskripsi       :\n%s\n", k->deskripsi);
    printf("=============== MASUKKAN DATA BARU =================\n");

    char nama[50];
    char lokasi[30];
    char tanggal[15];
    int hargaVIP;
    int hargaReguler;
    int jumlahVIPBaru;
    int jumlahRegBaru;
    char deskripsi[200];
    printf("Nama Baru [%s]: ", k->nama);
    scanf(" %[^\n]", nama);
    printf("Lokasi Baru [%s]: ", k->lokasi);
    scanf(" %[^\n]", lokasi);
    printf("Tanggal Baru [%s]: ", k->tanggal);
    scanf(" %[^\n]", tanggal);
    printf("Harga VIP baru [%d]: ", k->hargaVIP);
    scanf("%d", &hargaVIP);
    printf("Jumlah tiket VIP baru [%d]: ", k->jumlahTiketVIP);
    scanf("%d", &jumlahVIPBaru);
    printf("Harga Reguler baru [%d]: ", k->hargaReguler);
    scanf("%d", &hargaReguler);
    printf("Jumlah tiket Reguler baru [%d]: ", k->jumlahTiketReguler);
    scanf("%d", &jumlahRegBaru);
    printf("Deskripsi Baru:\n> ");
    scanf(" %[^\n]", deskripsi);

    countdownClear(2);
    printf("=====================================================\n");
    printf("              KONFIRMASI DATA KONSER EDIT            \n");
    printf("=====================================================\n\n");
    printf("Nama            : %s\n", nama);
    printf("Lokasi          : %s\n", lokasi);
    printf("Tanggal         : %s\n", tanggal);
    printf("Harga VIP       : %d\n", hargaVIP);
    printf("Kuota VIP       : %d\n", jumlahVIPBaru);
    printf("Harga Reguler   : %d\n", hargaReguler);
    printf("Kuota Reguler   : %d\n", jumlahRegBaru);
    printf("Deskripsi       :\n%s\n\n", deskripsi);

    printf("=====================================================\n");
    printf("Apakah Anda yakin ingin menyimpan perubahan? (y/n): ");
    char konfirmasi;
    scanf(" %c", &konfirmasi);

    if (konfirmasi == 'y' || konfirmasi == 'Y')
    {
        strcpy(k->nama, nama);
        strcpy(k->lokasi, lokasi);
        strcpy(k->tanggal, tanggal);
        k->hargaVIP = hargaVIP;
        k->jumlahTiketVIP = jumlahVIPBaru;
        k->hargaReguler = hargaReguler;
        k->jumlahTiketReguler = jumlahRegBaru;
        strcpy(k->deskripsi, deskripsi);

        printf("\nPerubahan berhasil disimpan!\n");
    }
    else
    {
        printf("Perubahan dibatalkan.\n");
        countdownClear(3);
        daftarKonserAdmin();
        return;
    }

    countdownClear(3);
    daftarKonserAdmin();
}

void hapusKonser()
{

    printf("===========================================================================\n");
    printf("                          DAFTAR KONSER\n");
    printf("===========================================================================\n");
    printf(" %-3s | %-25s | %-15s | %-11s | %-10s\n",
           "No", "Nama Konser", "Lokasi", "Tanggal", "Harga");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahKonser; i++)
    {
        printf(" %-3d | %-25s | %-15s | %-11s | Reg:%d  VIP:%d\n",
               konserList[i].id, konserList[i].nama, konserList[i].lokasi, konserList[i].tanggal,
               konserList[i].hargaReguler, konserList[i].hargaVIP);
    }
    printf("===========================================================================\n");
    int idKonser;
    printf("Masukkan ID konser yang ingin dihapus (0 untuk kembali): ");
    scanf("%d", &idKonser);
    if (idKonser == 0)
    {
        countdownClear(1);
        menuAdmin();
        return;
    }

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
        printf("\nKonser dengan ID %d tidak ditemukan!\n", idKonser);
        countdownClear(2);
        hapusKonser();
    }
    countdownClear(2);

    printf("=====================================================\n");
    printf("                KONFIRMASI PENGHAPUSAN              \n");
    printf("=====================================================\n\n");

    printf("ID              : %d\n", konserList[target].id);
    printf("Nama            : %s\n", konserList[target].nama);
    printf("Lokasi          : %s\n", konserList[target].lokasi);
    printf("Tanggal         : %s\n", konserList[target].tanggal);
    printf("Harga VIP       : %d\n", konserList[target].hargaVIP);
    printf("Harga Reguler   : %d\n", konserList[target].hargaReguler);
    printf("Deskripsi       :\n%s\n\n", konserList[target].deskripsi);

    printf("=====================================================\n");
    char konfirmasi;
    printf("Apakah Anda yakin ingin menghapus konser ini? (Y/N): ");
    scanf(" %c", &konfirmasi);

    if (konfirmasi == 'Y' || konfirmasi == 'y')
    {
        for (int i = target; i < jumlahKonser - 1; i++)
        {
            // proses hapus -> geser array
            konserList[i] = konserList[i + 1];
            konserList[i].id = i + 1;
        }
        jumlahKonser--;

        countdownClear(2);

        printf("=====================================================\n");
        printf("                KONSER BERHASIL DIHAPUS              \n");
        printf("=====================================================\n");
        printf("Konser dengan ID %d telah dihapus.\n", idKonser);
    }
    else
    {
        printf("\nPenghapusan dibatalkan.\n");
    }

    countdownClear(3);
    daftarKonserAdmin();
}
