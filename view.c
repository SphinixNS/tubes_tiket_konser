#include "view.h"
#include <stdio.h>


void tampilMenuAwal() {
    printf("          === Selamat Datang di Aplikasi Tiket Konser ===\n");
    printf("=====================================================================\n");
    printf("                    SISTEM PEMESANAN TIKET KONSER\n");
    printf("                        Enjoy your concert\n");
    printf("=====================================================================\n");

    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Keluar\n\n");

    printf("Silakan pilih menu: ");

    int pilihan;

    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("Kamu memilih Login.\n");
            break;
        case 2:
            printf("Kamu memilih Register.\n");
            break;
        case 3:
            printf("Thank you sudah menggunakan aplikasi kami. SEE YOU AGAIN!\n");
            break;
        default:
            printf("Pilihan kamu gak valid. Silakan coba lagi ya....\n");
            break;
    }
}

    void tampilanRegister() {
    char username[50];
    char password[50];

    printf("===============================================================\n");
    printf("                         REGISTRASI AKUN\n");
    printf("===============================================================\n\n");

    printf("Masukkan Username Kamu : ");
    scanf(" %[^\n]", username);

    printf("Masukkan Password Kamu : ");
    scanf("%s", password);

    printf("\n Yeay akun berhasil dibuat!\n");

    scanf("%*c"); 
    scanf("%*c");                               
}


