/* https://www.urionlinejudge.com.br/repository/UOJ_1708.html */

#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,fastr=0,slowr=0,i = 0,answ=0;
	cin >> x >> y;
	int fast = min(x,y);
	int slow = max(x,y);
	int dif = abs(x-y);
	dif = ceil((double)fast/dif);
	cout << dif+1 << endl;
return 0;
}