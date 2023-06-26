class Solution {
public:
    void func(int i, vector<int> &dis, vector<int> &low,vector<bool> &vis, int par, int &timer, vector<int> adj[], vector<vector<int>> &ans){
        dis[i] = low[i] = timer++;
        vis[i] = true;
        
        for(auto neigh: adj[i]){
            if(neigh == par) continue;
            if(!vis[neigh]){
                func(neigh, dis, low, vis, i, timer, adj, ans);
                low[i] = min(low[i], low[neigh]);
                
                if(low[neigh]>dis[i]){
                    ans.push_back({i, neigh});
                }
            }
            else{
                low[i] = min(low[i], dis[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> dis(n, -1);
        vector<int> low(n, -1);
        vector<bool> vis(n, false);
        
        int timer = 0;
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]) func(i, dis, low, vis, -1, timer, adj, ans);
        }
        
        return ans;
    }
};