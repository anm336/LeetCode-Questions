//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long func(int i, int j, int toTake, vector<vector<char>> &keys, vector<vector<vector<long long>>> &dp){
	    if((i==3 && j==0) || (i==3 && j==2) || i>3 || i<0 || j>2 || j<0) return 0;
	    if(toTake == 1) return 1;
	    if(dp[i][j][toTake] != -1) return dp[i][j][toTake];
	    
	    long long thatKey = func(i, j, toTake-1, keys, dp);
	    long long up = func(i-1, j, toTake-1, keys, dp);
	    long long down = func(i+1, j, toTake-1, keys, dp);
	    long long left = func(i, j-1, toTake-1, keys, dp);
	    long long right = func(i, j+1, toTake-1, keys, dp);
	    
	    return dp[i][j][toTake] = thatKey+up+down+left+right;
	}
	
	long long getCount(int N)
	{
		// Your code goes here
		long long ans = 0;
		vector<vector<char>> keys = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'*', '0', '#'}};
		
		vector<vector<vector<long long>>> dp(4, vector<vector<long long>> (4, vector<long long> (N+1, -1)));
		for(int i=0;i<=3;i++){
		    for(int j=0;j<3;j++){
		        if((i==3 && j==0) || (i==3 && j==2)) continue;
		        else ans+=func(i, j, N, keys, dp);
		    }
		}
		return ans;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends