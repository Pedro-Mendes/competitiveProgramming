/* https://uva.onlinejudge.org/external/15/p1585.pdf */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,count,sum;
	string s;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		sum = 0;
		count = 1;
		cin >> s;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == 'O')
			{
				sum+=count;
				count++;
			}else{
				count = 1;
			}
		}
		cout << sum << endl;
	}



}