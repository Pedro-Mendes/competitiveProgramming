/* https://uva.onlinejudge.org/external/8/p825.pdf */

#include<bits/stdc++.h>
using namespace std;
int dp[10100][10100];


int solve(int y, int x){
    if(y >= 0 && x>=0){
        if(dp[y][x] == -1){
            dp[y][x] = 0;
            dp[y][x] += solve(y-1,x);
            dp[y][x] += solve(y,x-1);
        }
        return dp[y][x];
    }
    return 0;
}



int main(){
    int w, n, x,t ,numbah,line;
    string str;
    stringstream ss;
    cin >> t;
    getline(cin,str);
    for (int j = 0; j < t; ++j){
        cin >> w >> n;
        getline(cin,str);
        //cout << "w = " << w << endl;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i<w; i++){
            //cout << "i = " << i << endl;
            getline(cin,str);
            //cout << "string :" << str << endl;
            ss.clear();
            ss << str;
            ss >> line;
            //cout << line << endl;
            while(ss >> numbah){
                dp[line-1][numbah-1] = 0; //encontrei buraco
                //cout << numbah << endl;
            }  
        }
        dp[0][0] = 1;
        cout << solve(w-1,n-1) << endl;
        if(j<t-1){
            cout << endl;
        }
    }
    
    
return 0;
}

