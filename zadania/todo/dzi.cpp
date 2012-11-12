#include <iostream>
#include <stdio.h>
#include <stack>
#define MAX 2000

using namespace std;

bool debug = 0;
int n;
bool wasPop;
int list[2*MAX];
int field[MAX][MAX];
int G[MAX+2];
int result;


class Pair{
	int k;
	int g;
	public:
	Pair(int k_, int g_){
		k=k_;
		g=g_;
	}
	Pair(){
		k=0;
		g=0;
	}
	void set(Pair p){
		k=p.getK();
		g=p.getG();
	}
	void setK(int k_){ k = k_;}
	void setG(int g_){ g = g_;}
	int getK(){ return k; }
	int getG(){ return g; }
};

void initField(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			//scanf('%d', field[i][j]);
			cin >> field[i][j];
		}
	}
}

void checkField(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			//scanf('%d', field[i][j]);
			cout << field[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

void initG(int verse){
	for(int i = 0; i<= n+1; i++){
		if(i == 0 || i == n+1) G[i] = 0;
		else if(field[verse][i-1] == 0) G[i]++;
		else G[i] = 0;
	}
	if(debug) for(int i = 0; i<= n+1; i++) cout <<"[debug]:G-tab["<<i<<"]="<< G[i]<< endl;
}

stack<Pair> S;
Pair pair_ = Pair();

void init(){
	while(!S.empty()) S.pop();
}

void kandydat(int obszar){
	if (obszar > result){ result = obszar;
		if(debug) cout << "[debug] kandydat: " << obszar << endl;
	}
}

void findMax(){
	int start;
	init();
	pair_.setG(0); pair_.setK(0);
	S.push(pair_);
	for(int j=1; j<n+1;j++){
		start = j;
		while (G[j]<S.top().getG()){
			pair_.set(S.top());
			S.pop();
			kandydat(pair_.getG() * (j - pair_.getK()));
			start = pair_.getK();
		}
		if(S.top().getG() < G[j]){
			pair_.setK(start);
			pair_.setG(G[j]);
			S.push(pair_);
		}
	}
}

int main(void){
	initField();
	for(int i=0; i<n; i++){
		initG(i);
		findMax();
	}
	cout << result;
}