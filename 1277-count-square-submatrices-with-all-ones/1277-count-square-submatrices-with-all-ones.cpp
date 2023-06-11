class Solution {
public:
    int func(vector<vector<int>> &matrix, vector<vector<int>> & dp, int i, int j){
        if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j] == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int right = func(matrix, dp, i+1, j);
        int down = func(matrix, dp, i, j+1);
        int diag = func(matrix, dp, i+1, j+1);
        
        int val = 1+min(right, min(down, diag));
        return dp[i][j] = val;     
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=func(matrix, dp, i, j);
            }
        }
        
        return ans;
    }
};