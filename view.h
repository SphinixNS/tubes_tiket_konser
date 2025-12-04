#ifndef OPERASI_H
#define OPERASI_H

struct Akun
{
    char username[50];
    char password[50];
    char role[10];
};

struct Konser
{
    int id;
    char nama[100];
    char lokasi[50];
    char tanggal[15];
    int harga;
    char deskripsi[200];
};

struct Tiket
{
    char namaKonser[50];
    char kursi[5];
    char tanggal[20];
    int harga;
};

extern struct Akun daftarAkun[100];
extern int jumlahAkun;

extern struct Konser konserList[100];
extern int jumlahKonser;

extern struct Tiket tiketSaya[100];
extern int jumlahTiket;



void main_menu();
//menu user
void konser();
void tampilMenuAwal();
void tampilanRegister();
void tampilanLogin();
void menuUser();
void lihatDaftarKonser();
void detailKonser(int idKonser);
void tampilanKursi(char kursiTerpilih[]);
void formPemesananTiket(char namaKonser[], int hargaKonser, char kursi[], char tanggal[]);
void lihatTiketSaya();
void searchConcert();
void sortingKonser();



//menu admin
void menuAdmin();
void daftarKonserAdmin();
void detailKonserAdmin(int idKonser);
void tambahKonser();
void editKonser();
void hapusKonser();



// utils.c
void countdownClear(int count);

#endif