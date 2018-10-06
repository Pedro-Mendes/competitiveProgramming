/* https://www.urionlinejudge.com.br/repository/UOJ_2542.html */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,l,cm,cl,a,x;
	int matrixL[101][101];
	int matrixM[101][101];
	while(cin >> n){
		memset(matrixL, 0, sizeof (matrixL));
		memset(matrixM, 0, sizeof (matrixM));
		cin >> m >> l;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				cin >> x;
				matrixM[i][j] = x;
			}
		}
		for (int i = 0; i < l; ++i){
			for (int j = 0; j < n; ++j){
				cin >> x;
				matrixL[i][j] = x;
			}
		}
		cin >> cm >> cl;
		cin >> a;
		if(matrixM[cm-1][a-1] > matrixL[cl-1][a-1]){
			cout << "Marcos" << endl;
		}else if(matrixM[cm-1][a-1] < matrixL[cl-1][a-1]){
			cout << "Leonardo" << endl;
		}else{
			cout <<"Empate" << endl;
		}

	}
	return 0;
}