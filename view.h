#ifndef OPERASI_H
#define OPERASI_H

struct Akun
{
    char username[50];
    char password[50];
};

extern struct Akun daftarAkun[100];
extern int jumlahAkun;

struct Konser
{
    int id;
    char nama[50];
    char lokasi[30];
    char tanggal[15];
    int harga;
    char deskripsi[200];
};

extern struct Konser konserList[3];

void main_menu();
void konser();
void tampilMenuAwal();
void tampilanRegister();
void tampilanLogin();
void menuUser();
void lihatDaftarKonser();
void detailKonser();
void tampilanKursi();
void formPemesananTiket(char namaKonser[], int hargaKonser);


// utils.c
void countdownClear(int count);

#endif