/* https://uva.onlinejudge.org/external/100/p10079.pdf */

#include<bits/stdc++.h>
using namespace std;


int main(){
	long long int n,answ;
	cin >> n;
	while(n >=0){
		answ = n*(n+1)/2;
		answ++;
		cout << answ << endl;
		cin >> n;
	}




return 0;
}
