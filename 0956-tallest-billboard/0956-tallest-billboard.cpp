class Solution {
public:
    int solve(int idx, int dif, vector<int> &rods, vector<vector<int>> &dp){
        if(idx == rods.size()){
            if(dif == 0) return 0;
            return -1e5;
        }

        if(dp[idx][dif + 5000] != -1) return dp[idx][dif + 5000];

        // dif = num1 - nums2
        int ans1 = solve(idx+1, dif, rods, dp);  

        // (nums1 + rods[idx]) - nums2 = (nums1 - nums2) + rods[idx]   = d + rods[idx]
        int ans2 = rods[idx] + solve(idx+1, dif + rods[idx], rods, dp); 

        // nums1 - (nums2 + rods[idx]) = (nums1 - nums2) - rods[idx] = d - rods[idx]
        int ans3 = rods[idx] + solve(idx+1, dif - rods[idx], rods, dp);  

        return dp[idx][dif + 5000] = max(ans1, max(ans2, ans3));
    }
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(20, vector<int> (10001, -1));
        int ans = solve(0,0,rods,dp)/2; 
        return ans;
    }
};