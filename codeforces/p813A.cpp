/* http://codeforces.com/problemset/problem/813/A */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int  n,m,x,start, end,sum=0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x; 
		sum+=x;	// in sum units of time (minimum) he would finish all problems and submit
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end;
		if (sum <= start)
		{
			cout << start << endl;
			return 0;
		}else if (sum > start && sum<= end)
		{
			cout << sum << endl;
			return 0;
		}
	}
	cout << -1 << endl;
return 0;
}