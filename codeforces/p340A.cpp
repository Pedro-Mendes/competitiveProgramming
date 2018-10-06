/* http://codeforces.com/problemset/problem/340/A */

#include<bits/stdc++.h>
using namespace std;

int mmc(int num1, int num2) {

    int mmc, aux, i;
    if(num1 == 1 || num2 == 1){
      return num1 * num2;
    }else if (num1 == num2){
      return num1;
    }else{
      for (i = 2; i <= num2; i++) {
          aux = num1 * i;
          if ((aux % num2) == 0) {
              mmc = aux;
              i = num2 + 1;
          }
      }
      return mmc;
     }
}

int main(){
  int x,y;
	unsigned long long a,b,m,l_lim, r_lim,answ;
	cin >> x >> y >> a >> b;
	m = mmc(x,y);
	if(a == b){
	  if(a%m){
	    cout << 0 << endl;
	    return 0;
	  }else{
	    cout << 1 << endl;
	    return 0;
	  }
	}
	if (m > b)
	{
		answ = 0;
	}else if (m == b)
	{
		answ = 1;
	}else{
	  r_lim = (b/m);
    r_lim *= m;
    if(a%m == 0){
      answ = r_lim/m - (a/m) + 1; /*   a/m é o numero de vezes q m aparece antes de a*/
    }else{
      answ = r_lim/m - (a/m);
    }
  }
	cout << answ << endl;

return 0;
}