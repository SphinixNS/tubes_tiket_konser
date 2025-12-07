#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int panjang(char s[])
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

int cocok(char nama[], char cari[])
{
    int ln = panjang(nama);
    int lc = panjang(cari);

    for (int i = 0; i <= ln - lc; i++)
    {
        int sama = 1;
        for (int j = 0; j < lc; j++)
        {
            if (lower(nama[i + j]) != lower(cari[j]))
            {
                sama = 0;
                break;
            }
        }
        if (sama)
            return 1;
    }

    return 0;
}

int compareTanggal(const char *t1, const char *t2)
{
    int d1, m1, y1;
    int d2, m2, y2;

    sscanf(t1, "%d-%d-%d", &d1, &m1, &y1);
    sscanf(t2, "%d-%d-%d", &d2, &m2, &y2);

    if (y1 != y2)
        return y1 - y2;
    if (m1 != m2)
        return m1 - m2;
    return d1 - d2;
}



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
               konserList[i].id, konserList[i].nama, konserList[i].lokasi, konserList[i].tanggal, konserList[i].hargaReguler);
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
        countdownClear(2);
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
    printf("1. Pesan Tiket\n");
    printf("2. Kembali\n");
    printf("===============================================================\n\n");

    int menu;
    printf("\nPilih menu: ");
    scanf("%d", &menu);
    getchar();

    if (menu == 1)
    {
        formPemesananTiket(idKonser);
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

void formPemesananTiket(int idKonser)
{

    struct Konser *k = &konserList[idKonser - 1];

    printf("\n===============================================================\n");
    printf("                        PEMESANAN TIKET\n");
    printf("===============================================================\n");
    printf("Nama Pembeli : ");
    char namaPembeli[50];
    scanf(" %[^\n]", namaPembeli);

    printf("\nPilih Jenis Tiket:\n");
    printf("1. VIP     (Rp.%d) — Sisa: %d\n", k->hargaVIP, k->jumlahTiketVIP);
    printf("2. Reguler (Rp.%d) — Sisa: %d\n", k->hargaReguler, k->jumlahTiketReguler);
    printf("Pilihan: ");

    int pilihan;
    scanf("%d", &pilihan);

    char jenis[20];
    int harga = 0;
    int *kuota = NULL;

    if (pilihan == 1)
    {
        strcpy(jenis, "VIP");
        harga = k->hargaVIP;
        kuota = &k->jumlahTiketVIP;
    }
    else if (pilihan == 2)
    {
        strcpy(jenis, "Reguler");
        harga = k->hargaReguler;
        kuota = &k->jumlahTiketReguler;
    }
    else
    {
        printf("[!] Jenis tiket tidak valid!\n");
        countdownClear(2);
        detailKonser(idKonser);
        return;
    }

    printf("Jumlah tiket yang dibeli : ");
    int jumlah;
    scanf("%d", &jumlah);

    if (jumlah <= 0)
    {
        printf("[!] Jumlah tidak valid!\n");
        countdownClear(2);
        detailKonser(idKonser);
        return;
    }

    if (*kuota < jumlah)
    {
        printf("\n[!] Kuota tidak cukup!\n");
        countdownClear(2);
        detailKonser(idKonser);
        return;
    }

    *kuota -= jumlah;

    strcpy(tiketSaya[jumlahTiket].namaPembeli, namaPembeli);
    strcpy(tiketSaya[jumlahTiket].namaKonser, k->nama);
    strcpy(tiketSaya[jumlahTiket].tanggal, k->tanggal);
    strcpy(tiketSaya[jumlahTiket].jenisTiket, jenis);
    tiketSaya[jumlahTiket].idKonser =  k->id;
    tiketSaya[jumlahTiket].jumlah = jumlah;
    tiketSaya[jumlahTiket].totalHarga = harga * jumlah;
    jumlahTiket++;
    countdownClear(2);

    printf("\n===============================================================\n");
    printf("                      PEMESANAN BERHASIL\n");
    printf("===============================================================\n");
    printf("Nama Pembeli : %s\n", namaPembeli);
    printf("Konser       : %s\n", k->nama);
    printf("Tanggal      : %s\n", k->tanggal);
    printf("Jenis Tiket  : %s\n", jenis);
    printf("Jumlah       : %d\n", jumlah);
    printf("Total Harga  : %d\n", harga * jumlah);
    printf("===============================================================\n\n");

    printf("Tekan ENTER untuk kembali...");
    getchar();
    getchar();
    countdownClear(2);
    menuUser();
}

void lihatTiketSaya()
{
    printf("===============================================================\n");
    printf("                           TIKET SAYA\n");
    printf("===============================================================\n\n");

    if (jumlahTiket == 0)
    {
        printf("Anda belum memiliki tiket yang dipesan.\n");
        printf("===============================================================\n\n");
        countdownClear(3);
        menuUser();
        return;
    }

    printf("ID | Nama Konser              | Tanggal     | Jenis Tiket | Jumlah | Total Harga\n");
    printf("----------------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahTiket; i++)
    {
        printf(" %-3d | %-23s | %-11s | %-11s | %-6d | %d\n",
               i + 1,
               tiketSaya[i].namaKonser,
               tiketSaya[i].tanggal,
               tiketSaya[i].jenisTiket,
               tiketSaya[i].jumlah,
               tiketSaya[i].totalHarga);
    }

    printf("=====================================================================\n\n");

    int pilihan;
    printf("Masukkan No tiket untuk melihat detail (0 untuk kembali): ");
    scanf("%d", &pilihan);
    getchar();
    if (pilihan == 0)
    {
        countdownClear(1);
        menuUser();
        return;
    }
    else
    {
        countdownClear(1);
        detailTiket(pilihan-1);
    }
}

void detailTiket(int idTiket)
{
    int target = -1;
    for (int i = 0; i < jumlahTiket; i++)
    {
        if (i == idTiket)
        {
            target = i;
            break;
        }
    }

    if (target == -1)
    {
        printf("\n[!] ID tiket tidak ditemukan!\n");
        printf("Layar akan kembali ke menu sebelumnya...\n");
        countdownClear(2);
        lihatTiketSaya();
        return;
    }

    struct Tiket t = tiketSaya[target];

    printf("\n===============================================================\n");
    printf("                          DETAIL TIKET\n");
    printf("===============================================================\n");
    printf("Nama Pembeli : %s\n", t.namaPembeli);
    printf("Nama Konser  : %s\n", t.namaKonser);
    printf("Tanggal      : %s\n", t.tanggal);
    printf("Jenis Tiket  : %s\n", t.jenisTiket);
    printf("Jumlah       : %d\n", t.jumlah);
    printf("Total Harga  : %d\n", t.totalHarga);
    printf("===============================================================\n\n");

    printf("Tekan ENTER untuk kembali...");
    getchar();
    countdownClear(2);
    lihatTiketSaya();
}


void searchConcert()
{
    char cari[50];
    int ketemu = 0;

    printf("===============================================================\n");
    printf("                          CARI KONSER\n");
    printf("===============================================================\n\n");

    printf("Masukkan nama konser yang dicari: ");
    scanf(" %[^\n]", cari);

    printf("\nHasil Pencarian:\n");
    printf("---------------------------------------------------------------\n");

    printf(" %-3s | %-25s | %-15s | %-11s | %-10s\n",
           "No", "ID", "Nama Konser", "Lokasi", "Tanggal", "Harga");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahKonser; i++)
    {
        if (cocok(konserList[i].nama, cari))
        {
            ketemu = 1;
            printf("%-3d | %-3d | %-25s | %-15s | %-11s | %d\n",
                   i + 1, konserList[i].id, konserList[i].nama, konserList[i].lokasi, konserList[i].tanggal, konserList[i].hargaReguler);
        }
    }


    if (!ketemu)
    {
        printf("Tidak ada konser dengan nama tersebut.\n");
        printf("---------------------------------------------------------------\n");
    }
    else
    {
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
            countdownClear(2);
            detailKonser(idKonser);
        }
    }

    printf("\nTekan ENTER untuk kembali...");
    getchar();
    getchar();
    countdownClear(2);

    menuUser();
}

