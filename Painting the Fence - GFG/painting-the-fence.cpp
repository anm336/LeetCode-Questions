//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007

class Solution{
    public:
    // long long func(int n, int k, vector<long long> &dp){
    //     if(n==1) return k;
    //     if(n==2){
    //         long long val = (k*(k-1)%mod + k)%mod;
    //         return val;
    //     }
        
    //     if(dp[n] != -1) return dp[n];
        
    //     long long val = ((k-1)*func(n-2, k, dp)%mod) + ((k-1)*func(n-1, k, dp)%mod)%mod;
    //     return dp[n] = val;
    // }
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1);
        dp[1] = k;
        dp[2] = (k*(k-1)%mod + k)%mod;
        
        for(int i=3;i<=n;i++){
            dp[i] = (((k-1)*dp[i-2])%mod + ((k-1)*dp[i-1])%mod)%mod;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends