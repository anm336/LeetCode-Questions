class Solution {
public:
//     int func(int i, int prev, vector<int> &arr, int diff, vector<vector<int>> &dp){
//         if(i==arr.size()) return 0;
        
//         if(dp[i][prev+1] != -1) return dp[i][prev+1];
//         int take = 0;
//         if(prev==-1 || arr[i]-arr[prev] == diff){
//             take = 1+func(i+1, i, arr, diff, dp);
//         }
//         int notake = func(i+1, prev, arr, diff, dp);
        
//         return dp[i][prev+1] = max(take, notake);
//     }
//     Gives TLE
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        
        unordered_map<int, int> m;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int temp = arr[i] - difference;
            int toAdd = 0;
            if(m.count(temp)) toAdd = m[temp];
            
            m[arr[i]] = 1+toAdd;
            ans = max(ans, 1+toAdd);
        }
        
        return ans;
        
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return func(0, -1, arr, difference, dp);
    }
};