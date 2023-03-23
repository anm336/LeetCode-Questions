class Solution {
public:
    int connectedcomp = 0;
    void dfs(vector<int> graph[], vector<bool>& vis, int x){
        vis[x] = 1;
        for(int j=0;j<graph[x].size();j++){
            if(vis[graph[x][j]]==0) dfs(graph, vis, graph[x][j]);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        vector<int> graph[n];
        for(int i=0;i<size;i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> vis(n+1, 0);
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                dfs(graph, vis, i);
                connectedcomp++;
            }
            else continue;
        }
        if(size<n-1) return -1;
        else return connectedcomp-1;
    }
};