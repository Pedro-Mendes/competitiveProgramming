/* https://br.spoj.com/problems/BOLSA/ */

#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>


using namespace std;

int main(){
	int n;
	char x;
	double value, aux, count;
	cin >> n;
	priority_queue <double> buyers; 
	priority_queue<double, vector<double>, greater<double> > sellers;	//top always the smaller number
	while(n!=0){
		count = 0; 
		buyers = priority_queue <double>();
		sellers = priority_queue<double, vector<double>, greater<double> >(); 
		for(int i=0; i<n;i++){
			cin >> x;
			cin >> value;
			if(x == 'C'){	//if this is a buyer, check the sellers queue for the least expensive action, which will generate more profit to the stocks market
										//if not found, push into the buyers queue
				if(!sellers.empty()){
					aux = value - sellers.top();
					if(aux > 0 || aux == 0){
						count += aux;
						sellers.pop();
					}else{
						buyers.push(value);
					}
				}else{
					buyers.push(value);
				}	
			
			}else{	//else this is a seller, check the buyers queue to verify the highest bidder and sell it to him
							//if not found, push into the sellers queue
				if(!buyers.empty()){
					aux = buyers.top() - value;
					if(aux > 0 || aux == 0){
						count += aux;
						buyers.pop();
					}else{
						sellers.push(value);	
					}
				}else{
					sellers.push(value);
				}
			
			
			}
		}
		cout << setprecision(2) << fixed << count <<endl;
		cin >>n;
	}

return 0;
}
