#include <stdio.h>
int tab[2002];
int main(){
	int m,n,j,k1=1,k2=1,suma=0;
	
	scanf("%d %d",&n,&m);
	for(int i=1; i<n; i++){
		scanf("%d",&j);
		tab[j]++;
	}
	for(int i=1; i<m; i++){
		scanf("%d",&j);
		tab[j+1000]++;
	}
	for(int i=1000; i>=0;i--){
		if(tab[i]!=0){
			suma += i*tab[i]*k2;
			k1+=tab[i];
		}
		if(tab[i+1000]!=0){
			suma += i*tab[i+1000]*k1;
			k2+=tab[i+1000];
		}
	}
	printf("%d\n",suma);
	return 0;
}
