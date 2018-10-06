/* http://codeforces.com/problemset/problem/814/A */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b,x,m=0;
	std::vector<int> ai;
	std::vector<int> a_zeros;
	std::vector<int> bi;
	cin >> a >> b;
	for (int i = 0; i < a; ++i)
	{
		cin >> x;
		ai.push_back(x);
		if (x==0)
		{
			a_zeros.push_back(i);
		}
	}
	for (int i = 0; i < b; ++i)
	{
		cin >> x;
		bi.push_back(x);
	}
	sort(bi.begin(), bi.end());
	for (int i = 0; i < b; ++i)
	{
		ai[a_zeros[i]] = bi[b-i-1];
	}
	
	/*for (int i = 0; i < a; ++i)
	{
		cout << ai[i] << " ";
	}
	cout << endl;
	*/
	if (ai[0] > ai[1])
	{
		cout << "Yes\n";
		return 0;
	}
	if (ai[a-1] < ai[a-2])
	{
		cout << "Yes\n";
		return 0;
	}
	for (int i = 1; i < a-1; ++i)
	{
		if (ai[i] < ai[i-1] || ai[i] > ai[i+1])
		{
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	

return 0;
}