//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
	
	int func(int i, int status, vector<int> &nums, vector<vector<int>> &dp){
	    if(i==nums.size()) return 0;
	    
	    if(dp[i][status+1] != -1) return dp[i][status+1];
	    
	    if(status == -1){
	        return dp[i][status+1] = max(max(1+func(i+1, 0, nums, dp), 1+func(i+1, 1, nums, dp)), func(i+1, status, nums, dp));
	    }
	    else if(status == true && nums[i]>nums[i-1]){
	        return dp[i][status+1] = max(1+func(i+1, !status, nums, dp), func(i+1, status, nums, dp));
	    }
	    else if(status == false && nums[i]<nums[i-1]){
	        return dp[i][status+1] = max(1+func(i+1, !status, nums, dp), func(i+1, status, nums, dp));
	    }
	    
	    else return dp[i][status+1] = func(i+1, status, nums, dp);
	}
	
	int AlternatingaMaxLength(vector<int>&nums){
	    int n = nums.size();
	    vector<vector<int>> dp(n+1, vector<int> (3, -1));
	    
	    return func(0, -1, nums, dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends