//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int i, int j, int n, vector<vector<int>> &Matrix, vector<vector<int>> &dirs, vector<vector<int>> &dp){
        if(i==n-1) return Matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int val = 0;
        for(int k=0;k<dirs.size();k++){
            int newi = i+dirs[k][0];
            int newj = j+dirs[k][1];
            if(newi>=0 && newi<n && newj>=0 && newj<n){
                val = max(val, func(newi, newj, n, Matrix, dirs, dp));
            }
        }
        
        return dp[i][j] = Matrix[i][j] + val;
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dirs = {{1, 0}, {1, -1}, {1, 1}};
        int ans = INT_MIN;
        vector<vector<int>> dp(N+1, vector<int> (N+1, -1));
        for(int i=0;i<N;i++){
            ans = max(ans, func(0, i, N, Matrix, dirs, dp));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends