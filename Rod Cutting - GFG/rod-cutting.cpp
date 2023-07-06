//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int func(int price[], int n, int len, vector<int> &dp){
        if(len==0) return 0;
        
        if(dp[len]!= -1) return dp[len];
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(len-i>=0){
                ans = max(ans, price[i-1] + func(price, n, len-i, dp));
            }
        }
        
        return dp[len] = ans;
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1, -1);
        return func(price, n, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends