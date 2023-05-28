class Solution {
public:
    int func(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m && j==n) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int way1 = 0;
        int way2 = 0;
        if(i+1<=m) way1 = func(i+1, j, m, n, dp);
        if(j+1<=n) way2 = func(i, j+1, m, n, dp);
        
        return dp[i][j] = way1+way2;
    }
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        
        func(1, 1, m, n, dp);
        
        return dp[1][1];
    }
};