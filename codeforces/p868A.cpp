/* http://codeforces.com/problemset/problem/868/A */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	bool found = false;
	string passwd;
	string x;
	vector<string> v;
	string t;
	cin >> passwd;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < n && !found; ++i){
		for (int k = 0; k < n && !found; ++k){
			t = v[i] + v[k];
			for (int i = 0; i < 3 && !found; ++i){
				if(t[i] == passwd[0] && t[i+1]==passwd[1]){
					cout << "YES\n";
					found = true;
				}
			}
		}
	}
	if(!found)
		cout << "NO\n";




return 0;
}