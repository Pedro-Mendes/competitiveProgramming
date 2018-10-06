/* https://br.spoj.com/problems/GUARDCOS/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	double d,vf,vg,tf,tg,x;
	while(cin >> d >> vf >> vg){
		tf = 12/vf;
		x = sqrt(d*d + 144);
		tg = x/vg;
	if(tg <= tf){cout << "S\n";}
	else{cout << "N\n";}
	}




return 0;
}
