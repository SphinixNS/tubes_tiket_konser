#include "view.h"
#include <stdio.h>
#include <string.h>

struct Akun {
    char username[50];
    char password[50];
};

struct Akun daftarAkun[100];  
int jumlahAkun = 0;

void tampilMenuAwal() {
    printf("          === Selamat Datang di Aplikasi Tiket Konser ===\n");
    printf("=====================================================================\n");
    printf("                    SISTEM PEMESANAN TIKET KONSER\n");
    printf("                        Enjoy your concert\n");
    printf("=====================================================================\n");

    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Keluar\n\n");
}

void tampilanRegister() {
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
}

int cekLogin(char username[], char password[]) {
    for (int i = 0; i < jumlahAkun; i++) {
        if (strcmp(daftarAkun[i].username, username) == 0 && strcmp(daftarAkun[i].password, password) == 0) {
            return 1; 
        }
    }
    return 0; 
}

void tampilanLogin() {
    char username[50];
    char password[50];

    while (1) {
        printf("===============================================================\n");
        printf("                        ⋆｡˚୨ LOGIN ୧˚｡⋆ \n");
        printf("===============================================================\n\n");

        printf("Username : ");
        scanf(" %[^\n]", username);

        printf("Password : ");
        scanf("%s", password);

        if (cekLogin(username, password)) {
            printf("\n[✓] Login berhasil! Welcoomee !, %s.\n", username);
            break;
        } else {
            printf("\n[!] Username atau password kamu salah :( \n");
        }

        printf("\n");
    }
}

