/* https://br.spoj.com/problems/BANDA09/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int matrix[100][100] = {{0}};
	int n,m,i,j,k,x,y,z,z1,z2,z3,w1=0,w2=0,w3=0,i1,i2,i3;
	cin >> n >> m;
	for(i =0 ; i<m ;i++){
		cin >> x >> y >> z;
		matrix[x-1][y-1] = z;
		matrix[y-1][x-1] = z;
	}
	
	for(i =0 ; i<n ;i++){
		for(j =0 ; j<n ;j++){
			if(i!=j){
				z1 = matrix[i][j];
				for(k = j+1 ; k<n ;k++){
					if(k!=i){
						z2 = matrix[i][k];
						z3 = matrix[j][k];
						if((z1+z2+z3)>=(w1+w2+w3)){
							w1 = z1;
							w2 = z2;
							w3 = z3;
							i1 = i;
							i2 = j;
							i3 = k;
						}
					}
				}
			}
		}
	}
	
	cout << i1+1 << " " << i2+1 << " " << i3+1<< endl;


return 0;
}
