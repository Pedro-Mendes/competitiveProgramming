/* https://br.spoj.com/problems/MARIENBA/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,sz,x,notGreaterThanOne = 1,T;
	cin >> T;
	for (int i = 0; i < T; ++i)
		{
			x =0;
			notGreaterThanOne = 1;
			for (int i = 0; i < 6; ++i)
			{
				cin >> sz;
				x^= sz;
				if (sz>1)
				{
					notGreaterThanOne = 0;
				}
			}

			cout << "Instancia " << i+1 << endl;
			if(x^notGreaterThanOne){
				cout << "sim\n";
			}else{
				cout << "nao\n";
			}

		}	
		

return 0;
}