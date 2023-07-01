//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int i, int n, int A[], int last, vector<vector<int>> &dp){
        if(i==n) return 0;
        
        if(dp[i][last+1] != -1) return dp[i][last+1];
        int take = 0;
        if(last == -1 || abs(A[i]-A[last])==1){
            take = 1+func(i+1, n, A, i, dp);
        }
        int notake = 0 + func(i+1, n, A, last, dp);
        
        return dp[i][last+1] = max(take, notake);
    }
    
    int longestSubsequence(int n, int A[])
    {
        // code here
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return func(0, n, A, -1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends