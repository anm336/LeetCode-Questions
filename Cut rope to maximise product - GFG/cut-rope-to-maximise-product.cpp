//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long func(int len, vector<long long> &dp){
        if(len==0) return 1;
        
        if(dp[len] != -1) return dp[len];
        long long ans = 1;
        for(int i=1;i<=len;i++){
            ans = max(ans, i*func(len-i, dp));
        }
        
        return dp[len] = ans;
    }
    
    long long maxProduct(int n) {
        // code here
        if(n == 2 || n == 3 || n==1) return (n-1);
        vector<long long> dp(n+1, -1);
        return func(n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.maxProduct(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends