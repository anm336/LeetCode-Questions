class Solution {
public:
    int ans = 0;
    
    int func(int i, int diff, vector<int> &nums, vector<unordered_map<int,int>> &dp){
        if(i<0) return 0;
        
        if(dp[i].count(diff)) return dp[i][diff];
        int ans = 0;
        for(int k=i-1;k>=0;k--){
            if(nums[i]-nums[k] == diff) ans = max(ans, 1+func(k, diff, nums, dp));
        }
        
        return dp[i][diff] = ans; 
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        //Memoised Solution
//         vector<unordered_map<int,int>> dp(n+1);
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int diff = nums[j]-nums[i];
//                 ans = max(ans, 2+func(i, diff, nums, dp));
//             }
//         }
        
//         return ans;
        
        int ans=0;
        vector<unordered_map<int,int>> dp(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int cnt=1;
                // check if answer already exists
                if(dp[j].count(diff))
                  cnt=dp[j][diff];
                
                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};