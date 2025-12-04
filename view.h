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

extern struct Akun daftarAkun[100];
extern int jumlahAkun;

extern struct Konser konserList[100];
extern int jumlahKonser;


void main_menu();
//menu user
void konser();
void tampilMenuAwal();
void tampilanRegister();
void tampilanLogin();
void menuUser();
void lihatDaftarKonser();
void detailKonser();
void tampilanKursi();
void formPemesananTiket(char namaKonser[], int hargaKonser);

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