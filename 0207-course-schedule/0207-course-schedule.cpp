class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis){
        vis[node] = true;
        dfsVis[node] = true;
        
        for(auto neigh: adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh, adj, vis, dfsVis)) return true;
            }
            else if(dfsVis[neigh]) return true;
        }
        
        dfsVis[node] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        
        for(int i=0;i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> vis(n, false);
        vector<bool> dfsVis(n, false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, dfsVis)) return false;
            }
        }
        
        return true;
    }
};