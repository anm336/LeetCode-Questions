class Solution {
public:
    bool func(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target<0) return false;
        if(i==nums.size()){
            if(target==0) return true;
            return false;
        }
        if(dp[i][target] != -1) return (dp[i][target]==0) ? false: true;
        
        bool inc = func(i+1, target-nums[i], nums, dp);
        bool exc = func(i+1, target, nums, dp);
        
        dp[i][target] = (inc||exc) ? 1 : 0;
        return (inc||exc);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
        return func(0, target, nums, dp);
    }
};