class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<pair<int,int>> graph[n];
        vector<int> vis(n+1,0);
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back({connections[i][1],1});
            graph[connections[i][1]].push_back({connections[i][0],-1});
        }
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            vis[x] = 1;
            for(int j=0;j<graph[x].size();j++){
                int a = graph[x][j].first;
                int b = graph[x][j].second;
                if(vis[a]!=1){
                    q.push(a);
                    if(b==1){
                        ans++;
                    }
                }
                else continue;
            }
        }
        return ans;
    }
};