//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i, int j, string str){
        while(i<j){
            if(str[i++]!=str[j--]) return false;
        }
        
        return true;
    }
    
    int func(int i, int n, string s, vector<int> &dp){
        if(isPalindrome(i, n-1, s)) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int cuts = INT_MAX;
        
        for(int k=1;k<s.size()-i;k++){
            if(isPalindrome(i, i+k-1, s)){
                cuts = min(cuts, 1+func(i+k, n, s, dp));
            }
        }
        
        return dp[i] = cuts;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        if(isPalindrome(0, n-1, str)) return 0;
        vector<int> dp(n+1, -1);
        return func(0, n, str, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends