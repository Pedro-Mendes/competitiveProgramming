/* https://br.spoj.com/problems/MINHOCA/ */

#include<stdio.h>
int main(){
	int i, j, N, M, m[100][100], sum=0, newsum =0;
	scanf("%d %d",&N,&M);
	for(i=0; i<N;i++){
		for(j=0;j<M;j++){
			m[i][j]=-1;
		}
	}
	for(i=0; i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",&m[i][j]);
		}
	}
	for(i =0; i<N; i++){
		for(j=0;j<M;j++){
			newsum+= m[i][j];
		}
		if(sum < newsum){
			sum = newsum;
			newsum = 0;
		}
		newsum = 0;
	}
newsum = 0;
	for(j =0; j<M; j++){
		for(i=0;i<N;i++){
			newsum+= m[i][j];
		}
		if(sum < newsum){
			sum = newsum;
			newsum = 0;
		}
newsum = 0;
	}
	printf("%d", sum);


return 0;
}
