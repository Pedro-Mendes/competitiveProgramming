/* http://codeforces.com/problemset/problem/808/A */

#include<bits/stdc++.h>
using namespace std;



int main(){
	int n,aux,k=0,rest, answ,p=1;
	cin >> n;
	aux = n;
	while(aux >= 10){
		aux = aux/10;
		k+=1;
	}
	for(int i =0; i<k;i++){
		p*=10;
	}


	answ = aux*p + p - n;
	cout << answ << endl;

return 0;
}