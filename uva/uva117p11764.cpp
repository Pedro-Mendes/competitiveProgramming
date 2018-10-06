/* https://uva.onlinejudge.org/external/117/p11764.pdf */

#include<iostream>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
	int T,N,H,L;
	cin >> T;
	vector<int> v(50,-1);
	for(int i=0; i<T;i++){
		H =0;
		L =0;
		cin >> N;
		if(T == 1){
			cout << "Case " << T << ": " << H <<  " " << L << endl; 
			continue;
		}
		for(int j = 0; j<N;j++){
			cin >> v[j];
		}
		for(int j = 0; j<N-1;j++){
			if(v[j] < v[j+1]){
				H++;
			}else if (v[j] > v[j+1]){
				L++;
			}
		}
		cout << "Case " << i+1 << ": " << H <<  " " << L << endl; 

	}

return 0;
}
