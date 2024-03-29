//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{

	public:
	int func(int i, int target, int n, int arr[], vector<vector<int>> &dp){
	    if(i==n){
	        if(target == 0) return 1;
	        else return 0;
	    }
	    if(dp[i][target] != -1) return dp[i][target];
	    
	    int inc = 0;
	    if(target-arr[i]>=0) inc = func(i+1, target-arr[i], n, arr, dp);
	    int exc = func(i+1, target, n, arr, dp);
	    
	    return dp[i][target] = (inc+exc)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return func(0, sum, n, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends