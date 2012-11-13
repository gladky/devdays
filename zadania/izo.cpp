#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int numbers[10002];

int main(void){
	int number;
	int i, j, tmp;
	cin >> number;
	int result = 0;
	for(i = 0; i< number; i++){
		scanf("%d",&tmp);
		numbers[tmp]++;
		result += tmp;
	}

	i=1;
	j=10002;
	
	while(i<j){
		if(numbers[i] != 0 && numbers[j] != 0){
			result += (j-i); 
			numbers[j]--;
			numbers[i]--;
		}
		if(numbers[i]==0) { i++;}
		if(numbers[j]==0) { j--;}
	}
	cout << result << endl;
	
	return 0;
}