/* http://codeforces.com/problemset/problem/805/A */

#include<bits/stdc++.h>
using namespace std;


int main(){
	int l,r,size;
	bool prime = true;
	cin >> l >> r;
	if (l!=r)
	{
		cout << 2 << endl;
	}else{
		if (l%2 == 0)
		{
			cout << 2 << endl;
			return 0;
		}else{
			for (int i = 3; i < sqrt(r); ++i)
			{
				if (r%i == 0)
				{
					cout << i << endl;
					prime = false;
					return 0;
				}
			}
			if (prime)
			{
				cout << r << endl;
				return 0;
			}

		}
	}


	return 0;
}