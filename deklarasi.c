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
    {"novan", "123", "user"}};
int jumlahAkun = 2;

int jumlahKonser = 20;

struct Konser konserList[100] = {
    {1, "Love in Harmony", "Jakarta", "12-05-2025", 630000, 350000, 200, 1200,
     "Konser romantis penuh nuansa cinta dengan musisi papan atas."},
    {2, "Rock The Night", "Bandung", "20-06-2025", 504000, 280000, 150, 1500,
     "Konser rock terbesar tahun ini dengan penampilan band-band ternama."},
    {3, "Symphony Dream", "Surabaya", "05-07-2025", 900000, 500000, 250, 1000,
     "Pertunjukan orkestra megah dengan kualitas internasional."},
    {4, "Jazz Night Delight", "Yogyakarta", "10-10-2025", 540000, 300000, 180, 800,
     "Malam penuh nuansa jazz yang akan membawa Anda ke dunia musik yang mendalam dan penuh emosi. Konser ini menampilkan musisi jazz lokal dan internasional yang telah berpengalaman di panggung dunia. Setiap penampilan diiringi dengan improvisasi yang membuat setiap lagu terasa unik dan segar."},
    {5, "Indie Vibes", "Medan", "15-10-2025", 360000, 200000, 120, 600,
     "Konser indie yang membawa suasana intim dan artistik, dengan musik yang penuh ekspresi dan kreatifitas. Anda akan dimanjakan dengan penampilan band indie lokal yang semakin digemari, serta beberapa musisi yang telah mendapatkan pengakuan internasional. Suasana yang hangat dan penuh kedekatan dengan penggemar menjadi ciri khas acara ini."},
    {6, "Punk Revolution", "Jakarta", "25-10-2025", 450000, 250000, 150, 900,
     "Konser punk yang menghadirkan energi tinggi dan semangat revolusi yang membara. Dengan penampilan band-band punk legendaris, acara ini adalah pesta musik bagi para penggemar budaya pemberontakan. Rasakan kegaduhan dan semangat muda yang tak terbendung!"},
    {7, "Classic Elegance", "Bali", "02-11-2025", 810000, 450000, 220, 1000,
     "Malam penuh keanggunan dengan musik klasik yang dimainkan oleh orkestra terkenal. Pertunjukan ini akan membawa Anda ke dunia yang penuh keindahan dan harmoni, dengan penampilan maestro musik klasik yang telah berpengalaman di panggung internasional. Nikmati kehalusan dan kedalaman setiap komposisi musik."},
    {8, "EDM Fantasia", "Bandung", "08-11-2025", 540000, 300000, 300, 2000,
     "Festival musik EDM terbesar yang menghadirkan DJ top dunia dengan permainan cahaya spektakuler. DJ-DJ ternama akan memanaskan suasana dan membuat Anda bergerak mengikuti alunan musik yang menghentak. Persiapkan diri Anda untuk sebuah pengalaman yang penuh energi dan euforia."},
    {9, "Pop Sensation", "Surabaya", "12-11-2025", 630000, 350000, 250, 1500,
     "Konser pop spektakuler dengan artis-artis papan atas Indonesia yang siap menghibur Anda. Dengan suasana yang meriah dan penuh keceriaan, konser ini menjadi ajang berkumpulnya penggemar pop dari berbagai penjuru. Dapatkan pengalaman musik yang berkelas dan penuh warna!"},
    {10, "Reggae Roots", "Makassar", "20-11-2025", 396000, 220000, 120, 700,
     "Konser reggae yang santai namun penuh semangat, membawa Anda ke akar musik reggae yang penuh pesan damai dan cinta. Dengan irama yang menenangkan dan penampilan musisi reggae ternama, acara ini cocok untuk mereka yang mencari ketenangan dan kebebasan dalam musik."},
    {11, "R&B Experience", "Medan", "27-11-2025", 504000, 280000, 180, 1000,
     "Rasakan sensasi musik R&B yang memukau, dengan penampilan penyanyi-penyanyi lokal dan internasional yang memiliki suara khas. Nikmati perpaduan antara melodi yang lembut dan beat yang mengalir, yang membuat Anda tak bisa berhenti bergoyang. Acara ini menjadi pengalaman musik yang penuh perasaan dan gaya."},
    {12, "Metal Storm", "Bandung", "05-12-2025", 594000, 330000, 200, 1200,
     "Bergabunglah dalam konser metal terbesar tahun ini dengan band-band rock legendaris yang siap mengguncang panggung. Dapatkan pengalaman dengan musik yang keras dan penuh adrenalin, serta panggung yang penuh dengan visual yang memukau. Ini adalah acara yang wajib dihadiri bagi para penggemar musik metal sejati."},
    {13, "Folk Tales", "Yogyakarta", "15-12-2025", 450000, 250000, 150, 800,
     "Konser folk yang membawa Anda menikmati lagu-lagu dengan lirik penuh makna dan cerita yang mendalam. Nikmati penampilan musisi folk yang berbakat, dengan nuansa yang intimate dan penuh kehangatan. Ini adalah malam yang menyentuh jiwa dan mengajak kita untuk mengenang kembali kisah-kisah lama."},
    {14, "Dance Pop Explosion", "Bali", "20-12-2025", 666000, 370000, 220, 1500,
     "Bersiaplah untuk pesta musik pop yang penuh energi dan kegembiraan. Dengan penampilan artis-artis pop terkenal yang siap membuat Anda menari sepanjang malam, konser ini adalah pilihan tepat untuk menikmati malam yang tak terlupakan. Musik yang upbeat dan suasana yang penuh kegembiraan menjadi daya tarik utama acara ini."},
    {15, "Piano Serenade", "Jakarta", "25-12-2025", 720000, 400000, 180, 900,
     "Nikmati malam penuh keindahan dengan konser piano solo yang dimainkan oleh pianis-pianis terkenal. Setiap nada yang dimainkan membawa emosi dan memikat hati, menciptakan atmosfer yang tenang namun mendalam. Ini adalah kesempatan untuk merasakan kekuatan musik klasik dalam kesunyian malam."},
    {16, "Hip-Hop Revolution", "Surabaya", "10-01-2026", 576000, 320000, 200, 1200,
     "Konser hip-hop dengan penampilan artis-artis rap legendaris dan battle yang seru. Aliran musik yang penuh dengan pesan sosial dan revolusi ini membawa energi yang tak bisa dihentikan. Bersiaplah untuk merasakan semangat dan keberanian dalam setiap kata yang dilantunkan."},
    {17, "Electronic Pulse", "Makassar", "15-02-2026", 558000, 310000, 250, 1500,
     "Festival musik elektronik dengan DJ-DJ top dunia yang akan membuat Anda terhanyut dalam ritme dan cahaya. Nikmati pengalaman musik yang menggetarkan tubuh dan membangkitkan semangat. Konser ini adalah untuk mereka yang suka dengan keseruan dan euforia musik elektronik."},
    {18, "Symphonic Rock", "Bandung", "05-03-2026", 810000, 450000, 220, 1000,
     "Paduan antara musik rock dan orkestra akan membawa Anda pada pengalaman mendalam yang luar biasa. Dengan penampilan band rock terkenal yang ditemani orkestra megah, konser ini menawarkan sebuah nuansa baru yang menggabungkan kekuatan gitar dengan keindahan simfoni."},
    {19, "Country Roads", "Yogyakarta", "12-04-2026", 504000, 280000, 150, 900,
     "Konser country yang membawa Anda pada perjalanan melintasi pedesaan Amerika dengan lagu-lagu penuh cerita. Dapatkan pengalaman musik country yang autentik dengan musisi-musisi terbaik. Ini adalah kesempatan untuk menikmati musik yang penuh dengan kehangatan dan kesederhanaan."},
    {20, "Soulful Evenings", "Medan", "20-04-2026", 576000, 320000, 180, 800,
     "Malam penuh musik soul yang menyentuh hati dengan penampilan penyanyi-penyanyi berbakat. Rasakan keindahan vokal yang penuh emosi dan lirik yang mendalam, menciptakan suasana yang intim dan penuh perasaan. Konser ini adalah untuk mereka yang mencari kedalaman dalam musik."}


};
struct Tiket tiketSaya[100];
int jumlahTiket = 0;
