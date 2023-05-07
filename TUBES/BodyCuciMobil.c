#include "SpTempatCuciMobil.h"

void MenuUtama(almttempatcuci tc1, almttempatcuci tc2){
	if (waktuSekarang <1020){
	system("cls");
	system("COLOR E0");
	char input[5];
	almtmobil car;
	int pilihan;
	printf(" _____________________________________________________________________________________   \n");
	printf("\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
    printf("\xb3x                                                                                   x\xb3\n");
	printf("\xb3x              XXX     XXX    XX   XXXXXX   XXXXXX   XXXXXX   XXXXXX                x\xb3\n");
	printf("\xb3x              XX X   X XX    XX   XX         XX     XX       XX   XX               x\xb3\n");
	printf("\xb3x              XX  X X  XX    XX   XXXXXX     XX     XXXXXX   XXXXXX                x\xb3\n");
	printf("\xb3x              XX   X   XX    XX       XX     XX     XX       XX   XX               x\xb3\n");
	printf("\xB3x              XX       XX    XX   XXXXXX     XX     XXXXXX   XX    XX              x\xb3\n");
    printf("\xB3x                                                                                   x\xb3\n");
    printf("\xB3x                                      DOORSMEER                                    x\xb3\n");
	printf("\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
    printf("\xb3_____________________________________________________________________________________\xb3\n\n\n");
	PrintWaktuSekarang();
	printf("\n");
	printf("\n1. Input Mobil");
	printf("\n2. Keluarkan Mobil Dari Antrian");
	printf("\n3. Skip 1 Menit");
	printf("\n4. Skip 2 Menit");
	printf("\n5. Skip 5 Menit");
	printf("\n6. Skip 15 Menit");
	printf("\n7. Skip 30 Menit");
	printf("\n8. Tampil Antrian");
	printf("\n9. Exit");
	printf("\n\nMasukkan Pilihan (1-9) : ");
	scanf(" %c", &input);
	for (int i = 0; input[i]; i++){
			if(!isdigit(input[i])){
				printf("Pilih berdasarkan angka, bukan menggunakan huruf!\n");
				system ("pause");
				MenuUtama(tc1, tc2);
			}
		}
	pilihan = atoi(input);
	//scanf("%d", &pilihan);
	switch(pilihan){
		case 1:	CreateMobil(&car);
				system("cls");
				inputMobil(car, tc1, tc2);
				MengantrikanMobil(tc1, tc2, car);
				printf("\n\nMobil Berhasil Dinputkan\n\n");
				system("pause");
				car = NULL;
				free(car);
				MenuUtama(tc1, tc2);
				break;
		case 2: system("cls");
				TampilAntrian (tc1);
				printf("\n\n");
				TampilAntrian (tc2);
				RemoveMobil(tc1, tc2);
				MenuUtama(tc1, tc2);
				break;
		case 3: SkipWaktu(tc1, tc2, pilihan);
				MenuUtama(tc1, tc2);
				break;
		case 4: SkipWaktu(tc1, tc2, pilihan);
				MenuUtama(tc1, tc2);
				break;
		case 5: SkipWaktu(tc1, tc2, pilihan);
				MenuUtama(tc1, tc2);
				break;
		case 6: SkipWaktu(tc1, tc2, pilihan);
				MenuUtama(tc1, tc2);
				break;
		case 7: SkipWaktu(tc1, tc2, pilihan);
				MenuUtama(tc1, tc2);
				break;
		case 8: system("cls");
				TampilAntrian (tc1);
				printf("\n\n");
				TampilAntrian (tc2);
				printf("\n\n");
				system("pause");
				MenuUtama(tc1, tc2);
				break;
		case 9: exit(0);
				break;
		default: printf("Pilihan yang anda Masukkan salah, Harap coba lagi!");
				 printf("\n\n");
				 system("pause");
				 MenuUtama(tc1, tc2);
		}
	} else {
		system("cls");
		printf("Tempat Cuci Sudah Tutup...\n");
		system("Pause");
		exit(1);
	}
}

void CreateMobil(almtmobil *temp){
	Mobil *car;
	car = (Mobil *) malloc(sizeof(Mobil));
	car->jenisMobil = '-';
	car->nextm = NULL;
	car->waktuKeluar = 0;
	car->waktuMasuk = 0;
	car->lamaProses = 0;
	car->waktuProses = 0;
	*temp = car;
}

void CreateAntrian(almttempatcuci *T, char name){
	TempatCuci *tc;
	tc = (TempatCuci *) malloc(sizeof(TempatCuci));
	tc->nama = name;
	tc->lastCar = NULL;
	tc->nextt = NULL;
	*T = tc;
}

void inputMobil(almtmobil temp, almttempatcuci tc1, almttempatcuci tc2){
	int jenisMobil;
	system("COLOR E0");
	jenisMobil = InputJenisKendaraan(temp, tc1, tc2);
	
	if((waktuSekarang + temp->lamaProses > 720) && (waktuSekarang < 720) ){ 
		printf("Waktu istirahat akan segera tiba, coba lagi pada pukul 13.00\n");
		system ("pause");
		MenuUtama(tc1, tc2);
	}
	
	if((waktuSekarang >= 720) && (waktuSekarang < 780) ){ 
		printf("Sedang jam istirahat, coba lagi pukul 13.00\n");
		system ("pause");
		MenuUtama(tc1, tc2);
	}
	
	if((waktuSekarang + temp->lamaProses > 1020) && (waktuSekarang < 1020) ){   
		printf("Mohon maaf, waktu tutup akan segera tiba. Kembali lagi besok\n");
		system ("pause");
		MenuUtama(tc1, tc2);
	}
	temp->waktuMasuk = waktuSekarang;
	printf("Waktu Masuk : ");	
	PrintJam(temp->waktuMasuk);
	printf("\nMasukkan Plat Nomor : ");
	scanf(" %[^\n]", temp->platNomor);
}

int InputJenisKendaraan(almtmobil temp, almttempatcuci tc1, almttempatcuci tc2){
	char input[5];
	int pilihan;
	system("COLOR E0");
	do{
		start:
		system("cls");
		printf(" ____________________________________________________________________________________________\n");
		printf("\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
		printf("\xb3x                                     JENIS KENDARAAN                                      x\xb3\n");
		printf("\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
		printf("\xb3x NO x JENIS x KETERANGAN  x                            CONTOH                  x  DURASI  x\xb3\n");
		printf("\xb3x 1. x   A   x Mobil Kecil x KIA Picanto, Suzuki Karimun, Toyota Yaris dll      x 30 menit x\xb3\n");
		printf("\xb3x 2. x   B   x Minibus     x Toyota Avanza, Honda Freed, Suzuki Ertiga, dll     x 45 menit x\xb3\n");
		printf("\xb3x 3. x   C   x Mobil Besar x Metromini, Truk, dll                               x 75 menit x\xb3\n");
		printf("\xb3x 0. Untuk Kembali                                                                         x\xb3\n");
		printf("\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
		printf("\xb3____________________________________________________________________________________________\xb3\n\n");
		printf("Pilih Jenis Kendaraan 1/2/3 : ");
		scanf(" %c", &input);
		
		//Cek apakah ada inputan berupa character
		//Disini juga ada perbedaan
		for (int i = 0; input[i]; i++){
			if(!isdigit(input[i])){
				printf("Pilih jenis kendaraan dengan menginputkan 1/2/3! bukan menggunakan huruf!\n");
				system ("pause");
				system ("cls");
				goto start;
			}
		}
		
		//Merubah inputan menjadi integer
		pilihan = atoi(input);
		
		if((pilihan < 0) || (pilihan > 3)){ 
			printf("Pilih jenis kendaraan dengan menginputkan 1-3!\n");
			system("pause");
		}
	}while((pilihan < 0) || (pilihan > 3));
	
	switch(pilihan){ //perbedaannya ada disini
		case 1 : temp->lamaProses = 30;
				 temp->jenisMobil = 'A';
				 break;
		case 2 : temp->lamaProses = 45;
				 temp->jenisMobil = 'B';
				 break;
		case 3 : temp->lamaProses = 75;
				 temp->jenisMobil = 'C';
				 break;	
		case 0 : MenuUtama(tc1,tc2);	 
	}
	return pilihan;
}

int AntrianIsEmpty(almttempatcuci T){
	if (T->nextt == NULL){
		return 1;
	} else {
		return 0;
	}
}

void PrintJam(int time){
	system("COLOR E0");
	int j,m;
	j = time/60;
	m = time%60;
	if ((j>=10) && (m>=10)){
		printf("%d:%d:00", j,m);
	}
	if ((j<=9) && (m>=10)){
		printf("0%d:%d:00", j,m);
	}
	if ((j>=10) && (m<=9)){
		printf("%d:0%d:00", j,m);
	}
	if ((j<=9) && (m<=9)){
		printf("0%d:0%d:00", j,m);
	}
}

void MengantrikanMobil(almttempatcuci tc1, almttempatcuci tc2, almtmobil car){
	system("COLOR E0");
	int temp1, temp2;
	temp1 = AntrianIsEmpty(tc1);
	if (temp1 == 1){
		car->waktuProses = waktuSekarang;
		car->waktuKeluar = waktuSekarang + car->lamaProses;
		tc1->lastCar = car;
		tc1->nextt = car;
		return;
	}
	
	//Kalau Tempat 2 Kosong
	temp2 = AntrianIsEmpty(tc2);
	if (temp2 == 1){
		car->waktuProses = waktuSekarang;
		car->waktuKeluar = waktuSekarang + car->lamaProses;
		tc2->lastCar = car;
		tc2->nextt = car;
		return;
	}
	
	//Kalau dua duanya ada isinya
	if ((temp1 == 0) && (temp2 == 0)){
		if((tc1->lastCar->waktuKeluar <= tc2->lastCar->waktuKeluar)){
			if ((tc1->lastCar->waktuKeluar + car->lamaProses > 720) && (waktuSekarang < 720)){
				printf("Mohon maaf, waktu istirahat akan segera tiba. Anda dapat kembali pada pukul 13.00.00");
				printf("\n");
				system ("pause");
				MenuUtama(tc1, tc2);
			}
			
			if ((tc1->lastCar->waktuKeluar + car->lamaProses > 1020) && (waktuSekarang < 1020)){
				printf("Mohon maaf, sebentar lagi kami akan tutup. Anda dapat kembali besok.");
				printf("\n");
				system ("pause");
				MenuUtama(tc1, tc2);
			}
			
			car->waktuProses = tc1->lastCar->waktuKeluar;
			car->waktuKeluar = car->waktuProses + car->lamaProses;
			tc1->lastCar->nextm = car;
			tc1->lastCar = car;
			return;
		}
		
		if((tc1->lastCar->waktuKeluar > tc2->lastCar->waktuKeluar)){
			if ((tc2->lastCar->waktuKeluar + car->lamaProses > 720) && (waktuSekarang < 720)){
				printf("Mohon maaf, waktu istirahat akan segera tiba. Anda dapat kembali pada pukul 13.00.00\n");
				system ("pause");
				MenuUtama(tc1, tc2);
			}
			
			if ((tc2->lastCar->waktuKeluar + car->lamaProses > 1020) && (waktuSekarang < 1020)){
				printf("Mohon maaf, sebentar lagi kami akan tutup. Anda dapat kembali besok\n.");
				system ("pause");
				MenuUtama(tc1, tc2);
			}
			
			car->waktuProses = tc2->lastCar->waktuKeluar;
			car->waktuKeluar = car->waktuProses + car->lamaProses;
			tc2->lastCar->nextm = car;
			tc2->lastCar = car;
			return;
		}
	}			
}

void TampilAntrian (almttempatcuci tc){
	int i;
	system("COLOR E0");
	almtmobil car;
	printf("---DOORSMEER %c---", tc->nama);
	if (tc->nextt == NULL){
		printf("\n[Antrian Kosong]\n\n");
	} else {
		printf("\nMobil yang sedang dicuci : %s || Sisa waktu cuci : %d menit, dan selesai pukul : ", tc->nextt->platNomor, tc->nextt->lamaProses);
		PrintJam(tc->nextt->waktuKeluar);
		printf("\n\nMobil Dalam Antrian : ");
		car = tc->nextt;
		if(car->nextm == NULL){
			printf("\nTidak ada Mobil Lagi\n\n");
		}else{
			i = 1;
			while (car->nextm != NULL){
				car = car->nextm;
				printf("\n%d. Mobil dengan Plat Nomor : %s || Mobil selesai dicuci pukul : ", i, car->platNomor);
				PrintJam(car->waktuKeluar);
				i = i + 1;
			}
		}

	}
	
}

void PrintWaktuSekarang(){
	system("COLOR E0");
	printf("Pukul : ");
	PrintJam(waktuSekarang);	
}

int SkipWaktu(almttempatcuci tc1, almttempatcuci tc2, int pilihan){
	switch (pilihan){
		case 3: waktuSekarang = waktuSekarang + 1;
				AfterSkip(tc1, tc2);
				return waktuSekarang;
		case 4: waktuSekarang = waktuSekarang + 2;
				AfterSkip(tc1, tc2);
				return waktuSekarang;
		case 5: waktuSekarang = waktuSekarang + 5;
				AfterSkip(tc1, tc2);
				return waktuSekarang;
		case 6: waktuSekarang = waktuSekarang + 15;
				AfterSkip(tc1, tc2);
				return waktuSekarang;
		case 7: waktuSekarang = waktuSekarang + 30;
				AfterSkip(tc1, tc2);
				return waktuSekarang;
	}
}

void RemoveMobil(almttempatcuci tc1, almttempatcuci tc2){
	int x1, x2;
	system("COLOR E0");
	x1 = AntrianIsEmpty(tc1); 
	x2 = AntrianIsEmpty(tc2);
	almtmobil car, delcar, temp, plus;
	char noPlat1[15];
	int cek, i;
	i = 0;
	if ((x1 == 0) && (x2 == 0)){
		printf("\nTidak Ada Mobil didalam Antrian\n\n");
		system("pause");
		MenuUtama(tc1, tc2);
	}
	if(x1 == 0){
		if(tc1->nextt->nextm != NULL){
			printf("\nMasukkan Plat Nomor mobil yang mau keluar : ");
			scanf(" %[^\n]", noPlat1);
			if (i == 0){
			car = tc1->nextt;
			while (car->nextm != NULL){
				cek = stringcompare(noPlat1, car->nextm->platNomor);
				if (cek == 0){
					temp = car;
					plus = car;
					//Apabila mobil dalam antrian lebih dari 1
					if(car->nextm->nextm != NULL){
						do{
							//Mengganti properti mobil berikutnya beruba waktu proses dan waktu keluarnya
							if(plus->nextm->waktuProses >= plus->nextm->nextm->waktuMasuk){
								plus->nextm->nextm->waktuProses = plus->nextm->waktuProses;
								plus->nextm->nextm->waktuKeluar = plus->nextm->nextm->waktuProses + plus->nextm->nextm->lamaProses;
							} else{
								plus->nextm->nextm->waktuProses = plus->nextm->nextm->waktuMasuk;
								plus->nextm->nextm->waktuKeluar = plus->nextm->nextm->waktuProses + plus->nextm->nextm->lamaProses;
							}
							plus = plus->nextm;
							}while(plus->nextm->nextm != NULL);
						//Menunjuk pointer mobil yang berada didepan mobil yang dihapus ke mobil yang ada dibelakangnya
						car = car->nextm->nextm;
						delcar = temp->nextm;
						temp->nextm = car;
						delcar->nextm = NULL;
						temp = NULL;
						car = NULL;
						free(delcar);
						free(temp);
						free(car);
						i = 1;
						MenuUtama(tc1, tc2);
					}else{
						//Bila mobil dalam antrian hanya satu
						delcar = temp->nextm;
						temp->nextm = NULL;
						car = NULL;
						temp = NULL;
						free(delcar);
						free(car);
						free(temp);
						i = 1;
						MenuUtama(tc1, tc2);
					}
				}
			 car = car->nextm;
			}
		}
	}
}
	//Untuk tempat cuci 2
	if(x2 == 0){
		if(tc2->nextt->nextm != NULL){
			if(i == 0){
			car = tc2->nextt;
			while (car->nextm != NULL){
				cek = stringcompare(noPlat1, car->nextm->platNomor);
				if (cek == 0){
					temp = car;
					plus = car;
					if(car->nextm->nextm != NULL){
						do{
							if(plus->nextm->waktuProses >= plus->nextm->nextm->waktuMasuk){
								plus->nextm->nextm->waktuProses = plus->nextm->waktuProses;
								plus->nextm->nextm->waktuKeluar = plus->nextm->nextm->waktuProses + plus->nextm->nextm->lamaProses;
							} else{
								plus->nextm->nextm->waktuProses = plus->nextm->nextm->waktuMasuk;
								plus->nextm->nextm->waktuKeluar = plus->nextm->nextm->waktuProses + plus->nextm->nextm->lamaProses;
							}
							plus = plus->nextm;
						}while(plus->nextm->nextm != NULL);
						car = car->nextm->nextm;
						delcar = temp->nextm;
						temp->nextm = car;
						delcar->nextm = NULL;
						temp = NULL;
						car = NULL;
						free(delcar);
						free(temp);
						free(car);
						MenuUtama(tc1, tc2);
					}else{
						delcar = temp->nextm;
						temp->nextm = NULL;
						car = NULL;
						temp = NULL;
						free(delcar);
						free(car);
						free(temp);
						MenuUtama(tc1, tc2);
					}
				}if(cek == 1){
				printf("\nTidak Ada Mobil dengan plat %s didalam Antrian\n\n", noPlat1);
				system("pause");
				}
			car = car->nextm;
			}
			}
		}else{
			printf("\nTidak Ada Mobil didalam Antrian\n\n", noPlat1);
			system("pause");
		}
	}else{
		printf("\nTidak Ada Mobil didalam Antrian\n\n", noPlat1);
		system("pause");
		}
}
 
// Ngambil dari Kating Seutuhnya
int stringcompare(char *a,char *b){  
    int flag = 0;  
    while(*a != '\0' && *b != '\0') 
    {  
        if(*a != *b)  
        {  
            flag = 1;  
        }  
        a++;  
        b++;  
    }  

    if(flag == 0) {     // APABILA DATANYA DINYATAKAN SAMA
        return 0;  
    } 
    else {              // APABILA DATANYA DINYATAKAN TIDAK SAMA
        return 1;  
    }
} 

void KeluarkanMobil (almttempatcuci tc1){
	int temp;
	temp = AntrianIsEmpty(tc1);
	if (temp == 0){
		if (tc1->nextt->nextm != NULL){
			if(waktuSekarang >= tc1->nextt->waktuKeluar){
				almtmobil carOut;
				carOut = tc1->nextt;
				tc1->nextt = tc1->nextt->nextm;
				carOut->nextm = NULL;
				free(carOut);
			}
			
		}else{
			if(waktuSekarang >= tc1->nextt->waktuKeluar){
				almtmobil carOut;
				carOut = tc1->nextt;
				tc1->nextt = NULL;
				free(carOut);
			}
		}
	}
}

void AfterSkip(almttempatcuci tc1, almttempatcuci tc2){
	UpdateWaktuCuci(tc1);
	UpdateWaktuCuci(tc2);
	KeluarkanMobil(tc1);
	KeluarkanMobil(tc2);
}

void UpdateWaktuCuci(almttempatcuci tc1){
	int i;
	i = AntrianIsEmpty(tc1);
	if (i == 0){
		if(tc1->nextt->nextm != NULL){
			if(waktuSekarang >= tc1->nextt->nextm->waktuProses){
				tc1->nextt->lamaProses = (tc1->nextt->lamaProses - (waktuSekarang - tc1->nextt->waktuProses));
				tc1->nextt->nextm->lamaProses = (tc1->nextt->nextm->lamaProses - (waktuSekarang - tc1->nextt->nextm->waktuProses));
			}
		}else if(tc1->nextt != NULL){
				if(waktuSekarang >= tc1->nextt->waktuProses){
						tc1->nextt->lamaProses = (tc1->nextt->lamaProses - (waktuSekarang - tc1->nextt->waktuProses));
			    }
		}
	}
}

void MenuAwal(almttempatcuci tc1, almttempatcuci tc2){
	system("cls");
	system("COLOR E0");
	int pilihan;
    printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
    printf("\t\t\xb3x                                                                                   x\xb3\n");
	printf("\t\t\xb3x              XXX     XXX    XX   XXXXXX   XXXXXX   XXXXXX   XXXXXX                x\xb3\n");
	printf("\t\t\xb3x              XX X   X XX    XX   XX         XX     XX       XX   XX               x\xb3\n");
	printf("\t\t\xb3x              XX  X X  XX    XX   XXXXXX     XX     XXXXXX   XXXXXX                x\xb3\n");
	printf("\t\t\xb3x              XX   X   XX    XX       XX     XX     XX       XX   XX               x\xb3\n");
	printf("\t\t\xB3x              XX       XX    XX   XXXXXX     XX     XXXXXX   XX    XX              x\xb3\n");
    printf("\t\t\xB3x                                                                                   x\xb3\n");
    printf("\t\t\xB3x                                      DOORSMEER                                    x\xb3\n");
	printf("\t\t\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
	printf("\t\t\t\t\t\t  1. Masuk Aplikasi\n");
	printf("\t\t\t\t\t\t  2. Manual Aplikasi\n");
	printf("\t\t\t\t\t\t  3. Keluar Aplikasi\n\n");
    printf("\t\t\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
	printf("\t\t\xb3x                          Copyright 2023 - MISTER DOORSMEER                        x\xb3\n");
	printf("\t\t\xb3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\xb3\n");
	printf("\t\t Masukkan Pilihan Anda (1-3): ");
	scanf("%d", &pilihan);
	switch (pilihan){
		case 1 : MenuUtama(tc1, tc2);
				 break;
		case 2 : MenuManual();
				 MenuAwal(tc1, tc2);
		case 3 : exit(0);
		
		default : printf("\n\t\t Pilihan Yang Anda Masukkan Salah! Coba Lagi\n\n");
				  system("pause");
				  MenuAwal(tc1, tc2);
	}                                                                
} 

void MenuManual(){
	system("cls");
	system("COLOR E0");
	printf("\nCARA MENGGUNAKAN APLIKASI :");
	printf("\n1. Klik '1' Untuk Memasukkan Mobil Ke Dalam Antrian ");
	printf("\n1. Klik '2' Untuk Menghapus Mobil Yang Berada Dalam Antrian ");
	printf("\n1. Untuk Input 3-7 Digunakan Untuk Skip Waktu Sesuai Keterangan Yang Tertera ");
	printf("\n1. Klik '8' Untuk Menampilkan Antrian ");
	printf("\n1. Klik '9' Untuk Keluar Antrian");
	printf("\n\n*Catatan Untuk Semua Inputan Menggunakan Angka Kecuali Saat Menginputkan Plat Nomor \n\n");
	system("pause");
}