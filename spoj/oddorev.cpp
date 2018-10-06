/* https://br.spoj.com/problems/ODDOREVE/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m,x, par_m, impar_m, par_j, impar_j;
	cin >> n;
	while(n!=0){
		par_m =0; 
		impar_m = 0; 
		par_j =0; 
		impar_j=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			if (x %2)
			{
				impar_m++;
			}else{
				par_m++;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			if (x %2)
			{
				impar_j++;
			}else{
				par_j++;
			}
		}
		if (impar_j >= par_m)
		{
			impar_j -= par_m;
			par_m = 0;
		}else{
			par_m -= impar_j;
			impar_j = 0;

		}
		if (impar_m >= par_j)
		{
			impar_m -= par_j;
			par_j = 0;
		}else{
			par_j -= impar_m;
			impar_m = 0;

		}
		// cout << "par_m = " << par_m << endl;
		// cout << "impar_m = " << impar_m << endl;
		// cout << "par_j = " << par_j << endl;
		// cout << "impar_j = " << impar_j << endl;
		cout << (par_m + impar_m + impar_m + par_j)/2 << endl;
		cin >> n;
	}

return 0;
}