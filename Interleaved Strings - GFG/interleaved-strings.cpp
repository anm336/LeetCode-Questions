//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool func(int n, int m, int len, string A, string B, string C, vector<vector<int>> &dp){
        if(len==0) return 1;
        
        if(dp[n][m] != -1) return dp[n][m];
        int takeA = 0, takeB = 0;
        if(n-1>=0 && A[n-1]==C[len-1]) takeA = func(n-1, m, len-1, A, B, C, dp);
        if(m-1>=0 && B[m-1]==C[len-1]) takeB = func(n, m-1, len-1, A, B, C, dp);
        
        return dp[n][m] = takeA || takeB;
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n = A.size();
        int m = B.size();
        int len = C.size();
        
        if(n+m != len) return false;
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return func(n, m, len, A, B, C, dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends