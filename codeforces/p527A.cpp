/* http://codeforces.com/problemset/problem/527/A */

#include<bits/stdc++.h>
using namespace std;

long long answ = 0;
long long gcd(long long a, long long b){
	if (b!=0){
		answ += a/b;
	}
	return b == 0 ? a : gcd(b, a%b);
}
int main(){
	long long a,b;
	cin >> a >> b;
	gcd(a,b);
	cout << answ << endl;
	return 0;
}