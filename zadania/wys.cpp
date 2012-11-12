#include<iostream>
#include<cmath>

using namespace std;

int main (void) {
	int n, rekord =0;
	int s =0; //odchylenie od polobwodu
	int x = 1, y=1; // poczatkowe miasta
	int obwod =0, wynik,pol_obwodu;
	int tmp;
	cin >> n;
	int wyspa[n];
	
	for(int i = 0; i< n; i ++){
		cin >> wyspa[i];
	}
	
	for(int i = 0; i< n; i ++){
		//cout << wyspa[i];
		obwod += wyspa[i];
	}
	
	rekord = obwod;
	pol_obwodu = obwod/2;
	
	while (y<=n){
		if (s < pol_obwodu) {
			s += wyspa[y];
			y ++;
		}
		else{
			s -=wyspa[x];
			x ++;
		}
		tmp = abs(pol_obwodu - s);
		if (rekord > tmp) rekord = tmp;
	}
	wynik = pol_obwodu - rekord;
	cout << wynik << endl;
}