void menuUser() {
    int pilihan;

    printf("===============================================================\n");
    printf("                      ˚୨୧⋆｡˚ MAIN MENU ˚୨୧⋆｡˚\n");
    printf("===============================================================\n\n");

    printf("✦ 1. Lihat Daftar Konser\n");
    printf("✦ 2. Cari Konser\n");
    printf("✦ 3. Urutkan Konser (Sorting)\n");
    printf("✦ 4. Pesan Tiket\n");
    printf("✦ 5. Lihat Tiket Saya\n");
    printf("✦ 6. Logout\n\n");

    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("\n>> Menampilkan daftar konser...\n\n");
            break;
        case 2:
            printf("\n>> Fitur cari konser belum dibuat.\n\n");
            break;
        case 3:
            printf("\n>> Fitur sorting konser belum dibuat.\n\n");
            break;
        case 4:
            printf("\n>> Fitur pesan tiket belum dibuat.\n\n");
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

struct Konser {
    int id;
    char nama[50];
    char lokasi[30];
    char tanggal[15];
    int harga;
};

void lihatDaftarKonser() {
    struct Konser ksr[3];

    ksr[0].id = 1;
    strcpy(ksr[0].nama, "Love in Harmony");
    strcpy(ksr[0].lokasi, "Jakarta");
    strcpy(ksr[0].tanggal, "12-05-2025");
    ksr[0].harga = 350000;

    ksr[1].id = 2;
    strcpy(ksr[1].nama, "Rock The Night");
    strcpy(ksr[1].lokasi, "Bandung");
    strcpy(ksr[1].tanggal, "20-06-2025");
    ksr[1].harga = 280000;

    ksr[2].id = 3;
    strcpy(ksr[2].nama, "Symphony Dream");
    strcpy(ksr[2].lokasi, "Surabaya");
    strcpy(ksr[2].tanggal, "05-07-2025");
    ksr[2].harga = 500000;

    printf("===============================================================\n");
    printf("                          DAFTAR KONSER ──★ ˙🍓 ̟ !!\n");
    printf("===============================================================\n");
    printf(" ID   | Nama Konser           | Lokasi           | Tanggal     | Harga\n");
    printf("---------------------------------------------------------------------------\n");

    int jumlahKonser = 3;
    for (int i = 0; i < jumlahKonser; i++) {
        printf(" %-4d | %-20s | %-15s | %-11s | %d\n", 
               ksr[i].id, ksr[i].nama, ksr[i].lokasi, ksr[i].tanggal, ksr[i].harga);
    }
}

void detailKonser() {

    printf("===============================================================\n");
    printf("                    ˚｡⋆୨୧˚ DETAIL KONSER ˚｡⋆୨୧˚\n");
    printf("===============================================================\n\n");

    printf("ID Konser      : \n");
    printf("Nama           : \n");
    printf("Lokasi         : \n");
    printf("Tanggal        : \n");
    printf("Harga          : \n\n");

    printf("Deskripsi Konser      :\n\n");

    printf("1. Pesan Tiket\n");
    printf("2. Kembali\n\n");

    printf("Pilih menu: ");

}

void tampilanKursi() {

    printf("===============================================================\n");
    printf("                        ╰┈➤ PILIH KURSI\n");
    printf("===============================================================\n\n");

    printf("Status: [O] = Kosong     [X] = Terisi\n\n");

    printf("            PANGGUNG\n");
    printf("-----------------------------------\n");

    printf("  A  [O][O][X][O][O][O][X][O][O][O]\n");
    printf("  B  [O][X][X][O][O][O][O][O][O][O]\n");
    printf("  C  [O][O][O][O][X][O][O][X][O][O]\n\n");

    printf("Pilih Baris (A/B/C): ");
    
    char baris;
    scanf(" %c", &baris);

    printf("Pilih Nomor Kursi Yang Kamu Mau (1-10): ");
    
    int nomor;
    scanf("%d", &nomor);

    printf("\n[✓] Kursi berhasil dipesan!\n\n");
}

void formPemesananTiket() {

    char baris;
    int nomor;

    printf("===============================================================\n");
    printf("                     ⋆☕︎ ˖ FORM PEMESANAN TIKET\n");
    printf("===============================================================\n\n");

    printf("Nama Konser : Rock The Night\n");
    printf("Harga       : 280000\n\n");

    printf("Masukkan Baris Kursi (A/B/C): ");
    scanf(" %c", &baris);

    printf("Masukkan Nomor Kursi        : ");
    scanf("%d", &nomor);

    printf("\nPemesanan berhasil!\n");
    printf("ID Tiket Kamu: TK-00281\n\n");

    scanf("%*c");  
    scanf("%*c");  
}

void tampilanTiketSaya() {

    printf("===============================================================\n");
    printf("                         ✉ TIKET SAYA ✉\n");
    printf("===============================================================\n\n");

    printf("No | Nama Konser         | Kursi | Tanggal     | Harga\n");
    printf("---------------------------------------------------------------\n");
    printf("1  | Rock The Night      | B-4   | 20-06-2025  | 280000\n");
    printf("2  | Love in Harmony     | A-2   | 12-05-2025  | 350000\n\n");

    printf("Tekan ENTER untuk kembali...");

    scanf("%*c");  
    scanf("%*c");  
}

void tampilanSearchKonser() {

    char keyword[50];

    printf("===============================================================\n");
    printf("                         ↪ CARI KONSER\n");
    printf("===============================================================\n\n");

    printf("Masukkan nama konser yang kamu cari: ");
    scanf(" %[^\n]", keyword);

    printf("\nHasil Pencarian kamu:\n");
    printf("---------------------------------------------------------------\n");
    printf("1. Love in Harmony\n");
    printf("   Lokasi : Jakarta\n");
    printf("   Harga  : 350000\n");
    printf("---------------------------------------------------------------\n\n");

    printf("Tekan ENTER untuk kembali...");

    scanf("%*c");  
    scanf("%*c"); 
}

void tampilanSortingKonser() {

    printf("===============================================================\n");
    printf("                  ₊˚⊹♡ SORTING DAFTAR KONSER ₊˚⊹♡\n");
    printf("===============================================================\n\n");

    printf("Urutkan berdasarkan:\n");
    printf("1. Harga Termurah → Termahal\n");
    printf("2. Harga Termahal → Termurah\n");
    printf("3. Tanggal Terdekat\n");
    printf("4. Nama (A-Z)\n\n");

    printf("Pilih: ");
    int pilihan;
    scanf("%d", &pilihan);

    printf("\nPilihan kamu: %d\n", pilihan);

    printf("\nTekan ENTER untuk kembali...");
    scanf("%*c");  
    scanf("%*c");  
}

void tampilanLogout() {

    printf("\n===============================================================\n");
    printf("                      -ˋˏ✄┈┈┈┈  LOGOUT\n");
    printf("===============================================================\n\n");

    printf("Kamu sudah logout ~~\n");
    printf("Thank you sudah menggunakan sistem kami!\n\n");

    printf("Tekan ENTER untuk keluar...");
    scanf("%*c");  
    scanf("%*c"); 
}




