class Solution {
public:
    int func(vector<int> &prices, int fee, int i, int buy, vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int price = 0;
        if(buy){
            price = max(-prices[i] + func(prices, fee, i+1, 0, dp), 0 + func(prices, fee, i+1, 1, dp));
        }
        else{
            price = max(prices[i] - fee + func(prices, fee, i+1, 1, dp), 0 + func(prices, fee, i+1, 0, dp));
        }
        
        return dp[i][buy] = price;
        
    }
    
    int tabulation(vector<int> &prices, int fee, vector<vector<int>> &dp){
        dp[prices.size()][0] = 0;
        dp[prices.size()][1] = 0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int price = 0;
                if(j){
                    price = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
                }
                else{
                    price = max(prices[i] - fee + dp[i+1][1], 0 + dp[i+1][0]);
                }
                dp[i][j] = price;
            }
        }
        return dp[0][1];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2));
        return tabulation(prices, fee, dp);
        //return func(prices, fee, 0, 1, dp);
    }
};