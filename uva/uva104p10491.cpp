/* https://uva.onlinejudge.org/external/104/p10491.pdf */

#include<iostream>
#include <iomanip>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
	double eq,cow, car, show, total;
	while(cin >> cow >> car >> show) {
		//cin >> cow >> car >> show;
		total = car + cow;
		//first scenario: picking a car first
		eq = (car/total) * ((car-1)/(total-(show+1)));
		//adding the second scenario: picking a cow first
		eq += (cow/total) * ((car)/(total-(show+1)));
		cout << setprecision(5) << fixed <<  eq << endl;
	}

return 0;
}
