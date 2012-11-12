#include<iostream>
#include<stdio.h>

using namespace std;

bool debug = false;
int size;
int const maxSize = 1002;
int content[maxSize][maxSize];
int odw[maxSize][maxSize];
int doliny=0, grzbiety=0, k;
//kolejka do poszukiwania wszerz
short posx[maxSize*maxSize], posy[maxSize*maxSize];

int spr(int nx, int ny, int x, int y, bool wynik){
	if(content[nx][ny] > content[x][y]) wynik = 0;
	if(!odw[nx][ny] && content[nx][ny] == content[x][y]){
		odw[nx][ny] = 1;
		posx[k]=nx;
		posy[k]=ny;
		k++;
	}
return wynik;
}

int szukajDoliny(int x, int y){
	posx[0] = x;
	posy[0] = y;
	odw[x][y] =1;
	int p = 0; 
	k=1;
	bool wynik =1;
	while(p<k){
		wynik = spr(posx[p]-1,	posy[p]-1,	posx[p],posy[p],wynik);
		wynik = spr(posx[p]-1,	posy[p],	posx[p],posy[p],wynik);
		wynik = spr(posx[p]-1,	posy[p]+1,	posx[p],posy[p],wynik);
		wynik = spr(posx[p],	posy[p]-1,	posx[p],posy[p],wynik);
		wynik = spr(posx[p],	posy[p]+1,	posx[p],posy[p],wynik);
		wynik = spr(posx[p]+1,	posy[p]-1,	posx[p],posy[p],wynik);
		wynik = spr(posx[p]+1,	posy[p],	posx[p],posy[p],wynik);
		wynik = spr(posx[p]+1,	posy[p]+1,	posx[p],posy[p],wynik);
		p++;
	}
	return wynik;
}


int main(){
	if(debug) cout << "getting size of table" << endl;
	cin >> size;
	if(debug) cout << "size of table " << size << endl;
	
	// czyszczenie tablic - WAZNE - wokol tablic musi byc obwodka -2*10^9
    for(int x = size + 1; x >= 0; x--) for(int y = size + 1; y >= 0; y--) {
        odw[x][y] = 0;
        content[x][y] = -2000000000;
    }
	
	// wczytanie danych
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			scanf("%d", &content[i][j]);		//i - wiersz; j - kolumna
			odw[i][j] = 0;
		}
	}
	if(debug) cout << "data for content marshaled" << endl;
	
	// obliczenie liczby dolin
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			if(!odw[i][j]) doliny += szukajDoliny(i,j);
			if(debug)printf("%d ", content[i][j]);
		}
		if(debug)printf("\n");
	}
	
	//odwrocenie mapy
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			content[i][j] = -content[i][j];
			odw[i][j] = 0;
		}
	}
	
	// obliczenie liczby grzebietow
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			if(!odw[i][j]) grzbiety += szukajDoliny(i,j);
			if(debug)printf("%d ", content[i][j]);
		}
		if(debug)printf("\n");
	}
	
	if(debug) cout << "Doliny i grzbiety policzone " << endl;
	cout << doliny <<" " << grzbiety<< endl;
	
	//zaczynamy o pierwszego i przeszukujemy wszerz  jesli pola dostepne i otoczenie mniejsze/wieksze
	//do przechowywania stanu pol uzyjemy dodatkowej tabeli
	//UNCHECKED, PROCESSED
	
	
	
	return 0;
}