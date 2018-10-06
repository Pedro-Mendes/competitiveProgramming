/* https://www.urionlinejudge.com.br/repository/UOJ_2530.html */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m,x,i=0,k=0;
	std::vector<int> juan;
	std::vector<int> rick;
	bool possible = true;
	while(cin >> n && cin >> m){
		k=0;
		possible = true;
		juan = vector<int> ();
		rick = vector<int> ();
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			juan.push_back(x);
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> x;
			rick.push_back(x);
		}
		// for (int i = 0; i < m; ++i)
		// {
		// 	cout << rick[i] << " ";
		// }
		// cout << endl;
		i=0;
		while(possible){
			if (juan[i] == rick[k])
			{
				k++;
			}
			//cout << k << endl;
			if (i+1 > juan.size() || k>= rick.size())
			{
				possible = false;
				break;
			}
			i++;

		}
		// cout << k << endl;
		if (k == (rick.size()))
		{
			cout << "sim" << endl;
		}else{
			cout << "nao" << endl;
		}
	}
return 0;
}