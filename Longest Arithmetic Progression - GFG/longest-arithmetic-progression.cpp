//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int func(int A[], int index, int d, vector<vector<int>> &dp){
        if(index<0) return 0;
        
        if(dp[index][d] != -1) return dp[index][d];
        int ans = 0;
        
        for(int k=index-1; k>=0; k--){
            if(A[index]-A[k] == d){
                ans = 1+func(A, k, d, dp);
            }
        }
        return dp[index][d] = ans;
    }
    
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2) return n; 
        int ans = 0;
        int maxa = INT_MIN;
        int mina = INT_MAX;
        for(int i=0;i<n;i++){
            maxa = max(maxa, A[i]);
            mina = min(mina, A[i]);
        }
        int diff = maxa - mina;
        vector<vector<int>> dp(n+1, vector<int> (diff+1, -1));
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, 2+func(A, i, A[j]-A[i], dp));
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends