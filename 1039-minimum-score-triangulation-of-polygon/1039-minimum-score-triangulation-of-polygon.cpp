class Solution {
public:
    int func(int i, int j, vector<int> & values, vector<vector<int>> &dp){
        if(i+1==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans, values[i]*values[j]*values[k] + func(i, k, values, dp) + func(k ,j, values, dp));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0, n-1, values, dp);
    }
};