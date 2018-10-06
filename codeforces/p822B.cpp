/* http://codeforces.com/problemset/problem/822/B */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int ss, ts,sum=0, minSum=6666, index, I;
	string s,t;
	std::vector<int> v;
	std::vector<int> aux;
	cin >> ss >> ts;
	cin >> s >> t;
	if(ss != ts){
		for (int i = 0; i <= ts-ss; ++i)
		{
			sum = 0;
			index = aux.size();
			for (int j = 0; j < ss; ++j)
			{
				if (s[j] != t[i+j])
				{
					sum++;
					aux.push_back(j+1);
				}
			}
			minSum = min(minSum, sum);
			//cout << minSum << endl;
			if (minSum == sum)
			{
				I = index;
			}
		}
	}else{
		sum = 0;
		for (int i = 0; i < ts; ++i)
		{
			if (s[i] != t[i])
			{
				sum++;
				aux.push_back(i+1);
			}
			//cout << minSum << endl;
		}
		minSum = sum;
		I = 0;
	}

	if (aux.size() > 0 && minSum!=0)
	{
		cout << minSum << endl;
		cout << aux[I] << " ";
		for (int i = 1; i < minSum; ++i)
		{
			cout << " " << aux[I+i];
		}
		cout << endl;

	}else{
		cout << 0 << endl;
	}
return 0;
}