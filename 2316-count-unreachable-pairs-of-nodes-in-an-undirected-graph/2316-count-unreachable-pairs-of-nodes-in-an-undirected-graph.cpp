class Solution {
public:
    long long temp=0;
    void dfs(int i, vector<int> graph[], vector<int>& vis){
        for(int j=0;j<graph[i].size();j++){
            if(vis[graph[i][j]]==0){
                temp++;
                vis[graph[i][j]]=1;
                dfs(graph[i][j], graph, vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        long long ans=0;
        long long remnodes = n;
        vector<int> vis(n+1, 0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i] = 1;
                dfs(i, graph, vis);
                temp++;
                ans+=(temp*(remnodes-temp));
                remnodes-=temp;
                temp=0;
            }
        }
        
        return ans;
    }
};