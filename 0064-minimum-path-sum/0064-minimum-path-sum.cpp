class Solution {
public:
    int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m){
        if(i==n-1 && j==m-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = INT_MAX;
        int right = INT_MAX;
        if(j+1<=m-1) right = grid[i][j] + func(i, j+1, grid, dp, n, m);
        if(i+1<=n-1) down = grid[i][j] + func(i+1, j, grid, dp, n, m);
        
        return dp[i][j] = min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return func(0, 0, grid, dp, n, m);
    }
};