#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Akun daftarAkun[100] = {
    {
        "admin",
        "admin123",
        "admin",
    },
    {"novan", "123"}};
int jumlahAkun = 2;

int jumlahKonser = 3;

struct Konser konserList[100] = {
    {1, "Love in Harmony", "Jakarta", "12-05-2025", 350000,
     "Konser romantis penuh nuansa cinta dengan musisi papan atas."},
    {2, "Rock The Night", "Bandung", "20-06-2025", 280000,
     "Konser rock terbesar tahun ini dengan penampilan band-band ternama."},
    {3, "Symphony Dream", "Surabaya", "05-07-2025", 500000,
     "Pertunjukan orkestra megah dengan kualitas internasional."}};

struct Tiket tiketSaya[100]; 
int jumlahTiket = 0;


