/* https://br.spoj.com/problems/IRMAOS/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,r,c,k;
	vector< vector<int> > matrix(101,vector<int> (101));
	vector< vector<int> > copy(101,vector<int> (101));
	cin >> n >> r >> c >> k;
	while(n!=0 && r!=0 && c!=0 && k!=0){
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				cin >> matrix[i][j]; 
			}
		}
		copy = matrix;
		for (int l = 0; l < k; ++l){
			for (int i = 0; i < r; ++i){
				for (int j = 0; j < c; ++j){
					if (i+1 <r){
						if (copy[i+1][j] == (copy[i][j]+1)%n){
							matrix[i+1][j] = copy[i][j];
						}
					}
					if (j+1 < c){
						if (copy[i][j+1] == (copy[i][j]+1)%n){
							matrix[i][j+1] = copy[i][j];
						}
					}
					if (i-1 >= 0){
						if (copy[i-1][j] == (copy[i][j]+1)%n){
							matrix[i-1][j] = copy[i][j];
						}
					}
					if (j-1>=0){
						if (copy[i][j-1] == (copy[i][j]+1)%n){
							matrix[i][j-1] = copy[i][j];
						}
					}
					
				}
			}
			copy = matrix;
		}
		for (int i = 0; i < r; ++i){
			cout << matrix[i][0];
			for (int j = 1; j < c; ++j){
				cout << " " << matrix[i][j];
			}
			cout << endl;
		}

		cin >> n >> r >> c >> k;
	}
return 0;
}