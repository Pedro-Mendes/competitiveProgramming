/* https://www.urionlinejudge.com.br/repository/UOJ_1709.html */

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,pos=1,answ=0;
  cin >> n;
  bool done = false;
  while(!done){
    if (pos!=n){
      if (2*pos <= n) {
        pos *=2;
      }else{
        pos = (2*pos)-(n+1);
      }
    }else{
      answ *=2;
      break;
    }
    answ++;
    if (pos == (n/2)+1) {
      done = true;
      answ++;
    }
  }
  cout << answ << endl;





return 0;
}