void sortingKonser()
{
    int pilihan;

    printf("===============================================================\n");
    printf("                       SORTING DAFTAR KONSER\n");
    printf("===============================================================\n\n");

    printf("Urutkan berdasarkan:\n");
    printf("1. Harga Termurah → Termahal\n");
    printf("2. Harga Termahal → Termurah\n");
    printf("3. Tanggal\n");
    printf("4. Nama (A-Z)\n\n");
    printf("Pilih (0 untuk kembali) : ");
    scanf("%d", &pilihan);
    getchar();
    if (pilihan == 0)
    {
        countdownClear(1);
        menuUser();
    }

    struct Konser tempList[100];
    for (int i = 0; i < jumlahKonser; i++)
    {
        tempList[i] = konserList[i];
    }

    for (int i = 0; i < jumlahKonser - 1; i++)
    {
        for (int j = 0; j < jumlahKonser - i - 1; j++)
        {

            int swap = 0;

            if (pilihan == 1 && tempList[j].hargaReguler > tempList[j + 1].hargaReguler)
                swap = 1;

            if (pilihan == 2 && tempList[j].hargaReguler < tempList[j + 1].hargaReguler)
                swap = 1;

            if (pilihan == 3 && compareTanggal(tempList[j].tanggal, tempList[j + 1].tanggal) > 0)
                swap = 1;

            if (pilihan == 4 && strcmp(tempList[j].nama, tempList[j + 1].nama) > 0)
                swap = 1;

            if (swap)
            {
                struct Konser t = tempList[j];
                tempList[j] = tempList[j + 1];
                tempList[j + 1] = t;
            }
        }
    }

    printf("\n===============================================================\n");
    printf("                    HASIL SORTING KONSER\n");
    printf("===============================================================\n");
    printf(" %-3s | %-25s | %-15s | %-11s | %-10s\n",
           "No", "Nama Konser", "Lokasi", "Tanggal", "Harga");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < jumlahKonser; i++)
    {
        printf(" %-3d | %-25s | %-15s | %-11s | %d\n",
               i + 1, tempList[i].nama, tempList[i].lokasi,
               tempList[i].tanggal, tempList[i].hargaReguler);
    }

    printf("===============================================================\n");
    printf("Tekan ENTER untuk kembali...");
    getchar();
    countdownClear(2);
    sortingKonser();
}
