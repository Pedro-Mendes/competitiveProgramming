/* https://uva.onlinejudge.org/external/106/p10678.pdf */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	double x,area, d,y,l;
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> d >> l;
		x = sqrt((l*l)/4 - (d*d)/4);
		y = l/2;
		area = 2*acos(0) * x * y;
		cout << std::setprecision(3) << fixed << area << '\n';
	}




return 0;
}