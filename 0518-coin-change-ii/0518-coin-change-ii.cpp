class Solution {
public:
    
    int func(int amount, int i, vector<int> &coins, vector<vector<long long int>> &dp){
        if(amount == 0) return 1;
        if(amount<0 || i<0) return 0;
        
        if(dp[amount][i] != -1) return dp[amount][i];
        int take = 0;
        if(amount-coins[i] >= 0) take = func(amount-coins[i], i, coins, dp);
        
        int nottake = func(amount, i-1, coins, dp);
        
        return dp[amount][i] = take+nottake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long int>> dp(amount+1, vector<long long int>(n+1, -1));
        
        return func(amount, n-1, coins, dp);
    }
};