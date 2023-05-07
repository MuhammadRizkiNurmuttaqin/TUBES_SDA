//ini Main

#include "BodyCuciMobil.c"


int main(){
	almttempatcuci doorsmeerA;
	almttempatcuci doorsmeerB;
	CreateAntrian(&doorsmeerA, 'A');
 	CreateAntrian(&doorsmeerB, 'B');
	MenuAwal(doorsmeerA, doorsmeerB);	
}
