class Solution {
public:
    
    int func(vector<vector<char>> &matrix, int i, int j, vector<vector<int>> &dp, int &ans){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = func(matrix, i+1, j, dp, ans);
        int down = func(matrix, i, j+1, dp, ans);
        int diag = func(matrix, i+1, j+1, dp, ans);
        
        if(matrix[i][j] == '1'){
            dp[i][j] = 1+min(right, min(down, diag));
            ans = max(ans, dp[i][j]*dp[i][j]);
            return dp[i][j];
        }
        else return dp[i][j] = 0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        func(matrix, 0, 0, dp, ans);
        
        return ans;
    }
};