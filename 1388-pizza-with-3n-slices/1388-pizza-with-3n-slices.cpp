class Solution {
public:
    int func(vector<int> &slices , int k, int sindex, int eindex, vector<vector<int>> &dp){
        if(k==0 || sindex > eindex) return 0;
        
        if(dp[sindex][k]!=-1) return dp[sindex][k];
        int take = slices[sindex] + func(slices, k-1, sindex+2, eindex, dp);
        int notake = 0 + func(slices, k, sindex+1, eindex, dp);
        
        return dp[sindex][k] = max(take, notake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int> ((k/3)+1, -1));
        vector<vector<int>> dp2(k, vector<int> ((k/3)+1, -1));
        int ans1 = func(slices, k/3, 0, k-2, dp1);
        int ans2 = func(slices, k/3, 1, k-1, dp2);
        return max(ans1, ans2);
    }
};