//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    long long func(int M, int N, int target, vector<vector<long long>> &dp){
        if(target<0) return 0;
        if(N!=0 && target==0) return 0;
        if(N==0){
            if(target==0) return 1;
            else return 0;
        }
        
        if(dp[target][N] != -1) return dp[target][N];
        
        long long ans = 0;
        for(int i=1;i<=M;i++){
            ans += func(M, N-1, target-i, dp);
        }
        
        return dp[target][N] = ans;
    }
    
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>> dp(X+1, vector<long long> (N+1, -1));
        return func(M, N, X, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends