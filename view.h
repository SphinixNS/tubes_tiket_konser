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
    int hargaVIP;
    int hargaReguler;
    int jumlahTiketVIP;
    int jumlahTiketReguler;
    char deskripsi[500];
};

struct Tiket
{
    int idKonser;
    char namaPembeli[50];
    char namaKonser[50];
    char jenisTiket[20];
    int jumlah;
    int totalHarga;
    char tanggal[15];
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
void formPemesananTiket(int idKonser);
void lihatTiketSaya();
void searchConcert();
void sortingKonser();
void detailTiket(int idTiket);



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