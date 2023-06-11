class Solution {
public:
    int func(vector<int> &coins, int rem, vector<int> &dp){
        if(rem == 0) return 0;
        
        if(dp[rem] != -1) return dp[rem];
        int temp = 1e9;
        for(int i=0;i<coins.size();i++){
            if(rem-coins[i] >= 0) temp = min(temp, 1+func(coins, rem-coins[i], dp));
        }
        
        return dp[rem] = temp;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        
        int val = func(coins, amount, dp);
        return val >= 1e9 ? -1 : val;
    }
};