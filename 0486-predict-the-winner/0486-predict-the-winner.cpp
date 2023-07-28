class Solution {
public:
    int func(int left, int right, vector<int> &nums, vector<vector<int>> &dp){
        if(left == right) return nums[left];
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int lScore = nums[left] - func(left+1, right, nums, dp);
        int rScore = nums[right] - func(left, right-1, nums, dp);
        
        return dp[left][right] = max(lScore, rScore);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return func(0, n-1, nums, dp)>=0;
    }
};