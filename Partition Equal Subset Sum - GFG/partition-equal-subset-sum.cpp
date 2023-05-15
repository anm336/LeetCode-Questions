//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int func(int N, int arr[], int index, int target, vector<vector<int>> &dp){
        if(target<0) return 0;
        if(index==0){
            if(target==0) return 1;
            else return 0;
        }
        
        if(dp[index][target] != -1) return dp[index][target];
        int inc = func(N, arr, index-1, target-arr[index], dp);
        int exc = func(N, arr, index-1, target, dp);
        
        if(inc==1 || exc==1) return dp[index][target] = 1;
        else return dp[index][target] = 0;
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2!=0) return 0;
        else{
            sum/=2;
            vector<vector<int>> dp(N+1, vector<int> (sum+1, -1));
            return func(N, arr, N-1, sum, dp);
        }
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends