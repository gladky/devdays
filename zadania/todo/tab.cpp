#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1001;
const int M = 1000001;
int theTable[2][N][N];
pair<int,int> verseMap[2][N];
pair<int,int> columnMap[2][N];
const bool debug = false;

int main (void) { 
	int tabNum, m, n;
	int tmpMin[2];
	int current;
	int minId[2];
	bool result;
	scanf("%d", &tabNum); 																			//ilos par tablic
	for(int iTab = 0; iTab < tabNum; iTab ++){
	result = true;
	scanf("%d %d", &n, &m);
		for(int pairItr = 0; pairItr < 2; pairItr ++){
			for(int i = 0; i < n; i++){ //wiersz
				for(int j = 0; j < m; j++){ // elementy wiersza (kol)
					scanf("%d", &current);
					current += M;
					theTable[pairItr][i][j] = current;
					if(j==0){
						if(i == 0){ minId[0] = current; minId[1]=j; }
						tmpMin[0] = current;
						tmpMin[1] = j;
					}
					else {
						if(current < tmpMin[0]){
							tmpMin[0] = current;
							tmpMin[1] = j;
						}
					}
					
				}
				//sort(theTable[pairItr][i], theTable[pairItr][i] + m);
				verseMap[pairItr][i] = make_pair(tmpMin[0], i);
				if(tmpMin[0] < minId[0]){
					minId[0] = tmpMin[0];
					minId[1] = tmpMin[1];
				}
			}
			sort(verseMap[pairItr],verseMap[pairItr] + n);
			
		}
		//sprawdzenie czy id wierszy sa takie same
		/*
		for(int i =0; i < n; i++){
			if(verseMap[0][i] != verseMap[1][i])
				result = false;
		}
		
		if(result == false){
			printf("NIE\n");
			continue;
		}*/
		
		//stworzenie columMap dla wiersza o min id
		for(int pairItr = 0; pairItr < 2; pairItr ++){
			for(int i = 0; i < m; i++){
				columnMap[pairItr][i] = make_pair(theTable[pairItr][verseMap[pairItr][minId[1]].second][i],i);
				//printf("kurwa %d", columnMap[pairItr][i].first);
			}
			//printf("\n");
			sort(columnMap[pairItr],columnMap[pairItr] + m);
		}
		
		
		
		
			if(debug) printf("+++++++\n");
			for(int i = 0; i < n; i++){ //wiersz
				for(int j = 0; j < m; j++){ // elementy wiersza (kol)
					if(theTable[0][verseMap[0][i].second][columnMap[0][j].second] != theTable[1][verseMap[1][i].second][columnMap[1][j].second]) result = false;
					if(debug) printf("%d ", theTable[0][verseMap[0][i].second][columnMap[0][j].second]);
				}
				if(debug)printf("\n");
			}
			if(debug){
				printf("---\n");
				for(int i = 0; i < n; i++){ //wiersz
					for(int j = 0; j < m; j++){ // elementy wiersza (kol)
						printf("%d ", theTable[1][verseMap[1][i].second][columnMap[1][j].second]);
					}
					printf("\n");
				}
			}
			
		
		
		if(result) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}