//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isThere(int i, int j, vector<vector<char>> &grid, string word, int ind, int xdir, int ydir){
	    if(ind == word.size()) return true;
	    
	    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return false; 
	    if(grid[i][j] != word[ind]) return false;
	    
	    bool ans = isThere(i+xdir, j+ydir, grid, word, ind+1, xdir, ydir);
	    return ans;
	}
	
	vector<vector<int>> searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    vector<vector<int>> dirs = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1,1}};
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	           bool occur = false;
	           for(auto x: dirs){
	               occur|=isThere(i, j, grid, word, 0, x[0], x[1]);
	               if(occur){
    	               ans.push_back({i, j});
    	               break;
    	           }
	           }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends