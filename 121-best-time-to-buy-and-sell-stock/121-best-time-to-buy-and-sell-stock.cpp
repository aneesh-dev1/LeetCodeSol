class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp = prices[0];
        int profit = 0;
        for(int i =0 ;i<prices.size();i++){
            cp = min(cp,prices[i]);
            profit = max(profit,prices[i]-cp);
        }
        return profit;
    }
};