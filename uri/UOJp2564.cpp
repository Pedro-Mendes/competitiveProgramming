/* https://www.urionlinejudge.com.br/repository/UOJ_2564.html */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, p ,r,atual,answ,maxi,maxindex;
	vector<int> v;
	map<int, int> map;
	while(cin >> n){
		atual = 1;
		answ = 0;
		maxi = 0;
		maxindex = 0;
		v.clear();
		for (int i = 0; i < n-1; ++i){
			cin >> p >> r;
			v.push_back(p);
			map[p] = r;
			maxi = max(maxi,p);
			if(maxi == p)
				maxindex = i;			//before this index whatev
		}
		//cout << "maxindex = " << maxindex << endl;
		for (int i = maxindex; i < n-1; ++i){
			p = v[i];
			//cout << "p = " << v[i] << endl;
			if(p > atual && map[p]==0){
				//cout << "first" << endl;
				//cout << "map[" << p << "] = " << map[p] << endl; 
				answ++;
				atual = p;
			}else if(p > atual && map[p]==1){
				//cout << "second" << endl;
				//cout << "map[" << p << "] = " << map[p] << endl; 
				atual = p;
			}else if(p< atual && map[p]==1){
				//cout << "third" << endl;
				//cout << "map[" << p << "] = " << map[p] << endl; 
				answ++;
			}
		}
		cout << answ << endl;
	}




	return 0;
}