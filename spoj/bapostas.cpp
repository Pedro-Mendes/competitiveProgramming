/* https://br.spoj.com/problems/BAPOSTAS/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, x,sum,prev,answ;
	cin >>t;
	while(t!=0){
		sum = 0;
		answ = 0;
		for(int i = 0; i< t; i++){
			cin >> x;
			prev = sum;
			sum+=x;
			if(sum < 0){
				answ = max(prev,answ);
				sum = 0;
			}else{
				answ = max(sum,answ);
			}
		}
	
	if(answ){cout << "The maximum winning streak is " << answ << "." << endl;}
	else{cout << "Losing streak." << endl;}
	cin >> t;
	}



return 0;
}




