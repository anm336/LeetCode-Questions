//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // bool dfs(int V, int par, vector<int> adj[], vector<bool> &vis){
    //     vis[V] = true;
        
    //     bool isLoop = false;
        
    //     for(int i=0;i<adj[V].size();i++){
    //         if(vis[adj[V][i]] && adj[V][i] == par) continue;
    //         if(vis[adj[V][i]]) return true;
    //         isLoop |= dfs(adj[V][i], V, adj, vis);
    //     }
        
    //     return isLoop;
    // }
    
    bool bfs(int V, vector<int> adj[], vector<bool> &vis){
        queue<int> q;
        unordered_map<int,int> par;
        par[V] = -1;
        vis[V] = true;
        q.push(V);
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++){
                if(vis[adj[x][i]] && adj[x][i] != par[x]) return true;
                else if(!vis[adj[x][i]]){
                    q.push(adj[x][i]);
                    vis[adj[x][i]] = true;
                    par[adj[x][i]] = x;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        // for(int i=0;i<V;i++){
        //     if(vis[i]) continue;
            
        //     if(dfs(i, -1, adj, vis)){
        //         return true;
        //         break;
        //     }
        // }
        
        for(int i=0;i<V;i++){
            if(vis[i]) continue;
            
            if(bfs(i, adj, vis)) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends