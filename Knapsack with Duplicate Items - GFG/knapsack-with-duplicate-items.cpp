//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int func(int N, int rem, int val[], int wt[], vector<int> &dp){
        if(rem==0) return 0;
        
        if(dp[rem]!=-1) return dp[rem];
        
        int profit = 0;
        for(int i=0;i<N;i++){
            if(rem-wt[i]>=0) profit = max(profit, val[i] + func(N, rem-wt[i], val, wt, dp));
        }
        
        return dp[rem] = profit;
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> dp(W+1, -1);
        return func(N, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends