#include <stdio.h>
#include <stdbool.h>
#define antrian_h

typedef struct antrian_cuci *address;
struct antrian_cuci
{
    int waktu_in;
    int waktu_proses;
    int waktu_out;
    address next;
};
struct mobil
{
    char nopol[15];
    int jenis_kendaraan;
    
};


int TipeKendaraan(){
    int jenis_kendaraan;
    bool Lagi = false;

    while(!Lagi){
        printf("\tTipe Kendaraan\n");
        printf("1. Minibus\n");
        printf("2. SUV\n");
        printf("3. Truk/Bus\n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%d",&jenis_kendaraan);

        if(jenis_kendaraan>3 || jenis_kendaraan<1){
            printf("Invalid, input tidak sesuai\n\n");
            Lagi = false;
        }
        else{
            Lagi = true;
            return jenis_kendaraan;
        }
    }
}

void input_kendaraan(){
    char no_plat[15];
    int Tipe;

    printf("masukan nomor kendaraan : ");
    scanf(" %[^\n]", &no_plat);

    Tipe = TipeKendaraan();
}