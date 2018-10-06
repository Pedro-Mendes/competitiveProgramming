/* https://br.spoj.com/problems/VARETAS/ */

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
	for(int i =0; i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int binarySearch(vector<int> vector, int min, int max, int key){
	if(max < min){return -1;}
	else{
		int mid = floor((max+min)/2);		
		if(vector[mid] > key){return binarySearch(vector, min, mid-1, key);}
		else if(vector[mid] < key){return binarySearch(vector, mid+1, max, key);}
		else{return mid;}				//or return true
	}
} 

int main(){
	int t,c,n,sum,prev;
	cin >> t;
	vector<int> ret;
	while(t!=0){
		ret.clear();
		sum = 0;
		for(int i =0; i<t;i++){
			cin >> c >> n;
			ret.push_back(n);
		}
		sort(ret.begin(),ret.end());
		

		for(int i =t-1; i>=0;i--){
			//printVector(ret);
			//cout << "searching index "<< i << ": element " << ret[i] << endl;
			if(ret[i]%4 == 0){
				sum += ret[i]/4;
				ret[i] = 0;
			}else{
				if(ret[i]>4){
					sum += floor(ret[i]/4);
					ret[i] = ret[i]%4;
				}
				if(ret[i]>1){
					for(int j =i-1; j>=0;j--){
						if((ret[i] == 3 && ret[j] == 3) || (ret[i] == 3 && ret[j]== 2) || (ret[i] == 2 && ret[j] == 2)){
							sum++;
							ret[i] = ret[i] - 2;
							ret[j] = ret[j] - 2;
						}						

					}
				
				}


			}



		}
		sort(ret.begin(),ret.end());

		for(int i =t-1; i>=0;i--){
			//printVector(ret);
			//cout << "searching index "<< i << ": element " << ret[i] << endl;
			if(ret[i]%4 == 0){
				sum += ret[i]/4;
				ret[i] = 0;
			}else{
				if(ret[i]>4){
					sum += floor(ret[i]/4);
					ret[i] = ret[i]%4;
				}
				if(ret[i]>1){
					for(int j =i-1; j>=0;j--){
						if((ret[i] == 3 && ret[j] == 3) || (ret[i] == 3 && ret[j]== 2) || (ret[i] == 2 && ret[j] == 2)){
							sum++;
							ret[i] = ret[i] - 2;
							ret[j] = ret[j] - 2;
						}						

					}
				
				}


			}



		}
		cout << sum << endl;
		cin >> t;
	}

return 0;
}
