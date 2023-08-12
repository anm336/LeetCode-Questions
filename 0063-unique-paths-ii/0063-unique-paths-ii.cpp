class Solution {
public:
    int func(int i, int j, int xtar, int ytar, vector<vector<int>> &dirs, vector<vector<int>> & obstacleGrid, vector<vector<int>> &dp){
        if(i==xtar && j==ytar){
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        for(int k=0;k<dirs.size();k++){
            int newx = i+dirs[k][0];
            int newy = j+dirs[k][1];
            
            if(newx>=0 && newx<=xtar && newy>=0 && newy<=ytar && obstacleGrid[newx][newy]==0){
                ans+=func(newx, newy, xtar, ytar, dirs, obstacleGrid, dp);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}};
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) return 0;
        if(n==1 && m==1){
            return 1;
        }
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return func(0, 0, n-1, m-1, dirs, obstacleGrid, dp);
    }
};