//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define mod 1000000007
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int prev1 = 1;
        int prev2 = 1;
        if(n==1 || n==2) return 1;
        
        for(int i=3; i<=n;i++){
            int temp = (prev1+prev2)%mod;
            prev2 = prev1;
            prev1 = temp;
        }
        
        return prev1;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends