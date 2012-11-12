#include <iostream>

using namespace std;

#define MAXSPYS 1000000
bool debug = 0;

int track[MAXSPYS];
int scount[MAXSPYS];
bool sent[MAXSPYS];
int queue[MAXSPYS];
int qh, qt;

int main(void){
	int N, current;
	int result = 0;
	
	//read data
	cin >> N;
	for(int i = 0; i < N; i++){
		int s;
		cin >> s;
		track[i] = s-1;
	}
	if(debug) for(int i = 0; i < N; i++) cout << "debug[track]" <<track[i] << endl;
	
	//count how many spys are tracking each spy
	for(int i = 0; i < N; i++) ++scount[track[i]];
	if(debug) for(int i = 0; i < N; i++) cout << "debug[scount]" <<scount[i] << endl;
	
	//fill queue with untracked spys
	for(int i = 0; i < N; i++) if(scount[i]==0) queue[qt++] = i;
	if(debug) for(int i = 0; i < N; i++) cout << "debug[queue]" <<queue[i] << endl;
	
	//send untracked spys and ones tracked by them to mission
	while(qh < qt){
	if(debug) cout << "debug[while#1]" << endl;
		current = queue[qh++];
		if(debug) cout << "debug[current]" << current << endl;
		if(sent[current] == 0 && sent[track[current]] == 0){
			if(debug) cout << "debug[condition are meet]" << endl;
			result++;
			sent[current] = sent[track[current]] = 1;
			if(--scount[track[track[current]]] == 0 && sent[track[track[current]]] == 0)
				queue[qt++] = track[track[current]];
		}
	}
	if(debug) for(int i = 0; i < N; i++) cout << "debug[sent]-1: " <<sent[i] << endl;
	
	//split cycles
	for(int i = 0; i < N; i++){
		if(sent[i] == 0){
			current = i;
			while(sent[current] == 0 && sent[track[current]] == 0){
				if(debug) cout << "debug[condition are meet]" << endl;
				result++;
				sent[current] = sent[track[current]] = 1;
				current = track[track[current]];
			}
		}
	}
	if(debug) for(int i = 0; i < N; i++) cout << "debug[sent]-2: " <<sent[i] << endl;
	
	//write result
	cout << result;
	return 0;
}