#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

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
            struct Akun akun;
            for (int i = 0; i < jumlahAkun; i++)
            {
                if (strcmp(daftarAkun[i].username, username) == 0)
                {
                    if (strcmp(daftarAkun[i].password, password) == 0)
                    {
                        akun = daftarAkun[i];
                    }
                }
            }

            printf("\nLogin berhasil! Selamat datang, %s.\n\n", username);
            countdownClear(2);
            if (strcmp(akun.role, "admin") == 0)
            {
                menuAdmin();
            }
            else
            {
                menuUser();
            }

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
