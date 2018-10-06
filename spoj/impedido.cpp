/* https://br.spoj.com/problems/IMPEDIDO/ */

#include<bits/stdc++.h>
using namespace std;


int main(){

	int a,d,ai,di,x;
	vector<int> atak;
	vector<int> def;
	char answ;
	cin >> a >> d;
	while(a!=0 && d!=0){
		answ = 'N';
		atak.clear();
		def.clear();
		for(int i = 0; i<a;i++){
			cin >> ai;
			atak.push_back(ai);
		}
		for(int i = 0; i<d;i++){
			cin >> di;
			def.push_back(di);
		}
		sort(atak.begin(), atak.end());
		sort(def.begin(), def.end());
		if(atak[0] < def[1]){
			answ = 'Y';
		}
		cout << answ << endl;
		cin >> a >> d;
	}
return 0;
}
