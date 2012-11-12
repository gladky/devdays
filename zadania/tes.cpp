#include <stdio.h>
#include <vector>

using namespace std;

// zmienne bezp wynikajace z zadania
const int M = 1000001; //maksymalna dlugosc glownego ciagu
int ciagA[M];
int ciagBi[M];
// zmienne pomocnicze
vector<int> l[M];
int currMaxElem = 0;
int current;
bool debug = false;

int pierwszy_wiekszy(int lc, int j){
	int lewy = 0;
	if(l[lc].size() <= 0) return -1;
	int prawy = l[lc].size() - 1;
	if(debug) printf("lewy=%d, prawy=%d, idx=%d\n",lewy,prawy,j);
	while(lewy < prawy){
		int srodkowy = (lewy + prawy) / 2;
		if(debug) printf("new srodkowy value: %d\n",srodkowy);
		if(l[lc][srodkowy] <= j) lewy = srodkowy +1;
		else prawy = srodkowy;
	}
	if(debug) printf("lewy=%d, lc.lewy=%d\n", lewy, l[lc][lewy]);
	if(l[lc][lewy] > j) return l[lc][lewy];
	else { 
		if(debug) printf("ciagB nie jest podciagiem ciaguA!!!!\n");
		return -1;
	}
}

void initTabL(int currMaxElem, int m){
	for(int i = 0; i < m; i++){
		l[ciagA[i]].push_back(i);
		if(debug)printf("wystapienie wartosci %d, w ciagu A, index %d\n" , ciagA[i], i);
	}
	if(debug)printf("zainicjowana tablica :\n");
	for(int i = 1 ; i <= currMaxElem; i++) if(debug)printf("%d", l[i].size());
	if(debug)printf("\n");
}


int main (void){
	// zmienne bezp wynikajace z zadania
	int m; //podana dlugosc glownego ciagu
	int n; //ilosc podciagow Bi
	int mi; //dlugosc kolejnych podciagow Bi
	// zmienne pomocnicze
	bool stillCanBe = true;
	
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &current);		//wczytanie ciagu A
		ciagA[i] = current;
		if(currMaxElem < current) currMaxElem = current;
	}
	
	initTabL(currMaxElem, m);
	
	scanf("%d",&n);
	for(int j = 0; j < n; j++){		//dla kazdego podciagu Bi
		scanf("%d", &mi);			//wczytaj dlugosc Bi
		for(int i = 0; i < mi; i++ ){
			scanf("%d", &ciagBi[i]);	//wczytanie ciagu B
		}
		int t = -1;
		for(int k = 0; k < mi; k++){	//dla kazdego elementu podciagu B
			if(debug) printf("current element from ciagB: %d\n", ciagBi[k]);
			t = pierwszy_wiekszy(ciagBi[k],t);
			if(debug)printf("t=%d\n",t);
			if(t == -1) {
				printf("NIE\n");
				break; // olej dalsze sprawdzanie, wczytaj kolejny podciag B
			}
		}
		if(t!= -1) printf("TAK\n");
		
	}
	
	if(debug)printf("hello\n");
	return 0;
}