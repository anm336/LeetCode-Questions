//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int func(int i, int j, string s, string t, int n, int m, vector<vector<int>> &dp){
        //Delete all remaining characters of the string part left
        if(i==n) return m-j;
        if(j==m) return n-i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        //If match
        if(s[i]==t[j]) return dp[i][j] = func(i+1, j+1, s, t, n, m, dp);
        else{
            //Otherwise 3 choices, make operations on first string;
            //Delete, Insert or Replace
            int del = 1+func(i+1, j, s, t, n, m, dp);
            int ins = 1+func(i, j+1, s, t, n, m, dp);
            int repl = 1+func(i+1, j+1, s, t, n, m, dp);
            return dp[i][j] = min(del, min(ins, repl));
        }
        
    }
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return func(0, 0, s, t, n, m, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends