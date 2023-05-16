class Solution {
public:
    int func(vector<int>& prices, int i, int buy, int t, vector<vector<vector<int>>> &dp){
        if(t==0) return 0;
        if(i==prices.size()) return 0;
        
        if(dp[i][buy][t] != -1) return dp[i][buy][t];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + func(prices, i+1, 0, t, dp) , 0 + func(prices, i+1, 1, t, dp));
        }
        
        else{
            profit = max(prices[i] + func(prices, i+1, 1, t-1, dp) , 0 + func(prices, i+1, 0, t, dp));
        }
        
        return dp[i][buy][t] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return func(prices, 0, 1, 2, dp);
    }
};