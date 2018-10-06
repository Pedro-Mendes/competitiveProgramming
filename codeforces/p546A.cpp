/* http://codeforces.com/problemset/problem/546/A */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int k,n,w,answ;
	cin >> k >> n >> w;
	answ = (w*(w+1))/2;
	answ *= k;
	if (n >= answ)
	{
		answ = 0;
	}else{
		answ -= n;
	}
	cout << abs(answ) << endl;
return 0;
}