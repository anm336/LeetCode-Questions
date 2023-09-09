class Solution {
public:
    int func(int target, vector<int> &nums, vector<int> &dp){
        if(target==0) return 1;        
        
        if(dp[target]!=-1) return dp[target];
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(target-nums[i]>=0) ans+=func(target-nums[i], nums, dp);
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, -1);
        
        return func(target, nums, dp);
    }
};