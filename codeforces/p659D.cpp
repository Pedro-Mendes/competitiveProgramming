/* http://codeforces.com/problemset/problem/659/D */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,answ=0,y,x;
	cin >> n;
	vector< pair<int,int> > v;
	for (int i = 0; i <= n; ++i){
		cin >> y >> x;
		v.push_back(make_pair(y,x));
	}
	for (int i = 2; i <= n; ++i){
		if((v[i].first == v[i-1].first && v[i].second > v[i-1].second && v[i-1].first > v[i-2].first && v[i-1].second == v[i-2].second) ||
			(v[i].first < v[i-1].first && v[i].second == v[i-1].second && v[i-1].first == v[i-2].first && v[i-1].second > v[i-2].second) ||
			(v[i].first == v[i-1].first && v[i].second < v[i-1].second && v[i-1].first < v[i-2].first && v[i-1].second == v[i-2].second) ||
			(v[i].first > v[i-1].first && v[i].second == v[i-1].second && v[i-1].first == v[i-2].first && v[i-1].second < v[i-2].second)
			){
			//cout << "Pontos: {(" << v[i].first << "," << v[i].second <<  "); (" << v[i-1].first << "," << v[i-1].second << "); (" << v[i-2].first << "," << v[i-2].second << ")}" << endl;
			answ++;
		}
	}
	cout << answ << endl;



	return 0;
}