class Solution {
public:
    
    int func(unordered_map<int,int> &f, int i, int bj, int a, int b, int x, vector<vector<int>> &dp){
        if(i>6000 || i<0 || bj>=2 || f.find(i)!=f.end()) return 1e9;
        
        if(i==x) return 0;
        
        if(dp[i][bj] != -1) return dp[i][bj];
        
        dp[i][bj] = 1+func(f, i+a, 0, a, b, x, dp);
        dp[i][bj] = min(dp[i][bj],1+func(f, i-b, bj+1, a, b, x, dp));
        
        return dp[i][bj];
    }
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,int> f;
        vector<vector<int>> dp(6001, vector<int>(2, -1));
        for(int i=0;i<forbidden.size();i++){
            f[forbidden[i]]++;
        }
        
        int ans = func(f, 0, 0, a, b, x, dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};