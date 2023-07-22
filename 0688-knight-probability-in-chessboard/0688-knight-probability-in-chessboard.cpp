class Solution {
public:
    bool onBoard(int n, int x, int y){
        if(x>=n || y>=n || x<0 || y<0) return false;
        return true;
    }
    
    double func(int i, int j, int k, int n, vector<vector<int>> &dirs, vector<vector<vector<double>>> &dp){
        if(!onBoard(n, i, j)) return 0;
        if(k==0) return 1;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        double sum = 0;
        for(int a=0; a<dirs.size(); a++){
            sum+=func(i+dirs[a][0], j+dirs[a][1], k-1, n, dirs, dp);
        }
        
        sum = sum/8;
        return dp[i][j][k] = sum;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>> (n+1, vector<double>(k+1, -1)));
        return func(row, column, k, n, dirs, dp);
    }
};