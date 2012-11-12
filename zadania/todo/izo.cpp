#include <iostream>
#include <stdlib.h>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(void){
	int number;
	int i, j;
	cin >> number;
	int result = 0;
	int numbers[number];
	for(int i = 0; i< number; i++)
	{
		cin >> numbers[i];
		result += numbers[i];
	}
	qsort(numbers, number, sizeof(int), compare );
	

	i=0;
	j=number - 1;
	while(i<j){
		result += (numbers[j] - numbers[i]); 
		i++;
		j--;
	}
	cout << result << endl;
	
	return 0;
}