class Solution {
public:
    int func(vector<int>& arr, map<pair<int, int>, int> &maxvals, int start, int end, vector<vector<int>> &dp){
        if(start==end) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = INT_MAX;
        for(int i=start; i<end; i++){
            ans = min(ans, maxvals[{start, i}]*maxvals[{i+1, end}] + func(arr, maxvals, start, i, dp) + func(arr, maxvals, i+1, end, dp));
        }
        return dp[start][end] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxvals;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            maxvals[{i,i}] = arr[i];
            for(int j=i+1;j<n;j++){
                maxvals[{i,j}] = max(arr[j], maxvals[{i, j-1}]);
            }
        }
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return func(arr, maxvals, 0, n-1, dp);
        return 0;
    }
};