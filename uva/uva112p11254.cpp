/* https://uva.onlinejudge.org/external/112/p11254.pdf */

#include <stdio.h>
#include <math.h>
int main(){
	long long N, d,a;
	scanf("%lld",&N);
	while(N!=-1){
		for(d = (int) sqrt(2* N); d>0; d--){
			if (((((2 * N) + d - (d*d))%(2*d)) == 0)){
				a = (int) ((2 * N) + d - (d*d))/(2*d);
				if(a>0){				
					printf("%lld = %lld + ... + %lld\n", N, a, a+(d-1));
					break;			
				}
			}
		}
		scanf("%lld",&N);
	
	}
return 0;
}
