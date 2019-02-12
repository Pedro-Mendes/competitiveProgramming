/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
git@Pedro-Mendes*/



/*Bruteforce gives time out*/
class Solution {
public:
    int calculate(vector<int>& prices, int start) {         //[7,1,5,3,6,4]
        if(start >= prices.size())
            return 0;
        int profit, maxProfit, max = 0;
        for (int j = start; j < prices.size(); j++) {
            maxProfit = 0;
            for (int i = j+1; i < prices.size(); i++) {
                if(prices[j] < prices[i]){
                    profit = calculate(prices, i+1) + prices[i]-prices[j];
                    if(profit > maxProfit)
                        maxProfit = profit;
                }
            }
            if(maxProfit > max)
                max = maxProfit;
        }
        return max;
    }
    
    int maxProfit(vector<int>& prices) {
        return calculate(prices, 0);
    }
};

/*Simple one pass
Since we cannot have more than one transaction at the same time,
the maximum profit will be given by the sums of consecutives (non-
negative) sums:
10 -----1 ------60-----40----1000
a ----- b ------c -----d-----e

maxProfit = c-b + e-d = 59 + 960
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit += max(prices[i]-prices[i-1],0);
        }
        return profit;
    }
};



