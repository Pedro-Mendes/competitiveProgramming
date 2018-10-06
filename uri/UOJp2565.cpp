/* https://www.urionlinejudge.com.br/repository/UOJ_2565.html */

#include<bits/stdc++.h>
using namespace std;



int main(){
	double m,mid_value, m1,m2,sum,sum2,media,sumMedia;
	int n;
	vector <double> tubos = {};
	while(cin >> n){
		sum=0;
		sum2=0;
		sumMedia=0;
		tubos.clear();
		for(int i = 0; i<n;i++){
			cin >> m;
			media += m;
			tubos.push_back(m);
		}
		media/=n;
		sort(tubos.begin(), tubos.end());
		if(n%2){ //if impar
			mid_value = tubos[ceil(n/2)];
			for(int i = 0; i<n;i++){
				sum += abs(tubos[i] - mid_value);
				sumMedia += abs(tubos[i] - media);
			}
		}else{ //if par
			m1 = tubos[ceil(n/2)];
			m2 = tubos[floor(n/2)];
			for(int i = 0; i<n;i++){
				sum += abs(tubos[i] - m1);
				sum2 += abs(tubos[i] - m2);
				sumMedia += abs(tubos[i] - media);
			}
			sum = min(sum,sum2);
		}
		sum = min(sum,sumMedia);
		cout << setprecision(2);
		cout << fixed;
		cout << sum << endl;

	}



return 0;
}