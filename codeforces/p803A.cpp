/* http://codeforces.com/problemset/problem/803/A */

#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector< vector<int> > m,int n){
	for(int i =0; i<n;i++){
		cout << m[i][0];
		for(int j = 1; j< n;j++){
			cout << " "<< m[i][j];
		}
		cout << endl;
	}
}


int main(){
	int n,k; //matrix nxn and k ones
	vector< vector<int> > m;
	cin >> n >> k;
	m = vector< vector<int> > (n, vector<int> (n,0));
	if(k <= n*n){
			//m[0][0] = 1;	
			//k-=1;
			for(int i = 0 ;i < n && k>0; i++)
				for(int j = 0; j < n && k>0; j++){
					if(m[i][j] == 0 && i!=j && k-2>=0){
						m[i][j] = 1;
						m[j][i] = 1;
						k-=2;
					}else if (m[i][j]==0 && i==j && k-1>=0){
						m[i][i] = 1;
						k-=1;
					}			
				}
	}else{
		k = -1;
	}
	if(k==0){
		printMatrix(m,n);
	}else{
		cout << -1 << endl;
	}
return 0;
}