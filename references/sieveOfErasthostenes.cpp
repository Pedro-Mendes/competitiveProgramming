#include<bits/stdc++.h>
using namespace std;

int erasthostenesSieve(int n) {
    vector<bool> primes(n+1,true);
    int numberOfPrimes = 0;
    for (int i = 2; i*i <= n; i++) {
        if(primes[i]) {
            for (int j = i*i; j <= n; j+=i)
                primes[j] = false;
        }
    }
    for (int p=2; p<=n; p++) {
        if (primes[p]) {
            numberOfPrimes++;
        } 
    } 
    return numberOfPrimes;
}

int main() {
    int n;
    cin >> n;
    cout << erasthostenesSieve(n) << endl;
}