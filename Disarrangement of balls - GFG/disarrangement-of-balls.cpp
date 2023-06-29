//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define mod 1000000007

class Solution{
public:
    long long int disarrange(int N){
        // code here
        long long int prev2 = 0;
        long long int prev1 = 1;
        if(N==1) return prev2;
        if(N==2) return prev1;
        
        for(int i=3;i<=N;i++){
            long long int val = (((i-1)*prev1)%mod + ((i-1)*prev2)%mod)%mod;
            prev2 = prev1;
            prev1 = val;
        }
        
        return prev1;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends