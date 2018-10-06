/* https://uva.onlinejudge.org/external/103/p10341.pdf */

#include<bits/stdc++.h>
using namespace std;

#define eu 2.718281828
#define limit 0.00000000001 
double p,q,r,s,t,u,eq,a,b,c,fa,fb,fc;

double f(double x){
	eq = p/pow(eu,x);
	eq+= q * sin(x);
	eq+= r * cos(x);
	eq+= s * tan(x);
	eq+= t * x * x;
	eq+= u;
	return eq;
}

int main(){
	double maxIt = (1/limit), answ = 666;
	maxIt = ceil(log(maxIt));
	while(cin >> p >> q >> r >> s >> t >> u){
		a = 0;
		b = 1;
		answ = 666;
		if(f(0) * f(1) > 0){	//no possible solution
			cout << "No solution\n";
		}else{
			while(fabs(b-a)>=limit){
				c = (a + b)/2;
				fc = f(c);
				//cout << "c = " << c << endl;
				fa = f(a);
				fb = (b);
				if(fc == 0){	//solution found
					break;
				}
				if(fc * fa > 0){
					a = c;
				}else{
					b = c;
				}
			}
				cout << setprecision(4) << fixed << c << endl;
			

		}


	}
return 0;
}
