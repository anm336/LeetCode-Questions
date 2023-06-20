//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1,1}, {-1, 1}, {1, -1}};
    
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '0') return;
        //if(grid[i][j] == '0') return;
        
        if(!vis[i][j]){
            vis[i][j] = true;
            
            for(int k=0;k<dirs.size();k++){
                dfs(i+dirs[k][0], j+dirs[k][1], grid, vis, n, m);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='0' && !vis[i][j]){
                    //cout<<i<<" "<<j<<endl;
                    dfs(i, j, grid, vis, n, m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends