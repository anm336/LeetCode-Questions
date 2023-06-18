#define mod 1000000007
class Solution {
public:
    int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m){
        //Base Condition
        if(dp[i][j] != 0) return dp[i][j];
        
        int val = 1;
        
        //up
        if(i-1>=0 && grid[i-1][j] > grid[i][j]){
            val = (val+func(i-1, j, grid, dp, n, m))%mod;
        }
        //left
        if(j-1>=0 && grid[i][j-1] > grid[i][j]){
            val = (val+func(i, j-1, grid, dp, n, m))%mod;
        }
        //down
        if(i+1<n && grid[i+1][j] > grid[i][j]){
            val = (val+func(i+1, j, grid, dp, n, m))%mod;
        }
        //right
        if(j+1<m && grid[i][j+1] > grid[i][j]){
            val = (val+func(i, j+1, grid, dp, n, m))%mod;
        }
        
        return dp[i][j] = val;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = (ans+func(i,j,grid,dp,n,m))%mod;
            }
        }
        
        return ans;
    }
};