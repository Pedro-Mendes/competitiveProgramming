/* https://uva.onlinejudge.org/external/131/p13135.pdf */

#include <bits/stdc++.h>
using namespace std;
int main(){
	int p,x,n,a1=3;
	double aux;
	cin >> p;
	for(int i =0;i<p;i++){
		cin >> x;
		aux = sqrt(1+(8*x));
		if(aux == floor(aux)){
			n = (-5 + aux)/2;
			n+=1;
			cout << n << endl;
		}else{
			cout << "No solution\n";
		}
	}



return 0;
}
