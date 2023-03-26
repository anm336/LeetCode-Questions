class Solution {
public:
    int ans = -1;
    void dfs(int x, vector<int>& edges, unordered_map<int,int>& mapping, vector<int>& vis){
        vis[x] = 1;
        int next = edges[x];
        
        if(next!=-1 && vis[next]==0){
            mapping[next] = mapping[x] + 1;
            dfs(next, edges, mapping, vis);
        }
        else if(next!=-1 && mapping[next]!=0){
            ans = max(ans, mapping[x]- mapping[next] + 1);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                unordered_map<int,int> mapping;
                mapping[i]++;
                dfs(i, edges, mapping, vis);
            }
        }
        return ans;
    }
};