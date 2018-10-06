/* http://codeforces.com/problemset/problem/808/B */

#include<bits/stdc++.h>
using namespace std;
	long long int n, a;
	double dynamicSum = 0;
	double finalSum = 0;
	int k,c=0, prev,i;
int main(){
	cin >> n >> k;
	if(k!=1){
		double v[300000];
		for(i =0; i< k;i++){
			cin >> a;
			v[i] = (double)a/(n-k+1);
			dynamicSum += v[i];
		}
		finalSum = dynamicSum;
		for(i = k; i<n; i++){
			cin >> a;
			v[i] = (double)a/(n-k+1);
			dynamicSum+= v[i]-v[i-k]; 
			finalSum += dynamicSum;
		}
	}else{
		for(i = 0; i<n;i++){
			cin >> a;
			finalSum+=(double)a/(n-k+1);
		}
	}
	//dynamicSum= (double)finalSum/(n-k+1);
	cout.precision(10);
	cout << fixed << finalSum << endl;
return 0;
}
