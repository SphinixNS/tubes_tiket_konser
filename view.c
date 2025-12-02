#include "view.h"
#include <stdio.h>
#include <string.h>

struct Akun {
    char username[50];
    char password[50];
};

struct Akun daftarAkun[100];  
int jumlahAkun = 0;

struct Konser {
    int id;
    char nama[50];
    char lokasi[30];
    char tanggal[15];
    int harga;
    char deskripsi[200];
};

struct Konser konserList[3] = {
    {1, "Love in Harmony", "Jakarta", "12-05-2025", 350000,
     "Konser romantis penuh nuansa cinta dengan musisi papan atas."}, {2, "Rock The Night", "Bandung", "20-06-2025", 280000,
     "Konser rock terbesar tahun ini dengan penampilan band-band ternama."}, {3, "Symphony Dream", "Surabaya", "05-07-2025", 500000,
     "Pertunjukan orkestra megah dengan kualitas internasional."}
};

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
        printf("                           LOGIN\n");
        printf("===============================================================\n\n");

        printf("Username : ");
        scanf(" %[^\n]", username);

        printf("Password : ");
        scanf("%s", password);

        if (cekLogin(username, password)) {
            printf("\nLogin berhasil! Welcome, %s.\n", username);
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

    switch (pilihan) {
        case 1:
            lihatDaftarKonser();
            break;
        case 2:
            printf("\n>> Fitur cari konser belum dibuat.\n\n");
            break;
        case 3:
            printf("\n>> Fitur sorting konser belum dibuat.\n\n");
            break;
        case 4:
            detailKonser();
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

void lihatDaftarKonser() {
    printf("===============================================================\n");
    printf("                          DAFTAR KONSER\n");
    printf("===============================================================\n");
    printf(" ID   | Nama Konser           | Lokasi           | Tanggal     | Harga\n");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf(" %-4d | %-20s | %-15s | %-11s | %d\n",
               konserList[i].id, konserList[i].nama, konserList[i].lokasi, konserList[i].tanggal, konserList[i].harga);
    }

    printf("\nTekan ENTER untuk kembali...\n");
    getchar();
    getchar(); 

}

void detailKonser() {
    int pilihID;

    printf("\nMasukkan ID konser yang ingin dilihat: ");
    scanf("%d", &pilihID);
    getchar(); 

    int found = -1;
    for (int i = 0; i < 3; i++) {
        if (konserList[i].id == pilihID) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\n[!] ID konser tidak ditemukan!\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        return;
    }

    struct Konser k = konserList[found];

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

    if (menu == 1) {
        tampilanKursi(); 
        formPemesananTiket(k.nama, k.harga); 
    }
    else if (menu == 2) {
        return; 
    }
    else {
        printf("\n[!] Menu tidak valid!\n");
        printf("Tekan ENTER untuk kembali...\n");
        getchar();
    }
}

void tampilanKursi() {
    char seats[3][10] = {
        {'O','O','X','O','O','O','X','O','O','O'},
        {'O','X','X','O','O','O','O','O','O','O'},
        {'O','O','O','O','X','O','O','X','O','O'}
    };

    printf("===============================================================\n");
    printf("                          PILIH KURSI\n");
    printf("===============================================================\n\n");

    printf("Legenda: [O] = Kosong     [X] = Terisi\n\n");
    printf("           PANGGUNG\n");
    printf("-----------------------------------\n");

    char barisLabel[] = {'A','B','C'};

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
        return;
    }

    printf("Pilih Nomor Kursi (1-10): ");
    scanf("%d", &pilihKursi);

    if (pilihKursi < 1 || pilihKursi > 10) {
        printf("[!] Nomor kursi tidak valid!\n");
        return;
    }

    int idxKursi = pilihKursi - 1;

    if (seats[idxBaris][idxKursi] == 'X') {
        printf("[!] Kursi sudah terisi!\n");
    } else {
        seats[idxBaris][idxKursi] = 'X';
        printf("\n[✓] Kursi %c%d berhasil dipilih!\n", barisLabel[idxBaris], pilihKursi);
    }

    printf("Tekan ENTER untuk kembali...\n");
    getchar();
}

void formPemesananTiket(char namaKonser[], int hargaKonser) {
    printf("\n===============================================================\n");
    printf("                      FORM PEMESANAN TIKET\n");
    printf("===============================================================\n\n");

    printf("Nama Konser : %s\n", namaKonser);
    printf("Harga       : %d\n\n", hargaKonser);

    printf("[✓] Pemesanan berhasil!\n");

    printf("\nTekan ENTER untuk kembali ke menu utama...");
    getchar();
}
