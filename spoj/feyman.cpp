/* https://br.spoj.com/problems/FEYNMAN/ */

#include<stdio.h>
int main(){
	int N, sum = 0, aux =0, aux2 = 0, i;
	scanf("%d", &N);
	while(N!=0){
		sum = 0;
		aux = N;
		while(aux != 0){
			sum += aux * aux;
			aux --;
			
		}
		printf("%d\n", sum);		
		scanf("%d", &N);
	}

return 0;
}
