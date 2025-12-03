#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Akun daftarAkun[100] = {"novan", "123"};
int jumlahAkun = 1;

struct Konser konserList[3] = {
    {1, "Love in Harmony", "Jakarta", "12-05-2025", 350000,
     "Konser romantis penuh nuansa cinta dengan musisi papan atas."},
    {2, "Rock The Night", "Bandung", "20-06-2025", 280000,
     "Konser rock terbesar tahun ini dengan penampilan band-band ternama."},
    {3, "Symphony Dream", "Surabaya", "05-07-2025", 500000,
     "Pertunjukan orkestra megah dengan kualitas internasional."}};

void tampilMenuAwal()
{
    printf("          === Selamat Datang di Aplikasi Tiket Konser ===\n");
    printf("=====================================================================\n");
    printf("                    SISTEM PEMESANAN TIKET KONSER\n");
    printf("                        Enjoy your concert\n");
    printf("=====================================================================\n");

    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Keluar\n\n");
    printf("=====================================================================\n");
    int pilihan;
    printf("Pilih menu: ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        countdownClear(1);
        tampilanLogin();
        break;
    case 2:
        countdownClear(1);
        tampilanRegister();
        break;
    case 3:
        printf("\nTerima kasih telah menggunakan aplikasi kami. Sampai jumpa!\n");
        exit(0);
        break;
    default:

        printf("\nPilihan tidak valid. Silakan coba lagi.\n\n");
        Sleep(2500);
        countdownClear(3);
        tampilMenuAwal();
        break;
    }
}

void tampilanRegister()
{
    char username[50];
    char password[50];

    printf("===============================================================\n");
    printf("                         REGISTRASI AKUN\n");
    printf("               Yuukk buat akun untuk melanjutkan\n");
    printf("===============================================================\n\n");

    printf("Masukkan Username Kamu : ");
    scanf(" %[^\n]", username);

    printf("Masukkan Password Kamu : ");
    scanf("%s", password);

    strcpy(daftarAkun[jumlahAkun].username, username);
    strcpy(daftarAkun[jumlahAkun].password, password);
    jumlahAkun++;

    printf("\nYeay akun berhasil dibuat!\n");
    countdownClear(2);
    tampilMenuAwal();
}

int cekLogin(char username[], char password[])
{
    for (int i = 0; i < jumlahAkun; i++)
    {
        if (strcmp(daftarAkun[i].username, username) == 0)
        {
            if (strcmp(daftarAkun[i].password, password) == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    return 2;
}

void tampilanLogin()
{
    char username[50];
    char password[50];

    while (1)
    {
        printf("===============================================================\n");
        printf("                           LOGIN\n");
        printf("===============================================================\n\n");

        printf("Username : ");
        scanf(" %[^\n]", username);

        printf("Password : ");
        scanf("%s", password);

        int status = cekLogin(username, password);
        if (status == 1)
        {
            printf("\nLogin berhasil! Selamat datang, %s.\n\n", username);
            countdownClear(2);
            menuUser();
            break;
        }
        else if (status == 0)
        {
            printf("\n[!] Password salah. Silakan coba lagi.\n\n");
        }
        else
        {
            printf("\n[!] Username tidak ditemukan. Silakan buat akun.\n\n");

            countdownClear(3);
            tampilMenuAwal();
        }

        countdownClear(2);
    }
}

void menuUser()
{
    int pilihan;

    printf("===============================================================\n");
    printf("                          MAIN MENU\n");
    printf("===============================================================\n\n");

    printf("1. Lihat Daftar Konser\n");
    printf("2. Cari Konser\n");
    printf("3. Urutkan Konser (Sorting)\n");
    printf("4. Pesan Tiket\n");
    printf("5. Lihat Tiket Saya\n");
    printf("6. Logout\n\n");

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
        printf("\n>> Fitur Pesan konser belum dibuat.\n\n");

        // detailKonser();
        break;
    case 5:
        printf("\n>> Fitur lihat tiket belum dibuat.\n\n");
        break;
    case 6:
        printf("\nLogout berhasil. Kembali ke menu utama.\n\n");
        break;
    default:
        printf("\nPilihan tidak valid.\n\n");
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

    for (int i = 0; i < 3; i++)
    {
        printf(" %-3d | %-25s | %-15s | %-11s | %d\n",
               konserList[i].id, konserList[i].nama, konserList[i].lokasi, konserList[i].tanggal, konserList[i].harga);
    }
    printf("===========================================================================\n");
    int idKonser;
    printf("\nMasukkan No konser yang ingin dilihat: ");
    scanf("%d", &idKonser);
    countdownClear(1);
    detailKonser(idKonser);
}

void detailKonser(int idKonser)
{
    int target = -1;
    for (int i = 0; i < 3; i++)
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

    printf("\n1. Pesan Tiket\n");
    printf("2. Kembali\n");

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
