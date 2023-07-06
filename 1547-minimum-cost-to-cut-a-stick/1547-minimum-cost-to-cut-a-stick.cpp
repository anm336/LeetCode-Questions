class Solution {
public:
//     int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
//         if(i>j) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         int mini = INT_MAX;
//         for(int k=i;k<=j;k++){
//             int val = (cuts[j+1]-cuts[i-1]) + func(i, k-1, cuts, dp) + func(k+1, j, cuts, dp);
//             mini = min(mini, val);
//         }
        
//         return dp[i][j] = mini;
//     }
    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
        for(int i=c; i>=1; i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int mini = INT_MAX;
                for(int k=i;k<=j;k++){
                    int val = (cuts[j+1]-cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, val);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][c];
        // return func(1, c, cuts, dp);
    }
};