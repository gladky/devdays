#include <iostream>

using namespace std;

int main (void) {
	int stos[250000];
	int ssize = 0;
	int wynik = 0;
	int n;
	
	cin >> n;
	int dane[n];
	for (int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		cin >> tmp;
		dane[i] = tmp;
	}

	for(int i=0; i<n; i++)
	{
		while (ssize>0 && stos[ssize-1] > dane[i]){
			ssize --;
		}
		if (ssize == 0 || stos[ssize-1] < dane[i]){
			stos[ssize++] = dane[i];
			wynik ++;
		}
	}
	
	cout << wynik << endl;
}