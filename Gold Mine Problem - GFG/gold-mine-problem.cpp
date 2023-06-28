//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int func(int i, int j, vector<vector<int>> &M, vector<vector<int>> &dp, int n, int m, vector<vector<int>> &dirs){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int val = 0;
        for(int k=0;k<dirs.size();k++){
            int newi = i+dirs[k][0];
            int newj = j+dirs[k][1];
            val = max(val, func(newi, newj, M, dp, n, m, dirs));
        }
        
        return dp[i][j] = M[i][j]+val;
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<int>> dirs = {{1, 1}, {0, 1}, {-1, 1}};
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int val = func(i, 0, M, dp, n, m, dirs);
            //cout<<val<<endl;
            ans = max(ans, val);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends