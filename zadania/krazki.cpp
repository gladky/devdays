#include<iostream>
#include<stdio.h>
using namespace std;

int R[300002];
int K[300002];
int M[300002];

int main (void){
	int n, m, tmp,pos;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d",&R[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%d",&K[i]);
	}
	//liczenie minimow
	tmp = R[0];
	M[0]= 2000000000;
	for(int i=0; i<n; i++){
		if(R[i] < tmp) tmp = R[i];
		M[i+1] = tmp;
	}
	//szukanie liniowe
	pos = n+1;
	for(int i=0; i<m; i++){
		if(pos>0)pos--;
		while(K[i]>M[pos])pos--;
	}
	cout << pos;
	return 0;
}
