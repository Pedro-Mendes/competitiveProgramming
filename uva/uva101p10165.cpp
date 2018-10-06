/* https://uva.onlinejudge.org/external/101/p10165.pdf */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,sz,x,notGreaterThanOne = 1;
	cin >> n;
	while(n!=0){
		x = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> sz;
			x^= sz;
			if (sz>1)
			{
				notGreaterThanOne = 0;
			}
		}

		if(x^notGreaterThanOne){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}

		cin >> n;
	}

return 0;
}