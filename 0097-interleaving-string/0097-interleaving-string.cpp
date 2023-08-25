class Solution {
public:
    bool func(int i, int j, int k, string s1, string s2, string s3, vector<vector<vector<int>>> &dp){
        if(k==s3.size()) return true;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        bool ans = false;
        if(i<s1.size() && s3[k]==s1[i]) ans|=func(i+1, j, k+1, s1, s2, s3, dp);
        if(j<s2.size() && s3[k]==s2[j]) ans|=func(i, j+1, k+1, s1, s2, s3, dp);
        
        return dp[i][j][k] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int s = s3.size();
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (s+1, -1)));
        if(n+m != s) return false;
        
        return func(0, 0, 0, s1, s2, s3, dp);
    }
};