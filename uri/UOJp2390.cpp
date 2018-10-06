/* https://www.urionlinejudge.com.br/repository/UOJ_2390.html */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t=0,x, last=0;
	cin >> n;
	cin >> x;
	t = 10;
	last = x+10;
	for(int i =1 ; i<n;i++){
		cin >> x;
		if (x <= last)
		{
			t+= x+10 - last;
			last = x+10;

		}else{
			last = x+10;
			t += 10;
		}
		//cout << "t = " << t << endl;
		
	}
	cout << t << endl;
	

return 0;
}