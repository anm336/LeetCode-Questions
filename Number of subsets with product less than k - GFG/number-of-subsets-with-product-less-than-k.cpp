//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int func(int i, int arr[], int prod, int N, int K, vector<vector<int>> &dp){
        if(i==N){
            if(prod<=K) return 1;
            return 0;
        }
        
        if(dp[i][prod]!=-1) return dp[i][prod];
        int take = 0, notake = 0;
        
        int temp = prod*arr[i];
        if(temp<=K){
            take = func(i+1, arr, temp, N, K, dp);
        }
        notake = func(i+1, arr, prod, N, K, dp);
        
        return dp[i][prod] = take + notake;
    }
    
    int numOfSubsets(int arr[], int N, int K) {
        // code here
        vector<vector<int>> dp(N+1, vector<int> (K+1, -1));
        return func(0, arr, 1, N, K, dp)-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends