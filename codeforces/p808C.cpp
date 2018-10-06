/* http://codeforces.com/problemset/problem/808/C */

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <float> result;
    vector <float> vol;
    pair <int,int> p;
    priority_queue < pair<int,int> > pq;
    float n,x,w,n_i, minVol,answ;
    cin >> n >>w;
    result.clear();
    vol.clear();
    for(int i = 0; i<n;i++){
		  cin >> n_i;
		  //cout << "n_i/2 = " << n_i/2 << endl;
		  minVol = ceil(n_i/2);
		 // cout << "minVol = " << minVol << endl;
		  result.push_back(minVol);
		  pq.push(make_pair(n_i,i)); //pair = (volume, index) 
		  w-= minVol;
		  if(w<0){
		      cout << -1 << endl;
		      return 0;
		  }
		}
		while(!pq.empty() && w>0){
    	p = pq.top();
    	//cout << "p.first = " << p.first <<  " p.second = " << p.second << endl;
    	pq.pop();
    	if(w+result[p.second] <= p.first){
    		result[p.second]+=w;
    		w=0; // 0 + result[i] always will be less then its volume
    		break;
    	}else{
    		w-= p.first - result[p.second]; 
    		result[p.second] = p.first;
    		if(w<0){
		      cout << -1 << endl;
		      return 0;
    		}
    	}
    }
    if(w!=0){
			cout << -1 << endl;
			return 0;
    }else{
    	cout << result[0];
    	for(int i = 1; i<n;i++){
    		cout << " " << result[i];
    	}
    	cout << endl;
    }
	

return 0;
}