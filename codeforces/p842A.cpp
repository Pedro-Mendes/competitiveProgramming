/* http://codeforces.com/problemset/problem/842/A */

#include<bits/stdc++.h>
using namespace std;

int main(){
	long long l,r,x,y,k;
	string answ = "NO\n";
	cin >> l >> r >> x >> y >> k;

	for (int i = x; i <=y ; ++i)
	{
		if (k*i <= r && k*i>= l){
			answ = "YES\n";
			continue;
			//cout << k*i << endl;
		}
	}
	cout << answ;



return 0;
}