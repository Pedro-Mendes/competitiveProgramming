/* https://icpcarchive.ecs.baylor.edu/external/51/p5113.pdf */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,sum;
	int n,a,d;
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> n >> a >> d;
		sum = a*n + ((n*(n-1))/2)*d;
		cout << sum << endl;
	}



	return 0;
}