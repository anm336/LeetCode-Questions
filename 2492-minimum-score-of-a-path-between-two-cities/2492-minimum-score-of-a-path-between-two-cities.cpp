class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1,0);
        vector<pair<int,int>> graph[n+1];
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        int ans = INT_MAX;
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            vis[x] = 1;
            for(int j=0;j<graph[x].size();j++){
                if(vis[graph[x][j].first]!=1){
                    q.push(graph[x][j].first);
                    ans=min(ans, graph[x][j].second);
                }
            }
        }
        return ans;
    }
};