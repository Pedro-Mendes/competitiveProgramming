/* https://www.urionlinejudge.com.br/repository/UOJ_1472.html */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	int n,d,sum, count,f,max;
	vector<int> pts;
	while(cin >> n){
		sum = 0;
		count = 0;
		pts.resize(n+1);
		pts.clear();
		for(int i =1; i<n+1;i++){
			cin >> d;
			sum += d;
			pts[i] = sum;
		}
		/*cout << "vector: " ;
		for(int i =0; i<n+1;i++){		//for printing vector
			cout << pts[i] << ' ';
		}
		cout << endl;*/
		max = pts[n]/3;
		if(pts[n]%3 == 0){
			for(int i =0; i<n;i++){
				f = ((pts[i]+max)%(pts[n]));
				//cout << "searching: "<< f<< "...";
				if(binary_search(pts.begin(), pts.begin()+n+1, f) && (binary_search(pts.begin(), pts.begin()+n+1, ((f+max)%(pts[n]))))){
					count++;
					//cout << "FOUND" << endl;
				}else{
					//cout << "NOT FOUND" << endl;
				} 
			}
			cout << count/3 << endl;
	}else{

			cout << 0 << endl;
	}

	}
return 0;
}
