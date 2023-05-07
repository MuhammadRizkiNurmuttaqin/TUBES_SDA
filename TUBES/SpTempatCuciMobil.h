//ini header
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <ctype.h>

// Deklarasi Data

typedef struct mobil *almtmobil;
typedef struct mobil{
	char platNomor[15];
	char jenisMobil;
	int waktuMasuk;
	int waktuKeluar; 
	int lamaProses; // Menunjukkan berapa lama mobil ini akan dicuci
	int waktuProses; // Menunjukkan kapan mobil tersebut akan dicuci
	almtmobil nextm;
} Mobil;

typedef struct tempatcuci *almttempatcuci;
typedef struct tempatcuci{
	char nama;
	almtmobil lastCar;
    almtmobil nextt;
} TempatCuci;


int waktuSekarang = 420;

// Deklarasi Modul
void CreateMobil(almtmobil *temp);
/*Deskripsi Modul
Prosedure
Untuk Membuat/mengalokasi mobil baru yang akan diproses
I.S : Mobil blm teralokasi
F.S : Mobil sudah ada dengan properti null/-/0
=========================================================================================*/

void inputMobil (almtmobil temp, almttempatcuci tc1, almttempatcuci tc2);
/*Deskripsi Modul
Prosedure
Memasukkan properti mobil berupa Plat Nomor dan Waktu Masuknya
I.S : Plat Nomor dan Waktu Masuk Mobil masih kosong
F.S : Plat Nomor dan waktu Masuk Mobil sudah diisi
=========================================================================================*/

int InputJenisKendaraan(almtmobil temp, almttempatcuci tc1, almttempatcuci tc2);
/*Deskripsi Modul
Function
Memasukkan properti mobil berupa jenis mobil
I.S : Jenis Mobil belum diketahui
F.S : nilai jenis mobil dikembalikan dan lama proses cuci sudah diketahui
=========================================================================================*/

void CreateAntrian(almttempatcuci *T, char name);
/*Deskripsi Modul
Prosedure
Untuk Membuat dan Mengalokasikan Sebuah tempat cuci Mobil
I.S : Tempat Cuci Mobil belum dialokasi
F.S : Tempat Cuci Mobil sudah dialokasi dengan properi pointer NULL
=========================================================================================*/

int AntrianIsEmpty(almttempatcuci T);
/*Deskripsi Modul
Function
Untuk mengetahui apakah tempat cuci mobil ada isinya atau kosong
I.S : Tempat Cuci Mobil belum diketahui isinya
F.S : Tempat Cuci mobil sudah diketahui apakah ada mobilnya atau tidak
=========================================================================================*/

void PrintJam(int time);
/*Deskripsi Modul
Prosedure
Untuk menampilkan waktu dalam bentuk jj:mm:dd
I.S : Jam masih dalam bentuk menit
F.S : Jam tampil dalam format jj:mm:dd
=========================================================================================*/

void MengantrikanMobil(almttempatcuci tc1, almttempatcuci tc2, almtmobil car);
/*Deskripsi Modul
Prosedure
Untuk mengantrikan mobil kedalam tempat cucian yang kosong atau yang paling cepat selesai
I.S : Mobil belum masuk antrian
F.S : Mobil masuk kedalam antrian bila tidak mendekati waktu istirahat atau tutup
=========================================================================================*/

void TampilAntrian (almttempatcuci tc);
/*Deskripsi Modul
Prosedure
Untuk mengetahui apakah tempat cuci mobil ada isinya atau kosong
I.S : Tempat Cuci Mobil belum diketahui isinya
F.S : Tempat Cuci mobil sudah diketahui apakah ada mobilnya atau tidak
=========================================================================================*/

int SkipWaktu(almttempatcuci tc1, almttempatcuci tc2, int pilihan);
/*Deskripsi Modul
Function
Untuk skip/memajukan waktu dalam beberapa satuan
I.S : Waktu tetap atau belum bertambah
F.S : Waktu berubah sesuai dengan inputan
=========================================================================================*/

void PrintWaktuSekarang();
/*Deskripsi Modul
Prosedure
Untuk menampilkan waktu utama
I.S : Waktu utama (waktuSekarang) belum tampil pada layar
F.S : Waktu utama (waktuSekarang) sudah tampil pada layar
=========================================================================================*/

void RemoveMobil(almttempatcuci tc1, almttempatcuci tc2);
/*Deskripsi Modul
Prosedure
Untuk mengeluarkan mobil dalam antrian
I.S : Antrian mobil sudah ada
F.S : Salah satu mobil didalam antrian dikeluarkan
=========================================================================================*/

int stringcompare(char *a,char *b);
/*Deskripsi Modul
Function
Untuk membandingkan nilai string
I.S : Terdapat dua string
F.S : Nilai string diketahui pernbandingannya (sama/berbeda)
=========================================================================================*/

void AfterSkip(almttempatcuci tc1, almttempatcuci tc2);
/*Deskripsi Modul
Prosedure
Untuk memanggil modul modul yang akan berubah ketika waktu di skip
I.S : Waktu sudah diskip
F.S : Beberapa variabel didalam modul modul yang dipanggil berubah waktunya
=========================================================================================*/

void UpdateWaktuCuci(almttempatcuci tc1);
/*Deskripsi Modul
Prosedure
Modul ini berfungsi untuk mengganti sisa waktu cuci(lamaProses) ketika waktu di skip
I.S : lama proses tetap
F.S : Lama proses berubah apabila waktu sudah melewati Waktu Cuci
=========================================================================================*/

void MenuUtama(almttempatcuci tc1, almttempatcuci tc2);
/*Deskripsi Modul
Prosedure
Untuk Menampilkan Menu Utama dan memilih proses yang mau dijalankan
I.S : Menu Utama belum tampil di layar
F.S : Menu Utama sudah tampil dan user bisa memilih proses yang akan dilakukan
=========================================================================================*/

void MenuAwal(almttempatcuci tc1, almttempatcuci tc2);
/*Deskripsi Modul
Prosedure
Untuk Menampilkan Menu Awal dan memulai program
I.S : Menu Utama Awal tampil di layar
F.S : Menu Utama sudah tampil dan user bisa memulai atau menghentikan program
=========================================================================================*/

void MenuManual();
/*Deskripsi Modul
Prosedure
Untuk Menampilkan Manual Aplikasi
I.S : Manual Aplikasi belum tampil
F.S : Manual Aplikasi sudah tampil
=========================================================================================*/