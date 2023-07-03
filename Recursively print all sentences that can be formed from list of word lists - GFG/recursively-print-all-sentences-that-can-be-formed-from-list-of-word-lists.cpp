//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    void func(int row, vector<vector<string>> &list, vector<string> temp, int m, int n, vector<vector<string>> &ans){
        if(row == m){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            temp.push_back(list[row][i]);
            func(row+1, list, temp, m, n, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
        int m = list.size();
        int n = list[0].size();
        vector<vector<string>> ans;
        vector<string> temp;
        
        func(0, list, temp, m, n, ans);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends