/* http://codeforces.com/problemset/problem/546/B */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x, answ=0,k,j;
	std::vector<int> rcvd;
	std::vector<int> visited(6001,0);
	rcvd.clear();
	bool found = false;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		rcvd.push_back(x);
		visited[x]+=1;
	}
	sort(rcvd.begin(), rcvd.end());
	k = rcvd[0]; //menor que ha
	for (int i = 0; i < n; ++i)
	{
		if (visited[rcvd[i]] >1)
		{
			visited[rcvd[i]] -=1;
			j=1;
			found = false;
			while(!found){
				if (visited[rcvd[i]+j] == 0)
				{
					//cout << "mais prox = " << rcvd[i]+j << " "; 
					//cout << "analisando  = " << rcvd[i] << " "; 
					visited[rcvd[i]+j] = 1;
					answ+= j;
					//cout << answ << endl;
					found = true;
					break;
				}
				++j;
			}
		}
	}

	cout << answ << endl;

return 0;
}