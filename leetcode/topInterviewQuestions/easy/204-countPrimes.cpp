/* https://leetcode.com/problems/count-primes/
git@Pedro-Mendes */

/*O(n) solution (both time and space) using Erasthostenes Sieve*/
class Solution {
public:
    int erasthostenesSieve(int n) {
        vector<bool> primes(n+1,true);
        int numberOfPrimes = 0;
        for (int i = 2; i*i < n; i++) {
            if(primes[i]) {
                for (int j = i*i; j <= n; j+=i)
                    primes[j] = false;
            }
        }
        for (int p=2; p<n; p++) {
            if (primes[p]) {
                numberOfPrimes++;
            } 
        } 
        return numberOfPrimes;
    }
    int countPrimes(int n) {
        return erasthostenesSieve(n);
    }
};