//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int func(int i, int canTake, int n, vector<int> &a, vector<vector<int>> &dp){
      if(i==n) return 0;
      
      if(dp[i][canTake] != -1) return dp[i][canTake];
      
      int take = 0;
      if(canTake>0){
          take = a[i] + func(i+1, canTake-1, n, a, dp);
      }
      int notake = 0 + func(i+1, 2, n, a, dp);
      
      return dp[i][canTake] = max(take, notake);
  }
  
  int findMaxSum(vector<int>& a){
      //Code Here
      int n = a.size();
      vector<vector<int>> dp(n+1, vector<int> (3, -1));
      return func(0, 2, n, a, dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends