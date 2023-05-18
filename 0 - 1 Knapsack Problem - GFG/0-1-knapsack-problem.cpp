//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int fun(int wt[], int val[], int remcap, int index, vector<vector<int>> &dp){
        if(index==0){
            if(wt[0]<=remcap) return val[0];
            else return 0;
        }
        if(dp[index][remcap] != -1) return dp[index][remcap];
        
        int inc = 0;
        if(wt[index]<=remcap) inc = val[index] + fun(wt, val, remcap-wt[index], index-1, dp);
        int exc = 0 + fun(wt, val, remcap, index-1, dp);
        return dp[index][remcap] = max(inc, exc);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int> (W+1, -1));
       return fun(wt, val, W, n-1, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends