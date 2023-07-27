//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool func(int i, int j, string wild, string pattern, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0) {
            while(i>=0){
                if(wild[i] != '*') return false;
                i--;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans;
        if(pattern[j] == wild[i] || wild[i]=='?') ans = func(i-1, j-1, wild, pattern, dp);
        else if(wild[i]=='*'){
            ans = (func(i-1, j, wild, pattern, dp) || func(i, j-1, wild, pattern, dp));
        }
        else ans = false;
        
        return dp[i][j] = ans;
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size();
        int m = pattern.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return func(n-1, m-1, wild, pattern, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends