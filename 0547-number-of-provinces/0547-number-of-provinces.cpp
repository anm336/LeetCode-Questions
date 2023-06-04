class Solution {
public:
    int ans = 0;
    void dfs(int i, vector<int> adj[], vector<bool> &vis){
        vis[i] = true;
        
        for(auto neigh: adj[i]){
            if(!vis[neigh]) dfs(neigh, adj, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }
        vector<bool> vis(n, false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans++;
            }
        }
        
        return ans;
    }
};