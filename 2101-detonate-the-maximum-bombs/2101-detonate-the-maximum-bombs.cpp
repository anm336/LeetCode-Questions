class Solution {
public:
    
    void dfs(int i, vector<int> adj[], vector<bool> &vis, int &cnt){
        vis[i] = true;
        
        for(auto neigh: adj[i]){
            if(!vis[neigh]){
                cnt++;
                dfs(neigh, adj, vis, cnt);
            }
        }
        
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        int n = bombs.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                int x2 = bombs[j][0], y2 = bombs[j][1];
                
                double dist = 1.0*(sqrt(1.0*pow(x1-x2, 2) + 1.0*pow(y1-y2, 2)));
                if(dist<=r1){
                    adj[i].push_back(j);
                    // cout<<i<<" "<<j<<" "<<dist;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            vector<bool> vis(n, false);
            int cnt = 1;
            dfs(i, adj, vis, cnt);
            ans = max(cnt, ans);
        }
        
        return ans;
    }
};