/* https://uva.onlinejudge.org/external/4/p459.pdf */

#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<string>
#include <array>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef pair<int,int> ii ;
typedef vector<ii> vii;
void print_visited(int visited[30], int size){
	
for(int i =0;i<size;i++){
 			cout << visited[i] << " ";
 		}
 		cout << endl;


}


void BFS(int m[30][30], int i, int visited[30], int size){
		for(int j=0; j<size; j++){
			if((m[i][j]) && (visited[j] == 0)){
				//print_visited(visited, size);
				visited[j] = 1;
				BFS(m, j, visited, size);
			}	
		}
}



int main(){
	int cases;
	char biggest;
	int size,l,r,count; 
	string input;
	int visited[30];
	int AdjMat [30] [30];
	
	cin >> cases;
	getline(cin, input);
	while(cases){
		count = 0;
		cin >> biggest;
		//cout << "biggest:" << biggest << endl;
 		size = ((int)biggest) - 64;
 		//cout << "size = " << size << endl;
 		memset(AdjMat, 0, sizeof(AdjMat[0][0]) * 30 * 30);
 		fill_n(visited, 30, 0);
 		//print_visited(visited,30);
		getline(cin, input);
		while(getline(cin, input)){
			if(input.empty()){
				//cout << "HERE" << endl;
				break;
			}
			l = (int)input[0] - 65;
			r = (int)input[1] - 65;
			AdjMat[l][r] = 1;	
			AdjMat[r][l] = 1;			
		}
		for(int i =0; i<size;i++){
			if(visited[i]==0){
				visited[i] = 1;
				BFS(AdjMat, i, visited,size);
				count++;
			}
		}
		cout << count << endl;
		cases--;
		if(cases != 0){
			cout << endl;
		}
	}
	/*for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(AdjMat[i][j])
			cout << i << "-> " << j << " ";
		}
		cout << endl;
	
	}*/
return 0;
}
