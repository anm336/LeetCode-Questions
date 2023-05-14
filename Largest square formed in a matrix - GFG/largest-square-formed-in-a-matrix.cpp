//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maxans = 0;
    int func(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = func(i,j+1,mat,dp);
        int down = func(i+1,j,mat,dp);
        int diag = func(i+1,j+1,mat,dp);
        
        if(mat[i][j]==1){
            dp[i][j] = 1 + min(right, min(down, diag));
            maxans = max(maxans, dp[i][j]);
            return dp[i][j];
        }
        else return dp[i][j] = 0;
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n , vector<int> (m,-1));
        func(0 , 0, mat, dp);
        return maxans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends